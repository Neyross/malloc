/*
** EPITECH PROJECT, 2021
** B-PSU-400-LYN-4-1-malloc-thibault.bordenave
** File description:
** libmalloc
*/

#ifndef LIBMALLOC_H_
#define LIBMALLOC_H_

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct chunk_s chunk_t;
struct chunk_s {
    chunk_t *next;
    chunk_t *prev;
    size_t size;
    bool free;
    void *to_use;
};

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
void my_put_nbr(size_t nb);
void my_putchar (char c);

#endif /* !LIBMALLOC_H_ */
