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
typedef struct vk_physical_device_portability_subset_features_khr {
    vk_structure_type s_type;
    void*             p_next;
    vk_bool32         constant_alpha_color_blend_factors;
    vk_bool32         events;
    vk_bool32         image_view_format_reinterpretation;
    vk_bool32         image_view_format_swizzle;
    vk_bool32         image_view2don3dimage;
    vk_bool32         multisample_array_image;
    vk_bool32         mutable_comparison_samplers;
    vk_bool32         point_polygons;
    vk_bool32         sampler_mip_lod_bias;
    vk_bool32         separate_stencil_mask_ref;
    vk_bool32         shader_sample_rate_interpolation_functions;
    vk_bool32         tessellation_isolines;
    vk_bool32         tessellation_point_mode;
    vk_bool32         triangle_fans;
    vk_bool32         vertex_attribute_access_beyond_stride;
} vk_physical_device_portability_subset_features_khr;

typedef struct vk_physical_device_portability_subset_properties_khr {
    vk_structure_type s_type;
    void*             p_next;
    uint32_t          min_vertex_input_binding_stride_alignment;
} vk_physical_device_portability_subset_properties_khr;

#define vk_khr_deferred_host_operations 1
VK_DEFINE_NON_DISPATCHABLE_HANDLE(vk_deferred_operation_khr)
#define VK_KHR_DEFERRED_HOST_OPERATIONS_SPEC_VERSION 3
#define VK_KHR_DEFERRED_HOST_OPERATIONS_EXTENSION_NAME "VK_KHR_deferred_host_operations"
typedef struct vk_deferred_operation_info_khr {
    vk_structure_type         s_type;
    const void*               p_next;
    vk_deferred_operation_khr operation_handle;
} vk_deferred_operation_info_khr;

typedef vk_result(VKAPI_PTR* pfn_vk_create_deferred_operation_khr)(vk_device                      device,
                                                                   const vk_allocation_callbacks* p_allocator,
                                                                   vk_deferred_operation_khr*     p_deferred_operation);
typedef void(VKAPI_PTR* pfn_vk_destroy_deferred_operation_khr)(vk_device device, vk_deferred_operation_khr operation,
                                                               const vk_allocation_callbacks* p_allocator);
typedef uint32_t(VKAPI_PTR* pfn_vk_get_deferred_operation_max_concurrency_khr)(vk_device                 device,
                                                                               vk_deferred_operation_khr operation);
typedef vk_result(VKAPI_PTR* pfn_vk_get_deferred_operation_result_khr)(vk_device                 device,
                                                                       vk_deferred_operation_khr operation);
typedef vk_result(VKAPI_PTR* pfn_vk_deferred_operation_join_khr)(vk_device device, vk_deferred_operation_khr operation);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL
vk_create_deferred_operation_khr(vk_device device, const vk_allocation_callbacks* p_allocator,
                                 vk_deferred_operation_khr* p_deferred_operation) __asm("vkCreateDeferredOperationKHR");

VKAPI_ATTR void VKAPI_CALL
vk_destroy_deferred_operation_khr(vk_device device, vk_deferred_operation_khr operation,
                                  const vk_allocation_callbacks* p_allocator) __asm("vkDestroyDeferredOperationKHR");

VKAPI_ATTR uint32_t VKAPI_CALL vk_get_deferred_operation_max_concurrency_khr(
    vk_device device, vk_deferred_operation_khr operation) __asm("vkGetDeferredOperationMaxConcurrencyKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_get_deferred_operation_result_khr(
    vk_device device, vk_deferred_operation_khr operation) __asm("vkGetDeferredOperationResultKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_deferred_operation_join_khr(
    vk_device device, vk_deferred_operation_khr operation) __asm("vkDeferredOperationJoinKHR");
#endif

#define vk_khr_pipeline_library 1
#define VK_KHR_PIPELINE_LIBRARY_SPEC_VERSION 1
#define VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME "VK_KHR_pipeline_library"
typedef struct vk_pipeline_library_create_info_khr {
    vk_structure_type  s_type;
    const void*        p_next;
    uint32_t           library_count;
    const vk_pipeline* p_libraries;
} vk_pipeline_library_create_info_khr;

#define vk_khr_ray_tracing 1
#define VK_KHR_RAY_TRACING_SPEC_VERSION 8
#define VK_KHR_RAY_TRACING_EXTENSION_NAME "VK_KHR_ray_tracing"

typedef enum vk_acceleration_structure_build_type_khr {
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR           = 0,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR         = 1,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR = 2,
    VK_ACCELERATION_STRUCTURE_BUILD_TYPE_MAX_ENUM_KHR       = 0x7fffffff
} vk_acceleration_structure_build_type_khr;
typedef union vk_device_or_host_address_khr {
    vk_device_address device_address;
    void*             host_address;
} vk_device_or_host_address_khr;

typedef union vk_device_or_host_address_const_khr {
    vk_device_address device_address;
    const void*       host_address;
} vk_device_or_host_address_const_khr;

typedef struct vk_acceleration_structure_build_offset_info_khr {
    uint32_t primitive_count;
    uint32_t primitive_offset;
    uint32_t first_vertex;
    uint32_t transform_offset;
} vk_acceleration_structure_build_offset_info_khr;

typedef struct vk_ray_tracing_shader_group_create_info_khr {
    vk_structure_type                    s_type;
    const void*                          p_next;
    vk_ray_tracing_shader_group_type_khr type;
    uint32_t                             general_shader;
    uint32_t                             closest_hit_shader;
    uint32_t                             any_hit_shader;
    uint32_t                             intersection_shader;
    const void*                          p_shader_group_capture_replay_handle;
} vk_ray_tracing_shader_group_create_info_khr;

typedef struct vk_ray_tracing_pipeline_interface_create_info_khr {
    vk_structure_type s_type;
    const void*       p_next;
    uint32_t          max_payload_size;
    uint32_t          max_attribute_size;
    uint32_t          max_callable_size;
} vk_ray_tracing_pipeline_interface_create_info_khr;

typedef struct vk_ray_tracing_pipeline_create_info_khr {
    vk_structure_type                                        s_type;
    const void*                                              p_next;
    vk_pipeline_create_flags                                 flags;
    uint32_t                                                 stage_count;
    const vk_pipeline_shader_stage_create_info*              p_stages;
    uint32_t                                                 group_count;
    const vk_ray_tracing_shader_group_create_info_khr*       p_groups;
    uint32_t                                                 max_recursion_depth;
    vk_pipeline_library_create_info_khr                      libraries;
    const vk_ray_tracing_pipeline_interface_create_info_khr* p_library_interface;
    vk_pipeline_layout                                       layout;
    vk_pipeline                                              base_pipeline_handle;
    int32_t                                                  base_pipeline_index;
} vk_ray_tracing_pipeline_create_info_khr;

typedef struct vk_acceleration_structure_geometry_triangles_data_khr {
    vk_structure_type                   s_type;
    const void*                         p_next;
    vk_format                           vertex_format;
    vk_device_or_host_address_const_khr vertex_data;
    vk_device_size                      vertex_stride;
    vk_index_type                       index_type;
    vk_device_or_host_address_const_khr index_data;
    vk_device_or_host_address_const_khr transform_data;
} vk_acceleration_structure_geometry_triangles_data_khr;

typedef struct vk_acceleration_structure_geometry_aabbs_data_khr {
    vk_structure_type                   s_type;
    const void*                         p_next;
    vk_device_or_host_address_const_khr data;
    vk_device_size                      stride;
} vk_acceleration_structure_geometry_aabbs_data_khr;

typedef struct vk_acceleration_structure_geometry_instances_data_khr {
    vk_structure_type                   s_type;
    const void*                         p_next;
    vk_bool32                           array_of_pointers;
    vk_device_or_host_address_const_khr data;
} vk_acceleration_structure_geometry_instances_data_khr;

typedef union vk_acceleration_structure_geometry_data_khr {
    vk_acceleration_structure_geometry_triangles_data_khr triangles;
    vk_acceleration_structure_geometry_aabbs_data_khr     aabbs;
    vk_acceleration_structure_geometry_instances_data_khr instances;
} vk_acceleration_structure_geometry_data_khr;

typedef struct vk_acceleration_structure_geometry_khr {
    vk_structure_type                           s_type;
    const void*                                 p_next;
    vk_geometry_type_khr                        geometry_type;
    vk_acceleration_structure_geometry_data_khr geometry;
    vk_geometry_flags_khr                       flags;
} vk_acceleration_structure_geometry_khr;

typedef struct vk_acceleration_structure_build_geometry_info_khr {
    vk_structure_type                                    s_type;
    const void*                                          p_next;
    vk_acceleration_structure_type_khr                   type;
    vk_build_acceleration_structure_flags_khr            flags;
    vk_bool32                                            update;
    vk_acceleration_structure_khr                        src_acceleration_structure;
    vk_acceleration_structure_khr                        dst_acceleration_structure;
    vk_bool32                                            geometry_array_of_pointers;
    uint32_t                                             geometry_count;
    const vk_acceleration_structure_geometry_khr* const* pp_geometries;
    vk_device_or_host_address_khr                        scratch_data;
} vk_acceleration_structure_build_geometry_info_khr;

typedef struct vk_acceleration_structure_create_geometry_type_info_khr {
    vk_structure_type    s_type;
    const void*          p_next;
    vk_geometry_type_khr geometry_type;
    uint32_t             max_primitive_count;
    vk_index_type        index_type;
    uint32_t             max_vertex_count;
    vk_format            vertex_format;
    vk_bool32            allows_transforms;
} vk_acceleration_structure_create_geometry_type_info_khr;

typedef struct vk_acceleration_structure_create_info_khr {
    vk_structure_type                                              s_type;
    const void*                                                    p_next;
    vk_device_size                                                 compacted_size;
    vk_acceleration_structure_type_khr                             type;
    vk_build_acceleration_structure_flags_khr                      flags;
    uint32_t                                                       max_geometry_count;
    const vk_acceleration_structure_create_geometry_type_info_khr* p_geometry_infos;
    vk_device_address                                              device_address;
} vk_acceleration_structure_create_info_khr;

typedef struct vk_acceleration_structure_memory_requirements_info_khr {
    vk_structure_type                                      s_type;
    const void*                                            p_next;
    vk_acceleration_structure_memory_requirements_type_khr type;
    vk_acceleration_structure_build_type_khr               build_type;
    vk_acceleration_structure_khr                          acceleration_structure;
} vk_acceleration_structure_memory_requirements_info_khr;

typedef struct vk_physical_device_ray_tracing_features_khr {
    vk_structure_type s_type;
    void*             p_next;
    vk_bool32         ray_tracing;
    vk_bool32         ray_tracing_shader_group_handle_capture_replay;
    vk_bool32         ray_tracing_shader_group_handle_capture_replay_mixed;
    vk_bool32         ray_tracing_acceleration_structure_capture_replay;
    vk_bool32         ray_tracing_indirect_trace_rays;
    vk_bool32         ray_tracing_indirect_acceleration_structure_build;
    vk_bool32         ray_tracing_host_acceleration_structure_commands;
    vk_bool32         ray_query;
    vk_bool32         ray_tracing_primitive_culling;
} vk_physical_device_ray_tracing_features_khr;

typedef struct vk_physical_device_ray_tracing_properties_khr {
    vk_structure_type s_type;
    void*             p_next;
    uint32_t          shader_group_handle_size;
    uint32_t          max_recursion_depth;
    uint32_t          max_shader_group_stride;
    uint32_t          shader_group_base_alignment;
    uint64_t          max_geometry_count;
    uint64_t          max_instance_count;
    uint64_t          max_primitive_count;
    uint32_t          max_descriptor_set_acceleration_structures;
    uint32_t          shader_group_handle_capture_replay_size;
} vk_physical_device_ray_tracing_properties_khr;

typedef struct vk_acceleration_structure_device_address_info_khr {
    vk_structure_type             s_type;
    const void*                   p_next;
    vk_acceleration_structure_khr acceleration_structure;
} vk_acceleration_structure_device_address_info_khr;

typedef struct vk_acceleration_structure_version_khr {
    vk_structure_type s_type;
    const void*       p_next;
    const uint8_t*    version_data;
} vk_acceleration_structure_version_khr;

typedef struct vk_strided_buffer_region_khr {
    vk_buffer      buffer;
    vk_device_size offset;
    vk_device_size stride;
    vk_device_size size;
} vk_strided_buffer_region_khr;

typedef struct vk_trace_rays_indirect_command_khr {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
} vk_trace_rays_indirect_command_khr;

typedef struct vk_copy_acceleration_structure_to_memory_info_khr {
    vk_structure_type                       s_type;
    const void*                             p_next;
    vk_acceleration_structure_khr           src;
    vk_device_or_host_address_khr           dst;
    vk_copy_acceleration_structure_mode_khr mode;
} vk_copy_acceleration_structure_to_memory_info_khr;

typedef struct vk_copy_memory_to_acceleration_structure_info_khr {
    vk_structure_type                       s_type;
    const void*                             p_next;
    vk_device_or_host_address_const_khr     src;
    vk_acceleration_structure_khr           dst;
    vk_copy_acceleration_structure_mode_khr mode;
} vk_copy_memory_to_acceleration_structure_info_khr;

typedef struct vk_copy_acceleration_structure_info_khr {
    vk_structure_type                       s_type;
    const void*                             p_next;
    vk_acceleration_structure_khr           src;
    vk_acceleration_structure_khr           dst;
    vk_copy_acceleration_structure_mode_khr mode;
} vk_copy_acceleration_structure_info_khr;

typedef vk_result(VKAPI_PTR* pfn_vk_create_acceleration_structure_khr)(
    vk_device device, const vk_acceleration_structure_create_info_khr* p_create_info,
    const vk_allocation_callbacks* p_allocator, vk_acceleration_structure_khr* p_acceleration_structure);
typedef void(VKAPI_PTR* pfn_vk_get_acceleration_structure_memory_requirements_khr)(
    vk_device device, const vk_acceleration_structure_memory_requirements_info_khr* p_info,
    vk_memory_requirements2* p_memory_requirements);
typedef void(VKAPI_PTR* pfn_vk_cmd_build_acceleration_structure_khr)(
    vk_command_buffer command_buffer, uint32_t info_count,
    const vk_acceleration_structure_build_geometry_info_khr*      p_infos,
    const vk_acceleration_structure_build_offset_info_khr* const* pp_offset_infos);
typedef void(VKAPI_PTR* pfn_vk_cmd_build_acceleration_structure_indirect_khr)(
    vk_command_buffer command_buffer, const vk_acceleration_structure_build_geometry_info_khr* p_info,
    vk_buffer indirect_buffer, vk_device_size indirect_offset, uint32_t indirect_stride);
typedef vk_result(VKAPI_PTR* pfn_vk_build_acceleration_structure_khr)(
    vk_device device, uint32_t info_count, const vk_acceleration_structure_build_geometry_info_khr* p_infos,
    const vk_acceleration_structure_build_offset_info_khr* const* pp_offset_infos);
typedef vk_result(VKAPI_PTR* pfn_vk_copy_acceleration_structure_khr)(
    vk_device device, const vk_copy_acceleration_structure_info_khr* p_info);
typedef vk_result(VKAPI_PTR* pfn_vk_copy_acceleration_structure_to_memory_khr)(
    vk_device device, const vk_copy_acceleration_structure_to_memory_info_khr* p_info);
typedef vk_result(VKAPI_PTR* pfn_vk_copy_memory_to_acceleration_structure_khr)(
    vk_device device, const vk_copy_memory_to_acceleration_structure_info_khr* p_info);
typedef vk_result(VKAPI_PTR* pfn_vk_write_acceleration_structures_properties_khr)(
    vk_device device, uint32_t acceleration_structure_count,
    const vk_acceleration_structure_khr* p_acceleration_structures, vk_query_type query_type, size_t data_size,
    void* p_data, size_t stride);
typedef void(VKAPI_PTR* pfn_vk_cmd_copy_acceleration_structure_khr)(
    vk_command_buffer command_buffer, const vk_copy_acceleration_structure_info_khr* p_info);
typedef void(VKAPI_PTR* pfn_vk_cmd_copy_acceleration_structure_to_memory_khr)(
    vk_command_buffer command_buffer, const vk_copy_acceleration_structure_to_memory_info_khr* p_info);
typedef void(VKAPI_PTR* pfn_vk_cmd_copy_memory_to_acceleration_structure_khr)(
    vk_command_buffer command_buffer, const vk_copy_memory_to_acceleration_structure_info_khr* p_info);
typedef void(VKAPI_PTR* pfn_vk_cmd_trace_rays_khr)(vk_command_buffer                   command_buffer,
                                                   const vk_strided_buffer_region_khr* p_raygen_shader_binding_table,
                                                   const vk_strided_buffer_region_khr* p_miss_shader_binding_table,
                                                   const vk_strided_buffer_region_khr* p_hit_shader_binding_table,
                                                   const vk_strided_buffer_region_khr* p_callable_shader_binding_table,
                                                   uint32_t width, uint32_t height, uint32_t depth);
typedef vk_result(VKAPI_PTR* pfn_vk_create_ray_tracing_pipelines_khr)(
    vk_device device, vk_pipeline_cache pipeline_cache, uint32_t create_info_count,
    const vk_ray_tracing_pipeline_create_info_khr* p_create_infos, const vk_allocation_callbacks* p_allocator,
    vk_pipeline* p_pipelines);
typedef vk_device_address(VKAPI_PTR* pfn_vk_get_acceleration_structure_device_address_khr)(
    vk_device device, const vk_acceleration_structure_device_address_info_khr* p_info);
typedef vk_result(VKAPI_PTR* pfn_vk_get_ray_tracing_capture_replay_shader_group_handles_khr)(
    vk_device device, vk_pipeline pipeline, uint32_t first_group, uint32_t group_count, size_t data_size, void* p_data);
typedef void(VKAPI_PTR* pfn_vk_cmd_trace_rays_indirect_khr)(
    vk_command_buffer command_buffer, const vk_strided_buffer_region_khr* p_raygen_shader_binding_table,
    const vk_strided_buffer_region_khr* p_miss_shader_binding_table,
    const vk_strided_buffer_region_khr* p_hit_shader_binding_table,
    const vk_strided_buffer_region_khr* p_callable_shader_binding_table, vk_buffer buffer, vk_device_size offset);
typedef vk_result(VKAPI_PTR* pfn_vk_get_device_acceleration_structure_compatibility_khr)(
    vk_device device, const vk_acceleration_structure_version_khr* version);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR vk_result VKAPI_CALL vk_create_acceleration_structure_khr(
    vk_device device, const vk_acceleration_structure_create_info_khr* p_create_info,
    const vk_allocation_callbacks* p_allocator,
    vk_acceleration_structure_khr* p_acceleration_structure) __asm("vkCreateAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_get_acceleration_structure_memory_requirements_khr(
    vk_device device, const vk_acceleration_structure_memory_requirements_info_khr* p_info,
    vk_memory_requirements2* p_memory_requirements) __asm("vkGetAccelerationStructureMemoryRequirementsKHR");

VKAPI_ATTR void VKAPI_CALL
vk_cmd_build_acceleration_structure_khr(vk_command_buffer command_buffer, uint32_t info_count,
                                        const vk_acceleration_structure_build_geometry_info_khr* p_infos,
                                        const vk_acceleration_structure_build_offset_info_khr* const*
                                            pp_offset_infos) __asm("vkCmdBuildAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_build_acceleration_structure_indirect_khr(
    vk_command_buffer command_buffer, const vk_acceleration_structure_build_geometry_info_khr* p_info,
    vk_buffer indirect_buffer, vk_device_size indirect_offset,
    uint32_t indirect_stride) __asm("vkCmdBuildAccelerationStructureIndirectKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_build_acceleration_structure_khr(
    vk_device device, uint32_t info_count, const vk_acceleration_structure_build_geometry_info_khr* p_infos,
    const vk_acceleration_structure_build_offset_info_khr* const*
        pp_offset_infos) __asm("vkBuildAccelerationStructureKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_copy_acceleration_structure_khr(
    vk_device device, const vk_copy_acceleration_structure_info_khr* p_info) __asm("vkCopyAccelerationStructureKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_copy_acceleration_structure_to_memory_khr(
    vk_device                                                device,
    const vk_copy_acceleration_structure_to_memory_info_khr* p_info) __asm("vkCopyAccelerationStructureToMemoryKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_copy_memory_to_acceleration_structure_khr(
    vk_device                                                device,
    const vk_copy_memory_to_acceleration_structure_info_khr* p_info) __asm("vkCopyMemoryToAccelerationStructureKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_write_acceleration_structures_properties_khr(
    vk_device device, uint32_t acceleration_structure_count,
    const vk_acceleration_structure_khr* p_acceleration_structures, vk_query_type query_type, size_t data_size,
    void* p_data, size_t stride) __asm("vkWriteAccelerationStructuresPropertiesKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_copy_acceleration_structure_khr(
    vk_command_buffer                              command_buffer,
    const vk_copy_acceleration_structure_info_khr* p_info) __asm("vkCmdCopyAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_copy_acceleration_structure_to_memory_khr(
    vk_command_buffer                                        command_buffer,
    const vk_copy_acceleration_structure_to_memory_info_khr* p_info) __asm("vkCmdCopyAccelerationStructureToMemoryKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_copy_memory_to_acceleration_structure_khr(
    vk_command_buffer                                        command_buffer,
    const vk_copy_memory_to_acceleration_structure_info_khr* p_info) __asm("vkCmdCopyMemoryToAccelerationStructureKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_trace_rays_khr(vk_command_buffer                   command_buffer,
                                                 const vk_strided_buffer_region_khr* p_raygen_shader_binding_table,
                                                 const vk_strided_buffer_region_khr* p_miss_shader_binding_table,
                                                 const vk_strided_buffer_region_khr* p_hit_shader_binding_table,
                                                 const vk_strided_buffer_region_khr* p_callable_shader_binding_table,
                                                 uint32_t width, uint32_t height,
                                                 uint32_t depth) __asm("vkCmdTraceRaysKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_create_ray_tracing_pipelines_khr(
    vk_device device, vk_pipeline_cache pipeline_cache, uint32_t create_info_count,
    const vk_ray_tracing_pipeline_create_info_khr* p_create_infos, const vk_allocation_callbacks* p_allocator,
    vk_pipeline* p_pipelines) __asm("vkCreateRayTracingPipelinesKHR");

VKAPI_ATTR vk_device_address VKAPI_CALL vk_get_acceleration_structure_device_address_khr(
    vk_device             device, const vk_acceleration_structure_device_address_info_khr*
                          p_info) __asm("vkGetAccelerationStructureDeviceAddressKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_get_ray_tracing_capture_replay_shader_group_handles_khr(
    vk_device device, vk_pipeline pipeline, uint32_t first_group, uint32_t group_count, size_t data_size,
    void* p_data) __asm("vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");

VKAPI_ATTR void VKAPI_CALL vk_cmd_trace_rays_indirect_khr(
    vk_command_buffer command_buffer, const vk_strided_buffer_region_khr* p_raygen_shader_binding_table,
    const vk_strided_buffer_region_khr* p_miss_shader_binding_table,
    const vk_strided_buffer_region_khr* p_hit_shader_binding_table,
    const vk_strided_buffer_region_khr* p_callable_shader_binding_table, vk_buffer buffer,
    vk_device_size offset) __asm("vkCmdTraceRaysIndirectKHR");

VKAPI_ATTR vk_result VKAPI_CALL vk_get_device_acceleration_structure_compatibility_khr(
    vk_device                                    device,
    const vk_acceleration_structure_version_khr* version) __asm("vkGetDeviceAccelerationStructureCompatibilityKHR");
#endif

#ifdef __cplusplus
}
#endif

#endif
