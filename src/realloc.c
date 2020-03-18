/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** realloc
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    block_t *block;
    void *dest;

    if (ptr == NULL)
        return (malloc(size));
    block = ptr - sizeof(block_t);
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (block->is_free)
        return (NULL);
    if (block->size >= size)
        return (ptr);
    dest = malloc(size);
    if (dest != NULL)
        memcpy(dest, block + sizeof(block_t), block->size);
    free(ptr);
    return (dest);
}