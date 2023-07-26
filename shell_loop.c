#include "shell.h"

/**
* hsh - Main function that runs the shell loop.
* @info: Pointer to the info_t struct holding shell state.
* @av: Array of strings holding command line arguments.
*
* Return: Result of the last command executed.
*/
int hsh(info_t *info, char **av)
{
int status;
char *input;

info->history = NULL;
info->histcount = 0;

while (1)
{
input = get_input(info);

if (!input)
{
if (isatty(STDIN_FILENO))
_puts("\n");
break;
}

if (*input)
{
add_history(info, input);
status = find_builtin(info);
if (status == -1)
find_cmd(info);
}

free(input);

if (info->exit)
break;
}

write_history(info);
free_info(info);
return (status);
}

/**
* find_builtin - Searches for a built-in command.
* @info: Pointer to the info_t struct holding command and arguments.
*
* Return: Return value of the built-in command, or -1 if not found.
*/
int find_builtin(info_t *info)
{
int i;

if (!info->argv || !info->argv[0])
return (-1);

for (i = 0; builtintbl[i].cmd; i++)
{
if (_strcmp(info->argv[0], builtintbl[i].cmd) == 0)
return (builtintbl[i].f(info));
}

return (-1);
}

/**
* find_cmd - Searches for a command in the PATH directories.
* @info: Pointer to the info_t struct holding command and arguments.
*/
void find_cmd(info_t *info)
{
char *path = _getenv(info, "PATH=");
char *cmd_path;

if (!info->argv[0] || !path)
{
_puts_fd(info->argv[0]);
_puts_fd(": not found\n");
info->status = 127;
return;
}

if (is_cmd(info, info->argv[0]))
cmd_path = find_path(info, path, info->argv[0]);
else
cmd_path = NULL;

free(path);

if (cmd_path)
{
info->path = cmd_path;
fork_cmd(info);
}
else
{
_puts_fd(info->argv[0]);
_puts_fd(": not found\n");
info->status = 127;
}
}

/**
* fork_cmd - Forks a child process to execute the command.
* @info: Pointer to the info_t struct holding command and arguments.
*/
void fork_cmd(info_t *info)
{
pid_t pid;
int status;

pid = fork();
if (pid == -1)
{
perror("fork");
return;
}

if (pid == 0)
{
execve(info->path, info->argv, info->env);
perror("execve");
exit(1);
}
else
{
wait(&status);
info->status = WEXITSTATUS(status);
}
}
