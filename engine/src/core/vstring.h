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

/**
 * @brief Performs a case-sensitive string comparison.
 *
 * @param str0 The first string to compare.
 * @param str1 The second string to compare.
 * @return True if the strings are equal, false otherwise.
 */
VAPI b8 strings_equal( const char* str0, const char* str1 );
