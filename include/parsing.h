#include <stdint.h>
#include <stddef.h>

// function to parse sbus channel
uint16_t *parse_buffer(uint8_t buff[], size_t buff_size, uint16_t channel[]);

// interpolate channel and return pwm value 
int interpolation(uint16_t ch);
