#ifndef VULKAN_FUCHSIA_H_
#define VULKAN_FUCHSIA_H_ 1

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

#define vk_fuchsia_imagepipe_surface 1
#define VK_FUCHSIA_IMAGEPIPE_SURFACE_SPEC_VERSION 1
#define VK_FUCHSIA_IMAGEPIPE_SURFACE_EXTENSION_NAME "VK_FUCHSIA_imagepipe_surface"
typedef VkFlags VkImagePipeSurfaceCreateFlagsFUCHSIA;
typedef struct VkImagePipeSurfaceCreateInfoFUCHSIA {
    VkStructureType                      s_type;
    const void*                          p_next;
    VkImagePipeSurfaceCreateFlagsFUCHSIA flags;
    zx_handle_t                          image_pipe_handle;
} VkImagePipeSurfaceCreateInfoFUCHSIA;

typedef VkResult(VKAPI_PTR* pfn_vk_create_image_pipe_surface_fuchsia)(
    VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* p_create_info,
    const VkAllocationCallbacks* p_allocator, VkSurfaceKHR* p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_image_pipe_surface_fuchsia(
    VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* p_create_info,
    const VkAllocationCallbacks* p_allocator, VkSurfaceKHR* p_surface) __asm("vkCreateImagePipeSurfaceFUCHSIA");
#endif

#ifdef __cplusplus
}
#endif

#endif
