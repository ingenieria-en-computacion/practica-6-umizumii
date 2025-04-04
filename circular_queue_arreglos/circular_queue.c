#include "circularqueue.h"
#include <stdio.h>

ColaCircular ColaCircular_Vacia() {
    ColaCircular C;
    C.head = -1;
    C.tail = -1;
    C.len = 0;
    return C;
}

bool ColaCircular_esVacia(ColaCircular C) {
    return C.len == 0;
}

bool ColaCircular_esLlena(ColaCircular C) {
    return C.len == TAM;
}

ColaCircular ColaCircular_Enqueue(ColaCircular C, int d) {
    if (ColaCircular_esLlena(C)) {
        printf("La cola está llena\n");
        return C;
    }

    if (ColaCircular_esVacia(C)) {
        C.head = 0;
        C.tail = 0;
    } else {
        C.tail = (C.tail + 1) % TAM;
    }

    C.data[C.tail] = d;
    C.len++;
    return C;
}

ColaCircular ColaCircular_Dequeue(ColaCircular C) {
    if (ColaCircular_esVacia(C)) {
        printf("La cola está vacía\n");
        return C;
    }

    if (C.len == 1) {
        return ColaCircular_Vacia();
    }

    C.head = (C.head + 1) % TAM;
    C.len--;
    return C;
}

int ColaCircular_First(ColaCircular C) {
    if (ColaCircular_esVacia(C)) {
        printf("La cola está vacía\n");
        return -1; // Valor de error
    }
    return C.data[C.head];
}

int ColaCircular_Last(ColaCircular C) {
    if (ColaCircular_esVacia(C)) {
        printf("La cola está vacía\n");
        return -1; // Valor de error
    }
    return C.data[C.tail];
}