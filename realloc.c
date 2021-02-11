/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** realloc
*/

#include "libmalloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
}

void *realloc(void *ptr, size_t size)
{
    void *newptr = malloc(size);
    char *b1 = ptr;
    char *b2 = newptr;

    if (size <= 0)
        return NULL;
    if (ptr)
        for (size_t i = 0, n = 0; i < 1024; ++i, n++)
            b2[n] = b1[n];
    return newptr;
}