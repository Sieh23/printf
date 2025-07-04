#include "main.h"

/**
 * get_format_func - Matches format specifier with handler
 * @c: format specifier
 * @args: argument list
 *
 * Return: number of characters printed or -1 for unknown
 */
int get_format_func(char c, va_list args)
{
	format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'p', print_pointer},
		{'S', print_custom_string},
		{'r', print_rev},
		{'R', print_rot13},
		{'\0', NULL}
	};

	int i = 0;

	while (formats[i].spec)
	{
		if (formats[i].spec == c)
			return (formats[i].func(args));
		i++;
	}

	return (-1);
}
