/*
 ============================================================================
 Name        : TP_[1].c
 Author      : FERRERO VALENTIN
 Version     :
 Copyright   :
 Description : Hacer una calculadora.
 ============================================================================
 */

#include "funciones.h"
#include "ingresoDeDatos.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int primerOperando;
	int segundoOperando;
	int suma;
	int resta;
	float division;
	int multiplicacion;
	int primerFactorial;
	int segundoFactorial;
	int verificadorDivision;
	int verificadorPrimerFactorial;
	int verificadorSegundoFactorial;

	do{
		opcion = desarrolloMenu();

		switch (opcion) {
		case 1:
			printf("Usted ha seleccionado la opción 1- Ingresar primer operando.\n");
			ingresarNumero("Ingrese el primer operando: ", "\nError, ingrese un operando vàlido: ", &primerOperando);
			break;
		case 2:
			printf("Usted ha seleccionado la opción 2- Ingresar segundo operando.\n");
			ingresarNumero("Ingrese el primer operando: ", "\nError, ingrese un operando vàlido: ", &segundoOperando);
			break;
		case 3:
			printf("Usted ha seleccionado la opción 3- Calcular todas las operaciones.\n");
			suma = sumaCalculo(primerOperando,segundoOperando);
			resta = restaCalculo(primerOperando,segundoOperando);
			multiplicacion = multiplicacionCalculo(primerOperando,segundoOperando);
			verificadorDivision = divisionCalculo(primerOperando,segundoOperando,&division);
			verificadorPrimerFactorial = calcularFactorial(primerOperando,&primerFactorial);
			verificadorSegundoFactorial = calcularFactorial(segundoOperando,&segundoFactorial);
			break;
		case 4:
			printf("Usted ha seleccionado la opción 4- Mostrar resultado de las operaciones.\n");

			printf("\nEl resultado de la suma entre %d y %d es: %d" ,primerOperando, segundoOperando , suma);
			printf("\nEl resultado de la resta entre %d y %d es: %d" ,primerOperando, segundoOperando , resta);
			if(verificadorDivision == 1)
			{
				printf("\nEl resultado de la division de %d por %d es: %.2f" ,primerOperando, segundoOperando , division);
			}
			else
			{
				printf("\nNo es posible dividir por cero.");
			}
			printf("\nEl resultado de la multiplicacion entre %d y %d es: %d" ,primerOperando, segundoOperando , multiplicacion);
			if(verificadorPrimerFactorial == 1)
			{
				printf("\nEl factorial de %d es: %d" ,primerOperando, primerFactorial);
			}
			else
			{
				printf("\nNo se puede calcular el factorial del primer operando.");
			}
			if(verificadorSegundoFactorial == 1)
			{
				printf("\nEl factorial de %d es: %d" ,segundoOperando, segundoFactorial);
			}
			else
			{
				printf("\nNo se puede calcular el factorial del segundo operando.");
			}
			printf("\nPresione ENTER para continuar");
			fflush(stdin);
			getchar();
			break;
		case 5:
			break;
		}
	} while (!(opcion == 5));

	return EXIT_SUCCESS;
}
