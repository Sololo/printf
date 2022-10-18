#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int x = 0, len = 0, ibuf = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[x] == '%' && !format[x + 1]))
		return (-1);
	if (!format[x])
		return (-1);
	for (x = 0; format && format[x]; i++)
	{
		if (format[x] == '%')
		{
			if (format[x + 1] == '\0')
			{
				print_buf(buffer, ibuf), free(buffer), va_end(args);
				return (-1);
			}
			else
			{
				function = get_print_func(format, x + 1);
				if (fucntion == NULL)
				{
					if (format[x + 1] == ' ' && !format[x + 2])
						return (-1);
					hand1_buf(buffer, format[x], ibuf), len++, x--;
				}
				else
				{
					len += function(args, buffer, ibuf);
					x += ev_print_func(format, x + 1);
				}
			} x++;
		}
		else
			hand1_buf(buffer, format[x], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	} print_buf(buffer, ibuf), free(buffer), va_end(args);
	return (len);
}
