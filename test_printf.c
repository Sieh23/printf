#include "main.h"
#include <stdio.h>

/**
 * main - Test function for _printf
 * Return: Always 0
 */
int main(void)
{
    int len, len2;
    int x = 42;

    /* Test basic functionality */
    printf("=== BASIC TESTS ===\n");

    len = _printf("Hello, World!\n");
    len2 = printf("Hello, World!\n");
    printf("Custom: %d chars, Standard: %d chars\n\n", len, len2);

    /* Test character */
    printf("=== CHARACTER TEST ===\n");
    _printf("Character: [%c]\n", 'A');
    printf("Character: [%c]\n", 'A');
    printf("\n");

    /* Test string */
    printf("=== STRING TEST ===\n");
    _printf("String: [%s]\n", "Hello");
    printf("String: [%s]\n", "Hello");
    _printf("NULL string: [%s]\n", NULL);
    /* printf("NULL string: [%s]\n", (char *)NULL); */ 
    printf("\n");

    /* Test integers */
    printf("=== INTEGER TESTS ===\n");
    _printf("Positive: [%d]\n", 42);
    printf("Positive: [%d]\n", 42);
    _printf("Negative: [%d]\n", -42);
    printf("Negative: [%d]\n", -42);
    _printf("Zero: [%i]\n", 0);
    printf("Zero: [%i]\n", 0);
    printf("\n");

    /* Test percent */
    printf("=== PERCENT TEST ===\n");
    _printf("Percent: [%%]\n");
    printf("Percent: [%%]\n");
    printf("\n");

    /* Test binary (custom) */
    printf("=== BINARY TEST ===\n");
    _printf("Binary of 42: [%b]\n", 42);
    _printf("Binary of 0: [%b]\n", 0);
    _printf("Binary of 255: [%b]\n", 255);
    printf("\n");

    /* Test unsigned */
    printf("=== UNSIGNED TEST ===\n");
    _printf("Unsigned: [%u]\n", 42u);
    printf("Unsigned: [%u]\n", 42u);
    printf("\n");

    /* Test octal */
    printf("=== OCTAL TEST ===\n");
    _printf("Octal: [%o]\n", 42);
    printf("Octal: [%o]\n", 42);
    printf("\n");

    /* Test hexadecimal */
    printf("=== HEXADECIMAL TEST ===\n");
    _printf("Hex lower: [%x]\n", 255);
    printf("Hex lower: [%x]\n", 255);
    _printf("Hex upper: [%X]\n", 255);
    printf("Hex upper: [%X]\n", 255);
    printf("\n");

    /* Test pointer */
    printf("=== POINTER TEST ===\n");
    _printf("Pointer: [%p]\n", (void *)&x);
    printf("Pointer: [%p]\n", (void *)&x);
    _printf("NULL pointer: [%p]\n", NULL);
    printf("NULL pointer: [%p]\n", (void *)NULL);
    printf("\n");

    /* Test custom string */
    printf("=== CUSTOM STRING TEST ===\n");
    _printf("Custom string: [%S]\n", "Hello\nWorld\x01");
    printf("\n");

    /* Test reverse string */
    printf("=== REVERSE STRING TEST ===\n");
    _printf("Reverse: [%r]\n", "Hello");
    printf("\n");

    /* Test ROT13 */
    printf("=== ROT13 TEST ===\n");
    _printf("ROT13: [%R]\n", "Hello World");
    printf("\n");

    /* Test unknown specifier */
    printf("=== UNKNOWN SPECIFIER TEST ===\n");
    _printf("Unknown: [%z]\n");

    printf("\n");

    return (0);
}
