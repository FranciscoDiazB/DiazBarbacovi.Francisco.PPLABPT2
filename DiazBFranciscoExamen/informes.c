#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"

int validarIdColor(int id, eColor colores[], int tam)
{
    int valido = 0;

    for(int i=0; i < tam; i++){
        if(colores[i].id == id){
            valido = 1;
            break;
        }
    }
    return valido;
}

int validarIdTipo(int id, eTipo tipos[], int tam)
{
    int valido = 0;

    for(int i=0; i < tam; i++){
        if(tipos[i].id == id){
            valido = 1;
            break;
        }
    }
    return valido;
}

int listarMotosColor(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

    int idColor;
    int todoOK = 0;
    char descripcion[20];
    int flag = 1;

    mostrarColores(colores, tamC);
    printf("\nIngrese Id del Color para mostrar las motos de ese color: ");
    fflush(stdin);
    scanf("%d", &idColor);
    while(validarIdColor(idColor, colores, tamC) == 0){
        printf("\nId Invalido. Reingrese id del Color: ");
        fflush(stdin);
        scanf("%d", &idColor);
    }
    printf("\n\n");
    cargarDescripcionColor(idColor, colores, tamC, descripcion);

    printf("\t\t\tListado de Motos del color: %s\t\t\t\n\n", descripcion);
    printf("ID \tMarca\t\tTipo\t\tColor\t   Cilindrada\n");
    printf("--------------------------------------------------------------------------------------");
    printf("\n");


    if(motos != NULL && colores != NULL && tipos != NULL && tam > 0 && tamC > 0 && tamT > 0){

        for(int i = 0; i < tam; i++){

            if(motos[i].idColor == idColor && motos[i].isEmpty == 0){

                mostrarUnaMoto(motos[i], tipos, tamT, colores, tamC);
                printf("\n");
                todoOK = 1;
                flag = 0;
            }
        }
        if(flag){
            printf("\nNo hay motos ingresadas del color : %s", descripcion);
        }
    }
    printf("\n");
    return todoOK;
}


int listarMotosTipo(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

    int idTipo;
    int todoOK = 0;
    char descripcion[20];
    int flag = 1;

    mostrarTipos(tipos, tamT);
    printf("\nIngrese Id del Tipo para mostrar las motos de ese tipo: ");
    fflush(stdin);
    scanf("%d", &idTipo);
    while(validarIdTipo(idTipo, tipos, tamT) == 0){
        printf("\nId Invalido. Reingrese id del tipo: ");
        fflush(stdin);
        scanf("%d", &idTipo);
    }
    printf("\n\n");
    cargarDescripcionTipo(idTipo, tipos, tamT, descripcion);

    printf("\t\t\tListado de Motos del Tipo: %s\t\t\t\n\n", descripcion);
    printf("ID \tMarca\t\tTipo\t\tColor\t   Cilindrada\n");
    printf("--------------------------------------------------------------------------------------");
    printf("\n");


    if(motos != NULL && colores != NULL && tipos != NULL && tam > 0 && tamC > 0 && tamT > 0){

        for(int i = 0; i < tam; i++){

            if(motos[i].idTipo == idTipo && motos[i].isEmpty == 0){

                mostrarUnaMoto(motos[i], tipos, tamT, colores, tamC);
                printf("\n");
                todoOK = 1;
                flag = 0;
            }
        }
        if(flag){
            printf("\nNo hay motos ingresadas del tipo : %s", descripcion);
        }
    }
    printf("\n");
    return todoOK;
}

int mayorCilindrada(eMoto motos[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){


    int todoOK = 0;
    int totalCilindrada;
    int totalMotos[tam];
    int flag = 0;
    int mayor = 0;

    if(motos != NULL && tam > 0 && tamT > 0 && tipos != NULL && tamC > 0 && colores != NULL){

            for(int i = 0; i < tam; i++){

            totalCilindrada = 0;

                if(motos[i].isEmpty == 0){

                    totalCilindrada += motos[i].cilindrada;
                }
            totalMotos[i] = totalCilindrada;
            }



        for(int i = 0; i < tam; i++){

            if(flag == 0 || totalMotos[i] > mayor){
                mayor = totalMotos[i];
                flag = 1;
            }
        }

        for(int i = 0; i < tam; i++){

            if(totalMotos[i] == mayor){

                printf("\n----------------------------------------------------\n");
                printf("La moto con mayor cilindrada: ");
                printf("%s\n", motos[i].marca);
                printf("Cilindrada: %d", totalMotos[i]);
                printf("\n----------------------------------------------------\n");
                todoOK = 1;
            }
        }

        if(flag == 0){
            printf("\nNo hay ninguna moto para mostrar");
        }
    }

    printf("\n");

    return todoOK;
}

int listarMotosTodoTipos(eMoto motos[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){

    int todoOK = 0;
    int flag;

    if(motos != NULL && tam > 0 && tamC > 0 && colores != NULL && tipos != NULL && tamT > 0){


        printf("\n\t\t\tListado de Motos \t\t\t\n\n");
        printf("ID \tMarca\t\tTipo\t\tColor\t   Cilindrada\n");
        printf("--------------------------------------------------------------------");
        for(int i = 0; i < tamT; i++){

            printf("\n\t\t\t TIPO: %s\t\t\t\n", tipos[i].descripcion);
            printf("--------------------------------------------------------------------\n");
            printf("\n");
            flag = 1;
            for(int j = 0; j < tam; j++){

                if(motos[j].idTipo == tipos[i].id && motos[j].isEmpty == 0){

                    mostrarUnaMoto(motos[j], tipos, tamT, colores, tamC);
                    printf("\n");
                    flag = 0;

                }
            }
            if(flag){
                printf("\t\tNo hay motos para mostrar con este tipo\n");
            }
        }
        todoOK = 1;
        printf("\n");
    }

    return todoOK;
}

int contarMotosColorTipo(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

    int idColor;
    int idTipo;
    int todoOK = 1;
    char descripcionColor[20];
    char descripcionTipo[20];
    int flag = 1;
    int contTipoColor = 0;

    mostrarColores(colores, tamC);
    printf("\nIngrese Id del Color: ");
    fflush(stdin);
    scanf("%d", &idColor);
    while(validarIdColor(idColor, colores, tamC) == 0){
        printf("\nId Invalido. Reingrese id del Color: ");
        fflush(stdin);
        scanf("%d", &idColor);
    }

    mostrarTipos(tipos, tamT);
    printf("\nIngrese Id del Tipo: ");
    fflush(stdin);
    scanf("%d", &idTipo);
    while(validarIdTipo(idTipo, tipos, tamT) == 0){
        printf("\nId Invalido. Reingrese id del tipo: ");
        fflush(stdin);
        scanf("%d", &idTipo);
    }

    printf("\n\n");
    cargarDescripcionColor(idColor, colores, tamC, descripcionColor);
    cargarDescripcionTipo(idTipo, tipos, tamT, descripcionTipo);

    printf("\t\t\tLas Motos del color: %s y del tipo %s \t\t\t\n\n", descripcionColor, descripcionTipo);
    printf("--------------------------------------------------------------------------------------");
    printf("\n");


    if(motos != NULL && colores != NULL && tipos != NULL && tam > 0 && tamC > 0 && tamT > 0){

        for(int i = 0; i < tam; i++){

            if(motos[i].idColor == idColor && motos[i].idTipo == idTipo && motos[i].isEmpty == 0){

                contTipoColor++;
                todoOK = 1;
                flag = 0;
            }
        }
        }

        if(flag){
            printf("\nNo hay motos ingresadas del color: %s y del tipo: %s", descripcionColor, descripcionTipo);
        }
        else{
            printf("\nHay un numero de %d motos del color %s y del tipo %s", contTipoColor ,descripcionColor, descripcionTipo);
        }

    printf("\n");
    return todoOK;
}

int colorMasElegido(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){


    int todoOK = 0;
    int contColorElegido;
    int totalColor[tamC];
    int flag = 0;
    int mayor = 0;

    if(motos != NULL && tam > 0 && tamT > 0 && tipos != NULL && tamC > 0 && colores != NULL){

        for(int c = 0; c < tamC; c++){

            contColorElegido = 0;

            for(int m = 0; m < tam; m++){

                if(motos[m].idColor == colores[c].id && motos[m].isEmpty == 0){

                    contColorElegido++;
                }
            }
            totalColor[c] = contColorElegido;

        }


        for(int i = 0; i < tamC; i++){

            if(flag == 0 || totalColor[i] > mayor){
                mayor = totalColor[i];
                flag = 1;
            }
        }

        for(int i = 0; i < tamC; i++){

            if(totalColor[i] == mayor){

                printf("\n----------------------------------------------------\n");
                printf("El color mas elegido: ");
                printf("Color %s\n", colores[i].nombreColor);
                printf("Cantidad de veces que se eligio: %d", totalColor[i]);
                printf("\n----------------------------------------------------\n");
                todoOK = 1;
            }
        }

        if(flag == 0){
            printf("\nNo hay ninguna moto para mostrar");
        }
    }
    printf("\n");

    return todoOK;
}

int trabajoUnaMoto(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi,
                          eColor colores[], int tamC, eServicio servicio[], int tamS){

         int cantServicios = 0;
         int idMoto;
         int flag = 1;
         int exito = 0;
         char marcaMoto[20];
         char nombreServicio[tamS][25];

         mostrarMotos(motos, tam, tipos, tamTi, colores, tamC);
         printf("\n\n\tEl trabajo de la moto\n\n");
         printf("Ingrese nuemero de ID de la Moto: ");
         fflush(stdin);
         scanf("%d", &idMoto);
         while(buscarMoto(motos, tam, idMoto) == -1){

            printf("ID de Moto no valido. Reingrese nuemero de ID de la Moto: ");
            fflush(stdin);
            scanf("%d", &idMoto);

         }
         printf("\n");

             if(trabajo != NULL && tamTra > 0 && motos != NULL && tam > 0 && tipos != NULL && tamTi > 0 && colores != NULL
                && tamC > 0 && servicio != NULL && tamS > 0) {

                  for(int i = 0; i < tamTra; i++){

                    if(trabajo[i].idBicicleta == idMoto && trabajo[i].isEmpty == 0){

                        for(int j = 0; j < tamS; j++){

                            if(servicio[j].id == trabajo[i].idServicio){

                                flag = 0;
                                cantServicios++;
                                strcpy(nombreServicio[j], servicio[j].descripcion);
                            }
                        }

                        if(flag == 0){
                        mostrarUnTrabajo(trabajo[i], motos, tam, servicio, tamS);
                        }
                    }
                  }
                  if(flag){
                    printf("\n\nLa moto con el ID %d no registra ningun trabajo", idMoto);
                    exito = 1;
                  }
                  else{
                    cargarMarcaMoto(idMoto, motos, tam, marcaMoto);
                    printf("\nLa cantidad de trabajos que se realizaron en la moto %s de ID %d fueron : %d", marcaMoto, idMoto, cantServicios);
                    exito = 1;
                  }
                }
          return exito;
}

int importeTrabajoUnaMoto(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi,
                          eColor colores[], int tamC, eServicio servicio[], int tamS){


         float acuTrabajo;
         int idMoto;
         int flag = 1;
         int exito = 0;
         char marcaMoto[20];

         mostrarMotos(motos, tam, tipos, tamTi, colores, tamC);
         printf("\n\n\tEl trabajo de la moto\n\n");
         printf("Ingrese nuemero de ID de la Moto: ");
         fflush(stdin);
         scanf("%d", &idMoto);
         while(buscarMoto(motos, tam, idMoto) == -1){

            printf("ID de Moto no valido. Reingrese nuemero de ID de la Moto: ");
            fflush(stdin);
            scanf("%d", &idMoto);

         }
         printf("\n");

             if(trabajo != NULL && tamTra > 0 && motos != NULL && tam > 0 && tipos != NULL && tamTi > 0 && colores != NULL
                && tamC > 0 && servicio != NULL && tamS > 0) {

                  for(int i = 0; i < tamTra; i++){

                    if(trabajo[i].idBicicleta == idMoto && trabajo[i].isEmpty == 0){

                        for(int j = 0; j < tamS; j++){

                            if(servicio[j].id == trabajo[i].idServicio){

                                acuTrabajo += servicio[j].precio;
                                flag = 0;
                            }
                        }

                    mostrarUnTrabajo(trabajo[i], motos, tam, servicio, tamS);
                    }
                  }
                  if(flag){
                    printf("\n\nLa moto con el ID %d no registra ningun trabajo", idMoto);
                    exito = 1;
                  }
                  else{
                    cargarMarcaMoto(idMoto, motos, tam, marcaMoto);
                    printf("\n\nEl importe total del trabajo realizado en la moto %s con el ID %d es de $%.2f", marcaMoto, idMoto, acuTrabajo);
                    exito = 1;
                  }
                }
          return exito;
}

int mostrarFechasMotosServicios(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi,
                          eColor colores[], int tamC, eServicio servicio[], int tamS){

        int exito = 0;
        int idServicio;
        char nombreServicio[25];
        char marcaMoto[20];
        int flag = 1;

        mostrarServicios(servicio, tamS);
        printf("\nIngrese Id del servicio para mostrar el trabajo realizado: ");
        fflush(stdin);
        scanf("%d", &idServicio);

        while(validarIdServicios(idServicio, servicio, tamS) == 0){
            printf("\nID Invalido. Reingrese Id del servicio para mostrar el trabajo realizado: ");
            fflush(stdin);
            scanf("%d", &idServicio);
        }
            if(trabajo != NULL && tamTra > 0 && motos != NULL && tam > 0 && tipos != NULL && tamTi > 0 && colores != NULL
                && tamC > 0 && servicio != NULL && tamS > 0) {

                 cargarDescripcionServicio(idServicio, servicio, tamS, nombreServicio);
                 printf("\n\nServicio realizado %s: ", nombreServicio);
                 printf("\n\n");
                 for(int t = 0; t < tamTra; t++){

                    if(trabajo[t].idServicio == idServicio && trabajo[t].isEmpty == 0){

                        cargarMarcaMoto(trabajo[t].idBicicleta, motos, tam, marcaMoto);
                        printf("La moto es %s, con su ID (de moto) %d. La fecha en la que se realizo %d/%02d/%d",marcaMoto, trabajo[t].idBicicleta, trabajo[t].fecha.dia, trabajo[t].fecha.mes, trabajo[t].fecha.anio);
                        printf("\n");
                        flag = 0;
                        exito = 1;
                    }
                 }
                 if(flag){
                    printf("Ese servicio no se realizo en ninguna moto\n");
                 }
            }
      return exito;
}


int serviciosEnUnaFecha(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi,
                          eColor colores[], int tamC, eServicio servicio[], int tamS){


         eFecha fechaTrabajo;
         int flag = 1;
         int cantServicios;
         int cantidad;
         int exito = 0;

         mostrarTrabajos(trabajo, tamTra, motos, tam, servicio, tamS);
         printf("\nIngrese la fecha del trabajo dd/mm/aaaa: ");
         fflush(stdin);
         cantidad = scanf("%d/%d/%d", &fechaTrabajo.dia, &fechaTrabajo.mes, &fechaTrabajo.anio);
         while(cantidad != 3){

         printf("\nIngrese la fecha del trabajo dd/mm/aaaa: ");
         fflush(stdin);
         cantidad = scanf("%d/%d/%d", &fechaTrabajo.dia, &fechaTrabajo.mes, &fechaTrabajo.anio);
         }
         printf("\n\n");

             if(trabajo != NULL && tamTra > 0 && motos != NULL && tam > 0 && tipos != NULL && tamTi > 0 && colores != NULL
                && tamC > 0 && servicio != NULL && tamS > 0) {

                for(int s = 0; s < tamS; s++){

                    cantServicios = 0;
                    printf("\nServicio de la fecha: %s\n", servicio[s].descripcion);
                    printf("------------------------------------------------------------------------------------------\n");

                        for(int i = 0; i < tamTra; i++){

                            if(trabajo[i].fecha.dia == fechaTrabajo.dia && trabajo[i].fecha.mes == fechaTrabajo.mes
                            && trabajo[i].fecha.anio == fechaTrabajo.anio && trabajo[i].isEmpty == 0 && trabajo[i].idServicio == servicio[s].id){

                                cantServicios++;
                                flag = 0;
                                mostrarUnTrabajo(trabajo[i], motos, tam, servicio, tamS);

                            }
                        }

                  if(flag || cantServicios == 0){
                    printf("No hubo servicios de %s en el dia %d/%02d/%d", servicio[s].descripcion, fechaTrabajo.dia,
                           fechaTrabajo.mes, fechaTrabajo.anio);
                    exito = 1;
                  }

                  else if(flag == 0 && cantServicios != 0){
                    printf("\nLa cantidad de servicios de %s que se realizaron el dia %d/%02d/%d fueron : %d", servicio[s].descripcion,
                           fechaTrabajo.dia, fechaTrabajo.mes, fechaTrabajo.anio, cantServicios);
                    exito = 1;
                  }
                  printf("\n\n");
                }
            }
        return exito;
}
