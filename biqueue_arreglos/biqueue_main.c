#include <stdio.h>
#include "biqueue.h"

int main() {
    Bicola C = Bicola_Vacia();

    // Pruebas de encolado
    C = Bicola_EnqueueBack(C, 10);
    C = Bicola_EnqueueBack(C, 20);
    C = Bicola_EnqueueFront(C, 5);
    C = Bicola_EnqueueFront(C, 1);

    printf("Primer elemento: %d\n", Bicola_First(C)); // Debe imprimir 1
    printf("Último elemento: %d\n", Bicola_Last(C));  // Debe imprimir 20

    // Prueba de desencolado
    C = Bicola_DequeueFront(C);
    printf("Después de dequeue front, primer elemento: %d\n", Bicola_First(C)); // Debe imprimir 5

    C = Bicola_DequeueBack(C);
    printf("Después de dequeue back, último elemento: %d\n", Bicola_Last(C)); // Debe imprimir 10

    // Comprobación de si está vacía
    if (Bicola_esVacia(C)) {
        printf("La bicola está vacía.\n");
    } else {
        printf("La bicola NO está vacía.\n");
    }

    return 0;
}