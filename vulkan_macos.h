#ifndef VULKAN_MACOS_H_
#define VULKAN_MACOS_H_ 1

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

#define vk_mvk_macos_surface 1
#define VK_MVK_MACOS_SURFACE_SPEC_VERSION 3
#define VK_MVK_MACOS_SURFACE_EXTENSION_NAME "VK_MVK_macos_surface"
typedef VkFlags VkMacOSSurfaceCreateFlagsMVK;
typedef struct VkMacOSSurfaceCreateInfoMVK {
    VkStructureType              s_type;
    const void*                  p_next;
    VkMacOSSurfaceCreateFlagsMVK flags;
    const void*                  p_view;
} VkMacOSSurfaceCreateInfoMVK;

typedef VkResult(VKAPI_PTR* pfn_vk_create_mac_ossurface_mvk)(VkInstance                         instance,
                                                             const VkMacOSSurfaceCreateInfoMVK* p_create_info,
                                                             const VkAllocationCallbacks*       p_allocator,
                                                             VkSurfaceKHR*                      p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_mac_ossurface_mvk(VkInstance                         instance,
                                                           const VkMacOSSurfaceCreateInfoMVK* p_create_info,
                                                           const VkAllocationCallbacks*       p_allocator,
                                                           VkSurfaceKHR* p_surface) __asm("vkCreateMacOSSurfaceMVK");
#endif

#ifdef __cplusplus
}
#endif

#endif
