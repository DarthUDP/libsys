/**
 * @file string.h
 * @brief Utilities for encoding/decoding integers to and from bytes in a stream little or big endian
 * @authors Matheus Xavier
 * This file is part of libsys and licensed under the:
 * BSD 3-Clause License
 * Copyright (c) 2021, Matheus Xavier
 * All rights reserved.
 */

#ifndef SYS_STRING_H
#define SYS_STRING_H
#ifdef CXX
extern "C" {
#endif

#include <rt_services.h>
#include <stddef.h>
#include <stdint.h>

extern volatile size_t __rsize_max;

#define RSIZE_MAX __rsize_max

typedef size_t rsize_t;

extern size_t strlen(const char *__restrict str, rsize_t max);

extern void *strcpy(char *__restrict dest, const char *__restrict src);

extern void *strcpyn(char *__restrict dest, const char *__restrict src, rsize_t count);

extern void *memcpy(void *__restrict dest, const void *__restrict src, rsize_t count);

extern errno_t memcpy_s(void *__restrict dest, rsize_t destsz, const void *__restrict src, rsize_t count);

#ifdef CXX
};
#endif

#endif
