#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char respuesta;
	FILE *file;
	int i;
	Employee *auxEmpleado;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSalario;

	printf("\n¿Desea guardar los cambios realizados? (s)i - (n)o: ");
	fflush(stdin);
	scanf("%c",&respuesta);

	if (respuesta == 's')
	{
		file = fopen(path,"w");
		if (file != NULL)
		{
			fprintf(file,"id,nombre,horasTrabajdas,sueldo\n");

			for(i = 0;i < ll_len(pArrayListEmployee);i ++)
			{
				auxEmpleado = ll_get(pArrayListEmployee,i);
				employee_getId(auxEmpleado,&auxId);
				employee_getNombre(auxEmpleado,auxNombre);
				employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
				employee_getSueldo(auxEmpleado,&auxSalario);
				fprintf(file,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSalario);
			}

			retorno = 0;
		}

		fclose(file);
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}

int controller_loadFromText(char* path ,LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int registros;
	char respuesta;
	FILE *file;

	if(!ll_isEmpty(pArrayListEmployee))
	{
		printf("\nATENCIÓN!!! Si prosigue con la apertura de un archivo,"
				"\nperderá los datos ingresados. ¿Qué acción desea realizar?"
				"\n  _(g)uardar los datos (.csv) y cargar el archivo."
				"\n   _(b)orrar los datos y cargar el archivo.");

		utn_getCaracter(&respuesta,"\n\n*Seleccione respuesta: ","\nERROR. Ha ingresado un caracter no válido.",'b','g',100);

		switch(respuesta)
		{
			case 'b':
				ll_clear(pArrayListEmployee);

				file = fopen(path,"r");

				if (file != NULL)
				{
					registros = parser_EmployeeFromText(file,pArrayListEmployee);
					if(registros)
					{
						retorno = 0;
						fclose(file);
					}
				}
			break;
			case 'g':
				if(!controller_saveAsText("./ingresados.csv",pArrayListEmployee))
				{
					ll_clear(pArrayListEmployee);

					file = fopen(path,"r");

					if (file != NULL)
					{
						registros = parser_EmployeeFromText(file,pArrayListEmployee);
						if(registros)
						{
							retorno = 0;
							fclose(file);
						}
					}
				}
				else
				{
					retorno = 0;
				}
			break;
		}
	}
	else
	{
		ll_clear(pArrayListEmployee);

		file = fopen(path,"r");

		if (file != NULL)
		{
			registros = parser_EmployeeFromText(file,pArrayListEmployee);
			if(registros)
			{
				retorno = 0;
				fclose(file);
			}
		}
	}

	return retorno;
}

int controller_saveAsBinary(char* path,LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char respuesta;
	FILE *file;
	int i;
	Employee *auxEmpleado;
	Employee aux;

	printf("\n¿Desea guardar los cambios realizados? (s)i - (n)o: ");
	fflush(stdin);
	scanf("%c",&respuesta);

	if(respuesta == 's')
	{
		file = fopen(path,"wb");
		if(file != NULL)
		{
			for(i = 0;i < ll_len(pArrayListEmployee);i ++)
			{
				auxEmpleado = ll_get(pArrayListEmployee,i);
				if(auxEmpleado != NULL)
				{
					aux = *(auxEmpleado);
					fwrite(&aux,sizeof(Employee),1,file);
				}

			}

			retorno = 0;
		}

		fclose(file);
	}
	else
	{
		retorno = 1;
	}

	return retorno;
}

int controller_loadFromBinary(char* path,LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int registros;
	char respuesta;
	FILE *file;

	if(!ll_isEmpty(pArrayListEmployee))
	{
		printf("\nATENCIÓN!!! Si prosigue con la apertura de un archivo,"
				"\nperderá los datos ingresados. ¿Qué acción desea realizar?"
				"\n  _(g)uardar los datos (.bin) y cargar el archivo."
				"\n   _(b)orrar los datos y cargar el archivo.");

		utn_getCaracter(&respuesta,"\n\n*Seleccione respuesta: ","\nERROR. Ha ingresado un caracter no válido.",'b','g',100);

		switch(respuesta)
		{
			case 'b':
				ll_clear(pArrayListEmployee);

				file = fopen(path,"rb");

				if(file != NULL)
				{
					registros = parser_EmployeeFromBinary(file,pArrayListEmployee);
					if (registros)
					{
						retorno = 0;
						fclose(file);
					}
				}
			break;
			case 'g':
				if(!controller_saveAsBinary("./ingresados.bin",pArrayListEmployee))
				{
					ll_clear(pArrayListEmployee);

					file = fopen(path,"rb");

					if(file != NULL)
					{
						registros = parser_EmployeeFromBinary(file,pArrayListEmployee);
						if (registros)
						{
							retorno = 0;
							fclose(file);
						}
					}
				}
				else
				{
					retorno = 0;
				}
			break;
		}
	}
	else
	{
		ll_clear(pArrayListEmployee);

		file = fopen(path,"rb");

		if(file != NULL)
		{
			registros = parser_EmployeeFromBinary(file,pArrayListEmployee);
			if (registros)
			{
				retorno = 0;
				fclose(file);
			}
		}
	}

	return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	int lastId = 1;

	if (!ll_isEmpty(pArrayListEmployee))
	{
		for (i = 0; i < ll_len(pArrayListEmployee); i ++)
		{
			Employee *aux = ll_get(pArrayListEmployee,i);
			employee_getId(aux,&auxId);
			if (auxId > lastId)
			{
				employee_getId(aux,&lastId);
			}
		}

		lastId ++;
	}

	Employee *nuevoEmp = employee_new();
	if (nuevoEmp != NULL)
	{
		utn_getNombre(auxNombre,128,"\nIngrese nombre del empleado: ","ERROR. Nombre no válido",100);
		utn_getNumero(&auxHorasTrabajadas,"\nIngrese cantidad de horas trabajadas (MAX 325): ","\nERROR. Cantidad de horas no validas.",60,325,100);
		utn_getNumero(&auxSueldo,"\nIngrese sueldo del empleado: ","\nERROR. Sueldo no valido.",10000,50000,100);

		if(auxNombre != NULL && auxHorasTrabajadas != 0 && auxSueldo != 0)
		{
			employee_setId(nuevoEmp,lastId);
			employee_setNombre(nuevoEmp,auxNombre);
			employee_setHorasTrabajadas(nuevoEmp,auxHorasTrabajadas);
			employee_setSueldo(nuevoEmp,auxSueldo);
			ll_add(pArrayListEmployee,(Employee*)nuevoEmp);

			retorno = 0;
		}
	}

	return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee *temp;
	int auxId;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;

	if (!ll_isEmpty(pArrayListEmployee))
	{
		printf("\n%50s","Lista de empleados");
		printf("\n\n%5s %2c %10s %2c %18s %3c %14s","Id",'|',"Nombre",'|',"Horas Trabajadas",'|',"Sueldo");
		printf("\n ------------------------------------------------------------------------");

		for (i = 0;i < ll_len(pArrayListEmployee);i ++)
		{
			temp = ll_get(pArrayListEmployee,i);

			if (temp != NULL)
			{
				employee_getId(temp,&auxId);
				employee_getNombre(temp,auxNombre);
				employee_getHorasTrabajadas(temp,&auxHorasTrabajadas);
				employee_getSueldo(temp,&auxSueldo);
				printf("\n%7d %16s %14d %19d",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
			}

		}
		printf("\n\nPresione una tecla para continuar...");
		fflush(stdin);
		getchar();
		retorno = 0;
	}
	else
	{
		printf("\nNo hay empleados cargados.");
		retorno = 0;
	}


	return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int i;
	int opcion;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	int auxId2;
	int idEncontrado = 0;
	Employee *aux;

	if(!ll_isEmpty(pArrayListEmployee))
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("\nIngrese Id del empleado a modificar: ");
		fflush(stdin);
		scanf("%d",&auxId);

		for(i = 0; i < ll_len(pArrayListEmployee);i ++)
		{
			aux = ll_get(pArrayListEmployee,i);
			employee_getId(aux,&auxId2);
			if(auxId2 == auxId)
			{
				idEncontrado = 1;
				break;
			}
		}

		if(aux != NULL && idEncontrado)
		{
			do
			{
				employee_getNombre(aux,auxNombre);
				employee_getHorasTrabajadas(aux,&auxHorasTrabajadas);
				employee_getSueldo(aux,&auxSueldo);
				printf("\n%50s","Modificar");
				printf("\n1.Nombre: %s",auxNombre);
				printf("\n2.Horas trabajadas: %d",auxHorasTrabajadas);
				printf("\n3.Sueldo: %d",auxSueldo);
				printf("\n4.Salir");
				fflush(stdin);

				utn_getNumero(&opcion,"\n\n*Seleccione opcion: ","\nERROR. Opcion no valida.",1,4,100);

				switch (opcion)
				{
					case 1:
						if(utn_getNombre(auxNombre,128,"\nIngrese nombre del empleado: ","ERROR. Nombre no válido",100) == 0)
						{
							employee_setNombre(aux,auxNombre);
							printf("\nEmpleado modificado exitosamente.");
							retorno = 0;
						}
					break;
					case 2:
						utn_getNumero(&auxHorasTrabajadas,"\nIngrese cantidad de horas trabajadas (MAX 325): ","\nERROR. Cantidad de horas no validas.",60,325,100);
						employee_setHorasTrabajadas(aux,auxHorasTrabajadas);
						printf("\nEmpleado modificado exitosamente.");
						retorno = 0;
					break;
					case 3:
						utn_getNumero(&auxSueldo,"\nIngrese sueldo del empleado: ","\nERROR. Sueldo no valido.",10000,50000,100);
						employee_setSueldo(aux,auxSueldo);
						printf("\nEmpleado modificado exitosamente.");
						retorno = 0;
					break;
				}
			} while (opcion != 4);
		}
		else
		{
			printf("\nEl id ingresado no existe.");
			retorno = 0;
		}
	}
	else
	{
		printf("\nNo hay empleados cargados.");
		retorno = 0;
	}

	return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int i;
	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	int auxId2;
	int auxIndex;
	char confirmar;
	int idEncontrado = 0;
	Employee *aux;

	if(!ll_isEmpty(pArrayListEmployee))
	{
		controller_ListEmployee(pArrayListEmployee);
		printf("\nIngrese Id del empleado a eliminar: ");
		fflush(stdin);
		scanf("%d",&auxId);

		for(i = 0;i < ll_len(pArrayListEmployee);i ++)
		{
			aux = ll_get(pArrayListEmployee,i);
			employee_getId(aux,&auxId2);
			if(auxId2 == auxId)
			{
				idEncontrado = 1;
				auxIndex = ll_indexOf(pArrayListEmployee,aux);
				break;
			}
		}

		if(aux != NULL && idEncontrado)
		{
			employee_getNombre(aux,auxNombre);
			employee_getHorasTrabajadas(aux,&auxHorasTrabajadas);
			employee_getSueldo(aux,&auxSueldo);
			printf("\n¿Desea eliminar el siguiente empleado?");
			printf("\nNombre: %s",auxNombre);
			printf("\nHoras trabajadas: %d",auxHorasTrabajadas);
			printf("\nSueldo: %d",auxSueldo);
			printf("\n\n*Respuesta (s)i - (n)o: ");
			fflush(stdin);
			scanf("%c",&confirmar);
			if(confirmar == 's')
			{
				ll_remove(pArrayListEmployee,auxIndex);
				employee_delete(aux);
				printf("\nEmpleado dado de baja exitosamente.");
				retorno = 0;
			}
			else
			{
				retorno = 0;
			}
		}
		else
		{
			printf("\nEl Id ingresado no existe.");
			retorno = 0;
		}
	}
	else
	{
		printf("\nNo hay empleados cargados.");
		retorno = 0;
	}

	return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	char nombre1[128];
	char nombre2[128];
	int i;
	int j;
	Employee *empleado1;
	Employee *empleado2;
	int id1;
	int id2;
	int horas1;
	int horas2;
	int salario1;
	int salario2;

	if(!ll_isEmpty(pArrayListEmployee))
	{
		do
		{
			printf("\n%50s","Ordenar empleados por:");
			printf("\n\n1.Nombre -> Ascendente");
			printf("\n2.Nombre -> Descendente");
			printf("\n3.Id -> Ascendente");
			printf("\n4.Id -> Descendente");
			printf("\n5.Horas -> Ascendente");
			printf("\n6.Horas -> Descendente");
			printf("\n7.Sueldo -> Ascendente");
			printf("\n8.Sueldo -> Descendente");
			printf("\n9.Salir");
			utn_getNumero(&opcion,"\n\n*Seleccione la opcion deseada: ","\nERROR. Ha ingresado una opcion no valida.",1,9,100);

			switch(opcion)
			{
				case 1:
					for (i = 0;i < ll_len(pArrayListEmployee)-1;i ++)
					{
						for (j = i+1;j < ll_len(pArrayListEmployee);j ++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getNombre(empleado1,nombre1);
							employee_getNombre(empleado2,nombre2);
							if(strcmp(nombre1,nombre2) > 0)
							{
								ll_set(pArrayListEmployee,i,empleado2);
								ll_set(pArrayListEmployee,j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 2:
					for (i = 0;i < ll_len(pArrayListEmployee)-1;i ++)
					{
						for (j = i+1;j < ll_len(pArrayListEmployee);j ++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getNombre(empleado1,nombre1);
							employee_getNombre(empleado2,nombre2);
							if(strcmp(nombre1,nombre2) < 0)
							{
								ll_set(pArrayListEmployee,i,empleado2);
								ll_set(pArrayListEmployee,j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 3:
					for(i = 0;i < ll_len(pArrayListEmployee)-1;i ++)
					{
						for (j = i+1; j < ll_len(pArrayListEmployee);j ++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getId(empleado1,&id1);
							employee_getId(empleado2,&id2);
							if (id1 > id2)
							{
								ll_set(pArrayListEmployee,i,empleado2);
								ll_set(pArrayListEmployee,j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 4:
					for(i = 0;i < ll_len(pArrayListEmployee)-1;i ++)
					{
						for (j = i+1; j < ll_len(pArrayListEmployee);j ++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getId(empleado1,&id1);
							employee_getId(empleado2,&id2);
							if (id1 < id2)
							{
								ll_set(pArrayListEmployee,i,empleado2);
								ll_set(pArrayListEmployee,j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 5:
					for(i = 0;i < ll_len(pArrayListEmployee)-1;i ++)
					{

						for (j = i+1; j < ll_len(pArrayListEmployee);j ++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getHorasTrabajadas(empleado1,&horas1);
							employee_getHorasTrabajadas(empleado2,&horas2);
							if (horas1 > horas2)
							{
								ll_set(pArrayListEmployee,i,empleado2);
								ll_set(pArrayListEmployee,j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 6:
					for(i = 0;i < ll_len(pArrayListEmployee)-1;i ++)
					{

						for (j = i+1; j < ll_len(pArrayListEmployee);j ++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getHorasTrabajadas(empleado1,&horas1);
							employee_getHorasTrabajadas(empleado2,&horas2);
							if (horas1 < horas2)
							{
								ll_set(pArrayListEmployee,i,empleado2);
								ll_set(pArrayListEmployee,j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 7:
					for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++)
					{
						for (int j = i + 1; j < ll_len(pArrayListEmployee); j++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getSueldo(empleado1,&salario1);
							employee_getSueldo(empleado2,&salario2);
							if (salario1 > salario2)
							{
								ll_set(pArrayListEmployee, i,empleado2);
								ll_set(pArrayListEmployee, j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
				case 8:
					for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++)
					{
						for (int j = i + 1; j < ll_len(pArrayListEmployee); j++)
						{
							empleado1 = ll_get(pArrayListEmployee,i);
							empleado2 = ll_get(pArrayListEmployee,j);
							employee_getSueldo(empleado1,&salario1);
							employee_getSueldo(empleado2,&salario2);
							if (salario1 > salario2)
							{
								ll_set(pArrayListEmployee, i,empleado2);
								ll_set(pArrayListEmployee, j,empleado1);
							}
						}
					}
					retorno = 0;
					printf("\nEl orden de empleados se ha realizado correctamente.");
				break;
			}
		} while (!(opcion == 9));
	}
	else
	{
		printf("\nNo hay empleados cargados.");
		retorno = 0;
	}

	return retorno;
}
