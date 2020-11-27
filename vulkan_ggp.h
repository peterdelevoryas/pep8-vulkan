#ifndef VULKAN_GGP_H_
#define VULKAN_GGP_H_ 1

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

#define vk_ggp_stream_descriptor_surface 1
#define VK_GGP_STREAM_DESCRIPTOR_SURFACE_SPEC_VERSION 1
#define VK_GGP_STREAM_DESCRIPTOR_SURFACE_EXTENSION_NAME "VK_GGP_stream_descriptor_surface"
typedef vk_flags vk_stream_descriptor_surface_create_flags_ggp;
typedef struct vk_stream_descriptor_surface_create_info_ggp {
    vk_structure_type                             s_type;
    const void*                                   p_next;
    vk_stream_descriptor_surface_create_flags_ggp flags;
    ggp_stream_descriptor                         stream_descriptor;
} vk_stream_descriptor_surface_create_info_ggp;

typedef vk_result(VKAPI_PTR* pfn_vk_create_stream_descriptor_surface_ggp)(
    vk_instance instance, const vk_stream_descriptor_surface_create_info_ggp* p_create_info,
    const vk_allocation_callbacks* p_allocator, vk_surface_khr* p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_stream_descriptor_surface_ggp(
    vk_instance instance, const vk_stream_descriptor_surface_create_info_ggp* p_create_info,
    const vk_allocation_callbacks* p_allocator, vk_surface_khr* p_surface) __asm("vkCreateStreamDescriptorSurfaceGGP");
#endif

#define vk_ggp_frame_token 1
#define VK_GGP_FRAME_TOKEN_SPEC_VERSION 1
#define VK_GGP_FRAME_TOKEN_EXTENSION_NAME "VK_GGP_frame_token"
typedef struct vk_present_frame_token_ggp {
    vk_structure_type s_type;
    const void*       p_next;
    ggp_frame_token   frame_token;
} vk_present_frame_token_ggp;

#ifdef __cplusplus
}
#endif

#endif
