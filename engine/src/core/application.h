#pragma once

#include "defines.h"

/**
 * @brief Represents the game structure.
 */
struct game;

/**
 * @brief Represents the configuration for the application.
 */
typedef struct application_config {
	i16 start_pos_x;	/**< Window starting position on the x-axis, if applicable. */
	i16 start_pos_y;	/**< Window starting position on the y-axis, if applicable. */
	i16 start_width;	/**< Window starting width, if applicable. */
	i16 start_height;	/**< Window starting height, if applicable. */
	const char* name;			/**< The application name used in windowing, if applicable. */
} application_config;

/**
 * @brief Creates the application instance.
 *
 * @param game_inst Pointer to the game structure.
 * @return true if the application creation is successful, false otherwise.
 */
VAPI b8 application_create( struct game* game_inst );

/**
 * @brief Runs the application.
 *
 * @return true if the application runs successfully, false otherwise.
 */
VAPI b8 application_run();