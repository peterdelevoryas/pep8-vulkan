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
#define VK_NN_VI_SURFACE_SPEC_VERSION 1
#define VK_NN_VI_SURFACE_EXTENSION_NAME "VK_NN_vi_surface"
typedef VkFlags VkViSurfaceCreateFlagsNN;
typedef struct VkViSurfaceCreateInfoNN {
    VkStructureType          s_type;
    const void*              p_next;
    VkViSurfaceCreateFlagsNN flags;
    void*                    window;
} VkViSurfaceCreateInfoNN;

typedef VkResult(VKAPI_PTR* pfn_vk_create_vi_surface_nn)(VkInstance                     instance,
                                                         const VkViSurfaceCreateInfoNN* p_create_info,
                                                         const VkAllocationCallbacks*   p_allocator,
                                                         VkSurfaceKHR*                  p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_vi_surface_nn(VkInstance                     instance,
                                                       const VkViSurfaceCreateInfoNN* p_create_info,
                                                       const VkAllocationCallbacks*   p_allocator,
                                                       VkSurfaceKHR* p_surface) __asm("vkCreateViSurfaceNN");
#endif

#ifdef __cplusplus
}
#endif

#endif
