#pragma once

#include "defines.h"

/**
 * @brief Returns the length of the given string.
 *
 * @param str The input string.
 * @return The length of the string.
 */
VAPI u64 string_length( const char* str );

/**
 * @brief Duplicates the given string.
 *
 * @param str The input string to duplicate.
 * @return A dynamically allocated copy of the input string.
 *         The caller is responsible for freeing the memory.
 */
VAPI char* string_duplicate( const char* str );