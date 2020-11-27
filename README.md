# snake-case-vulkan

For example:

```c
typedef struct VkInstanceCreateInfo {
    VkStructureType          sType;
    const void*              pNext;
    VkInstanceCreateFlags    flags;
    const VkApplicationInfo* pApplicationInfo;
    uint32_t                 enabledLayerCount;
    const char* const*       ppEnabledLayerNames;
    uint32_t                 enabledExtensionCount;
    const char* const*       ppEnabledExtensionNames;
} VkInstanceCreateInfo;

VKAPI_ATTR VkResult VKAPI_CALL vkCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                const VkAllocationCallbacks* pAllocator, VkInstance* pInstance);

```

```c
typedef struct vk_instance_create_info {
    vk_structure_type          s_type;
    const void*                p_next;
    vk_instance_create_flags   flags;
    const vk_application_info* p_application_info;
    uint32_t                   enabled_layer_count;
    const char* const*         pp_enabled_layer_names;
    uint32_t                   enabled_extension_count;
    const char* const*         pp_enabled_extension_names;
} vk_instance_create_info;

VKAPI_ATTR vk_result VKAPI_CALL vk_create_instance(const vk_instance_create_info* p_create_info,
                                                   const vk_allocation_callbacks* p_allocator,
                                                   vk_instance*                   p_instance) __asm("vkCreateInstance");
```

`TODO` Build headers with `cmake`.
