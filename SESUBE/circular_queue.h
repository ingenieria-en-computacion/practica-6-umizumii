#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
#include <stdio.h>
#include <stdbool.h>

#define TAM 100

typedef struct {
    int head;
    int tail;
    int len;
    int data[TAM];
} ColaCircular;

ColaCircular ColaCircular_Vacia();
bool ColaCircular_esVacia(ColaCircular C);
bool ColaCircular_esLlena(ColaCircular C);
ColaCircular ColaCircular_Enqueue(ColaCircular C, int d);
ColaCircular ColaCircular_Dequeue(ColaCircular C);
int ColaCircular_First(ColaCircular C);
int ColaCircular_Last(ColaCircular C);

#endif


