/**
 * @file rt_services.h
 * @brief Utilities for encoding/decoding integers to and from bytes in a stream little or big endian
 * @authors Matheus Xavier
 * This file is part of libsys and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#ifndef SYS_ERROR_H
#define SYS_ERROR_H
#ifdef CXX
extern "C" {
#endif

#include <cstddef>
#include <cstdint>

/**
 * @brief Used to document error handlers and functions returning errors
 */
typedef int errno_t;

/**
 * @brief This is the signature of the handler called upon runtime errors
 */
typedef void (*constraint_handler_t)(const char *msg, void *obj, errno_t error);

extern constraint_handler_t __sys_current_constraint_handler;

struct sys_rt_error_info {
	const char *file_name;
	size_t lineno;
};

typedef struct sys_rt_error_info rt_err_info_t

#define SYS_ASSERT_HANDLER() \
	if (!__sys_current_constraint_handler) return -255;

	/**
 * @brief Set the runtime constraint failure handler function, note however
 * that differently from the stdlib version of this feature,
 * no default handler is installed.
 * @param handler
 * @return the previous handler, on first set it will return NULL
 */
	extern constraint_handler_t
	set_constraint_handler_s(constraint_handler_t handler);

#ifdef CXX
};
#endif

#endif
