#include "shell.h"

/**
* print_error - Print an error message to standard error.
* @info: Pointer to the info_t structure.
* @estr: String containing the specified error type.
*
* Return: None.
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
_eputs(": ");
if (info->err_num != -1)
_eputs(convert_number(info->err_num, 10, CONVERT_SIGNED));
_eputchar('\n');
}

/**
* print_d - Print a decimal (integer) number (base 10) to a file descriptor.
* @input: The integer to print.
* @fd: The file descriptor to write to.
*
* Return: The number of characters printed.
*/
int print_d(int input, int fd)
{
char buf[12]; /* Longest decimal representation of an int is 11 digits */
int i = 0;

if (input == 0)
_putfd('0', fd);

else
{
if (input < 0)
{
_putfd('-', fd);
input = -input;
}

while (input != 0)
{
buf[i++] = (input % 10) + '0';
input /= 10;
}

for (i = i - 1; i >= 0; i--)
_putfd(buf[i], fd);
}

return (i);
}

/**
* convert_number - Convert a number to a string in the specified base.
* @num: The number to convert.
* @base: The base of the number.
* @flags: Argument flags (CONVERT_SIGNED or CONVERT_UNSIGNED).
*
* Return: A pointer to the converted string.
*/
char *convert_number(long int num, int base, int flags)
{
static char buffer[12]; /* Longest decimal representation of an int is 11 digits */
char *ptr = buffer;

if (flags == CONVERT_SIGNED && (base == 10) && (num < 0))
{
num = -num;
*ptr++ = '-';
}

/* Handle 0 explicitly, otherwise empty string is printed */
if (num == 0)
{
*ptr++ = '0';
*ptr = '\0';
return buffer;
}

/* Convert number to the specified base */
while (num != 0)
{
int remainder = num % base;
*ptr++ = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
num /= base;
}

*ptr = '\0';
/* Reverse the string to get the correct representation */
_strrev(buffer);
return buffer;
}

/**
* remove_comments - Replace the first instance of '#' with '\0'.
* @buf: Address of the string to modify.
*
* Return: Always returns 0.
*/
void remove_comments(char *buf)
{
char *ptr = _strchr(buf, '#');
if (ptr != NULL)
*ptr = '\0';
}
