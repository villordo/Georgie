#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include "gestionPersonas.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    persona p;
    struct nodo2 * sig;
    struct nodo2 * ante;
} nodo2;

nodo2 * inicLista();

nodo2 * crearNodoLista(persona p);

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo);
// recursivo
nodo2 * buscarUltimoR(nodo2 * lista);

nodo2 * agregarAlFinal(nodo2 * lista, nodo2 * nuevoNodo);

void mostrarNodo(nodo2 * aux);

void recorrerYmostrar(nodo2 * lista);




#endif // LISTADOBLE_H_INCLUDED
