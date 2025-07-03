#include "main.h"
/**
 * This file is going to hold our helper functions
 * will be linked to our main function
 *
 */

/**
 * print_string - Prints a string
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return count;
}

// _putchar - Writes a character to stdout
/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success, returns the number of characters written (1).
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int integer_i(int i)
{
	if (i < 0)
	{
		_putchar('-');
		i = -i;
	}

	if (i / 10)
		integer_i(i / 10);

	_putchar((i % 10) + '0');

	return (0);
}
	/**
	 * print_percent - Prints a percent sign
	 * @args: Argument list (unused)
	 * Return: Number of characters printed (1)
	 */
	int print_percent(va_list args)
	{
		(void)args;
		return (_putchar('%'));
	}

	/**
	 * print_int - Prints an integer
	 * @args: Argument list
	 * Return: Number of characters printed
	 */
	int print_int(va_list args)
	{
		int n = va_arg(args, int);
		int count = 0;
		unsigned int num;

		if (n < 0)
		{
			count += _putchar('-');
			num = -n;
		}
		else
		{
			num = n;
		}

		if (num / 10)
			count += print_unsigned_recursive(num / 10);

		count += _putchar((num % 10) + '0');
		return (count);
	}

	/**
	 * print_unsigned_recursive - Helper function to print unsigned int recursively
	 * @n: Number to print
	 * Return: Number of characters printed
	 */
	int print_unsigned_recursive(unsigned int n)
	{
		int count = 0;

		if (n / 10)
			count += print_unsigned_recursive(n / 10);

		count += _putchar((n % 10) + '0');
		return (count);
	}

	/**
	 * print_binary - Converts unsigned int to binary
	 * @args: Argument list
	 * Return: Number of characters printed
	 */
	int print_binary(va_list args)
	{
		unsigned int n = va_arg(args, unsigned int);
		int count = 0;
		char binary[32];
		int i = 0;

		if (n == 0)
			return (_putchar('0'));

		while (n > 0)
		{
			binary[i] = (n % 2) + '0';
			n /= 2;
			i++;
		}

		while (i > 0)
		{
			i--;
			count += _putchar(binary[i]);
		}

		return (count);
	}

	/**
 * print_unsigned - Prints an unsigned integer
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_unsigned_recursive(n));
}


/**
 * print_octal - Prints unsigned int in octal
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char octal[32];
	int i = 0;

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		octal[i] = (n % 8) + '0';
		n /= 8;
		i++;
	}

	while (i > 0)
	{
		i--;
		count += _putchar(octal[i]);
	}

	return (count);
}

/**
 * print_hex_lower - Prints unsigned int in lowercase hexadecimal
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char hex[32];
	int i = 0;
	char hex_digits[] = "0123456789abcdef";

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		hex[i] = hex_digits[n % 16];
		n /= 16;
		i++;
	}

	while (i > 0)
	{
		i--;
		count += _putchar(hex[i]);
	}

	return (count);
}

/**
 * print_hex_upper - Prints unsigned int in uppercase hexadecimal
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char hex[32];
	int i = 0;
	char hex_digits[] = "0123456789ABCDEF";

	if (n == 0)
		return (_putchar('0'));

	while (n > 0)
	{
		hex[i] = hex_digits[n % 16];
		n /= 16;
		i++;
	}

	while (i > 0)
	{
		i--;
		count += _putchar(hex[i]);
	}

	return (count);
}