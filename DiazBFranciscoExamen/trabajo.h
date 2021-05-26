#include "fecha.h"
#include "moto.h"
#include "tipo.h"
#include "color.h"
#include "servicios.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int idTra;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

/** \brief inicializa el campo de is empty en 1
 *
 * \param trabajo[] eTrabajo
 * \param tam int
 * \return void
 *
 */
void inicializarTrabajo(eTrabajo trabajo[], int tam);

/** \brief busca donde haya campos is empty 1 (libres) y pasa el indice
 *
 * \param trabajo[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[], int tam);

/** \brief busca un indice libre, y registra un trabajo de una moto, cambiando su campo is empty a 0
 *
 * \param trabajo[] eTrabajo
 * \param tamTra int
 * \param motos[] eMoto
 * \param tam int
 * \param tipos[] eTipo
 * \param tamTi int
 * \param colores[] eColor
 * \param tamC int
 * \param servicio[] eServicio
 * \param tamS int
 * \param pNextId int*
 * \return int
 *
 */
int altaTrabajo(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi, eColor colores[], int tamC, eServicio servicio[], int tamS, int* pNextId);

/** \brief muestra todos los trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param motos[] eMoto
 * \param tam int
 * \param servicio[] eServicio
 * \param tamS int
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamTra, eMoto motos[], int tam, eServicio servicio[], int tamS);

/** \brief muestra un trabajo
 *
 * \param unTrabajo eTrabajo
 * \param motos[] eMoto
 * \param tam int
 * \param servicio[] eServicio
 * \param tamS int
 * \return void
 *
 */
void mostrarUnTrabajo(eTrabajo unTrabajo, eMoto motos[], int tam, eServicio servicio[], int tamS);

#endif // TRABAJO_H_INCLUDED
