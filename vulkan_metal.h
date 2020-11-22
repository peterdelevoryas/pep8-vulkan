#ifndef VULKAN_METAL_H_
#define VULKAN_METAL_H_ 1

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

#define vk_ext_metal_surface 1

#ifdef __OBJC__
@class cametal_layer;
#else
typedef void cametal_layer;
#endif

#define VK_EXT_METAL_SURFACE_SPEC_VERSION 1
#define VK_EXT_METAL_SURFACE_EXTENSION_NAME "VK_EXT_metal_surface"
typedef VkFlags VkMetalSurfaceCreateFlagsEXT;
typedef struct VkMetalSurfaceCreateInfoEXT {
    VkStructureType              s_type;
    const void*                  p_next;
    VkMetalSurfaceCreateFlagsEXT flags;
    const cametal_layer*         p_layer;
} VkMetalSurfaceCreateInfoEXT;

typedef VkResult(VKAPI_PTR* pfn_vk_create_metal_surface_ext)(VkInstance                         instance,
                                                             const VkMetalSurfaceCreateInfoEXT* p_create_info,
                                                             const VkAllocationCallbacks*       p_allocator,
                                                             VkSurfaceKHR*                      p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_metal_surface_ext(VkInstance                         instance,
                                                           const VkMetalSurfaceCreateInfoEXT* p_create_info,
                                                           const VkAllocationCallbacks*       p_allocator,
                                                           VkSurfaceKHR* p_surface) __asm("vkCreateMetalSurfaceEXT");
#endif

#ifdef __cplusplus
}
#endif

#endif
