/*
** EPITECH PROJECT, 2020
** Malloc
** File description:
** malloc
*/

#include <criterion/criterion.h>
#include "../include/my_malloc.h"
#include "../include/tests.h"

Test(malloc, one, .init = openLib, .fini = closeLib)
{
    char * (*fc_ptr)(int) = getSymbol("malloc");
    char *result = fc_ptr(4);

    cr_assert(result != NULL);
}