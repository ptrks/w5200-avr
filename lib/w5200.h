#ifndef W5200_REGIO_H
#define W5200_REGIO_H

#include <stdint.h>

/* General configuration methods */



void w5200_init(const uint8_t *mac,const uint8_t *ip, const uint8_t *gw, const uint8_t *subnet);
void w5200_set_mac(const uint8_t mac[]);
void w5200_set_ip(const uint8_t ip[]);
void w5200_set_subnet(const uint8_t subnet);
void w5200_set_gateway(const uint8_t gw[]);


#endif