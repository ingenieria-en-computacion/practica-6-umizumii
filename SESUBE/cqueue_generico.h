#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// ----------------------------
// Macro para declarar estructuras y prototipos
// ----------------------------
#define DECLARE_CIRCULAR_QUEUE(TYPE) \
    typedef struct { \
        TYPE* data; \
        size_t front; \
        size_t rear; \
        size_t capacity; \
    } CircularQueue_##TYPE; \
    \
    CircularQueue_##TYPE* circular_queue_##TYPE##_create(size_t capacity); \
    void circular_queue_##TYPE##_destroy(CircularQueue_##TYPE* q); \
    bool circular_queue_##TYPE##_is_empty(const CircularQueue_##TYPE* q); \
    bool circular_queue_##TYPE##_is_full(const CircularQueue_##TYPE* q); \
    bool circular_queue_##TYPE##_enqueue(CircularQueue_##TYPE* q, TYPE value); \
    bool circular_queue_##TYPE##_dequeue(CircularQueue_##TYPE* q, TYPE* value); \
    TYPE circular_queue_##TYPE##_front(const CircularQueue_##TYPE* q); \
    TYPE circular_queue_##TYPE##_rear(const CircularQueue_##TYPE* q);

// ----------------------------
// Macro para implementación
// ----------------------------
#define IMPLEMENT_CIRCULAR_QUEUE(TYPE) \
    CircularQueue_##TYPE* circular_queue_##TYPE##_create(size_t capacity) { \
        CircularQueue_##TYPE* q = (CircularQueue_##TYPE*)malloc(sizeof(CircularQueue_##TYPE)); \
        if (!q) return NULL; \
        q->data = (TYPE*)malloc(capacity * sizeof(TYPE)); \
        if (!q->data) { free(q); return NULL; } \
        q->front = q->rear = 0; \
        q->capacity = capacity; \
        return q; \
    } \
    \
    void circular_queue_##TYPE##_destroy(CircularQueue_##TYPE* q) { \
        if (q) { \
            free(q->data); \
            free(q); \
        } \
    } \
    \
    bool circular_queue_##TYPE##_is_empty(const CircularQueue_##TYPE* q) { \
        return q->front == q->rear; \
    } \
    \
    bool circular_queue_##TYPE##_is_full(const CircularQueue_##TYPE* q) { \
        return (q->rear + 1) % q->capacity == q->front; \
    } \
    \
    bool circular_queue_##TYPE##_enqueue(CircularQueue_##TYPE* q, TYPE value) { \
        if (circular_queue_##TYPE##_is_full(q)) return false; \
        q->data[q->rear] = value; \
        q->rear = (q->rear + 1) % q->capacity; \
        return true; \
    } \
    \
    bool circular_queue_##TYPE##_dequeue(CircularQueue_##TYPE* q, TYPE* value) { \
        if (circular_queue_##TYPE##_is_empty(q)) return false; \
        *value = q->data[q->front]; \
        q->front = (q->front + 1) % q->capacity; \
        return true; \
    } \
    \
    TYPE circular_queue_##TYPE##_front(const CircularQueue_##TYPE* q) { \
        return q->data[q->front]; \
    } \
    \
    TYPE circular_queue_##TYPE##_rear(const CircularQueue_##TYPE* q) { \
        return q->data[(q->rear - 1 + q->capacity) % q->capacity]; \
    }

// ----------------------------
// Declaración para tipos concretos
// ----------------------------
DECLARE_CIRCULAR_QUEUE(int)
DECLARE_CIRCULAR_QUEUE(char)
DECLARE_CIRCULAR_QUEUE(float)

// ----------------------------
// Implementación para tipos concretos
// ----------------------------
#ifdef CIRCULAR_QUEUE_IMPLEMENTATION
IMPLEMENT_CIRCULAR_QUEUE(int)
IMPLEMENT_CIRCULAR_QUEUE(char)
IMPLEMENT_CIRCULAR_QUEUE(float)
#endif