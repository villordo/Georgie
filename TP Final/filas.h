#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"
#include "gestionPersonas.h"

typedef struct{
	nodo2 *cabeza;
	nodo2 *cola;
}fila;

void *inicFila(fila *fila1);
nodo2 *crearNodoFila(persona dato);
void mostrarFila(fila *fila1);
void agregarPpio(fila *fila1, nodo2 *nuevoNodo);
void *agregarFinalFilas(fila *fila1, nodo2 *nuevoNodo);
int filaVacia(fila *fila1);
nodo2 *extraer(fila *fila1);
void leerFila(fila *fila1);
nodo2 *primero(fila *fila1);
fila *agregarEnOrden(fila *fila1, nodo2 *nuevoNodo);
fila *agregarPorPrioridad(fila *fila1, nodo2*nuevoNodo);

#endif // FILAS_H_INCLUDED
