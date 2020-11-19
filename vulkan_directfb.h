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
typedef vk_flags vk_direct_fbsurface_create_flags_ext;
typedef struct vk_direct_fbsurface_create_info_ext {
    vk_structure_type                    s_type;
    const void*                        p_next;
    vk_direct_fbsurface_create_flags_ext    flags;
    idirect_fb*                         dfb;
    idirect_fbsurface*                  surface;
} vk_direct_fbsurface_create_info_ext;

typedef vk_result (VKAPI_PTR *pfn_vk_create_direct_fbsurface_ext)(vk_instance instance, const vk_direct_fbsurface_create_info_ext* p_create_info, const vk_allocation_callbacks* p_allocator, vk_surface_khr* p_surface);
typedef vk_bool32 (VKAPI_PTR *pfn_vk_get_physical_device_direct_fbpresentation_support_ext)(vk_physical_device physical_device, uint32_t queue_family_index, idirect_fb* dfb);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_direct_fbsurface_ext(
    vk_instance                                  instance,
    const vk_direct_fbsurface_create_info_ext*       p_create_info,
    const vk_allocation_callbacks*                p_allocator,
    vk_surface_khr*                               p_surface) __asm("vkCreateDirectFBSurfaceEXT");

VKAPI_ATTR vk_bool32 VKAPI_CALL vk_get_physical_device_direct_fbpresentation_support_ext(
    vk_physical_device                            physical_device,
    uint32_t                                    queue_family_index,
    idirect_fb*                                  dfb) __asm("vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif

#ifdef __cplusplus
}
#endif

#endif
