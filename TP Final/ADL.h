#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED
#include "filas.h"

typedef struct
{
        int nro_de_caja;
        char nombreCajero[40];
        int tipo_pago;                 //  1 efectivo, 2 crédito o débito, 3 todos
        int abiertaOcerrada;
        int algoritmoPlanificacion;  // debe informar que tipo de alg. de planificación utiliza la caja
        int cantPersonas;
        fila filita ;
} caja;

int buscarCaja(caja adl[], int tipodepago, int validos);
int buscarCajaMenosGente(caja adl[], int tipoPago, int validos);
int asignarCaja(caja adl[], int tipoPago, int validos);
void abrirCaja(caja adl[]);
void cerrarCaja(caja adl[],int validos);
void abrirOcerrarCaja(caja adl[],int validos);
int buscarCajaPorNumero(caja adl[],int nro_de_caja,int validos);
void mostrarCaja(caja adl[],int validos);
void modularizar(caja adl[6], int i);
void inicCajas(caja adl[6]);
void noVerEstaFuncion(caja adl[6]);
void procesarFifo(caja cajas[],int i,int tiempoDeEntrada,nodo2* nuevoNodo);
void procesarPrioridades(caja cajas[],int i,int tiempoDeEntrada,nodo2 *nuevoNodo);
void procesarRoundRobin(caja cajas[],int i, int quantum, int tiempoDeEntrada,nodo2* nuevoNodo);
void procesarSRTF(caja cajas[],int i,int tiempoDeEntrada,nodo2 *nuevoNodo);
float calcularTiempoProceso(fila *fila1,int cant_clientes);
float calcularTiempoEspera(fila *fila1, int cant_clientes);
void vaciarCaja(caja cajas[], int i);
nodo2 *aumentarTiempo(nodo2 *lista);
int contarClientesCaja(caja cajas[],int i);





#endif // ADL_H_INCLUDED
