#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function that produces output according to format
 *
 *
 * Return:the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list argp;
	va_start(argp, *format);

	int count = 0;

	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
