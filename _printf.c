#include "main.h"

void clearing(va_list args, buffer_v *output);
int running_printf(const char *format, va_list args, buffer_v *output);
int _printf(const char *format, ...);

/**
 * clearing - Clears operations for _printf.
 * @args: A va_list of arguments provided to _printf.
 * @output: A buffer_t struct.
 */
void clearing(va_list args, buffer_v *output)
{
	va_end(args);
	write(1, output->start, output->len);
	bufferfree(output);
}

/**
 * running_printf - Reads the string format for _printf.
 * @format: Character string to print (may contain directives).
 * @output: A buffer_t struct with a buffer.
 * @args: A va_list of arguments.
 *
 * Return: Amount of characters stored to output.
 */
int running_printf(const char *format, va_list args, buffer_v *output)
{
	int x, wid, prec, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*func)(va_list, buffer_v *,
			unsigned char, int, int, unsigned char);

	for (x = 0; *(format + x); x++)
	{
		len = 0;
		if (*(format + x) == '%')
		{
			tmp = 0;
			flags = flags_handler(format + x + 1, &tmp);
			wid = width_handler(args, format + x + tmp + 1, &tmp);
			prec = precision_handler(args, format + x + tmp + 1,
					&tmp);
			len = length_handler(format + x + tmp + 1, &tmp);
			h = *handle_specifiers(format + x + tmp + 1);
			if (h != NULL)
			{
				x += tmp + 1;
				ret += h(args, output, flags, wid, prec, len);
				continue;
			}
			else if (*(format + x + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(output, (format + x), 1);
		x += (len != 0) ? 1 : 0;
	}
	clearing(args, output);
	return (ret);
}

/**
 * _printf - Outputs formatted strings.
 * @format: Character string to printed (may contain directives).
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	buffer_v *output;
	va_list args;
	int ret;

	if (format == NULL)
		return (-1);
	output = init_buffer();

	if (output == NULL)
		return (-1);
	va_start(args, format);
	ret = running_printf(format, args, output);
	return (ret);
}

