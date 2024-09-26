#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TMin INT_MIN
#define TMax INT_MAX

#include "btest.h"
#include "bits.h"

test_rec test_set[] = {
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
 {"bitXor", (funct_t) bitXor, (funct_t) test_bitXor, 2, "& ~", 7, 1,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
{"byteSwap", (funct_t) byteSwap, (funct_t) test_byteSwap, 3,
     "! ~ & ^ | + << >>", 17, 2,
    {{TMin, TMax},{0,3},{0,3}}},
 {"logicalShift", (funct_t) logicalShift, (funct_t) test_logicalShift,
   2, "! ~ & ^ | + << >>", 20, 3,
  {{TMin, TMax},{0,31},{TMin,TMax}}},
 {"float_i2f", (funct_t) float_i2f, (funct_t) test_float_i2f, 1,
    "$", 30, 4,
     {{1, 1},{1,1},{1,1}}},
 {"leftBitCount", (funct_t) leftBitCount, (funct_t) test_leftBitCount, 1, "! ~ & ^ | + << >>,<,>", 40, 4,
  {{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
  {"floatPower2",(funct_t)floatPower2,(funct_t)test_floatPower2,1,"$",30,4,{{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
  {"floatScale2",(funct_t)floatScale2,(funct_t)test_floatScale2,1,"$",30,4,{{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
  {"reverse",(funct_t)reverse,(funct_t)test_reverse,1,"$",30,3,{{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
  {"samesign",(funct_t)samesign,(funct_t)test_samesign,2,">> ! ^",12,2,{{TMin, TMax},{TMin,TMax},{TMin,TMax}}},
  {"logtwo",(funct_t) logtwo,(funct_t) test_logtwo,1,"$",25,4,{{1, TMax},{TMin,TMax},{TMin,TMax}}},
  {"float64_f2i",(funct_t) float64_f2i,(funct_t) test_float64_f2i,1,"$",40,3,{{TMin, TMax},{TMax,TMin},{TMin,TMax}}},
  {"", NULL, NULL, 0, "", 0, 0,
   {{0, 0},{0,0},{0,0}}}
};
