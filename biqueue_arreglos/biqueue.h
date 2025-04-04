#ifndef __BIQUEUE_H__
#define __BIQUEUE_H__


#include <stdbool.h>

#define TAM 100  // Tamaño máximo de la bicola

typedef struct {
    int head;
    int tail;
    int len;
    int data[TAM];
} Bicola;

Bicola Bicola_Vacia();
Bicola Bicola_EnqueueFront(Bicola C, int d);
Bicola Bicola_EnqueueBack(Bicola C, int d);
Bicola Bicola_DequeueFront(Bicola C);
Bicola Bicola_DequeueBack(Bicola C);
int Bicola_First(Bicola C);
int Bicola_Last(Bicola C);
void Bicola_Mostrar(Bicola C);
bool Bicola_esVacia(Bicola C);
bool Bicola_esLlena(Bicola C);

#endif