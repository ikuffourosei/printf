#include "main.h"

void print_input(char input[], int *input_ind);
/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, input_ind = 0;
	va_list list;
	char input[BUFF_SIZE];

	va_start(list, format);

	if (format == NULL)
	{
		return (-1);
	}
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			input[input_ind++] = format[i];
			if (input_ind == BUFF_SIZE)
			{
				print_input(input, &input_ind);
				printed_chars++;
			}
		}
		else
		{
			print_input(input, &input_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, input, flags, width, precision, size);
			if (printed == -1)
			{
				return (-1);
			}
			printed_chars += printed;
		}
	}
	print_input(input, &input_ind);
	va_end(list);
	return (printed_chars);
}
/**
* print_input - Prints the contents of the input if it exist
* @input: Array of chars
* @input_ind: Index at which to add next char, represents the length.
*/
void print_input(char input[], int *input_ind)
{
	if (*input_ind > 0)
	{
		write(1, &input[0], *input_ind);
	}
	*input_ind = 0;
}
