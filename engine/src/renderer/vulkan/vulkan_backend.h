#pragma once

#include "renderer/renderer_backend.h"

/**
 * @brief Initializes the Vulkan renderer backend.
 *
 * @param backend The renderer backend to initialize.
 * @param application_name The name of the application.
 * @param plat_state The platform state.
 * @return True if initialization is successful, false otherwise.
 */
b8 vulkan_renderer_backend_initialize( renderer_backend* backend, const char* application_name, struct platform_state* plat_state );

/**
 * @brief Shuts down the Vulkan renderer backend.
 *
 * @param backend The renderer backend to shut down.
 */
void vulkan_renderer_backend_shutdown( renderer_backend* backend );

/**
 * @brief Handles resizing events for the Vulkan renderer backend.
 *
 * @param backend The renderer backend.
 * @param width The new width after resizing.
 * @param height The new height after resizing.
 */
void vulkan_renderer_backend_on_resized( renderer_backend* backend, u16 width, u16 height );

/**
 * @brief Begins a frame for rendering with the Vulkan backend.
 *
 * @param backend The renderer backend.
 * @param delta_time The time elapsed since the last frame.
 * @return True if the frame begins successfully, false otherwise.
 */
b8 vulkan_renderer_backend_begin_frame( renderer_backend* backend, f32 delta_time );

/**
 * @brief Ends a frame for rendering with the Vulkan backend.
 *
 * @param backend The renderer backend.
 * @param delta_time The time elapsed since the last frame.
 * @return True if the frame ends successfully, false otherwise.
 */
b8 vulkan_renderer_backend_end_frame( renderer_backend* backend, f32 delta_time );
