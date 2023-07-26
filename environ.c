#include "shell.h"

/**
* _myenv - Print the current environment.
* @info: Pointer to the info_t structure.
*
* Return: Always returns 0.
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv - Get the value of a specified environment variable.
* @info: Pointer to the info_t structure.
* @name: The name of the environment variable.
*
* Return: The value of the specified environment variable, or NULL if not found.
*/
char *_getenv(info_t *info, const char *name)
{
size_t len = _strlen(name);
list_t *node = info->env;

while (node)
{
if (_strncmp(node->str, name, len) == 0)
return (node->str + len);
node = node->next;
}

return (NULL);
}

/**
* _mysetenv - Set a new environment variable or modify an existing one.
* @info: Pointer to the info_t structure.
*
* Return: Always returns 0.
*/
int _mysetenv(info_t *info)
{
if (info->argc < 3)
{
dprintf(STDERR_FILENO, "Usage: %s NAME VALUE\n", info->argv[0]);
return (0);
}

_setenv(info, info->argv[1], info->argv[2]);
return (0);
}

/**
* _myunsetenv - Remove an environment variable.
* @info: Pointer to the info_t structure.
*
* Return: Always returns 0.
*/
int _myunsetenv(info_t *info)
{
int i;

if (info->argc < 2)
{
dprintf(STDERR_FILENO, "Usage: %s NAME [NAME ...]\n", info->argv[0]);
return (0);
}

for (i = 1; i < info->argc; i++)
_unsetenv(info, info->argv[i]);

return (0);
}

/**
* populate_env_list - Initialize the env linked list with the values from environ.
* @info: Pointer to the info_t structure.
*
* Return: Always returns 0.
*/
int populate_env_list(info_t *info)
{
int i;

for (i = 0; environ[i]; i++)
add_node_end(&info->env, environ[i]);

return (0);
}
