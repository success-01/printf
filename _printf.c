#include "main.h"

/**
 * _printf - String formatted (output)
 * @format: Is a character string with all desired characters
 *
 * Return: Printed amount of characters
 */

int _printf(const char *format, ...)
{
	int characters.print;
	conver_t  f_list[] = {
		{"b", print_binary},
		{"c", print_char},
		{"d", print_integer},
		{"r", print_reversed},
		{"R", rot 13},
		{"s", print_string},
		{"i", print_interger},
		{"%", print_percentage},
i		{"x", print_hexadecimal},
		{"X", print_heX},
		{"o", print_octal},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	/*calling function parser*/
	characters.print = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (chars_printed);
}
