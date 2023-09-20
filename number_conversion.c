#include "main.h"

unsigned int convert_di(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_b(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_di - It converts an argument to a signed int and
 *              stores it to a buffer contained in a struct.
 * @ap: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_v struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	long int m, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		m = va_arg(ap, long int);
	else
		m = va_arg(ap, int);
	if (len == SHORT)
		m = (short)m;

	/* Handle space flag */
	if (F_SPACE == 1 && m >= 0)
		ret += _memcpy(output, &space, 1);

	if (prec <= 0 && F_NEG == 0) /* Handle width  */
	{
		if (m == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (m < 0) ? -m : m; copy > 0; copy /= 10)
				count++;
		}
		count += (m == 0) ? 1 : 0;
		count += (m < 0) ? 1 : 0;
		count += (F_PLUS == 1 && m >= 0) ? 1 : 0;
		count += (F_SPACE == 1 && m >= 0) ? 1 : 0;

		/* Handle plus flag when zero flag is active */
		if (F_ZERO == 1 && F_PLUS == 1 && m >= 0)
			ret += _memcpy(output, &plus, 1);
		/*Print negative sign when zero flag is active */
		if (F_ZERO == 1 && m < 0)
			ret += _memcpy(output, &neg, 1);

		pad = (F_ZERO == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			ret += _memcpy(output, &pad, 1);
	}

	/* Print negative sign when zero flag is not active */
	if (F_ZERO == 0 && m < 0)
		ret += _memcpy(output, &neg, 1);
	/* Handle plus flag when zero flag is not active */
	if (F_ZERO == 0 && (F_PLUS == 1 && m >= 0))
		ret += _memcpy(output, &plus, 1);

	if (!(m == 0 && prec == 0))
		ret += sbase_converter(output, m, "0123456789",
				flags, 0, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_b - Converts an unsigned int argument to binary
 *             and stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_v struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_b(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int num;

	num = va_arg(ap, unsigned int);

	(void)len;

	return (ubase_converter(output, num, "01", flags, wid, prec));
}

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @ap: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_v struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_o(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (F_HASH == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		ret += ubase_converter(output, num, "01234567",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @ap: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_u(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;

	if (len == LONG)
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && prec == 0))
		ret += ubase_converter(output, num, "0123456789",
				flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
