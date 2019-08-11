#ifndef GESTIONPERSONAS_H_INCLUDED
#define GESTIONPERSONAS_H_INCLUDED

typedef struct
{
    int id;
    char apellido[30];
    char nombres[40];
    int tipoCliente; /// Prioridad 1: Embarazada, 2: Jubilado, 3: Comun
    int medioPago; /// 1: Efectivo, 2: Tarjeta, 3: Todos
    int cantArticulos; /// *** Tiempo de ejecucion
    int tiempoEspera; /// *** Tiempo de respuesta
    int tiempoProcesado; /// *** Tiempo procesado en caja
    int eliminado; /// 1: Eliminado, 0; Activo
}persona;

int cantRegistros(char archivo_personas[]);
void cargarPersonas(char archivo_personas[]);
persona cargarUnaPersona(char archivo_personas[], persona personas);
void eliminarPersona(char archivo_personas[], int id);
void modificarNombreP(char archivo_personas[],  int id, char nombre[30]);
void modificarApellidoP(char archivo_personas[],  int id, char apellido[30]);
void modificarTipoPago(char archivo_personas[],  int id, int tipoPago);
void modificarArticulos(char archivo_personas[],  int id, int cantidadArticulos);
void mostrarPersonas(char archivo_personas[]);

#endif // GESTIONPERSONAS_H_INCLUDED
