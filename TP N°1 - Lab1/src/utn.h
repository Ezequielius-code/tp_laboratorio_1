/*
 * utn.h
 *
 *  Created on: 12 abr. 2021
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef UTN_H_
#define UTN_H_

/*
 * brief Recibe un número de tipo float para validarlo mediante un flag,
 * 		 1 si se cargó correctamente, y 0 si hubo un error.
 * param1 Número de tipo float (operando).
 * param2 Indicación para el usuario.
 * return Si la carga fue exitosa, devuelve el número ingresado por el
 * 		  usuario, de lo contrario, devuelve error.
 */

int getFloat(float* operand, char[]);

/*
 * brief Recibe un número entero ingresado por el usuario.
 * param1 Indicación para el usuario.
 * return Devuelve la el número ingresado por el usuario
 * 		  para acceder a una opción.
 */
int getInt(char[]);


#endif /* UTN_H_ */
