#include "main.h"

unsigned int convert_s(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_S(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_r(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_R(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_s - It converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @ap: va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid:the width modifier.
 * @prec:the precision modifier.
 * @len: the length modifier.
 * @output: A buffer_v struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_s(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	while (*str != '\0' && prec > 0)
	{
		ret += _memcpy(output, str, 1);
		prec--;
		str++;
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_S - It converts an argument to a string and
 *             stores it to a buffer contained in a struct.
 * @ap: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 *
 * Description: Non-printable characteres (ASCII values < 32 or >= 127)
 *              are stored as \x followed by the ASCII code value in hex.
 */
unsigned int convert_S(va_list ap, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int size, index;
	unsigned int ret = 0;

	(void)len;
	str = va_arg(ap, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; str[size];)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (index = 0; *(str + index) != '\0' && index < prec; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
			ret += _memcpy(output, hex, 2);
			if (*(str + index) < 16)
				ret += _memcpy(output, &zero, 1);
			ret += convert_ubase(output, *(str + index),
					     "0123456789ABCDEF", flags, 0, 0);
			continue;
		}
		ret += _memcpy(output, (str + index), 1);
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_r - It reverses a string and stores it
 *             to a buffer contained in a struct.
 * @ap: A va_list pointing to the string to be reversed.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_r(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size, end, i;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	end = size - 1;
	prec = (prec == -1) ? size : prec;
	for (i = 0; end >= 0 && i < prec; i++)
	{
		ret += _memcpy(output, (str + end), 1);
		end--;
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_R - It converts a string to ROT13 and stores
 *             it to a buffer contained in a struct.
 * @ap: A va_list pointing to the string to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A lenth modifier.
 * @output: buffer_v struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_R(va_list ap, buffer_v *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int x, y, size;
	unsigned int ret = 0;

	(void)flags;
	(void)len;

	str = va_arg(ap, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	ret += print_string_width(output, flags, wid, prec, size);

	prec = (prec == -1) ? size : prec;
	for (x = 0; *(str + x) != '\0' && x < prec; i++)
	{
		for (y = 0; y < 52; y++)
		{
			if (*(str + x) == *(alpha + y))
			{
				ret += _memcpy(output, (rot13 + y), 1);
				break;
			}
		}
		if (y == 52)
			ret += _memcpy(output, (str + x), 1);
	}

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
