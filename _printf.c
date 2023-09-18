#include "main.h"

void clearing(va_list args, buffer_v *output);
int running_printf(const char *format, va_list args, buffer_v *output);
int _printf(const char *format, ...);
/**
 * clearing - Clears unwanted data for _printf.
 * @args: Va_list of arguments for _printf.
 * @output: buffer_v struct.
 */
void clearing(va_list args, buffer_v *output);
{
	va_end(args);
	write(1, output->start, output->len);
	buffer_free(output);
}

/**
 * running _printf -Reads _printf string format output.
 * @format: Prints character string (may have directives).
 * @output: buffer_v struct with a buffer.
 * @args: arguments for va_list.
 * Return: Amount of characters stored to output.
 */
int running_printf(const char *format, va_list args, buffer_v *output);
{
	int x, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buffer_v *, unsinged char,
			int, int, unsigned char);

	for (x = 0; *(format + x); x++)
	{
		len = 0;
		if (*(format + x) == '%')
		{
			tmp = 0;
			flags = flags_handler(format + x + 1, &tmp);
			prec = precision_handler(args, format + x + tmp + 1, &tmp);
			wid = width_handler(args, format + x + tmp + 1, &tmp);
			f = specifiers_handler(format + x + tmp + 1);
		len = length_handler(format + x + tmp + 1, &tmp);
	if (f != NULL)
	{
	x += tmp + 1;
ret += f(args, output, flags, wid, prec, len);
continue;
	}
	else if (*(format + x + tmp + 1) == '\0')
	{
		ret = -1;
		break;
	}
		}
		ret += memcopy(output, (format + x), 1);
		x += (len != 0) ? 1 : 0;
	}
	clearing(args, output);
	return (ret);
}
/**
 * _printf - Formatted string output
 * @format:String character to be printed (may contain directives)
 *
 * Return: Amount of characters to be printed
 */

int _printf(const char *format, ...)
{
	buffer_v *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = buffer_init();
	if (output == NULL)
		return (-1);

	va_start(args, format);

	ret = running_printf(format, args, output);

	return (ret);
}
