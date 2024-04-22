#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fonction pour afficher l'environnement */
void show_environment()
{
    system("env");
}

/* Fonction pour définir une variable d'environnement */
void set_environment_variable(char *name, char *value) {
    if (name == NULL || value == NULL)
    {
        fprintf(stderr, "Usage: setenv <variable> <valeur>\n");
        return;
    }
    setenv(name, value, 1);
}

/* Fonction pour supprimer une variable d'environnement */
void unset_environment_variable(char *name)
{
    if (name == NULL)
    {
        fprintf(stderr, "Usage: unsetenv <variable>\n");
        return;
    }
    unsetenv(name);
}
