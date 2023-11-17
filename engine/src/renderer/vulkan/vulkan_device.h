#pragma once

#include "vulkan_types.inl"

/**
 * @brief Creates a Vulkan device associated with the specified Vulkan context.
 *
 * @param[in] context The Vulkan context with the Vulkan instance to use.
 * @return True if the Vulkan device creation is successful; otherwise, false.
 */
b8 vulkan_device_create( vulkan_context* context );

/**
 * @brief Destroys the Vulkan device associated with the specified Vulkan context.
 *
 * @param[in] context The Vulkan context with the Vulkan device to destroy.
 */
void vulkan_device_destroy( vulkan_context* context );

/**
 * @brief Queries the Vulkan swapchain support information for a physical device and surface.
 *
 * @param[in]  physical_device  The Vulkan physical device.
 * @param[in]  surface          The Vulkan surface.
 * @param[out] out_support_info Pointer to the structure where swapchain support information will be stored.
 */
void vulkan_device_query_swapchain_support(
	VkPhysicalDevice physical_device,
	VkSurfaceKHR surface,
	vulkan_swapchain_support_info* out_support_info );
