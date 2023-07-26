#include "shell.h"

/**
* _memset - Fills a block of memory with a given value.
* @s: Pointer to the memory block.
* @b: Byte value to fill the memory with.
* @n: Number of bytes to be filled.
*
* Return: Pointer to the memory block.
*/
void *_memset(void *s, int b, size_t n)
{
unsigned char *ptr = s;
size_t i;

for (i = 0; i < n; i++)
ptr[i] = (unsigned char)b;

return s;
}

/**
* ffree - Frees a string of strings.
* @str: Pointer to the string of strings.
*/
void ffree(char **str)
{
size_t i;

if (!str)
return;

for (i = 0; str[i]; i++)
{
free(str[i]);
str[i] = NULL;
}

free(str);
}

/**
* _realloc - Reallocates a block of memory.
* @ptr: Pointer to the previous block of memory.
* @old_size: Size of the previous block of memory.
* @new_size: Size of the new block of memory.
*
* Return: Pointer to the new block of memory.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *new_ptr;

if (ptr == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(ptr);
return (NULL);
}

if (new_size == old_size)
return (ptr);

new_ptr = malloc(new_size);

if (new_ptr == NULL)
return (NULL);

if (old_size < new_size)
_memset(new_ptr + old_size, 0, new_size - old_size);

_memcpy(new_ptr, ptr, old_size);
free(ptr);

return (new_ptr);
}
