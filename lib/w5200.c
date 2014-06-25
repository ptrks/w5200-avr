#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "spi.h"
#include "utility.h"
#include "w5200_constants.h"

char debug = 1;


/* Private register IO functions */
static uint8_t w5200_read_register(uint16_t addr){
	
	uint8_t data;

	spi_cs_low();

	spi_transfer(high_byte(addr));
	spi_transfer(low_byte(addr));
	spi_transfer(0x00);
	spi_transfer(0x01);
	data = spi_transfer(0);

	spi_cs_high();
	
	return data;
}

static void w5200_write_register(uint16_t addr, uint8_t data) {
    
    spi_cs_low();

    spi_transfer(high_byte(addr));
    spi_transfer(low_byte(addr));
    spi_transfer(0x80);
    spi_transfer(0x01);
    spi_transfer(data);
    
    spi_cs_high();

}



/* General configuration methods */

void w5200_init(uint8_t *mac, uint8_t *ip, uint8_t *gw, uint8_t *subnet) {

	int i;
	_delay_ms(300);
	spi_enable();

	/* Software reset  */
	w5200_write_register(MR,0x80);
	
	/* Set mac address */
	for(i = 0; i < 6; i++) 
		w5200_write_register((SHAR+i),mac[i]);

	/* Set source IP address */
	for(i = 0; i < 4; i++)
		w5200_write_register((SIPR+i),ip[i]);

	/* Set gateway */
	for(i = 0; i < 4; i++)
		w5200_write_register((GAR+i),gw[i]);

	/* Set subnet mask */ 
	for(i = 0; i < 4; i++)
		w5200_write_register((SUBR+i),subnet[i]);

	/* Debug Logging */
	if(debug) {
		  printf("----------------w5200 Init----------------\n");
 		  printf("IP Address  : %d.%d.%d.%d\n",w5200_read_register(SIPR+0),w5200_read_register(SIPR+1),w5200_read_register(SIPR+2),w5200_read_register(SIPR+3));
		  printf("Subnet Mask : %d.%d.%d.%d\n",w5200_read_register(SUBR+0),w5200_read_register(SUBR+1),w5200_read_register(SUBR+2),w5200_read_register(SUBR+3));
		  printf("Gateway     : %d.%d.%d.%d\n",w5200_read_register(GAR+0),w5200_read_register(GAR+1),w5200_read_register(GAR+2),w5200_read_register(GAR+3));
		  printf("Mac Address : %x:%x:%x:%x:%x:%x\n",w5200_read_register(SHAR+0),w5200_read_register(SHAR+1),w5200_read_register(SHAR+2),w5200_read_register(SHAR+3),w5200_read_register(SHAR+4),w5200_read_register(SHAR+5));
		  printf("------------------------------------------\n");
	}

}
