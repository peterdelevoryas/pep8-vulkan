# pep8-vulkan

[PEP8](https://www.python.org/dev/peps/pep-0008/)

Example of the differences this project adds:

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

To use this in a cmake project:

```
$ cd your-project/
$ git submodule add https://github.com/peterdelevoryas/pep8-vulkan
```

In `your-project/CMakeLists.txt`:

```
cmake_minimum_required(VERSION 3.19)
project(your-project)

add_subdirectory(pep8-vulkan)

add_executable(your-target main.c)
target_link_libraries(your-target pep8-vulkan)
```

In source files:

```
...
#include "pep8-vulkan/vulkan.h"
...
```
