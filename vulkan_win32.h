#ifndef VULKAN_WIN32_H_
#define VULKAN_WIN32_H_ 1

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

#define vk_khr_win32_surface 1
#define VK_KHR_WIN32_SURFACE_SPEC_VERSION 6
#define VK_KHR_WIN32_SURFACE_EXTENSION_NAME "VK_KHR_win32_surface"
typedef VkFlags VkWin32SurfaceCreateFlagsKHR;
typedef struct VkWin32SurfaceCreateInfoKHR {
    VkStructureType              s_type;
    const void*                  p_next;
    VkWin32SurfaceCreateFlagsKHR flags;
    HINSTANCE                    hinstance;
    HWND                         hwnd;
} VkWin32SurfaceCreateInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_create_win32_surface_khr)(VkInstance                         instance,
                                                             const VkWin32SurfaceCreateInfoKHR* p_create_info,
                                                             const VkAllocationCallbacks*       p_allocator,
                                                             VkSurfaceKHR*                      p_surface);
typedef VkBool32(VKAPI_PTR* pfn_vk_get_physical_device_win32_presentation_support_khr)(VkPhysicalDevice physical_device,
                                                                                       uint32_t queue_family_index);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_create_win32_surface_khr(VkInstance                         instance,
                                                           const VkWin32SurfaceCreateInfoKHR* p_create_info,
                                                           const VkAllocationCallbacks*       p_allocator,
                                                           VkSurfaceKHR* p_surface) __asm("vkCreateWin32SurfaceKHR");

VKAPI_ATTR VkBool32 VKAPI_CALL vk_get_physical_device_win32_presentation_support_khr(
    VkPhysicalDevice physical_device,
    uint32_t         queue_family_index) __asm("vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif

#define vk_khr_external_memory_win32 1
#define VK_KHR_EXTERNAL_MEMORY_WIN32_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME "VK_KHR_external_memory_win32"
typedef struct VkImportMemoryWin32HandleInfoKHR {
    VkStructureType                    s_type;
    const void*                        p_next;
    VkExternalMemoryHandleTypeFlagBits handle_type;
    HANDLE                             handle;
    LPCWSTR                            name;
} VkImportMemoryWin32HandleInfoKHR;

typedef struct VkExportMemoryWin32HandleInfoKHR {
    VkStructureType            s_type;
    const void*                p_next;
    const SECURITY_ATTRIBUTES* p_attributes;
    DWORD                      dw_access;
    LPCWSTR                    name;
} VkExportMemoryWin32HandleInfoKHR;

typedef struct VkMemoryWin32HandlePropertiesKHR {
    VkStructureType s_type;
    void*           p_next;
    uint32_t        memory_type_bits;
} VkMemoryWin32HandlePropertiesKHR;

typedef struct VkMemoryGetWin32HandleInfoKHR {
    VkStructureType                    s_type;
    const void*                        p_next;
    VkDeviceMemory                     memory;
    VkExternalMemoryHandleTypeFlagBits handle_type;
} VkMemoryGetWin32HandleInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_get_memory_win32_handle_khr)(
    VkDevice device, const VkMemoryGetWin32HandleInfoKHR* p_get_win32_handle_info, HANDLE* p_handle);
typedef VkResult(VKAPI_PTR* pfn_vk_get_memory_win32_handle_properties_khr)(
    VkDevice device, VkExternalMemoryHandleTypeFlagBits handle_type, HANDLE handle,
    VkMemoryWin32HandlePropertiesKHR* p_memory_win32_handle_properties);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL
vk_get_memory_win32_handle_khr(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* p_get_win32_handle_info,
                               HANDLE* p_handle) __asm("vkGetMemoryWin32HandleKHR");

VKAPI_ATTR VkResult VKAPI_CALL vk_get_memory_win32_handle_properties_khr(
    VkDevice device, VkExternalMemoryHandleTypeFlagBits handle_type, HANDLE handle,
    VkMemoryWin32HandlePropertiesKHR* p_memory_win32_handle_properties) __asm("vkGetMemoryWin32HandlePropertiesKHR");
#endif

#define vk_khr_win32_keyed_mutex 1
#define VK_KHR_WIN32_KEYED_MUTEX_SPEC_VERSION 1
#define VK_KHR_WIN32_KEYED_MUTEX_EXTENSION_NAME "VK_KHR_win32_keyed_mutex"
typedef struct VkWin32KeyedMutexAcquireReleaseInfoKHR {
    VkStructureType       s_type;
    const void*           p_next;
    uint32_t              acquire_count;
    const VkDeviceMemory* p_acquire_syncs;
    const uint64_t*       p_acquire_keys;
    const uint32_t*       p_acquire_timeouts;
    uint32_t              release_count;
    const VkDeviceMemory* p_release_syncs;
    const uint64_t*       p_release_keys;
} VkWin32KeyedMutexAcquireReleaseInfoKHR;

#define vk_khr_external_semaphore_win32 1
#define VK_KHR_EXTERNAL_SEMAPHORE_WIN32_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_SEMAPHORE_WIN32_EXTENSION_NAME "VK_KHR_external_semaphore_win32"
typedef struct VkImportSemaphoreWin32HandleInfoKHR {
    VkStructureType                       s_type;
    const void*                           p_next;
    VkSemaphore                           semaphore;
    VkSemaphoreImportFlags                flags;
    VkExternalSemaphoreHandleTypeFlagBits handle_type;
    HANDLE                                handle;
    LPCWSTR                               name;
} VkImportSemaphoreWin32HandleInfoKHR;

typedef struct VkExportSemaphoreWin32HandleInfoKHR {
    VkStructureType            s_type;
    const void*                p_next;
    const SECURITY_ATTRIBUTES* p_attributes;
    DWORD                      dw_access;
    LPCWSTR                    name;
} VkExportSemaphoreWin32HandleInfoKHR;

typedef struct VkD3D12FenceSubmitInfoKHR {
    VkStructureType s_type;
    const void*     p_next;
    uint32_t        wait_semaphore_values_count;
    const uint64_t* p_wait_semaphore_values;
    uint32_t        signal_semaphore_values_count;
    const uint64_t* p_signal_semaphore_values;
} VkD3D12FenceSubmitInfoKHR;

typedef struct VkSemaphoreGetWin32HandleInfoKHR {
    VkStructureType                       s_type;
    const void*                           p_next;
    VkSemaphore                           semaphore;
    VkExternalSemaphoreHandleTypeFlagBits handle_type;
} VkSemaphoreGetWin32HandleInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_import_semaphore_win32_handle_khr)(
    VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* p_import_semaphore_win32_handle_info);
typedef VkResult(VKAPI_PTR* pfn_vk_get_semaphore_win32_handle_khr)(
    VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* p_get_win32_handle_info, HANDLE* p_handle);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_import_semaphore_win32_handle_khr(
    VkDevice             device, const VkImportSemaphoreWin32HandleInfoKHR*
                         p_import_semaphore_win32_handle_info) __asm("vkImportSemaphoreWin32HandleKHR");

VKAPI_ATTR VkResult VKAPI_CALL
vk_get_semaphore_win32_handle_khr(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* p_get_win32_handle_info,
                                  HANDLE* p_handle) __asm("vkGetSemaphoreWin32HandleKHR");
#endif

#define vk_khr_external_fence_win32 1
#define VK_KHR_EXTERNAL_FENCE_WIN32_SPEC_VERSION 1
#define VK_KHR_EXTERNAL_FENCE_WIN32_EXTENSION_NAME "VK_KHR_external_fence_win32"
typedef struct VkImportFenceWin32HandleInfoKHR {
    VkStructureType                   s_type;
    const void*                       p_next;
    VkFence                           fence;
    VkFenceImportFlags                flags;
    VkExternalFenceHandleTypeFlagBits handle_type;
    HANDLE                            handle;
    LPCWSTR                           name;
} VkImportFenceWin32HandleInfoKHR;

typedef struct VkExportFenceWin32HandleInfoKHR {
    VkStructureType            s_type;
    const void*                p_next;
    const SECURITY_ATTRIBUTES* p_attributes;
    DWORD                      dw_access;
    LPCWSTR                    name;
} VkExportFenceWin32HandleInfoKHR;

typedef struct VkFenceGetWin32HandleInfoKHR {
    VkStructureType                   s_type;
    const void*                       p_next;
    VkFence                           fence;
    VkExternalFenceHandleTypeFlagBits handle_type;
} VkFenceGetWin32HandleInfoKHR;

typedef VkResult(VKAPI_PTR* pfn_vk_import_fence_win32_handle_khr)(
    VkDevice device, const VkImportFenceWin32HandleInfoKHR* p_import_fence_win32_handle_info);
typedef VkResult(VKAPI_PTR* pfn_vk_get_fence_win32_handle_khr)(
    VkDevice device, const VkFenceGetWin32HandleInfoKHR* p_get_win32_handle_info, HANDLE* p_handle);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_import_fence_win32_handle_khr(
    VkDevice                               device,
    const VkImportFenceWin32HandleInfoKHR* p_import_fence_win32_handle_info) __asm("vkImportFenceWin32HandleKHR");

VKAPI_ATTR VkResult VKAPI_CALL
vk_get_fence_win32_handle_khr(VkDevice device, const VkFenceGetWin32HandleInfoKHR* p_get_win32_handle_info,
                              HANDLE* p_handle) __asm("vkGetFenceWin32HandleKHR");
#endif

#define vk_nv_external_memory_win32 1
#define VK_NV_EXTERNAL_MEMORY_WIN32_SPEC_VERSION 1
#define VK_NV_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME "VK_NV_external_memory_win32"
typedef struct VkImportMemoryWin32HandleInfoNV {
    VkStructureType                   s_type;
    const void*                       p_next;
    VkExternalMemoryHandleTypeFlagsNV handle_type;
    HANDLE                            handle;
} VkImportMemoryWin32HandleInfoNV;

typedef struct VkExportMemoryWin32HandleInfoNV {
    VkStructureType            s_type;
    const void*                p_next;
    const SECURITY_ATTRIBUTES* p_attributes;
    DWORD                      dw_access;
} VkExportMemoryWin32HandleInfoNV;

typedef VkResult(VKAPI_PTR* pfn_vk_get_memory_win32_handle_nv)(VkDevice device, VkDeviceMemory memory,
                                                               VkExternalMemoryHandleTypeFlagsNV handle_type,
                                                               HANDLE*                           p_handle);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_get_memory_win32_handle_nv(VkDevice device, VkDeviceMemory memory,
                                                             VkExternalMemoryHandleTypeFlagsNV handle_type,
                                                             HANDLE* p_handle) __asm("vkGetMemoryWin32HandleNV");
#endif

#define vk_nv_win32_keyed_mutex 1
#define VK_NV_WIN32_KEYED_MUTEX_SPEC_VERSION 2
#define VK_NV_WIN32_KEYED_MUTEX_EXTENSION_NAME "VK_NV_win32_keyed_mutex"
typedef struct VkWin32KeyedMutexAcquireReleaseInfoNV {
    VkStructureType       s_type;
    const void*           p_next;
    uint32_t              acquire_count;
    const VkDeviceMemory* p_acquire_syncs;
    const uint64_t*       p_acquire_keys;
    const uint32_t*       p_acquire_timeout_milliseconds;
    uint32_t              release_count;
    const VkDeviceMemory* p_release_syncs;
    const uint64_t*       p_release_keys;
} VkWin32KeyedMutexAcquireReleaseInfoNV;

#define vk_ext_full_screen_exclusive 1
#define VK_EXT_FULL_SCREEN_EXCLUSIVE_SPEC_VERSION 4
#define VK_EXT_FULL_SCREEN_EXCLUSIVE_EXTENSION_NAME "VK_EXT_full_screen_exclusive"

typedef enum VkFullScreenExclusiveEXT {
    VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT                = 0,
    VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT                = 1,
    VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT             = 2,
    VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT = 3,
    VK_FULL_SCREEN_EXCLUSIVE_MAX_ENUM_EXT               = 0x7fffffff
} VkFullScreenExclusiveEXT;
typedef struct VkSurfaceFullScreenExclusiveInfoEXT {
    VkStructureType          s_type;
    void*                    p_next;
    VkFullScreenExclusiveEXT full_screen_exclusive;
} VkSurfaceFullScreenExclusiveInfoEXT;

typedef struct VkSurfaceCapabilitiesFullScreenExclusiveEXT {
    VkStructureType s_type;
    void*           p_next;
    VkBool32        full_screen_exclusive_supported;
} VkSurfaceCapabilitiesFullScreenExclusiveEXT;

typedef struct VkSurfaceFullScreenExclusiveWin32InfoEXT {
    VkStructureType s_type;
    const void*     p_next;
    HMONITOR        hmonitor;
} VkSurfaceFullScreenExclusiveWin32InfoEXT;

typedef VkResult(VKAPI_PTR* pfn_vk_get_physical_device_surface_present_modes2ext)(
    VkPhysicalDevice physical_device, const VkPhysicalDeviceSurfaceInfo2KHR* p_surface_info,
    uint32_t* p_present_mode_count, VkPresentModeKHR* p_present_modes);
typedef VkResult(VKAPI_PTR* pfn_vk_acquire_full_screen_exclusive_mode_ext)(VkDevice device, VkSwapchainKHR swapchain);
typedef VkResult(VKAPI_PTR* pfn_vk_release_full_screen_exclusive_mode_ext)(VkDevice device, VkSwapchainKHR swapchain);
typedef VkResult(VKAPI_PTR* pfn_vk_get_device_group_surface_present_modes2ext)(
    VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* p_surface_info, VkDeviceGroupPresentModeFlagsKHR* p_modes);

#ifndef VK_NO_PROTOTYPES
VKAPI_ATTR VkResult VKAPI_CALL vk_get_physical_device_surface_present_modes2ext(
    VkPhysicalDevice physical_device, const VkPhysicalDeviceSurfaceInfo2KHR* p_surface_info,
    uint32_t*         p_present_mode_count,
    VkPresentModeKHR* p_present_modes) __asm("vkGetPhysicalDeviceSurfacePresentModes2EXT");

VKAPI_ATTR VkResult VKAPI_CALL vk_acquire_full_screen_exclusive_mode_ext(
    VkDevice device, VkSwapchainKHR swapchain) __asm("vkAcquireFullScreenExclusiveModeEXT");

VKAPI_ATTR VkResult VKAPI_CALL vk_release_full_screen_exclusive_mode_ext(
    VkDevice device, VkSwapchainKHR swapchain) __asm("vkReleaseFullScreenExclusiveModeEXT");

VKAPI_ATTR VkResult VKAPI_CALL vk_get_device_group_surface_present_modes2ext(
    VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* p_surface_info,
    VkDeviceGroupPresentModeFlagsKHR* p_modes) __asm("vkGetDeviceGroupSurfacePresentModes2EXT");
#endif

#ifdef __cplusplus
}
#endif

#endif
