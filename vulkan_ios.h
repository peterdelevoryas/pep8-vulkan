#ifndef VULKAN_IOS_H_
#define VULKAN_IOS_H_ 1

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

#define vk_mvk_ios_surface 1
#define VK_MVK_IOS_SURFACE_SPEC_VERSION 3
#define VK_MVK_IOS_SURFACE_EXTENSION_NAME "VK_MVK_ios_surface"
typedef VkFlags VkIOSSurfaceCreateFlagsMVK;
typedef struct VkIOSSurfaceCreateInfoMVK {
    VkStructureType            s_type;
    const void*                p_next;
    VkIOSSurfaceCreateFlagsMVK flags;
    const void*                p_view;
} VkIOSSurfaceCreateInfoMVK;

typedef VkResult(VKAPI_PTR* pfn_vk_create_iossurface_mvk)(VkInstance                       instance,
                                                          const VkIOSSurfaceCreateInfoMVK* p_create_info,
                                                          const VkAllocationCallbacks*     p_allocator,
                                                          VkSurfaceKHR*                    p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_iossurface_mvk(VkInstance                       instance,
                                                        const VkIOSSurfaceCreateInfoMVK* p_create_info,
                                                        const VkAllocationCallbacks*     p_allocator,
                                                        VkSurfaceKHR* p_surface) __asm("vkCreateIOSSurfaceMVK");
#endif

#ifdef __cplusplus
}
#endif

#endif
