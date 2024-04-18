#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * _env - searches for the environment string pointed
 * @name: containing the name of the requested variable
 * Return: the associated value to the string
 */
char *_env(const char *name)
{
	char *value;

	if (name == NULL)
		return (NULL);

	value = getenv(name);

	if (value != NULL && value[0] != '\0')
		return (value);

	return (NULL);
}
