#include "filas.h"
#include "lista2.h"
#include <stdio.h>
#include <stdlib.h>

void *inicFila(fila *fila1){
	fila1->cabeza=NULL;
	fila1->cola=NULL;
}

nodo2 *crearNodoFila(persona dato){
	nodo2 *aux=(nodo2*)malloc(sizeof(nodo2));
	aux->p=dato;
	aux->ante=NULL;
	aux->sig=NULL;
	return aux;
}

void mostrarFila(fila *fila1){
	nodo2 *aux=fila1->cabeza;
	while(aux!=NULL){
        printf("\n");
        printf("\nDATOS CLIENTE.");
		printf("\nID: %d",aux->p.id);
        printf("\nNombre: %s",aux->p.nombres);
        printf("\nApellido: %s", aux->p.apellido);
        printf("\nMedio de Pago: %d",aux->p.medioPago);
        printf("\nTipo Cliente: %d",aux->p.tipoCliente);
        printf("\nCantidad Articulos: %d",aux->p.cantArticulos);
        printf("\nTiempo Procesado: %d", aux->p.tiempoProcesado);
        printf("\nTiempo Espera: %d\n", aux->p.tiempoEspera);
		aux=aux->sig;
	}

}

void agregarPpio(fila *fila1, nodo2 *nuevoNodo){
	if(fila1->cabeza == NULL){
		fila1->cabeza=nuevoNodo;
		fila1->cola=nuevoNodo;
	}else{
		nodo2 *aux=fila1->cabeza;
		nuevoNodo->sig=fila1->cabeza;
		aux->ante=nuevoNodo;
		fila1->cabeza=nuevoNodo;
	}
}
fila *agregarEnOrden(fila *fila1, nodo2*nuevoNodo)
{
    nodo2 *lista=fila1->cabeza;
    if(lista==NULL)
    {
		lista=nuevoNodo;
		fila1->cabeza=lista;
		fila1->cola=lista;
    }
    else
    {
        if(nuevoNodo->p.cantArticulos < lista->p.cantArticulos)
        {
            lista=agregarAlPrincipio(lista,nuevoNodo);
            fila1->cabeza=lista;
        }
        else
        {
            nodo2 *seg=lista->sig;
            nodo2 *ante=lista;
            while(seg!=NULL && nuevoNodo->p.cantArticulos > seg->p.cantArticulos){
                ante=seg;
                seg=seg->sig;
            }
            ante->sig=nuevoNodo;
            nuevoNodo->ante=ante;
            nuevoNodo->sig=seg;
            if(seg!=NULL) seg->ante=nuevoNodo;
            nodo2 *ultimo=NULL;
            ultimo=buscarUltimoR(lista);
            fila1->cola=ultimo;
        }
    }
    return fila1;
}
fila *agregarPorPrioridad(fila *fila1, nodo2*nuevoNodo)
{
    nodo2 *lista=fila1->cabeza;
    if(lista==NULL)
    {
		lista=nuevoNodo;
		fila1->cabeza=lista;
		fila1->cola=lista;
    }
    else
    {
        if(nuevoNodo->p.tipoCliente < lista->p.tipoCliente)
        {
            lista=agregarAlPrincipio(lista,nuevoNodo);
            fila1->cabeza=lista;
        }
        else
        {
            nodo2 *seg=lista->sig;
            nodo2 *ante=lista;
            while(seg!=NULL && nuevoNodo->p.tipoCliente > seg->p.tipoCliente){
                ante=seg;
                seg=seg->sig;
            }
            ante->sig=nuevoNodo;
            nuevoNodo->ante=ante;
            nuevoNodo->sig=seg;
            if(seg!=NULL) seg->ante=nuevoNodo;
            nodo2 *ultimo=NULL;
            ultimo=buscarUltimoR(lista);
            fila1->cola=ultimo;
        }
    }
    return fila1;
}



void *agregarFinalFilas(fila *fila1, nodo2 *nuevoNodo){
	if(fila1->cabeza == NULL){
        fila1->cabeza=nuevoNodo;
		fila1->cola=nuevoNodo;
	}else{
		nodo2* cola=fila1->cola;
        cola->sig =  nuevoNodo;
        nuevoNodo->ante=cola;
        fila1->cola=nuevoNodo;
	}
}

nodo2 *extraer(fila *fila1){
    nodo2 *eliminado=fila1->cabeza;
	if(fila1->cabeza==fila1->cola){
		fila1->cabeza=NULL;
		fila1->cola=NULL;
	}else{
		nodo2 *nodoSig=eliminado->sig;
		eliminado->sig=NULL;
		nodoSig->ante=NULL;
		fila1->cabeza=nodoSig;
	}
	return eliminado;
}

nodo2 *primero(fila *fila1){
	nodo2 *rta;
	if(fila1->cabeza){
		nodo2 *aux=fila1->cabeza;
		rta=aux;
	}
	return rta;
}

int filaVacia(fila *fila1){
	int rta=0;
	mostrarNodo(fila1->cabeza);
	if(fila1->cabeza!=NULL){
		rta=1;
	}
	return rta;
}
