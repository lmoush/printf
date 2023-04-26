#include "main.h"
/**
 * print_char - it print characters
 * @types: it repreents list of args
 * @buffer: an array
 * @size: size
 * @width: the width
 * @flags: it calculates the flags
 * @precision: the precision
 * Return: the num of characters
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}
/**
 * print_string - it prints a string
 * @types: the list of args
 * @buffer: array
 * @width: width
 * @flags: calculate the flags
 * @precision: precision
 * @size: size
 * Return: num of chars
 */

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *string = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string =  "      ";
	}

	while (string[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}

		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (width);
		}
	}

	return (write(1, string, len));
}
