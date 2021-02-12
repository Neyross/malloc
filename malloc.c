/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** malloc
*/

#include "libmalloc.h"

void *malloc(size_t size)
{
    void *adress = sbrk(0);

    if (size < 0)
        return NULL;
    if (sbrk(size) == (void *) -1)
        return NULL;
    return adress;
}