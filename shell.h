#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
char *read_line(void);
int is_built_in(char **command);
void handle_built_in(char **command, int *status);
void hsh_exit(char **cmd, int *status);
char *_path(char *command);
char *get_env(char *var);
char *my_strdup(const char *s);
char **_str(char *line);
void free_array(char **command);
int exec(char **arr, char **av, int command_number);
int main(__attribute__((unused)) int ac, char **av);
void hsh_env(char **cmd, int *status);

#endif
