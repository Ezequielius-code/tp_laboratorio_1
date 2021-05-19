/*
 * ArrayEmployees.h
 *  Biblioteca de Funciones TP 2
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

/*
 * brief Employee structure
 */
typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/*
 * brief To indicate that all position in the array are empty,
 *       this function put the flag (isEmpty) in TRUE in all
 *       position of the array
 * param list Employee* Pointer to array of employees
 * param len int Array length
 * return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(Employee* list,int len);

/*
 * brief receive the list of employees and search for an available spot
 * param receive the list
 * param receive the size of the list
 * return In case of finding a slot, it returns the index of the list that is available,
 * 		  (0) in case of No slot found,
 *        and (-1) in case of error in any parameter
 */
int searchSlot(Employee* list,int len);

/*
 * brief add in a existing list of employees the values received as parameters
 *       in the first empty position
 * param list employee*
 * param len int
 * param id int
 * param name[] char
 * param lastName[] char
 * param salary float
 * param sector int
 * return int Return (-1) if Error [Invalid length or NULL pointer or without
 *            free space] - (0) if Ok
 */
int addEmployee(Employee* list,int len,int id,char name[],char lastName[],float salary,int sector);

/*
 * brief Request the necessary data to load an employee
 * param receive the list of employees
 * param receive the size of the list
 * return Returns (-1) in case there is no slot for a new employee,
 *        or (0) if the order can be made because there is a slot available
 */
int getEmployee(Employee* list,int len,int* lastID);

/*
 * brief print the content of employees array
 * param list Employee*
 * param length int
 * return int
 */
int printEmployees(Employee* list,int length);

/*
 * brief performs the modification of an element of the Employees array.
 * param receive the list of employees
 * param receive the size of the list
 * return returns (0) in case of not being able to print on screen,
 *        or (1) if it printed correctly
 */
int ModifyEmployee(Employee* list,int len);

/*
 * brief Remove a Employee by Id (put isEmpty Flag in 1)
 * param list Employee*
 * param len int
 * param id int
 * return int Return (-1) if Error [Invalid length or NULL pointer or if can't
 *         find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/*
 * brief Sort the elements in the array of employees, the argument order
 * indicate UP or DOWN order
 * param list Employee*
 * param len int
 * param order int [1] indicate UP - [0] indicate DOWN
 * return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortEmployees(Employee* list,int len,int order);

/*
 * brief find an Employee by Id en returns the index position in array
 * param list Employee*
 * param len int
 * param id int
 * return Return employee index position or (-1) if [Invalid length or NULL
 *        pointer received or employee not found]
 */
int findEmployeeById(Employee* list,int len,int id);

/*
 * brief Calculate the average salary of the payroll of employees,
 *       and the total of all salaries.
 * param list Employee*
 * param len int
 * param memory address where the total salaries will be stored
 * param memory address where the number of employees that exceed the average will be stored
 * return returns the average of all payroll salaries
 */
float averageSalary(Employee* list,int len,float* total,int* cantEmp);

/*
 * brief it goes through an array checking if it´s full or not
 * param list Employee*
 * param len int
 * return returns (0) in case it is complete or the amount of available slots, it means int > zero
 */
int arrayEmpty(Employee* list,int len);

/*
 * brief scroll through the Employees list looking for the biggest Id
 * param list Employee*
 * param len int
 * return returns the biggest Id occupied so far, or (-1) if there is not
 */
int searchId(Employee* list,int len);

/*
 * brief receives information of the payroll and shows it formatted on the screen
 * param receives the memory address of the average salary
 * param receives the memory address of the total sum of salaries
 * param receives the memory address of the number of employees above the average
 * return it doesn´t return anything, it only shows the information on the screen
 */
void printAverageInfo(float* promedio,float* total,int* cantEncimaDelPromedio);

#endif /* ARRAYEMPLOYEES_H_ */
