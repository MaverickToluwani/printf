#include "main.h"
/**
 * digit_print - Prints numbers with 0-f
 * @val: an integer
 * @base: number base of integer
 * Return: a digit_print
 */
int digit_print(long val, int base)
{
	int count;
	char *symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (val < 0)
	{
		write(1, "-", 1);
		return (digit_print(-val, base) + 1);
	}
	else if (val < base)
	{
		return (char_print(symbols[val]));
	}
	else
	{
		count += digit_print(val / base, base);
		return (count + digit_print(val % base, base));
	}
}
