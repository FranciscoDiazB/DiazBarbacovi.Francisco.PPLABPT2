#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "servicios.h"


int cargarDescripcionServicio(int id, eServicio servicio[], int tam, char descr[]){

    int todoOK = 0;

    if(servicio != NULL && tam > 0 && descr != NULL && id >= 20000 && id <= 20003){

        for(int i = 0; i < tam; i++){
            if(servicio[i].id == id){
                strcpy(descr, servicio[i].descripcion);
                todoOK = 1;
                break;
            }
        }
    }

    return todoOK;
}

int cargarValorServicio(int id, eServicio servicio[], int tam, float* precio){

    int todoOK = 0;

    if(servicio != NULL && tam > 0 && precio != NULL && id >= 20000 && id <= 20003){

        for(int i = 0; i < tam; i++){
            if(servicio[i].id == id){
                *precio = servicio[i].precio;
                todoOK = 1;
                break;
            }
        }
    }
    return todoOK;
}

void mostrarServicios(eServicio servicio[], int tam){

    printf("\n\t\tServicios de la Moto\n\n");
    printf("\tID del Servicio\t\tServicio\t\tPrecio\n");
    printf("\t------------------------------------------------------------\n\n");

    for(int i = 0; i < tam; i++){

       mostrarUnServicio(servicio[i]);
       printf("\n");
    }
    printf("\n\n");
}

void mostrarUnServicio(eServicio unServicio){

    printf("\t%d\t\t\t%-10s\t\t$%.2f", unServicio.id, unServicio.descripcion, unServicio.precio);

}

int validarIdServicios(int id, eServicio servicios[], int tam){

    int valido = 0;
    if(servicios != NULL && tam > 0){

        for(int i = 0; i < tam; i++){
            if(servicios[i].id == id){
                valido = 1;
                break;
            }
        }
    }
    return valido;
}
