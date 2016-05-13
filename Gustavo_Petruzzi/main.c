#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>
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


    initPeliculas = initArrayPeliculas(peliculas, MAX_PELICULAS);
    initDirectores = initArrayDirectores(directores, MAX_DIRECTORES);

    strcpy(directores[0].nombre,"Jose");
    strcpy(directores[0].fechaNacimiento, "21/11/1991");
    strcpy(directores[0].paisOrigen, "Argentina");
    directores[0].idDirector = 1;
    directores[0].isEmpty = 0;

    strcpy(directores[1].nombre,"Juan");
    strcpy(directores[1].fechaNacimiento, "11/02/1982");
    strcpy(directores[1].paisOrigen, "chile");
    directores[1].idDirector = 2;
    directores[1].isEmpty = 0;

    strcpy(directores[2].nombre,"Jorge");
    strcpy(directores[2].fechaNacimiento, "11/02/1994");
    strcpy(directores[2].paisOrigen, "EEUU");
    directores[2].idDirector = 3;
    directores[2].isEmpty = 0;


    strcpy(peliculas[0].titulo, "El perror");
    peliculas[0].anio = 1991;
    strcpy(peliculas[0].nacionalidad,"Argentina");
    peliculas[0].idPelicula = 1;
    peliculas[0].idDirector = 1;
    peliculas[0].isEmpty = 0;

    strcpy(peliculas[1].titulo, "Puto el que lee");
    peliculas[1].anio = 2015;
    strcpy(peliculas[1].nacionalidad, "Argentina");
    peliculas[1].idPelicula = 2;
    peliculas[1].idDirector = 1;
    peliculas[1].isEmpty = 0;



    strcpy(peliculas[2].titulo, "El perror");
    peliculas[2].anio = 1998;
    strcpy(peliculas[2].nacionalidad,"chile");
    peliculas[2].idPelicula = 3;
    peliculas[2].idDirector = 2;
    peliculas[2].isEmpty = 0;

    strcpy(peliculas[3].titulo, "Star Wars IV");
    peliculas[3].anio = 1998;
    strcpy(peliculas[3].nacionalidad,"EEUU");
    peliculas[3].idPelicula = 4;
    peliculas[3].idDirector = 3;
    peliculas[3].isEmpty = 0;

    strcpy(peliculas[4].titulo, "Star Wars V");
    peliculas[4].anio = 1998;
    strcpy(peliculas[4].nacionalidad,"EEUU");
    peliculas[4].idPelicula = 5;
    peliculas[4].idDirector = 3;
    peliculas[4].isEmpty = 0;

    strcpy(peliculas[5].titulo, "Star Wars VI");
    peliculas[5].anio = 1998;
    strcpy(peliculas[5].nacionalidad,"EEUU");
    peliculas[5].idPelicula = 6;
    peliculas[5].idDirector = 3;
    peliculas[5].isEmpty = 0;




    if(initDirectores == 0 && initPeliculas == 0)
    {


        do{

            opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJA PELICULA\n4-NUEVO DIRECTOR\n5-ELIMINAR DIRECTOR\n6-INFORMAR\n7-LISTAR\n8-SALIR\n", '1', '8');
            switch(opcion)
            {
                system("cls");
                case '1':

                    auxInt = isEmptyDirector(directores, MAX_DIRECTORES);
                    if(auxInt == 0)
                    {
                        system("cls");
                        agregarPelicula(peliculas, MAX_PELICULAS, directores, MAX_PELICULAS);

                    }
                    else
                    {

                        printf("No hay ningun director ingresado\nPor favor, para agregar alguna pelicula ingrese un director\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '2':
                    auxInt = isEmptyPelicula(peliculas, MAX_PELICULAS);
                    if(auxInt == 0)
                    {
                        system("cls");
                        modificar(peliculas, MAX_PELICULAS,directores, MAX_PELICULAS);
                    }
                    else
                    {
                        printf("No hay ninguna pelicula ingresada!\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '3':
                    auxInt = isEmptyPelicula(peliculas, MAX_PELICULAS);
                    if(auxInt == 0)
                    {
                        system("cls");
                        borrar(peliculas, MAX_PELICULAS);
                    }
                    else
                    {
                        printf("No hay ninguna pelicula ingresada!\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '4':
                    system("cls");
                    nuevoDirector(directores, MAX_DIRECTORES);
                    system("pause");
                    system("cls");
                    break;
                case '5':
                    auxInt = isEmptyDirector(directores, MAX_DIRECTORES);
                    if(auxInt ==0)
                    {
                        system("cls");
                        borrarDirector(directores, MAX_DIRECTORES);
                    }
                    else
                    {
                        printf("No hay ningun director cargado!\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '6':

                    auxInt = isEmptyPelicula(peliculas, MAX_PELICULAS);
                    if(auxInt ==0)
                    {
                        system("cls");
                        informar(directores,MAX_DIRECTORES, peliculas, MAX_PELICULAS);
                    }

                    else
                    {
                        printf("No hay ninguna pelicula ingresada!\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '7':
                    auxInt = isEmptyPelicula(peliculas, MAX_PELICULAS);

                    if(auxInt ==0)
                    {
                        system("cls");
                        ordenar(peliculas, MAX_PELICULAS);
                        mostrarPeliculas(peliculas,MAX_PELICULAS, directores, MAX_DIRECTORES);
                    }
                    else
                    {
                        printf("No hay ninguna pelicula ingresada!\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                case '8':
                    printf("Saliendo del programa");
                    break;
                default:
                    printf("Opcion no valida\n\n");
                    system("pause");
                    system("cls");
                }

        }while(opcion!='8');
    }
    else
    {
        printf("No se pudo inicilizar el programa");
    }
    return 0;
}

