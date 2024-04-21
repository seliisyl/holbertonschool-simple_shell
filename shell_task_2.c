#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 1024

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char prompt[] = "# ";

    while (1)
{
        printf("%s", prompt);

/* Lire la commande de l'utilisateur */
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
            /* Gérer la fin de fichier (EOF) */
            printf("\n");
            break;
        }
/* Supple le saut a la ligne à la fin de la command */
        command[strcspn(command, "\n")] = '\0';

        /* Créer un processus fils pour exécuter la commande */
        pid_t pid = fork();

        if (pid == -1)
{
            /* Gérer l'erreur de fork */
            perror("fork");
        } else if (pid == 0)
{
            /* processus fils */
            /* Exécuter la commande avec execve */
            if (execve(command, NULL, NULL) == -1)
{
                /* Si execve échoue, afficher un message d'erreur */
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
else
{
            /* processus parent */
            /* Att la fin du processus fils */
            wait(NULL);
        }
    }

    return 0;
}
