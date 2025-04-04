#include "biqueue.h"
#include <stdio.h>

Bicola Bicola_Vacia() {
    Bicola C;
    C.head = -1;
    C.tail = -1;
    C.len = 0;
    return C;
}

bool Bicola_esVacia(Bicola C) {
    return C.len == 0;
}

bool Bicola_esLlena(Bicola C) {
    return C.len == TAM;
}

Bicola Bicola_EnqueueFront(Bicola C, int d) {
    if (Bicola_esLlena(C)) {
        printf("La bicola está llena\n");
        return C;
    }
    if (Bicola_esVacia(C)) {
        C.head = C.tail = 0;
    } else {
        C.head = (C.head == 0) ? TAM - 1 : C.head - 1;
    }
    C.data[C.head] = d;
    C.len++;
    return C;
}

Bicola Bicola_EnqueueBack(Bicola C, int d) {
    if (Bicola_esLlena(C)) {
        printf("La bicola está llena\n");
        return C;
    }
    if (Bicola_esVacia(C)) {
        C.head = C.tail = 0;
    } else {
        C.tail = (C.tail + 1) % TAM;
    }
    C.data[C.tail] = d;
    C.len++;
    return C;
}

Bicola Bicola_DequeueFront(Bicola C) {
    if (Bicola_esVacia(C)) {
        printf("La bicola está vacía\n");
        return C;
    }
    if (C.len == 1) {
        return Bicola_Vacia();
    }
    C.head = (C.head + 1) % TAM;
    C.len--;
    return C;
}

Bicola Bicola_DequeueBack(Bicola C) {
    if (Bicola_esVacia(C)) {
        printf("La bicola está vacía\n");
        return C;
    }
    if (C.len == 1) {
        return Bicola_Vacia();
    }
    C.tail = (C.tail == 0) ? TAM - 1 : C.tail - 1;
    C.len--;
    return C;
}

int Bicola_First(Bicola C) {
    if (Bicola_esVacia(C)) {
        printf("La bicola está vacía\n");
        return -1;
    }
    return C.data[C.head];
}

int Bicola_Last(Bicola C) {
    if (Bicola_esVacia(C)) {
        printf("La bicola está vacía\n");
        return -1;
    }
    return C.data[C.tail];
}