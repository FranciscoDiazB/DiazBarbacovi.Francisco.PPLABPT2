#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "moto.h"


void inicializarMotos(eMoto motos[], int tam){

    for(int i = 0; i < tam; i++){

        motos[i].isEmpty = 1;
    }
}


int buscarLibreMoto(eMoto motos[], int tam){

    int retorno = -1;

    for(int i = 0; i < tam; i++){

        if(motos[i].isEmpty){
            retorno = i;
            break;
        }
    }
    return retorno;
}

int altaMoto(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT, int* pId){

    int todoOK = 0;
    int indice;
    eMoto motoNueva;

    system("cls");
    printf("\t\tAlta Moto\n\n");
    printf("El numero de identificacion de la moto es : %d", *pId);
    printf("\n\n");

    if(motos != NULL && tam > 0 && pId != NULL && tipos != NULL && tamC > 0 && tamT > 0 && colores != NULL){

        indice = buscarLibreMoto(motos, tam);

        if(indice == -1){
            printf("No hay lugar en el sistema para el ingreso de nueva moto\n");
        }
        else{

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(motoNueva.marca);
            printf("\n");

            mostrarTipos(tipos, tamT);
            printf("Ingrese tipo de la moto: ");
            fflush(stdin);
            scanf("%d", &motoNueva.idTipo);
            while(motoNueva.idTipo < 1000 || motoNueva.idTipo > 1003){
                printf("Tipo invalido. Reingrese el tipo: ");
                fflush(stdin);
                scanf("%d", &motoNueva.idTipo);
                system("pause");
            }
            printf("\n");

            mostrarColores(colores, tamC);
            printf("Ingrese color de la moto: ");
            fflush(stdin);
            scanf("%d", &motoNueva.idColor);
            while(motoNueva.idColor < 10000 || motoNueva.idColor > 10004){
                 printf("Color invalido. Reingrese color de la moto: ");
                 fflush(stdin);
                 scanf("%d", &motoNueva.idColor);
                 system("pause");
            }
            printf("\n");

            printf("Ingrese cilindrada de la moto (50, 125, 500, 600 o 750): ");
            fflush(stdin);
            scanf("%d", &motoNueva.cilindrada);
            while(motoNueva.cilindrada != 50 && motoNueva.cilindrada != 125 && motoNueva.cilindrada != 500 &&
                  motoNueva.cilindrada != 600 && motoNueva.cilindrada != 750){
                 printf("Cilindrada incorrecta. Reingrese cilindrida (50, 125, 500, 600 o 750): ");
                 fflush(stdin);
                 scanf("%d", &motoNueva.cilindrada);
                 system("pause");
            }
            printf("\n");

            motoNueva.id = *pId;
            (*pId)++;
            motoNueva.isEmpty = 0;

            motos[indice] = motoNueva;
            todoOK = 1;

            }
       }

    return todoOK;
}

int mostrarMotos(eMoto motos[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC){

int exito = 0;
int flag = 1;

printf("\t\t\tListado de Motos\t\t\t\n\n");
printf("ID\tMarca\t\tTipo\t     Color\tCilindrada\n");
printf("----------------------------------------------------------------------------------");
printf("\n\n");

    for(int i = 0; i < tam; i++){

        if(motos[i].isEmpty == 0){
            mostrarUnaMoto(motos[i], tipos, tamT, colores, tamC);
            printf("\n");
            flag = 0;
            exito = 1;
        }
    }
    if(flag){
        printf("No hay motos que mostrar");
    }

    return exito;
}

void mostrarUnaMoto(eMoto unaMoto, eTipo tipos[], int tamT, eColor colores[], int tamC){

    char descripcionTipo[20];
    char nombreColor[20];

    if(cargarDescripcionColor(unaMoto.idColor, colores, tamC, nombreColor) &&
       cargarDescripcionTipo(unaMoto.idTipo, tipos, tamT, descripcionTipo)){

        printf("%d\t%-10s\t%-10s\t%-10s\t%d\n",
            unaMoto.id,
            unaMoto.marca,
            descripcionTipo,
            nombreColor,
            unaMoto.cilindrada);
    }
}

int buscarMoto(eMoto motos[], int tam, int idMoto){

    int indice = -1;

    if(motos != NULL && tam > 0){
        for(int i = 0; i < tam; i++){

            if(motos[i].id == idMoto && motos[i].isEmpty == 0){

                indice = i;
                break;
            }
        }
    }
    return indice;
}

int modificarMoto(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

    int todoOK = 0;
    int indice;
    int introducirId;
    char respuesta;
    int opcionModificar;

    printf("\n\t\t\tModificar Motos\n");
    mostrarMotos(motos, tam, tipos, tamT, colores, tamC);

    printf("\nIntroduzca numero de ID de la moto: ");
    fflush(stdin);
    scanf("%d", &introducirId);
    if(buscarMoto(motos, tam, introducirId) == -1){
        printf("\n\nNo existen motos con ese ID\n");
        printf("Reingrese numero de ID de la moto: ");
        fflush(stdin);
        scanf("%d", &introducirId);
    }
    printf("\n");

    if(motos != NULL && tam > 0 && tamC > 0 && colores != NULL && tipos != NULL && tamT > 0){

        indice = buscarMoto(motos, tam, introducirId);

                if( indice == -1){
                        printf("\nNo hay motos para modificar");
                }
                else{
                    mostrarUnaMoto(motos[indice], tipos, tamT, colores, tamC);

                    printf("\n\nDesea seguir con la modificacion? Marque 's' para Si y 'n' para No (en minuscula).\n");
                    fflush(stdin);
                    respuesta = getchar();

                    if(respuesta == 's'){
                        printf("\n1. Modificar Color\n");
                        printf("2. Modificar Cilindrada\n");
                        printf("\nIngrese el numero correspondiente a la caracteristica que desea modificar: ");
                        fflush(stdin);
                        scanf("%d", &opcionModificar);

                        switch(opcionModificar){

                            case 1:
                                mostrarColores(colores, tamC);
                                printf("Ingrese nuevo ID del color: ");
                                fflush(stdin);
                                scanf("%d", &motos[indice].idColor);
                                while(motos[indice].idColor < 10000 || motos[indice].idColor > 10004){
                                        printf("Color invalido. Reingrese color de la moto: ");
                                        fflush(stdin);
                                        scanf("%d", &motos[indice].idColor);
                                        system("pause");
                                }
                                todoOK = 1;
                                break;

                            case 2:
                                printf("Ingrese nueva cilindrada (50, 125, 500, 600 o 750): ");
                                fflush(stdin);
                                scanf("%d", &motos[indice].cilindrada);
                                while(motos[indice].cilindrada != 50 && motos[indice].cilindrada != 125 && motos[indice].cilindrada != 500 &&
                                      motos[indice].cilindrada != 600 && motos[indice].cilindrada != 750){
                                            printf("Cilindrada incorrecta. Reingrese cilindrida (50, 125, 500, 600 o 750): ");
                                            fflush(stdin);
                                            scanf("%d", &motos[indice].cilindrada);
                                            system("pause");
                                }
                                todoOK = 1;
                                break;

                            default:
                                printf("Dato invalido");
                                break;

                        }
                    }
                    else{
                        printf("\nModificacion cancelada por el usuario");
                    }
                }

    }

    return todoOK;

}

int bajaMoto(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT){

    int todoOk = 0;
    int indice = -1;
    int idMoto;
    char respuesta;

    printf("\n\t\t\tBaja Motos\n");
    mostrarMotos(motos, tam, tipos, tamT, colores, tamC);

    printf("\nIntroduzca numero de ID de la moto: ");
    fflush(stdin);
    scanf("%d", &idMoto);
    printf("\n");
    while(buscarMoto(motos, tam, idMoto) == -1){
        printf("Dato invalido. Reintroduzca numero de ID: ");
        fflush(stdin);
        scanf("%d", &idMoto);
        system("pause");
    }

    if(motos != NULL && tam > 0 && colores != NULL && tamC > 0 && tipos !=  NULL && tamT > 0){

        indice = buscarMoto(motos, tam, idMoto);

        if(indice == -1){

            printf("No existe una moto con ese numero de ID : %d", idMoto);
        }
        else{
            mostrarUnaMoto(motos[indice], tipos, tamT, colores, tamC);
            printf("\n\nEste es la moto que busca? Marque 's' para Si y 'n' para No (en minuscula).\n");
            fflush(stdin);
            respuesta = getchar();
            if(respuesta == 's'){
                motos[indice].isEmpty = 1;
                todoOk = 1;
            }
            else{
                printf("Baja cancelada por el usuario");
            }
        }
    }
    return todoOk;
}

int cargarMarcaMoto(int id, eMoto motos[], int tam, char marca[]){

    int todoOK = 0;
    int indice;

    if(motos != NULL && tam > 0 && marca != NULL){

        indice = buscarMoto(motos, tam, id);

        if(indice != -1){

            strcpy(marca, motos[indice].marca);
            todoOK = 1;
        }
    }
    return todoOK;
}
