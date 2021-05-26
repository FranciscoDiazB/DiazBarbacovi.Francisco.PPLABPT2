#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"

int cargarDescripcionColor(int id, eColor colores[], int tam, char descr[]){

    int todoOK = 0;

    if(colores != NULL && tam > 0 && descr != NULL && id >= 10000 && id <= 10004){

        for(int i = 0; i < tam; i++){
            if(colores[i].id == id){
                strcpy(descr, colores[i].nombreColor);
                todoOK = 1;
                break;
            }
        }
    }

    return todoOK;
}

void mostrarColores(eColor colores[], int tam){

    printf("\n\t\tColores de la Moto\n\n");
    printf("\tID del Color\t\tColor\n");
    printf("\t--------------------------------------------------\n\n");

    for(int i = 0; i < tam; i++){

       mostrarUnColor(colores[i]);
       printf("\n");
    }
    printf("\n\n");
}

void mostrarUnColor(eColor unColor){

    printf("\t%d\t\t\t\t%-10s", unColor.id, unColor.nombreColor);

}
