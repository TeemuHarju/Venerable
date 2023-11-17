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

	VkQueue graphics_queue;                        /**< Graphics queue. */
	VkQueue present_queue;                         /**< Presentation queue. */
	VkQueue transfer_queue;                        /**< Transfer queue. */

	VkPhysicalDeviceProperties properties;         /**< Physical device properties. */
	VkPhysicalDeviceFeatures features;             /**< Physical device features. */
	VkPhysicalDeviceMemoryProperties memory;       /**< Physical device memory properties. */

	VkFormat depth_format;                         /**< Detected depth format. */
} vulkan_device;

/**
 * @brief Represents a Vulkan image.
 */
typedef struct vulkan_image {
	VkImage handle;         /**< Vulkan image handle. */
	VkDeviceMemory memory;  /**< Vulkan device memory. */
	VkImageView view;       /**< Vulkan image view. */
	u32 width;              /**< Image width. */
	u32 height;             /**< Image height. */
} vulkan_image;

/**
 * @brief Represents the Vulkan swapchain.
 */
typedef struct vulkan_swapchain {
	VkSurfaceFormatKHR image_format;  /**< Surface format for the images. */
	u8 max_frames_in_flight;         /**< Maximum frames in flight. */
	VkSwapchainKHR handle;           /**< Vulkan swapchain handle. */
	u32 image_count;                 /**< Number of images in the swapchain. */
	VkImage* images;                 /**< Array of Vulkan images. */
	VkImageView* views;              /**< Array of Vulkan image views. */

	vulkan_image depth_attachment;   /**< Depth attachment for the swapchain. */
} vulkan_swapchain;


/**
 * @brief Represents the Vulkan context.
 */
typedef struct vulkan_context {

	u32 framebuffer_width;                /**<The framebuffer's current height.*/

	u32 framebuffer_height;               /**< The framebuffer's current height. */

	VkInstance instance;                  /**< Vulkan instance. */
	VkAllocationCallbacks* allocator;     /**< Vulkan allocation callbacks. */
	VkSurfaceKHR surface;                 /**< Vulkan surface. */

#if defined(_DEBUG)
	VkDebugUtilsMessengerEXT debug_messenger; /**< Vulkan debug messenger for debugging purposes. */
#endif

	vulkan_device device; /**< Vulkan device associated with the context. */

	vulkan_swapchain swapchain;
	u32 image_index;
	u32 current_frame;

	b8 recreating_swapchain;

	i32( *find_memory_index )( u32 type_filter, u32 property_flags );

} vulkan_context;

