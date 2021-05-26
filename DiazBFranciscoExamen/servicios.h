#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;

}eServicio;

/** \brief carga la descripcion del servicio a una cadena de caracteres, utilzando el id
 *
 * \param id int nuermo de id
 * \param servicio[] eServicio array de servicios
 * \param tam int atamnios del array
 * \param descr[] char cadena de caracteres
 * \return int devuelve 1 si pudo cargarlo, sino 0
 *
 */
int cargarDescripcionServicio(int id, eServicio servicio[], int tam, char descr[]);

/** \brief muestra todos los servicios
 *
 * \param servicio[] eServicio array de servicios
 * \param tam int tamanio del array
 * \return void no devuelve nada
 *
 */
void mostrarServicios(eServicio servicio[], int tam);

/** \brief muestra un servicio especifico
 *
 * \param unServicio eServicio un servicio
 * \return void no devuelve nada
 *
 */
void mostrarUnServicio(eServicio unServicio);

/** \brief valida un id de servicios, devolviendo 1 si es valido, sino devuelve 0
 *
 * \param id int numero de id
 * \param servicios[] eServicio array de servicios
 * \param tam int tamanio del array
 * \return int devuelve 1 si es valido el numero de id, sino 0
 *
 */
int validarIdServicios(int id, eServicio servicios[], int tam);

/** \brief utilizando el id de servicios, carga en una variable flotante el precio del servicio
 *
 * \param id int numero de id
 * \param servicio[] eServicio array de servicios
 * \param tam int tamanio del array
 * \param precio float* puntero flotante pasado por referencia
 * \return int deuvelve 1 si se pudo cargar, sino devuelve 0.
 *
 */
int cargarValorServicio(int id, eServicio servicio[], int tam, float* precio);

#endif // SERVICIOS_H_INCLUDED
