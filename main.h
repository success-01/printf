#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>

/* Flag Macro Modifiers */
#define F_NEGATIVE ((flags >> 4) & 1)
#define F_PLUS (flags & 1)
#define F_ZERO ((flags >> 3) & 1)
#define F_HASH ((flags >> 2) & 1)
#define F_SPACE ((flags >> 1) & 1)
#define NEGATIVE 16
#define PLUS 1
#define ZERO 8
#define HASH 4
#define SPACE 2

/* Length Macro Modifiers */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct buffer_u - A buffers defining struct that is new
 * @buffer: Points to an array character
 * @start: Points to the begininning of a buffer
 * @len: Length of string in buffer
 */
typedef struct buffer_u
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_v;

/**
 * struct convert_u - New type defining stuct convert.
 * @specifier: Conversion specifier operator.
 * @f: Associated function pointer.
 */

typedef struct convert_u

{
	unsigned char specifier;
	unsigned int (*f)(va_list, buffer_v *, unsingned char,
			int, int, unsigned char);
} convert_v;

/**
 * struct flag_u - Function defining a new flag struct.
 * @flag: Represents a flag
 * @value: Value integer of flag
 */
typedef struct flag_u
{
	unsigned char flag;
	unsigned char value;
} flag_v;

	/*Main functions*/
int _printf(const char *format, ...);
	/* Conversion Specifier Function */
	unsigned int c_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int b_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int di_convert(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int o_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int s_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int p_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int percent_convert(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int R_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int r_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int X_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int x_convert(va_list args, buffer_v *output, unsigned char flags,
			int wid, int prec, unsigned char len);
	unsigned int S_convert(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int u_convert(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);

	/* Modifiers */
	unsigned int print_width(buffer_v *output, unsigned int printed,
			unsigned char flags, int wid);
	unsigned int print_width_string(buffer_v *output,
			unsigned char flags, int wid, int prec, int size);
	unsigned int print_neg_width(buffer_v *output, unsigned int printed,
			unsigned char flags, int width);


	/* Handlers */
	unsigned char flags_handler(const char *flags, char *index);
	unsigned char length_handler(const char *modifier, char *index);
	unsigned int (*specifiers_handler(const char *specifier))(va_list, buffer_v *,
			unsinged char flags, int wid);
	int width_handler(va_list args, const char *modifier, char *index);
	int precision_handler(va_list args, const char *modifier, char *index);

	/* Helper Functions */
	unsigned int sbase_converter(buffer_v *output, long int num, char *base,
			unsigned char flags, int wid, int prec);
	unsigned int ubase_converter(buffer_v *output, unsigned long int num,
			char *base, unsigned char flags, int wid, int prec);
	void buffer_free(buffer_v *output);
	buffer_v *buffer_init(void);

#endif
