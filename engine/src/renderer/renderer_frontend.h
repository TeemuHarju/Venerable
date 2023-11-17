#pragma once

#include "renderer_types.inl"

/**
 * @brief Represents static mesh data.
 */
struct static_mesh_data;

/**
 * @brief Represents the platform state.
 */
struct platform_state;

/**
 * @brief Initializes the renderer.
 *
 * @param application_name The name of the application.
 * @param plat_state The platform state.
 * @return True if initialization is successful, false otherwise.
 */
b8 renderer_initialize( const char* application_name, struct platform_state* plat_state );

/**
 * @brief Shuts down the renderer.
 */
void renderer_shutdown();

/**
 * @brief Notifies the renderer of a window resize event.
 *
 * @param width The new width of the window.
 * @param height The new height of the window.
 */
void renderer_on_resized( u16 width, u16 height );

/**
 * @brief Draws a frame in the renderer.
 *
 * @param packet The render packet containing information about the frame.
 * @return True if drawing the frame is successful, false otherwise.
 */
b8 renderer_draw_frame( render_packet* packet );
