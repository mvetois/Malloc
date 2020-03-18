/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** testsym)
{
    return dlsym(handle, sym);
}

void openLib(void)
{
    handle = dlopen("./libmy_malloc.so", RTLD_LAZY);
}

void closeLib(void)
{
    if (handle != NULL)
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include "../include/tests.h"

void *handle = NULL;

void *getSymbol(const char *sym)
{
    return dlsym(handle, sym);
}

void openLib(void)
{
    handle = dlopen("./libmy_malloc.so", RTLD_LAZY);
}

void closeLib(void)
{
    if (handle != NULL)
        dlclose(handle);
}