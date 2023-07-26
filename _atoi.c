#include "shell.h"

/**
 * interactive - Check if the shell is running in interactive mode.
 * @info: Pointer to the info_t structure.
 *
 * Return: 1 if the shell is running in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Check if a character is a delimiter.
 * @c: The character to check.
 * @delim: The delimiter string to compare against.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - Check if a character is an alphabetic character.
 * @c: The character to check.
 *
 * Return: 1 if the character is an alphabetic character, 0 otherwise.
 */
int _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The input string to convert.
 *
 * Return: The converted integer value.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	while (*s)
	{
		if (_isalpha(*s))
			break;

		if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
		}
		else
		{
			break;
		}
		s++;
	}

	return (result * sign);
}
