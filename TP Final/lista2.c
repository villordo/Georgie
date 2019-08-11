#include "lista2.h"
#include <string.h>

nodo2 * inicLista()
{
    return NULL;
}

nodo2 * crearNodoLista(persona p)
{
    nodo2* aux=(nodo2*) malloc(sizeof(nodo2));
    aux->p.id=p.id;
    strcpy(aux->p.apellido, p.apellido);
    strcpy(aux->p.nombres, p.nombres);
    aux->p.tipoCliente=p.tipoCliente;
    aux->p.medioPago=p.medioPago;
    aux->p.cantArticulos=p.cantArticulos;
    aux->p.tiempoEspera=0;
    aux->p.tiempoProcesado=0;
    aux->p.eliminado=p.eliminado;
    aux->ante=NULL;
    aux->sig=NULL;
    return aux;
}

nodo2 * agregarAlPrincipio(nodo2 * lista, nodo2 * nuevoNodo)
{
    nuevoNodo->sig=lista;
    if(lista!=NULL)
    {
        lista->ante=nuevoNodo;
    }
    return nuevoNodo;
}

// recursivo
nodo2 *buscarUltimoR(nodo2 *lista)
{
    nodo2 * rta=NULL;
    if(lista!=NULL)
    {
        if(lista->sig==NULL)
        {
            rta=lista;
        }
        else
        {
            rta=buscarUltimoR(lista->sig);
        }
    }
    return rta;
}

nodo2 *agregarAlFinal(nodo2 *lista, nodo2 *nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo2 * ultimo = buscarUltimoR(lista);
        ultimo->sig = nuevoNodo;
        nuevoNodo->ante = ultimo;
    }
    return lista;
}
void mostrarNodo(nodo2 *aux)
{
    printf("\nNombre: %s", aux->p.nombres);
    printf("\nApellido: %s", aux->p.apellido);
    printf("\nTipo de cliente: %d", aux->p.tipoCliente);
    printf("\nMedio de pago: %d", aux->p.medioPago);
    printf("\nCantidad de articulos: %d", aux->p.cantArticulos);
    printf("\nTiempo Procesado: %d", aux->p.tiempoProcesado);
    printf("\nTiempo Espera: %d\n\n", aux->p.tiempoEspera);
}

void recorrerYmostrar(nodo2 * lista)
{
    nodo2 * seg = lista;
    while (seg != NULL)
    {
        mostrarNodo(seg);
        seg=seg->sig;
    }
    printf("\n");
}

