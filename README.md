# pep8-vulkan
Vulkan headers transformed to follow [PEP8](https://www.python.org/dev/peps/pep-0008/)

Vulkan uses `camelCase` for functions and struct fields, `PascalCase` for types,
and `SCREAMING_SNAKE_CASE` for constants. My codebase uses PEP8 (even though it's C, I still like
PEP8), so I want the functions and attributes to be `snake_case`. So, I wrote `convert.c`
to rename functions and struct fields and add `__asm("originalName")` to retain
the correct linkage.

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
typedef struct VkInstanceCreateInfo {
    VkStructureType          s_type;
    const void*              p_next;
    VkInstanceCreateFlags    flags;
    const VkApplicationInfo* p_application_info;
    uint32_t                 enabled_layer_count;
    const char* const*       pp_enabled_layer_names;
    uint32_t                 enabled_extension_count;
    const char* const*       pp_enabled_extension_names;
} VkInstanceCreateInfo;

VKAPI_ATTR VkResult VKAPI_CALL vk_create_instance(const VkInstanceCreateInfo*  p_create_info,
                                                  const VkAllocationCallbacks* p_allocator,
                                                  VkInstance*                  p_instance) __asm("vkCreateInstance");
```
