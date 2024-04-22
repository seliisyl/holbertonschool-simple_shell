#include <stdio.h>
#include <unistd.h>

/* Exécute une commande externe en utilisant execve() */
void execute_external_command(char *path, char **args)
{
    if (execve(path, args, NULL) == -1)
{
        perror("Erreur lors de l'exécution de la commande");
    }
    exit(EXIT_FAILURE);
}
