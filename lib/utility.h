#ifndef UTILITY_H
#define UTILITY_H


#define set_bit(var, mask)   ((var) |= (uint8_t)(1 << mask))
#define clear_bit(var, mask)   ((var) &= (uint8_t)~(1 << mask))

#define high_byte(byte) ((byte & 0xFF00) >> 8)
#define low_byte(byte) ((byte & 0x00FF))



#endif