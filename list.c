/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** list
*/

#include "libmalloc.h"

void split(chunk_t *chunk, size_t size)
{
    chunk_t *new;
    void *ptr;

    if (chunk->size - size <= sizeof(chunk_t))
        return;
    if (chunk->size == size)
        return;
    ptr = (void *)chunk + size + sizeof(chunk_t);
    new = ptr;
    new->size = chunk->size - sizeof(chunk_t) - size;
    new->to_use = ptr + sizeof(chunk_t);
    new->prev = chunk;
    new->next = chunk->next;
    new->free = true;
    chunk->prev->next = new;
    chunk->size = size;
    chunk->next = new;
    chunk->free = true;
}