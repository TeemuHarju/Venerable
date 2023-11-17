#pragma once

#include "defines.h"
#include "core/asserts.h"

#include <vulkan/vulkan.h>

// Checks the given expression's return value against VK_SUCCESS.
#define VK_CHECK(expr)               \
    {                                \
        KASSERT(expr == VK_SUCCESS); \
    }

/**
 * @brief Represents the Vulkan context.
 */
typedef struct vulkan_context {
	VkInstance instance;                  /**< The Vulkan instance. */
	VkAllocationCallbacks* allocator;     /**< The Vulkan allocation callbacks. */
#if defined(_DEBUG)
	VkDebugUtilsMessengerEXT debug_messenger;
#endif
} vulkan_context;
