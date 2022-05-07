cmake_minimum_required(VERSION 3.22)
project(libsys)

set(CMAKE_C_STANDARD 99)

set(__LIBSYS_HOSTED 1)

file(GLOB CSources source/*.c)
file(GLOB_RECURSE CHeaders headers/*.h)

add_library(sys ${CSources} ${CHeaders})
target_include_directories(sys PUBLIC headers)
target_compile_options(sys PUBLIC
        -ffreestanding
        -fno-stack-protector
        -fno-stack-check
        -funsigned-char
        -fno-pic
        -mabi=sysv
        -mno-mmx
        -mno-3dnow
        -mno-sse
        -mno-sse2
        -mno-red-zone
        -mcmodel=kernel
        -O2
        -g
        -Wall
        -Wextra
        -Wpedantic
        -pipe
        )
target_link_options(sys PUBLIC
        -T ${CMAKE_CURRENT_SOURCE_DIR}/ld/x86_64/kernel.ld
        -fuse-ld=lld
        -nostdlib
        -static
        )
