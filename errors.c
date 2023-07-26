#include "shell.h"

/**
* _eputs - Print a string to standard error.
* @str: The string to print.
*
* Return: Always returns 1.
*/
int _eputs(const char *str)
{
while (*str)
_eputchar(*str++);
return (1);
}

/**
* _eputchar - Write a character to standard error.
* @c: The character to write.
*
* Return: 1 on success, or -1 on error.
*/
int _eputchar(char c)
{
static char buf[WRITE_BUF_SIZE];
static int i;

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(STDERR_FILENO, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

/**
* _putfd - Write a character to a specified file descriptor.
* @c: The character to write.
* @fd: The file descriptor to write to.
*
* Return: 1 on success, or -1 on error.
*/
int _putfd(char c, int fd)
{
static char buf[WRITE_BUF_SIZE];
static int i;

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
}

/**
* _putsfd - Print a string to a specified file descriptor.
* @str: The string to print.
* @fd: The file descriptor to write to.
*
* Return: The number of characters written to the file descriptor.
*/
ssize_t _putsfd(const char *str, int fd)
{
ssize_t chars_written = 0;

while (*str)
{
if (_putfd(*str, fd) == -1)
return (-1);
chars_written++;
str++;
}

return (chars_written);
}
