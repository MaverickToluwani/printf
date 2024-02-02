#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int format_print(char Formatspeifier, va_list arg);
int digit_print(long val, int base);
int str_print(char* str);
int char_print(int val);


#endif
