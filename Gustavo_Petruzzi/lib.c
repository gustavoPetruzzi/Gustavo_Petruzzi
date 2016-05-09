#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib.h"
#include "input.h"


/** \brief inicializa el array de estructuras
 *
 * \param ePelicula* pPelicula puntero del array a inicializar
 * \param int length tamaño maximo del array
 * \return devuelve [-1] si no lo pudo inicializar (pUsuario == NULL o length < 0)
 *         y [0] si esta ok
 */
int initArrayPeliculas(ePelicula* pPelicula, int length)
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
    else
    {
        printf("No ningun directorio de peliculas!");
    }
    return retorno;
}


/** \brief inicializa el array de estructuras
 *
 * \param ePelicula* pPelicula puntero del array a inicializar
 * \param int length tamaño maximo del array
 * \return devuelve [-1] si no lo pudo inicializar (pUsuario == NULL o length < 0)
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
 * @param lista el array se pasa como parametro.
 * @param length la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibre(ePelicula* pPelicula,int length)
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
    else
    {
        printf("No ningun directorio de peliculas!");
    }

    return index;
}



int buscarIdPelicula(ePelicula* pPelicula, int length, int idPelicula)
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
    else
    {
        printf("No ningun directorio de peliculas!");
    }

    return index;
}

/** \brief le solicita datos al usuario
 *
 * \param lista[] lugar donde recorre los indices
 * \param int lenght tamaño del array
 * \param char* nombre dato pedido al usuario
 * \param char* nick dato pedido al usuario
 * \param char* claveAcceso dato pedido al usuario
 * \param char* email dato pedido al usuario
 * \param int pedirNick si es [1] le pide el nick al usuariom si es [0] no se lo pide
 * \return
 *
 */


void pedirDatosPelicula(ePelicula* pPelicula, int length, char* titulo,int* anio, char* Nacionalidad,int* idDirector, int* idPelicula, int pedirId)
{
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int auxInt;
    int auxIndice;

    if(pPelicula != NULL && length> 0)
    {
        do
        {
            auxInt = getString(auxTitulo, "Ingrese el nombre de la pelicula: ", "ERROR: Maximo 50 caracteres y solo letras\n", 1, 50);
        }while(auxInt!=0);
        strcpy(titulo, auxTitulo);
        system("cls");

        do
        {
            auxInt = getInt(&auxAnio, "Ingrese el anio de la pelicula: ", "ERROR: solo se permite entre 1800 y 2016\n", 1799, 2017);
        }while(auxInt!=0);
        *anio = auxAnio;
        system("cls");

        do
        {
            auxInt = getString(auxNacionalidad, "Ingrese la nacionalidad de la pelicula: ", "ERROR: Maximo 50 caracteres y solo letras\n", 1, 50);
        }while(auxInt!=0);
        strcpy(Nacionalidad, auxNacionalidad);
        system("cls");

        do
        {
            auxInt = getInt(&auxIdDirector, "Ingrese ID del director: ", "ERROR: solo se permite entre 1 y 500\n", 0, 501);
        }while(auxInt!=0);
        *idDirector = auxIdDirector;
        system("cls");


        if(pedirId)
        {

            do
            {
                auxInt = getInt(&auxIdPelicula,"Ingrese el id de la pelicula: ", "ERROR: solo numeros entre 1 y 1000\n", 0,1001);
                auxIndice = buscarIdPelicula(pPelicula, length, auxIdPelicula);
                if(auxIndice == -1)
                {
                    *idPelicula = auxIdPelicula;
                }
                else
                {
                    printf("Ya existe ese ID cargado!\n");
                    printf("%d", auxIndice);
                    auxInt = -1;
                }

            }while(auxInt!=0);

            system("cls");
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }
}


ePelicula cargarPelicula(char auxTitulo[],int auxAnio, char auxNacionalidad[],int auxIdDirector, int auxIdPelicula)
{
    ePelicula auxPelicula;

    strcpy(auxPelicula.titulo, auxTitulo );
    auxPelicula.anio = auxAnio;
    strcpy(auxPelicula.nacionalidad, auxNacionalidad);
    auxPelicula.idDirector = auxAnio;
    auxPelicula.idPelicula = auxIdPelicula;
    auxPelicula.isEmpty = 0;

    return auxPelicula;
}


void agregarPelicula(ePelicula* pPelicula, int length)
{
    int indice;
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;

    if(pPelicula != NULL && length> 0)
    {
        indice =obtenerEspacioLibre(pPelicula, length);
        if(indice!= -1)
        {
            pedirDatosPelicula(pPelicula, length, auxTitulo,&auxAnio, auxNacionalidad, &auxIdDirector, &auxIdPelicula, 1);
            pPelicula[indice] =cargarPelicula(auxTitulo, auxAnio, auxNacionalidad,auxIdDirector, auxIdPelicula);
            printf("Usuario cargado!");
        }
        else
        {
            printf("No hay mas lugar para agregar peliculas!");
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }
}

/** \brief Indica si existe algun producto cargado
 *
 * \param puntero lista[] lugar donde va a iterar la funcion
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
        printf("No ningun directorio de peliculas!");
    }
    return retorno;
}

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
        printf("No ningun directorio de peliculas!");
    }
    return retorno;
}


void modificar(ePelicula* pPelicula, int length)
{
    int indice;
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int auxInt;

    if(pPelicula != NULL && length> 0)
    {
        auxInt = getInt(&auxIdPelicula, "Ingrese el id a buscar", "ERROR: solamente se puede ingresar de 1 a 1000", 0, 1001);
        if(auxInt==0)
        {

            indice = buscarIdPelicula(pPelicula, length,auxIdPelicula);
            if(indice != -1)
            {
                pedirDatosPelicula(pPelicula, length,auxTitulo, &auxAnio, auxNacionalidad,&auxIdDirector, &auxIdPelicula, 0);
                pPelicula[indice] = cargarPelicula(auxTitulo, auxAnio, auxNacionalidad, auxIdDirector, auxIdPelicula);
            }
            else
            {
                printf("No existe ese Id");
            }
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }

}


void borrar(ePelicula* pPelicula, int length)
{
    int auxIdPelicula;
    int auxInt;
    int indice;
    auxInt = getInt(&auxIdPelicula, "Ingrese el ID de la pelicula a borrar: ", "ERROR: solo se permite de 1 a 1000", 0, 1001);
    if(auxInt== 0)
    {
        indice = buscarIdPelicula(pPelicula, length, auxIdPelicula);
        if(indice != -1)
        {
            pPelicula[indice].isEmpty = 1;
        }
        else
        {
            printf("No existe ningun producto con ese codigo\n!");
        }
    }
}

int buscarNombreDirector(eDirector* pDirector, int length, char nombre[])
{
    int i;
    int index = -1;
    if(pDirector != NULL && length> 0)
    {
        for(i=0;i<length; i++)
        {
            if(pDirector[i].isEmpty == 0)
            {

                if(strcmp(pDirector[i].nombre,nombre) == 0)
                {
                    index = i;
                    break;
                }
            }
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }

    return index;
}

int buscarIdDirector(eDirector* pDirector, int length, int idDirector)
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
    else
    {
        printf("No ningun directorio de peliculas!");
    }

    return index;
}
void pedirDatosDirector(eDirector* pDirector, int length,char* nombre,char* fechaNacimiento,char* paisOrigen, int* idDirector)
{
    char auxNombre[50];
    char auxFechaNacimiento[12];
    char auxPaisOrigen[50];
    int auxIdDirector;
    int indice;
    int auxInt;

    if(pDirector != NULL && length> 0)
    {
        do
        {
            auxInt = getName(auxNombre, "Ingrese el nombre del director: ", "ERROR: Maximo 50 caracteres \n", 1, 50);
            indice = buscarNombreDirector(pDirector, length, auxNombre);
            if(indice == -1)
            {
                strcpy(nombre, auxNombre);
            }
            else
            {
                printf("Ese director ya existe!");
                auxInt = -1;
            }
        }while(auxInt!=0);
        system("cls");

        do
        {
            auxInt = getString(auxFechaNacimiento, "Ingrese la fecha de nacimiento: ", "ERROR: ingrese en formato dd/mm/aaaa\n", 1, 13);
        }while(auxInt!=0);
        strcpy(fechaNacimiento , auxFechaNacimiento);
        system("cls");

        do
        {
            auxInt = getString(auxPaisOrigen, "Ingrese el pais de origen: ", "ERROR: Maximo 50 caracteres ", 1, 50);
        }while(auxInt!=0);
        strcpy(paisOrigen, auxPaisOrigen);
        system("cls");
        do
        {
            auxInt = getInt(&auxIdDirector, "Ingrese el id del director:", "ERROR: valido de 1 a 500", 0,501);
            indice = buscarIdDirector(pDirector, length, auxIdDirector);
            if(indice == -1)
            {
                *idDirector = auxIdDirector;
            }
            else
            {
                printf("Ese director ya existe!");
                auxInt = -1;
            }
        }while(auxInt!=0);
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }


}

eDirector cargarDirector(char auxNombre[],char auxFechaNacimiento[],char auxPaisOrigen[], int auxIdDirector)
{
    eDirector auxDirector;

    strcpy(auxDirector.nombre, auxNombre );
    strcpy(auxDirector.fechaNacimiento , auxFechaNacimiento );
    strcpy(auxDirector.paisOrigen, auxPaisOrigen);
    auxDirector.idDirector = auxIdDirector;
    auxDirector.isEmpty = 0;

    return auxDirector;
}


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
    else
    {
        printf("No ningun directorio de peliculas!");
    }

    return index;
}

void nuevoDirector(eDirector* pDirector, int length)
{
    char auxNombre[50];
    char auxFechaNacimiento[12];
    char auxPaisOrigen[50];
    int auxIdDirector;
    int indice;

    if(pDirector != NULL && length> 0)
    {
        indice = obtenerEspacioLibreDirector(pDirector, length);
        if(indice!= -1)
        {
            pedirDatosDirector(pDirector,length,auxNombre,auxFechaNacimiento,auxPaisOrigen,&auxIdDirector);
            pDirector[indice] = cargarDirector(auxNombre, auxFechaNacimiento, auxPaisOrigen, auxIdDirector);
            printf("Director cargado!");
        }
        else
        {
            printf("No hay mas lugar para agregar peliculas!");
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }
}

void borrarDirector(eDirector* pDirector, int length)
{
    char auxnombre[50];
    int auxInt;
    int indice;
    char opcion;
    if(pDirector != NULL && length> 0)
    {
        auxInt = getName(auxnombre, "Ingrese el nombre del director a borrar: ", "ERROR: Maximo 50 caracteres y solo letras", 1, 50);
        if(auxInt== 0)
        {
            indice = buscarNombreDirector(pDirector, length, auxnombre);
            if(indice != -1)
            {
                printf("Desea eliminar director? s/n");
                fflush(stdin);
                scanf("%c", &opcion);
                if(opcion == 's')
                {
                    pDirector[indice].isEmpty = 1;
                    printf("Director Borrado");
                }
                else if(opcion == 'n')
                {
                    printf("accion cancelada");
                }
                else
                {
                    printf("Opcion no valida");
                }
            }
            else
            {
                printf("No existe ningun producto con ese codigo\n!");
            }
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }
}

/** \brief recibe el array, el tamaño y el id del director
 *
 * \param ePelicula* pPelicula
 * \param int length
 * \param int auxIdDirector
 * \return devuelve la cantidad de peliculas segun lo pasado por parametro
 *
 */

int cantidadPeliculasDirector(ePelicula* pPelicula, int length, int auxIdDirector)
{
    int i;


    int cantidadPeliculas = 0;
    if(pPelicula != NULL && length> 0)
    {

        for(i=0;i<length;i++)
        {
            if(pPelicula[i].isEmpty == 0)
            {
                if(pPelicula[i].idDirector == auxIdDirector)
                {
                    cantidadPeliculas = cantidadPeliculas +1;
                }
            }
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }
    return cantidadPeliculas;
}
int directorMasPeliculas(eDirector* pDirector, int lengthDirectores, ePelicula* pPelicula, int lengthPelicula)
{
    int i;
    int indiceDirectorMaspeliculas;
    int maximaCantidad;
    int auxIdDirector;
    int cantidadActual;
    int flagPrimera = 1;
    if(pDirector != NULL && lengthDirectores> 0)
    {
        for(i=0;i<lengthDirectores; i++)
        {
            if(pDirector[i].isEmpty == 0)
            {
                if(flagPrimera)
                {
                    auxIdDirector = pDirector[i].idDirector;
                    maximaCantidad = cantidadPeliculasDirector(pPelicula, lengthPelicula, auxIdDirector);
                    indiceDirectorMaspeliculas = i;
                    flagPrimera = 0;
                }
                else
                {
                    auxIdDirector = pDirector[i].idDirector;
                    cantidadActual = cantidadPeliculasDirector(pPelicula, lengthPelicula, auxIdDirector);
                    if(cantidadActual> maximaCantidad)
                    {
                        maximaCantidad = cantidadActual;
                        indiceDirectorMaspeliculas = i;
                    }
                }
            }
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!");
    }
    return indiceDirectorMaspeliculas;
}
void informar(eDirector* pDirector, int lengthDirector, ePelicula* pPelicula, int lengthPelicula)
{
    char opcion;
    int indiceDirector;
    opcion = mostrarMenu("1-Director con mas peliculas\n2-peliculas con mas directores", '1', '2');
    switch(opcion)
    {
        case '1':
            indiceDirector = directorMasPeliculas(pDirector, lengthDirector, pPelicula, lengthPelicula);
            printf("El director con mas peliculas es: %s", pDirector[indiceDirector].nombre);
            break;
        case '2':
            printf("NOT YET");
            break;
    }

}

void ordenar(ePelicula* pPelicula, int length)
{
    int i,j;
    ePelicula auxPelicula;
    for(i = 0;i < length-1 ;i++)
    {
        for(j= i + 1 ;j<length; j++)
        {
            if(strcmp(pPelicula[i].titulo, pPelicula[j].titulo)<0)
            {
                auxPelicula = pPelicula[i];
                pPelicula[i] = pPelicula[j];
                pPelicula[j] = auxPelicula;
            }
            else if(strcmp(pPelicula[i].titulo, pPelicula[j].titulo)==0)
            {
                if(pPelicula[i].anio > pPelicula[j].anio)
                {
                    auxPelicula = pPelicula[i];
                    pPelicula[i] = pPelicula[j];
                    pPelicula[j] = auxPelicula;
                }
            }
        }
    }
}


void mostrarPeliculas(ePelicula* pPelicula, int length, eDirector* pDirector, int lengthDirectores)
{
    int i;
    int indice;
    if((pDirector != NULL && lengthDirectores> 0) && (pPelicula != NULL && length> 0))
    {
        for(i = 0; i<length; i++)
        {
            if(pPelicula[i].isEmpty == 0)
            {
                indice = buscarIdDirector(pDirector, lengthDirectores, pPelicula[i].idDirector);
                printf("Pelicula : \n\t%s\nDirector:\n\t%s\nAnio:%d\n\t%s\nNacionalidad\n\t%s\n\n\n\n\n", pPelicula[i].titulo, pDirector[indice].nombre,pPelicula[i].anio, pDirector[indice].paisOrigen);
            }

        }
    }
}


