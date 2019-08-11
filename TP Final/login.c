#include "login.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testigo[2][2]= {{-1,2},{1,-1}};

int cantidadDeRegistros(char archi_usuarios[]) ///Retorna la cantidad de registros que hay en un archivo.
{
    FILE*archi;
    long cant_registros;
    archi=fopen(archi_usuarios,"rb");
    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        cant_registros=ftell(archi)/sizeof(usuario);

    }
    fclose(archi);
    return cant_registros;
}
usuario ingresarDatos(){
    usuario aux;
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(aux.apellido);
    printf("Ingrese un nuevo usuario: ");
    fflush(stdin);
    gets(aux.usuarios);
    return aux;
}
void registrarUsuarios(char archivo_usuarios[])
{
    FILE *file;
    usuario usuarios;
    char password[1][10], aux_user[20], pregunta='s';
    int rta=0, cantLetras=0, cant_registros=0;
    if(file=fopen(archivo_usuarios, "rb")==NULL)
        file=fopen(archivo_usuarios, "wb");
    else
        file=fopen(archivo_usuarios, "ab");
    usuarios=ingresarDatos();
    rta=buscarUsuario(archivo_usuarios, usuarios.usuarios);
    while(rta==1)
    {
        printf("\nEl usuario ya existe por favor ingrese otro.");
        fflush(stdin);
        gets(aux_user);
        rta=buscarUsuario(archivo_usuarios, aux_user);
        if(rta==0)
            strcpy(usuarios.usuarios, aux_user);
    }
    printf("Ingrese contrasenia(MAX. 10 caracteres): ");
    fflush(stdin);
    gets(password);
    cantLetras=saberCantidadLetras(password);
    pasarAnumeros(password, cantLetras, usuarios.pass); //PRIMERO LA PASAMOS A SUS RESPECTIVOS NUMEROS
    encriptar(usuarios.pass); //LUEGO ES ENCRIPTADA PARA LUEGO SER GUARDADA EN EL ARCHIVO
    usuarios.eliminado=0;
    cant_registros=cantidadDeRegistros(archivo_usuarios);
    usuarios.id=cant_registros+1;
    fwrite(&usuarios, sizeof(usuario), 1, file);
    fclose(file);
}
int buscarUsuario(char archivo_usuarios[], char aux_user[])  ///Verifica si el usuario existe en el archivo
{
    FILE *file;
    usuario aux;
    file=fopen(archivo_usuarios,"rb");
    int rta=0;
    if(file!=NULL)
    {
        while(fread(&aux, sizeof(usuario), 1, file)>0 && aux.eliminado==0)
        {
            if(strcmpi(aux.usuarios, aux_user)==0)
            {
                rta++;
            }
        }

    }
    fclose(file);
    return rta;
}
int saberCantidadLetras(char palabra[])   /// retorna la cantidad de letras de ua palabra.
{
    int i=0;
    while(palabra[i]!=0)
    {
        i++;
    }
    return i;
}
void pasarAnumeros(char pass[], int cant_letras, int contra[2][5])   ///pasa la pass ingresada a numero en una matriz de 2x5
{
    int j=0;
    int k=0;
    int i=0;
    while(k<5)
    {
        while(j<2)
        {
            if(i<cant_letras)
            {
                contra[j][k]=numero_letra(pass[i]);
            }
            else
            {
                contra[j][k]=0;
            }
            i++;
            j++;

        }
        k++;
        j=0;
    }
}
int numero_letra(char letra[]) /// Retorna el numero correspondiente a una letra.
{
    char abc[]= {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    int i=0;
    while(i<=36)
    {
        if(letra==abc[i])
        {
            return i;
        }
        i++;
    }
}
void encriptar(int contra[2][5])  ///encripta la contraseña multiplicando por la testigo
{
    int pass[2][5];
    int numero=0;
    int i=0;
    while(i<5)
    {
        numero=testigo[0][0]*contra[0][i];
        numero=numero+testigo[0][1]*contra[1][i];
        pass[0][i]=numero;
        i++;
    }
    i=0;
    while(i<5)
    {
        numero=testigo[1][0]*contra[0][i];
        numero=numero+testigo[1][1]*contra[1][i];
        pass[1][i]=numero;
        i++;
    }
    contra=matrizToMatriz2x5(contra,pass);
}
void desencriptar(int pass[2][5], int contra[2][5]) ///desencripta la contraseña que esta almacenada en el archivo.
{
    int contra_aux[2][5];
    int numero=0;
    int invers[2][2];
    inversa(invers);
    int i=0;
    while(i<5)
    {
        numero=invers[0][0]*pass[0][i];
        numero=numero+invers[0][1]*pass[1][i];
        contra_aux[0][i]=numero;
        i++;
    }
    i=0;
    while(i<5)
    {
        numero=invers[1][0]*pass[0][i];
        numero=numero+invers[1][1]*pass[1][i];
        contra_aux[1][i]=numero;
        i++;
    }
    contra=matrizToMatriz2x5(contra,contra_aux);
}
int matrizToMatriz2x5(int M1[2][5],int M2[2][5])   /// copia una matriz en la otra
{
    int j=0;
    int k=0;
    for(k=0; k<2; k++)
    {
        for(j=0; j<5; j++)
        {
            M1[k][j]=M2[k][j];
        }
    }
    return M1;
}
void inversa(int inversa[2][2])    ///saca la inversa de la matriz testigo.
{
    int determ=0;
    determ=determinante();
    inversa[0][0]=testigo[1][1];
    inversa[1][1]=testigo[0][0];
    inversa[0][1]=testigo[0][1]*-1;
    inversa[1][0]=testigo[1][0]*-1;

    inversa[0][0]=(1/determ)*inversa[0][0];
    inversa[1][1]=(1/determ)*inversa[1][1];
    inversa[0][1]=(1/determ)*inversa[0][1];
    inversa[1][0]=(1/determ)*inversa[1][0];
}
int determinante() /// saca la determinante de la matriz testigo
{
    int rta=0;
    rta=(testigo[0][0]*testigo[1][1])-(testigo[0][1]*testigo[1][0]);
    return rta;
}
int logIn(char archivo_usuarios[]) ///Funcion de ingreso por un el user y el pass
{
    FILE *file;
    usuario aux;
    char aux_user[20];
    char pass[1][20];
    int rtaUser=0, rtaPass=0;
    file=fopen(archivo_usuarios,"rb");
    if(file!=NULL)
    {
        printf("\nIngrese su Usuario:");
        fflush(stdin);
        gets(aux_user);
        rtaUser=buscarUsuario(archivo_usuarios, aux_user);
        if(rtaUser==0)
        {
            while(rtaUser==0)
            {
                system("cls");
                printf("\nEl usuario NO existe por favor ingrese otro:");
                fflush(stdin);
                gets(aux_user);
                rtaUser=buscarUsuario(archivo_usuarios, aux_user);
            }
        }
        printf("\nIngrese pass:");
        fflush(stdin);
        gets(pass);
        rtaPass=buscarContraDeUsuario(archivo_usuarios,aux_user, pass);
        if(rtaPass==0)
        {
            while(rtaPass==0)
            {
                system("cls");
                printf("\nSu contrasenia es incorrecta,por favor vuelva a ingresarla: ");
                fflush(stdin);
                gets(pass);
                rtaPass=buscarContraDeUsuario(archivo_usuarios, aux_user, pass);
            }

        }
        printf("\nUsted se ha logeado con exito.\n\n");
    }
    fclose(file);
    return rtaPass;
}
int buscarContraDeUsuario(char archivo_usuarios[], char aux_user[], char pass[])
{
    FILE *file;
    usuario aux;
    file=fopen(archivo_usuarios,"rb");
    int cant_letras=0, contra[2][5], rta=0;
    char pass_aux[20];
    if(file!=NULL)
    {
        while(fread(&aux, sizeof(usuario), 1, file)>0)
        {
            if(strcmpi(aux_user,aux.usuarios)==0)
            {
                desencriptar(aux.pass,contra);
                cant_letras=cantLetrasMatriz(contra);
                pasarAletras(pass_aux,cant_letras,contra);
                if(strcmpi(pass,pass_aux)==0)
                {
                    rta++;
                }
            }
        }

    }
    fclose(file);
    return rta;
}
int cantLetrasMatriz(int contra[2][5]) ///Retorna la cantidada de caracteres en una matriz 2x5
{
    int j=0;
    int k=0;
    int total=0;
    for(k=0; k<2; k++)
    {
        for(j=0; j<5; j++)
        {
            if(contra[k][j]!=0)
            {
                total++;
            }
        }
    }
    return total;
}
void pasarAletras(char pass[10],int cant_letras,int contra[2][5])    ///una vez desencriptada la contraseña se ultiliza esta funcion para pasarla a letras y compararlas.
{
    int j=0;
    int k=0;
    int i=0;
    char letra;
    while(k<5)
    {
        while(j<2)
        {
            if(i<cant_letras)
            {
                pass[i]=letra_numero(contra[j][k]);
                i++;
            }
            j++;

        }
        k++;
        j=0;
    }
    pass[i]='\0';
}
int letra_numero(int numero) ///Retorna la letra correspondiente a un numero.
{
    int abc_num[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26, 27, 28, 29, 30, 31, 32, 33, 34, 35,36};
    int i=0;
    int letra;
    char abc[]= {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    while(i<=36)
    {
        if(numero==abc_num[i])
        {
            letra = abc[i];
        }
        i++;
    }
    return letra;
}
void mostrarUsuarios(char archivo_usuarios[]){
    FILE *file;
    usuario aux;
    char pass[10];
    file=fopen(archivo_usuarios, "rb");
    if(file!=NULL){
        while(fread(&aux, sizeof(usuario), 1, file)>0 && aux.eliminado==0){
            printf("\nID: %d", aux.id);
            printf("\nNombre: %s", aux.nombre);
            printf("\nApellido: %s", aux.apellido);
            printf("\nUsuario: %s", aux.usuarios);
        }
    }
    else
        printf("No hay usuarios en el sistema.");
    fclose(file);
}

void mostrarUsuariosConEliminado(char archivo_usuarios[]){
    FILE *file;
    usuario aux;
    char pass[10];
    int aux_pass[2][5], i=0, j=0, cantLetras=0;
    file=fopen(archivo_usuarios, "rb");
    if(file!=NULL){
        while(fread(&aux, sizeof(usuario), 1, file)>0 ){
            printf("\nID: %d", aux.id);
            printf("\nNombre: %s", aux.nombre);
            printf("\nApellido: %s", aux.apellido);
            printf("\nUsuario: %s", aux.usuarios);
            printf("\nEliminado: %d", aux.eliminado);
            desencriptar(aux.pass, aux_pass);
            cantLetras=cantLetrasMatriz(aux_pass);
            pasarAletras(pass, cantLetras, aux_pass);
            printf("\nContrasenia:  ");
            puts(pass);
        }
    }
    fclose(file);
}

void eliminarUsuario(char archivo_usuarios[], char auxUsuario[20]){
    FILE *file;
    usuario aux;
    int flag=0;
    file=fopen(archivo_usuarios, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(usuario), 1, file)>0){
                if(strcmp(auxUsuario, aux.usuarios)==0 && aux.eliminado==0){
                    flag=1;
                    aux.eliminado=1;
                    printf("Usted se ha dado de baja exitosamente.");
                }
        }
        if(flag==0) printf("No existe usuario.");
        fseek(file, sizeof(usuario)*(-1), SEEK_CUR);
        fwrite(&aux, sizeof(usuario), 1, file);
    }
    fclose(file);
}
void modificarNombre(char archivo_usuarios[], char auxUsuario[20], char nombre[30])
{
    FILE *file;
    usuario aux;
    int flag=0;
    file=fopen(archivo_usuarios, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(usuario), 1, file)>0){
            if(strcmp(auxUsuario, aux.usuarios) && aux.eliminado==0){
                flag=1;
                strcpy(aux.nombre, nombre);
                printf("Se cambio el nombre exitosamente.");
            }
        }
        if(flag==0) printf("No existe usuario.");
    }
    fseek(file, sizeof(usuario)*(-1), SEEK_CUR);
    fwrite(&aux, sizeof(usuario), 1, file);
    fclose(file);
}
void modificarApellido(char archivo_usuarios[], char auxUsuario[20], char apellido[30])
{
    FILE *file;
    usuario aux;
    int flag=0;
    file=fopen(archivo_usuarios, "r+b");
    if(file!=NULL){
        while(flag==0 && fread(&aux, sizeof(usuario), 1, file)>0){
            if(strcmp(apellido, aux.apellido)==0 && aux.eliminado==0){
                    flag=1;
                    strcpy(aux.apellido,apellido);
                    printf("Se cambio el apellido exitosamente.");
            }
        }
        if(flag==0) printf("No existe usuario.");
    }
    fseek(file, sizeof(usuario)*(-1), SEEK_CUR);
    fwrite(&aux, sizeof(usuario), 1, file);
    fclose(file);
}
int buscarIdUsuario(char archivo_usuarios[]){
    FILE *file;
    usuario aux;
    file=fopen(archivo_usuarios, "rb");
    if(file!=NULL){
        fseek(file, 0, SEEK_CUR);
        fread(&aux, sizeof(usuario), 1, file);
        printf("Usuario: %s", aux.usuarios);
    }
    return 1;
}
