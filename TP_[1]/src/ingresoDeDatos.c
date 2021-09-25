#include "ingresoDeDatos.h"

void mostrarMenu(void)
{
	printf("\n1- Ingresar primer operando. ");
	printf("\n2- Ingresar segundo operando. ");
	printf("\n3- Calcular todas las operaciones. ");
	printf("\n4- Mostrar resultado de las operaciones. ");
	printf("\n5- Salir. ");
}
int ingresarOpcion(void)
{
	int opcion;

	printf("\nIngrese una opción: ");
	fflush(stdin);
	scanf("%d", &opcion);

	while (!(opcion > 0 && opcion < 6)) {
		printf("\nError, ingrese una opción válida: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}
	return opcion;
}
int desarrolloMenu(void)
{
	int opcion;

	mostrarMenu();
	opcion = ingresarOpcion();

	return opcion;
}
int ingresarNumero(char mensaje[], char mensajeDeError[], int* resultado)
{
	int entero;
	int retorno = 0;

	printf("%s", mensaje);

	do
	{
		if (ingresarCadena(&entero) == 1)
		{
			*resultado = entero;
			retorno = 1;
			break;
		}

		printf("%s", mensajeDeError);
	}while(retorno == 0);

	return retorno;
}
int ingresarCadena(int* resultado)
{
	int retorno = 0;
	char cadena[20];

	scanf("%s", cadena);

	if(validacionNumero(cadena) == 1)
	{
		*resultado = atoi(cadena);
		retorno = 1;
	}

	return retorno;
}
int validacionNumero(char cadena[])
{
	int i = 0;
	int retorno = 1;

	if(cadena[i] == '-')
	{
		i = 1;
		while (cadena[i] != '\0')
		{
			if ((isdigit(cadena[i])) == 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	else
	{
		while (cadena[i] != '\0')
		{
			if ((isdigit(cadena[i])) == 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
