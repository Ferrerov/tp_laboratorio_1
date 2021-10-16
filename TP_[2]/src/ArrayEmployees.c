#include "ArrayEmployees.h"

void initEmployees(eEmployee employee[], int len)
{
	for(int i = 0; i<len; i++)
	{
		employee[i].isEmpty = EMPTY;
	}
}

int addEmployee(eEmployee employee[], int len, int* pIdEmployee)
{
	int validation = -1;

	for(int i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == EMPTY)
		{
			*pIdEmployee = i + 1;
			getString("\nIngrese el nombre del empleado: ", employee[i].name, len);
			getString("\nIngrese el apellido del empleado: ", employee[i].lastName, len);
			if(getFloat(&employee[i].salary, "\nIngrese el salario del empleado: ", "\nError, ingrese un salario válido: ", 1, INT_MAX, 5) != 0)
			{
				break;
			}
			if(getNumber(&employee[i].sector, "\nIngrese el sector del empleado: ", "\nError, ingrese un sector válido: ", 1, INT_MAX, 5) != 0)
			{
				break;
			}
			employee[i].isEmpty = OCCUPIED;
			validation = 0;
			break;
		}
	}
	return validation;
}

int findEmployeeById(eEmployee employee[], int len, int retries, int* index)
{
	int validation = -1;
	int idFind;

	do
	{
		retries--;

		getNumber(&idFind, "\nIngrese el ID del empleado: ", "\nError, ID fuera de rango. Ingrese nuevamente: ", 1, len, 5);

		for(int i = 0; i < len; i++)
		{
			if(employee[i].isEmpty == OCCUPIED &&  employee[i].id == idFind)
			{
				*index = i;
				retries = 0;
				validation = 0;
				break;
			}
		}
		if(validation != 0)
		{
			printf("ID no encontrado.");
		}
	}while(retries > 0);

	return validation;
}

int modifyEmployee(eEmployee employee[], int len, int retries)
{
	int validation = -1;
	int index;
	int response;

		if(findEmployeeById(employee, len, retries, &index) == 0)
		{
			printf("\nQue dato desea modificar?"
					"\n1. Nombre "
					"\n2. Apellido "
					"\n3. Salario "
					"\n4. Sector");
			getNumber(&response, "\nIngrese una opción: ", "\nError, ingrese una opción válida: ", 1, 11, INT_MAX);

			switch(response)
			{
			case 1:
				getString("\nIngrese el nombre del empleado: ", employee[index].name, len);
				validation = 0;
				break;
			case 2:
				getString("\nIngrese el apellido del empleado: ", employee[index].lastName, len);
				validation = 0;
				break;
			case 3:
				if(getFloat(&employee[index].salary, "\nIngrese el salario del empleado: ", "\nError, ingrese un salario válido: ", 1, INT_MAX, 5) == 0)
				{
					validation = 0;
				}
				break;
			case 4:
				if(getNumber(&employee[index].sector, "\nIngrese el sector del empleado: ", "\nError, ingrese un sector válido: ", 1, INT_MAX, 5) == 0)
				{
					validation = 0;
				}
				break;
			}
		}
	return validation;
}

int removeEmploye(eEmployee employee[], int len, int retries)
{
	int validation = -1;
	int index;
	char response;

	if(findEmployeeById(employee, len, retries, &index) ==0)
	{
		printf("\nEsta seguro que desea dar de baja al cliente? (s/n): ");
		fflush(stdin);
		scanf("%c", &response);
		while(!(response == 's' || response == 'n'))
		{
			printf("\nError, ingrese una opción válida: ");
			printf("\nEsta seguro que desea dar de baja al cliente? (s/n)");
			fflush(stdin);
			scanf("%c", &response);
		}
		if(response == 's')
		{
			employee[index].isEmpty = EMPTY;
			validation = 0;
		}
		else
		{
			printf("\nNo se ha podido dar de baja, se ha cancelado la operación. ");
			printf("\nPulse una tecla para continuar");
			getchar();
		}
	}
	return validation;
}

int organizeByLastName(eEmployee employee[], int len)
{
	int validation = -1;
	eEmployee aux;

	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(employee[i].sector < employee[j].sector)
			{
				aux = employee[i];
				employee[i] = employee[j];
				employee[j] = aux;
				validation = 0;
			}
			else
			{
				if(employee[i].sector == employee[j].sector && strcmp(employee[i].lastName, employee[j].lastName) > 0)
				{
					aux = employee[i];
					employee[i] = employee[j];
					employee[j] = aux;
					validation = 0;
				}
			}
		}
	}
	return validation;
}

int printEmployee(eEmployee employee)
{
	int validation = -1;

	if(employee.isEmpty == OCCUPIED)
	{
		printf("\n|%-6d|%-30s|%-30s|%-11.2f|%-6d|",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
		validation = 0;
	}

	return validation;
}

int printEmployeeList(eEmployee employee[], int len)
{
	int validation = -1;
	int flagTitles = -1;

	for(int i = 0; i < len; i++)
	{
		if(printEmployee(employee[i]) == 0)
		{
			if(flagTitles != 0)
			{
				printf("\n|%*s|%*s|%*s|%*s|%*s", -6, "ID EMPLEADO", -30, "NOMBRE",-30,"APELLIDO",-11 ,"SALARIO", -6,"SECTOR");
				printf("\n-------------------------------------------------------");
				flagTitles = 0;
			}
			validation = 0;
		}
	}

	return validation;
}

int salaryAverage(eEmployee employee[], int len, float* pAverage, float* pTotal, int* pCounter)
{
	int validation = -1;
	float total = 0;
	float average;
	int counter = 0;
	int moreThanAverageCounter = 0;

	for(int i = 0; i < len; i++)
	{
		if(employee[i].isEmpty == OCCUPIED)
		{
			total = total + employee[i].salary;
			counter++;
			validation = 0;
		}
	}

	average = total / counter;
	*pTotal = total;

	for(int j = 0; j < len; j++)
	{
		if(employee[j].isEmpty == OCCUPIED && employee[j].salary > average)
		{
			total = total + employee[j].salary;
			moreThanAverageCounter++;
			validation = 0;
		}
	}

	*pCounter = moreThanAverageCounter;
	*pAverage = average;

	return validation;
}

int salaryAverageList(eEmployee employee[], int len)
{
	int validation = -1;
	float average;
	float total;
	int counter;

	if(salaryAverage(employee, len, &average, &total, &counter) == 0)
	{
		printf("\nEL total de los salario es de: %.2f", total);
		printf("\nEL promedio de los salario es de: %.2f", average);
		printf("\nLa cantidad de empleados que superan el salario promedio es de: %d", counter);
	}

	return validation;
}
