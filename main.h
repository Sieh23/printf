#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * This the the main function
 * Responsible for storing our prototypes
 */

 /* Main printf function */
int _printf(const char *format, ...);

 /* Helper functions */
int print_string(va_list args);
 
/* self-putchar function*/
int _putchar(char c);


/* Conversion specifier i */
int integer_i(int i);

//helper function to print a percent sign
int print_percent(va_list args);


 #endif
