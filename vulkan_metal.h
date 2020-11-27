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
typedef vk_flags vk_metal_surface_create_flags_ext;
typedef struct vk_metal_surface_create_info_ext {
    vk_structure_type                 s_type;
    const void*                       p_next;
    vk_metal_surface_create_flags_ext flags;
    const cametal_layer*              p_layer;
} vk_metal_surface_create_info_ext;

typedef vk_result(VKAPI_PTR* pfn_vk_create_metal_surface_ext)(vk_instance                             instance,
                                                              const vk_metal_surface_create_info_ext* p_create_info,
                                                              const vk_allocation_callbacks*          p_allocator,
                                                              vk_surface_khr*                         p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_metal_surface_ext(vk_instance                             instance,
                                                            const vk_metal_surface_create_info_ext* p_create_info,
                                                            const vk_allocation_callbacks*          p_allocator,
                                                            vk_surface_khr* p_surface) __asm("vkCreateMetalSurfaceEXT");
#endif

#ifdef __cplusplus
}
#endif

#endif
