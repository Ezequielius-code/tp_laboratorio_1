/*
 * utn.h
 *
 *  Biblioteca de funciones UTN.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Solicita un número al usuario, luego de verificarlo devuelve el resultado.
 * \param resultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es el número mínimo a ser aceptado.
 * \param maximo Es el número máximo a ser aceptado.
 * \return Retorna 0 si se obtuvo el número y -1 si no.
 *
 */
int utn_getNumero(int *resultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos);

/**
 * \brief Solicita un número float al usuario, luego de verificarlo devuelve el resultado.
 * \param resultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es el número mínimo a ser aceptado.
 * \param maximo Es el número máximo a ser aceptado.
 * \return Retorna 0 si se obtuvo el número y -1 si no.
 *
 */
int utn_getNumeroFlotante(float *resultado,char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos);

/**
 * \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado.
 * \param resultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es uno de los caracteres a ser aceptado.
 * \param maximo Es el otro caracter a ser aceptado.
 * \return Retorna 0 si se obtuvo el caracter y -1 si no.
 *
 */
int utn_getCaracter(char *resultado,char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos);

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param longitud Define el tamaño de cadena.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param reintentos Recibe la cantidad de reintentos que habrá para ingresar el dato correcto en caso de error.
 * \return Retorna 0 si se obtuvo el número y -1 si no.
 */
int utn_getNombre(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);

/**
 * \brief Solicita una fecha en formato (dd/mm/aaaa) al usuario, verifica el string y devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param longitud Define el tamaño de cadena.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError mensajeError Es el mensaje de error a ser mostrado.
 * \param reintentos Recibe la cantidad de reintentos que habrá para ingresar el dato correcto en caso de error.
 * \return Retorna 0 si se obtuvo el número y -1 si no.
 */
int utn_getFecha(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);

#endif /* UTN_H_ */
