#ifndef CH32V003_LIB_UTILS_STRINGIFY
#define CH32V003_LIB_UTILS_STRINGIFY
#include <inttypes.h>
#include <stdint.h>
#include <sys/cdefs.h>

///@brief stringify floating point value
///@details precision is fixed to 5 fractional digits
void to_string_f(float value, char* dst, size_t len);

void to_string_u32b(uint32_t value, char* dst, size_t len);
void to_string_u16b(uint16_t value, char* dst, size_t len);
void to_string_u8b(uint8_t value, char* dst, size_t len);

#endif
