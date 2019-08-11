#include "gestionPersonas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cantRegistros(char archivo_personas[]){
    FILE *file;
    long cantRegistros;
    file=fopen(archivo_personas, "rb");
    if(file!=NULL){
        fseek(file, 0, SEEK_END);
        cantRegistros=ftell(file)/sizeof(persona);
    }
    fclose(file);
    return cantRegistros;
}
void cargarPersonas(char archivo_personas[]){
    FILE *file;
    persona personas;
    int cantidadRegistros=0;
    char answr='s';
    while(answr=='s'){
        if(file=fopen(archivo_personas, "rb")==NULL)
            file=fopen(archivo_personas, "wb");
        else
            file=fopen(archivo_personas, "ab");
        personas=cargarUnaPersona(archivo_personas, personas);
        cantidadRegistros=cantRegistros(archivo_personas);
        personas.id=cantidadRegistros+1;
        fwrite(&personas, sizeof(persona), 1, file);
        printf("\nQuiere seguir ingresando clientes?: ");
        fflush(stdin);
        scanf("%c", &answr);
        fclose(file);
    }

}
persona cargarUnaPersona(char archivo_personas[], persona personas){
    printf("Ingrese nombre del cliente: ");
    fflush(stdin);
    gets(personas.nombres);
    printf("Ingrese apellido del cliente: ");
    fflush(stdin);
    gets(personas.apellido);
    printf("Ingrese tipo de cliente(1:Embarazada, 2:Jubilado, 3:Comun): ");
    fflush(stdin);
    scanf("%d", &personas.tipoCliente);
    printf("Ingrese medio de pago(1:Efectivo, 2:Tarjeta, 3:Todos): ");
    fflush(stdin);
    scanf("%d", &personas.medioPago);
    printf("Ingrese cantidad de articulos: ");
    fflush(stdin);
    scanf("%d", &personas.cantArticulos);
    personas.tiempoEspera=0;
    personas.tiempoProcesado=0;
    personas.eliminado=0;

    return personas;
}
void eliminarPersona(char archivo_personas[], int id){
    FILE *file;
    persona aux;
    int flag=0;
    file=fopen(archivo_personas, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(persona), 1, file)>0){
            if(aux.id==id){
                flag=1;
                aux.eliminado=1;
                fseek(file, sizeof(persona)*(-1), SEEK_CUR);
                fwrite(&aux, sizeof(persona), 1, file);
            }
        }

    }
    fclose(file);
}
void modificarNombreP(char archivo_personas[], int id, char nombre[30])
{
    FILE *file;
    persona aux;
    int flag=0;
    file=fopen(archivo_personas, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(persona), 1, file)>0 ){
            if(aux.id==id){
                flag=1;
                strcpy(aux.nombres, nombre);
            }
        }
    }
    fseek(file, sizeof(persona)*(-1), SEEK_CUR);
    fwrite(&aux, sizeof(persona), 1, file);
    fclose(file);
}
void modificarApellidoP(char archivo_personas[], int id, char apellido[30])
{
    FILE *file;
    persona aux;
    int flag=0;
    file=fopen(archivo_personas, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(persona), 1, file)>0){
            if(aux.id==id){
                flag=1;
                strcpy(aux.apellido, apellido);
            }
        }
    }
    fseek(file, sizeof(persona)*(-1), SEEK_CUR);
    fwrite(&aux, sizeof(persona), 1, file);
    fclose(file);
}
void modificarTipoPago(char archivo_personas[], int id, int tipoPago)
{
    FILE *file;
    persona aux;
    int flag=0;
    file=fopen(archivo_personas, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(persona), 1, file)>0){
            if(aux.id==id){
                flag=1;
                aux.medioPago=tipoPago;
            }
        }
    }
    fseek(file, sizeof(persona)*(-1), SEEK_CUR);
    fwrite(&aux, sizeof(persona), 1, file);
    fclose(file);
}
void modificarArticulos(char archivo_personas[], int id, int cantidadArticulos)
{
    FILE *file;
    persona aux;
    int flag=0;
    file=fopen(archivo_personas, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(persona), 1, file)>0){
            if(aux.id==id){
                flag=1;
                aux.cantArticulos=cantidadArticulos;
            }
        }
    }
    fseek(file, sizeof(persona)*(-1), SEEK_CUR);
    fwrite(&aux, sizeof(persona), 1, file);
    fclose(file);
}
void mostrarPersonas(char archivo_personas[]){
    FILE *file;
    persona aux;
    char pass[10];
    file=fopen(archivo_personas, "rb");
    if(file!=NULL){
        while(fread(&aux, sizeof(persona), 1, file)>0 && aux.eliminado==0){
            printf("\nID: %d", aux.id);
            printf("\nNombre: %s", aux.nombres);
            printf("\nApellido: %s", aux.apellido);
            printf("\nTipo de cliente: %d", aux.tipoCliente);
            printf("\nMedio de pago: %d", aux.medioPago);
            printf("\nCantidad de articulos: %d", aux.cantArticulos);
            printf("\nEliminado: %d\n", aux.eliminado);
        }
    }
    else
        printf("No hay personas en el sistema.");
    fclose(file);
}
