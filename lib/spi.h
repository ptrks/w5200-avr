#ifndef SPI_H
#define SPI_H

#include <stdint.h>

void spi_enable();
uint8_t spi_transfer(uint8_t data);
void spi_cs_low(void);
void spi_cs_high(void);


#endif