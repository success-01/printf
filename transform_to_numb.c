#include "main.h"

	unsigned int convert_sbase(buffer_t *output, long int num, char *base,
			unsigned char flags, int wid, int prec);
	unsigned int convert_ubase(buffer_t *output,
			unsigned long int num, char *base,
			unsigned char flags, int wid, int prec);

/**
 * sbase_converter - Converts a signed long to an inputted base and stores
 * the result to a buffer contained in a struct.
 * @output: A buffer_v struct containing a character array.
 * @num: A signed long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
	unsigned int sbase_converetr(buffer_v *output, long int num, char *base,
			unsigned char flags, int wid, int prec)
{
	int size;
	char digit, pad = '0';
	unsigned int ret = 1;

	for (size = 0; *(base + size);)
		size++;

	if (num >= size || num <= -size)
		ret += convert_sbase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		for (; prec > 1; prec--, wid--) /* Precision handler */
			ret += _memcpy(output, &pad, 1);

		if (F_NEG == 0) /* Width handler */
		{
			pad = (F_ZERO == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
	}
	digit = base[(num < 0 ? -1 : 1) * (num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}

/**
 * ubase _converter- Converts an unsigned long to an inputted base and
 * stores the result to a buffer contained in a struct.
 * @output: A buffer_v struct containing a character array.
 * @num: An unsigned long to be converted.
 * @base: A pointer to a string containing the base to convert to.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
	unsigned int convert_ubase(buffer_t *output,
			unsigned long int num, char *base, unsigned char flags, int wid, int prec)
{
	unsigned int size, ret = 1;
	char digit, pad = '0', *lead = "0x";

	for (size = 0; *(base + size);)
		size++;

	if (num >= size)
		ret += convert_ubase(output, num / size, base,
				flags, wid - 1, prec - 1);
	else
	{
		if (((flags >> 5) & 1) == 1) /* Printing a ptr address */
		{
			wid -= 2;
			prec -= 2;
		}
		for (; prec > 1; prec--, wid--) /* Precision handler */
			ret += _memcpy(output, &pad, 1);

		if (F_NEG == 0) /* Width handler */
		{
			pad = (F_ZERO == 1) ? '0' : ' ';
			for (; wid > 1; wid--)
				ret += _memcpy(output, &pad, 1);
		}
		if (((flags >> 5) & 1) == 1) /* Print 0x for ptr address */
			ret += _memcpy(output, lead, 2);
	}
	digit = base[(num % size)];
	_memcpy(output, &digit, 1);

	return (ret);
}
