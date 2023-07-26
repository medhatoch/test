#include "shell.h"

/**
* _myhistory - Display the history list.
* @info: Pointer to the info_t structure.
*
* Return: Always returns 0.
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
* unset_alias - Unset an alias.
* @info: Pointer to the info_t structure.
* @str: The alias string.
*
* Return: 1 if the character '=' is not found in str, 0 otherwise.
*/
int unset_alias(info_t *info, char *str)
{
char *p = _strchr(str, '=');

if (!p)
return (1);

*p = '\0';
delete_node_at_index(&info->alias, get_node_index(info->alias, str));
*p = '=';
return (0);
}

/**
* set_alias - Set an alias.
* @info: Pointer to the info_t structure.
* @str: The alias string.
*
* Return: 0 on success, 1 on failure.
*/
int set_alias(info_t *info, char *str)
{
char *p = _strchr(str, '=');

if (!p)
return (1);

if (*(p + 1) == '\0')
{
unset_alias(info, str);
return (0);
}

add_node_end(&info->alias, str);
return (0);
}

/**
* print_alias - Print an alias.
* @node: Pointer to the node in the alias list.
*
* Return: Always returns 0.
*/
int print_alias(list_t *node)
{
if (node)
{
char *p = _strchr(node->str, '=');

while (*node->str != '=')
{
_putchar(*node->str);
node->str++;
}
_putchar(*node->str++);
_puts(p + 1);
_putchar('\n');
}
return (0);
}

/**
* _myalias - Create and manipulate aliases in the shell.
* @info: Pointer to the info_t structure.
*
* Return: Always returns 0.
*/
int _myalias(info_t *info)
{
int i = 0;
char *p = NULL;
list_t *node = NULL;

if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}

for (i = 1; info->argv[i]; i++)
{
p = _strchr(info->argv[i], '=');
if (p)
set_alias(info, info->argv[i]);
else
print_alias(node_starts_with(info->alias, info->argv[i], '='));
}

return (0);
}
