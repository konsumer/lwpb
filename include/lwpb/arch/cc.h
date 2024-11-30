/** @file cc.h
 * 
 * Compiler specifics.
 * 
 * Copyright 2009 Simon Kallweit
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __LWPB_ARCH_CC_H__
#define __LWPB_ARCH_CC_H__

#include <stdint.h>

#ifndef NULL
#define NULL ((void *) 0)
#endif

#define U8_MIN  0
#define U8_MAX  0xff

#define U16_MIN 0
#define U16_MAX 0xffff

#define U32_MIN 0
#define U32_MAX 0xffffffff

#define U64_MIN 0
#define U64_MAX 0xffffffffffffffffLL

#define S8_MIN  (-127-1)
#define S8_MAX  127

#define S16_MIN (-32767-1)
#define S16_MAX 32767

#define S32_MIN (-2147483647-1)
#define S32_MAX 2147483647

#define S64_MIN (-9223372036854775807LL-1)
#define S64_MAX 9223372036854775807LL

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;

typedef int8_t s8_t;
typedef int16_t s16_t;
typedef int32_t s32_t;
typedef int64_t s64_t;

// typedef unsigned int size_t;


#endif // __LWPB_ARCH_CC_H__
