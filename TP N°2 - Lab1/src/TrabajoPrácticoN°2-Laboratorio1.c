/*
 ============================================================================
 Name        : TrabajoPrácticoN°2-Laboratorio1.c
 Author      : Brutto, Ezequiel Andrés
 Version     : 1.0.0
 Description : Una empresa requiere un sistema para administrar su nómina de empleados.
 Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define LEN 1000

int main(void)
{
	setbuf(stdout,NULL);

	int validarMenu = 1;
	int ultimoId = 0;
	float totalSueldos;
	float promedioSueldos;
	int sueldosArribaPromedio;
	char encabezado[187];
	char opciones[153];
	char menu[187];
	char opcNoVal[41];
	char sinDatos[48];
	char subMenu[174];
	Employee Empleados[LEN];

	snprintf(encabezado,sizeof(encabezado),"\nSoftWork%c - Gesti%cn de empleados.",174,243);
	snprintf(opciones,sizeof(opciones),"\n   1-Ingresar empleado.\n   2-Modificar datos empleado.\n   3-Dar de baja empleado.\n   4-Listar empleados.\n   5-Finalizar programa.\n\n*Seleccione opci%cn: ",243);
	strncat(encabezado,opciones,sizeof(encabezado));
	strncpy(menu,encabezado,sizeof(menu));
	snprintf(opcNoVal,sizeof(opcNoVal),"\nERROR. La opci%cn ingresada no es v%clida.",243,225);
	snprintf(sinDatos,sizeof(sinDatos),"\nOpci%cn no disponible. No hay datos ingresados.",243);
	snprintf(subMenu,sizeof(subMenu),"\n  1-Mostrar lista de empleados.\n  2-*Gasto total en sueldos,\n    *Sueldo promedio, y\n    *Personal con sueldos \n    encima del promedio.\n  3-Volver. \n\n*Seleccione opci%cn: ",243);

	initEmployees(Empleados,LEN);

	do
	{
		switch (utn_getNumero(menu,opcNoVal,1,5))
		{
			case 1:
				getEmployee(Empleados,LEN,&ultimoId);
				system("pause");
			break;
			case 2:
				if(arrayEmpty(Empleados,LEN) != 0)
				{
					printEmployees(Empleados,LEN);
					if(ModifyEmployee(Empleados,LEN))
					{
						printf("Los datos se han modificado correctamente.\n");
					}
					else
					{
						printf("Se produjo un error. Por favor, intente nuevamente.\n");
					}
					system("pause");
				}
				else
				{
					printf(sinDatos);
					printf("\n");
					system("pause");
				}
			break;
			case 3:
				if(arrayEmpty(Empleados,LEN) != 0)
				{
					printEmployees(Empleados,LEN);
					if(removeEmployee(Empleados,LEN,utn_getNumero("Para dar de baja, ingrese Id del empleado: ","El Id ingresado no se encuentra registrado.",1,searchId(Empleados,LEN))))
					{
						printf("\nSe produjo un error. Por favor, intente nuevamente.\n");
					}
					else
					{
						printf("\nEl empleado ha sido dado de baja\n");
						system("pause");
					}
				}
				else
				{
					printf(sinDatos);
					printf("\n");
					system("pause");
				}
			break;
			case 4:
				if(arrayEmpty(Empleados,LEN) != 0)
				{
					switch (utn_getNumero(subMenu,opcNoVal,1,3))
					{
						case 1:
							sortEmployees(Empleados,LEN,0);
							printEmployees(Empleados,LEN);
							system("pause");
						break;
						case 2:
							promedioSueldos = averageSalary(Empleados,LEN,&totalSueldos,&sueldosArribaPromedio);
							printAverageInfo(&promedioSueldos,&totalSueldos,&sueldosArribaPromedio);
						break;
						case 3:
						break;
					}
				}
				else
				{
					printf(sinDatos);
					printf("\n");
					system("pause");
				}
			break;
			case 5:
				validarMenu = 0;
			break;
		}
	}while(validarMenu);

	return 0;
}
