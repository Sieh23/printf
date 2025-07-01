#include "main.h"
#include <stdio.h>
#include <stdlib.h>

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

	_putchar((i % 10)+ '0');

	return(0);
}

int main()
{
	integer_i(-2998);
	_putchar('\n');
	return(0);
}
