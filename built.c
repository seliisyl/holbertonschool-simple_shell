#include "shell.h"
/**
 * built_in - Checks command is a built-in shell command.
 *
 * @command: Array of strings representing the command and its arguments.
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int built_in(char **command)

{
	char *built[] = {"exit", "env", "cd", "help", NULL};
	int i;

	for (i = 0; built[i]; i++)
	{
		if (strcmp(command[0], built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);

}
/**
 * handle_built - Handles the execution of built-in shell commands.
 *
 * @command: Array of strings representing the command and its arguments.
 * @status: Pointer to the status variable of the shell.
 */
void handle_built(char **command, int *status)

{
	if (strcmp(command[0], "exit") == 0)
	{
		hsh_exit(command, status);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		hsh_env(command, status);
	}
}
/**
 * _exit - Handles the "exit" built-in command.
 *
 * @cmd: Array of strings representing the command and its arguments.
 * @status: Pointer to the status variable of the shell.
 */
void _exit(char **cmd, int *status)

{
	free_array(cmd);
	exit(*status);
}
/**
 *_env - Handles the "env" built-in command.
 *
 * @cmd: Array of strings representing the command and its arguments.
 * @status: Pointer to the status variable of the shell.
 */
void _env(char **cmd, int *status)

{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	free_array(cmd);
	(*status) = 0;
}
