#include "main.h"

unsigned int convert_x(va_list ap, buffer_v *output,
unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_X(va_list ap, buffer_v *output,
unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_x – It converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 * @ap: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: width modifier.
 * @prec: precision modifier.
 * @len: length modifier.
 * @output: A buffer_v struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(va_list ap, buffer_v *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x";

	if (len == LONG)
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (F_HASH == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += ubase_converter(output, num, "0123456789abcdef",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_X – It converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 * @ap: va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: width modifier.
 * @prec: precision modifier.
 * @len: length modifier.
 * @output: A buffer_v struct containing a character array.
 *
 * Return: number of bytes stored to the buffer.
 */
unsigned int convert_X(va_list ap, buffer_v *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(ap, unsigned long);
	else
		num = va_arg(ap, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (F_HASH == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += ubase_converter(output, num, "0123456789ABCDEF",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
