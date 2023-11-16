#pragma once

#include "core/application.h"

/**
 * @brief Represents the basic game state in a game.
 *        Called for creation by the application.
 */
typedef struct game {
	application_config app_config; /**< The application configuration. */

	/**
	 * @brief Function pointer to the game's initialize function.
	 *
	 * @param game_inst Pointer to the game structure.
	 * @return true if initialization is successful, false otherwise.
	 */
	b8( *initialize )( struct game* game_inst );

	/**
	 * @brief Function pointer to the game's update function.
	 *
	 * @param game_inst Pointer to the game structure.
	 * @param delta_time Time elapsed since the last update.
	 * @return true if update is successful, false otherwise.
	 */
	b8( *update )( struct game* game_inst, f32 delta_time );

	/**
	 * @brief Function pointer to the game's render function.
	 *
	 * @param game_inst Pointer to the game structure.
	 * @param delta_time Time elapsed since the last render.
	 * @return true if rendering is successful, false otherwise.
	 */
	b8( *render )( struct game* game_inst, f32 delta_time );

	/**
	 * @brief Function pointer to handle resizes, if applicable.
	 *
	 * @param game_inst Pointer to the game structure.
	 * @param width New width after resizing.
	 * @param height New height after resizing.
	 */
	void ( *on_resize )( struct game* game_inst, u32 width, u32 height );

	void* state; /**< Game-specific game state. Created and managed by the game. */
} game;