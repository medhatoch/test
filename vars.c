#include "shell.h"

/**
* is_chain - Tests if the current character is a chain delimiter.
* @info: Pointer to a struct containing information about the current command.
* @buf: Character buffer containing the current command.
* @p: Pointer to the current position in buf.
*
* Return: 1 if a chain delimiter is found, 0 otherwise.
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
if (*p >= info->len)
return (0);

if (buf[*p] == '|' || buf[*p] == '&')
{
(*p)++;
while (*p < info->len && buf[*p] == ' ')
(*p)++;
return (1);
}
return (0);
}

/**
* check_chain - Checks if we should continue chaining based on the last status.
* @info: Pointer to a struct containing information about the current command.
* @buf: Character buffer containing the current command.
* @p: Pointer to the current position in buf.
* @i: The starting position in buf.
* @len: The length of buf.
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
if (*p < len && (buf[*p] == '|' || buf[*p] == '&'))
{
info->chain = buf[*p];
(*p)++;
while (*p < len && buf[*p] == ' ')
(*p)++;
if (*p >= len)
{
info->exit_code = 2;
(*p) = i;
}
}
else
{
info->chain = 0;
}
}

/**
* replace_alias - Replaces aliases in the tokenized string.
* @info: Pointer to a struct containing information about the current command.
*
* Return: 1 if a replacement is made, 0 otherwise.
*/
int replace_alias(info_t *info)
{
size_t i;
char *alias_val;

if (info->alias == NULL)
return (0);

for (i = 0; info->tok[i]; i++)
{
alias_val = get_alias(info->alias, info->tok[i]);
if (alias_val != NULL)
{
free(info->tok[i]);
info->tok[i] = _strdup(alias_val);
free(alias_val);
return (1);
}
}
return (0);
}

/**
* replace_vars - Replaces variables in the tokenized string.
* @info: Pointer to a struct containing information about the current command.
*
* Return: 1 if a replacement is made, 0 otherwise.
*/
int replace_vars(info_t *info)
{
size_t i;

for (i = 0; info->tok[i]; i++)
{
if (*(info->tok[i]) == '$')
{
if (replace_var(info, info->tok[i]) == 1)
return (1);
}
}
return (0);
}

/**
* replace_string - Replaces a string.
* @old: Pointer to the old string.
* @new: The new string.
*
* Return: 1 if a replacement is made, 0 otherwise.
*/
int replace_string(char **old, char *new)
{
if (*old != NULL)
free(*old);

*old = new;

if (*old == NULL)
return (0);

return (1);
}
