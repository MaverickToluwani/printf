#include "main.h"
/**
 * format_print - check for a format specifer
 * This function handles various format specifiers
 * @Formatspecifier: Format specifier
 * @arg: List of arguments in variadic function
 * Return: count
 */
int format_print(char Formatspecifier, va_list arg)
{
	int count;

	count = 0;
	/**
	 * The code below checks for modifier cases
	 */
	if (Formatspecifier == 'c')
		count += char_print(va_arg(arg, int));
	else if (Formatspecifier == 's')
		count += str_print(va_arg(arg, char*));
	else if (Formatspecifier == 'd')
		count += digit_print((va_arg(arg, int)), 10);
	else if (Formatspecifier == 'x' || Formatspecifier == 'X')
		count += digit_print((va_arg(arg, unsigned int)), 16);
	else if (Formatspecifier == 'o')
		count += digit_print((va_arg(arg, unsigned int)), 8);
	else if (Formatspecifier == 'b')
		count += digit_print((va_arg(arg, unsigned int)), 2);
	else if (Formatspecifier == 'i')
	{
		Formatspecifier++;
		if ((Formatspecifier == 0) && ((Formatspecifier++) != 'x'))
			count += digit_print((va_arg(arg, int)), 8);
		else if ((Formatspecifier == 0) && ((Formatspecifier++) == 'x'))
			count += digit_print((va_arg(arg, int)), 16);
		else
			count += digit_print((va_arg(arg, int)), 10);
	}
	else if (Formatspecifier == 'u')
		count += digit_print((va_arg(arg, unsigned int)), 10);
	else if (Formatspecifier == 'p')
		count += digit_print((va_arg(arg, int)), 16);
	else if (Formatspecifier == '%')
		count += write(1, "%", 1);
	else
		count += write(1, &Formatspecifier, 1);
	return (count);
}
