#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----
// Macro para declarar estructuras y prototipos de las funciones
// -----
#define DECLARE_BIQUEUE(TYPE)\
    typedef struct { \
        TYPE* data; \
        size_t front; \
        size_t rear; \
        size_t capacity; \
    } Biqueue_##TYPE; \
    \
    Biqueue_##TYPE* biqueue_##TYPE##_create(size_t capacity); \
    void biqueue_##TYPE##_destroy(Biqueue_##TYPE* q); \
    bool biqueue_##TYPE##_is_empty(const Biqueue_##TYPE* q); \
    bool biqueue_##TYPE##_is_full(const Biqueue_##TYPE* q); \
    bool biqueue_##TYPE##_enqueue_front(Biqueue_##TYPE* q, TYPE value); \
    bool biqueue_##TYPE##_enqueue_back(Biqueue_##TYPE* q, TYPE value); \
    bool biqueue_##TYPE##_dequeue_front(Biqueue_##TYPE* q, TYPE* value); \
    bool biqueue_##TYPE##_dequeue_back(Biqueue_##TYPE* q, TYPE* value); \
    TYPE biqueue_##TYPE##_first(const Biqueue_##TYPE* q); \
    TYPE biqueue_##TYPE##_last(const Biqueue_##TYPE* q);

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_BIQUEUE(TYPE) \
    Biqueue_##TYPE* biqueue_##TYPE##_create(size_t capacity) { \
        Biqueue_##TYPE* q = (Biqueue_##TYPE*)malloc(sizeof(Biqueue_##TYPE)); \
        if (!q) return NULL; \
        q->data = (TYPE*)malloc(capacity * sizeof(TYPE)); \
        if (!q->data) { free(q); return NULL; } \
        q->front = q->rear = 0; \
        q->capacity = capacity; \
        return q; \
    } \
    \
    void biqueue_##TYPE##_destroy(Biqueue_##TYPE* q) { \
        if (q) { \
            free(q->data); \
            free(q); \
        } \
    } \
    \
    bool biqueue_##TYPE##_is_empty(const Biqueue_##TYPE* q) { \
        return q->front == q->rear; \
    } \
    \
    bool biqueue_##TYPE##_is_full(const Biqueue_##TYPE* q) { \
        return (q->rear + 1) % q->capacity == q->front; \
    } \
    \
    bool biqueue_##TYPE##_enqueue_front(Biqueue_##TYPE* q, TYPE value) {\
        if (biqueue_##TYPE##_is_full(q)) return false; \
        q->front = (q->front - 1 + q->capacity) % q->capacity; \
        q->data[q->front] = value; \
        return true;\
    } \
    \
    bool biqueue_##TYPE##_enqueue_back(Biqueue_##TYPE* q, TYPE value) { \
        if (biqueue_##TYPE##_is_full(q)) return false; \
        q->data[q->rear] = value; \
        q->rear = (q->rear + 1) % q->capacity; \
        return true; \
    } \
    \
    bool biqueue_##TYPE##_dequeue_front(Biqueue_##TYPE* q, TYPE* value) { \
        if (biqueue_##TYPE##_is_empty(q)) return false; \
        *value = q->data[q->front]; \
        q->front = (q->front + 1) % q->capacity; \
        return true; \
    } \
    \
    bool biqueue_##TYPE##_dequeue_back(Biqueue_##TYPE* q, TYPE* value) { \
        if (biqueue_##TYPE##_is_empty(q)) return false; \
        q->rear = (q->rear - 1 + q->capacity) % q->capacity; \
        *value = q->data[q->rear]; \
        return true; \
    } \
    \
    TYPE biqueue_##TYPE##_first(const Biqueue_##TYPE* q) { \
        return q->data[q->front]; \
    } \
    \
    TYPE biqueue_##TYPE##_last(const Biqueue_##TYPE* q) { \
        return q->data[(q->rear - 1 + q->capacity) % q->capacity]; \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_BIQUEUE(int)
DECLARE_BIQUEUE(char)
DECLARE_BIQUEUE(float)

// ----
// Implementación para tipos concretos
// -----
#ifdef BIQUEUE_IMPLEMENTATION
IMPLEMENT_BIQUEUE(int)
IMPLEMENT_BIQUEUE(char)
IMPLEMENT_BIQUEUE(float)
#endif