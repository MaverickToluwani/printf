#include "main.h"
/**
 * char_print - Prints out a characters
 * @val: An int of 1 byte
 * Return: int
 */
int char_print(int val)
{
	return (write(1, &val, 1));
}
