#include "main.h"
/**
 * _printf - Displays inputs
 * @format: String argument passed to _print
 * Return: count
 */
int _printf(const char *format, ...)
{
	int count;

	va_list arg;

	if (format == NULL)
		return (-1);
	va_start(arg, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			count += format_print(*format, arg);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(arg);
	return (count);
}
