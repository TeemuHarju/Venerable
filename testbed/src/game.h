#pragma once

#include <defines.h>
#include <game_types.h>

/**
 * @brief Represents the state of the game.
 */
typedef struct game_state {
	f32 delta_time; /**< The time elapsed since the last frame. */
} game_state;

/**
 * @brief Initializes the game.
 *
 * @param game_inst The game instance.
 * @return True if initialization is successful, false otherwise.
 */
b8 game_initialize( game* game_inst );

/**
 * @brief Updates the game state.
 *
 * @param game_inst The game instance.
 * @param delta_time The time elapsed since the last frame.
 * @return True if the update is successful, false otherwise.
 */
b8 game_update( game* game_inst, f32 delta_time );

/**
 * @brief Renders the game.
 *
 * @param game_inst The game instance.
 * @param delta_time The time elapsed since the last frame.
 * @return True if rendering is successful, false otherwise.
 */
b8 game_render( game* game_inst, f32 delta_time );

/**
 * @brief Handles the game resizing event.
 *
 * @param game_inst The game instance.
 * @param width The new width of the window.
 * @param height The new height of the window.
 */
void game_on_resize( game* game_inst, u32 width, u32 height );