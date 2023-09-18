#include "main.h"

unsigned int convert_di(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_o(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_u(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_b(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);

/**
 *convert_di - converts argument to signed int and stores arg to buffer contained in struct.
 *@ap: va_list pointing to arg to be converted
 *@flags:flag specifier
 *@wid:a width specifier
 *@prec:a precision specifier
 *@len:length specifier
 *@output:buffer_t structure with char array
 *Return: number of bytes stored to a buffer.
 */
unsigned int convert_di(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len);
{
	long int m, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (len == LONG)
		m = va_arg(ap, long int);
	else
		m = va_arg(ap, int);
	if (len == SHORT)
		m = (short)d;

	if (SPACE_FLAG == 1 && m >= 0)
	ret += _memcpy(output, &space, 1);

	if (prec <= 0 && NEG_FLAG == 0)
	{
		if (m == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (m < 0) ? -m : d; copy > 0; copy /= 10)
				count++;
		}
		count += (m == 0) ? 1 : 0;
		count += (m < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && m >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && m >= 0) ? 1 : 0;

		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && m >= 0)
			ret += _memcpy(output, &plus, 1);

		if (ZERO_FLAG == 1 && m < 0)
			ret += _memcpy(output, &neg, 1);

		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (wid -= count; wid > 0; wid--)
			ret += _memcpy(output, &pad, 1);
	}
}

/**
 *convert_o - converts unsigned int to octal and stores it in buffer kept in struct
 * @ap: va_list refrencing arg to undergo conversion
 * @len:length specifier
 * @wid:width specifier
 * @prec:precision specifier
 * @flags:flag specifier
 * @output:buffer_t struct with character array.
 * Return:number of bytes stored to the buffer.
 */
unsigned int convert_o(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
		num = va_arg(ap, unsigned long int);
	else
		num = va_arg(ap, unsigned int);

	if (len == SHORT)
		num = va_arg(unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "01234567", flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_u - converts unsigned int to decimal and stores it to buffer kept in struct
 * @ap:va_list referencing arg to undergo conversion
 * @flags:flag specifier
 * @len:length specifier
 * @wid:width specifier
 * @prec:precision specifier
 * @output:buffer_t struct with a array of a character type
 * Return:number of bytes store to a buffer
 */
unsigned int convert_u(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int numb;
	unsigned int ret = 0;

	if (len == LONG)
		numb = va_arg(ap, unsigned long int);
	else
		numb = va_arg(ap, unsigned int);
	if (len == SHORT)
		numb = va_arg(unsigned short)numb;

	if (!(numb == 0 && prec == 0))
		ret += convert_ubase(output, numb, "0123456789", flags, wid, prec)

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_b - converts unsigned int to binary and stores it to a buffer kept in struct
 * @ap:va_list referencing arg to undergo conversion
 * @flags:flag specifier
 * @len:length specifier
 * @wid:width specifier
 * @prec:precision specifier
 * @output:buffer_t struct with an array of a character type
 * Return:number of bytes to store to a buffer
 */
unsigned int convert_b(va_list ap, buffer_t *output, unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned int numb;

	numb = va_arg(ap, unsigned int);

	(void)len;

	return (convert_ubase(output, numb, "01", flags, wid, prec));
}
