#ifndef VULKAN_ANDROID_H_
#define VULKAN_ANDROID_H_ 1

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



#define vk_khr_android_surface 1
struct anative_window;
#define VK_KHR_ANDROID_SURFACE_SPEC_VERSION 6
#define VK_KHR_ANDROID_SURFACE_EXTENSION_NAME "VK_KHR_android_surface"
typedef vk_flags vk_android_surface_create_flags_khr;
typedef struct vk_android_surface_create_info_khr {
    vk_structure_type                   s_type;
    const void*                       p_next;
    vk_android_surface_create_flags_khr    flags;
    struct anative_window*             window;
} vk_android_surface_create_info_khr;

typedef vk_result (VKAPI_PTR *pfn_vk_create_android_surface_khr)(vk_instance instance, const vk_android_surface_create_info_khr* p_create_info, const vk_allocation_callbacks* p_allocator, vk_surface_khr* p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_android_surface_khr(
    vk_instance                                  instance,
    const vk_android_surface_create_info_khr*        p_create_info,
    const vk_allocation_callbacks*                p_allocator,
    vk_surface_khr*                               p_surface) __asm("vkCreateAndroidSurfaceKHR");
#endif


#define vk_android_external_memory_android_hardware_buffer 1
struct ahardware_buffer;
#define VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_SPEC_VERSION 3
#define VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_EXTENSION_NAME "VK_ANDROID_external_memory_android_hardware_buffer"
typedef struct vk_android_hardware_buffer_usage_android {
    vk_structure_type    s_type;
    void*              p_next;
    uint64_t           android_hardware_buffer_usage;
} vk_android_hardware_buffer_usage_android;

typedef struct vk_android_hardware_buffer_properties_android {
    vk_structure_type    s_type;
    void*              p_next;
    vk_device_size       allocation_size;
    uint32_t           memory_type_bits;
} vk_android_hardware_buffer_properties_android;

typedef struct vk_android_hardware_buffer_format_properties_android {
    vk_structure_type                  s_type;
    void*                            p_next;
    vk_format                         format;
    uint64_t                         external_format;
    vk_format_feature_flags             format_features;
    vk_component_mapping               sampler_ycbcr_conversion_components;
    vk_sampler_ycbcr_model_conversion    suggested_ycbcr_model;
    vk_sampler_ycbcr_range              suggested_ycbcr_range;
    vk_chroma_location                 suggested_xchroma_offset;
    vk_chroma_location                 suggested_ychroma_offset;
} vk_android_hardware_buffer_format_properties_android;

typedef struct vk_import_android_hardware_buffer_info_android {
    vk_structure_type            s_type;
    const void*                p_next;
    struct ahardware_buffer*    buffer;
} vk_import_android_hardware_buffer_info_android;

typedef struct vk_memory_get_android_hardware_buffer_info_android {
    vk_structure_type    s_type;
    const void*        p_next;
    vk_device_memory     memory;
} vk_memory_get_android_hardware_buffer_info_android;

typedef struct vk_external_format_android {
    vk_structure_type    s_type;
    void*              p_next;
    uint64_t           external_format;
} vk_external_format_android;

typedef vk_result (VKAPI_PTR *pfn_vk_get_android_hardware_buffer_properties_android)(vk_device device, const struct ahardware_buffer* buffer, vk_android_hardware_buffer_properties_android* p_properties);
typedef vk_result (VKAPI_PTR *pfn_vk_get_memory_android_hardware_buffer_android)(vk_device device, const vk_memory_get_android_hardware_buffer_info_android* p_info, struct ahardware_buffer** p_buffer);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_get_android_hardware_buffer_properties_android(
    vk_device                                    device,
    const struct ahardware_buffer*               buffer,
    vk_android_hardware_buffer_properties_android*   p_properties) __asm("vkGetAndroidHardwareBufferPropertiesANDROID");

VKAPI_ATTR vk_result VKAPI_CALL vk_get_memory_android_hardware_buffer_android(
    vk_device                                    device,
    const vk_memory_get_android_hardware_buffer_info_android* p_info,
    struct ahardware_buffer**                    p_buffer) __asm("vkGetMemoryAndroidHardwareBufferANDROID");
#endif

#ifdef __cplusplus
}
#endif

#endif
