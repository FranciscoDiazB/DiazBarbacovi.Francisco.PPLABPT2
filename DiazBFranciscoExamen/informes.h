#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


int validarIdTipo(int id, eTipo tipos[], int tam);



int validarIdColor(int id, eColor colores[], int tam);



/** \brief muestra un listado de motos del color seleccionado
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param tipos[] eTipo array de los tipos
 * \param tamT int tamanio del array de los tipos
 * \return int devuelve 1 si se pudo mostrar, sino devuelve 0
 *
 */
int listarMotosColor(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);


/** \brief muestra un listado de motos del tipo seleccionado
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param tipos[] eTipo array de los tipos
 * \param tamT int tamanio del array de los tipos
 * \return int devuelve 1 si se pudo mostrar, sino devuelve 0
 *
 */
int listarMotosTipo(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);


/** \brief muestra la o las motos (en caso de empate) de mayor cilindrada
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param tipos[] eTipo array de los tipos
 * \param tamT int tamanio del array de los tipos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \return int devuelve 1 si se pudo mostrar, sino devuelve 0
 *
 */
int mayorCilindrada(eMoto motos[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);



/** \brief muestra un listado de motos separados por los diferentes tipos
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param tipos[] eTipo array de los tipos
 * \param tamT int tamanio del array de los tipos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \return int devuelve 1 si se pudo mostrar, sino devuelve 0
 *
 */
int listarMotosTodoTipos(eMoto motos[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);



/** \brief te cuenta la cantidad de motos registradas del tipo y color seleccionado
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param tipos[] eTipo array de los tipos
 * \param tamT int tamanio del array de los tipos
 * \return int devuelve 1 si se pudo contar, sino devuelve 0
 *
 */
int contarMotosColorTipo(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);



/** \brief te muestra cual es el color o los (en caso de empates) mas elegidos, y la cantidad de veces que se eligio
 *
 * \param motos[] eMoto array de motos
 * \param tam int tamanio del array de motos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param tipos[] eTipo array de los tipos
 * \param tamT int tamanio del array de los tipos
 * \return int devuelve 1 si se muestra, en el caso de que no devuelve 0
 *
 */
int colorMasElegido(eMoto motos[], int tam, eColor colores[], int tamC, eTipo tipos[], int tamT);


/** \brief te pido el ingreso del id de una moto, y te muestra los trabajos que se le hicieron
 *
 * \param trabajo[] eTrabajo array de trabajos
 * \param tamTra int el tamanio del array de trabajos
 * \param motos[] eMoto array de motos
 * \param tam int el tamanio del array de motos
 * \param tipos[] eTipo array de los tipos
 * \param tamTi int el tamanio del array de tipos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param servicio[] eServicio array de los servicios
 * \param tamS int el tamanio del array de los servicios
 * \return int devuelve 1 si se pudo mostrar, sino devuelve 0.
 *
 */
int trabajoUnaMoto(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi, eColor colores[], int tamC,
                   eServicio servicio[], int tamS);


/** \brief te pide el ingreso del id de una moto, y te muestra los trabajos que se le hicieron y el dinero recaudado de esos trabajos
 *
 * \param trabajo[] eTrabajo array de trabajos
 * \param tamTra int el tamanio del array de trabajos
 * \param motos[] eMoto array de motos
 * \param tam int el tamanio del array de motos
 * \param tipos[] eTipo array de los tipos
 * \param tamTi int el tamanio del array de tipos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param servicio[] eServicio array de los servicios
 * \param tamS int el tamanio del array de los servicios
 * \return int devuelve 1 si se pudo realizar el acumulado del importe y mostrarlo, sino devulve 0
 *
 */
int importeTrabajoUnaMoto(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi, eColor colores[], int tamC, eServicio servicio[], int tamS);


/** \brief te pide el ingreso de un servicio y te muestra las fechas en la que se realizo ese servicio
 *
 * \param trabajo[] eTrabajo array de trabajos
 * \param tamTra int el tamanio del array de trabajos
 * \param motos[] eMoto array de motos
 * \param tam int el tamanio del array de motos
 * \param tipos[] eTipo array de los tipos
 * \param tamTi int el tamanio del array de tipos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param servicio[] eServicio array de los servicios
 * \param tamS int el tamanio del array de los servicios
 * \return int devuelve 1 si se pudo mostrar las fechas, sino devuelve 0.
 *
 */
int mostrarFechasMotosServicios(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi, eColor colores[],
                                int tamC, eServicio servicio[], int tamS);


/** \brief te pide el ingreso de una fecha y te muestra los trabajos que se realizaron en esa fecha y la cantidad de trabajos
 *
 * \param trabajo[] eTrabajo array de trabajos
 * \param tamTra int el tamanio del array de trabajos
 * \param motos[] eMoto array de motos
 * \param tam int el tamanio del array de motos
 * \param tipos[] eTipo array de los tipos
 * \param tamTi int el tamanio del array de tipos
 * \param colores[] eColor array de los colores
 * \param tamC int tamanio del array de los colores
 * \param servicio[] eServicio array de los servicios
 * \param tamS int el tamanio del array de los servicios
 * \return int devuelve 1 si se pudo mostrar los trabajos realizados y la cantidad, sino devuelve 0.
 *
 */
int serviciosEnUnaFecha(eTrabajo trabajo[], int tamTra, eMoto motos[], int tam, eTipo tipos[], int tamTi, eColor colores[],
                        int tamC, eServicio servicio[], int tamS);

#endif // INFORMES_H_INCLUDED
