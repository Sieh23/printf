#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * This the the main function
 * Responsible for storing our prototypes
 */

 /**
 * struct format - Struct for format specifiers
 * @spec: The format specifier character
 * @func: The function associated with the specifier
 */
typedef struct format
{
	char spec;
	int (*func)(va_list);
} format_t;

/* Main printf function */
int _printf(const char *format, ...);

/* Helper functions */
int print_string(va_list args);
 
/* self-putchar function*/
int _putchar(char c);


/* Conversion specifier i */
int integer_i(int i);

/* helper function to print a percent sign */
int print_percent(va_list args);


/* function to print an integer */
int print_int(va_list args);

/* function to pring binary */
int print_binary(va_list args);

int print_unsigned(va_list args);

int print_octal(va_list args);

/* this is the reverse string function*/
void _rev_string(char *c);

// print custom string with non-printable chars as \xXX
int print_custom_string(va_list args);

// print the pointer address
int print_pointer(va_list args);

// print the length of a string
int _strlen(char *s);

// copy a string from source to destination
char *_strcpy(char *dest, char *src);

// print the absolute value of an integer
int _abs(int n);

#endif

