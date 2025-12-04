#ifndef HEADER_H
#define HEADER_H

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed char s8;
typedef signed int s32;
typedef float f32;

#define DATA_PINS 0xFF
#define RS 1<<8
#define EN 1<<9

typedef struct can_frame{
	u32 m_id;
	u32 rtr;
	u32 dlc;
	u32 byteA;
	u32 byteB;
} can_msg;

void delay_ms(u32 );
void LCD_INIT(void);
void LCD_COMMAND(u8 );
void LCD_DATA(u8 );
void LCD_STRING(const u8 *);
void LCD_INTEGER(s32 );
void LCD_FLOAT(f32 );
void LCD_BINARY(u32 );

#endif



