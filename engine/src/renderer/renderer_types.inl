#pragma once

#include "defines.h"

/**
 * @brief Represents the types of renderer backends.
 */
typedef enum renderer_backend_type {
	RENDERER_BACKEND_TYPE_VULKAN,    /**< Vulkan renderer backend. */
	RENDERER_BACKEND_TYPE_OPENGL,    /**< OpenGL renderer backend. */
	RENDERER_BACKEND_TYPE_DIRECTX    /**< DirectX renderer backend. */
} renderer_backend_type;

/**
 * @brief Represents the renderer backend interface.
 */
typedef struct renderer_backend {
	struct platform_state* plat_state; /**< The platform state used by the renderer backend. */
	u64 frame_number;                  /**< The current frame number. */

	/**
	 * @brief Initializes the renderer backend.
	 *
	 * @param backend The renderer backend to initialize.
	 * @param application_name The name of the application.
	 * @param plat_state The platform state.
	 * @return True if initialization is successful, false otherwise.
	 */
	b8( *initialize )( struct renderer_backend* backend, const char* application_name, struct platform_state* plat_state );

	/**
	 * @brief Shuts down the renderer backend.
	 *
	 * @param backend The renderer backend to shut down.
	 */
	void ( *shutdown )( struct renderer_backend* backend );

	/**
	 * @brief Notifies the renderer backend of a window resize event.
	 *
	 * @param backend The renderer backend.
	 * @param width The new width of the window.
	 * @param height The new height of the window.
	 */
	void ( *resized )( struct renderer_backend* backend, u16 width, u16 height );

	/**
	 * @brief Begins a frame in the renderer backend.
	 *
	 * @param backend The renderer backend.
	 * @param delta_time The time elapsed since the last frame.
	 * @return True if the frame begins successfully, false otherwise.
	 */
	b8( *begin_frame )( struct renderer_backend* backend, f32 delta_time );

	/**
	 * @brief Ends a frame in the renderer backend.
	 *
	 * @param backend The renderer backend.
	 * @param delta_time The time elapsed since the last frame.
	 * @return True if the frame ends successfully, false otherwise.
	 */
	b8( *end_frame )( struct renderer_backend* backend, f32 delta_time );
} renderer_backend;

/**
 * @brief Represents a render packet.
 */
typedef struct render_packet {
	f32 delta_time; /**< The time elapsed since the last frame. */
} render_packet;