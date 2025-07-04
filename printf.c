#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list myFormat;
	int i = 0, count = 0;
	int temp;

	if (format == NULL)
		return (-1);

	va_start(myFormat, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(myFormat);
				return (-1);
			}

			if (format[i] == '%')
			{
				count += _putchar('%');
			}
			else
			{
				temp = get_format_func(format[i], myFormat);
				if (temp == -1)
				{
					count += _putchar('%');
					count += _putchar(format[i]);
				}
				else
				{
					count += temp;
				}
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
