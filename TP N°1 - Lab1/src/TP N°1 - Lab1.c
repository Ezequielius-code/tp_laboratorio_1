/*
 ============================================================================
 Name        : TrabajoPrácticoN°1-Laboratorio1.c
 Author      : Brutto, Ezequiel Andrés
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Hacer una calculadora.
 Para ello, el programa iniciará y contará con un menú de opciones:
    1. Ingresar 1er operando (A=x)
    2. Ingresar 2do operando (B=y)
    3. Calcular todas las operaciones
		a) Calcular la suma (A+B)
		b) Calcular la resta (A-B)
		c) Calcular la división (A/B)
		d) Calcular la multiplicación (A*B)
		e) Calcular el factorial (A!)
	4. Informar resultados
		a) “El resultado de A+B es: r”
		b) “El resultado de A-B es: r”
		c) “El resultado de A/B es: r” o “No es posible dividir por cero”
		d) “El resultado de A*B es: r”
		e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una
biblioteca aparte, que contenga las funciones para realizar las cinco
operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos
A y B (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc).
• Documentar todas las funciones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	//Opciones del menú.
	int menuOptions = 0;
	//Ingreso de operandos.
	float operand1 = 0;
	float operand2 = 0;
	//Validación de operandos.
	int flagOperand1 = 0;
	int flagOperand2 = 0;
	//Validación del menú.
	int menuValidation = 0;
	int flagOperations = 0;
	//Resultado de básicas.
	float additionResult = 0;
	float subtractionResult = 0;
	float multiplicationResult = 0;
	float divisionResult = 0;
	//Resultado de factoriales.
	int factorialA = 0;
	int factorialB = 0;

	while (menuValidation == 0)
	{
		printf ("\t Calculadora TP N°1 UTN-FRA \n");
		if(flagOperand1 == 0)
		{
			printf("\t 1_ Ingresar el primer operando, A = \n");
		}
		else
		{
			printf("\t 1_ Ingresar el primer operando, A = %9.2f \n",operand1);
		}
		if(flagOperand2 == 0)
		{
			printf("\t 2_ Ingresar el segundo operando, B = \n");
		}
		else
		{
			printf("\t 2_ Ingresar el segundo operando, B = %8.2f \n",operand2);
		}
		printf("\t 3_ Realizar el cálculo de las operaciones. \n");
		printf("\t 4_ Visualizar los resultados de las operaciones. \n");
		printf("\t 5_ Salir de la calculadora. \n");

		switch (menuOptions = getInt("\n _Ingrese la opción deseada: "))
		{
			case 1:
				flagOperand1 = getFloat(&operand1,"\n\t _Ingrese operando A: ");
			break;
			case 2:
				flagOperand2 = getFloat(&operand2,"\n\t _Ingrese operando B: ");
			break;
			case 3:
				if(flagOperand1 == 1 && flagOperand2 == 1)
				{
					additionResult = addition(operand1,operand2);
					subtractionResult = subtraction(operand1,operand2);
					multiplicationResult = multiplication(operand1,operand2);
					divisionResult = division(operand1,operand2);
					factorialA = factorial(operand1);
					factorialB = factorial(operand2);
					flagOperations = 1;
					printf("\n\t Las operaciones se han realizado con éxito.\n");
				}
				else
				{
					printf("\n ERROR. No es posible calcular sin ingresar ambos operandos. \n");
				}
				system("pause");
				break;
			case 4:
				if(flagOperations == 0 || flagOperand1 == 0 || flagOperand2 == 0)
				{
					printf("\n ERROR. No se muestran resultados sin realizar el cálculo (opción 3).\n");
				}
				else
				{
					printf("\n La suma de los dos operandos es: %.2f \n",additionResult);
					printf("\n La resta de B a A es: %.2f \n",subtractionResult);
					printf("\n La multiplicación entre ambos operandos es: %.2f \n",multiplicationResult);
					if(operand2 == 0)
					{
						printf("\n Operando B = 0. No es posible realizar la división. \n");
					}
					else
					{
						printf("\n La división de A por B es: %.2f \n",divisionResult);
					}
					if(factorialA == 0)
					{
						printf("\n ERROR. No es posible realizar el factorial de A: %.2f\n",operand1);
					}
					else
					{
						printf("\n El resultado de A! es : %d \n",factorialA);
					}
					if(factorialB == 0)
					{
						printf("\n ERROR. No es posible realizar el factorial de B: %.2f\n",operand2);
					}
					else
					{
						printf("\n El resultado de B! es : %d \n",factorialB);
					}
				}
				system("\npause");
				break;
			case 5:
				menuValidation =1;
				break;
			default:
				printf("\t\n ERROR. Ha ingresado una opción no válida. \n");
				system("pause");
				menuValidation = 0;
				break;
			}
	}
	return EXIT_SUCCESS;
}
