#pragma once

#include "defines.h"

/**
 * @brief Enumeration representing memory tags.
 *
 * For temporary use. Should be assigned one of the below or have a new tag created.
 */
typedef enum memory_tag {
	MEMORY_TAG_UNKNOWN,             /**< Unknown memory tag. */
	MEMORY_TAG_ARRAY,               /**< Memory tag for arrays. */
	MEMORY_TAG_DARRAY,              /**< Memory tag for dynamic arrays. */
	MEMORY_TAG_DICT,                /**< Memory tag for dictionaries. */
	MEMORY_TAG_RING_QUEUE,          /**< Memory tag for ring queues. */
	MEMORY_TAG_BST,                 /**< Memory tag for binary search trees. */
	MEMORY_TAG_STRING,              /**< Memory tag for strings. */
	MEMORY_TAG_APPLICATION,         /**< Memory tag for application-related allocations. */
	MEMORY_TAG_JOB,                 /**< Memory tag for job-related allocations. */
	MEMORY_TAG_TEXTURE,             /**< Memory tag for texture-related allocations. */
	MEMORY_TAG_MATERIAL_INSTANCE,   /**< Memory tag for material instance-related allocations. */
	MEMORY_TAG_RENDERER,            /**< Memory tag for renderer-related allocations. */
	MEMORY_TAG_GAME,                /**< Memory tag for game-related allocations. */
	MEMORY_TAG_TRANSFORM,           /**< Memory tag for transformation-related allocations. */
	MEMORY_TAG_ENTITY,              /**< Memory tag for entity-related allocations. */
	MEMORY_TAG_ENTITY_NODE,         /**< Memory tag for entity node-related allocations. */
	MEMORY_TAG_SCENE,               /**< Memory tag for scene-related allocations. */

	MEMORY_TAG_MAX_TAGS             /**< Maximum number of memory tags. */
} memory_tag;

/**
 * @brief Initializes the memory system.
 */
VAPI void initialize_memory();

/**
 * @brief Shuts down the memory system.
 */
VAPI void shutdown_memory();

/**
 * @brief Allocates memory with a specified tag.
 *
 * @param size The size of the memory to allocate.
 * @param tag The memory tag.
 * @return A pointer to the allocated memory.
 */
VAPI void* kallocate( u64 size, memory_tag tag );

/**
 * @brief Frees allocated memory with a specified tag.
 *
 * @param block A pointer to the memory block to free.
 * @param size The size of the memory block.
 * @param tag The memory tag.
 */
VAPI void kfree( void* block, u64 size, memory_tag tag );

/**
 * @brief Sets a block of memory to zero.
 *
 * @param block A pointer to the memory block.
 * @param size The size of the memory block.
 * @return A pointer to the zeroed memory block.
 */
VAPI void* kzero_memory( void* block, u64 size );

/**
 * @brief Copies memory from source to destination.
 *
 * @param dest A pointer to the destination memory block.
 * @param source A pointer to the source memory block.
 * @param size The size of the memory block.
 * @return A pointer to the destination memory block.
 */
VAPI void* kcopy_memory( void* dest, const void* source, u64 size );

/**
 * @brief Sets a block of memory to a specified value.
 *
 * @param dest A pointer to the destination memory block.
 * @param value The value to set.
 * @param size The size of the memory block.
 * @return A pointer to the destination memory block.
 */
VAPI void* kset_memory( void* dest, i32 value, u64 size );

/**
 * @brief Gets a string representation of the memory usage.
 *
 * @return A pointer to the string representation of memory usage.
 */
VAPI char* get_memory_usage_str();

