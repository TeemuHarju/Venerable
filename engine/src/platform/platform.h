#pragma once

#include "defines.h"

/**
 * @struct platform_state
 * @brief Structure representing the state of the platform.
 */
typedef struct platform_state {
	void* internal_state;
} platform_state;

/**
 * @fn VAPI bool platform_startup(platform_state* plat_state, const char* application_name, i32 x, i32 y, i32 width, i32 height)
 * @brief Initializes the platform.
 *
 * @param plat_state Pointer to the platform state structure.
 * @param application_name Name of the application.
 * @param x Initial x-coordinate of the window.
 * @param y Initial y-coordinate of the window.
 * @param width Initial width of the window.
 * @param height Initial height of the window.
 * @return Boolean indicating whether the platform initialization was successful.
 */
VAPI bool platform_startup(
	platform_state* plat_state,
	const char* application_name,
	i32 x,
	i32 y,
	i32 width,
	i32 height );

/**
 * @fn VAPI void platform_shutdown(platform_state* plat_state)
 * @brief Shuts down the platform.
 *
 * @param plat_state Pointer to the platform state structure.
 */
VAPI void platform_shutdown( platform_state* plat_state );

/**
 * @fn VAPI bool platform_pump_messages(platform_state* plat_state)
 * @brief Processes platform-specific messages.
 *
 * @param plat_state Pointer to the platform state structure.
 * @return Boolean indicating whether there are more messages to process.
 */
VAPI bool platform_pump_messages( platform_state* plat_state );

/**
 * @fn void* platform_allocate(u64 size, b8 aligned)
 * @brief Allocates memory.
 *
 * @param size Size of the memory to allocate.
 * @param aligned Boolean indicating whether the memory should be aligned.
 * @return Pointer to the allocated memory.
 */
void* platform_allocate( u64 size, b8 aligned );

/**
 * @fn void platform_free(void* block, b8 aligned)
 * @brief Frees memory.
 *
 * @param block Pointer to the memory block to free.
 * @param aligned Boolean indicating whether the memory was aligned.
 */
void platform_free( void* block, b8 aligned );

/**
 * @fn void* platform_zero_memory(void* block, u64 size)
 * @brief Sets a block of memory to zero.
 *
 * @param block Pointer to the memory block.
 * @param size Size of the memory block.
 * @return Pointer to the modified memory block.
 */
void* platform_zero_memory( void* block, u64 size );

/**
 * @fn void* platform_copy_memory(void* dest, const void* source, u64 size)
 * @brief Copies memory from source to destination.
 *
 * @param dest Pointer to the destination memory block.
 * @param source Pointer to the source memory block.
 * @param size Size of the memory block to copy.
 * @return Pointer to the destination memory block.
 */
void* platform_copy_memory( void* dest, const void* source, u64 size );

/**
 * @fn void* platform_set_memory(void* dest, i32 value, u64 size)
 * @brief Sets a block of memory to a specified value.
 *
 * @param dest Pointer to the memory block.
 * @param value Value to set in each byte of the memory block.
 * @param size Size of the memory block.
 * @return Pointer to the modified memory block.
 */
void* platform_set_memory( void* dest, i32 value, u64 size );

/**
 * @fn void platform_console_write(const char* message, u8 colour)
 * @brief Writes a message to the console.
 *
 * @param message The message to write.
 * @param colour Color code for the console output.
 */
void platform_console_write( const char* message, u8 colour );

/**
 * @fn void platform_console_write_error(const char* message, u8 colour)
 * @brief Writes an error message to the console.
 *
 * @param message The error message to write.
 * @param colour Color code for the console output.
 */
void platform_console_write_error( const char* message, u8 colour );

/**
 * @fn f64 platform_get_absolute_time()
 * @brief Gets the absolute time.
 *
 * @return Absolute time in seconds.
 */
f64 platform_get_absolute_time();

/**
 * @fn void platform_sleep(u64 ms)
 * @brief Sleeps the thread for the provided duration.
 *
 * This function blocks the main thread and should only be used for giving time back to the OS
 * for unused update power. Therefore, it is not exported.
 *
 * @param ms Duration to sleep in milliseconds.
 */
void platform_sleep( u64 ms );