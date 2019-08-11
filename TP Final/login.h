#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    char usuarios[20];
    int pass[2][5];
    int eliminado; /// 1: Eliminado, 0: Activo
}usuario;

usuario ingresarDatos();
void registrarUsuarios(char archivo_usuarios[]);
int buscarUsuario(char archivo_usuarios[], char aux_user[30]);
int saberCantidadLetras(char palabra[]);
void pasarAnumeros(char password[], int cantLetras, int pass[2][5]);
int numero_letra(char letra[]);
void encriptar(int contra[2][5]);
void desencriptar(int pass[2][5], int contra[2][5]);
int matrizToMatriz2x5(int M1[2][5],int M2[2][5]);
void inversa(int inversa[2][2]);
int determinante();
int logIn(char archivo_usuarios[]);
int buscarContraDeUsuario(char archivo_usuarios[], char aux_user[], char pass[]);
int cantLetrasMatriz(int contra[2][5]);
void pasarAletras(char pass[10],int cant_letras,int contra[2][5]);
int letra_numero(int numero);
void mostrarUsuarios(char archivo_usuarios[]);
int cantidadDeRegistros(char archi_usuarios[]);
void eliminarUsuario(char archivo_usuarios[], char auxUsuario[20]);
void modificarNombre(char archivo_usuarios[], char auxUsuario[20], char nombre[30]);
void modificarApellido(char archivo_usuarios[], char auxUsuario[20], char apellido[30]);
void mostrarUsuariosConEliminado(char archivo_usuarios[]);


#endif // LOGIN_H_INCLUDED
