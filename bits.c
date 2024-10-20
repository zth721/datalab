/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
     return (~(x&y))&(~(~x&~y));
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    int sign_x = x >> 31;  
    int sign_y = y >> 31;  
    int is_x_zero = !(x);  
    int is_y_zero = !(y);  
    if (is_x_zero || is_y_zero) {  
        return is_x_zero && is_y_zero;  
    }  
    return !(sign_x ^ sign_y);  

}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {  
    int result = 0;  
    // Check if v is greater than or equal to each power of 2 (1, 2, 4, 8, 16, 32, ...)  
    if (v >> 16) {   
        result = 16;   
        v >>= 16;   
    }  
    if (v >> 8) {   
        result += 8;   
        v >>= 8;   
    }  
    if (v >> 4) {   
        result += 4;   
        v >>= 4;   
    }  
    if (v >> 2) {   
        result += 2;   
        v >>= 2;   
    }  
    if (v >> 1) {   
        result += 1;   
        v >>= 1;   
    }  
    // At this point, v should be 1, and result holds the log base 2 of the original v  
    return result;  
}



/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {  
    int mask_n = 0xFF << (n << 3); 
    int mask_m = 0xFF << (m << 3); 
    int nth_byte = (x & mask_n) >> (n << 3);  
    int mth_byte = (x & mask_m) >> (m << 3);   
    x = x & ~mask_n & ~mask_m;    
    x = x | (nth_byte << (m << 3)) | (mth_byte << (n << 3));  
    return x;  
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned x) {  
    x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;  
    x = (x & 0x33333333) << 2 | (x & 0xCCCCCCCC) >> 2;  
    x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;  
    x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;  
    x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;  
    return x;  
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    x>>=n;
    return x&(~(1<<31>>n<<1));
    }

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {  
    x = ~x; 
    int result = 0;  
    int z; 
    int num; 
   
    z = !(x >> 16);   
    num = z << 4;
    result = num; 
    x <<= num; 
  
   
    z = !(x >> 24); 
    num = z << 3; 
    result += num;   
    x <<= num;

    z = !(x >> 28); 
    num = z << 2;  
    result += num; 
    x <<= num;

    z = !(x >> 30);
    num = z << 1; 
    result += num; 
    x <<= num; 
  
    result += !(x >> 31) + !(x >> 30);
    return result;  
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {  
    unsigned exponent = 127,sign;
    if (x == 0) {  
        return 0;  
    }  
    if (x < 0) {  
        sign = 1;  
        x = -x;  
    }  
    unsigned msb = 31;  
    while ((x & (1 << msb)) == 0) {  
        msb--;  
    }  
    x <<= (31 - msb);   
    unsigned mantissa = (x >> 9) & 0x7FFFFF; 
    return (sign << 31) | (exponent << 23) | mantissa;  
}


/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {  
    unsigned sign = uf & 0x80000000;  
    unsigned exponent = (uf & 0x7F800000) >> 23;  
    unsigned fraction = uf & 0x007FFFFF;  
    if (exponent == 0xFF) {  
        return uf;  
    }  
    if (exponent == 0) {  
        fraction <<= 1;  
        if (fraction & 0x00800000) {  
            exponent++;  
            fraction &= 0x007FFFFF; 
        }  
    } else {  
        exponent++;  
        if (exponent == 0xFF) {  
            return sign | 0x7F800000; 
        }  
    }  
    return sign | (exponent << 23) | fraction;  
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {  
    unsigned sign = (uf2 >> 31) & 0x1;  
    unsigned exponent = (uf2 >> 20) & 0x7FF;  
    int real_exponent = exponent - 1023;  
    int fraction;  
    if (real_exponent <= 20) {  
        fraction = (uf2 & 0x000FFFFF) | 0x00100000; 
    } else {  
        fraction = ((uf2 & 0x000FFFFF) << (real_exponent - 20 + 3)) |  
                   ((uf1 & 0x000007FF) >> (20 - (real_exponent - 20))) |  
                   0x00100000; 
    }  
    if (exponent < 1023) {  
        return 0;  
    } 
    if (real_exponent == -1023) {  
        return sign ? -1 : 1;  
    }  
    if (real_exponent > 31) {  
        return 0x80000000;   
    } 
    fraction <<= (real_exponent < 0 ? 0 : real_exponent);  
    if (sign) {  
        fraction = -fraction;  
    }  
    if (fraction < -2147483648) { 
        return 0x80000000;  
    }  
    if (fraction > 2147483647) { 
        return 0x7FFFFFFF; 
    }  
  
    return fraction;  
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {  
    const int bias = 127;  
    unsigned exponent = 0;  
    if (x < -149) {  
        return 0; 
    }  
    if (x > 127) {  
        return 0x7F800000;   
    }  
    exponent = x + bias;  
    return (exponent << 23);  
}  
