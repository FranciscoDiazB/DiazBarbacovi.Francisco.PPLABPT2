#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcodeo.h"


char marcas[10][20] = {

    "YAMAHAA",
    "HUNDAI",
    "MOTOMEL",
    "SUZUKI",
    "HUNDAI",
    "YAMAHAA",
    "YAMAHAA",
    "FERRARI",
    "TESLA",
    "TESLA"
};

int idTipos[10] = {1003,1000,1001,1002,1002,1000,1003,1002,1001,1000};

int idColores[10] = {10001,10003,10002,10000,10000,10002,10002,10003,10003,10001};

int cilindrada[10] = {125,50,750,600,750,50,125,750,500,500};

int idMotos[] = {301,303,302,300,305,300,301,302,307,300,301,302,305,302,306,303,300};

int idServicios[] = {20000,20003,20001,20001,20003,20002,20001,20002,20003,20000,20000,20001,20002,20002,20001,20002,20003};


eFecha fecha[] =
{
    {2,4,2021},
    {2,4,2021},
    {2,4,2021},
    {2,4,2021},
    {3,4,2021},
    {3,4,2021},
    {4,4,2021},
    {4,4,2021},
    {5,4,2021},
    {6,4,2021},
    {7,4,2021},
    {8,4,2021},
    {9,4,2021},
    {10,4,2021},
    {11,4,2021},
    {12,4,2021},
    {13,4,2021}
};


int hardcodearMotos(eMoto motos[], int tam, int cant, int* pLegajo){

    int cantidad = 0;
    if(motos != NULL && tam > 0 && cant >= 0 && cant <= tam && pLegajo != NULL){

        for(int i = 0; i < cant; i++){

                motos[i].id = *pLegajo;
                (*pLegajo)++;
                strcpy(motos[i].marca, marcas[i]);
                motos[i].idTipo = idTipos[i];
                motos[i].idColor = idColores[i];
                motos[i].cilindrada = cilindrada[i];
                motos[i].isEmpty = 0;
                cantidad++;
        }
    }
    return cantidad;
}

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId){

    int cantidad = 0;
    if( trabajos != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){

        for(int i = 0; i < cant; i++){

                trabajos[i].idTra = *pId;
                (*pId)++;
                trabajos[i].idBicicleta = idMotos[i];
                trabajos[i].idServicio = idServicios[i];
                trabajos[i].fecha = fecha[i];
                trabajos[i].isEmpty = 0;
                cantidad++;
        }
    }
    return cantidad;
}

