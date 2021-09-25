#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/// @fn int sumaCalculo(int, int)
/// @brief int suma dos numeros
/// @param primerOperando
/// @param segundoOperando
/// @return devuelve el resultado de la suma
int sumaCalculo(int primerOperando,int segundoOperando);

/// @fn int restaCalculo(int, int)
/// @brief resta dos numeros
/// @param primerOperando
/// @param segundoOperando
/// @return devuelve el resultado de la resta
int restaCalculo(int primerOperando,int segundoOperando);

/// @fn int divisionCalculo(float, float, float*)
/// @brief funcion que divide un numero por otro
/// @param primerOperando primer numero, el dividendo
/// @param segundoOperando segundo numero, el divisor
/// @param resultado puntero al espacio de memoria donde se escribe el resultado de la division
/// @return devuelve 1 si se pudo dividir o 0 si se dividio por 0
int divisionCalculo(float primerOperando,float segundoOperando, float* resultado);

/// @fn int multiplicacionCalculo(int, int)
/// @brief multiplica dos numeros entre si
/// @param primerOperando
/// @param segundoOperando
/// @return devuelve el resultado de la multiplicacion
int multiplicacionCalculo(int primerOperando,int segundoOperando);

/// @fn int calcularFactorial(int, int*)
/// @brief  calcula el factorial de UN numero
/// @param operando numero a buscar factorial
/// @param resultado puntero al espacio de memoria donde se escribe el resultado del factorial
/// @return devuelve 1 si existe factorial o 0 si no es posible
int calcularFactorial(int operando, int* resultado);

#endif /* FUNCIONES_H_ */
