#include <stdio.h>
#include <stdlib.h>
#include "gestionPersonas.h"
#include "login.h"
#include "arboleslib.h"
#include "strings.h"
#include "ADL.h"
#include "filas.h"

char archivo_usuarios[]="usuarios.dat", archivo_personas[]="personas.dat";

int main(int argc, char *argv[])
{
    caja cajas[6];
    char auxUsuario[20], nuevo[20], preguntaCliente, auxUser[30];
    int validos=0, rta=0, tiempoEntrada=0, auxTiempo=0, id=0, switchCajas=0;
    float tiempoProcesamiento=0, tiempoEspera=0;
    nodoArbol *arbol=inicArbol();
    nodo2 *auxNodo=NULL;
    fila *auxFila=&cajas[0].filita;
    persona aux;
    int selected;


    do
    {
        selected = menulog();
        switch(selected)
        {
        case 1:
            system("cls");
            registrarUsuarios(archivo_usuarios);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            logIn(archivo_usuarios);
            int opcion;
            do
            {
                opcion = menu3();
                switch(opcion)
                {
                case 1:
                    system("cls");
                    int selected2;
                    do
                    {
                        selected2 = menuAMBLU();
                        switch(selected2)
                        {
                        case 1:
                            system("cls");
                            registrarUsuarios(archivo_usuarios);
                            system("PAUSE");
                            break;
                        case 2:
                            system("cls");
                            printf("\nIngrese su usuario:");
                            fflush(stdin);
                            gets(auxUsuario);
                            eliminarUsuario(archivo_usuarios,auxUsuario);
                            system("PAUSE");
                            break;
                        case 3:
                            system("cls");
                            int selected3;
                            do
                            {
                                selected3 = menuModificar();
                                switch(selected3)
                                {
                                case 1:
                                    system("cls");
                                    char nombre[30];
                                    printf("\nIngrese su usuario:");
                                    fflush(stdin);
                                    gets(auxUser);
                                    printf("\nIngrese el nuevo nombre:");
                                    fflush(stdin);
                                    gets(nombre);
                                    modificarNombre(archivo_usuarios,auxUser,nombre);
                                    system("PAUSE");
                                    break;
                                case 2:
                                    system("cls");
                                    char ape[30];
                                    printf("\nIngrese su usuario:");
                                    fflush(stdin);
                                    gets(auxUser);
                                    printf("\nIngrese el nuevo apellido:");
                                    fflush(stdin);
                                    gets(ape);
                                    modificarApellido(archivo_usuarios,auxUser,ape);
                                    system("PAUSE");
                                    break;
                                case 0:

                                    break;
                                }

                            }
                            while(selected3!=0);
                        case 4:
                            system("cls");
                            mostrarUsuarios(archivo_usuarios);
                            system("pause");
                            break;
                        case 0:

                            break;
                        }

                    }
                    while(selected2!=0);
                    break;
                case 2:
                    system("cls");
                    ///abml pers
                    int selected8;
                    do
                    {
                        selected8 = menuPersonas();
                        switch(selected8)
                        {
                        case 1:
                            system("cls");
                            cargarPersonas(archivo_personas);

                            system("PAUSE");
                            break;
                        case 2:
                            system("cls");
                            mostrarPersonas(archivo_personas);
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            inicCajas(cajas);
                            noVerEstaFuncion(cajas);
                            arbol=pasarArchivoToArbol(archivo_personas, arbol);
                            int selected5;
                            do
                            {
                                selected5 = menuPasaje();
                                int selected4;
                                switch(selected5)
                                {
                                case 1:
                                    system("cls");
                                    //preorder
                                    int selected7;
                                    do
                                    {
                                        pasarPreOrder(arbol, cajas, 6);

                                        selected7=menuPocesamiento();
                                        switch(selected7)
                                        {
                                        case 1:
                                            system("color 0a"); ///SJF
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 0);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarFifo(cajas, 0, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 0);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[0].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[0].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 0);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 2:
                                            system("color 0a");///SRTF
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 1);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarSRTF(cajas, 1, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 1);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[1].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[1].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 1);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 3:
                                            system("color 0a");///RRQ5
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 2);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarRoundRobin(cajas, 2, 5, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 2);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[2].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[2].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 2);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 4:
                                            system("color 0a");///RRQ8
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 3);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarRoundRobin(cajas, 3, 8, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 3);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[3].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[3].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 3);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 5:
                                            system("color 0a");///FIFO
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 4);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarFifo(cajas, 4, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 4);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[4].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[4].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 4);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 6:
                                            system("color 0a");///PRIORIDADES NO AP
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 5);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarPrioridades(cajas, 5, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 5);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[5].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[5].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 5);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 0:
                                            break;
                                        }
                                    }
                                    while(selected7!=0);

                                    system("PAUSE");
                                    break;
                                case 2:
                                    system("cls");
                                    //inorder
                                    int selected9;
                                    do
                                    {
                                        pasarInOrder(arbol, cajas, 6);

                                        selected9=menuPocesamiento();
                                        switch(selected9)
                                        {
                                        case 1:
                                            system("color 0a"); ///SJF
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 0);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarFifo(cajas, 0, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 0);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[0].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[0].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 0);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 2:
                                            system("color 0a");///SRTF
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 1);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarSRTF(cajas, 1, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 1);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[1].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[1].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 1);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 3:
                                            system("color 0a");///RRQ5
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 2);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarRoundRobin(cajas, 2, 5, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 2);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[2].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[2].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 2);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 4:
                                            system("color 0a");///RRQ8
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 3);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarRoundRobin(cajas, 3, 8, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 3);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[3].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[3].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 3);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 5:
                                            system("color 0a");///FIFO
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 4);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarFifo(cajas, 4, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 4);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[4].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[4].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 4);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 6:
                                            system("color 0a");///PRIORIDADES NO AP
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 5);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarPrioridades(cajas, 5, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 5);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[5].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[5].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 5);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 0:
                                            break;
                                        }
                                    }
                                    while(selected9!=0);
                                    break;
                                case 3:
                                    system("cls");
                                    //postorder
                                    int selected10;
                                    do
                                    {
                                        pasarPostOrder(arbol, cajas, 6);

                                        selected10=menuPocesamiento();
                                        switch(selected10)
                                        {
                                        case 1:
                                            system("color 0a"); ///SJF
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 0);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarFifo(cajas, 0, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 0);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[0].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[0].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 0);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 2:
                                            system("color 0a");///SRTF
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 1);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarSRTF(cajas, 1, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 1);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[1].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[1].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 1);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 3:
                                            system("color 0a");///RRQ5
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 2);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarRoundRobin(cajas, 2, 5, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 2);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[2].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[2].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 2);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 4:
                                            system("color 0a");///RRQ8
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 3);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarRoundRobin(cajas, 3, 8, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 3);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[3].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[3].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 3);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 5:
                                            system("color 0a");///FIFO
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 4);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarFifo(cajas, 4, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 4);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[4].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[4].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 4);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 6:
                                            system("color 0a");///PRIORIDADES NO AP
                                            do
                                            {
                                                selected4 = menuCajas();
                                                switch(selected4)
                                                {
                                                    case 1:
                                                            system("cls");
                                                            mostrarCaja(cajas, 5);
                                                            system("pause");
                                                            break;
                                                    case 2:
                                                            system("cls");
                                                            printf("Quiere ingresar un cliente en algun tiempo determinado?: ");
                                                            fflush(stdin);
                                                            scanf("%c", &preguntaCliente);
                                                            if(preguntaCliente=='s'){
                                                                printf("Ingrese tiempo: ");
                                                                fflush(stdin);
                                                                scanf("%d", &tiempoEntrada);
                                                                aux=cargarUnaPersona(archivo_personas, aux);
                                                                aux.id=1+cantidadDeRegistros(archivo_personas);
                                                                auxNodo=crearNodoLista(aux);
                                                            }
                                                            procesarPrioridades(cajas, 5, tiempoEntrada, auxNodo);
                                                            rta=contarClientesCaja(cajas, 5);
                                                            tiempoEspera=calcularTiempoEspera(&cajas[5].filita, rta);
                                                            printf("\nTiempo de espera promedio: %.2f", tiempoEspera);
                                                            tiempoProcesamiento=calcularTiempoProceso(&cajas[5].filita, rta);
                                                            printf("\nTiempo de procesamiento promedio: %2.f", tiempoProcesamiento);
                                                            system("PAUSE");
                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            vaciarCaja(cajas, 5);
                                                            printf("Caja vaciada exitosamente.");
                                                            system("pause");
                                                            break;
                                                            case 0:

                                                            break;
                                                }
                                            }while(selected4!=0);
                                            break;
                                        case 0:
                                            break;
                                        }
                                    }
                                    while(selected10!=0);
                                    break;
                                case 0:

                                    break;
                                }

                            }
                            while(selected5!=0);
                            system("PAUSE");
                            break;

                        case 0:

                            break;
                        }

                    }
                    while(selected8!=0);
                    system("PAUSE");
                    break;
                case 0:

                    break;
                }

            }
            while(opcion!=0);



            break;
        case 0:
            printf("\n\nGoodBye! :)\n");

            break;
        }

    }
    while(selected!=0);

    system("PAUSE");
    return 0;
}
///----------------------------------------------------------------------------------------------------------

int menuCajas()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nGESTION CAJAS");
    printf("\n-----------");
    printf("\n1-Mostrar Caja");
    printf("\n2-Procesar Caja");
    printf("\n3-Vaciar Caja");
    printf("\n0-BACK");
    printf("\n\nElija una opcion: ");
    scanf("%d",&input);
    return input;
}

///-----------------------------------------------------------------------------------------------------------------------


int menulog()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Sign up");
    printf("\n2-Login");
    printf("\n0-QUIT");
    printf("\n\nChoose a option: ");
    scanf("%d",&input);
    return input;
}

int menu3()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-ABML Users");
    printf("\n2-ABML Clients");
    printf("\n0-BACK");
    printf("\n\nChoose an option: ");
    scanf("%d",&input);
    return input;
}

int menuAMBLU()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nABML USERS");
    printf("\n-----------");
    printf("\n1-Sign up");
    printf("\n2-Eliminar usuario");
    printf("\n3-Modificar");
    printf("\n4-Listado");
    printf("\n0-BACK");
    printf("\n\nChoose a option: ");
    scanf("%d",&input);
    return input;
}

int menuModificar()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1-Nombre");
    printf("\n2-Apellido");
    printf("\n0-BACK");
    printf("\n\nQue desea modificar? ");
    scanf("%d",&input);
    return input;
}

int menuPersonas()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nGESTION PERSONAS");
    printf("\n-----------");
    printf("\n1-Cargar personas");
    printf("\n2-Mostrar personas");
    printf("\n3-Pasar personas a cajas");
    printf("\n0-BACK");
    printf("\n\nElija una opcion: ");
    scanf("%d",&input);
    return input;
}

int menuPasaje()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nPasajes");
    printf("\n-----------");
    printf("\n1-PREORDER");
    printf("\n2-INORDER");
    printf("\n3-POSTORDER");
    printf("\n0-BACK");
    printf("\n\nElija una opcion: ");
    scanf("%d",&input);
    return input;
}
int menuPocesamiento()
{
    system("color 0a");
    int input;
    system("cls");
    printf("\nLABORATORY 2 FINAL TP");
    printf("\n----------");
    printf("\nElija una caja: ");
    printf("\n-----------");
    printf("\n1-SJF");
    printf("\n2-SRTF");
    printf("\n3-RR Q5");
    printf("\n4-RR Q8");
    printf("\n5-FIFO");
    printf("\n6-PRIORIDADES NO AP");
    printf("\n0-BACK");
    printf("\n\nElija una opcion: ");
    scanf("%d",&input);
    return input;
}




