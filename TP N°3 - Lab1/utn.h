/*
 * utn.h
 * 	Biblioteca de Funciones UTN.
 *      Author: Brutto, Ezequiel Andr�s
 */
#ifndef UTN_H_
#define UTN_H_


/*
 * brief pide un entero, valida que se encuentre entre un m�nimo y un m�ximo.
 * param recibe el texto para pedir el n�mero.
 * param texto alternativo, en caso de error.
 * return retorna el n�mero ingresado, validado.
 */
int utn_getNumero (char *texto,char *textoError,int min,int max);

/*
 * brief Valida que el n�mero ingresado en utn_getNumero
 *       este dentro de los valores correspondientes.
 * param n�mero entero ingresado.
 * param menor valor permitido.
 * param mayor valor permitido.
 * return (1) falso ; (0) verdadero.
 */
int ValidarMinMax(int dato,int min,int max);

/*
 * brief pide un float, valida que se encuentre entre un m�nimo y un m�ximo.
 * param recibe el texto para pedir el n�mero.
 * param texto alternativo, en caso de error.
 * return retorna el n�mero ingresado, validado.
 */
float utn_getNumeroFlotante(char *texto,char *textoError,float min,float max);

/*
 * brief Valida que el n�mero ingresado en utn_getNumero
 *       este dentro de los valores correspondientes.
 * param n�mero entero ingresado.
 * param menor valor permitido.
 * param mayor valor permitido.
 * return (1) falso ; (0) verdadero.
 */
int ValidarMinMaxFloat(float dato,float min,float max);

/*
 * brief pide el ingreso de una cadea de caracteres.
 * param recibe la direcci�n donde guardar� el array.
 * param texto que solicita el ingreso de la cadena.
 * param tama�o de la cadena.
 * return no retorna, solo guarda el ingreso en la cadena pasada por par�metro.
 */
int utn_GetName(char name[],char text[],int tam);


/*
 * brief valida que los caracteres ingresados en utn_GetName sean alfab�ticos.
 * param cadena donde se guard� la cadena.
 * param l�mite de la cadena.
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
 * brief carga la primera posici�n disponible dentro de un array.
 * param recibe el array a cargar.
 * param recibe la longitud del array.
 * param numero a cargar en el array.
 * return si se carga con �xito retorna (1), si no (0).
 */
int CargaSecuencialArrayInt(int array[],int tam,int dato);

/*
 * brief crga un dato en la posici�n solicitada.
 * param recibe la longitud del array.
 * param recibe el dato que se quiere cargar en el array.
 * param recibe la posici�n en donde guardar el dato.
 * return si se carga con �xito retorna (1), si no (0).
 */
int CargaAleatoriaArrayInt(int array[],int tam,int dato,int posicion);


/*
 * brief recibe un array y lo imprime indicando su posici�n
 * param recibe el array a mostrar.
 * param texto que corresponde al dato a mostrar.
 * return si existen datos a mostrar retorna (1), si no (0).
 */
int MostrarArrayInt(int array[],char text[],int tam);


/*
 * brief ordena un array de mayor a menor con el m�todo de burbujeo.
 * param recibe el array a ordenar.
 * param recibe el tama�o del array a ordenar.
 * return retorna la cantidad de iteraciones necesarias para ordenar el array,
 *      si ocurre alg�n error o no se puede ordenar, retorna (-1).
 */
int ordenarArrayInt(int *array,int tam);


/*
 * brief Inicia una cadena de caracteres con el primero en may�scula,
 * 		 y el resto en min�sculas.
 * param recibe el array a "ordenar".
 * param recibe el tama�o del array.
 * return no retorna nada.
 */
void formatName(char name[],int tam);

#endif /* UTN_H_ */
