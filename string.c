#include "shell.h"

/**
* _strlen - Returns the length of a string.
* @s: The input string.
*
* Return: The length of the string.
*/
size_t _strlen(const char *s)
{
size_t len = 0;

if (!s)
return (0);

while (s[len] != '\0')
len++;

return (len);
}

/**
* _strcmp - Compares two strings.
* @s1: The first input string.
* @s2: The second input string.
*
* Return: 0 if the strings are equal, otherwise the difference between
* the ASCII values of the first differing characters.
*/
int _strcmp(const char *s1, const char *s2)
{
int i;

if (!s1 || !s2)
return (-1);

for (i = 0; s1[i] && s2[i]; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}

return (s1[i] - s2[i]);
}

/**
* starts_with - Checks if a string starts with a given prefix.
* @str: The input string.
* @prefix: The prefix to check for.
*
* Return: If the string starts with the prefix, return a pointer to the
* character immediately following the prefix. Otherwise, return NULL.
*/
char *starts_with(const char *str, const char *prefix)
{
size_t i;

if (!str || !prefix)
return (NULL);

for (i = 0; prefix[i]; i++)
{
if (str[i] != prefix[i])
return (NULL);
}

return ((char *)(str + i));
}

/**
* _strcat - Concatenates two strings.
* @dest: The destination buffer.
* @src: The source buffer.
*
* Return: A pointer to the beginning of the destination string.
*/
char *_strcat(char *dest, const char *src)
{
size_t dest_len = _strlen(dest);
size_t i;

if (!dest || !src)
return (NULL);

for (i = 0; src[i]; i++)
dest[dest_len + i] = src[i];

dest[dest_len + i] = '\0';

return (dest);
}
