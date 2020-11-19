# snakey-vulkan
Vulkan headers transformed to snake_case

Really dump C program "convert.c" remaps identifiers from mixedCase to snake_case. Doesn't do it perfectly, but so far works good enough for me.

Still links with vulkan libraries by specifying `__asm("originalName")` as suffix on functions, to make sure the link-name is unmodified.

E.g.

```c
typedef struct VkInstanceCreateInfo {
    VkStructureType             sType;
    const void*                 pNext;
    VkInstanceCreateFlags       flags;
    const VkApplicationInfo*    pApplicationInfo;
    uint32_t                    enabledLayerCount;
    const char* const*          ppEnabledLayerNames;
    uint32_t                    enabledExtensionCount;
    const char* const*          ppEnabledExtensionNames;
} VkInstanceCreateInfo;

VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance);
```

gets changed to:

```c
typedef struct vk_instance_create_info {
    vk_structure_type             s_type;
    const void*                 p_next;
    vk_instance_create_flags       flags;
    const vk_application_info*    p_application_info;
    uint32_t                    enabled_layer_count;
    const char* const*          pp_enabled_layer_names;
    uint32_t                    enabled_extension_count;
    const char* const*          pp_enabled_extension_names;
} vk_instance_create_info;

VKAPI_ATTR vk_result VKAPI_CALL vk_create_instance(
    const vk_instance_create_info*                 p_create_info,
    const vk_allocation_callbacks*                p_allocator,
    vk_instance*                                 p_instance) __asm("vkCreateInstance");
```

An example test.c is included that makes an instance and gets a gpu:

```c
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "vulkan.h"

int main() {
        _putenv("VK_INSTANCE_LAYERS=VK_LAYER_KHRONOS_validation");
        const char *extensions[] = {
                "VK_KHR_surface",
                "VK_KHR_win32_surface",
                "VK_EXT_debug_report",
                "VK_EXT_debug_utils",
        };
        vk_instance_create_info info = {
                .s_type = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                .enabled_extension_count = 4,
                .pp_enabled_extension_names = extensions,
        };
        vk_instance instance;
        vk_create_instance(&info, NULL, &instance);
        assert(instance);

        uint32_t physical_device_count = 1;
        vk_physical_device physical_device;
        vk_enumerate_physical_devices(instance, &physical_device_count, &physical_device);
        assert(physical_device);

        vk_physical_device_properties properties;
        vk_get_physical_device_properties(physical_device, &properties);
        printf("Using physical device '%s'\n", properties.device_name);

        vk_destroy_instance(instance, NULL);
}
```
