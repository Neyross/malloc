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

#define align2(x) (x / 2 * 2)

typedef struct chunk_s chunk_t;
struct chunk_s {
    chunk_t *next;
    size_t size;
    bool free;
};

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !LIBMALLOC_H_ */
