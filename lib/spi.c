#include <avr/io.h>
#include <stdint.h>
#include <avr/sfr_defs.h>
#include "utility.h"

#define SPI_PORT PORTB
#define SPI_DDR  DDRB

#define MOSI_PIN 3
#define SCK_PIN  5
#define CS_PIN   2

void spi_enable() {

	 set_bit(SPI_PORT,CS_PIN);

	 set_bit(SPI_DDR,MOSI_PIN);
	 set_bit(SPI_DDR,SCK_PIN);
	 set_bit(SPI_DDR,CS_PIN);

	 set_bit(SPCR,SPE);
	 set_bit(SPCR,MSTR);

	 set_bit(SPSR,SPI2X);
}


uint8_t spi_transfer(uint8_t data){
	SPDR = data;
	loop_until_bit_is_set(SPSR,SPIF);
  	return SPDR;
}


void spi_cs_low(void) {
	clear_bit(SPI_PORT,CS_PIN);
}


void spi_cs_high(void) {
	set_bit(SPI_PORT,CS_PIN);
}
