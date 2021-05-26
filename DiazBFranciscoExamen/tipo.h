#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

/** \brief carga la descripcion utilizando el numero de identificador, a un array de caracteres (cadena de caracteres)
 *
 * \param id int numero de identificador
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \param descr[] char array de caracteres (cadena de caracteres)
 * \return int si se pudo hacer devuelve 1, sino 0.
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char descr[]);

/** \brief muestra todos los tipos
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \return void no devuelve
 *
 */
void mostrarTipos(eTipo tipos[], int tam);

/** \brief muestra un tipo
 *
 * \param unTipo eTipo un tipo solo
 * \return void no devuelve
 *
 */
void mostrarUnTipo(eTipo unTipo);

#endif // TIPO_H_INCLUDED
