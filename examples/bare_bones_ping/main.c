#include <avr/io.h>
#include <util/delay.h>
#include "../../lib/w5200.h"
#include "../../lib/usart_printf.h"




int main(void) {

  usart_initialize();
  _delay_ms(10);
  stdout = &uart_output;

  uint8_t mac_address[6] = {0x22,0x22,0x22,0x10,0x00,0x33};
  uint8_t local_host[4]  = {192,168,1,191};
  uint8_t gateway[4]     = {192,168,1,1};
  uint8_t subnet[4]     =  {255,255,255,0};

  printf("--------Bare Bones Ping Example--------\n");
  w5200_init(mac_address,local_host,gateway,subnet);
  for(;;){
    
  }

  return 0;
}