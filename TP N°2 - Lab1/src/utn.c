#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

int utn_getNumero (char *texto,char *textoError,int min,int max)
{
	int datoIngresado;
	int validacion;

	validacion = -1;

	do
	{
		printf("\n%s", texto);
		fflush(stdin);
		if(scanf("%d",&datoIngresado))
		{
			if(ValidarMinMax(datoIngresado, min,max))
			{
				validacion = 0;
			}
			else
			{
				printf("%s",textoError);
			}
		}
		else
		{
			printf("%s",textoError);
		}
	}while(validacion);

	return datoIngresado;
}

int ValidarMinMax(int dato,int min,int max)
{
    int valido;

    valido = -1;

    if(dato < min || dato > max)
    {
        valido = 0;
    }

    return valido;
}

float utn_getNumeroFlotante(char *texto,char *textoError,float min,float max)
{
	float datoIngresado;
	int validacion;

	validacion = -1;

	do
	{
		printf("\n%s",texto);
		fflush(stdin);
		if(scanf("%f",&datoIngresado))
		{
			if(ValidarMinMax(datoIngresado,min,max))
			{
				validacion = 0;
			}
			else
			{
				printf("%s",textoError);
			}
		}
		else
		{
			printf("%s",textoError);
		}
	}while(validacion);

	return datoIngresado;
}

int ValidarMinMaxFloat(float dato,float min,float max)
{
    int valido;

    valido = -1;

    if(dato < min || dato > max)
    {
        valido = 0;
    }

    return valido;
}

void utn_GetName(char name[],char text[],int tam)
{
	int validacion;

	do
	{
		printf("%s",text);
		fflush(stdin);
		scanf("%[^\n]",name);
		if(isName(name,tam) != 1)
		{
			validacion = 0;
		}
		else
		{
			validacion = 1;
		}

	} while (validacion);
}

int isName (char *cadena,int limite)
{
	int retorno;
	int i ;

	retorno = 0;

	for (i = 0; i <= limite && cadena[i] != '\0'; i ++)
	{
		if((cadena[i] < 'a' || cadena[i] > 'z')
		&& (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i]=='\0'))
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

void utn_InitArrayInt(int array[],int tam){

	for (int i = 0;  i < tam ;++i)
	{
		array[i]=0;
	}
}

int CargaSecuencialArrayInt(int array[],int tam,int dato)
{
	int respuesta;

	respuesta = 0;

	for (int i = 0;i < tam; ++i)
	{
		if(array[i] == 0)
		{
			array[i] = dato;
			respuesta = 1;
			break;
		}
	}

	return respuesta;
}

int CargaAleatoriaArrayInt(int array[],int tam,int dato,int posicion)
{
	int respuesta;
	int i;

	respuesta = 0;

	for (i = 0; i < tam; i ++)
	{
		if( posicion == i && array[i] == 0 )
		{
			array[i] = dato;
			respuesta = 1;
			break;
		}
	}

	return respuesta;
}

int MostrarArrayInt(int array[],char text[],int tam)
{
	int respuesta;
	int i;

	respuesta = 0;

	if(array != NULL && tam >= 0)
	{

		for (i = 0; i < tam; i ++)
		{
			printf("\nId: %d - %s: %d",i,text,array[i]);
		}
		respuesta = 1;
	}

	return respuesta;
}

int ordenarArrayInt(int *array,int tam)
{
	int i;
	int flagSwap;
	int contador;
	int resultado;
	int buffer;

	contador = 0;
	resultado = -1;

	if(array != NULL && tam >= 0)
	{
		do{
			flagSwap = 0;
			for (i = 0; i < tam -1; i ++)
			{
				if(array[i] < array[i+1])
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
				}
				contador++;
			}
		}while(flagSwap);

		resultado = contador;
	}
	return resultado;
}
