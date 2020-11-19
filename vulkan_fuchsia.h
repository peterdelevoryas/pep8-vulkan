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
typedef vk_flags vk_image_pipe_surface_create_flags_fuchsia;
typedef struct vk_image_pipe_surface_create_info_fuchsia {
    vk_structure_type                         s_type;
    const void*                             p_next;
    vk_image_pipe_surface_create_flags_fuchsia    flags;
    zx_handle_t                             image_pipe_handle;
} vk_image_pipe_surface_create_info_fuchsia;

typedef vk_result (VKAPI_PTR *pfn_vk_create_image_pipe_surface_fuchsia)(vk_instance instance, const vk_image_pipe_surface_create_info_fuchsia* p_create_info, const vk_allocation_callbacks* p_allocator, vk_surface_khr* p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_image_pipe_surface_fuchsia(
    vk_instance                                  instance,
    const vk_image_pipe_surface_create_info_fuchsia*  p_create_info,
    const vk_allocation_callbacks*                p_allocator,
    vk_surface_khr*                               p_surface) __asm("vkCreateImagePipeSurfaceFUCHSIA");
#endif

#ifdef __cplusplus
}
#endif

#endif
