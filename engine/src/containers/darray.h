#pragma once

#include "defines.h"

/*
Memory layout
u64 capacity = number elements that can be held
u64 length = number of elements currently contained
u64 stride = size of each element in bytes
void* elements
*/

/**
 * @brief Enumeration representing properties of a dynamic array.
 */
enum {
	DARRAY_CAPACITY,           /**< Capacity of the dynamic array. */
	DARRAY_LENGTH,             /**< Length or size of the dynamic array. */
	DARRAY_STRIDE,             /**< Stride of the dynamic array. */
	DARRAY_FIELD_LENGTH        /**< Length of a field in the dynamic array. */
};

/**
 * @brief Creates a dynamic array.
 *
 * @param length The initial length of the array.
 * @param stride The stride (size) of each element in the array.
 * @return A pointer to the created dynamic array.
 */
VAPI void* _darray_create( u64 length, u64 stride );

/**
 * @brief Destroys a dynamic array.
 *
 * @param array A pointer to the dynamic array to be destroyed.
 */
VAPI void _darray_destroy( void* array );

/**
 * @brief Gets the value of a specific field in the dynamic array.
 *
 * @param array A pointer to the dynamic array.
 * @param field The index of the field to retrieve.
 * @return The value of the specified field.
 */
VAPI u64 _darray_field_get( void* array, u64 field );

/**
 * @brief Sets the value of a specific field in the dynamic array.
 *
 * @param array A pointer to the dynamic array.
 * @param field The index of the field to set.
 * @param value The value to set for the specified field.
 */
VAPI void _darray_field_set( void* array, u64 field, u64 value );

/**
 * @brief Resizes a dynamic array.
 *
 * @param array A pointer to the dynamic array to be resized.
 * @return A pointer to the resized dynamic array.
 */
VAPI void* _darray_resize( void* array );

/**
 * @brief Pushes a value to the end of the dynamic array.
 *
 * @param array A pointer to the dynamic array.
 * @param value_ptr A pointer to the value to be pushed.
 * @return A pointer to the modified dynamic array.
 */
VAPI void* _darray_push( void* array, const void* value_ptr );

/**
 * @brief Pops a value from the end of the dynamic array.
 *
 * @param array A pointer to the dynamic array.
 * @param dest A pointer to store the popped value.
 */
VAPI void _darray_pop( void* array, void* dest );

/**
 * @brief Pops a value at a specific index from the dynamic array.
 *
 * @param array A pointer to the dynamic array.
 * @param index The index from which to pop the value.
 * @param dest A pointer to store the popped value.
 * @return A pointer to the modified dynamic array.
 */
VAPI void* _darray_pop_at( void* array, u64 index, void* dest );

/**
 * @brief Inserts a value at a specific index in the dynamic array.
 *
 * @param array A pointer to the dynamic array.
 * @param index The index at which to insert the value.
 * @param value_ptr A pointer to the value to be inserted.
 * @return A pointer to the modified dynamic array.
 */
VAPI void* _darray_insert_at( void* array, u64 index, void* value_ptr );

#define DARRAY_DEFAULT_CAPACITY 1
#define DARRAY_RESIZE_FACTOR 2

#define darray_create(type) \
    _darray_create(DARRAY_DEFAULT_CAPACITY, sizeof(type))

#define darray_reserve(type, capacity) \
    _darray_create(capacity, sizeof(type))

#define darray_destroy(array) _darray_destroy(array);

#define darray_push(array, value)           \
    {                                       \
        typeof(value) temp = value;         \
        array = _darray_push(array, &temp); \
    }
// NOTE: could use __auto_type for temp above, but intellisense
// for VSCode flags it as an unknown type. typeof() seems to
// work just fine, though. Both are GNU extensions.

#define darray_pop(array, value_ptr) \
    _darray_pop(array, value_ptr)

#define darray_insert_at(array, index, value)           \
    {                                                   \
        typeof(value) temp = value;                     \
        array = _darray_insert_at(array, index, &temp); \
    }

#define darray_pop_at(array, index, value_ptr) \
    _darray_pop_at(array, index, value_ptr)

#define darray_clear(array) \
    _darray_field_set(array, DARRAY_LENGTH, 0)

#define darray_capacity(array) \
    _darray_field_get(array, DARRAY_CAPACITY)

#define darray_length(array) \
    _darray_field_get(array, DARRAY_LENGTH)

#define darray_stride(array) \
    _darray_field_get(array, DARRAY_STRIDE)

#define darray_length_set(array, value) \
    _darray_field_set(array, DARRAY_LENGTH, value)
