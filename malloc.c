/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** malloc
*/

#include "libmalloc.h"

chunk_t *head = NULL;

chunk_t *best_fit(size_t size, chunk_t *last)
{
    chunk_t *base;

    if (!head)
        return NULL;
    base = head;
    while (base->size < size || base->free == false)
    {
        base = base->next;
        if (base == head)
            return NULL;
    }
    return base;
}

chunk_t *new_alloc(size_t size)
{
    chunk_t *new;
    void *ptr;

    ptr = sbrk(size);
    if (ptr == (void *)-1)
        return NULL;
    new = ptr;
    new->size = size - sizeof(chunk_t);
    new->to_use = ptr + sizeof(chunk_t);
    new->free = true;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void append(chunk_t *chunk)
{
    chunk_t *base;

    if (!head)
        head = chunk;
    base = head;
    while (base < chunk)
    {
        base = base->next;
        if (base == head)
            break;
    }
    chunk->prev = base->prev;
    chunk->next = base;
    base->prev = chunk;
    base->prev->next = chunk;
}

size_t block_size(size_t size)
{
    int i = 1;

    size = size + sizeof(chunk_t);
    i = i + size / page_size();
    return page_size() * i;
}

void *malloc(size_t size)
{
    chunk_t *mem;

    if (size <= 0)
        return NULL;
    mem = best_fit(size, mem);
    if (!mem)
    {
        mem = new_alloc(block_size(size));
        if (!mem)
            return NULL;
        else
        {
            append(mem);
            split(mem, size);
            mem->free = false;
            return mem->to_use;
        }
    }
    if (mem->size > size)
        split(mem, size);
    mem->free = false;
    return mem->to_use;
}