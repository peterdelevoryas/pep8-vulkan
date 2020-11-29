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
typedef VkFlags VkStreamDescriptorSurfaceCreateFlagsGGP;
typedef struct VkStreamDescriptorSurfaceCreateInfoGGP {
    VkStructureType                         s_type;
    const void*                             p_next;
    VkStreamDescriptorSurfaceCreateFlagsGGP flags;
    ggp_stream_descriptor                   stream_descriptor;
} VkStreamDescriptorSurfaceCreateInfoGGP;

typedef VkResult(VKAPI_PTR* pfn_vk_create_stream_descriptor_surface_ggp)(
    VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* p_create_info,
    const VkAllocationCallbacks* p_allocator, VkSurfaceKHR* p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_stream_descriptor_surface_ggp(
    VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* p_create_info,
    const VkAllocationCallbacks* p_allocator, VkSurfaceKHR* p_surface) __asm("vkCreateStreamDescriptorSurfaceGGP");
#endif

#define vk_ggp_frame_token 1
#define VK_GGP_FRAME_TOKEN_SPEC_VERSION 1
#define VK_GGP_FRAME_TOKEN_EXTENSION_NAME "VK_GGP_frame_token"
typedef struct VkPresentFrameTokenGGP {
    VkStructureType s_type;
    const void*     p_next;
    ggp_frame_token frame_token;
} VkPresentFrameTokenGGP;

#ifdef __cplusplus
}
#endif

#endif
