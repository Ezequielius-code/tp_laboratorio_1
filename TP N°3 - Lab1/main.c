/*
 ============================================================================
 Name        : TrabajoPrácticoN°3-Laboratorio1.c
 Author      : Brutto Ezequiel Andrés
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define CSV_PATH "./data.csv"
#define BIN_PATH "./data.bin"

int main()
{
	setbuf(stdout, NULL);

    char menu[1000];
    int opcion;

    snprintf(menu,sizeof(menu),"\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c MENU %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
    		                   "\n   1. Cargar los datos de los empleados \n     desde el archivo data.csv (modo texto)."
    		                   "\n   2. Cargar los datos de los empleados \n     desde el archivo data.csv (modo binario)."
    		                   "\n   3. Alta de empleado"
    		                   "\n   4. Modificar datos de empleado"
    		                   "\n   5. Baja de empleado"
    		                   "\n   6. Listar empleados"
    		                   "\n   7. Ordenar empleados"
    		                   "\n   8. Guardar los datos de los empleados \n     en el archivo data.csv (modo texto)."
    		                   "\n   9. Guardar los datos de los empleados \n     en el archivo data.csv (modo binario)."
    		                   "\n   10. Salir"
    		                   "\n\n *Seleccione opci%cn: ",171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,
							   171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,
							   187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,243);

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
    	opcion = utn_getNumero(menu,"\nERROR. Se ingreso una opcion no valida.\n",1,10);
    	switch(opcion)
        {
            case 1:
                if(controller_loadFromText(CSV_PATH,listaEmpleados))
                {
                	printf("\nSe produjo un error al leer el archivo.");
                }
                else
                {
                	printf("\nEl archivo ha sido cargado exitosamente.");
                }
            break;
            case 2:
            	if(controller_loadFromBinary(BIN_PATH,listaEmpleados))
            	{
            		printf("\nSe produjo un error al leer el archivo.");
            	}
            	else
				{
					printf("\nEl archivo ha sido cargado exitosamente.");
				}
            break;
            case 3:
            	if(controller_addEmployee(listaEmpleados))
            	{
            		printf("\nSe ha producido un error.");
            	}
            	else
				{
					printf("\nEmpleado añadido exitosamente.");
				}
            break;
            case 4:
            	if(controller_editEmployee(listaEmpleados))
            	{
            		printf("\nSe ha producido un error.");
            	}
            	else
				{
					printf("\nEmpleado modificado exitosamente.");
				}
            break;
            case 5:
            	if(controller_removeEmployee(listaEmpleados))
            	{
            		printf("\nSe ha producido un error.");
            	}
            	else
				{
					printf("\nEmpleado dado de baja exitosamente.");
				}
            break;
            case 6:
            	if(controller_ListEmployee(listaEmpleados))
            	{
            		printf("\nSe ha producido un error.");
            	}
            break;
            case 7:
            	if(controller_sortEmployee(listaEmpleados))
            	{
            		printf("\nSe ha producido un error.");
            	}
            	else
				{
					printf("\nEmpleados ordenados exitosamente.");
				}
            break;
            case 8:
            	if(ll_isEmpty(listaEmpleados))
            	{
            		printf("\nNo hay datos para guardar.");
            	}
            	else
            	{
            		if(controller_saveAsText(CSV_PATH,listaEmpleados))
            		{
            			printf("\nSe ha producido un error.");
            		}
            		else
            		{
            			printf("\nLa lista se ha guardado exitosamente.");
            		}
            	}
            	break;
            case 9:
            	if(ll_isEmpty(listaEmpleados))
				{
					printf("\nNo hay datos para guardar.");
				}
            	else
            	{
            		if(controller_saveAsBinary(BIN_PATH,listaEmpleados))
            		{
            			printf("\nSe ha producido un error.");
            		}
            		else
            		{
            			printf("\nLa lista se ha guardado exitosamente.");
            		}
            	}
            break;
        }
    }while(opcion != 10);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

