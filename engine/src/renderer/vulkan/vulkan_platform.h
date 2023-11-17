#pragma once

#include "defines.h"

/**
 * @brief Appends the names of required extensions for this platform to the provided dynamic array.
 *
 * @param[in,out] names_darray A dynamic array (DArray) pointer to which the extension names will be appended.
 *                              The function assumes that the array is already created and may modify its contents.
 */
void platform_get_required_extension_names( const char*** names_darray );