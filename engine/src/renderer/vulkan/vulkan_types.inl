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
 * @brief Represents the Vulkan swapchain support information.
 */
typedef struct vulkan_swapchain_support_info {
	VkSurfaceCapabilitiesKHR capabilities; /**< Vulkan surface capabilities. */
	u32 format_count;                     /**< Number of supported surface formats. */
	VkSurfaceFormatKHR* formats;          /**< Array of supported surface formats. */
	u32 present_mode_count;               /**< Number of supported presentation modes. */
	VkPresentModeKHR* present_modes;      /**< Array of supported presentation modes. */
} vulkan_swapchain_support_info;

/**
 * @brief Represents the Vulkan device.
 */
typedef struct vulkan_device {
	VkPhysicalDevice physical_device;              /**< Vulkan physical device. */
	VkDevice logical_device;                       /**< Vulkan logical device. */
	vulkan_swapchain_support_info swapchain_support; /**< Swapchain support information for the device. */
	i32 graphics_queue_index;                      /**< Index of the graphics queue. */
	i32 present_queue_index;                       /**< Index of the presentation queue. */
	i32 transfer_queue_index;                      /**< Index of the transfer queue. */
	VkPhysicalDeviceProperties properties;          /**< Physical device properties. */
	VkPhysicalDeviceFeatures features;              /**< Physical device features. */
	VkPhysicalDeviceMemoryProperties memory;        /**< Physical device memory properties. */
} vulkan_device;

/**
 * @brief Represents the Vulkan context.
 */
typedef struct vulkan_context {
	VkInstance instance;                  /**< Vulkan instance. */
	VkAllocationCallbacks* allocator;     /**< Vulkan allocation callbacks. */
	VkSurfaceKHR surface;                  /**< Vulkan surface. */

#if defined(_DEBUG)
	VkDebugUtilsMessengerEXT debug_messenger; /**< Vulkan debug messenger for debugging purposes. */
#endif

	vulkan_device device; /**< Vulkan device associated with the context. */
} vulkan_context;

