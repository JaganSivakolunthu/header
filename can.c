/*can.c*/
#include "can.h"

void can1_init()
{
	VPBDIV=1;
	PINSEL1|=(1<<18);
	PINSEL1&=~(1<<19);
	C1MOD=0x1;//reset CAN1 controller
	AFMR=0x2;
	C1BTR=0x001C001D;//for B125Kbps
	//C1IER=0x1;//Enable CAN1 RX Interrupt
	C1MOD=0x0;//CAN1 controller into normal mode
}
void can1_tx(u32 id,u32 rtr,u32 dlc,u32 byteA,u32 byteB)
{
	C1TID1=id;
	C1TFI1=(dlc<<16);
	if(rtr==0)//if data frame
	{
		C1TFI1&=~(1<<30);
		C1TDA1=byteA;
		C1TDB1=byteB;	
	}
	else	
		C1TFI1|=(1<<30);
	C1CMR=(1<<0)|(1<<5);
	while((C1SR&(1<<3))==0);
}
void can1_rx(u32 *id,u32 *rtr, u32 *dlc, u32 *byteA,u32 *byteB)
{
	while((C1SR&0x1)==0);
  *id=C1RID;
  *rtr=(C1RFS>>30)&1;
	*dlc=(C1RFS>>16)&0xF;
	*byteA=C1RDA;
	*byteB=C1RDB;
	C1CMR=(1<<2);//release rx buffers
}





















