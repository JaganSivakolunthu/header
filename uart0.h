#include <lpc21xx.h>

void uart0_init(unsigned int baud)
{
	PINSEL0 |= 5;//P0.0=TXD0, P0.1=RXD0
	U0LCR=0x83;//DLAB=1, WORD LENGTH=8bits, PARITY=Disabled,No of Stop Bits=1
	switch(baud)	//setting baudrate
	{	
		case 4800:	U0DLL=195;break;//4800bps
		case 7200:	U0DLL=130;break;//7200bps
		case 9600:	U0DLL=195;break;//9600bps
		case 57600:	U0DLL=16;break;//9600bps
		case 115200:U0DLL=32;break;//@PCLK=60MHz
		default: 		U0DLL=195;//for PCLK=30MHz
	}	
	U0LCR=0x3;////DLAB=0, WORD LENGTH=8bits, PARITY=Disabled,No of Stop Bits=1
}

unsigned char uart0_rx(void)
{
 while(!(U0LCR&0X1));
 return U0RBR;
}

void uart0_tx(unsigned char data)
{
	U0THR=data; 
    while(!(U0LCR&(1<<5)));
}

