#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;

/** \brief carga la descripcion del color en un array de caracteres, utilizando un numero de id
 *
 * \param id int numero de identificador
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \param descr[] char array de caracteres
 * \return int devuelve 1 si se pudo cargar, sino 0
 *
 */
int cargarDescripcionColor(int id, eColor colores[], int tam, char descr[]);

/** \brief muestra la lista de colores
 *
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \return void no devuelve nada
 *
 */
void mostrarColores(eColor colores[], int tam);

/** \brief muestra un color
 *
 * \param unColor eColor un color
 * \return void no devuelve nada
 *
 */
void mostrarUnColor(eColor unColor);


#endif // COLOR_H_INCLUDED
