/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** malloc
*/

#include <math.h>
#include "my_malloc.h"

block_t *block_head(void)
{
    static block_t *start = NULL;
    return (start);
}

static block_t *find_free_block(size_t const size, block_t *block)
{
    if (block == NULL)
        return (NULL);
    while (block->next != NULL) {
        if (block->is_free == true && size <= block->size)
            return (block);
        block = block->next;
    }
    return (NULL);
}

static void *create_block(size_t const size, block_t *block)
{
    void *data = block->data + block->size;
    size_t s = size / (getpagesize());

    if (block->data + block->size + size < sbrk(0)) {
        s = (s == 0) ? 2 : s;
        if (s % 2 != 0)
            s++;
        data = sbrk(getpagesize() * s);
    }
    if (data == (void *)-1)
        return (NULL);
    while (block->next != NULL)
        block = block->next;
    block->next = data;
    block->next->size = size;
    block->next->is_free = false;
    block->next->prev = block;
    block->next->next = NULL;
    block->next->data = sizeof(block_t) + data;
    return (block->next);
}

static void *init_block(size_t const size)
{
    block_t *new;
    void *data;
    size_t s = size / (getpagesize());

    s = (s == 0) ? 2 : s;
    if (s % 2 != 0)
        s++;
    data = sbrk(getpagesize() * s);
    if (data == (void *)-1)
        return (NULL);
    new = data;
    new->size = size;
    new->is_free = false;
    new->prev = NULL;
    new->next = NULL;
    new->data = sizeof(block_t) + data;
    return (new);
}

void *malloc(size_t size)
{
    block_t *start = block_head();
    block_t *block;

    if (size == 0)
        return (NULL);
    while (log(size)/log(2) != (int)(log(size)/log(2)))
        size++;
    if (start == NULL) {
        if ((start = init_block(size)) == NULL)
            return (NULL);
        return (start->data);
    }
    if ((block = find_free_block(size, start)) != NULL) {
        block->is_free = false;
        return (block->data);
    } else {
        if ((block = create_block(size, start)) == NULL)
            return (NULL);
        return (block->data);
    }
    return (NULL);
}