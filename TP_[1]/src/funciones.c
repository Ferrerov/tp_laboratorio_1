#include "funciones.h"

int sumaCalculo(int primerOperando,int segundoOperando)
{
	int resultado;

	resultado = primerOperando + segundoOperando;

	return resultado;
}
int restaCalculo(int primerOperando,int segundoOperando)
{
	int resultado;

	resultado = primerOperando - segundoOperando;

	return resultado;
}
int divisionCalculo(float primerOperando,float segundoOperando, float* resultado)
{
	int verificador = 0;

	if(segundoOperando != 0)
	{
		*resultado = primerOperando / segundoOperando;
		verificador = 1;
	}

	return verificador;
}
int multiplicacionCalculo(int primerOperando,int segundoOperando)
{
	int resultado;

	resultado = primerOperando * segundoOperando;

	return resultado;
}
int calcularFactorial(int operando, int* resultado)
{
	int verificador = 0;
	int factorial = 1;

	if(!(operando < 0))
	{
		if(operando == 0)
		{
			*resultado = 1;
			verificador = 1;
		}
		else
		{
			while(operando > 1)
			{
				factorial = factorial * operando;
				operando--;
			}
			*resultado = factorial;
			verificador = 1;
		}
	}
	return verificador;
}


