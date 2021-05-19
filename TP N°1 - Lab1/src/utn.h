/*
 * utn.h
 *
 *  Created on: 12 abr. 2021
 *      Author: Brutto, Ezequiel Andr�s
 */

#ifndef UTN_H_
#define UTN_H_

/*
 * brief Recibe un n�mero de tipo float para validarlo mediante un flag,
 * 		 1 si se carg� correctamente, y 0 si hubo un error.
 * param1 N�mero de tipo float (operando).
 * param2 Indicaci�n para el usuario.
 * return Si la carga fue exitosa, devuelve el n�mero ingresado por el
 * 		  usuario, de lo contrario, devuelve error.
 */

int getFloat(float* operand, char[]);

/*
 * brief Recibe un n�mero entero ingresado por el usuario.
 * param1 Indicaci�n para el usuario.
 * return Devuelve la el n�mero ingresado por el usuario
 * 		  para acceder a una opci�n.
 */
int getInt(char[]);


#endif /* UTN_H_ */
