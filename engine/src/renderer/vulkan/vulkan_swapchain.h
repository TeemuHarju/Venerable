#pragma once

#include "vulkan_types.inl"

/**
 * @brief Creates a Vulkan swapchain.
 *
 * @param context The Vulkan context.
 * @param width The width of the swapchain.
 * @param height The height of the swapchain.
 * @param out_swapchain Pointer to the Vulkan swapchain to be created.
 */
void vulkan_swapchain_create(
	vulkan_context* context,
	u32 width,
	u32 height,
	vulkan_swapchain* out_swapchain );

/**
 * @brief Recreates a Vulkan swapchain.
 *
 * @param context The Vulkan context.
 * @param width The width of the swapchain.
 * @param height The height of the swapchain.
 * @param swapchain Pointer to the Vulkan swapchain to be recreated.
 */
void vulkan_swapchain_recreate(
	vulkan_context* context,
	u32 width,
	u32 height,
	vulkan_swapchain* swapchain );

/**
 * @brief Destroys a Vulkan swapchain.
 *
 * @param context The Vulkan context.
 * @param swapchain Pointer to the Vulkan swapchain to be destroyed.
 */
void vulkan_swapchain_destroy(
	vulkan_context* context,
	vulkan_swapchain* swapchain );

/**
 * @brief Acquires the index of the next image in the swapchain.
 *
 * @param context The Vulkan context.
 * @param swapchain Pointer to the Vulkan swapchain.
 * @param timeout_ns The timeout in nanoseconds.
 * @param image_available_semaphore Semaphore signaling that an image is available.
 * @param fence Fence for synchronization.
 * @param out_image_index Pointer to store the acquired image index.
 * @return True if successful, false otherwise.
 */
b8 vulkan_swapchain_acquire_next_image_index(
	vulkan_context* context,
	vulkan_swapchain* swapchain,
	u64 timeout_ns,
	VkSemaphore image_available_semaphore,
	VkFence fence,
	u32* out_image_index );

/**
 * @brief Presents the image in the swapchain.
 *
 * @param context The Vulkan context.
 * @param swapchain Pointer to the Vulkan swapchain.
 * @param graphics_queue Vulkan graphics queue.
 * @param present_queue Vulkan present queue.
 * @param render_complete_semaphore Semaphore signaling the completion of rendering.
 * @param present_image_index The index of the image to present.
 */
void vulkan_swapchain_present(
	vulkan_context* context,
	vulkan_swapchain* swapchain,
	VkQueue graphics_queue,
	VkQueue present_queue,
	VkSemaphore render_complete_semaphore,
	u32 present_image_index );
