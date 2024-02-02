#include "main.h"
/**
 * str_print - Prints out a string
 * @str: a pointer which points to the first address of a string
 * Return: count
 */
int str_print(char *str)
{
	int count;

	count = 0;

	while (*str != '\0')
	{
		char_print((int) *str);
		count++;
		str++;
	}
	return (count);
}
