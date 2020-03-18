/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** calloc
*/

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *data = malloc(size * nmemb);

    if (data == NULL)
        return (NULL);
    return (memset(data, 0, size * nmemb));
}