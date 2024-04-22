#ifndef __SHELL_H__
#define __SHELL_H__

#include <stddef.h>

char *_which(char *filename, list_path *head);
void exitt(char **arv);
int main();
char *copy_string(const char *src);
char **add_word_to_array(char **array, const char *word, int index);
char **splitstring(char *str, const char *delim);
char **process_tokens(char **array, const char *delim);
char *_env(const char *name);
void show_environment();
void set_environment_variable(char *name, char *value);
void unset_environment_variable(char *name);
void exit_shell(char *arg);
int checkbuild(char *command);
void execute_external_command(char *path, char **args);


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "environment.h"
#include "builtin_commands.h"
#include "checkbuild.h"
#include "external_commands.h"

#endif
