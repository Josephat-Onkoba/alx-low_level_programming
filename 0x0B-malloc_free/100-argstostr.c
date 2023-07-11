#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program
 * @ac: The number of arguments
 * @av: An array of strings containing the arguments
 *
 * Return: Pointer to a new string containing the concatenated arguments,
 *         or NULL if ac is 0, av is NULL, or if memory allocation fails.
 */
char *argstostr(int ac, char **av)
{
    if (ac == 0 || av == NULL)
        return NULL;

    int total_length = 0;
    int i, j, k;
    char *concatenated;

    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            total_length++;
            j++;
        }
        total_length++; /* Account for the newline character */
    }

    concatenated = malloc(sizeof(char) * (total_length + 1));

    if (concatenated == NULL)
        return NULL;

    k = 0;

    for (i = 0; i < ac; i++)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            concatenated[k] = av[i][j];
            j++;
            k++;
        }
        concatenated[k] = '\n';
        k++;
    }

    concatenated[k] = '\0';

    return concatenated;
}
