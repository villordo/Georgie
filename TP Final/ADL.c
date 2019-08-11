#include "ADL.h"
#include "filas.h"
#include <string.h>


int buscarCaja(caja adl[],int tipodepago,int validos)
{
    int rta=-1, i=0;
    while(i<validos && rta==-1){
        rta=buscarCajaMenosGente(adl, tipodepago, validos);
        i++;
    }
    if(rta==-1){
        i=0;
        while(i<validos && rta==-1){
            rta=buscarCajaMenosGente(adl, 3, validos);
            i++;
        }
    }
    return rta;
}
int buscarCajaMenosGente(caja adl[], int tipoPago, int validos){
    int i=0, aux=0;
    aux=asignarCaja(adl, tipoPago, validos);
    for(i=0;i<validos;i++){
        if(adl[i].cantPersonas < adl[aux].cantPersonas && adl[i].abiertaOcerrada==1 && adl[i].tipo_pago==adl[aux].tipo_pago ||adl[i].cantPersonas < adl[aux].cantPersonas && adl[i].abiertaOcerrada==1 && adl[i].tipo_pago==3) aux=i;
    }
    return aux;
}
int asignarCaja(caja adl[], int tipoPago, int validos){
    int i=0, rta=-1;
    while(i<validos && rta==-1){
        if(adl[i].abiertaOcerrada==1 && adl[i].tipo_pago==tipoPago) rta=i;
        else
        i++;
    }
    return rta;
}
int buscarCajaPorNumero(caja adl[],int nro_de_caja,int validos)
{
    int rta=-1;
    int i=0;
    if(adl[i].abiertaOcerrada==1)
    {
        while((i<validos)&& rta==-1)
        {
            if(nro_de_caja==adl[i].nro_de_caja)
            {
                rta=i;
            }
            i++;
        }
    }
    return rta;
}
void abrirOcerrarCaja(caja adl[],int validos)
{
    int opcion;
    printf("\nDesea abrir o cerrar la caja?(1: Cerrar, 2: Abrir): ");
    fflush(stdin);
    scanf("%d",&opcion);
    if(opcion==1)
    {
        cerrarCaja(adl,validos);
    }
    else
    {
        abrirCaja(adl);
    }

}
void cerrarCaja(caja adl[],int validos)
{
    int cajon=0,pos=0;
    printf("\nIngrese la Nro de caja a cerrar:");
    fflush(stdin);
    scanf("%d",&cajon);
    if(filaVacia(&adl[cajon].filita)==0)
    {
        pos=buscarCajaPorNumero(adl,cajon,validos);
        adl[pos].abiertaOcerrada=0;
        printf("\nLa caja %d se cerro satifactoriamente.\n",cajon);
    }
    else
    {
        printf("\nHay clientes en la caja no puede cerrarse.\n");
    }
}
void abrirCaja(caja adl[])
{
    int cajon=0;
    printf("\nIngrese la Nro de caja que desea abrir:");
    fflush(stdin);
    scanf("%d",&cajon);
    if(adl[cajon].abiertaOcerrada==1)
    {
        printf("\nLa caja ya se encuentra abierta.");
    }
    else
    {
        adl[cajon].abiertaOcerrada=1;
        printf("\nCaja %d abierta satifactoriamente.",cajon);
    }

}
void mostrarCaja(caja adl[], int i)
{
    printf("///---------------");
    modularizar(adl, i);
    mostrarFila(&adl[i].filita);
    printf("\n\n///---------------\n\n");
}
void modularizar(caja adl[], int i)
{
    printf("\n\nDATOS CAJA.");
    printf("\nNro de caja: %d", adl[i].nro_de_caja);
    printf("\nTipo de pago: %d", adl[i].tipo_pago);
    printf("\nAlgoritmo de planificacion: %d", adl[i].algoritmoPlanificacion);
    printf("\nCajero: %s", adl[i].nombreCajero);
    printf("\nCantidad de personas: %d", adl[i].cantPersonas);
}
void inicCajas(caja adl[6]){
    int i=0;
    for(i=0;i<6;i++)
    {
        adl[i].cantPersonas=0;
        fila auxCaja=adl[i].filita;
        inicFila(&auxCaja);
        adl[i].filita=auxCaja;
    }
}
void noVerEstaFuncion(caja adl[])
{

    adl[0].nro_de_caja=1;
    strcpy(&adl[0].nombreCajero,"Leito");
    adl[0].tipo_pago=1;
    adl[0].abiertaOcerrada=1;
    adl[0].algoritmoPlanificacion=1;

    adl[1].nro_de_caja=2;
    strcpy(&adl[1].nombreCajero,"Tommy");
    adl[1].tipo_pago=2;
    adl[1].abiertaOcerrada=1;
    adl[1].algoritmoPlanificacion=2;

    adl[2].nro_de_caja=3;
    strcpy(&adl[2].nombreCajero,"Cork");
    adl[2].tipo_pago=3;
    adl[2].abiertaOcerrada=1;
    adl[2].algoritmoPlanificacion=1;

    adl[3].nro_de_caja=4;
    strcpy(&adl[3].nombreCajero,"Doush");
    adl[3].tipo_pago=3;
    adl[3].abiertaOcerrada=1;
    adl[3].algoritmoPlanificacion=3;

    adl[4].nro_de_caja=5;
    strcpy(&adl[4].nombreCajero,"Inay");
    adl[4].tipo_pago=3;
    adl[4].abiertaOcerrada=1;
    adl[4].algoritmoPlanificacion=4;

    adl[5].nro_de_caja=6;
    strcpy(&adl[5].nombreCajero,"Mudo");
    adl[5].tipo_pago=3;
    adl[5].abiertaOcerrada=1;
    adl[5].algoritmoPlanificacion=6;
}
void procesarFifo(caja cajas[],int i,int tiempoDeEntrada,nodo2 *nuevoNodo)
{
    fila *fila1=&cajas[i].filita;
    nodo2 *aux=extraer(fila1);
    int tiempo=0;
    while(aux!=NULL && aux->p.cantArticulos>0)
    {
        while(aux->p.cantArticulos>0)
        {
            if(tiempo==tiempoDeEntrada)
                if(nuevoNodo!=NULL) agregarFinalFilas(fila1,nuevoNodo);
            tiempo++;
            printf("Cliente siendo atendido: \n");
            aux->p.cantArticulos=aux->p.cantArticulos-1;
            aux->p.tiempoProcesado=aux->p.tiempoProcesado+1;
            recorrerYmostrar(aux);
            printf("Clientes en espera: \n");
            fila1->cabeza=aumentarTiempo(fila1->cabeza);
            modularizar(cajas, i);
            mostrarFila(fila1);
            system("pause");
            system("cls");
        }
        agregarFinalFilas(fila1, aux);
        cajas[i].cantPersonas++;
        if((fila1->cabeza)->p.cantArticulos>0){
            aux=extraer(fila1);
            cajas[i].cantPersonas--;
        }
    }
}
void procesarPrioridades(caja cajas[], int i, int tiempoDeEntrada, nodo2 *nuevoNodo)
{
    fila *fila1=&cajas[i].filita;
    nodo2 *aux=extraer(fila1);
    int tiempo=0;
    while(aux!=NULL && aux->p.cantArticulos>0)
    {
        while(aux->p.cantArticulos>0)
        {
            if(tiempo==tiempoDeEntrada)
                if(nuevoNodo!=NULL) agregarPorPrioridad(fila1,nuevoNodo);
            tiempo++;
            printf("Cliente siendo atendido: \n");
            aux->p.cantArticulos=aux->p.cantArticulos-1;
            aux->p.tiempoProcesado=aux->p.tiempoProcesado+1;
            recorrerYmostrar(aux);
            printf("Clientes en espera: \n");
            fila1->cabeza=aumentarTiempo(fila1->cabeza);
            modularizar(cajas, i);
            mostrarFila(fila1);
            system("pause");
            system("cls");
        }
        agregarFinalFilas(fila1, aux);
        cajas[i].cantPersonas++;
        if((fila1->cabeza)->p.cantArticulos>0){
            aux=extraer(fila1);
            cajas[i].cantPersonas--;
        }
    }
}
void procesarRoundRobin(caja cajas[], int i, int quantum,int tiempoDeEntrada,nodo2 *nuevoNodo)
{
    int auxQuantum=0, tiempo=0, rta=0;
    fila *fila1=&cajas[i].filita;
    fila *auxFila;
    nodo2 *aux=extraer(fila1);
    while(aux!=NULL && aux->p.cantArticulos>0)
    {
        while(auxQuantum<quantum && aux->p.cantArticulos>0)
        {
            if(tiempo==tiempoDeEntrada)
                if(nuevoNodo!=NULL) agregarFinalFilas(fila1,nuevoNodo);
            tiempo++;
            auxQuantum++;
            printf("Cliente siendo atendido: \n");
            aux->p.cantArticulos=aux->p.cantArticulos-1;
            aux->p.tiempoProcesado=aux->p.tiempoProcesado+1;
            recorrerYmostrar(aux);
            printf("Clientes en espera: \n");
            fila1->cabeza=aumentarTiempo(fila1->cabeza);
            modularizar(cajas, i);
            mostrarFila(fila1);
            system("pause");
            system("cls");
        }
        auxQuantum=0;
        if(aux->p.cantArticulos>0){
            agregarFinalFilas(fila1, aux);
            cajas[i].cantPersonas++;
        }
        /*else{
            agregarFinalFilas(&auxFila, aux);
        }*/
        aux=extraer(fila1);
        cajas[i].cantPersonas--;

    /*while(auxFila!=NULL){
        agregarFinalFilas(fila1, extraer(&auxFila));
    }*/
    }
}
void procesarSRTF(caja cajas[],int i,int tiempoDeEntrada,nodo2 *nuevoNodo){
    fila *fila1=&cajas[i].filita;
    nodo2 *aux=extraer(fila1);
    int tiempo=0;
    while(aux!=NULL && aux->p.cantArticulos>0)
    {
        while(aux->p.cantArticulos>0)
        {
            if(tiempo==tiempoDeEntrada && nuevoNodo!=NULL){
                if(nuevoNodo->p.cantArticulos < aux->p.cantArticulos){
                    fila1=agregarEnOrden(fila1, aux);
                    aux=nuevoNodo;
                }
                else
                    fila1=agregarEnOrden(fila1, nuevoNodo);
            }
            tiempo++;
            printf("\nCliente siendo atendido: \n\n");
            aux->p.cantArticulos=aux->p.cantArticulos-1;
            aux->p.tiempoProcesado=aux->p.tiempoProcesado+1;
            recorrerYmostrar(aux);
            printf("\n\nClientes en espera: \n\n");
            fila1->cabeza=aumentarTiempo(fila1->cabeza);
            modularizar(cajas, i);
            mostrarFila(fila1);
            system("pause");
            system("cls");
        }
        agregarFinalFilas(fila1, aux);
        cajas[i].cantPersonas++;
        if((fila1->cabeza)->p.cantArticulos>0){
            aux=extraer(fila1);
            cajas[i].cantPersonas--;
        }

    }
}
nodo2 *aumentarTiempo(nodo2 *lista){
    if(lista!=NULL){
            if(lista->p.cantArticulos>0){
                lista->p.tiempoEspera=lista->p.tiempoEspera+1;
                lista->sig=aumentarTiempo(lista->sig);
            }
    }
    return lista;
}
float calcularTiempoProceso(fila *fila1,int cant_clientes)
{
    nodo2 *auxLista=fila1->cabeza;
    float rta=0;
    while(auxLista!=NULL){
        rta=rta+auxLista->p.tiempoProcesado;
        auxLista=auxLista->sig;
    }
    return rta/(float)cant_clientes;
}
float calcularTiempoEspera(fila *fila1, int cant_clientes){
    nodo2 *auxLista=fila1->cabeza;
    float rta=0;
    while(auxLista!=NULL){
        rta=rta+auxLista->p.tiempoEspera;
        auxLista=auxLista->sig;
    }
    return rta/(float)cant_clientes;
}
int contarClientesCaja(caja cajas[],int i)
{
    int contador=0;
    nodo2*aux=(&cajas[i].filita)->cabeza;
    while(aux!=NULL)
    {
        contador++;
        aux=aux->sig;
    }
    return contador;
}
void vaciarCaja(caja cajas[], int i){
    fila *fila1=&cajas[i].filita;
    nodo2 *aux=NULL;
    while(fila1->cabeza!=NULL){
        aux=extraer(fila1);
        free(aux);
        cajas[i].cantPersonas--;
    }
}


