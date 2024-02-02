#include "main.h"
#include <stdio.h>

int char_print(int val)
{
    return write(1, &val, 1);
}

int str_print(char* str)
{
    int count;
    count = 0;

    while(*str != '\0')
    {
        char_print((int) *str);
        count++;
        str++;
    }
    return count;
}

int digit_print(long val, int base)
{
    int count;
    char* symbols;

    symbols = "0123456789abcdef";
    count = 0;
    if (val < 0)
    {
        write(1,"-", 1);
        return digit_print(-val, base) + 1;
    }
    else if (val < base)
    {
        return char_print(symbols[val]);
    }
    else
    {    count += digit_print(val/base, base);
        return count + digit_print(val%base, base);
    }
}

int format_print(char Formatspecifier, va_list arg)
{
    int count ;
    count = 0;

    if (Formatspecifier == 'c')
        count += char_print(va_arg(arg, int));
    
    else if (Formatspecifier == 's')
        count += str_print(va_arg(arg, char*));
    
    else if (Formatspecifier == 'd')
        count += digit_print((va_arg(arg, int)), 10);
    
    else if (Formatspecifier == 'x')
        count += digit_print((va_arg(arg, unsigned int)), 16);

    else if (Formatspecifier == 'o')
        count += digit_print((va_arg(arg, unsigned int)), 8);

    else if (Formatspecifier == 'b')
        count += digit_print((va_arg(arg, unsigned int)), 2);
    else if (Formatspecifier == 'i')
    {
	    Formatspecifier++;
	    if ((Formatspecifier == 0) && ((Formatspecifier++) != 'x'))
	    {
		    count += digit_print((va_arg(arg, int)), 8);
	    }
	    else if ((Formatspecifier == 0) && ((Formatspecifier++) == 'x'))
	    {
		    count += digit_print((va_arg(arg, int)), 16);
	    }
	    else
	    {
		    count += digit_print((va_arg(arg, int)), 10);
	    }
    }
    else
        count += write(1,&Formatspecifier, 1);

    return count;
}

int _printf(const char* format, ...)
{
    int count;


    va_list arg;

    if (format == NULL)
        return(-1);

    va_start(arg, format);
    count = 0;
    while (*format != '\0')
    {
        if(*format == '%')
        {
            ++format;
            count += format_print(*format, arg);
        }
        else
            count += write(1, format, 1);
        format++;
    }

    va_end(arg);
    return count;
}
