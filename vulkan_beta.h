#ifndef VULKAN_BETA_H_
#define VULKAN_BETA_H_ 1

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

#define vk_khr_portability_subset 1
#define VK_KHR_PORTABILITY_SUBSET_SPEC_VERSION 1
#define VK_KHR_PORTABILITY_SUBSET_EXTENSION_NAME "VK_KHR_portability_subset"
typedef struct VkPhysicalDevicePortabilitySubsetFeaturesKHR {
    VkStructureType s_type;
    void*           p_next;
    VkBool32        constant_alpha_color_blend_factors;
    VkBool32        events;
    VkBool32        image_view_format_reinterpretation;
    VkBool32        image_view_format_swizzle;
    VkBool32        image_view2don3dimage;
    VkBool32        multisample_array_image;
    VkBool32        mutable_comparison_samplers;
    VkBool32        point_polygons;
    VkBool32        sampler_mip_lod_bias;
    VkBool32        separate_stencil_mask_ref;
    VkBool32        shader_sample_rate_interpolation_functions;
    VkBool32        tessellation_isolines;
    VkBool32        tessellation_point_mode;
    VkBool32        triangle_fans;
    VkBool32        vertex_attribute_access_beyond_stride;
} VkPhysicalDevicePortabilitySubsetFeaturesKHR;

typedef struct VkPhysicalDevicePortabilitySubsetPropertiesKHR {
    VkStructureType s_type;
    void*           p_next;
    uint32_t        min_vertex_input_binding_stride_alignment;
} VkPhysicalDevicePortabilitySubsetPropertiesKHR;

#define vk_khr_deferred_host_operations 1
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDeferredOperationKHR)
#define VK_KHR_DEFERRED_HOST_OPERATIONS_SPEC_VERSION 3
#define VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME "VK_KHR_deferred_host_operations"
typedef struct VkDeferredOperationInfoKHR {
    VkStructureType        s_type;
    const void*            p_next;
    VkDeferredOperationKHR operation_handle;
} VkDeferredOperationInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_create_deferred_operation_khr)(VkDevice                     device,
                                                                  const VkAllocationCallbacks* p_allocator,
                                                                  VkDeferredOperationKHR*      p_deferred_operation);
typedef void(VKAPI_PTR* pfn_vk_destroy_deferred_operation_khr)(VkDevice device, VkDeferredOperationKHR operation,
                                                               const VkAllocationCallbacks* p_allocator);
typedef uint32_t(VKAPI_PTR* pfn_vk_get_deferred_operation_max_concurrency_khr)(VkDevice               device,
                                                                               VkDeferredOperationKHR operation);
typedef VkResult(VKAPI_PTR* pfn_vk_get_deferred_operation_result_khr)(VkDevice               device,
                                                                      VkDeferredOperationKHR operation);
typedef VkResult(VKAPI_PTR* pfn_vk_deferred_operation_join_khr)(VkDevice device, VkDeferredOperationKHR operation);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL
vk_create_deferred_operation_khr(VkDevice device, const VkAllocationCallbacks* p_allocator,
                                 VkDeferredOperationKHR* p_deferred_operation) __asm("vkCreateDeferredOperationKHR");

VKAPI_ATTR void VKAPI_CALL
vk_destroy_deferred_operation_khr(VkDevice device, VkDeferredOperationKHR operation,
                                  const VkAllocationCallbacks* p_allocator) __asm("vkDestroyDeferredOperationKHR");

VKAPI_ATTR uint32_t VKAPI_CALL vk_get_deferred_operation_max_concurrency_khr(
    VkDevice device, VkDeferredOperationKHR operation) __asm("vkGetDeferredOperationMaxConcurrencyKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_get_deferred_operation_result_khr(
    VkDevice device, VkDeferredOperationKHR operation) __asm("vkGetDeferredOperationResultKHR");

VKAPI_ATTR VkResult VKAPI_CALL
vk_deferred_operation_join_khr(VkDevice device, VkDeferredOperationKHR operation) __asm("vkDeferredOperationJoinKHR");
#endif

#define vk_khr_pipeline_library 1
#define VK_KHR_PIPELINE_LIBRARY_SPEC_VERSION 1
#define VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME "VK_KHR_pipeline_library"
typedef struct VkPipelineLibraryCreateInfoKHR {
    VkStructureType   s_type;
    const void*       p_next;
    uint32_t          library_count;
    const VkPipeline* p_libraries;
} VkPipelineLibraryCreateInfoKHR;

#define vk_khr_ray_tracing 1
#define VK_KHR_RAY_TRACING_SPEC_VERSION 8
#define VK_KHR_RAY_TRACING_EXTENSION_NAME "VK_KHR_ray_tracing"

typedef enum VkAccelerationStructureBuildTypeKHR {
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR           = 0,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR         = 1,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR = 2,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_MAX_ENUM_KHR       = 0x7fffffff
} VkAccelerationStructureBuildTypeKHR;
typedef union VkDeviceOrHostAddressKHR {
    VkDeviceAddress device_address;
    void*           host_address;
} VkDeviceOrHostAddressKHR;

typedef union VkDeviceOrHostAddressConstKHR {
    VkDeviceAddress device_address;
    const void*     host_address;
} VkDeviceOrHostAddressConstKHR;

typedef struct VkAccelerationStructureBuildOffsetInfoKHR {
    uint32_t primitive_count;
    uint32_t primitive_offset;
    uint32_t first_vertex;
    uint32_t transform_offset;
} VkAccelerationStructureBuildOffsetInfoKHR;

typedef struct VkRayTracingShaderGroupCreateInfoKHR {
    VkStructureType                s_type;
    const void*                    p_next;
    VkRayTracingShaderGroupTypeKHR type;
    uint32_t                       general_shader;
    uint32_t                       closest_hit_shader;
    uint32_t                       any_hit_shader;
    uint32_t                       intersection_shader;
    const void*                    p_shader_group_capture_replay_handle;
} VkRayTracingShaderGroupCreateInfoKHR;

typedef struct VkRayTracingPipelineInterfaceCreateInfoKHR {
    VkStructureType s_type;
    const void*     p_next;
    uint32_t        max_payload_size;
    uint32_t        max_attribute_size;
    uint32_t        max_callable_size;
} VkRayTracingPipelineInterfaceCreateInfoKHR;

typedef struct VkRayTracingPipelineCreateInfoKHR {
    VkStructureType                                   s_type;
    const void*                                       p_next;
    VkPipelineCreateFlags                             flags;
    uint32_t                                          stage_count;
    const VkPipelineShaderStageCreateInfo*            p_stages;
    uint32_t                                          group_count;
    const VkRayTracingShaderGroupCreateInfoKHR*       p_groups;
    uint32_t                                          max_recursion_depth;
    VkPipelineLibraryCreateInfoKHR                    libraries;
    const VkRayTracingPipelineInterfaceCreateInfoKHR* p_library_interface;
    VkPipelineLayout                                  layout;
    VkPipeline                                        base_pipeline_handle;
    int32_t                                           base_pipeline_index;
} VkRayTracingPipelineCreateInfoKHR;

typedef struct VkAccelerationStructureGeometryTrianglesDataKHR {
    VkStructureType               s_type;
    const void*                   p_next;
    VkFormat                      vertex_format;
    VkDeviceOrHostAddressConstKHR vertex_data;
    VkDeviceSize                  vertex_stride;
    VkIndexType                   index_type;
    VkDeviceOrHostAddressConstKHR index_data;
    VkDeviceOrHostAddressConstKHR transform_data;
} VkAccelerationStructureGeometryTrianglesDataKHR;

typedef struct VkAccelerationStructureGeometryAabbsDataKHR {
    VkStructureType               s_type;
    const void*                   p_next;
    VkDeviceOrHostAddressConstKHR data;
    VkDeviceSize                  stride;
} VkAccelerationStructureGeometryAabbsDataKHR;

typedef struct VkAccelerationStructureGeometryInstancesDataKHR {
    VkStructureType               s_type;
    const void*                   p_next;
    VkBool32                      array_of_pointers;
    VkDeviceOrHostAddressConstKHR data;
} VkAccelerationStructureGeometryInstancesDataKHR;

typedef union VkAccelerationStructureGeometryDataKHR {
    VkAccelerationStructureGeometryTrianglesDataKHR triangles;
    VkAccelerationStructureGeometryAabbsDataKHR     aabbs;
    VkAccelerationStructureGeometryInstancesDataKHR instances;
} VkAccelerationStructureGeometryDataKHR;

typedef struct VkAccelerationStructureGeometryKHR {
    VkStructureType                        s_type;
    const void*                            p_next;
    VkGeometryTypeKHR                      geometry_type;
    VkAccelerationStructureGeometryDataKHR geometry;
    VkGeometryFlagsKHR                     flags;
} VkAccelerationStructureGeometryKHR;

typedef struct VkAccelerationStructureBuildGeometryInfoKHR {
    VkStructureType                                  s_type;
    const void*                                      p_next;
    VkAccelerationStructureTypeKHR                   type;
    VkBuildAccelerationStructureFlagsKHR             flags;
    VkBool32                                         update;
    VkAccelerationStructureKHR                       src_acceleration_structure;
    VkAccelerationStructureKHR                       dst_acceleration_structure;
    VkBool32                                         geometry_array_of_pointers;
    uint32_t                                         geometry_count;
    const VkAccelerationStructureGeometryKHR* const* pp_geometries;
    VkDeviceOrHostAddressKHR                         scratch_data;
} VkAccelerationStructureBuildGeometryInfoKHR;

typedef struct VkAccelerationStructureCreateGeometryTypeInfoKHR {
    VkStructureType   s_type;
    const void*       p_next;
    VkGeometryTypeKHR geometry_type;
    uint32_t          max_primitive_count;
    VkIndexType       index_type;
    uint32_t          max_vertex_count;
    VkFormat          vertex_format;
    VkBool32          allows_transforms;
} VkAccelerationStructureCreateGeometryTypeInfoKHR;

typedef struct VkAccelerationStructureCreateInfoKHR {
    VkStructureType                                         s_type;
    const void*                                             p_next;
    VkDeviceSize                                            compacted_size;
    VkAccelerationStructureTypeKHR                          type;
    VkBuildAccelerationStructureFlagsKHR                    flags;
    uint32_t                                                max_geometry_count;
    const VkAccelerationStructureCreateGeometryTypeInfoKHR* p_geometry_infos;
    VkDeviceAddress                                         device_address;
} VkAccelerationStructureCreateInfoKHR;

typedef struct VkAccelerationStructureMemoryRequirementsInfoKHR {
    VkStructureType                                  s_type;
    const void*                                      p_next;
    VkAccelerationStructureMemoryRequirementsTypeKHR type;
    VkAccelerationStructureBuildTypeKHR              build_type;
    VkAccelerationStructureKHR                       acceleration_structure;
} VkAccelerationStructureMemoryRequirementsInfoKHR;

typedef struct VkPhysicalDeviceRayTracingFeaturesKHR {
    VkStructureType s_type;
    void*           p_next;
    VkBool32        ray_tracing;
    VkBool32        ray_tracing_shader_group_handle_capture_replay;
    VkBool32        ray_tracing_shader_group_handle_capture_replay_mixed;
    VkBool32        ray_tracing_acceleration_structure_capture_replay;
    VkBool32        ray_tracing_indirect_trace_rays;
    VkBool32        ray_tracing_indirect_acceleration_structure_build;
    VkBool32        ray_tracing_host_acceleration_structure_commands;
    VkBool32        ray_query;
    VkBool32        ray_tracing_primitive_culling;
} VkPhysicalDeviceRayTracingFeaturesKHR;

typedef struct VkPhysicalDeviceRayTracingPropertiesKHR {
    VkStructureType s_type;
    void*           p_next;
    uint32_t        shader_group_handle_size;
    uint32_t        max_recursion_depth;
    uint32_t        max_shader_group_stride;
    uint32_t        shader_group_base_alignment;
    uint64_t        max_geometry_count;
    uint64_t        max_instance_count;
    uint64_t        max_primitive_count;
    uint32_t        max_descriptor_set_acceleration_structures;
    uint32_t        shader_group_handle_capture_replay_size;
} VkPhysicalDeviceRayTracingPropertiesKHR;

typedef struct VkAccelerationStructureDeviceAddressInfoKHR {
    VkStructureType            s_type;
    const void*                p_next;
    VkAccelerationStructureKHR acceleration_structure;
} VkAccelerationStructureDeviceAddressInfoKHR;

typedef struct VkAccelerationStructureVersionKHR {
    VkStructureType s_type;
    const void*     p_next;
    const uint8_t*  version_data;
} VkAccelerationStructureVersionKHR;

typedef struct VkStridedBufferRegionKHR {
    VkBuffer     buffer;
    VkDeviceSize offset;
    VkDeviceSize stride;
    VkDeviceSize size;
} VkStridedBufferRegionKHR;

typedef struct VkTraceRaysIndirectCommandKHR {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
} VkTraceRaysIndirectCommandKHR;

typedef struct VkCopyAccelerationStructureToMemoryInfoKHR {
    VkStructureType                    s_type;
    const void*                        p_next;
    VkAccelerationStructureKHR         src;
    VkDeviceOrHostAddressKHR           dst;
    VkCopyAccelerationStructureModeKHR mode;
} VkCopyAccelerationStructureToMemoryInfoKHR;

typedef struct VkCopyMemoryToAccelerationStructureInfoKHR {
    VkStructureType                    s_type;
    const void*                        p_next;
    VkDeviceOrHostAddressConstKHR      src;
    VkAccelerationStructureKHR         dst;
    VkCopyAccelerationStructureModeKHR mode;
} VkCopyMemoryToAccelerationStructureInfoKHR;

typedef struct VkCopyAccelerationStructureInfoKHR {
    VkStructureType                    s_type;
    const void*                        p_next;
    VkAccelerationStructureKHR         src;
    VkAccelerationStructureKHR         dst;
    VkCopyAccelerationStructureModeKHR mode;
} VkCopyAccelerationStructureInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_create_acceleration_structure_khr)(
    VkDevice device, const VkAccelerationStructureCreateInfoKHR* p_create_info,
    const VkAllocationCallbacks* p_allocator, VkAccelerationStructureKHR* p_acceleration_structure);
typedef void(VKAPI_PTR* pfn_vk_get_acceleration_structure_memory_requirements_khr)(
    VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoKHR* p_info,
    VkMemoryRequirements2* p_memory_requirements);
typedef void(VKAPI_PTR* pfn_vk_cmd_build_acceleration_structure_khr)(
    VkCommandBuffer command_buffer, uint32_t info_count, const VkAccelerationStructureBuildGeometryInfoKHR* p_infos,
    const VkAccelerationStructureBuildOffsetInfoKHR* const* pp_offset_infos);
typedef void(VKAPI_PTR* pfn_vk_cmd_build_acceleration_structure_indirect_khr)(
    VkCommandBuffer command_buffer, const VkAccelerationStructureBuildGeometryInfoKHR* p_info, VkBuffer indirect_buffer,
    VkDeviceSize indirect_offset, uint32_t indirect_stride);
typedef VkResult(VKAPI_PTR* pfn_vk_build_acceleration_structure_khr)(
    VkDevice device, uint32_t info_count, const VkAccelerationStructureBuildGeometryInfoKHR* p_infos,
    const VkAccelerationStructureBuildOffsetInfoKHR* const* pp_offset_infos);
typedef VkResult(VKAPI_PTR* pfn_vk_copy_acceleration_structure_khr)(VkDevice                                  device,
                                                                    const VkCopyAccelerationStructureInfoKHR* p_info);
typedef VkResult(VKAPI_PTR* pfn_vk_copy_acceleration_structure_to_memory_khr)(
    VkDevice device, const VkCopyAccelerationStructureToMemoryInfoKHR* p_info);
typedef VkResult(VKAPI_PTR* pfn_vk_copy_memory_to_acceleration_structure_khr)(
    VkDevice device, const VkCopyMemoryToAccelerationStructureInfoKHR* p_info);
typedef VkResult(VKAPI_PTR* pfn_vk_write_acceleration_structures_properties_khr)(
    VkDevice device, uint32_t acceleration_structure_count, const VkAccelerationStructureKHR* p_acceleration_structures,
    VkQueryType query_type, size_t data_size, void* p_data, size_t stride);
typedef void(VKAPI_PTR* pfn_vk_cmd_copy_acceleration_structure_khr)(VkCommandBuffer command_buffer,
                                                                    const VkCopyAccelerationStructureInfoKHR* p_info);
typedef void(VKAPI_PTR* pfn_vk_cmd_copy_acceleration_structure_to_memory_khr)(
    VkCommandBuffer command_buffer, const VkCopyAccelerationStructureToMemoryInfoKHR* p_info);
typedef void(VKAPI_PTR* pfn_vk_cmd_copy_memory_to_acceleration_structure_khr)(
    VkCommandBuffer command_buffer, const VkCopyMemoryToAccelerationStructureInfoKHR* p_info);
typedef void(VKAPI_PTR* pfn_vk_cmd_trace_rays_khr)(VkCommandBuffer                 command_buffer,
                                                   const VkStridedBufferRegionKHR* p_raygen_shader_binding_table,
                                                   const VkStridedBufferRegionKHR* p_miss_shader_binding_table,
                                                   const VkStridedBufferRegionKHR* p_hit_shader_binding_table,
                                                   const VkStridedBufferRegionKHR* p_callable_shader_binding_table,
                                                   uint32_t width, uint32_t height, uint32_t depth);
typedef VkResult(VKAPI_PTR* pfn_vk_create_ray_tracing_pipelines_khr)(
    VkDevice device, VkPipelineCache pipeline_cache, uint32_t create_info_count,
    const VkRayTracingPipelineCreateInfoKHR* p_create_infos, const VkAllocationCallbacks* p_allocator,
    VkPipeline* p_pipelines);
typedef VkDeviceAddress(VKAPI_PTR* pfn_vk_get_acceleration_structure_device_address_khr)(
    VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* p_info);
typedef VkResult(VKAPI_PTR* pfn_vk_get_ray_tracing_capture_replay_shader_group_handles_khr)(
    VkDevice device, VkPipeline pipeline, uint32_t first_group, uint32_t group_count, size_t data_size, void* p_data);
typedef void(VKAPI_PTR* pfn_vk_cmd_trace_rays_indirect_khr)(
    VkCommandBuffer command_buffer, const VkStridedBufferRegionKHR* p_raygen_shader_binding_table,
    const VkStridedBufferRegionKHR* p_miss_shader_binding_table,
    const VkStridedBufferRegionKHR* p_hit_shader_binding_table,
    const VkStridedBufferRegionKHR* p_callable_shader_binding_table, VkBuffer buffer, VkDeviceSize offset);
typedef VkResult(VKAPI_PTR* pfn_vk_get_device_acceleration_structure_compatibility_khr)(
    VkDevice device, const VkAccelerationStructureVersionKHR* version);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_acceleration_structure_khr(
    VkDevice device, const VkAccelerationStructureCreateInfoKHR* p_create_info,
    const VkAllocationCallbacks* p_allocator,
    VkAccelerationStructureKHR*  p_acceleration_structure) __asm("vkCreateAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_get_acceleration_structure_memory_requirements_khr(
    VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoKHR* p_info,
    VkMemoryRequirements2* p_memory_requirements) __asm("vkGetAccelerationStructureMemoryRequirementsKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_build_acceleration_structure_khr(
    VkCommandBuffer command_buffer, uint32_t info_count, const VkAccelerationStructureBuildGeometryInfoKHR* p_infos,
    const VkAccelerationStructureBuildOffsetInfoKHR* const*
        pp_offset_infos) __asm("vkCmdBuildAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_build_acceleration_structure_indirect_khr(
    VkCommandBuffer command_buffer, const VkAccelerationStructureBuildGeometryInfoKHR* p_info, VkBuffer indirect_buffer,
    VkDeviceSize indirect_offset, uint32_t indirect_stride) __asm("vkCmdBuildAccelerationStructureIndirectKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_build_acceleration_structure_khr(
    VkDevice device, uint32_t info_count, const VkAccelerationStructureBuildGeometryInfoKHR* p_infos,
    const VkAccelerationStructureBuildOffsetInfoKHR* const* pp_offset_infos) __asm("vkBuildAccelerationStructureKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_copy_acceleration_structure_khr(
    VkDevice device, const VkCopyAccelerationStructureInfoKHR* p_info) __asm("vkCopyAccelerationStructureKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_copy_acceleration_structure_to_memory_khr(
    VkDevice                                          device,
    const VkCopyAccelerationStructureToMemoryInfoKHR* p_info) __asm("vkCopyAccelerationStructureToMemoryKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_copy_memory_to_acceleration_structure_khr(
    VkDevice                                          device,
    const VkCopyMemoryToAccelerationStructureInfoKHR* p_info) __asm("vkCopyMemoryToAccelerationStructureKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_write_acceleration_structures_properties_khr(
    VkDevice device, uint32_t acceleration_structure_count, const VkAccelerationStructureKHR* p_acceleration_structures,
    VkQueryType query_type, size_t data_size, void* p_data,
    size_t stride) __asm("vkWriteAccelerationStructuresPropertiesKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_copy_acceleration_structure_khr(
    VkCommandBuffer                           command_buffer,
    const VkCopyAccelerationStructureInfoKHR* p_info) __asm("vkCmdCopyAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_copy_acceleration_structure_to_memory_khr(
    VkCommandBuffer                                   command_buffer,
    const VkCopyAccelerationStructureToMemoryInfoKHR* p_info) __asm("vkCmdCopyAccelerationStructureToMemoryKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_copy_memory_to_acceleration_structure_khr(
    VkCommandBuffer                                   command_buffer,
    const VkCopyMemoryToAccelerationStructureInfoKHR* p_info) __asm("vkCmdCopyMemoryToAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_trace_rays_khr(VkCommandBuffer                 command_buffer,
                                                 const VkStridedBufferRegionKHR* p_raygen_shader_binding_table,
                                                 const VkStridedBufferRegionKHR* p_miss_shader_binding_table,
                                                 const VkStridedBufferRegionKHR* p_hit_shader_binding_table,
                                                 const VkStridedBufferRegionKHR* p_callable_shader_binding_table,
                                                 uint32_t width, uint32_t height,
                                                 uint32_t depth) __asm("vkCmdTraceRaysKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_create_ray_tracing_pipelines_khr(
    VkDevice device, VkPipelineCache pipeline_cache, uint32_t create_info_count,
    const VkRayTracingPipelineCreateInfoKHR* p_create_infos, const VkAllocationCallbacks* p_allocator,
    VkPipeline* p_pipelines) __asm("vkCreateRayTracingPipelinesKHR");

VKAPI_ATTR VkDeviceAddress VKAPI_CALL vk_get_acceleration_structure_device_address_khr(
    VkDevice                                           device,
    const VkAccelerationStructureDeviceAddressInfoKHR* p_info) __asm("vkGetAccelerationStructureDeviceAddressKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_get_ray_tracing_capture_replay_shader_group_handles_khr(
    VkDevice device, VkPipeline pipeline, uint32_t first_group, uint32_t group_count, size_t data_size,
    void* p_data) __asm("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_trace_rays_indirect_khr(
    VkCommandBuffer command_buffer, const VkStridedBufferRegionKHR* p_raygen_shader_binding_table,
    const VkStridedBufferRegionKHR* p_miss_shader_binding_table,
    const VkStridedBufferRegionKHR* p_hit_shader_binding_table,
    const VkStridedBufferRegionKHR* p_callable_shader_binding_table, VkBuffer buffer,
    VkDeviceSize offset) __asm("vkCmdTraceRaysIndirectKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_get_device_acceleration_structure_compatibility_khr(
    VkDevice                                 device,
    const VkAccelerationStructureVersionKHR* version) __asm("vkGetDeviceAccelerationStructureCompatibilityKHR");
#endif

#ifdef __cplusplus
}
#endif

#endif
