#include "main.h"

unsigned int print_width(buffer_v *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buffer_v *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_v *output, unsigned int printed,
		unsigned char flags, int wid);

/**
 * print_width - Stores leading spaces to the buffer for width modifier.
 * @output: A buffer_v struct containing a character array.
 * @printed: The current number of characters already printed to output
 *           for a given number specifier.
 * @flags: flag modifiers.
 * @wid: width modifier.
 *
 * Return:The number of bytes stored to the buffer.
 */
unsigned int print_width(buffer_v *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (F_NEG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_string_width - Stores leading spaces to buffer for width modifier.
 * @output: A buffer_v struct containing a character array.
 * @flags: the flag modifiers.
 * @wid: the width modifier.
 * @prec: the precision modifier.
 * @size: The size of the string.
 *
 * Return:Number of bytes stored to the buffer.
 */
unsigned int print_string_width(buffer_v *output,
		unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (F_NEG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - Stores trailing spaces to a buffer for a '-' flag.
 * @output: A buffer_v struct containing a character array.
 * @printed: The current number of bytes already stored to output
 *           for a given specifier.
 * @flags:the  flag modifiers.
 * @wid: the width modifier.
 *
 * Return:Number of bytes stored to the buffer.
 */
unsigned int print_neg_width(buffer_v *output, unsigned int printed,
		unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (F_NEG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
