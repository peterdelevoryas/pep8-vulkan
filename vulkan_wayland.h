#ifndef VULKAN_WAYLAND_H_
#define VULKAN_WAYLAND_H_ 1

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

#define vk_khr_wayland_surface 1
#define VK_KHR_WAYLAND_SURFACE_SPEC_VERSION 6
#define VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME "VK_KHR_wayland_surface"
typedef VkFlags VkWaylandSurfaceCreateFlagsKHR;
typedef struct VkWaylandSurfaceCreateInfoKHR {
    VkStructureType                s_type;
    const void*                    p_next;
    VkWaylandSurfaceCreateFlagsKHR flags;
    struct wl_display*             display;
    struct wl_surface*             surface;
} VkWaylandSurfaceCreateInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_create_wayland_surface_khr)(VkInstance                           instance,
                                                               const VkWaylandSurfaceCreateInfoKHR* p_create_info,
                                                               const VkAllocationCallbacks*         p_allocator,
                                                               VkSurfaceKHR*                        p_surface);
typedef VkBool32(VKAPI_PTR* pfn_vk_get_physical_device_wayland_presentation_support_khr)(
    VkPhysicalDevice physical_device, uint32_t queue_family_index, struct wl_display* display);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_wayland_surface_khr(
    VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* p_create_info, const VkAllocationCallbacks* p_allocator,
    VkSurfaceKHR* p_surface) __asm("vkCreateWaylandSurfaceKHR");

VKAPI_ATTR VkBool32 VKAPI_CALL vk_get_physical_device_wayland_presentation_support_khr(
    VkPhysicalDevice physical_device, uint32_t queue_family_index,
    struct wl_display* display) __asm("vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif

#ifdef __cplusplus
}
#endif

#endif
