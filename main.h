#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>

/* Flag Macro Modifiers */
#define F_MINUS.O ((flags >> 4) & 1)
#define F_PLUS.O (flags & 1)
#define F_ZERO.O ((flags >> 3) & 1)
#define F_HASH.O ((flags >> 2) & 1)
#define F_SPACE.O ((flags >> 1) & 1)
#define MINUS.O 16
#define PLUS.O 1
#define ZERO.O 8
#define HASH.O 4
#define SPACE.O 2

/* Length Macro Modifiers */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct buffer_h - A buffers defining struct that is new
 * @buffer: Points to an array character
 * @start: Points to the begininning of a buffer
 * @len: Length of string in buffer
 */
typedef struct buffer_u
{
	char *buffer;
	char *start;
	unsigned int len;
}buffer_v;

/**
 * struct convert_u - symbols structure and functions is defined
 * @specifier: Conversion specifier operator
 * @f: Associated function pointer
 */

typedef struct convert_u

{
	unsigned char specifier;
	unsigned int (*f)(va_list, buffer_v*, unsingned char, int);
}convert_v;

/**
 * struct flag_u - Function defining a new flag struct.
 * @flag: Represents a flag
 * @value: Value integer of flag
 */
typedef struct flag_u
{
	unsigned char flag;
	unsigned char value;
}flag_v;

/*Main functions*/
int _printf(const char *format, ...);
/* Conversion Specifier Function */
unsigned int c_convert(va_list args, buffer_v *output,unsigned char flags, int wid, int prec, unsigned char len);
unsigned int b_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int di_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int o_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int s_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int p_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int percent_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int R_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int r_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int X_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int x_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int S_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int u_convert(va_list args, buffer v *output, unsigned char flags, int wid, int prec, unsigned char len);

/* Modifiers */

#endif
