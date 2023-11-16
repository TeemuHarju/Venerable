#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging for release builds.
#if KRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

/**
 * @enum log_level
 * @brief Enumeration representing different log levels.
 */
typedef enum log_level {
	LOG_LEVEL_FATAL = 0, /**< Fatal error log level. */
	LOG_LEVEL_ERROR = 1, /**< Error log level. */
	LOG_LEVEL_WARN = 2,  /**< Warning log level. */
	LOG_LEVEL_INFO = 3,  /**< Information log level. */
	LOG_LEVEL_DEBUG = 4, /**< Debug log level. */
	LOG_LEVEL_TRACE = 5  /**< Trace log level. */
} log_level;

/**
 * @fn b8 initialize_logging()
 * @brief Initializes the logging system.
 *
 * @return Boolean indicating whether the logging initialization was successful.
 */
b8 initialize_logging();

/**
 * @fn void shutdown_logging()
 * @brief Shuts down the logging system.
 */
void shutdown_logging();

/**
 * @fn VAPI void log_output(log_level level, const char* message, ...)
 * @brief Logs a message with the specified log level.
 *
 * @param level Log level of the message.
 * @param message Format string for the log message.
 * @param ... Additional arguments for the format string.
 */
VAPI void log_output( log_level level, const char* message, ... );

// Logs a fatal-level message.
#define KFATAL(message, ...) log_output(log_level::LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef KERROR
// Logs an error-level message.
#define KERROR(message, ...) log_output(log_level::LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// Logs a warning-level message.
#define KWARN(message, ...) log_output(log_level::LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_WARN_ENABLED != 1
#define KWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs an info-level message.
#define KINFO(message, ...) log_output(log_level::LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_INFO_ENABLED != 1
#define KINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs a debug-level message.
#define KDEBUG(message, ...) log_output(log_level::LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_DEBUG_ENABLED != 1
#define KDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs a trace-level message.
#define KTRACE(message, ...) log_output(log_level::LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
// Does nothing when LOG_TRACE_ENABLED != 1
#define KTRACE(message, ...)
#endif