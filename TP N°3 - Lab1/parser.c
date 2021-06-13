#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char buffer[4][128];
	Employee *auxEmpleado = NULL;
	int registros = 0;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0), *(buffer + 1),*(buffer + 2), *(buffer + 3));
	while (!feof(pFile))
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0),*(buffer + 1), *(buffer + 2), *(buffer + 3));
		registros++;
		auxEmpleado = employee_newParametros(*(buffer + 0), *(buffer + 1),*(buffer + 2), *(buffer + 3));
		ll_add(pArrayListEmployee,auxEmpleado);
	}

	return registros;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int registros = 0;
	Employee auxEmp;
	while(!feof(pFile))
	{
		if(fread(&auxEmp,sizeof(Employee),1,pFile) == 1)
		{
			Employee *temp = employee_new();
			employee_setId(temp,auxEmp.id);
			employee_setNombre(temp,auxEmp.nombre);
			employee_setHorasTrabajadas(temp,auxEmp.horasTrabajadas);
			employee_setSueldo(temp,auxEmp.sueldo);
			ll_add(pArrayListEmployee,(Employee*)temp);
		}
		registros++;
	}

	return registros;
}
