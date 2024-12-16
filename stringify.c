#include "stringify.h"

#include <iso646.h>
#include <stdio.h>

#define ABS(a)    ((a) < 0 ? (-(a)) : (a))
#define SIGN(a)   ((a) < 0 ? -1 : 1)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

///@brief stringify floating point value
///@details precision is fixed to 5 fractional digits
void to_string_f(float value, char* dst, size_t len) {
    int sign      = SIGN(value);
    value         = ABS(value);
    uint32_t dec  = value;
    uint32_t frac = (value - dec) * 100'000;
    snprintf(dst, len, "%s%" PRIu32 ".%05" PRIu32, sign < 0 ? "-" : "", dec, frac);
}

void to_string_u32b(uint32_t value, char* dst, size_t len) {
    uint32_t mask = 1 << 31;
    for (size_t i = 0; (i < len - 1) and (i < 32); i++) {
        dst[i] = ((value & (mask >> i)) == 0) ? '0' : '1';
    }
    dst[MIN(len - 1, 32)] = '\0';
}

void to_string_u16b(uint16_t value, char* dst, size_t len) {
    uint32_t mask = 1 << 15;
    for (size_t i = 0; (i < len - 1) and (i < 16); i++) {
        dst[i] = ((value & (mask >> i)) == 0) ? '0' : '1';
    }
    dst[MIN(len - 1, 16)] = '\0';
}
