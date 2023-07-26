#include "shell.h"

/* Buffer chained commands entered by the user */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t bytes_read;
*len = 0;
*buf = NULL;

do
{
char *line = NULL;
size_t n = 0;

bytes_read = getline(&line, &n, stdin);

if (bytes_read > 0)
{
if (*buf == NULL)
{
*buf = malloc(bytes_read);
if (*buf == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
}
else
{
*buf = realloc(*buf, *len + bytes_read);
if (*buf == NULL)
{
perror("Memory reallocation error");
exit(EXIT_FAILURE);
}
}

memcpy(*buf + *len, line, bytes_read);
*len += bytes_read;
free(line);
}
} while (bytes_read > 0 && (*buf)[*len - 1] != '\n');

return bytes_read;
}

/* Get a line of input from the user */
ssize_t get_input(info_t *info)
{
ssize_t bytes_read;
char *line = NULL;
size_t n = 0;

bytes_read = getline(&line, &n, stdin);

if (bytes_read > 0)
{
if (line[bytes_read - 1] == '\n')
line[bytes_read - 1] = '\0'; // Remove the newline character
info->input = line;
}

return bytes_read;
}

/* Read buffer */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t bytes_read;

bytes_read = read(STDIN_FILENO, buf, READ_BUF_SIZE);

if (bytes_read > 0)
{
buf[bytes_read] = '\0';
*i = 0;
}

return bytes_read;
}

/* Get the next line of input from STDIN */
ssize_t _getline(info_t *info, char **ptr, size_t *length)
{
ssize_t bytes_read;
char *line = NULL;
size_t n = 0;

bytes_read = getline(&line, &n, stdin);

if (bytes_read > 0)
{
if (line[bytes_read - 1] == '\n')
line[bytes_read - 1] = '\0'; // Remove the newline character
*ptr = line;
*length = bytes_read;
}

return bytes_read;
}

/* Signal handler for Ctrl-C */
void sigintHandler(int sig_num)
{
// Block the SIGINT signal to prevent accidental termination
signal(SIGINT, sigintHandler);
_putchar('\n'); // Print a newline to prevent the shell prompt from getting mixed up
_putfd(STDOUT_FILENO, info->prompt);
fflush(stdout);
}
