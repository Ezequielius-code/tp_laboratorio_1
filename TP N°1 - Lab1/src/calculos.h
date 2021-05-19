/*
 * operaciones.h
 *
 *  Created on: 10 abr. 2021
 *      Author:  Brutto, Ezequiel Andr�s
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/*
 * brief Recibe dos n�meros y hace una suma.
 * param1 Recibe el primer n�mero.
 * param2 Recibe el segundo n�mero.
 * return Devuelve el resultado de la suma de los n�meros recibidos.
 */
float addition (float a, float b);

/*
 * brief Recibe dos n�meros y hace una resta.
 * param1 Primer n�mero, es el minuendo.
 * param2 Segundo n�mero, el sustraendo.
 * return Devuelve la diferencia entre minuendo y sustraendo.
 */
float subtraction (float a, float b);

/*
 * brief Recibe dos n�meros y los multiplica.
 * param1 Primer n�mero, el multiplicando.
 * param2 Segundo n�mero, el multiplicador.
 * return Devuelve el producto entre los dos n�meros recibidos.
 */
float multiplication (float a, float b);

/*
 * brief Recibe dos n�meros y efect�a una divisi�n.
 * param1 Primer n�mero, el dividendo.
 * param2 Segundo n�mero, el divisor.
 * return Devuelve el cociente de la divisi�n como resultado.
 */
float division (float a, float b);

/*
 * brief Recibe un n�mero de tipo float y valida si es un n�mero entero.
 * param1 N�mero float a ser evaluado.
 * return Devuelve 0 si el n�mero posee decimales, y 1 si el n�mero es entero,
 *        es decir, si los decimales despu�s de la coma no tienen valor.
 */
int isInteger (float a);

/*
 * brief Recibe un n�mero.
 * param1 El n�mero recibido puede considerarse n.
 * return Devuelve el valor del producto de todos los n�meros enteros
 *        positivos desde 1 hasta n.
 */
int factorial (float a);

#endif /* OPERACIONES_H_ */
