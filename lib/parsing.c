#include <stdint.h>
#include <parsing.h>
#include <math.h>
#include <stddef.h>
// implement interpolation here
int interpolation(uint16_t channel) {
	// write interpolation code here
        return 0;
}
// creating 11-bit channel with buffer size check
uint16_t *parse_buffer(uint8_t buff[], size_t buff_size, uint16_t channel[]) { 
    // Check if buffer has enough elements
    if (buff_size < 23) {
        // Handle error (return NULL or handle differently)
        return NULL;
    }

    // Masking byte shifting bits (value in hex '0x07FF')
    uint16_t mask = 0x07FF;

    // Creating channels 
    channel[0]  = ((buff[1]  | buff[2] << 8)                & mask);
    channel[1]  = ((buff[2] >> 3 | buff[3] << 5)            & mask);
    channel[2]  = ((buff[3] >> 6 | buff[4] << 2 | buff[5] << 10) & mask);
    channel[3]  = ((buff[5] >> 1 | buff[6] << 7)            & mask);
    channel[4]  = ((buff[6] >> 4 | buff[7] << 4)            & mask);
    channel[5]  = ((buff[7] >> 7 | buff[8] << 1 | buff[9] << 9)  & mask);
    channel[6]  = ((buff[9] >> 2 | buff[10] << 6)           & mask);
    channel[7]  = ((buff[10] >> 5 | buff[11] << 3)          & mask);
    channel[8]  = ((buff[12]     | buff[13] << 8)           & mask);
    channel[9]  = ((buff[13] >> 3 | buff[14] << 5)          & mask);
    channel[10] = ((buff[14] >> 6 | buff[15] << 2 | buff[16] << 10) & mask);
    channel[11] = ((buff[16] >> 1 | buff[17] << 7)          & mask);
    channel[12] = ((buff[17] >> 4 | buff[18] << 4)          & mask);
    channel[13] = ((buff[18] >> 7 | buff[19] << 1 | buff[20] << 9) & mask);
    channel[14] = ((buff[20] >> 2 | buff[21] << 6)          & mask);
    channel[15] = ((buff[21] >> 5 | buff[22] << 3)          & mask);

    return channel;
}
