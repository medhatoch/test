#include "shell.h"

/**
* add_node - adds a new node to the start of the linked list
* @head: pointer to the head node of the list
* @str: string value for the new node
* @num: integer value for indexing purposes
* 
* Return: the new head of the linked list
*/
list_t *add_node(list_t **head, char *str, int num)
{
list_t *new_node;

if (!head)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

_memset(new_node, 0, sizeof(list_t));
new_node->str = _strdup(str);
new_node->num = num;
new_node->next = *head;
*head = new_node;

return (*head);
}

/**
* add_node_end - adds a new node to the end of the linked list
* @head: pointer to the head node of the list
* @str: string value for the new node
* @num: integer value for indexing purposes
* 
* Return: the new node that was added to the list
*/
list_t *add_node_end(list_t **head, char *str, int num)
{
list_t *new_node, *temp;

if (!head)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

_memset(new_node, 0, sizeof(list_t));
new_node->str = _strdup(str);
new_node->num = num;
new_node->next = NULL;

if (!*head)
{
*head = new_node;
return (new_node);
}

temp = *head;
while (temp->next)
temp = temp->next;

temp->next = new_node;

return (new_node);
}

/**
* print_list_str - prints only the string values of each node in the linked list
* @h: pointer to the head node of the list
* 
* Return: size of the list
*/
size_t print_list_str(const list_t *h)
{
size_t count = 0;

while (h)
{
if (h->str)
{
_puts(h->str);
_puts("\n");
count++;
}
h = h->next;
}

return (count);
}

/**
* delete_node_at_index - deletes a node at a given index in the linked list
* @head: pointer to the head node of the list
* @index: index of the node to be deleted
* 
* Return: 1 if the node was successfully deleted, 0 otherwise
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *current, *prev;
unsigned int i = 0;

if (!head || !*head)
return (0);

current = *head;
if (index == 0)
{
*head = current->next;
free(current->str);
free(current);
return (1);
}

while (current && i < index)
{
prev = current;
current = current->next;
i++;
}

if (!current)
return (0);

prev->next = current->next;
free(current->str);
free(current);

return (1);
}

/**
* free_list - frees all memory allocated to nodes in the linked list
* @head: pointer to the head pointer of the list
* 
* This function does not return anything.
*/
void free_list(list_t **head)
{
list_t *temp;

if (!head)
return;

while (*head)
{
temp = *head;
*head = (*head)->next;
free(temp->str);
free(temp);
}
}
