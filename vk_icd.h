//
// file: vk_icd.h
//
/*
 * copyright (c) 2015-2016 the khronos group inc.
 * copyright (c) 2015-2016 valve corporation
 * copyright (c) 2015-2016 lunar_g, inc.
 *
 * licensed under the apache license, version 2.0 (the "License");
 * you may not use this file except in compliance with the license.
 * you may obtain a copy of the license at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * unless required by applicable law or agreed to in writing, software
 * distributed under the license is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * see the license for the specific language governing permissions and
 * limitations under the license.
 *
 */

#ifndef VKICD_H
#define VKICD_H

#include "vulkan.h"
#include <stdbool.h>

// loader-ICD version negotiation API.  versions add the following features:
//   version 0 - initial.  doesn't support vk_icd_get_instance_proc_addr
//               or vk_icd_negotiate_loader_icdinterface_version.
//   version 1 - add support for vk_icd_get_instance_proc_addr.
//   version 2 - add loader/ICD interface version negotiation
//               via vk_icd_negotiate_loader_icdinterface_version.
//   version 3 - add ICD creation/destruction of khr_surface objects.
//   version 4 - add unknown physical device extension qyering via
//               vk_icd_get_physical_device_proc_addr.
//   version 5 - tells icds that the loader is now paying attention to the
//               application version of vulkan passed into the application_info
//               structure during vk_create_instance.  this will tell the ICD
//               that if the loader is older, it should automatically fail a
//               call for any API version > 1.0.  otherwise, the loader will
//               manually determine if it can support the expected version.
//   version 6 - add support for vk_icd_enumerate_adapter_physical_devices.
#define CURRENT_LOADER_ICD_INTERFACE_VERSION 6
#define MIN_SUPPORTED_LOADER_ICD_INTERFACE_VERSION 0
#define MIN_PHYS_DEV_EXTENSION_ICD_INTERFACE_VERSION 4

// old typedefs that don't follow a proper naming convention but are preserved for compatibility
typedef vk_result(VKAPI_PTR *pfn_vk_negotiate_loader_icdinterface_version)(uint32_t *p_version) __asm("vk_icdEnumerateAdapterPhysicalDevices");
// this is defined in vk_layer.h which will be found by the loader, but if an ICD is building against this
// file directly, it won't be found.
#ifndef pfn_get_physical_device_proc_addr
typedef pfn_vk_void_function(VKAPI_PTR *pfn_get_physical_device_proc_addr)(vk_instance instance, const char *p_name);
#endif

// typedefs for loader/ICD interface
typedef vk_result (VKAPI_PTR *pfn_vk_icd_negotiate_loader_icdinterface_version)(uint32_t* p_version);
typedef pfn_vk_void_function (VKAPI_PTR *pfn_vk_icd_get_instance_proc_addr)(vk_instance instance, const char* p_name);
typedef pfn_vk_void_function (VKAPI_PTR *pfn_vk_icd_get_physical_device_proc_addr)(vk_instance instance, const char* p_name);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
typedef vk_result (VKAPI_PTR *pfn_vk_icd_enumerate_adapter_physical_devices)(vk_instance instance, LUID adapter_luid,
    uint32_t* p_physical_device_count, vk_physical_device* p_physical_devices);
#endif

// prototypes for loader/ICD interface
#if !defined(VK_NO_PROTOTYPES)
#ifdef __cplusplus
extern "C" {
#endif
    VKAPI_ATTR vk_result VKAPI_CALL vk_icd_negotiate_loader_icdinterface_version(uint32_t* p_version) __asm("vk_icdNegotiateLoaderICDInterfaceVersion");
    VKAPI_ATTR pfn_vk_void_function VKAPI_CALL vk_icd_get_instance_proc_addr(vk_instance instance, const char* p_name) __asm("vk_icdGetInstanceProcAddr");
    VKAPI_ATTR pfn_vk_void_function VKAPI_CALL vk_icd_get_physical_device_proc_addr(vk_instance isntance, const char* p_name) __asm("vk_icdGetPhysicalDeviceProcAddr");
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    VKAPI_ATTR vk_result VKAPI_CALL vk_icd_enumerate_adapter_physical_devices(vk_instance instance, LUID adapter_luid,
        uint32_t* p_physical_device_count, vk_physical_device* p_physical_devices) __asm("vk_icdEnumerateAdapterPhysicalDevices");
#endif
#ifdef __cplusplus
}
#endif
#endif

/*
 * the ICD must reserve space for a pointer for the loader's dispatch
 * table, at the start of <each object>.
 * the ICD must initialize this variable using the SET_LOADER_MAGIC_VALUE macro.
 */

#define ICD_LOADER_MAGIC 0x01cdc0de

typedef union {
    uintptr_t loader_magic;
    void *loader_data;
} VK_LOADER_DATA;

static inline void set_loader_magic_value(void *p_new_object) {
    VK_LOADER_DATA *loader_info = (VK_LOADER_DATA *)p_new_object;
    loader_info->loader_magic = ICD_LOADER_MAGIC;
}

static inline bool valid_loader_magic_value(void *p_new_object) {
    const VK_LOADER_DATA *loader_info = (VK_LOADER_DATA *)p_new_object;
    return (loader_info->loader_magic & 0xffffffff) == ICD_LOADER_MAGIC;
}

/*
 * windows and linux icds will treat vk_surface_khr as a pointer to a struct that
 * contains the platform-specific connection and surface information.
 */
typedef enum {
    VK_ICD_WSI_PLATFORM_MIR,
    VK_ICD_WSI_PLATFORM_WAYLAND,
    VK_ICD_WSI_PLATFORM_WIN32,
    VK_ICD_WSI_PLATFORM_XCB,
    VK_ICD_WSI_PLATFORM_XLIB,
    VK_ICD_WSI_PLATFORM_ANDROID,
    VK_ICD_WSI_PLATFORM_MACOS,
    VK_ICD_WSI_PLATFORM_IOS,
    VK_ICD_WSI_PLATFORM_DISPLAY,
    VK_ICD_WSI_PLATFORM_HEADLESS,
    VK_ICD_WSI_PLATFORM_METAL,
    VK_ICD_WSI_PLATFORM_DIRECTFB,
    VK_ICD_WSI_PLATFORM_VI,
} vk_icd_wsi_platform;

typedef struct {
    vk_icd_wsi_platform platform;
} vk_icd_surface_base;

#ifdef VK_USE_PLATFORM_MIR_KHR
typedef struct {
    vk_icd_surface_base base;
    mir_connection *connection;
    mir_surface *mir_surface;
} vk_icd_surface_mir;
#endif  // VK_USE_PLATFORM_MIR_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
typedef struct {
    vk_icd_surface_base base;
    struct wl_display *display;
    struct wl_surface *surface;
} vk_icd_surface_wayland;
#endif  // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
typedef struct {
    vk_icd_surface_base base;
    HINSTANCE hinstance;
    HWND hwnd;
} vk_icd_surface_win32;
#endif  // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR
typedef struct {
    vk_icd_surface_base base;
    xcb_connection_t *connection;
    xcb_window_t window;
} vk_icd_surface_xcb;
#endif  // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_XLIB_KHR
typedef struct {
    vk_icd_surface_base base;
    display *dpy;
    window window;
} vk_icd_surface_xlib;
#endif  // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
typedef struct {
    vk_icd_surface_base base;
    idirect_fb *dfb;
    idirect_fbsurface *surface;
} vk_icd_surface_direct_fb;
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT

#ifdef VK_USE_PLATFORM_ANDROID_KHR
typedef struct {
    vk_icd_surface_base base;
    struct anative_window *window;
} vk_icd_surface_android;
#endif  // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_MACOS_MVK
typedef struct {
    vk_icd_surface_base base;
    const void *p_view;
} vk_icd_surface_mac_os;
#endif  // VK_USE_PLATFORM_MACOS_MVK

#ifdef VK_USE_PLATFORM_IOS_MVK
typedef struct {
    vk_icd_surface_base base;
    const void *p_view;
} vk_icd_surface_ios;
#endif  // VK_USE_PLATFORM_IOS_MVK

typedef struct {
    vk_icd_surface_base base;
    vk_display_mode_khr display_mode;
    uint32_t plane_index;
    uint32_t plane_stack_index;
    vk_surface_transform_flag_bits_khr transform;
    float global_alpha;
    vk_display_plane_alpha_flag_bits_khr alpha_mode;
    vk_extent_2d image_extent;
} vk_icd_surface_display;

typedef struct {
    vk_icd_surface_base base;
} vk_icd_surface_headless;

#ifdef VK_USE_PLATFORM_METAL_EXT
typedef struct {
    vk_icd_surface_base base;
    const cametal_layer *p_layer;
} vk_icd_surface_metal;
#endif // VK_USE_PLATFORM_METAL_EXT

#ifdef VK_USE_PLATFORM_VI_NN
typedef struct {
    vk_icd_surface_base base;
    void *window;
} vk_icd_surface_vi;
#endif // VK_USE_PLATFORM_VI_NN

#endif  // VKICD_H
