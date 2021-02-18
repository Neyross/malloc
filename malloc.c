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

    if (!head)
        return NULL;
    while (base->free == false || base->size <= size){
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
    chunk_t *base;

    if (!head)
        head = chunk;
    base = head;
    while (base->next != 0) {
        base = base->next;
        if (base == head)
            break;
    }
    chunk->prev = base->prev;
    chunk->next = base;
    base->prev = chunk;
    base->prev->next = chunk;
}

void *malloc(size_t size)
{
    chunk_t *mem = NULL;

    if (size <= 0)
        return NULL;
    mem = best_fit(size, mem);
    if (!mem)
        mem = new_alloc(size + sizeof(chunk_t));
    if (!mem)
        return NULL;
    else
    {
        append(mem);
        split(mem, size);
        mem->free = false;
        return mem->to_use;
    }
    if (mem->size > size)
        split(mem, size);
    mem->free = false;
    return mem->to_use;
}