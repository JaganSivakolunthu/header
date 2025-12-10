#ifndef CAN_DRIVER_H
#define CAN_DRIVER_H

#include <LPC21xx.h>
#include "header.h"

// CAN1 driver functions
void can1_init(void);
void can1_tx(u32 id, u32 rtr, u32 dlc, u32 byteA, u32 byteB);
void can1_rx(u32 *id, u32 *rtr, u32 *dlc, u32 *byteA, u32 *byteB);

#endif





 
