/*
 * Copyright 2018 Scott Court
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/** @file */

#pragma once

#include <stdint.h>

/** Set if the instruction is any form of a relative jump. */
#define LDE_FLAG_RELJUMP 0x0000001

/** Holds a decoded instruction. */
struct decoded_instruction {
	short length;	/** The length of the decoded instruction. */
	uint32_t flags; /** Any flags pertaining to the decoded instruction. */
	void* data;	/** Pointer to any additional data. */
};

/** Decodes an instruction
  * @param instruction		A pointer to the instruction to decode.
  * @param d			A pointer to a decoded_instruction structure to
  *                             store the decoded instuction information is.
  * @return 0 on success, 1 on failure.
  */
char decode(char* instruction, struct decoded_instruction* d);

