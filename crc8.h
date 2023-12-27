#ifndef __CRC8_H__
#define __CRC8_H__

#include <stdint.h>

/* Init CRC8 lookup table */
void crc8_init(uint8_t poly);

/* Calculate CRC8 checksum */
uint8_t crc8_calc(uint8_t *data, uint8_t len);

#endif /* __CRC8_H__ */

