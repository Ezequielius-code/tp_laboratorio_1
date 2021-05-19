/*
 * operaciones.h
 *
 *  Created on: 10 abr. 2021
 *      Author:  Brutto, Ezequiel Andrés
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

/*
 * brief Recibe dos números y hace una suma.
 * param1 Recibe el primer número.
 * param2 Recibe el segundo número.
 * return Devuelve el resultado de la suma de los números recibidos.
 */
float addition (float a, float b);

/*
 * brief Recibe dos números y hace una resta.
 * param1 Primer número, es el minuendo.
 * param2 Segundo número, el sustraendo.
 * return Devuelve la diferencia entre minuendo y sustraendo.
 */
float subtraction (float a, float b);

/*
 * brief Recibe dos números y los multiplica.
 * param1 Primer número, el multiplicando.
 * param2 Segundo número, el multiplicador.
 * return Devuelve el producto entre los dos números recibidos.
 */
float multiplication (float a, float b);

/*
 * brief Recibe dos números y efectúa una división.
 * param1 Primer número, el dividendo.
 * param2 Segundo número, el divisor.
 * return Devuelve el cociente de la división como resultado.
 */
float division (float a, float b);

/*
 * brief Recibe un número de tipo float y valida si es un número entero.
 * param1 Número float a ser evaluado.
 * return Devuelve 0 si el número posee decimales, y 1 si el número es entero,
 *        es decir, si los decimales después de la coma no tienen valor.
 */
int isInteger (float a);

/*
 * brief Recibe un número.
 * param1 El número recibido puede considerarse n.
 * return Devuelve el valor del producto de todos los números enteros
 *        positivos desde 1 hasta n.
 */
int factorial (float a);

#endif /* OPERACIONES_H_ */
