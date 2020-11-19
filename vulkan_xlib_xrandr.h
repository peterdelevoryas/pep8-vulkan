#ifndef VULKAN_XLIB_XRANDR_H_
#define VULKAN_XLIB_XRANDR_H_ 1

/*
** copyright (c) 2015-2020 the khronos group inc.
**
** SPDX-license-identifier: apache-2.0
*/

/*
** this header is generated from the khronos vulkan XML API registry.
**
*/


#ifdef __cplusplus
extern "C" {
#endif



#define vk_ext_acquire_xlib_display 1
#define VK_EXT_ACQUIRE_XLIB_DISPLAY_SPEC_VERSION 1
#define VK_EXT_ACQUIRE_XLIB_DISPLAY_EXTENSION_NAME "VK_EXT_acquire_xlib_display"
typedef vk_result (VKAPI_PTR *pfn_vk_acquire_xlib_display_ext)(vk_physical_device physical_device, display* dpy, vk_display_khr display);
typedef vk_result (VKAPI_PTR *pfn_vk_get_rand_routput_display_ext)(vk_physical_device physical_device, display* dpy, rroutput rr_output, vk_display_khr* p_display);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_acquire_xlib_display_ext(
    vk_physical_device                            physical_device,
    display*                                    dpy,
    vk_display_khr                                display) __asm("vkAcquireXlibDisplayEXT");

VKAPI_ATTR vk_result VKAPI_CALL vk_get_rand_routput_display_ext(
    vk_physical_device                            physical_device,
    display*                                    dpy,
    rroutput                                    rr_output,
    vk_display_khr*                               p_display) __asm("vkGetRandROutputDisplayEXT");
#endif

#ifdef __cplusplus
}
#endif

#endif
