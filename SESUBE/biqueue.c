#include "biqueue.h"
#include <stdio.h>

Bicola Bicola_Vacia() {
    Bicola B;
    B.head = -1;
    B.tail = -1;
    B.len = 0;
    return B;
}

bool Bicola_esVacia(Bicola B) {
    return B.len == 0;
}

bool Bicola_esLlena(Bicola B) {
    return B.len == TAM;
}

Bicola Bicola_EnqueueFront(Bicola B, int d) {
    if (Bicola_esLlena(B)) {
        printf("Error: Bicola llena\n");
        return B;
    }
    
    if (Bicola_esVacia(B)) {
        B.head = B.tail = 0;
    } else {
        B.head = (B.head == 0) ? TAM - 1 : B.head - 1;
    }
    
    B.data[B.head] = d;
    B.len++;
    return B;
}

Bicola Bicola_EnqueueBack(Bicola B, int d) {
    if (Bicola_esLlena(B)) {
        printf("Error: Bicola llena\n");
        return B;
    }
    
    if (Bicola_esVacia(B)) {
        B.head = B.tail = 0;
    } else {
        B.tail = (B.tail + 1) % TAM;
    }
    
    B.data[B.tail] = d;
    B.len++;
    return B;
}

Bicola Bicola_DequeueFront(Bicola B) {
    if (Bicola_esVacia(B)) {
        printf("Error: Bicola vacia\n");
        return B;
    }
    
    if (B.len == 1) {
        return Bicola_Vacia();
    }
    
    B.head = (B.head + 1) % TAM;
    B.len--;
    return B;
}

Bicola Bicola_DequeueBack(Bicola B) {
    if (Bicola_esVacia(B)) {
        printf("Error: Bicola vacia\n");
        return B;
    }
    
    if (B.len == 1) {
        return Bicola_Vacia();
    }
    
    B.tail = (B.tail == 0) ? TAM - 1 : B.tail - 1;
    B.len--;
    return B;
}

int Bicola_First(Bicola B) {
    if (Bicola_esVacia(B)) {
        printf("Error: Bicola vacia\n");
        return -1;  // Valor de error
    }
    return B.data[B.head];
}

int Bicola_Last(Bicola B) {
    if (Bicola_esVacia(B)) {
        printf("Error: Bicola vacia\n");
        return -1;  // Valor de error
    }
    return B.data[B.tail];
}

void Bicola_Mostrar(Bicola B) {
    if (Bicola_esVacia(B)) {
        printf("Bicola vacia\n");
        return;
    }
    
    printf("Bicola [");
    int i = B.head;
    int count = 0;
    
    while (count < B.len) {
        printf("%d", B.data[i]);
        if (count < Bicola_DequeueBack < B.len - 1) printf(", ");
        
        i = (i + 1) % TAM;
        count++;
    }
    
    printf("]\n");
}