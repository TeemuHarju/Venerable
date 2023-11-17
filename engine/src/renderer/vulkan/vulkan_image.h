#pragma once

#include "vulkan_types.inl"

/**
 * @brief Creates a Vulkan image.
 *
 * @param context The Vulkan context.
 * @param image_type The type of the image.
 * @param width The width of the image.
 * @param height The height of the image.
 * @param format The format of the image.
 * @param tiling The tiling mode of the image.
 * @param usage The usage flags of the image.
 * @param memory_flags The memory property flags.
 * @param create_view Whether to create an image view.
 * @param view_aspect_flags The aspect flags for the image view.
 * @param out_image Pointer to the Vulkan image to be created.
 */
void vulkan_image_create(
	vulkan_context* context,
	VkImageType image_type,
	u32 width,
	u32 height,
	VkFormat format,
	VkImageTiling tiling,
	VkImageUsageFlags usage,
	VkMemoryPropertyFlags memory_flags,
	b32 create_view,
	VkImageAspectFlags view_aspect_flags,
	vulkan_image* out_image );

/**
 * @brief Creates a Vulkan image view.
 *
 * @param context The Vulkan context.
 * @param format The format of the image view.
 * @param image Pointer to the Vulkan image.
 * @param aspect_flags The aspect flags for the image view.
 */
void vulkan_image_view_create(
	vulkan_context* context,
	VkFormat format,
	vulkan_image* image,
	VkImageAspectFlags aspect_flags );

/**
 * @brief Destroys a Vulkan image.
 *
 * @param context The Vulkan context.
 * @param image Pointer to the Vulkan image to be destroyed.
 */
void vulkan_image_destroy( vulkan_context* context, vulkan_image* image );
