/**
 * THis is where the main code will be
 *
 */

 #include "main.h"

 int _printf(const char *format, ...)
 {
     va_list myFormat;

    int i = 0, count = 0;

    if (format == NULL)
    {
        return (-1);
    }

    va_start(myFormat, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == '\0')
            {
                return (-1);
                break;
            }
            if (format[i] == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += get_format_func(format[i], myFormat);
            }
        }
        else
        {
            count += _putchar(format[i]);
        }
        i++;
    }

    va_end(myFormat);
    return (count);
}

/**
 * get_format_func - Selects the correct function for format specifier
 * @c: Format specifier character
 * @args: Argument list
 * 
 * Return: Number of characters printed
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

	/* If no match found, print % and the character */
	_putchar('%');
	_putchar(c);
	return (2);
}