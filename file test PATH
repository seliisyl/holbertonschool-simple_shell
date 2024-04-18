#include <unistd.h> 

char *_which(char *filename, list_path *head)
{
    char *path;
    struct stat st;

    list_path *tmp = head;

    while (tmp)
    {
        /* Construire le chemin absolu */
        path = concat_all(tmp->dir, "/", filename);
        
/* Vérifier si le fichier existe */
        if (access(path, X_OK) == 0 && stat(path, &st) == 0 && S_ISREG(st.st_mode))
        {
            /* Le fichier existe et est exécutable */
            return (path);
        }
        free(path); /* Libérer la mémoire du chemin */
        tmp = tmp->p; /* Passer au répertoire suivant */
    }
/* Aucun chemin d'accès valide trouvé */
    return (NULL);
}
