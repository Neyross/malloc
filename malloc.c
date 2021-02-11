/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** malloc
*/

#include "libmalloc.h"

void *malloc(size_t size)
{
    void *adress;

    if (size <= 0)
        return NULL;
    adress = sbrk(size);
    if (adress == (void *) -1)
        return NULL;
    return adress;
}