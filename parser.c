#include "shell.h"

/**
* is_cmd - Checks if a path corresponds to an executable command.
* @info: Pointer to the info_t struct.
* @path: Path to check.
*
* Return: 1 if path is an executable command, 0 otherwise.
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;

if (!path || stat(path, &st) == -1)
return (0);

return (S_ISREG(st.st_mode));
}

/**
* dup_chars - Duplicate characters from a string.
* @pathstr: String to duplicate characters from.
* @start: Starting index to duplicate from.
* @stop: Ending index to duplicate up to (exclusive).
*
* Return: Duplicated characters in a new string.
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[4096];
int i, j = 0;

if (start < 0 || stop <= start || stop > (int)_strlen(pathstr))
return (NULL);

for (i = start; i < stop; i++)
{
buf[j] = pathstr[i];
j++;
}
buf[j] = '\0';

return (buf);
}

/**
* find_path - Find the full path of a command using the PATH environment variable.
* @info: Pointer to the info_t struct.
* @pathstr: PATH environment variable.
* @cmd: Command to search for.
*
* Return: Full path to the command if found, otherwise NULL.
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
char *path_entry, *full_path;
int i = 0;

if (!pathstr || !cmd)
return (NULL);

while (pathstr[i])
{
if (pathstr[i] == ':')
{
path_entry = dup_chars(pathstr, 0, i);
full_path = _strcat(path_entry, "/");
full_path = _strcat(full_path, cmd);

if (is_cmd(info, full_path))
return (full_path);

free(path_entry);
free(full_path);
}
i++;
}

full_path = _strcat(pathstr, "/");
full_path = _strcat(full_path, cmd);

if (is_cmd(info, full_path))
return (full_path);

return (NULL);
}
