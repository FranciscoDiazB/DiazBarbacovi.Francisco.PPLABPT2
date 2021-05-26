#include "color.h"
#include "tipo.h"


#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int isEmpty;

}eMoto;

/** \brief inicializa el campo is empty en 1
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array
 * \return void no devuelve nada
 *
 */
void inicializarMotos(eMoto motos[], int tam);

/** \brief busca el espacio libre de motos
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \return int deuvelve el indice libre
 *
 */
int buscarLibreMoto(eMoto motos[], int tam);

/** \brief en un campo is empty igual a 1, ingresa una nueva moto y asigna un numero de identificador incremental
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamanio del array de tipos
 * \param pId int* puntero numero de identificador pasado por referencia
 * \return int devuelve 1 si se pudo registrar, sino 0
 *
 */
int altaMoto(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT, int* pId);

/** \brief muestra todas las motos
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamanio del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \return int devuelve 1 si se pudo mostrar, sino 0
 *
 */
int mostrarMotos(eMoto motos[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/** \brief muestra una moto
 *
 * \param unaMoto eMoto una moto
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamanio del array de tipos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \return void no devuelve
 *
 */
void mostrarUnaMoto(eMoto unaMoto, eTipo tipos[], int tamT, eColor colores[], int tamC);

/** \brief busca una moto usando el numero de identificador (su campo tiene que ser 0)
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array
 * \param idMoto int numero de identificador
 * \return int devuelve 1 si es valido, sino 0
 *
 */
int buscarMoto(eMoto motos[], int tam, int idMoto);

/** \brief utilizando el numero de identificador de moto, modifica esa moto (tiene que estar registrada)
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamanio del array de tipos
 * \return int devuelve 1 si se pudo modificar, sino 0
 *
 */
int modificarMoto(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief utilizando el numero de identificador de moto, cambia su campo a is empty igual a 1 (tiene que estar registrada)
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de colores
 * \param tamC int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamanio del array de tipos
 * \return int devuelve 1 si se pudo realizar la baja, sino 0
 *
 */
int bajaMoto(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief carga la marca de la moto en un array de caracteres, utilizando numero de id
 *
 * \param id int numero de identificador
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param marca[] char array de caracteres (cadena de caracteres)
 * \return int devuelve 1 si se pudo cargar, sino 0.
 *
 */
int cargarMarcaMoto(int id, eMoto motos[], int tam, char marca[]);



#endif // MOTO_H_INCLUDED
