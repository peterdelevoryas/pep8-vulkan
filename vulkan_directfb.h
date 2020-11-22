#ifndef VULKAN_DIRECTFB_H_
#define VULKAN_DIRECTFB_H_ 1

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

#define vk_ext_directfb_surface 1
#define VK_EXT_DIRECTFB_SURFACE_SPEC_VERSION 1
#define VK_EXT_DIRECTFB_SURFACE_EXTENSION_NAME "VK_EXT_directfb_surface"
typedef VkFlags VkDirectFBSurfaceCreateFlagsEXT;
typedef struct VkDirectFBSurfaceCreateInfoEXT {
    VkStructureType                 s_type;
    const void*                     p_next;
    VkDirectFBSurfaceCreateFlagsEXT flags;
    idirect_fb*                     dfb;
    idirect_fbsurface*              surface;
} VkDirectFBSurfaceCreateInfoEXT;

typedef VkResult(VKAPI_PTR* pfn_vk_create_direct_fbsurface_ext)(VkInstance                            instance,
                                                                const VkDirectFBSurfaceCreateInfoEXT* p_create_info,
                                                                const VkAllocationCallbacks*          p_allocator,
                                                                VkSurfaceKHR*                         p_surface);
typedef VkBool32(VKAPI_PTR* pfn_vk_get_physical_device_direct_fbpresentation_support_ext)(
    VkPhysicalDevice physical_device, uint32_t queue_family_index, idirect_fb* dfb);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_direct_fbsurface_ext(
    VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* p_create_info, const VkAllocationCallbacks* p_allocator,
    VkSurfaceKHR* p_surface) __asm("vkCreateDirectFBSurfaceEXT");

VKAPI_ATTR VkBool32 VKAPI_CALL vk_get_physical_device_direct_fbpresentation_support_ext(
    VkPhysicalDevice physical_device, uint32_t queue_family_index,
    idirect_fb* dfb) __asm("vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif

#ifdef __cplusplus
}
#endif

#endif
