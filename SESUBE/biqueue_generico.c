#include "biqueue_generico.h"

#ifdef BIQUEUE_IMPLEMENTATION

IMPLEMENT_BIQUEUE(int)
IMPLEMENT_BIQUEUE(char)
IMPLEMENT_BIQUEUE(float)

#endif

void biqueue_int_display(const Biqueue_int* q) {
    if (biqueue_int_is_empty(q)) {
        printf("Bicola vacía\n");
        return;
    }
    
    printf("Contenido (capacidad %zu): [", q->capacity);
    size_t i = q->front;
    while (i != q->rear) {
        printf("%d", q->data[i]);
        i = (i + 1) % q->capacity;
        if (i != q->rear) printf(", ");
    }
    printf("]\n");
}


void test_biqueue_operations() {
    printf("\n=== Prueba de Bicola Int ===\n");
    Biqueue_int* biq = biqueue_int_create(5);
    
    biqueue_int_enqueue_front(biq, 10);
    biqueue_int_enqueue_back(biq, 20);
    biqueue_int_enqueue_front(biq, 5);
    biqueue_int_enqueue_back(biq, 30);
    
    biqueue_int_display(biq);
    printf("Front: %d, Rear: %d\n", biqueue_int_first(biq), biqueue_int_last(biq));
    
    
    int val;
    biqueue_int_dequeue_front(biq, &val);
    printf("Dequeued front: %d\n", val);
    biqueue_int_dequeue_back(biq, &val);
    printf("Dequeued back: %d\n", val);
    
    biqueue_int_display(biq);
    
    biqueue_int_destroy(biq);
}