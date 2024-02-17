/**
 * @file my_lib.h
 * @author Dong Hyeon Kim (eastchord0729@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-02-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MY_LIB_H_
#define MY_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#define OFF 0
#define ON 1

#ifndef BENCH
#define BENCH OFF
#endif

#ifndef DEBUG
#define DEBUG OFF
#endif

typedef enum
{
    NO_ERROR = 0,
    NULL_POINTER_ERROR = 1
} Error;

typedef struct
{
    u64 count, aver, max, min, std;
} CycleResult;

static inline u64 cycle()
{
    u64 ret;
    asm volatile("mrs %0, cntvct_el0" : "=r"(ret));
    return ret;
}

Error cycle_print(const CycleResult *cycle_result);
Error debug_print(const void *data, size_t size);

#endif