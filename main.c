#include <stdio.h>
#include <string.h>
#include "environment.h"
#include "builtin_commands.h"
#include "checkbuild.h"
#include "external_commands.h"

#define BUFFER_SIZE 1024

/* Exécute la commande appropriée en fonction de l'entrée de l'utilisateur */
void execute_command(char **args) {
    if (args[0] == NULL) {
        return; /* La commande est vide */
    }
    if (checkbuild(args[0])) {
        /* La commande est une commande intégrée */
        if (strcmp(args[0], "exit") == 0) {
            exit_shell(args[1]); /* Gestion de la commande exit */
        } else if (strcmp(args[0], "env") == 0) {
            show_environment(); /* Gestion de la commande env */
        } else if (strcmp(args[0], "setenv") == 0) {
            set_environment_variable(args[1], args[2]); /* Gestion de la commande setenv */
        } else if (strcmp(args[0], "unsetenv") == 0) {
            unset_environment_variable(args[1]); /* Gestion de la commande unsetenv */
        }
    } else {
        /* La commande est une commande externe */
        execute_external_command(args[0], args); /* Exécution de la commande externe */
    }
}

int main() {
    char input[BUFFER_SIZE];
    char *args[BUFFER_SIZE / 2 + 1]; /* Tableau pour stocker les mots de l'entrée utilisateur */

    /* Boucle principale du shell */
    while (1) {
        printf("#cisfun$ ");
        fflush(stdout); /* Pour vider le tampon de sortie */

        /* Lire l'entrée utilisateur */
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            break; /* EOF (End Of File) détecté */
        }

        /* Division de l'entrée utilisateur en mots individuels */
        char *token;
        int i = 0;
        token = strtok(input, " \n");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \n");
        }
        args[i] = NULL; /* Ajoutez NULL à la fin pour indiquer la fin des arguments */

        /* Exécution de la commande */
        execute_command(args);
    }

    printf("\n"); /* Saut de ligne pour une meilleure apparence */
    return 0;
}
