#include "main.h"
/**
 * print_unsigned - it prints an unsigned num
 * @types: the list of args
 * @buffer: an array to print
 * @flags: calculates the flags
 * @width: width
 * @precision: precision
 * @size: the size
 * Return: number of the characters printed
 */

int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);

        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[i--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';
 
        while (num > 0)
        {
                buffer[i--] = (num % 10) + '0';
                num /= 10;
        }
        i++;
        return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_octal - it prints an unsigned num in octal 
 * @types: list of args
 * @buffer: an array to print
 * @flags: calculates the flags
 * @width: width
 * @precision: the precision
 * @size: the size
 * Return: num of chars
 */

int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(width);
        num = convert_size_unsgnd(num, size);

        if (num == 0)
                buffer[i--] = '0';
        buffer[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[i--] = (num % 8) + '0';
                num /= 8;
        }

        if (flags & F_HASH && init_num != 0)
                buffer[i--] = '0';
        i++;

        return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - it prints an unsigned num in hexadecimal
 * @types: list of args
 * @buffer: buffer of array
 * @flags: calculates the flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: num of the characters
 */

int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, precision, size));
}
/**
 *
