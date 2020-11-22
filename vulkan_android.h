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
typedef VkFlags VkAndroidSurfaceCreateFlagsKHR;
typedef struct VkAndroidSurfaceCreateInfoKHR {
    VkStructureType                s_type;
    const void*                    p_next;
    VkAndroidSurfaceCreateFlagsKHR flags;
    struct anative_window*         window;
} VkAndroidSurfaceCreateInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_create_android_surface_khr)(VkInstance                           instance,
                                                               const VkAndroidSurfaceCreateInfoKHR* p_create_info,
                                                               const VkAllocationCallbacks*         p_allocator,
                                                               VkSurfaceKHR*                        p_surface);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_android_surface_khr(
    VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* p_create_info, const VkAllocationCallbacks* p_allocator,
    VkSurfaceKHR* p_surface) __asm("vkCreateAndroidSurfaceKHR");
#endif

#define vk_android_external_memory_android_hardware_buffer 1
struct ahardware_buffer;
#define VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_SPEC_VERSION 3
#define VK_ANDROID_EXTERNAL_MEMORY_ANDROID_HARDWARE_BUFFER_EXTENSION_NAME                                              \
    "VK_ANDROID_external_memory_android_hardware_buffer"
typedef struct VkAndroidHardwareBufferUsageANDROID {
    VkStructureType s_type;
    void*           p_next;
    uint64_t        android_hardware_buffer_usage;
} VkAndroidHardwareBufferUsageANDROID;

typedef struct VkAndroidHardwareBufferPropertiesANDROID {
    VkStructureType s_type;
    void*           p_next;
    VkDeviceSize    allocation_size;
    uint32_t        memory_type_bits;
} VkAndroidHardwareBufferPropertiesANDROID;

typedef struct VkAndroidHardwareBufferFormatPropertiesANDROID {
    VkStructureType               s_type;
    void*                         p_next;
    VkFormat                      format;
    uint64_t                      external_format;
    VkFormatFeatureFlags          format_features;
    VkComponentMapping            sampler_ycbcr_conversion_components;
    VkSamplerYcbcrModelConversion suggested_ycbcr_model;
    VkSamplerYcbcrRange           suggested_ycbcr_range;
    VkChromaLocation              suggested_xchroma_offset;
    VkChromaLocation              suggested_ychroma_offset;
} VkAndroidHardwareBufferFormatPropertiesANDROID;

typedef struct VkImportAndroidHardwareBufferInfoANDROID {
    VkStructureType          s_type;
    const void*              p_next;
    struct ahardware_buffer* buffer;
} VkImportAndroidHardwareBufferInfoANDROID;

typedef struct VkMemoryGetAndroidHardwareBufferInfoANDROID {
    VkStructureType s_type;
    const void*     p_next;
    VkDeviceMemory  memory;
} VkMemoryGetAndroidHardwareBufferInfoANDROID;

typedef struct VkExternalFormatANDROID {
    VkStructureType s_type;
    void*           p_next;
    uint64_t        external_format;
} VkExternalFormatANDROID;

typedef VkResult(VKAPI_PTR* pfn_vk_get_android_hardware_buffer_properties_android)(
    VkDevice device, const struct ahardware_buffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* p_properties);
typedef VkResult(VKAPI_PTR* pfn_vk_get_memory_android_hardware_buffer_android)(
    VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* p_info, struct ahardware_buffer** p_buffer);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_get_android_hardware_buffer_properties_android(
    VkDevice device, const struct ahardware_buffer* buffer,
    VkAndroidHardwareBufferPropertiesANDROID* p_properties) __asm("vkGetAndroidHardwareBufferPropertiesANDROID");

VKAPI_ATTR VkResult VKAPI_CALL vk_get_memory_android_hardware_buffer_android(
    VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* p_info,
    struct ahardware_buffer** p_buffer) __asm("vkGetMemoryAndroidHardwareBufferANDROID");
#endif

#ifdef __cplusplus
}
#endif

#endif
