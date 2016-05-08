#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define MAX_PELICULAS 1000
#define MAX_DIRECTORES 500
int main()
{
    ePelicula peliculas[MAX_PELICULAS];
    eDirector directores[MAX_DIRECTORES];
    int initPeliculas;
    int initDirectores;
    char opcion;
    int auxInt;


    initPeliculas = initArrayPelicula(peliculas, MAX_PELICULAS);
    initDirectores = initArrayDirectores(directores, MAX_DIRECTORES);
    if(initPeliculas == 0 && initDirectores == 0)
    {
        do
        {
            opcion = mostrarMenu("1-ALTAS PELICULAS\n2-MODIFICAR DATOS DE UNA PELICULA\n3-BAJA DE PELICULA\n4-NUEVO DIRECTOR\n5-ELIMINAR DIRECTOR\n6-INFORMAR\n7-LISTAR\n8-SALIR\n", '1', '8');
            system("cls");
            switch(opcion)
            {
                case '1':
                    auxInt = isEmptyDirector(directores, MAX_DIRECTORES);
                    if(auxInt == 0)
                    {
                        agregarPelicula(peliculas, MAX_PELICULAS, directores, MAX_PELICULAS);
                    }
                    else
                    {
                        printf("No hay ningun director cargado\n!");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '2':
                    auxInt = isEmptyPelicula(peliculas,MAX_PELICULAS);
                    if(auxInt == 0)
                    {
                        modificar(peliculas, MAX_PELICULAS,directores, MAX_PELICULAS);
                    }
                    else
                    {
                        printf("No hay ninguna pelicula cargada\n!");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '3':
                    auxInt = isEmptyPelicula(peliculas,MAX_PELICULAS);
                    if(auxInt == 0)
                    {
                        borrar(peliculas, MAX_PELICULAS);
                    }
                    else
                    {
                        printf("No hay ninguna pelicula cargada\n!");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '4':
                        nuevoDirector(directores, MAX_DIRECTORES);
                    break;
                case '5':
                        auxInt = isEmptyDirector(directores, MAX_DIRECTORES);
                    if(auxInt == 0)
                    {
                        eliminarDirector(directores, MAX_DIRECTORES);
                    }
                    else
                    {
                        printf("No hay ningun director cargado!\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '6':
                    system("pause");
                    system("cls");
                    break;
                case '7':
                    system("pause");
                    system("cls");
                    break;
                case '8':
                    break;
            }
        }while(opcion!='8');

    }
    else
    {
        printf("Ha ocurrido un error");
    }

    return 0;
}
