#include "shell.h"

/**
 * _myexit - Exit the shell.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always returns -2 to signal the shell to exit.
 */
int _myexit(info_t *info)
{
	if (info->argv[1])
	{
		int err_num = _erratoi(info->argv[1]);
		if (err_num == -1)
		{
			info->status = 2;
			dprintf(STDERR_FILENO, "Error: Numeric argument required\n");
			return (1);
		}
		info->err_num = err_num;
		return (-2);
	}

	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - Change the current directory.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always returns 0.
 */
int _mycd(info_t *info)
{
	char buffer[1024];
	char *dir = NULL;
	int chdir_ret;

	if (!info->argv[1])
		dir = _getenv(info, "HOME=");
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD=");
		if (!dir)
			dir = _getenv(info, "PWD=");
		if (!dir)
			dir = getcwd(buffer, sizeof(buffer));
	}
	else
		dir = info->argv[1];

	if (!dir)
	{
		dprintf(STDERR_FILENO, "Error: TODO message\n");
		return (0);
	}

	chdir_ret = chdir(dir);
	if (chdir_ret == -1)
	{
		perror("chdir");
		return (0);
	}

	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, sizeof(buffer)));

	return (0);
}

/**
 * _myhelp - Display a help message.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always returns 0.
 */
int _myhelp(info_t *info)
{
	(void)info;
	char **arg_array = info->argv;

	/* TODO: Implement the help message */
	printf("Help message: Not yet implemented\n");
	return (0);
}
