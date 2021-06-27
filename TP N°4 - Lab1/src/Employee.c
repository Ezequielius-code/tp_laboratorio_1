#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
	Employee* empleado;
	empleado = (Employee*)malloc(sizeof(Employee));

	return empleado;
}

void employee_delete(Employee* this)
{
	free(this);
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* empleado;
	empleado = (Employee*)malloc(sizeof(Employee));
	if(empleado != NULL)
	{
		employee_setId(empleado,atoi(idStr));
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
		employee_setSueldo(empleado,atoi(sueldoStr));
	}

	return empleado;
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this -> id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this -> nombre,nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		this -> horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{

	int retorno = -1;

	if(this != NULL)
	{
		this -> sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this -> id;
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(nombre,this -> nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL)
	{
		*horasTrabajadas = this -> horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if(this != NULL)
	{
		*sueldo = this -> sueldo;
		retorno = 0;
	}

	return retorno;
}

int aumentarSueldos(void *empleado)
{
	int retorno = -1;
	int auxSueldo;

	if(empleado != NULL)
	{
		 auxSueldo = (*(Employee*)(empleado)).sueldo;

		 if(auxSueldo > 20000)
		 {
			 auxSueldo = auxSueldo+(auxSueldo*10/100);

			 (*(Employee*)(empleado)).sueldo = auxSueldo;
		 }

		 retorno = 0;
	}

	return retorno;
}
