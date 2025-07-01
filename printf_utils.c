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

<<<<<<< HEAD
int integer_i(int i)
{
        if (i < 0)
        {
                _putchar('-');
                i = -i;
        }

        if (i / 10)
                integer_i(i / 10);

        _putchar((i % 10)+ '0');

        return(0);
=======
/**
 * print_percent - Prints a percent sign
 * @args: Argument list (unused)
 * Return: Number of characters printed (1)
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
>>>>>>> refs/remotes/origin/main
}
