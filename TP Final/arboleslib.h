#ifndef ARBOLESLIB_H_INCLUDED
#define ARBOLESLIB_H_INCLUDED
#include "ADL.h"
#include "gestionPersonas.h"



typedef struct
{
    persona p;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;


nodoArbol*inicArbol();
nodoArbol*crearNodoArbol(persona p);
nodoArbol* buscar(nodoArbol*arbol,char nombre[]);
nodoArbol*insertar(nodoArbol*arbol,persona p);
void preorder(nodoArbol*arbol);
void inorder(nodoArbol*arbol);
void postorder(nodoArbol*arbol);
nodoArbol* borrarNodoArbol(nodoArbol*arbol,char nombre[]);
nodoArbol* nodoMasIzq(nodoArbol*arbol);
nodoArbol* nodoMasDer(nodoArbol*arbol);
nodoArbol* sobrescribirDatos(nodoArbol*arbol,nodoArbol*aux);
void pasarPreOrder(nodoArbol*arbol,caja cajas[], int validos);
void pasarInOrder(nodoArbol*arbol,caja cajas[], int validos);
void pasarPostOrder(nodoArbol*arbol,caja cajas[], int validos);
void pasarDeArbolToLineaDeCajas(nodo2 *nuevoNodo,caja cajas[6], int i);
void mostrarNodoArbol(nodoArbol*arbol);

#endif // ARBOLESLIB_H_INCLUDED
