/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** calloc
*/

#include "libmalloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(size * nmemb);

    if (!ptr)
        return NULL;
    return memset(ptr, 0, (size *nmemb));
}