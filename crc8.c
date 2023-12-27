#include <stdint.h>
#include "crc8.h"

static uint8_t crc8_lut[256] = {};

/* Init CRC8 lookup table */
void crc8_init(uint8_t poly)
{
  uint16_t i = 0;
  uint8_t j = 0;
  uint8_t crc = 0x00;
  for (i = 0; i < 256; i++)
  {
    crc = i;
    for (j = 0; j < 8; j++)
    {
      crc = (crc << 1) ^ ((crc & 0x80) ? poly : 0x00);
    }
    crc8_lut[i] = crc;
  }
}

/* Calculate CRC8 checksum */
uint8_t crc8_calc(uint8_t *data, uint8_t len)
{
  uint8_t crc = 0x00;
  if (data && (0 < len))
  {
    while (len--)
    {
      crc = crc8_lut[crc ^ *data++];
    }
  }
  return crc;
}

