/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** calloc
*/

#include "my_malloc.h"

static void merge_free(block_t *block)
{
    if (block->next->is_free == true) {
        block->size += sizeof(block_t) + block->next->size;
        block->next->next->prev = block;
        block->next = block->next->next;
    }
    if (block->prev->is_free == true) {
        block->size += sizeof(block_t) + block->prev->size;
        block->prev->prev->next = block;
        block->prev = block->prev->prev;
    }
}

void free(void *ptr)
{
    block_t *check = block_head();

    if (ptr == NULL)
        return;
    while (check != NULL) {
        if (check->data == ptr) {
            check->is_free = true;
            merge_free(check);
            return;
        }
        check = check->next;
    }
}