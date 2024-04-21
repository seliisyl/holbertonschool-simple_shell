/**
 * copy_string - Copie une chaîne de caractères dans une nouvelle mémoire allouée.
 * @src: la chaîne source à copier
 * Return: un pointeur vers la nouvelle chaîne de caractères, ou NULL en cas d'échec
 */
char *copy_string(const char *src)
{
    char *dest = malloc(_strlen(src) + 1);
    if (dest == NULL)
    {
        perror(_getenv("_"));
        return NULL;
    }
    _strcpy(dest, src);
    return dest;
}

/**
 * add_word_to_array - Ajoute un mot à un tableau de pointeurs de mots.
 * @array: le tableau de pointeurs de mots
 * @word: le mot à ajouter
 * @index: l'indice où ajouter le mot dans le tableau
 * Return: le tableau mis à jour, ou NULL en cas d'échec
 */
char **add_word_to_array(char **array, const char *word, int index)
{
    char **temp = malloc(sizeof(char *) * (index + 1));
    if (temp == NULL)
    {
        perror(_getenv("_"));
        return NULL;
    }
    for (int i = 0; i < index; i++)
    {
        temp[i] = array[i];
    }
    temp[index] = copy_string(word);
    if (temp[index] == NULL)
    {
        freearv(temp);
        return NULL;
    }
    if (index > 0)
    {
        free(array);
    }
    return temp;
}
/**
 * splitstring - Divise une chaîne de caractères en mots en utilisant un délimiteur.
 * @str: la chaîne de caractères à diviser
 * @delim: le délimiteur utilisé pour la division
 * Return: un tableau de pointeurs de mots, ou NULL en cas d'échec
 */
char **splitstring(char *str, const char *delim)
{
    char *copy = copy_string(str);
    if (copy == NULL)
    {
        return NULL;
    }
    char **array = allocate_array();
    if (array == NULL)
    {
        free(copy);
        return NULL;
    }
    char *token = strtok(copy, delim);
    if (token == NULL)
    {
        array[0] = NULL;
        free(copy);
        return array;
    }
    array[0] = copy_string(token);
    if (array[0] == NULL)
    {
        free(copy);
        freearv(array);
        return NULL;
    }
    array = process_tokens(array, delim);
    free(copy);
    return array;
}

/**
 * process_tokens - Traitement des tokens restants après le premier token.
 * @array: le tableau de pointeurs de mots
 * @delim: le délimiteur utilisé pour la division
 * Return: le tableau mis à jour, ou NULL en cas d'échec
 */
char **process_tokens(char **array, const char *delim)
{
    int i = 1;
    char *token = strtok(NULL, delim);
    while (token)
    {
        array = add_word_to_array(array, token, i);
        if (array == NULL)
        {
            freearv(array);
            return NULL;
        }
        token = strtok(NULL, delim);
        i++;
    }
    return array;
}
