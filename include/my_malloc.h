/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct block_s{
    size_t size;
    bool is_free;
    void *data;
    struct block_s *next;
    struct block_s *prev;
} block_t;

//malloc.c
block_t *block_head(void);
void *malloc(size_t size);

//free.c
void free(void *ptr);

//calloc.c
void *calloc(size_t nmemb, size_t size);

//realloc.c
void *realloc(void *ptr, size_t size);

#endif /* !MY_MALLOC_H_ */
