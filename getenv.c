#include "shell.h"

/**
 * get_environ - Returns a string array copy of the environment variables
 * @info: Pointer to the info struct
 * Return: Pointer to the string array containing environment variables
 */
char **get_environ(info_t *info)
{
    if (info->environ == NULL)
    {
        int env_count = 0;
        list_t *env_node = info->env;

        while (env_node)
        {
            env_count++;
            env_node = env_node->next;
        }

        char **environ_copy = malloc((env_count + 1) * sizeof(char *));
        if (environ_copy == NULL)
            return (NULL);

        int i = 0;
        env_node = info->env;
        while (env_node)
        {
            environ_copy[i] = env_node->str;
            env_node = env_node->next;
            i++;
        }
        environ_copy[i] = NULL;
        info->environ = environ_copy;
    }

    return (info->environ);
}

/**
 * _unsetenv - Removes an environment variable from the linked list
 * @info: Pointer to the info struct
 * @var: Name of the environment variable to remove
 * Return: 1 if the linked list was changed, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
    int env_changed = 0;
    list_t *current = info->env;
    list_t *prev = NULL;

    while (current)
    {
        if (_strcmp(current->str, var) == 0)
        {
            if (prev == NULL)
                info->env = current->next;
            else
                prev->next = current->next;

            free(current->str);
            free(current);
            env_changed = 1;
            break;
        }

        prev = current;
        current = current->next;
    }

    return (env_changed);
}

/**
 * _setenv - Sets an environment variable in the linked list
 * @info: Pointer to the info struct
 * @var: Name of the environment variable
 * @value: Value of the environment variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(info_t *info, char *var, char *value)
{
    char *buf = NULL;
    int ret = -1;
    list_t *current = info->env;

    while (current)
    {
        if (_strcmp(current->str, var) == 0)
        {
            free(current->str);
            buf = malloc((_strlen(var) + _strlen(value) + 2) * sizeof(char));
            if (buf == NULL)
                return (-1);

            _strcpy(buf, var);
            _strcat(buf, "=");
            _strcat(buf, value);
            current->str = buf;
            ret = 0;
            break;
        }

        current = current->next;
    }

    if (ret == -1)
    {
        buf = malloc((_strlen(var) + _strlen(value) + 2) * sizeof(char));
        if (buf == NULL)
            return (-1);

        _strcpy(buf, var);
        _strcat(buf, "=");
        _strcat(buf, value);
        if (add_node_end(&info->env, buf) == NULL)
            ret = -1;
        else
            ret = 0;
    }

    return (ret);
}
