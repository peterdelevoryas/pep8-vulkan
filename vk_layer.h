//
// file: vk_layer.h
//
/*
 * copyright (c) 2015-2017 the khronos group inc.
 * copyright (c) 2015-2017 valve corporation
 * copyright (c) 2015-2017 lunar_g, inc.
 *
 * licensed under the apache license, version 2.0 (the "License");
 * you may not use this file except in compliance with the license.
 * you may obtain a copy of the license at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * unless required by applicable law or agreed to in writing, software
 * distributed under the license is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * see the license for the specific language governing permissions and
 * limitations under the license.
 *
 */

/* need to define dispatch table
 * core struct can then have ptr to dispatch table at the top
 * along with object ptrs for current and next OBJ
 */
#pragma once

#include "vulkan.h"
#if defined(__GNUC__) && __GNUC__ >= 4
#define VK_LAYER_EXPORT __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#define VK_LAYER_EXPORT __attribute__((visibility("default")))
#else
#define VK_LAYER_EXPORT
#endif

#define MAX_NUM_UNKNOWN_EXTS 250

// loader-layer version negotiation API.  versions add the following features:
//   versions 0/1 - initial.  doesn't support vk_layer_get_physical_device_proc_addr
//                  or vk_icd_negotiate_loader_layer_interface_version.
//   version 2    - add support for vk_layer_get_physical_device_proc_addr and
//                  vk_icd_negotiate_loader_layer_interface_version.
#define CURRENT_LOADER_LAYER_INTERFACE_VERSION 2
#define MIN_SUPPORTED_LOADER_LAYER_INTERFACE_VERSION 1

#define VK_CURRENT_CHAIN_VERSION 1

// typedef for use in the interfaces below
typedef pfn_vk_void_function(VKAPI_PTR* pfn_get_physical_device_proc_addr)(
    VkInstance instance, const char* p_name) __asm("vk_icdNegotiateLoaderLayerInterfaceVersion");

// version negotiation values
typedef enum VkNegotiateLayerStructType {
    LAYER_NEGOTIATE_UNINTIALIZED     = 0,
    LAYER_NEGOTIATE_INTERFACE_STRUCT = 1,
} VkNegotiateLayerStructType;

// version negotiation structures
typedef struct VkNegotiateLayerInterface {
    VkNegotiateLayerStructType        s_type;
    void*                             p_next;
    uint32_t                          loader_layer_interface_version;
    pfn_vk_get_instance_proc_addr     pfn_get_instance_proc_addr;
    pfn_vk_get_device_proc_addr       pfn_get_device_proc_addr;
    pfn_get_physical_device_proc_addr pfn_get_physical_device_proc_addr;
} VkNegotiateLayerInterface;

// version negotiation functions
typedef VkResult(VKAPI_PTR* pfn_vk_negotiate_loader_layer_interface_version)(
    VkNegotiateLayerInterface* p_version_struct);

// function prototype for unknown physical device extension command
typedef VkResult(VKAPI_PTR* pfn_phys_dev_ext)(VkPhysicalDevice phys_device);

// ------------------------------------------------------------------------------------------------
// create_instance and create_device support structures

/* sub type of structure for instance and device loader ext of create_info.
 * when s_type == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO
 * or s_type == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO
 * then VkLayerFunction indicates struct type pointed to by p_next
 */
typedef enum VkLayerFunction_ {
    VK_LAYER_LINK_INFO                     = 0,
    VK_LOADER_DATA_CALLBACK                = 1,
    VK_LOADER_LAYER_CREATE_DEVICE_CALLBACK = 2,
    VK_LOADER_FEATURES                     = 3,
} VkLayerFunction;

typedef struct VkLayerInstanceLink_ {
    struct VkLayerInstanceLink_*      p_next;
    pfn_vk_get_instance_proc_addr     pfn_next_get_instance_proc_addr;
    pfn_get_physical_device_proc_addr pfn_next_get_physical_device_proc_addr;
} VkLayerInstanceLink;

/*
 * when creating the device chain the loader needs to pass
 * down information about it's device structure needed at
 * the end of the chain. passing the data via the
 * VkLayerDeviceInfo avoids issues with finding the
 * exact instance being used.
 */
typedef struct VkLayerDeviceInfo_ {
    void*                         device_info;
    pfn_vk_get_instance_proc_addr pfn_next_get_instance_proc_addr;
} VkLayerDeviceInfo;

typedef VkResult(VKAPI_PTR* pfn_vk_set_instance_loader_data)(VkInstance instance, void* object);
typedef VkResult(VKAPI_PTR* pfn_vk_set_device_loader_data)(VkDevice device, void* object);
typedef VkResult(VKAPI_PTR* pfn_vk_layer_create_device)(VkInstance instance, VkPhysicalDevice physical_device,
                                                        const VkDeviceCreateInfo*    p_create_info,
                                                        const VkAllocationCallbacks* p_allocator, VkDevice* p_device,
                                                        pfn_vk_get_instance_proc_addr layer_gipa,
                                                        pfn_vk_get_device_proc_addr*  next_gdpa);
typedef void(VKAPI_PTR* pfn_vk_layer_destroy_device)(VkDevice physical_device, const VkAllocationCallbacks* p_allocator,
                                                     pfn_vk_destroy_device destroy_function);

typedef enum VkLoaderFeastureFlagBits {
    VK_LOADER_FEATURE_PHYSICAL_DEVICE_SORTING = 0x00000001,
} VkLoaderFlagBits;
typedef VkFlags VkLoaderFeatureFlags;

typedef struct {
    VkStructureType s_type; // VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO
    const void*     p_next;
    VkLayerFunction function;
    union {
        VkLayerInstanceLink*            p_layer_info;
        pfn_vk_set_instance_loader_data pfn_set_instance_loader_data;
        struct {
            pfn_vk_layer_create_device  pfn_layer_create_device;
            pfn_vk_layer_destroy_device pfn_layer_destroy_device;
        } layer_device;
        VkLoaderFeatureFlags loader_features;
    } u;
} VkLayerInstanceCreateInfo;

typedef struct VkLayerDeviceLink_ {
    struct VkLayerDeviceLink_*    p_next;
    pfn_vk_get_instance_proc_addr pfn_next_get_instance_proc_addr;
    pfn_vk_get_device_proc_addr   pfn_next_get_device_proc_addr;
} VkLayerDeviceLink;

typedef struct {
    VkStructureType s_type; // VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO
    const void*     p_next;
    VkLayerFunction function;
    union {
        VkLayerDeviceLink*            p_layer_info;
        pfn_vk_set_device_loader_data pfn_set_device_loader_data;
    } u;
} VkLayerDeviceCreateInfo;

#ifdef __cplusplus
extern "C" {
#endif

VKAPI_ATTR VkResult VKAPI_CALL vk_negotiate_loader_layer_interface_version(
    VkNegotiateLayerInterface* p_version_struct) __asm("vkNegotiateLoaderLayerInterfaceVersion");

typedef enum VkChainType {
    VK_CHAIN_TYPE_UNKNOWN                                 = 0,
    VK_CHAIN_TYPE_ENUMERATE_INSTANCE_EXTENSION_PROPERTIES = 1,
    VK_CHAIN_TYPE_ENUMERATE_INSTANCE_LAYER_PROPERTIES     = 2,
    VK_CHAIN_TYPE_ENUMERATE_INSTANCE_VERSION              = 3,
} VkChainType;

typedef struct VkChainHeader {
    VkChainType type;
    uint32_t    version;
    uint32_t    size;
} VkChainHeader;

typedef struct VkEnumerateInstanceExtensionPropertiesChain {
    VkChainHeader header;
    VkResult(VKAPI_PTR* pfn_next_layer)(const struct VkEnumerateInstanceExtensionPropertiesChain*, const char*,
                                        uint32_t*, VkExtensionProperties*);
    const struct VkEnumerateInstanceExtensionPropertiesChain* p_next_link;

#if defined(__cplusplus)
    inline VkResult call_down(const char* p_layer_name, uint32_t* p_property_count,
                              VkExtensionProperties* p_properties) const {
        return pfn_next_layer(p_next_link, p_layer_name, p_property_count, p_properties);
    }
#endif
} VkEnumerateInstanceExtensionPropertiesChain;

typedef struct VkEnumerateInstanceLayerPropertiesChain {
    VkChainHeader header;
    VkResult(VKAPI_PTR* pfn_next_layer)(const struct VkEnumerateInstanceLayerPropertiesChain*, uint32_t*,
                                        VkLayerProperties*);
    const struct VkEnumerateInstanceLayerPropertiesChain* p_next_link;

#if defined(__cplusplus)
    inline VkResult call_down(uint32_t* p_property_count, VkLayerProperties* p_properties) const {
        return pfn_next_layer(p_next_link, p_property_count, p_properties);
    }
#endif
} VkEnumerateInstanceLayerPropertiesChain;

typedef struct VkEnumerateInstanceVersionChain {
    VkChainHeader header;
    VkResult(VKAPI_PTR* pfn_next_layer)(const struct VkEnumerateInstanceVersionChain*, uint32_t*);
    const struct VkEnumerateInstanceVersionChain* p_next_link;

#if defined(__cplusplus)
    inline VkResult call_down(uint32_t* p_api_version) const {
        return pfn_next_layer(p_next_link, p_api_version);
    }
#endif
} VkEnumerateInstanceVersionChain;

#ifdef __cplusplus
}
#endif
