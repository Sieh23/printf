#include "main.h"

/* print_string - Prints a string */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return count;
}

/* _putchar - Writes a character to stdout */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/* print_char - Prints a single character */
int print_char(va_list args)
{
	return _putchar(va_arg(args, int));
}

/* print_percent - Prints a percent sign */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/* print_int - Prints an integer */
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
		num = n;

	if (num / 10)
		count += print_unsigned_recursive(num / 10);

	count += _putchar((num % 10) + '0');
	return count;
}

/* Helper: recursive printing of unsigned integer */
int print_unsigned_recursive(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_recursive(n / 10);

	count += _putchar((n % 10) + '0');
	return count;
}

/* print_unsigned - Prints unsigned integer */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	return print_unsigned_recursive(n);
}

/* print_binary - Prints unsigned int in binary */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	char binary[32];
	int i = 0;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		binary[i++] = (n % 2) + '0';
		n /= 2;
	}

	while (i--)
		count += _putchar(binary[i]);

	return count;
}

/* print_octal - Prints unsigned int in octal */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char octal[32];
	int i = 0, count = 0;

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		octal[i++] = (n % 8) + '0';
		n /= 8;
	}

	while (i--)
		count += _putchar(octal[i]);

	return count;
}

/* print_hex_lower - Lowercase hex */
int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[32];
	int i = 0, count = 0;
	char *digits = "0123456789abcdef";

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		hex[i++] = digits[n % 16];
		n /= 16;
	}

	while (i--)
		count += _putchar(hex[i]);

	return count;
}

/* print_hex_upper - Uppercase hex */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex[32];
	int i = 0, count = 0;
	char *digits = "0123456789ABCDEF";

	if (n == 0)
		return _putchar('0');

	while (n > 0)
	{
		hex[i++] = digits[n % 16];
		n /= 16;
	}

	while (i--)
		count += _putchar(hex[i]);

	return count;
}

/* _rev_string - Reverses a string in-place */
void _rev_string(char *s)
{
	int i = 0, j = _strlen(s) - 1;
	char tmp;

	while (i < j)
	{
		tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
}

/* print_rev - Prints a reversed string */
int print_rev(va_list args)
{
	char *s = va_arg(args, char *);
	char *copy;
	int len, i, count = 0;

	if (s == NULL)
		s = "(null)";

	len = _strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return 0;

	_strcpy(copy, s);
	_rev_string(copy);

	for (i = 0; i < len; i++)
		count += _putchar(copy[i]);

	free(copy);
	return count;
}

/* _rot13 - Applies ROT13 to a string */
void _rot13(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z'))
			s[i] = ((s[i] - 'a' + 13) % 26) + 'a';
		else if ((s[i] >= 'A' && s[i] <= 'Z'))
			s[i] = ((s[i] - 'A' + 13) % 26) + 'A';
	}
}

/* print_rot13 - Prints a ROT13 string */
int print_rot13(va_list args)
{
	char *s = va_arg(args, char *);
	char *copy;
	int len, i, count = 0;

	if (s == NULL)
		s = "(null)";

	len = _strlen(s);
	copy = malloc(len + 1);
	if (!copy)
		return 0;

	_strcpy(copy, s);
	_rot13(copy);

	for (i = 0; i < len; i++)
		count += _putchar(copy[i]);

	free(copy);
	return count;
}

/* print_custom_string - Prints non-printable chars as \xXX */
int print_custom_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0, i;

	if (!s)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += print_hex_char(s[i]);
		}
		else
			count += _putchar(s[i]);
	}
	return count;
}

/* print_hex_char - Helper to print a char in \xXX format */
int print_hex_char(char c)
{
	int count = 0;
	char digits[] = "0123456789ABCDEF";

	count += _putchar(digits[(c >> 4) & 0xF]);
	count += _putchar(digits[c & 0xF]);

	return count;
}

/* print_pointer - Print pointer address */
int print_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long addr = (unsigned long)ptr;
	char hex[32];
	char *digits = "0123456789abcdef";
	int i = 0, count = 0;

	if (!ptr)
		return write(1, "(nil)", 5);

	count += _putchar('0');
	count += _putchar('x');

	while (addr)
	{
		hex[i++] = digits[addr % 16];
		addr /= 16;
	}

	while (i--)
		count += _putchar(hex[i]);

	return count;
}

/* _strlen - Get string length */
int _strlen(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;

	return len;
}

/* _strcpy - Copy string */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

/* _abs - Return absolute value */
int _abs(int n)
{
	return (n < 0 ? -n : n);
}
