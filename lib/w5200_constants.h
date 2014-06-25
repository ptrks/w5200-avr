#ifndef W5200_CONSTANTS_H
#define W5200_CONSTANTS_H




#define W52_SPI_OPCODE_READ 0x0000
#define W52_SPI_OPCODE_WRITE 0x8000

#define MR   		0x0000   // Mode Register
#define GAR  		0x0001   // Gateway Address: 0x0001 to 0x0004
#define SUBR 		0x0005   // Subnet mask Address: 0x0005 to 0x0008
#define SHAR  		0x0009   // Source Hardware Address (MAC): 0x0009 to 0x000E
#define SIPR 		0x000F   // Source IP Address: 0x000F to 0x0012
#define RMSR 		0x001A   // RX Memory Size Register
#define TMSR 		0x001B   // TX Memory Size Registerping
#define IR 	 		0x0015   //Interrupt
#define IMR  		0x0016   //Interrupt Mask
#define RTR0 		0x0017 
#define RTR1 		0x0018
#define RCR  		0x0019
#define PATR0 		0x001C
#define PATR1 		0x001D
#define PPPALGO 	0x001E
#define VERSIONR 	0x001F
#define PTIMER 		0x0028
#define PMAGIC 		0x0029
#define INTLEVEL0 	0x0030
#define INTLEVEL1 	0x0031
#define IR2 		0x0034
#define PSTATUS 	0x0035
#define IMR2 		0x0036


#endif