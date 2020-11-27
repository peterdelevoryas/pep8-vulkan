#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "vulkan.h"

int main() {
    putenv("VK_INSTANCE_LAYERS=VK_LAYER_KHRONOS_validation");
    const char* extensions[] = {
        "VK_KHR_surface",
        "VK_KHR_xcb_surface",
        "VK_EXT_debug_report",
        "VK_EXT_debug_utils",
    };
    struct vk_instance_create_info info = {
        .s_type                     = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .enabled_extension_count    = 4,
        .pp_enabled_extension_names = extensions,
    };
    struct vk_instance* instance;
    vk_create_instance(&info, NULL, &instance);
    assert(instance);

    uint32_t           physical_device_count = 1;
    struct vk_physical_device* physical_device;
    vk_enumerate_physical_devices(instance, &physical_device_count, &physical_device);
    assert(physical_device);

    struct vk_physical_device_properties properties;
    vk_get_physical_device_properties(physical_device, &properties);
    printf("Using physical device '%s'\n", properties.device_name);

    vk_destroy_instance(instance, NULL);
}
