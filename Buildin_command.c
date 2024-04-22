#include <stdio.h>
#include <stdlib.h>
#include "environment.h"

/* Fonction pour quitter le shell */
void exit_shell(char *arg)
{
    int exit_code = arg ? atoi(arg) : 0;
    exit(exit_code);
}
