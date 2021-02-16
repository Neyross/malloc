/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** malloc
*/

#include "libmalloc.h"

chunk_t *head;

chunk_t *best_fit(size_t size, chunk_t *last)
{
    chunk_t *base = head;

    while (base && base->free == false && base->size < size) {
        last = base;
        base = base->next;
    }
    return base;
}

void *malloc(size_t size)
{
    void *adress = sbrk(0);

    if (size < 0)
        return NULL;
    if (sbrk(size) == (void *) -1)
        return NULL;
    return adress;
}