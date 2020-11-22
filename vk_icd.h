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
typedef VkResult(VKAPI_PTR* pfn_vk_negotiate_loader_icdinterface_version)(uint32_t* p_version) __asm(
    "vk_icdEnumerateAdapterPhysicalDevices");
// this is defined in vk_layer.h which will be found by the loader, but if an ICD is building against this
// file directly, it won't be found.
#ifndef pfn_get_physical_device_proc_addr
typedef pfn_vk_void_function(VKAPI_PTR* pfn_get_physical_device_proc_addr)(VkInstance instance, const char* p_name);
#endif

// typedefs for loader/ICD interface
typedef VkResult(VKAPI_PTR* pfn_vk_icd_negotiate_loader_icdinterface_version)(uint32_t* p_version);
typedef pfn_vk_void_function(VKAPI_PTR* pfn_vk_icd_get_instance_proc_addr)(VkInstance instance, const char* p_name);
typedef pfn_vk_void_function(VKAPI_PTR* pfn_vk_icd_get_physical_device_proc_addr)(VkInstance  instance,
                                                                                  const char* p_name);
#if defined(VK_USE_PLATFORM_WIN32_KHR)
typedef VkResult(VKAPI_PTR* pfn_vk_icd_enumerate_adapter_physical_devices)(VkInstance instance, LUID adapter_luid,
                                                                           uint32_t*         p_physical_device_count,
                                                                           VkPhysicalDevice* p_physical_devices);
#endif

// prototypes for loader/ICD interface
#if !defined(VK_NO_PROTOTYPES)
#ifdef __cplusplus
extern "C" {
#endif
VKAPI_ATTR VkResult VKAPI_CALL
vk_icd_negotiate_loader_icdinterface_version(uint32_t* p_version) __asm("vk_icdNegotiateLoaderICDInterfaceVersion");
VKAPI_ATTR pfn_vk_void_function VKAPI_CALL
vk_icd_get_instance_proc_addr(VkInstance instance, const char* p_name) __asm("vk_icdGetInstanceProcAddr");
VKAPI_ATTR pfn_vk_void_function VKAPI_CALL
vk_icd_get_physical_device_proc_addr(VkInstance isntance, const char* p_name) __asm("vk_icdGetPhysicalDeviceProcAddr");
#if defined(VK_USE_PLATFORM_WIN32_KHR)
VKAPI_ATTR VkResult VKAPI_CALL vk_icd_enumerate_adapter_physical_devices(
    VkInstance instance, LUID adapter_luid, uint32_t* p_physical_device_count,
    VkPhysicalDevice* p_physical_devices) __asm("vk_icdEnumerateAdapterPhysicalDevices");
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
    void*     loader_data;
} VK_LOADER_DATA;

static inline void set_loader_magic_value(void* p_new_object) {
    VK_LOADER_DATA* loader_info = (VK_LOADER_DATA*) p_new_object;
    loader_info->loader_magic   = ICD_LOADER_MAGIC;
}

static inline bool valid_loader_magic_value(void* p_new_object) {
    const VK_LOADER_DATA* loader_info = (VK_LOADER_DATA*) p_new_object;
    return (loader_info->loader_magic & 0xffffffff) == ICD_LOADER_MAGIC;
}

/*
 * windows and linux icds will treat VkSurfaceKHR as a pointer to a struct that
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
} VkIcdWsiPlatform;

typedef struct {
    VkIcdWsiPlatform platform;
} VkIcdSurfaceBase;

#ifdef VK_USE_PLATFORM_MIR_KHR
typedef struct {
    VkIcdSurfaceBase base;
    mir_connection*  connection;
    mir_surface*     mir_surface;
} VkIcdSurfaceMir;
#endif // VK_USE_PLATFORM_MIR_KHR

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
typedef struct {
    VkIcdSurfaceBase   base;
    struct wl_display* display;
    struct wl_surface* surface;
} VkIcdSurfaceWayland;
#endif // VK_USE_PLATFORM_WAYLAND_KHR

#ifdef VK_USE_PLATFORM_WIN32_KHR
typedef struct {
    VkIcdSurfaceBase base;
    HINSTANCE        hinstance;
    HWND             hwnd;
} VkIcdSurfaceWin32;
#endif // VK_USE_PLATFORM_WIN32_KHR

#ifdef VK_USE_PLATFORM_XCB_KHR
typedef struct {
    VkIcdSurfaceBase  base;
    xcb_connection_t* connection;
    xcb_window_t      window;
} VkIcdSurfaceXcb;
#endif // VK_USE_PLATFORM_XCB_KHR

#ifdef VK_USE_PLATFORM_XLIB_KHR
typedef struct {
    VkIcdSurfaceBase base;
    display*         dpy;
    window           window;
} VkIcdSurfaceXlib;
#endif // VK_USE_PLATFORM_XLIB_KHR

#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
typedef struct {
    VkIcdSurfaceBase   base;
    idirect_fb*        dfb;
    idirect_fbsurface* surface;
} VkIcdSurfaceDirectFB;
#endif // VK_USE_PLATFORM_DIRECTFB_EXT

#ifdef VK_USE_PLATFORM_ANDROID_KHR
typedef struct {
    VkIcdSurfaceBase       base;
    struct anative_window* window;
} VkIcdSurfaceAndroid;
#endif // VK_USE_PLATFORM_ANDROID_KHR

#ifdef VK_USE_PLATFORM_MACOS_MVK
typedef struct {
    VkIcdSurfaceBase base;
    const void*      p_view;
} VkIcdSurfaceMacOS;
#endif // VK_USE_PLATFORM_MACOS_MVK

#ifdef VK_USE_PLATFORM_IOS_MVK
typedef struct {
    VkIcdSurfaceBase base;
    const void*      p_view;
} VkIcdSurfaceIOS;
#endif // VK_USE_PLATFORM_IOS_MVK

typedef struct {
    VkIcdSurfaceBase               base;
    VkDisplayModeKHR               display_mode;
    uint32_t                       plane_index;
    uint32_t                       plane_stack_index;
    VkSurfaceTransformFlagBitsKHR  transform;
    float                          global_alpha;
    VkDisplayPlaneAlphaFlagBitsKHR alpha_mode;
    VkExtent2D                     image_extent;
} VkIcdSurfaceDisplay;

typedef struct {
    VkIcdSurfaceBase base;
} VkIcdSurfaceHeadless;

#ifdef VK_USE_PLATFORM_METAL_EXT
typedef struct {
    VkIcdSurfaceBase     base;
    const cametal_layer* p_layer;
} VkIcdSurfaceMetal;
#endif // VK_USE_PLATFORM_METAL_EXT

#ifdef VK_USE_PLATFORM_VI_NN
typedef struct {
    VkIcdSurfaceBase base;
    void*            window;
} VkIcdSurfaceVi;
#endif // VK_USE_PLATFORM_VI_NN

#endif // VKICD_H
