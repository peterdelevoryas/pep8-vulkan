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
typedef vk_flags vk_mac_ossurface_create_flags_mvk;
typedef struct vk_mac_ossurface_create_info_mvk {
    vk_structure_type                 s_type;
    const void*                       p_next;
    vk_mac_ossurface_create_flags_mvk flags;
    const void*                       p_view;
} vk_mac_ossurface_create_info_mvk;

typedef vk_result(VKAPI_PTR* pfn_vk_create_mac_ossurface_mvk)(vk_instance                             instance,
                                                              const vk_mac_ossurface_create_info_mvk* p_create_info,
                                                              const vk_allocation_callbacks*          p_allocator,
                                                              vk_surface_khr*                         p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_mac_ossurface_mvk(vk_instance                             instance,
                                                            const vk_mac_ossurface_create_info_mvk* p_create_info,
                                                            const vk_allocation_callbacks*          p_allocator,
                                                            vk_surface_khr* p_surface) __asm("vkCreateMacOSSurfaceMVK");
#endif

#ifdef __cplusplus
}
#endif

#endif
