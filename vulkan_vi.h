#ifndef VULKAN_VI_H_
#define VULKAN_VI_H_ 1

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



#define vk_nn_vi_surface 1
#define VK_NN_VI_SURFACE_SPEC_VERSION     1
#define VK_NN_VI_SURFACE_EXTENSION_NAME   "VK_NN_vi_surface"
typedef vk_flags vk_vi_surface_create_flags_nn;
typedef struct vk_vi_surface_create_info_nn {
    vk_structure_type             s_type;
    const void*                 p_next;
    vk_vi_surface_create_flags_nn    flags;
    void*                       window;
} vk_vi_surface_create_info_nn;

typedef vk_result (VKAPI_PTR *pfn_vk_create_vi_surface_nn)(vk_instance instance, const vk_vi_surface_create_info_nn* p_create_info, const vk_allocation_callbacks* p_allocator, vk_surface_khr* p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_vi_surface_nn(
    vk_instance                                  instance,
    const vk_vi_surface_create_info_nn*              p_create_info,
    const vk_allocation_callbacks*                p_allocator,
    vk_surface_khr*                               p_surface) __asm("vkCreateViSurfaceNN");
#endif

#ifdef __cplusplus
}
#endif

#endif
