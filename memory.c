#include "shell.h"

/**
* bfree - Safely frees dynamically allocated memory
* @ptr: Pointer to a pointer to the memory to be freed
*
* This function frees the memory pointed to by the pointer @ptr and sets
* the pointer @ptr to NULL to avoid dangling pointers.
*
* Return: 1 on success (memory was freed), 0 on failure (ptr is NULL or *ptr is NULL)
*/
void bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
