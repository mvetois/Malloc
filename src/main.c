/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** main
*/
#include "my_malloc.h"
void *my_malloc(size_t size);

int main(void)
{
    char *a = my_malloc(getpagesize() * 4);
    a[0] = 'a';
    a[1] = 'a';
    a[2] = '\0';
    printf("%s\n", a);
    char *b = my_malloc(sizeof(char) * 5);
    b[0] = 'b';
    b[1] = 'b';
    b[2] = '\0';
    printf("%s\n", b);
    free(a);
}