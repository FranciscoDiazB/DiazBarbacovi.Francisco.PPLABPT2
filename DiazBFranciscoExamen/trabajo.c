#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabajo.h"

void inicializarTrabajo(eTrabajo trabajo[], int tam){

    for(int i = 0; i < tam; i++){

        trabajo[i].isEmpty = 1;
    }
}


int buscarLibreTrabajo(eTrabajo trabajo[], int tam){

    int retorno = -1;

    for(int i = 0; i < tam; i++){

        if(trabajo[i].isEmpty){
            retorno = i;
            break;
        }
    }
    return retorno;
}

int altaTrabajo(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi,
                eColor colores[], int tamC, eServicio servicio[], int tamS, int* pNextId){

   int todoOk = 0;
   int indice;
   int idMoto;
   int idServicio;
   eTrabajo nuevoTrabajo;

   if(trabajo != NULL && tamTra > 0 && motos !=  NULL && tam > 0 && tipos != NULL && tamTi > 0 && colores != NULL && tamC > 0 &&
      servicio != NULL && tamS > 0 && pNextId != NULL){


        printf("\n            Alta Trabajo\n\n");
        indice = buscarLibreTrabajo(trabajo, tamTra);

        if(indice == -1){
            printf("No hay lugar para mas trabajos\n\n");
        }
        else{
            mostrarMotos(motos, tam, tipos, tamTi, colores, tamC);
            printf("\nIngrese el ID de la moto: ");
            fflush(stdin);
            scanf("%d", &idMoto);
            while(buscarMoto(motos, tam, idMoto) == -1){
                printf("\nNo existe Moto con ese ID. Reingrese ID de la moto: ");
                fflush(stdin);
                scanf("%d", &idMoto);
                printf("\n");
                system("pause");
                printf("\n");
            }
            nuevoTrabajo.idBicicleta = idMoto;

            mostrarServicios(servicio, tamS);
            printf("\nIngrese el Id correspondiente al servicio que quiera: ");
            fflush(stdin);
            scanf("%d", &idServicio);
            while(validarIdServicios(idServicio, servicio, tam) == 0){
                printf("\nDato invalido. Reingrese el Id correspondiente al servicio que quiera: ");
                fflush(stdin);
                scanf("%d", &idServicio);
                printf("\n");
                system("pause");
                printf("\n");
            }
            nuevoTrabajo.idServicio = idServicio;

            printf("\nIngrese la fecha dd/mm/aaaa del servicio (a partir del anio 2015) : ");
            fflush(stdin);
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            printf("\n");
            while(nuevoTrabajo.fecha.dia > 31 || nuevoTrabajo.fecha.dia < 1 || nuevoTrabajo.fecha.mes > 12 ||
                  nuevoTrabajo.fecha.mes < 1 || nuevoTrabajo.fecha.anio < 2015)
                {
                    printf("\nFecha invalida. Ingrese la fecha dd/mm/aaaa del servicio (a partir del anio 2015) : ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
                    printf("\n");
                    system("pause");
                    printf("\n");
                }

            nuevoTrabajo.idTra = *pNextId;
            (*pNextId)++;
            nuevoTrabajo.isEmpty = 0;

            trabajo[indice] = nuevoTrabajo;
            todoOk = 1;
        }
   }
    return todoOk;
}

int mostrarTrabajos(eTrabajo trabajos[], int tamTra, eMoto motos[], int tam, eServicio servicio[], int tamS){

    int flag = 1;
    int exito = -1;

    printf("\n\t\t\tListado de Trabajos\t\t\t\n\n");
    printf(" ID Trabajo\tID Moto\t\tMarca\t\t  Servicio/Precio\t\tFecha de Trabajo\n");
    printf(" -------------------------------------------------------------------------------------------");
    printf("\n\n");

    if(trabajos != NULL && tamTra > 0 && motos != NULL && tam > 0 && servicio != NULL && tamS > 0){

        for(int i = 0; i < tamTra; i++){

            if(trabajos[i].isEmpty == 0){
                mostrarUnTrabajo(trabajos[i], motos, tam, servicio, tamS);
                printf("\n");
                flag = 0;
                exito = 1;
            }
        }
    }
    if(flag){
        printf("No hay Trabajos para mostrar");
    }
    return exito;
}


void mostrarUnTrabajo(eTrabajo unTrabajo, eMoto motos[], int tam, eServicio servicio[], int tamS){

   char marcaMoto[20];
   char descripcionServicio[25];
   float precioServicio = 0;


   if(cargarDescripcionServicio(unTrabajo.idServicio, servicio, tamS, descripcionServicio) &&
      cargarMarcaMoto(unTrabajo.idBicicleta, motos, tam, marcaMoto) &&
      cargarValorServicio(unTrabajo.idServicio, servicio, tamS, &precioServicio)){

        printf(" %d\t       %d\t\t%s\t\t%10s/$%.2f\t\t%d/%02d/%d\n", unTrabajo.idTra,
            unTrabajo.idBicicleta,
            marcaMoto,
            descripcionServicio,
            precioServicio,
            unTrabajo.fecha.dia,
            unTrabajo.fecha.mes,
            unTrabajo.fecha.anio);
   }


}
