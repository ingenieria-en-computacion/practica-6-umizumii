#include "cqueue_generico.h"

IMPLEMENT_CIRCULAR_QUEUE(int)
IMPLEMENT_CIRCULAR_QUEUE(char)
IMPLEMENT_CIRCULAR_QUEUE(float)

void circular_queue_int_show(const CircularQueue_int* q) {
    if (circular_queue_int_is_empty(q)) {
        printf("Cola vacía\n");
        return;
    }

    printf("Contenido de la cola [capacidad: %zu]:\n", q->capacity);
    size_t i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

void test_circular_queue_int() {
    const size_t capacity = 5;
    CircularQueue_int* q = circular_queue_int_create(capacity);
    
    if (!q) {
        printf("Error al crear la cola\n");
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (!circular_queue_int_enqueue(q, i*10)) {
            printf("Cola llena al intentar insertar %d\n", i*10);
        }
    }

    circular_queue_int_show(q);

    int value;
    for (int i = 0; i < 2; i++) {
        if (circular_queue_int_dequeue(q, &value)) {
            printf("Elemento eliminado: %d\n", value);
        }
    }

    circular_queue_int_show(q);

    printf("Front: %d\n", circular_queue_int_front(q));
    printf("Rear: %d\n", circular_queue_int_rear(q));

    circular_queue_int_destroy(q);
}