#include "shell.h"

/**
* list_len - Determines the length of a linked list.
* @h: Pointer to the first node of the list.
*
* Return: Size of the list as a size_t data type.
*/
size_t list_len(const list_t *h)
{
size_t len = 0;
while (h)
{
len++;
h = h->next;
}
return (len);
}

/**
* list_to_strings - Converts a linked list into an array of strings.
* @head: Pointer to the first node of the list.
*
* Return: Array of strings corresponding to the str member of each node.
*/
char **list_to_strings(const list_t *head)
{
size_t len = list_len(head);
char **str_array;
size_t i = 0;

str_array = malloc((len + 1) * sizeof(char *)); // Allocate memory for the array of strings

if (!str_array)
return (NULL);

while (head)
{
str_array[i] = _strdup(head->str); // Copy each string to the array
head = head->next;
i++;
}

str_array[i] = NULL; // Null-terminate the array
return (str_array);
}

/**
* print_list - Prints the contents of a linked list.
* @h: Pointer to the first node of the list.
*
* Return: Size of the list as a size_t data type.
*/
size_t print_list(const list_t *h)
{
size_t len = 0;
while (h)
{
if (h->str)
_puts(h->str);
else
_puts("(nil)");

_puts(": ");
_putnum(h->num);
_puts("\n");

h = h->next;
len++;
}
return (len);
}

/**
* node_starts_with - Finds a node whose string starts with a given prefix.
* @node: Pointer to the first node of the list.
* @prefix: Prefix to match.
* @c: Character to match after the prefix (optional).
*
* Return: Pointer to the matched node or NULL if no match found.
*/
list_t *node_starts_with(list_t *node, const char *prefix, char c)
{
while (node)
{
if (starts_with(node->str, prefix))
{
if (c == '\0' || node->str[_strlen(prefix)] == c)
return (node);
}
node = node->next;
}
return (NULL);
}

/**
* get_node_index - Finds the index of a node in the linked list.
* @head: Pointer to the first node of the list.
* @node: Pointer to the node whose index is to be found.
*
* Return: Index of the node or -1 if not found.
*/
int get_node_index(const list_t *head, const list_t *node)
{
int index = 0;
while (head)
{
if (head == node)
return (index);
head = head->next;
index++;
}
return (-1);
}
