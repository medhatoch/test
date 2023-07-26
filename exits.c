#include "shell.h"

/**
* _strncpy - Copy a string from src to dest, up to n characters.
* @dest: Destination buffer.
* @src: Source string.
* @n: Maximum number of characters to copy.
*
* Return: A pointer to the destination buffer.
*/
char *_strncpy(char *dest, const char *src, size_t n)
{
size_t i = 0;
char *s = dest;

while (i < n && src[i] != '\0')
{
dest[i] = src[i];
i++;
}

while (i < n)
{
dest[i] = '\0';
i++;
}

return s;
}

/**
* _strncat - Concatenate two strings, appending at most n characters from src to dest.
* @dest: Destination buffer.
* @src: Source string.
* @n: Maximum number of characters to append.
*
* Return: A pointer to the destination buffer.
*/
char *_strncat(char *dest, const char *src, size_t n)
{
size_t i = 0, j = 0;
char *s = dest;

while (dest[i] != '\0')
i++;

while (j < n && src[j] != '\0')
{
dest[i] = src[j];
i++;
j++;
}

if (j < n)
dest[i] = '\0';

return s;
}

/**
* _strchr - Locate a character in a string.
* @s: The string to be parsed.
* @c: The character to look for.
*
* Return: A pointer to the first occurrence of c in s,
*         or NULL if the character is not found.
*/
char *_strchr(const char *s, int c)
{
do {
if (*s == c)
return (char *)s;
} while (*s++);

return NULL;
}
