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

int _putchar(char c)
{
	return (write(1, &c, 1));
}
