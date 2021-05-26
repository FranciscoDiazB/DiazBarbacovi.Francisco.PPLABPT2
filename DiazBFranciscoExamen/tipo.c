#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipo.h"




int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char descr[]){

    int todoOK = 0;

    if(tipos != NULL && tam > 0 && descr != NULL && id >= 1000 && id <= 1003){

        for(int i = 0; i < tam; i++){
            if(tipos[i].id == id){
                strcpy(descr, tipos[i].descripcion);
                todoOK = 1;
                break;
            }
        }
    }

    return todoOK;
}

void mostrarTipos(eTipo tipos[], int tam){

    printf("\n\t\tTipos de Moto\n\n");
    printf("\tID del Tipo\t\tDescripcion Tipo\n");
    printf("\t--------------------------------------------------\n\n");

    for(int i = 0; i < tam; i++){

       mostrarUnTipo(tipos[i]);
       printf("\n");
    }
    printf("\n\n");
}

void mostrarUnTipo(eTipo unTipo){

    printf("\t%d\t\t\t\t%-10s", unTipo.id, unTipo.descripcion);

}
