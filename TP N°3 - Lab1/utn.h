/*
 * utn.h
 * 	Biblioteca de Funciones UTN.
 *      Author: Brutto, Ezequiel Andrés
 */
#ifndef UTN_H_
#define UTN_H_


/*
 * brief pide un entero, valida que se encuentre entre un mínimo y un máximo.
 * param recibe el texto para pedir el número.
 * param texto alternativo, en caso de error.
 * return retorna el número ingresado, validado.
 */
int utn_getNumero (char *texto,char *textoError,int min,int max);

/*
 * brief Valida que el número ingresado en utn_getNumero
 *       este dentro de los valores correspondientes.
 * param número entero ingresado.
 * param menor valor permitido.
 * param mayor valor permitido.
 * return (1) falso ; (0) verdadero.
 */
int ValidarMinMax(int dato,int min,int max);

/*
 * brief pide un float, valida que se encuentre entre un mínimo y un máximo.
 * param recibe el texto para pedir el número.
 * param texto alternativo, en caso de error.
 * return retorna el número ingresado, validado.
 */
float utn_getNumeroFlotante(char *texto,char *textoError,float min,float max);

/*
 * brief Valida que el número ingresado en utn_getNumero
 *       este dentro de los valores correspondientes.
 * param número entero ingresado.
 * param menor valor permitido.
 * param mayor valor permitido.
 * return (1) falso ; (0) verdadero.
 */
int ValidarMinMaxFloat(float dato,float min,float max);

/*
 * brief pide el ingreso de una cadea de caracteres.
 * param recibe la dirección donde guardará el array.
 * param texto que solicita el ingreso de la cadena.
 * param tamaño de la cadena.
 * return no retorna, solo guarda el ingreso en la cadena pasada por parámetro.
 */
int utn_GetName(char name[],char text[],int tam);


/*
 * brief valida que los caracteres ingresados en utn_GetName sean alfabéticos.
 * param cadena donde se guardó la cadena.
 * param límite de la cadena.
 * return En caso de error retorna (1), si no (0).
 */
int isName (char*cadena,int limite);

/*
 * brief recorre un array e inicializa sus posiciones en cero.
 * param recibe el array a inicializar.
 * param recibe la longitud del array.
 * return no retorna nada.
 */
void utn_InitArrayInt(int array[],int tam);

/*
 * brief carga la primera posición disponible dentro de un array.
 * param recibe el array a cargar.
 * param recibe la longitud del array.
 * param numero a cargar en el array.
 * return si se carga con éxito retorna (1), si no (0).
 */
int CargaSecuencialArrayInt(int array[],int tam,int dato);

/*
 * brief crga un dato en la posición solicitada.
 * param recibe la longitud del array.
 * param recibe el dato que se quiere cargar en el array.
 * param recibe la posición en donde guardar el dato.
 * return si se carga con éxito retorna (1), si no (0).
 */
int CargaAleatoriaArrayInt(int array[],int tam,int dato,int posicion);


/*
 * brief recibe un array y lo imprime indicando su posición
 * param recibe el array a mostrar.
 * param texto que corresponde al dato a mostrar.
 * return si existen datos a mostrar retorna (1), si no (0).
 */
int MostrarArrayInt(int array[],char text[],int tam);


/*
 * brief ordena un array de mayor a menor con el método de burbujeo.
 * param recibe el array a ordenar.
 * param recibe el tamaño del array a ordenar.
 * return retorna la cantidad de iteraciones necesarias para ordenar el array,
 *      si ocurre algún error o no se puede ordenar, retorna (-1).
 */
int ordenarArrayInt(int *array,int tam);


/*
 * brief Inicia una cadena de caracteres con el primero en mayúscula,
 * 		 y el resto en minúsculas.
 * param recibe el array a "ordenar".
 * param recibe el tamaño del array.
 * return no retorna nada.
 */
void formatName(char name[],int tam);

#endif /* UTN_H_ */
