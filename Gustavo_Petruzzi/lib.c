#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "lib.h"



/** \brief inicializa el array de estructuras
 *
 * \param ePelicula* pPelicula puntero del array a inicializar
 * \param int length tamaño maximo del array
 * \return devuelve [-1] si no lo pudo inicializar (pPelicula == NULL o length < 0)
 *         y [0] si esta ok
 */

int initArrayPelicula(ePelicula* pPelicula, int length)
{
    int retorno = -1;
    int i;

    if(pPelicula != NULL && length> 0)
    {
        for(i=0;i<length;i++)
        {
            pPelicula[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}



/** \brief inicializa el array de estructuras
 *
 * \param eDirector* pDirector puntero del array a inicializar
 * \param int length tamaño maximo del array
 * \return devuelve [-1] si no lo pudo inicializar (pDirector == NULL o length < 0)
 *         y [0] si esta ok
 */

int initArrayDirectores(eDirector* pDirector, int length)
{
    int retorno = -1;
    int i;

    if(pDirector != NULL && length> 0)
    {
        for(i=0;i<length;i++)
        {
            pDirector[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief crea un menu segun los parametros pasados por el usuario
 *
 * \param char textomenu[] Es la cadena que sirve como menu a ser mostrado
 * \param char min valor minimo que puede tomar el menu
 * \param char min valor maximo que puede tomar el menu
 * \return la opcion elegida por el usuario segun los parametros min y max
 *
 */



char mostrarMenu( char textomenu[], char min, char max )
{
    char opcion ='|';
    int flagPrimera = 1;


    do
    {
        if((opcion < min || opcion > max) && flagPrimera != 1)
        {
            printf("ERROR: reingrese\n");
        }
        printf("%s", textomenu);
        fflush(stdin);
        scanf("%c",&opcion);
        flagPrimera = 0;
    }while(opcion < min || opcion > max);
    return opcion;
}


/**
 * Obtiene el primer indice libre del array.
 * @param pPelicula el array se pasa como parametro.
 * @param length la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibrePelicula(ePelicula* pPelicula,int length)
{
    int index = -1;
    int i;
    if(pPelicula != NULL && length> 0)
    {


        for(i= 0; i<length; i++)
        {
            if(pPelicula[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}


/**
 * Obtiene el primer indice libre del array.
 * @param pDirector el array se pasa como parametro.
 * @param length la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibreDirector(eDirector* pDirector,int length)
{
    int index = -1;
    int i;

    if(pDirector != NULL && length> 0)
    {


        for(i= 0; i<length; i++)
        {
            if(pDirector[i].isEmpty == 1)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}


/** \brief busca en el array lo pasado por parametro
 *
 * \param  lista[]
 * \param int length
 * \param char nick[]
 * \return devuelve el indice donde lo encontro o [-1] si no lo encontro
 *
 */
int buscarPorId(ePelicula* pPelicula, int length, int idPelicula)
{
    int i;
    int index = -1;
    if(pPelicula != NULL && length> 0)
    {
        for(i=0;i<length; i++)
        {
            if(pPelicula[i].isEmpty == 0)
            {
                if(pPelicula[i].idPelicula == idPelicula)
                {
                    index = i;
                    break;
                }
            }
        }
    }
    return index;
}
int buscarPorIdDirector(eDirector* pDirector, int length, int idDirector)
{
    int i;
    int index = -1;
    if(pDirector != NULL && length> 0)
    {
        for(i=0;i<length; i++)
        {
            if(pDirector[i].isEmpty == 0)
            {
                if(pDirector[i].idDirector == idDirector)
                {
                    index = i;
                    break;
                }
            }
        }
    }
    return index;
}
void pedirDatosPelicula(ePelicula* pPelicula, int length,eDirector* pDirector, int lengthDirector, char* titulo,int* anio, char* nacionalidad, int* idDirector, int* idPelicula, int pedirIdPelicula)
{
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;

    int auxIndice;
    int auxInt;
    if(pPelicula != NULL && length> 0)
    {
        do
        {
            auxInt = getString(auxTitulo, "Ingrese el titulo: ", "ERROR: Maximo 50 caracteres\n", 2, 51);
        }while(auxInt!=0);
        strcpy(titulo, auxTitulo);
        system("cls");

        do
        {
            auxInt = getInt(&auxAnio, "Ingrese el anio de la pelicula: ", "ERROR: valido entre 1800 y 2016 \n", 1799, 2017);
        }while(auxInt!=0);
        *anio = auxAnio;
        system("cls");

        do
        {
            auxInt = getString(auxNacionalidad, "Ingrese la nacionalidad: ", "ERROR: Maximo 50 caracteres\n", 2, 51);
        }while(auxInt!=0);
        strcpy(nacionalidad, auxNacionalidad);
        system("cls");

        do
        {
            auxInt = getInt(&auxIdDirector, "Ingrese el Id del director: ", "ERROR: valido entre 1800 y 2016 \n", 0, 501);
            auxIndice = buscarPorIdDirector(pDirector,lengthDirector, auxIdDirector);
            if(auxIndice !=-1)
            {

            }
            else
            {
                printf("Ya existe un ID con ese director");
            }
        }while(auxInt!=0);
        *idDirector = auxIdDirector;
        system("cls");

        if(pedirIdPelicula)
        {
            do
            {
                auxInt = getInt(&auxIdPelicula,"Ingrese el id de la pelicua: ", "ERROR: valido solo entre 1 y 1000\n", 0,1001);
                auxIndice = buscarPorId(pPelicula, length, auxIdPelicula);
                if(auxIndice == -1)
                {

                }
                else
                {
                    printf("Ya existe ese ID de pelicula!\n");
                    auxInt = -1;
                }
            }while(auxInt!=0);
            *idPelicula = auxIdPelicula;
            system("cls");
        }
    }
}




/** \brief carga los datos  en variable de la estructura
 *

 * \param char auxTitulo[] dato solicitado al usuario
 * \param int auxAnio dato solicitado al usuario
 * \param char auxNacionalidad[] dato solicitado al usuario
 * \param auxIdDirector dato solicitado al usuario
 * \return devuelve una variable eUsuario cargada
 *
 */


ePelicula cargarPelicula(char auxTitulo[],int auxAnio, char auxNacionalidad[], int auxIdDirector, int auxIdPelicula)
{
    ePelicula auxPelicula;

    strcpy(auxPelicula.titulo, auxTitulo);
    auxPelicula.anio = auxAnio;
    strcpy(auxPelicula.nacionalidad, auxNacionalidad);
    auxPelicula.idDirector = auxIdDirector;
    auxPelicula.idPelicula = auxIdPelicula;
    auxPelicula.isEmpty = 0;

    return auxPelicula;
}

/** \brief Carga un elemento al array de estructuras
 *
 * \param ePelicula* pPelicula[] lugar donde carga el usuario
 * \param int length tamaño del array

 * \return
 *
 */

void agregarPelicula(ePelicula* pPelicula,int length, eDirector* pDirector, int lengthDirector)
{

    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int indiceLibre;

    if(pPelicula != NULL && length> 0)
    {
        indiceLibre = obtenerEspacioLibrePelicula(pPelicula, length);
        if(indiceLibre != -1)
            {
                pedirDatosPelicula(pPelicula, length, pDirector, lengthDirector ,auxTitulo,&auxAnio,auxNacionalidad,&auxIdDirector,&auxIdPelicula, 1);
                pPelicula[indiceLibre] = cargarPelicula(auxTitulo,auxAnio,auxNacionalidad,auxIdDirector,auxIdPelicula);
                printf("Pelicula Cargada!\n");
            }
            else
            {
                printf("No hay mas lugar\n");
            }
    }
    else
    {
        printf("No hay ningun directorio de pelicula!");
    }
}

/** \brief Indica si existe algun elemento cargado
 *
 * \param ePelicula* pPelicula lugar donde va a iterar la funcion
 * \param int length tamaño maximo del array de estructura
 * \return devuelve [1] si el array no tiene ningun producto cargado o
 *         [0] si esta cargado con aunque sea un producto
 */
int isEmptyPelicula(ePelicula* pPelicula, int length)
{
    int i;
    int retorno = 1;
    if(pPelicula != NULL && length> 0)
    {
        for(i= 0; i<length; i++)
        {
            if(pPelicula[i].isEmpty == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    else
    {
        printf("No hay ningun directorio cargado!");
    }
    return retorno;
}


/** \brief Indica si existe algun elemento cargado
 *
 * \param eDirector* pDirector lugar donde va a iterar la funcion
 * \param int length tamaño maximo del array de estructura
 * \return devuelve [1] si el array no tiene ningun producto cargado o
 *         [0] si esta cargado con aunque sea un producto
 */
int isEmptyDirector(eDirector* pDirector, int length)
{
    int i;
    int retorno = 1;
    if(pDirector != NULL && length> 0)
    {
        for(i= 0; i<length; i++)
        {
            if(pDirector[i].isEmpty == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    else
    {
        printf("No hay ningun directorio cargado!");
    }
    return retorno;
}


void modificar(ePelicula* pPelicula,int length, eDirector* pDirector, int lengthDirector)
{
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int indiceLibre;
    int auxInt;

    if(pPelicula != NULL && length> 0)
    {
        auxInt = getInt(&auxIdPelicula, "Ingrese el id de la pelicula a modificar: ", "ERROR: valido entre 1 y 1000", 0, 1001);
        if(auxInt == 0)
        {
            indiceLibre = buscarPorId(pPelicula, length, auxIdPelicula);
            if(indiceLibre!= -1)
            {
                    pedirDatosPelicula(pPelicula, length,pDirector,lengthDirector,auxTitulo, &auxAnio,auxNacionalidad,&auxIdDirector,&auxIdPelicula, 0);
                    pPelicula[indiceLibre] = cargarPelicula(auxTitulo,auxAnio,auxNacionalidad, auxIdDirector, auxIdPelicula);
                    printf("Pelicula modificado!\n");
            }
            else
            {
                printf("No existe Pelicula con ese ID!\n");
            }
        }
    }
    else
    {
        printf("No hay ningun directorio cargado!");
    }
}

void borrar(ePelicula* pPelicula, int length)
{
    int auxIdPelicula;
    int auxInt;
    int indice;

    if(pPelicula != NULL && length> 0)
    {
        auxInt = getInt(&auxIdPelicula, "Ingrese el ID de la pelicula a borrar: ", "ERROR: valido entre 1 y 1000\n", 0, 1001);
        if(auxInt== 0)
        {
            indice = buscarPorId(pPelicula, length, auxIdPelicula);
            if(indice != -1)
            {
                pPelicula[indice].isEmpty = 1;
            }
            else
            {
                printf("No existe ninguna pelicula con ese ID\n!");
            }
        }
    }
    else
    {
        printf("No hay ninguna directorio cargado!");
    }
}



int buscarPorNombre(eDirector* pDirector, int length, char auxNombre[])
{
    int i;
    int index = -1;
    if(pDirector != NULL && length> 0)
    {
        for(i=0;i<length; i++)
        {
            if(pDirector[i].isEmpty == 0)
            {
                if(strcmp(pDirector[i].nombre, auxNombre)== 0)
                {
                    index = i;
                    break;
                }
            }
        }
    }
    return index;
}

void pedirDatosDirector(eDirector* pDirector, int length, char* nombre,char* fechaNacimiento ,char* paisOrigen, int* idDirector)
{
    char auxNombre[50];
    char auxFechaNacimiento[15];
    char auxPaisOrigen[50];
    int auxIdDirector;

    int auxIndice;
    int auxInt;
    if(pDirector != NULL && length> 0)
    {
        do
        {
            auxInt = getName(auxNombre, "Ingrese el nombre del director: ", "ERROR: Maximo 50 caracteres\n", 2, 51);
            auxIndice = buscarPorNombre(pDirector, length, auxNombre);
            if(auxIndice == -1)
            {

            }
            else
            {
                printf("Ya existe ese el nombre de ese director!\n");
                printf("%d", auxIndice);
                auxInt = -1;
            }
        }while(auxInt!=0);
        strcpy(nombre, auxNombre);
        system("cls");

        do
        {
            auxInt = getString(auxFechaNacimiento, "Ingrese la fecha nacimiento: ", "ERROR: Maximo 15 caracteres\n", 2, 15);
        }while(auxInt!=0);
        strcpy(fechaNacimiento, auxFechaNacimiento);
        system("cls");

        do
        {
            auxInt = getString(auxPaisOrigen, "Ingrese pais de origen: ", "ERROR: Maximo 50 caracteres\n", 2, 50);
        }while(auxInt!=0);
        strcpy(paisOrigen, auxPaisOrigen);
        system("cls");

        do
        {
            auxInt = getInt(&auxIdDirector, "Ingrese el Id del director: ", "ERROR: valido entre 1800 y 2016 \n", 0, 501);
            auxIndice = buscarPorIdDirector(pDirector, length, auxIdDirector);
            if(auxIndice == -1)
            {
                printf("ALGO!");
            }
            else
            {
                printf("Ya existe ese ID de director!\n");
                auxInt = -1;
            }
        }while(auxInt!=0);
        *idDirector = auxIdDirector;
        system("cls");

    }
}


eDirector cargarDirector(char auxNombre[],char auxFechaNacimiento[] ,char auxPaisOrigen[], int auxIdDirector)
{
    eDirector auxDirector;

    strcpy(auxDirector.nombre, auxNombre);
    strcpy(auxDirector.fechaNacimiento, auxFechaNacimiento);
    auxDirector.idDirector = auxIdDirector;
    auxDirector.isEmpty = 0;

    return auxDirector;
}

void nuevoDirector(eDirector* pDirector,int length)
{

    char auxNombre[50];
    char auxFechaNacimiento[15];
    char auxPaisOrigen[50];
    int auxIdDirector;

    int indiceLibre;

    if(pDirector != NULL && length> 0)
    {
        indiceLibre = obtenerEspacioLibreDirector(pDirector, length);
        if(indiceLibre != -1)
            {
                pedirDatosDirector(pDirector,length,auxNombre,auxFechaNacimiento,auxPaisOrigen,&auxIdDirector);
                pDirector[indiceLibre] = cargarDirector(auxNombre,auxFechaNacimiento,auxPaisOrigen,auxIdDirector);
                printf("Director Cargado!\n");
            }
            else
            {
                printf("No hay mas lugar\n");
            }
    }
    else
    {
        printf("No hay ningun directorio de pelicula!");
    }
}

void eliminarDirector(eDirector* pDirector, int length)
{
    char auxNombre[50];
    int auxInt;
    int indice;

    if(pDirector != NULL && length> 0)
    {
        auxInt = getName(auxNombre, "Ingrese el nombre del director a borrar: ", "ERROR: Maximo 50 caracteres\n", 0, 1001);
        if(auxInt== 0)
        {
            indice = buscarPorNombre(pDirector, length, auxNombre);
            if(indice != -1)
            {
                pDirector[indice].isEmpty = 1;
            }
            else
            {
                printf("No existe ninguna pelicula con ese ID\n!");
            }
        }
    }
    else
    {
        printf("No hay ninguna directorio cargado!");
    }
}






