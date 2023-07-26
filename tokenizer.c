#include "shell.h"

/**
* strtow - Splits a string into words based on a delimiter string.
* @str: The input string to split.
* @d: The delimiter string.
*
* Return: A pointer to an array of strings containing the words, or NULL on failure.
*/
char **strtow(char *str, char *d)
{
int i, j, k, words;
char **arr;

if (str == NULL || *str == '\0')
return (NULL);

if (d == NULL)
d = " ";

words = count_words(str, d);
if (words == 0)
return (NULL);

arr = malloc(sizeof(char *) * (words + 1));
if (arr == NULL)
return (NULL);

for (i = 0; i < words; i++)
{
while (*str && is_delim(*str, d))
str++;
k = word_len(str, d);
arr[i] = malloc(sizeof(char) * (k + 1));
if (arr[i] == NULL)
{
for (j = 0; j < i; j++)
free(arr[j]);
free(arr);
return (NULL);
}
for (j = 0; j < k; j++)
arr[i][j] = *str++;
arr[i][j] = '\0';
}

arr[i] = NULL;
return (arr);
}

/**
* strtow2 - Splits a string into words based on a delimiter character.
* @str: The input string to split.
* @d: The delimiter character.
*
* Return: A pointer to an array of strings containing the words, or NULL on failure.
*/
char **strtow2(char *str, char d)
{
int i, j, k, words;
char **arr;

if (str == NULL || *str == '\0')
return (NULL);

words = count_words2(str, d);
if (words == 0)
return (NULL);

arr = malloc(sizeof(char *) * (words + 1));
if (arr == NULL)
return (NULL);

for (i = 0; i < words; i++)
{
while (*str && *str == d)
str++;
k = word_len2(str, d);
arr[i] = malloc(sizeof(char) * (k + 1));
if (arr[i] == NULL)
{
for (j = 0; j < i; j++)
free(arr[j]);
free(arr);
return (NULL);
}
for (j = 0; j < k; j++)
arr[i][j] = *str++;
arr[i][j] = '\0';
}

arr[i] = NULL;
return (arr);
}
