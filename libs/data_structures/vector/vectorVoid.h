#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct vectorVoid {
    int *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;

} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.data = malloc(n * baseTypeSize);

    if (!v.data) {
        fprintf(stderr, "bad alloc\n");
        exit(1);
    }

    v.size = 0;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity > v->capacity) {
        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);
        if (newData == NULL) {
            fprintf(stderr, "bad alloc\n");
            exit(1);
        }
        v->data = newData;
        v->capacity = newCapacity;
    }
}

void shrinkToFitV(vectorVoid *v) {
    if (v->size < v->capacity) {
        void *newData = realloc(v->data, v->size * v->baseTypeSize);
        if (newData == NULL) {
            fprintf(stderr, "bad alloc\n");
            exit(1);
        }
        v->data = newData;
        v->capacity = v->size;
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

#endif