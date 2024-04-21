#include "shell.h"
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

/**
 * get_path - handle the path
 * @line: a string of command
 * Return: the handle the path
 */

char *path(char *line)
{
	char *path;
	int length_line;
	char *token, *tmp, *file;
	struct stat st;

	if (line == NULL)
		exit(EXIT_FAILURE);
	length_line = strlen(line);
	if (strstr(line, "/") == NULL)
	{
		path = getenv("PATH");
		tmp = malloc(strlen(path) + 1);
		if (tmp == NULL)
			perror("malloc"), exit(EXIT_FAILURE);
		strcpy(tmp, path);
		token = strtok(tmp, ":");
		while (token)
		{
			file = malloc(length_line + strlen(token) + 2);
			if (file == NULL)
			{
				free(tmp), free(file);
				perror("malloc"), exit(EXIT_FAILURE);
			}
			sprintf(file, "%s/%s", token, line);
			if (stat(file, &st) == 0)
			{
				free(tmp);
				return (file);
			}
			free(file);
			token = strtok(NULL, ":");
		}
		free(tmp);
		return (NULL);
	}
	return (line);
}
