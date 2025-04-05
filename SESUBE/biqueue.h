#ifndef __BIQUEUE_H__
#define __BIQUEUE_H__

#include <stdio.h>
#include <stdbool.h>

#define TAM 100  // Tamaño máximo de la bicola

typedef struct {
    int head;
    int tail;
    int len;
    int data[TAM];
}Bicola;

Bicola Bicola_Vacia();
Bicola Bicola_EnqueueFront(Bicola B, int d);
Bicola Bicola_EnqueueBack(Bicola B, int d);
Bicola Bicola_DequeueFront(Bicola B);
Bicola Bicola_DequeueBack(Bicola B);
int Bicola_First(Bicola B);
int Bicola_Last(Bicola B);
void Bicola_Mostrar(Bicola B);
bool Bicola_esVacia(Bicola B);
bool Bicola_esLlena(Bicola B);

#endif