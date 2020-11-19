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
typedef pfn_vk_void_function (VKAPI_PTR *pfn_get_physical_device_proc_addr)(vk_instance instance, const char* p_name) __asm("vk_icdNegotiateLoaderLayerInterfaceVersion");

// version negotiation values
typedef enum vk_negotiate_layer_struct_type {
    LAYER_NEGOTIATE_UNINTIALIZED = 0,
    LAYER_NEGOTIATE_INTERFACE_STRUCT = 1,
} vk_negotiate_layer_struct_type;

// version negotiation structures
typedef struct vk_negotiate_layer_interface {
    vk_negotiate_layer_struct_type s_type;
    void *p_next;
    uint32_t loader_layer_interface_version;
    pfn_vk_get_instance_proc_addr pfn_get_instance_proc_addr;
    pfn_vk_get_device_proc_addr pfn_get_device_proc_addr;
    pfn_get_physical_device_proc_addr pfn_get_physical_device_proc_addr;
} vk_negotiate_layer_interface;

// version negotiation functions
typedef vk_result (VKAPI_PTR *pfn_vk_negotiate_loader_layer_interface_version)(vk_negotiate_layer_interface *p_version_struct);

// function prototype for unknown physical device extension command
typedef vk_result(VKAPI_PTR *pfn_phys_dev_ext)(vk_physical_device phys_device);

// ------------------------------------------------------------------------------------------------
// create_instance and create_device support structures

/* sub type of structure for instance and device loader ext of create_info.
 * when s_type == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO
 * or s_type == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO
 * then vk_layer_function indicates struct type pointed to by p_next
 */
typedef enum vk_layer_function_ {
    VK_LAYER_LINK_INFO = 0,
    VK_LOADER_DATA_CALLBACK = 1,
    VK_LOADER_LAYER_CREATE_DEVICE_CALLBACK = 2,
    VK_LOADER_FEATURES = 3,
} vk_layer_function;

typedef struct vk_layer_instance_link_ {
    struct vk_layer_instance_link_ *p_next;
    pfn_vk_get_instance_proc_addr pfn_next_get_instance_proc_addr;
    pfn_get_physical_device_proc_addr pfn_next_get_physical_device_proc_addr;
} vk_layer_instance_link;

/*
 * when creating the device chain the loader needs to pass
 * down information about it's device structure needed at
 * the end of the chain. passing the data via the
 * vk_layer_device_info avoids issues with finding the
 * exact instance being used.
 */
typedef struct vk_layer_device_info_ {
    void *device_info;
    pfn_vk_get_instance_proc_addr pfn_next_get_instance_proc_addr;
} vk_layer_device_info;

typedef vk_result (VKAPI_PTR *pfn_vk_set_instance_loader_data)(vk_instance instance,
        void *object);
typedef vk_result (VKAPI_PTR *pfn_vk_set_device_loader_data)(vk_device device,
        void *object);
typedef vk_result (VKAPI_PTR *pfn_vk_layer_create_device)(vk_instance instance, vk_physical_device physical_device, const vk_device_create_info *p_create_info,
						      const vk_allocation_callbacks *p_allocator, vk_device *p_device, pfn_vk_get_instance_proc_addr layer_gipa, pfn_vk_get_device_proc_addr *next_gdpa);
typedef void (VKAPI_PTR *pfn_vk_layer_destroy_device)(vk_device physical_device, const vk_allocation_callbacks *p_allocator, pfn_vk_destroy_device destroy_function);

typedef enum vk_loader_feasture_flag_bits {
    VK_LOADER_FEATURE_PHYSICAL_DEVICE_SORTING = 0x00000001,
} vk_loader_flag_bits;
typedef vk_flags vk_loader_feature_flags;

typedef struct {
    vk_structure_type s_type; // VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO
    const void *p_next;
    vk_layer_function function;
    union {
        vk_layer_instance_link *p_layer_info;
        pfn_vk_set_instance_loader_data pfn_set_instance_loader_data;
        struct {
	        pfn_vk_layer_create_device pfn_layer_create_device;
	        pfn_vk_layer_destroy_device pfn_layer_destroy_device;
	    } layer_device;
        vk_loader_feature_flags loader_features;
    } u;
} vk_layer_instance_create_info;

typedef struct vk_layer_device_link_ {
    struct vk_layer_device_link_ *p_next;
    pfn_vk_get_instance_proc_addr pfn_next_get_instance_proc_addr;
    pfn_vk_get_device_proc_addr pfn_next_get_device_proc_addr;
} vk_layer_device_link;

typedef struct {
    vk_structure_type s_type; // VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO
    const void *p_next;
    vk_layer_function function;
    union {
        vk_layer_device_link *p_layer_info;
        pfn_vk_set_device_loader_data pfn_set_device_loader_data;
    } u;
} vk_layer_device_create_info;

#ifdef __cplusplus
extern "C" {
#endif

VKAPI_ATTR vk_result VKAPI_CALL vk_negotiate_loader_layer_interface_version(vk_negotiate_layer_interface *p_version_struct) __asm("vkNegotiateLoaderLayerInterfaceVersion");

typedef enum vk_chain_type {
    VK_CHAIN_TYPE_UNKNOWN = 0,
    VK_CHAIN_TYPE_ENUMERATE_INSTANCE_EXTENSION_PROPERTIES = 1,
    VK_CHAIN_TYPE_ENUMERATE_INSTANCE_LAYER_PROPERTIES = 2,
    VK_CHAIN_TYPE_ENUMERATE_INSTANCE_VERSION = 3,
} vk_chain_type;

typedef struct vk_chain_header {
    vk_chain_type type;
    uint32_t version;
    uint32_t size;
} vk_chain_header;

typedef struct vk_enumerate_instance_extension_properties_chain {
    vk_chain_header header;
    vk_result(VKAPI_PTR *pfn_next_layer)(const struct vk_enumerate_instance_extension_properties_chain *, const char *, uint32_t *,
                                      vk_extension_properties *);
    const struct vk_enumerate_instance_extension_properties_chain *p_next_link;

#if defined(__cplusplus)
    inline vk_result call_down(const char *p_layer_name, uint32_t *p_property_count, vk_extension_properties *p_properties) const {
        return pfn_next_layer(p_next_link, p_layer_name, p_property_count, p_properties);
    }
#endif
} vk_enumerate_instance_extension_properties_chain;

typedef struct vk_enumerate_instance_layer_properties_chain {
    vk_chain_header header;
    vk_result(VKAPI_PTR *pfn_next_layer)(const struct vk_enumerate_instance_layer_properties_chain *, uint32_t *, vk_layer_properties *);
    const struct vk_enumerate_instance_layer_properties_chain *p_next_link;

#if defined(__cplusplus)
    inline vk_result call_down(uint32_t *p_property_count, vk_layer_properties *p_properties) const {
        return pfn_next_layer(p_next_link, p_property_count, p_properties);
    }
#endif
} vk_enumerate_instance_layer_properties_chain;

typedef struct vk_enumerate_instance_version_chain {
    vk_chain_header header;
    vk_result(VKAPI_PTR *pfn_next_layer)(const struct vk_enumerate_instance_version_chain *, uint32_t *);
    const struct vk_enumerate_instance_version_chain *p_next_link;

#if defined(__cplusplus)
    inline vk_result call_down(uint32_t *p_api_version) const {
        return pfn_next_layer(p_next_link, p_api_version);
    }
#endif
} vk_enumerate_instance_version_chain;

#ifdef __cplusplus
}
#endif
