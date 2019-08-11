#include "lista2.h"
#include "arboleslib.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "ADL.h"


nodoArbol*inicArbol()
{
    return NULL;
}

nodoArbol *crearNodoArbol(persona p)
{
    nodoArbol*aux = malloc(sizeof(nodoArbol));
    strcpy(aux->p.apellido,p.apellido);
    strcpy(aux->p.nombres,p.nombres);
    aux->p.id=p.id;
    aux->p.cantArticulos=p.cantArticulos;
    aux->p.medioPago=p.medioPago;
    aux->p.tipoCliente=p.tipoCliente;
    aux->p.eliminado=0;
    aux->izq= NULL;
    aux->der= NULL;

    return aux;
}

nodoArbol *buscar(nodoArbol *arbol,char nombre[])
{
    nodoArbol*rta=NULL;
    if(arbol!=NULL)
    {
        if(strcmpi(nombre,arbol->p.nombres)==0)
        {
            rta=arbol; ///si encuentra el dato lo retorna
        }
        else
        {
            if(strcmpi(nombre,arbol->p.nombres)<0)
            {
                rta=buscar(arbol->der,nombre);
            }
            else
            {
                printf("izq");
                rta=buscar(arbol->izq,nombre);
            }
        }
    }
    return rta;
}

nodoArbol*insertar(nodoArbol*arbol,persona p)
{
    if(arbol==NULL)
    {
        arbol=crearNodoArbol(p);
    }
    else
    {
        if( strcmp(p.nombres,arbol->p.nombres)>0)
        {
            arbol->der=insertar(arbol->der,p);
        }
        else
        {
            arbol->izq=insertar(arbol->izq,p);
        }
    }
    return arbol;
}
nodoArbol* pasarArchivoToArbol(char archivo_clientes[],nodoArbol*arbol)
{
    FILE*archi;
    persona aux;
    archi=fopen(archivo_clientes,"rb");
    if(archi!=NULL)
    {
        while(fread(&aux, sizeof(persona), 1,archi)>0)
        {
            arbol=insertar(arbol,aux);
        }
    }
    fclose(archi);
    return arbol;
}
void preorder(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        printf("\nID: %d",arbol->p.id);
        printf("\nNombre: %s",arbol->p.nombres);
        printf("\nApellido: %s",arbol->p.apellido);
        printf("\nMedio de Pago: %d",arbol->p.medioPago);
        printf("\nTipo Cliente: %d",arbol->p.tipoCliente);
        printf("\nCantidad Articulos: %d",arbol->p.cantArticulos);
        preorder(arbol->izq);
        preorder(arbol->der);
    }

}

void inorder(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);
        printf("\nID: %d",arbol->p.id);
        printf("\nNombre: %s",arbol->p.nombres);
        printf("\nApellido: %s",arbol->p.apellido);
        printf("\nMedio de Pago: %d",arbol->p.medioPago);
        printf("\nTipo Cliente: %d",arbol->p.tipoCliente);
        printf("\nCantidad Articulos: %d",arbol->p.cantArticulos);
        inorder(arbol->der);
    }

}

void postorder(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        postorder(arbol->izq);
        postorder(arbol->der);
        printf("\nID: %d",arbol->p.id);
        printf("\nNombre: %s",arbol->p.nombres);
        printf("\nApellido: %s",arbol->p.apellido);
        printf("\nMedio de Pago: %d",arbol->p.medioPago);
        printf("\nTipo Cliente: %d",arbol->p.tipoCliente);
        printf("\nCantidad Articulos: %d",arbol->p.cantArticulos);
        printf("\n");
        printf("- - - - - - - - -");
    }

}
void mostrarNodoArbol(nodoArbol*arbol)
{
    if(arbol!=NULL)
    {
        printf("\nID: %d",arbol->p.id);
        printf("\nNombre: %s",arbol->p.nombres);
        printf("\nApellido: %s",arbol->p.apellido);
        printf("\nMedio de Pago: %d",arbol->p.medioPago);
        printf("\nTipo Cliente: %d",arbol->p.tipoCliente);
        printf("\nCantidad Articulos: %d",arbol->p.cantArticulos);
    }

}
void mostrarArbol(nodoArbol*arbol)
{
    int selected;
    postorder(arbol);
}
nodoArbol* borrarNodoArbol(nodoArbol*arbol,char nombre[])
{
    nodoArbol*aux=NULL;
    nodoArbol*auxIzq=NULL;
    nodoArbol*auxDer=NULL;

    if(arbol!=NULL);
    {
        printf("\n nombre %s, nombre arbol %s",nombre,arbol->p.nombres);

        if(strcmpi(nombre,arbol->p.nombres)==0)
        {
            if(arbol->der==NULL && arbol->izq==NULL) ///si no tiene hijos
            {
                printf("\nborra nodo");
                aux=arbol;
                arbol=NULL;
                free(aux);
                printf("\nfree\n");
            }
            else///si tiene hijos
            {
                if(arbol->izq==NULL)///si tiene un hijo a la derecha
                {
                    printf("\ncon hijo a la der\n");
                    auxDer=nodoMasIzq(arbol->der);
                    arbol=sobrescribirDatos(arbol,auxDer);
                    arbol->der=borrarNodoArbol(arbol->der,arbol->p.nombres);
                }
                else///si tiene un hijo a la izq
                {
                    auxIzq=nodoMasDer(arbol->izq);
                    arbol=sobrescribirDatos(arbol,auxIzq);
                    arbol->izq=borrarNodoArbol(arbol->izq,arbol->p.nombres);
                }
            }
        }
        else
        {

            if(strcmpi(nombre,arbol->p.nombres)>0)
            {
                printf("\navanza der");
                arbol->der=borrarNodoArbol(arbol->der,nombre);
            }
            else
            {
                printf("\navanza izq");
                arbol->izq=borrarNodoArbol(arbol->izq,nombre);
            }
        }
    }


    return arbol;
}

nodoArbol* nodoMasIzq(nodoArbol*arbol)///retorna el nodo mas a la izquierda de la derecha
{
    nodoArbol*aux=NULL;
    if(arbol!=NULL)
    {
        if(arbol->izq==NULL)
        {
            aux=arbol;

        }
        else
        {
            aux=nodoMasIzq(arbol->izq);
        }
    }
    return aux;
}
nodoArbol* nodoMasDer(nodoArbol*arbol) ///retorna el nodo mas a la derecha de la izquierda
{
    nodoArbol*aux=NULL;
    if(arbol!=NULL)
    {
        if(arbol->der==NULL)
        {
            aux=arbol;

        }
        else
        {
            aux=nodoMasDer(arbol->der);
        }
    }
    return aux;
}

nodoArbol* sobrescribirDatos(nodoArbol*arbol,nodoArbol*aux)///sobrescribe los datos del nodo eliminado
{
    strcpy(arbol->p.apellido, aux->p.apellido);
    arbol->p.cantArticulos=aux->p.cantArticulos;
    arbol->p.eliminado=aux->p.eliminado;
    arbol->p.id=aux->p.id;
    arbol->p.medioPago=aux->p.medioPago;
    strcpy(arbol->p.nombres, aux->p.nombres);
    arbol->p.tipoCliente=aux->p.tipoCliente;
    return arbol;
}
void pasarPreOrder(nodoArbol *arbol, caja cajas[], int validos)
{
    int i=0;
    if(arbol!=NULL)
    {
        nodo2 *aux=crearNodoLista(arbol->p);
        i=buscarCaja(cajas, arbol->p.medioPago, validos);
        pasarDeArbolToLineaDeCajas(aux, cajas, i);
        pasarPreOrder(arbol->izq, cajas, validos);
        pasarPreOrder(arbol->der, cajas, validos);
    }
}
void pasarInOrder(nodoArbol *arbol, caja cajas[], int validos)
{
    int i=0;
    if(arbol!=NULL)
    {
        pasarInOrder(arbol->izq, cajas, validos);
        nodo2 *aux=crearNodoLista(arbol->p);
        i=buscarCaja(cajas, arbol->p.medioPago, validos);
        pasarDeArbolToLineaDeCajas(aux, cajas, i);
        pasarInOrder(arbol->der, cajas, validos);
    }
}
void pasarPostOrder(nodoArbol *arbol, caja cajas[], int validos)
{
    int i=0;
    if(arbol!=NULL)
    {
        pasarInOrder(arbol->izq, cajas, validos);
        pasarInOrder(arbol->der, cajas, validos);
        nodo2 *aux=crearNodoLista(arbol->p);
        i=buscarCaja(cajas, arbol->p.medioPago, validos);
        pasarDeArbolToLineaDeCajas(aux, cajas, i);
    }
}
void pasarDeArbolToLineaDeCajas(nodo2 *nuevoNodo, caja cajas[6], int i)
{
    fila *auxCaja=&cajas[i].filita;
    int aux = cajas[i].algoritmoPlanificacion;
    switch(aux)
    {
        case 1: /// CAJA SJF
                auxCaja=agregarEnOrden(auxCaja, nuevoNodo);
                cajas[i].cantPersonas=cajas[i].cantPersonas+1;
                break;
        case 2: /// CAJA SRTF
                auxCaja=agregarEnOrden(auxCaja, nuevoNodo);
                cajas[i].cantPersonas=cajas[i].cantPersonas+1;
                break;
        case 3: /// CAJA RR Quantum 5
                agregarFinalFilas(auxCaja, nuevoNodo);
                cajas[i].cantPersonas=cajas[i].cantPersonas+1;
                break;
        case 4: /// CAJA RR Quantum 8
                agregarFinalFilas(auxCaja, nuevoNodo);
                cajas[i].cantPersonas=cajas[i].cantPersonas+1;
                break;
        case 5: /// CAJA FIFO
                agregarFinalFilas(auxCaja, nuevoNodo);
                cajas[i].cantPersonas=cajas[i].cantPersonas+1;
                break;
        case 6: /// CAJA Prioridades no apropiativa
                auxCaja=agregarPorPrioridad(auxCaja, nuevoNodo);
                cajas[i].cantPersonas=cajas[i].cantPersonas+1;
                break;
        }

}






