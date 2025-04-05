#include "circular_queue.h"

ColaCircular ColaCircular_Vacia() {
    ColaCircular C;
    C.head = 0;
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
        printf("Error: Cola llena\n");
        return C;
    }
    
    C.tail = (C.tail + 1) % TAM;
    C.data[C.tail] = d;
    C.len++;
    return C;
}

ColaCircular ColaCircular_Dequeue(ColaCircular C) {
    if (ColaCircular_esVacia(C)) {
        printf("Error: Cola vacía\n");
        return C;
    }
    
    C.head = (C.head + 1) % TAM;
    C.len--;
    if (ColaCircular_esVacia(C)) {
        C = ColaCircular_Vacia();
    }
    
    return C;
}

int ColaCircular_First(ColaCircular C) {
    if (ColaCircular_esVacia(C)) {
        printf("Error: Cola vacía\n");
        return -1;  
    }
    return C.data[C.head];
}

int ColaCircular_Last(ColaCircular C) {
    if (ColaCircular_esVacia(C)) {
        printf("Error: Cola vacía\n");
        return -1;  
    }
    return C.data[C.tail];
}