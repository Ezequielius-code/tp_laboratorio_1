#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 		  un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiará la cadena obtenida.
 * \param longitud Define el tamaño de cadena.
 * \return Retorna 0 (ÉXITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
static int getString(char *cadena, int longitud);

/**
 * \brief Obtiene un número entero desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \return Retorna 0 (ÉXITO) si se obtiene un número entero y -1 (ERROR) si no.
 *
 */
static int getInt(int *pResultado);

/**
 * \brief Verifica si la cadena ingresada es numérica.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de cadena.
 * \return Retorna 1 (verdadero) si la cadena es numérica y 0 (falso) si no lo es.
 *
 */
static int esNumerica(char *cadena,int limite);

/**
 * \brief Obtiene un número float desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \return Retorna 0 (ÉXITO) si se obtiene un número entero y -1 (ERROR) si no.
 *
 */
static int getFloat(float *pResultado);

/**
 * \brief Verifica si la cadena ingresada es de tipo float.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de cadena.
 * \return Retorna 1 (verdadero) si la cadena es numérica y 0 (falso) si no lo es.
 *
 */
static int esFloat(char *cadena,int limite);

/**
 * \brief Obtiene un caracter desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \return Retorna 0 (ÉXITO) si se obtiene un número entero y -1 (ERROR) si no.
 */
static int getCaracter(char *pResultado);

/**
 * \brief Verifica si la cadena ingresada es de tipo char.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de cadena.
 * \return Retorna 1 (verdadero) si la cadena es numérica y 0 (falso) si no lo es.
 */
static int esCaracter(char *cadena,int limite);

/**
 * \brief Obtiene un nombre desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param longitud Define el tamaño de cadena.
 * \return Retorna 0 (ÉXITO) si se obtiene un nombre y -1 (ERROR) si no.
 *
 */
static int getNombre(char *pResultado, int longitud);

/**
 * \brief Verifica si la cadena ingresada es un array de caracteres(nombre).
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de cadena.
 * \return Retorna 1 (verdadero) si la cadena es alfabetica y 0 (falso) si no lo es.
 *
 */
static int esNombre(char *cadena,int limite);

/**
 * \brief Recibe una cadena de caracteres y convierte el primero en mayúscula,
 * 		  y los restantes en minúsculas.
 * \param cadena Cadena a ser acomodada.
 * \return Retorna 0 (ÉXITO) si se acomoda la cadena, y 1 (ERROR) si no.
 */
static int acomodarNombre(char *cadena);

/**
 * \brief Obtiene una fecha desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejará el resultado de la función.
 * \param longitud Define el tamaño de cadena.
 * \return Retorna 0 (ÉXITO) si se obtiene un nombre y -1 (ERROR) si no.
 */
static int getFecha(char *pResultado, int longitud);

/**
 * \brief Verifica si la cadena ingresada concuerda con el formato "fecha".
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tamaño de cadena.
 * \return Retorna 1 (verdadero) si la cadena es una fecha y 0 (falso) si no lo es.
 */
static int esFecha(char *cadena, int limite);

int utn_getNumero(int *resultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(resultado != NULL &&
	   mensaje != NULL &&
	   mensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&bufferInt) == 0 &&
			   bufferInt >= minimo &&
			   bufferInt <= maximo)
			{
				*resultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getNumeroFlotante(float *resultado,char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int retorno;

	if(resultado != NULL &&
	   mensaje != NULL &&
	   mensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0 &&
			   bufferFloat >= minimo &&
			   bufferFloat <= maximo)
			{
				*resultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getCaracter(char *pResultado,char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos)
{
	char bufferChar;
	int retorno = -1;

	if(pResultado != NULL &&
	   mensaje != NULL &&
	   mensajeError != NULL &&
	   minimo > 0 &&
	   maximo > 0 &&
	   reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getCaracter(&bufferChar) == 0 &&
			  (bufferChar == minimo ||
			   bufferChar == maximo))
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getNombre(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos)
{
	char bufferString[256];
	int retorno = -1;

	do
	{
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos --;
		}
	}while(reintentos >= 0);

	return retorno;
}

int utn_getFecha(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos)
{
	char bufferString[256];
	int retorno = -1;

	do
	{
		printf("%s",mensaje);
		if(getFecha(bufferString,sizeof(bufferString)) == 0)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos --;
		}
	}while(reintentos >= 0);

	return retorno;
}

static int getString(char *cadena,int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL &&
		   bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
		{
			bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}

static int getInt(int *pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
	   getString(bufferString,sizeof(bufferString)) == 0 &&
	   esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno = 0;
	}

	return retorno;
}

static int esNumerica(char *cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i = 0;i < limite && cadena[i] != '\0';i ++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] < '0' || cadena[i] > '9')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

static int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[128];

	if(pResultado != NULL &&
	   getString(buffer,sizeof(buffer)) == 0 &&
	   esFloat(buffer,sizeof(buffer)))
	{
		*pResultado = atof(buffer);
		retorno = 0;
	}

	return retorno;
}

static int esFloat(char *cadena, int limite)
{
	int retorno = 1;
	int i = 0;
	int contadorPunto = 0;

	if(cadena[0] == '-' || cadena[0] == '+')
	{
		i = 1;
	}

	for(; cadena[i] != '\0' ; i ++)
	{
		if((cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '.')
		{
			retorno = 0;
			break;
		}
		else
		{
			if(cadena[i] == '.')
			{
				contadorPunto ++;
				if(contadorPunto > 1)
				{
					retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

static int getCaracter(char *pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
	   getString(bufferString,sizeof(bufferString)) == 0 &&
	   esCaracter(bufferString,sizeof(bufferString)))
	{
		*pResultado = bufferString[0];
		retorno = 0;
	}

	return retorno;
}

static int esCaracter(char *cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i = 0;i < limite && cadena[i] != '\0';i ++)
	{
		if((cadena[i] < 'a' || cadena[i] > 'z') &&
		   (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

static int getNombre(char *pResultado, int longitud)
{
	int retorno = -1;
	char buffer[256];

	if(pResultado != NULL &&
	   getString(buffer,sizeof(buffer)) == 0 &&
	   esNombre(buffer,sizeof(buffer)) &&
	   acomodarNombre(buffer) == 0 &&
	   strnlen(buffer,sizeof(buffer)) < longitud)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}

	return retorno;
}

static int esNombre(char *cadena,int limite)
{
	int retorno = 1;
	int i ;

	for (i = 0; i <= limite && cadena[i] != '\0'; i ++)
	{
		if((cadena[i] < 'a' || cadena[i] > 'z') &&
		   (cadena[i] < 'A' || cadena[i] > 'Z') &&
		   (cadena[0] == ' ' ||cadena[i] != ' '))
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

static int acomodarNombre(char *cadena)
{
	int retorno = -1;

	while(*cadena != '\0')
	{
		while(!isalpha(*cadena) && (*cadena != '\0'))
		{
			cadena ++;
		}

		if(isalpha(*cadena) && *cadena >= 'A')
		{
			*cadena = toupper(*cadena);
			cadena ++;
		}
		while(isalpha(*cadena))
		{
			*cadena = tolower(*cadena);
			cadena ++;
		}

		retorno = 0;
	}

	return retorno;
}

static int getFecha(char *pResultado, int longitud)
{
	int retorno = -1;
	char buffer[256];

	if(pResultado != NULL &&
	   getString(buffer,sizeof(buffer)) == 0 &&
	   esFecha(buffer,sizeof(buffer)) &&
	   strnlen(buffer,sizeof(buffer)) < longitud)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}

	return retorno;
}

static int esFecha(char *cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i = 0; cadena[i] != '\0' ; i ++)
	{
		if((cadena[0] < '0' || cadena[0] > '3') &&
		   (cadena[1] < '0' || cadena[1] > '9') &&
		   (cadena[2] != '/') &&
		   (cadena[3] < '0' || cadena[3] > '1') &&
		   (cadena[4] < '0' || cadena[4] > '2') &&
		   (cadena[5] != '/') && (cadena[6] != '2') &&
		   (cadena[7] < '0' || cadena[7] > '9') &&
		   (cadena[8] < '0' || cadena[8] > '9') &&
		   (cadena[9] < '0' || cadena[9] > '9'))
		{
			retorno = 0;
			break;
		}

		return retorno;
	}

	return retorno;
}
