#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * This is the main header file
 * Responsible for storing all function prototypes and structs
 */

/*
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

/* Format selector */
int get_format_func(char c, va_list args);

/* Character and string handling */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/* Integer and number handling */
int print_int(va_list args);
int print_unsigned(va_list args);
int print_unsigned_recursive(unsigned int n);
int print_binary(va_list args);
int print_octal(va_list args);
int print_hex_upper(va_list args);
int print_hex_lower(va_list args);

/* Pointer handling */
int print_pointer(va_list args);

/* Custom formats */
int print_custom_string(va_list args);
int print_rev(va_list args);
int print_rot13(va_list args);

/* Helper functions */
int _putchar(char c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _abs(int n);
int print_hex_char(char c);

/* String transformations */
void _rev_string(char *c);
void _rot13(char *c);


#endif /* MAIN_H */
