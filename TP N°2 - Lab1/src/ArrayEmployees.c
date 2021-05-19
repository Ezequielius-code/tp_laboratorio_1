#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#define VACIO 0
#define OCUPADO 1

int initEmployees(Employee* list,int len)
{
	int retorno;

	retorno = 0;

	if(len > 0)
	{
		for(int i = 0; i < len; i ++)
		{
			list[i].isEmpty=0;
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

int addEmployee(Employee* list,int len,int id,char name[],char lastName[],float salary,int sector)
{
	int place =	searchSlot(list, len);

	if(place >= 0)
	{
		list[place].id=id;
		strcpy(list[place].name,name);
		strcpy(list[place].lastName,lastName);
		list[place].salary = salary;
		list[place].sector = sector;
		list[place].isEmpty = OCUPADO;
	}

	return 0;
}

int searchSlot(Employee* list, int len)
{
	int i;
	int reply;

	reply = 0;

	if(len>0)
	{
		for (i = 0; i < len; i ++)
		{
			if(list[i].isEmpty == VACIO)
			{
				reply = i;
				break;
			}
			else
			{
				reply=-1;
			}
		}
	}

	return reply;
}

int searchId(Employee* list,int len)
{
	int i;
	int reply = -1;

	for (i = 0; i < len; i ++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			if(list[i].id > reply)
			{
				reply = list[i].id;
			}
		}
	}

	return reply;
}

int arrayEmpty(Employee* list,int len)
{
	int i;
	int reply=0;

	for (i = 0; i < len; i ++)
	{
		if(list[i].isEmpty == 1)
		{
			reply ++;
		}
	}

	return reply;
}


int getEmployee(Employee* list,int len,int* lastID)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int reply;
	int id;

	reply = 0;

	if(searchSlot(list, len) <= -1)
	{
		printf("No hay espacio para el ingreso de nuevos empleados.\n");
		reply = -1;
	}
	else
	{
		id = *lastID+1;
		utn_GetName(name,"Ingrese nombre del empleado: ",51);
		formatName(name,51);
		utn_GetName(lastName,"Ingrese apellido del empleado: ",51);
		formatName(lastName,51);
		salary = utn_getNumeroFlotante("Ingrese sueldo en pesos del empleado: ","ERROR. Valor no existente.",1,999999);
		sector = utn_getNumero("Ingrese sector del empleado: ","ERROR. Sector no existente.",1,10);
		addEmployee(list,len,id,name,lastName,salary,sector);
		*lastID = id;
		reply = 0;
	}
	if(reply == 0)
	{
		printf("El empleado ha sido registrado correctamente. \n");
	}

	return reply;
}

void formatName(char name[],int tam)
{
	int i;
	char auxName[51];

	strcpy(auxName,name);

	for (i = 0; i < 51; i ++)
	{
		auxName[i] = tolower(auxName[i]);
	}
	auxName[0] = toupper(auxName[0]);

	strcpy(name,auxName);
}

int printEmployees(Employee* list, int length)
{
	int i;

	printf("+-----------------------------------------------------------------------------+\n");
	printf("|%10s  %20s  %20s  %10s %10s| \n","ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
	printf("+-----------------------------------------------------------------------------+\n");
	if(length > 0)
	{
		for (i = 0; i < length; i ++)
		{
			if(list[i].isEmpty==1)
			{
				printf("|%10d|  %20s|  %20s|  %10.2f| %6d| \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
	printf("+-----------------------------------------------------------------------------+\n");

	return 0;
}

int ModifyEmployee(Employee* list,int len)
{
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int i;
	int reply;
	int id = utn_getNumero("Ingrese Id a modificar: ","ERROR. Id no existente ",1,len+1);
	int aux = findEmployeeById(list,len,id);

	reply = 0;

	if(aux >= 0)
	{
		printf("Se modificara el empleado: \n");
		printf("+------------------------------------------------------------------------------+\n");
		printf("|%10s  %20s  %20s  %10s %10s| \n","ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
		printf("+------------------------------------------------------------------------------+\n");
		printf("|%10d|  %20s|  %20s|  %10.2f| %6d| \n",list[aux].id,list[aux].name,list[aux].lastName,list[aux].salary,list[aux].sector);
		printf("+------------------------------------------------------------------------------+\n");
		for (i = 0; i < len; i ++)
		{
			if(list[i].id == id)
			{
				switch (utn_getNumero("Dato a modificar: \n"
									  "  1-Nombre\n"
									  "  2-Apellido\n"
									  "  3-Sueldo\n"
									  "  4-Sector\n"
									  "*Seleccione dato: ","\nERROR. La opcion no existe.",1,4))
				{
					case 1:
						utn_GetName(name, "Ingrese nuevo nombre: ",51);
						formatName(name,51);
						strcpy(list[i].name,name);
					break;
					case 2:
						utn_GetName(lastName, "Ingrese nuevo apellido: ",51);
						formatName(lastName,51);
						strcpy(list[i].lastName,lastName);
					break;
					case 3:
						salary = utn_getNumeroFlotante("Ingrese nuevo sueldo: ","ERROR. Valor no existente.",1,999999);
						list[i].salary=salary;
					break;
					case 4:
						sector = utn_getNumero("Ingrese nuevo sector: ","Sector no existente.",1,10);
						list[i].sector = sector;
					break;
				}

				reply=1;
				break;
			}
		}
	}

	return reply;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	int reply;

	reply = -1;

	if(len > 0)
	{
		for (i = 0; i < len; i ++)
		{
			if(list[i].id==id && list[i].isEmpty == 1)
			{
				reply = i;
			}
		}
	}

	return reply;
}

int removeEmployee(Employee* list,int len,int id)
{
	int reply;
	int position = findEmployeeById(list, len, id);
	reply = -1;

	if(position != -1)
	{
		if(list[position].isEmpty == OCUPADO)
		{
			list[position].isEmpty = VACIO;
			reply=0;
		}
	}

	return reply;
}

int sortEmployees(Employee* list,int len,int order)
{
	int i;
	int flagSwap;
	int counter;
	int reply;
	Employee aux;

	counter = 0;
	reply = -1;

	if(list != NULL && len >= 0)
	{
		do
		{
			flagSwap = 0;
			for (i = 0; i < len-1; i ++)
			{
				if(order == 0)
				{
					if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
					{
						flagSwap = 1;
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName) == 0 && list[i].sector > list[i+1].sector)
						{
							flagSwap = 1;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
						}
					}
				}
				else if(order == 1)
				{
					if(strcmp(list[i+1].lastName,list[i].lastName) > 0)
					{
						flagSwap = 1;
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
					}
					else
					{
						if(strcmp(list[i].lastName,list[i+1].lastName) == 0 && list[i+1].sector > list[i].sector)
						{
							flagSwap = 1;
							aux = list[i];
							list[i] = list[i+1];
							list[i+1] = aux;
						}
					}
				}

				counter++;
			}
		} while(flagSwap);

		reply = counter;
	}

	return reply;
}

float averageSalary(Employee* list,int len,float* total,int* cantEmp)
{
	int i;
	float reply;
	float accum;
	int counter;
	int cantidadEmpleados;

	reply = -1;
	accum = 0;
	counter = 0;
	cantidadEmpleados = 0;

	if(list != NULL && len >= 0)
	{
		for (i = 0; i < len; i ++)
		{
			if(list[i].isEmpty == 1)
			{
				accum += list[i].salary;
				counter ++;
			}
		}
		*total = accum;
		reply = ((float)accum/(float)counter);
		for (i = 0; i < len; i ++)
		{
			if(list[i].salary > reply && list[i].isEmpty == 1)
			{
				cantidadEmpleados ++;
			}
		}
		*cantEmp = cantidadEmpleados;
	}

	return reply;
}

void printAverageInfo(float* promedio,float* total,int* cantEncimaDelPromedio)
{
	printf("DATOS DE SUELDOS TOTAL Y PROMEDIO DE LA NOMINA DE EMPLEADOS: \n");
	printf("+------------------------------------------------------------------------------------+\n");
	printf("|%1s      | %-25s  | %20s | \n"," PROMEDIO "," TOTAL "," EMPLEADOS POR ARRIBA DEL PROMEDIO  ");
	printf("+------------------------------------------------------------------------------------+\n");
	printf("| %-15.2f|  %-26.2f|  %21d               |\n",*promedio,*total,*cantEncimaDelPromedio);
	printf("+------------------------------------------------------------------------------------+\n");
	system("pause");
}
