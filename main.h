#ifndef MAIN_H_
#define MAIN_H_

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define F_PLUS (flags & 1)
#define F_SPACE ((flags >> 1) & 1)
#define F_HASH ((flags >> 2) & 1)
#define F_ZERO ((flags >> 3) & 1)
#define F_NEG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_u - Type defining a buffer struct.
 * @buffer: Pointer to a character array.
 * @start: Pointer to the start of buffer.
 * @len: length of string stored in buffer.
 */
typedef struct buffer_u
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_v;

/**
* struct convert_u - New type defining a converter struct.
 * @specifier: Character representing a conversion specifier.
 * @func: Pointer to a conversion function corresponding to specifier.
 */
typedef struct convert_u
{
	unsigned char specifier;
	unsigned int (*h)(va_list, buffer_v *,
			unsigned char, int, int, unsigned char);
} converter_u;

/**
 * struct flag_u - New type defining a flags struct.
 * @flag: Character representing a flag.
 * @value: Integer value of the flag.
 */
typedef struct flag_u
{
	unsigned char flag;
	unsigned char value;
} flag_v;

int _printf(const char *format, ...);

	/* Conversion Specifier Functions */
	unsigned int convert_c(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_s(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_di(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_percent(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_b(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_u(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_o(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_x(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_X(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_S(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_p(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_r(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);
	unsigned int convert_R(va_list args, buffer_v *output,
			unsigned char flags, int wid, int prec, unsigned char len);

	/* Handlers */
	unsigned char flags_handler(const char *flags, char *index);
	unsigned char length_handler(const char *modifier, char *index);
	int width_handler(va_list args, const char *modifier, char *index);
	int precision_handler(va_list args, const char *modifier, char *index);
	unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_v *,
			unsigned char, int, int, unsigned char);

	/* Modifiers */
	unsigned int print_width(buffer_v *output, unsigned int printed,
			unsigned char flags, int wid);
	unsigned int print_string_width(buffer_v *output,
			unsigned char flags, int wid, int prec, int size);
	unsigned int print_neg_width(buffer_v *output,
			unsigned int printed, unsigned char flags, int wid);

	/* Helper Functions */
	buffer_v *init_buffer(void);
	void bufferfree(buffer_v *output);
	unsigned int _memcpy(buffer_v *output, const char *src, unsigned int n);
	unsigned int sbase_converter(buffer_v *output,
			long int num, char *base, unsigned char flags, int wid, int prec);
	unsigned int ubase_converter(buffer_v *output, unsigned long int num,
			char *base, unsigned char flags, int wid, int prec);

#endif
