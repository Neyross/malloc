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
    chunk_t *base = head;

    while (base && base->free == false && base->size < size)
    {
        last = base;
        base = base->next;
    }
    return base;
}

size_t block_size(size_t size)
{
    int i = 1;

    size = size + sizeof(chunk_t);
    for (; size % page_size() > size; size %= page_size(), i++)
        ;
    return align2(i * page_size());
}

chunk_t *new_alloc(size_t size)
{
    chunk_t *new;
    void *ptr;

    ptr = sbrk(size);
    if (ptr == (void *)-1)
        return NULL;
    new = (chunk_t *)ptr;
    new->size = size - sizeof(chunk_t);
    new->to_use = ptr + sizeof(chunk_t);
    new->free = true;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

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

void append(chunk_t *chunk)
{
    chunk_t *base = head;

    if (!head)
        head = chunk;
    while (base < chunk)
        base = base->next;
    chunk->next = base;
    chunk->prev = base->prev;
    base->prev->next = chunk;
    base->prev = chunk;
}

void *malloc(size_t size)
{
    chunk_t *mem = NULL;

    if (size <= 0)
        return NULL;
    mem = best_fit(size, mem);
    if (!mem)
        mem = new_alloc(block_size(size));
    if (!mem)
        return NULL;
    else
    {
        append(mem);
        split (mem, size);
        mem->free = false;
        return mem->to_use;
    }
    if (mem->size > size)
        split(mem, size);
    mem->free = false;
    return mem->to_use;
}