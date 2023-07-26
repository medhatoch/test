#include "shell.h"

/**
* _strcpy - Copies the string pointed to by src, including the null
*           terminator, to the buffer pointed to by dest.
* @dest: The destination buffer.
* @src: The source string.
*
* Return: A pointer to the destination buffer.
*/
char *_strcpy(char *dest, const char *src)
{
size_t i;

if (dest == src || src == NULL)
return (dest);

for (i = 0; src[i]; i++)
dest[i] = src[i];

dest[i] = '\0';

return (dest);
}

/**
* _strdup - Duplicates a string.
* @str: The input string.
*
* Return: A pointer to the duplicated string, or NULL if memory allocation fails.
*/
char *_strdup(const char *str)
{
size_t len, i;
char *dup;

if (str == NULL)
return (NULL);

len = _strlen(str);
dup = malloc(sizeof(char) * (len + 1));

if (dup == NULL)
return (NULL);

for (i = 0; i < len; i++)
dup[i] = str[i];

dup[i] = '\0';

return (dup);
}

/**
* _puts - Prints a string to the standard output.
* @str: The input string.
*/
void _puts(const char *str)
{
size_t i;

if (str == NULL)
return;

for (i = 0; str[i]; i++)
_putchar(str[i]);
}

/**
* _putchar - Writes a character to the standard output.
* @c: The character to be written.
*
* Return: 1 on success, -1 on error.
*/
int _putchar(char c)
{
static char buf[BUF_SIZE];
static int index;

if (c == BUF_FLUSH || index >= BUF_SIZE - 1)
{
write(1, buf, index);
index = 0;
}

if (c != BUF_FLUSH)
buf[index++] = c;

return (1);
}
