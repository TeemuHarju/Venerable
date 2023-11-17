#pragma once

#include "renderer_types.inl"

/**
 * @brief Represents the platform state.
 */
struct platform_state;

/**
 * @brief Creates a renderer backend of the specified type.
 *
 * @param type The type of renderer backend to create.
 * @param plat_state The platform state.
 * @param out_renderer_backend The pointer to the created renderer backend.
 * @return True if creation is successful, false otherwise.
 */
b8 renderer_backend_create( renderer_backend_type type, struct platform_state* plat_state, renderer_backend* out_renderer_backend );

/**
 * @brief Destroys the specified renderer backend.
 *
 * @param renderer_backend The renderer backend to destroy.
 */
void renderer_backend_destroy( renderer_backend* renderer_backend );
