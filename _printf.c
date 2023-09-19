#include "main.h"

/**
 * _printf - It receives the main string and all the necessary parameters to
 * print a formated string
 * @format: String containing all the desired characters
 * Return: Total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_v f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
