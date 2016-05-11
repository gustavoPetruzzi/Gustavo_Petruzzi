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
    char opcion;
    printf("%s", textomenu);
    fflush(stdin);
    scanf("%c",&opcion);
    return opcion;
}

/**
 * Obtiene el primer indice libre del array.
 * @param ePelicula* pPelicula el array se pasa como parametro.
 * @param int length la cantidad total de items
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
    return index;
}

/** \brief Busca la posicion en el array del dato pasado por parametro
 *
 * \param ePelicula * pPelicula array donde busca lo pasado por parametro
 * \param int length tamaño total del array
 * \param int idPelicula dato que busca en el array
 * \return devuelve la posicion donde se haya el dato pasado por parametro
 *
 */


int buscarPorIdPelicula(ePelicula* pPelicula, int length, int idPelicula)
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

/** \brief le solicita datos al usuario
 *
 * \param ePelicula* pPelicula lugar donde recorre los indices
 * \param int lenght tamaño del array
 * \param char* titulo dato pedido al usuario
 * \param int* anio dato pedido al usuario
 * \param char* Nacionalidad dato pedido al usuario
 * \param int* idDirector dato pedido al usuario
 * \param int* idPelicula dato pedido al usuario
 * \param int pedirId si el parametro pasado es 1, se le solicita el id al usuario, si es cualquier otro numero, no se le pide
 * \return
 *
 */


int pedirDatosPelicula(ePelicula* pPelicula, int lengthPelicula,eDirector* pDirector, int lengthDirector, char* titulo,int* anio, char* Nacionalidad,int* idDirector, int* idPelicula, int pedirId)
{
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int auxInt;
    int auxIndice;
    int retorno = 1;
    char seguir = 's';

    if(pPelicula != NULL && lengthPelicula> 0)
    {
        do
        {
            auxInt = getStringSpace(auxTitulo, "Ingrese el titulo de la pelicula: ", "Error: Maximo 50 caracteres\n", 0, 50);
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



        if(pedirId)
        {

            do
            {
                auxInt = getInt(&auxIdPelicula,"Ingrese el id de la pelicula: ", "ERROR: solo numeros entre 1 y 1000\n", 0,1001);
                auxIndice = buscarPorIdPelicula(pPelicula, lengthPelicula, auxIdPelicula);
                if(auxIndice == -1 && auxInt == 0)
                {
                    *idPelicula = auxIdPelicula;
                }
                else
                {
                    printf("Ya existe ese ID cargado!\n");
                    auxInt = -1;
                }

            }while(auxInt!=0);

            system("cls");
        }
    }

    do
        {
            auxInt = getInt(&auxIdDirector, "Ingrese ID del director: ", "ERROR: solo se permite entre 1 y 500\n", 0, 501);
            auxIndice = buscarPorIdDirector(pDirector, lengthDirector, auxIdDirector);
            if(auxIndice != -1)
            {
                *idDirector = auxIdDirector;
                seguir = 'n';
            }
            else
            {
                printf("Ese Id no se encuentra cargado\nDesea seguir?: s/n");
                do
                {
                    fflush(stdin);
                    scanf("%c",&seguir);
                    if(seguir !='n' && seguir!='s')
                    {
                        printf("caracter no valido\n ingrese \"s\" para seguir o \"n\" para salir");
                    }
                }while(seguir !='n' && seguir !='s');
                if(seguir=='n')
                {
                    retorno = 0;
                    break;
                }
            }
        }while(auxInt!=0 || seguir == 's');
        printf("%c", seguir);
        system("cls");


    return retorno;
}
/** \brief carga un elemento del array de estructura
 *
 * \param char auxTitulo[] dato a ser cargado en el array
 * \param  int auxAnio dato a ser cargado en el array
 * \param  char auxNacionalidad[] dato a ser cargado en el array
 * \param  int auxIdDirector dato a ser cargado en el array
 * \param  int auxIdPelicula dato a ser cargado en el array
 * \return un elemento del array de estructuras
 *
 */


ePelicula cargarPelicula(char auxTitulo[],int auxAnio, char auxNacionalidad[],int auxIdDirector, int auxIdPelicula)
{
    ePelicula auxPelicula;

    strcpy(auxPelicula.titulo, auxTitulo );
    auxPelicula.anio = auxAnio;
    strcpy(auxPelicula.nacionalidad, auxNacionalidad);
    auxPelicula.idDirector = auxIdDirector;
    auxPelicula.idPelicula = auxIdPelicula;
    auxPelicula.isEmpty = 0;

    return auxPelicula;
}

/** \brief agrega un elemento al array de estructura en una posicion libre
 *
 * \param ePelicula* pPelicula array de estructura donde agrega el elemento
 * \param int length tamaño total del array de estructuras
 * \return
 *
 */


void agregarPelicula(ePelicula* pPelicula, int lengthPelicula,eDirector* pDirector, int lengthDirector)
{
    int indice;
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int auxInt;

    if(pPelicula != NULL && lengthPelicula> 0)
    {
        indice =obtenerEspacioLibre(pPelicula, lengthPelicula);
        if(indice!= -1)
        {
            auxInt = pedirDatosPelicula(pPelicula, lengthPelicula, pDirector, lengthDirector, auxTitulo,&auxAnio, auxNacionalidad, &auxIdDirector, &auxIdPelicula, 1);
            if(auxInt)
            {
                pPelicula[indice] =cargarPelicula(auxTitulo, auxAnio, auxNacionalidad,auxIdDirector, auxIdPelicula);
                printf("Pelicula cargada!\n");
            }
            else
            {
                printf("No se ha cargado la pelicula\n");
            }
        }
        else
        {
            printf("No hay mas lugar para agregar peliculas!\n");
        }
    }
}

/** \brief Indica si existe algun elemento cargado
 *
 * \param puntero lista[] lugar donde va a iterar la funcion
 * \param int length tamaño maximo del array de estructura
 * \return devuelve [1] si el array no tiene ningun elemento cargado o
 *         [0] si esta cargado con aunque sea un elemento
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
    return retorno;
}


/** \brief Indica si existe algun elemento cargado
 *
 * \param puntero lista[] lugar donde va a iterar la funcion
 * \param int length tamaño maximo del array de estructura
 * \return devuelve [1] si el array no tiene ningun elemento cargado o
 *         [0] si esta cargado con aunque sea un elemento
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
    return retorno;
}

/** \brief modifica los datos cargados en algun elemento
 *
 * \param ePelicula* pPelicula array de estructuras donde busca el elemento a modificar
 * \param int length tamaño total del array
 * \return
 *
 */

void modificar(ePelicula* pPelicula, int lengthPelicula,eDirector* pDirector, int lengthDirector)
{
    int indice;
    char auxTitulo[50];
    int auxAnio;
    char auxNacionalidad[50];
    int auxIdDirector;
    int auxIdPelicula;
    int auxInt;

    if(pPelicula != NULL && lengthPelicula> 0)
    {
        auxInt = getInt(&auxIdPelicula, "Ingrese el id a buscar", "ERROR: solamente se puede ingresar de 1 a 1000\n", 0, 1001);
        if(auxInt==0)
        {

            indice = buscarPorIdPelicula(pPelicula, lengthPelicula,auxIdPelicula);
            if(indice != -1)
            {
                pedirDatosPelicula(pPelicula, lengthPelicula,pDirector, lengthDirector, auxTitulo, &auxAnio, auxNacionalidad,&auxIdDirector, &auxIdPelicula, 0);
                pPelicula[indice] = cargarPelicula(auxTitulo, auxAnio, auxNacionalidad, auxIdDirector, auxIdPelicula);
            }
            else
            {
                printf("No existe ese Id\n");
            }
        }
    }
}

/** \brief borra un elemento cargado en el array
 *
 * \param ePelicula* pPelicula array de estructuras donde busca el elemento a modificar
 * \param int length tamaño total del array
 * \return
 *
 */

void borrar(ePelicula* pPelicula, int length)
{
    int auxIdPelicula;
    int auxInt;
    int indice;
    if(pPelicula != NULL && length> 0)
    {
        auxInt = getInt(&auxIdPelicula, "Ingrese el ID de la pelicula a borrar: ", "ERROR: solo se permite de 1 a 1000\n", 0, 1001);
        if(auxInt== 0)
        {
            indice = buscarPorIdPelicula(pPelicula, length, auxIdPelicula);
            if(indice != -1)
            {
                pPelicula[indice].isEmpty = 1;
            }
        }
    }
}


/** \brief busca el indice del elemento segun el dato pasado por parametro
 *
 * \param eDirector* pDirector array de estructura donde busca el indice
 * \param int length tamaño total del array
 * \param char nombre[] dato por el cual busca el indice
 * \return indice del elemento buscado
 *
 */

int buscarPorNombreDirector(eDirector* pDirector, int length, char nombre[])
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
    return index;
}


/** \brief busca el indice del elemento segun el dato pasado por parametro
 *
 * \param eDirector* pDirector array de estructura donde busca el indice
 * \param int length tamaño total del array
 * \param  int idDirector dato por el cual busca el indice
 * \return indice del elemento buscado
 *
 */

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
    else
    {
        printf("No ningun directorio de peliculas!\n");
    }

    return index;
}



/** \brief le solicita datos al usuario
 *
 * \param eDirector* pDirectora lugar donde recorre los indices
 * \param int lenght tamaño del array
 * \param char* nombre dato pedido al usuario
 * \param char* fechaNacimiento dato pedido al usuario
 * \param char* paisOrigen dato pedido al usuario
 * \param int* idDirector dato pedido al usuario
 * \return
 *
 */
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
            indice = buscarPorNombreDirector(pDirector, length, auxNombre);
            if(indice == -1)
            {
                strcpy(nombre, auxNombre);
            }
            else
            {
                printf("Ese director ya existe!\n");
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
            auxInt = getString(auxPaisOrigen, "Ingrese el pais de origen: ", "ERROR: Maximo 50 caracteres\n ", 1, 50);
        }while(auxInt!=0);
        strcpy(paisOrigen, auxPaisOrigen);
        system("cls");
        do
        {
            auxInt = getInt(&auxIdDirector, "Ingrese el id del director: ", "ERROR: valido de 1 a 500\n", 0,501);
            indice = buscarPorIdDirector(pDirector, length, auxIdDirector);
            if(indice == -1 && auxInt == 0)
            {
                *idDirector = auxIdDirector;
            }
            else
            {
                printf("Ese director ya existe!\n");
                auxInt = -1;
            }
        }while(auxInt!=0);
    }
    else
    {
        printf("No ningun directorio de peliculas!\n");
    }


}


/** \brief carga un elemento del array de estructura
 *
 * \param char auxNombre[] dato a ser cargado en el array
 * \param  char auxFechaNacimiento[] dato a ser cargado en el array
 * \param  char auxPaisOrigen[] dato a ser cargado en el array
 * \param  int auxIdDirector dato a ser cargado en el array
 * \return un elemento del array de estructuras
 *
 */


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

/**
 * Obtiene el primer indice libre del array.
 * @param eDirector* pDirector el array se pasa como parametro.
 * @param int length la cantidad total de items
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
    else
    {
        printf("No ningun directorio de peliculas!\n");
    }

    return index;
}

/** \brief agrega un elemento al array de estructura en una posicion libre
 *
 * \param eDirector* pDirector array de estructura donde agrega el elemento
 * \param int length tamaño total del array de estructuras
 * \return
 *
 */

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
            printf("Director cargado!\n");
        }
        else
        {
            printf("No hay mas lugar para agregar peliculas!\n");
        }
    }
    else
    {
        printf("No ningun directorio de peliculas!\n");
    }
}

/** \brief borra un elemento cargado en el array
 *
 * \param eDirector* pDirector array de estructuras donde busca el elemento a modificar
 * \param int length tamaño total del array
 * \return
 *
 */

void borrarDirector(eDirector* pDirector, int length)
{
    char auxnombre[50];
    int auxInt;
    int indice;
    char opcion;
    if(pDirector != NULL && length> 0)
    {
        auxInt = getName(auxnombre, "Ingrese el nombre del director a borrar: ", "ERROR: Maximo 50 caracteres y solo letras\n", 1, 50);
        if(auxInt== 0)
        {
            indice = buscarPorNombreDirector(pDirector, length, auxnombre);
            if(indice != -1)
            {
                printf("Desea eliminar director? s/n\n");
                fflush(stdin);
                scanf("%c", &opcion);
                if(opcion == 's')
                {
                    pDirector[indice].isEmpty = 1;
                    printf("Director Borrado\n");
                }
                else if(opcion == 'n')
                {
                    printf("accion cancelada\n");
                }
                else
                {
                    printf("Opcion no valida\n");
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

/** \brief Cuenta la cantidad de veces que figura el parametro pasado en un miembro del
           array de estructuras
 *
 * \param ePelicula* pPelicula array de estructuras donde cuenta la cantidad
 * \param int length tamaño  del array
 * \param int auxIdDirector dato a comparar con un miembro del array de estructuras
 * \return devuelve la cantidad de veces que figura el parametro pasado en un miembro del
           array de estructuras
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
        printf("No ningun directorio de peliculas!\n");
    }
    return cantidadPeliculas;
}

/** \brief Busca el director con mas peliculas
 *
 * \param eDirector* pDirector array de estructuras
 * \param int lengthDirectores tamaño del array de estructuras como primer parametro
 * \param ePelicula* pPelicula array de estructuras
 * \param int lengthPelicula tamaño del array de estructuras pasado como tercer paramentro
 * \return  la posicion donde se encuentra el director con mas peliculas
 *
 */

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


/** \brief informa al director con mas peliculas y las peliculas con mas directores
 *
 * \param eDirector* pDirector array de estructuras
 * \param int lengthDirector tamaño del array de estructuras como primer parametro
 * \param ePelicula* pPelicula array de estructuras
 * \param int lengthPelicula tamaño del array de estructuras pasado como tercer paramentro
 * \return
 *
 */

void informar(eDirector* pDirector, int lengthDirector, ePelicula* pPelicula, int lengthPelicula)
{
    char opcion;
    int indiceDirector;
    opcion = mostrarMenu("1-Director con mas peliculas\n2-peliculas con mas directores\n", '1', '2');
    switch(opcion)
    {
        case '1':
            indiceDirector = directorMasPeliculas(pDirector, lengthDirector, pPelicula, lengthPelicula);
            printf("El director con mas peliculas es: %s\n", pDirector[indiceDirector].nombre);
            break;
        case '2':
            printf("NOT YET");
            break;
    }

}

/** \brief ordena el array estructura pasado por parametro
 *
 * \param ePelicula* pPelicula array a estructuras a ser ordenado
 * \param int length tamaño del array de estructuras
 * \return
 *
 */

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

/** \brief muestra por pantalla los miembros de la estructura
 *
 * \param eDirector* pDirector array de estructuras
 * \param int lengthDirector tamaño del array de estructuras como primer parametro
 * \param ePelicula* pPelicula array de estructuras
 * \param int lengthPelicula tamaño del array de estructuras pasado como tercer paramentro
 * \return
 *
 */


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
                indice = buscarPorIdDirector(pDirector, lengthDirectores, pPelicula[i].idDirector);
                printf("Pelicula : \n\t%s\nDirector:\n\t%s\nAnio:\n\t%d\nNacionalidad:\n\t%s\n\n\n\n\n", pPelicula[i].titulo, pDirector[indice].nombre,pPelicula[i].anio, pDirector[indice].paisOrigen);
            }

        }
    }
}


