#pragma once

#include "defines.h"

struct platform_state;
struct vulkan_context;

/**
 * @brief Creates a Vulkan surface for the specified platform.
 *
 * @param plat_state Pointer to the platform state.
 * @param context Pointer to the Vulkan context.
 * @return True if the Vulkan surface creation is successful, false otherwise.
 */
b8 platform_create_vulkan_surface(
	struct platform_state* plat_state,
	struct vulkan_context* context
);


/**
 * @brief Appends the names of required extensions for this platform to the provided dynamic array.
 *
 * @param[in,out] names_darray A dynamic array (DArray) pointer to which the extension names will be appended.
 *                              The function assumes that the array is already created and may modify its contents.
 */
void platform_get_required_extension_names( const char*** names_darray );