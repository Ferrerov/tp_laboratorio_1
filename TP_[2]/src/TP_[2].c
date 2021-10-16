/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Ferrero Valentin
 Version     :
 Copyright   : 
 Description : Trabajo practico 2
 ============================================================================
 */

#include "ArrayEmployees.h"

#define LEN 3
#define RETRIES 3

int main(void)
{
	setbuf(stdout, NULL);

	int response;
	eEmployee employee[LEN];

    initEmployees(employee, LEN);
    int id;
    int flagAdd = -1;

	do{
		    	printf("\n1. Dar de alta un empleado.\n");
		    	printf("2. Modificar datos de un empleado.\n");
		    	printf("3. Dar de baja un empleado.\n");
		    	printf("4. Informar:\n"
		    	    			"    1) Listado de empleados.\n"
		    	    			"    2) Total y promedio de salarios, y cuantos empleados superan el salario promedio\n");
		    	printf("5. Salir.\n");

		    	getNumber(&response, "\nIngrese una opción: ", "\nError, ingrese una opción válida: ", 1, 11, INT_MAX);

		    	switch(response){
		    	    case 1:
		    	    	printf("Usted ha seleccionado la opción 1: Dar de alta un empleado.\n");
		    	    	if(addEmployee(employee, LEN, &id) == 0)
		    	    	{
			    	    	printf("\nEl ID del nuevo empleado es: %d", id);
			    	    	flagAdd = 0;
		    	    	}
		    	    	else
		    	    	{
			    	    	printf("\nNo se pudo dar de alta el empleado, operación cancelada.");
		    	    	}
		    	        break;
		    	    case 2:
		    	    	printf("Usted ha seleccionado la opción 2: Modificar dato de un empleado.\n");
		    	    	printEmployeeList(employee, LEN);
		    	    	if(flagAdd == 0 && modifyEmployee(employee, LEN, RETRIES) == 0)
		    	    	{
		    	    		printf("\nSe ha modificado el dato del empleado.");
		    	    	}
		    	    	else
		    	    	{
		    	    		printf("\nNo se ha podido modificar el dato del empleado.");
		    	    	}
		    	        break;
		    	    case 3:
		    	    	printf("Usted ha seleccionado la opción 3: Dar de baja un empleado.\n");
		    	    	printEmployeeList(employee, LEN);
		    	    	if(flagAdd == 0 && removeEmploye(employee, LEN, RETRIES) == 0)
		    	    	{
		    	    		printf("\nSe ha dado de baja al empleado. ");
		    	    	}
		    	    	else
		    	    	{
		    	    		printf("\nNo se ha podido dar de baja al empleado. ");
		    	    	}

		    	    	break;
		    	    case 4:
		    	    	printf("Usted ha seleccionado la opción 4: Informar:\n"
		    	    			"    1) Listado de empleados.\n"
		    	    			"    2) Total y promedio de salarios, y cuantos empleados superan el salario promedio\n");
		    	    	organizeByLastName(employee, LEN);
		    	    	if(flagAdd != 0 && printEmployeeList(employee, LEN) != 0)
		    	    	{
		    	    		printf("No hay empleados que mostrar. \n");
		    	    	}
		    	    	else
		    	    	{
		    	    		salaryAverageList(employee, LEN);
		    	    	}
		    	    	break;
		    	    case 5:
		    	    	printf("Usted ha seleccionado la opción 5: Salir.\n");
		    	    	break;
		    	    default:
				    	printf("Error, seleccione una opción de menu válida. \n");
		    	    	break;
		    	}
		    }while(response != 5);
	return EXIT_SUCCESS;
}
