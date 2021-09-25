#ifndef INGRESODEDATOS_H_
#define INGRESODEDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @fn void mostrarMenu(void)
/// @brief imprime el menu
void mostrarMenu(void);

/// @fn int desarrolloMenu(void)
/// @brief se muestra el menu y se selecciona una opcion
/// @return devuelve la opcion
int desarrolloMenu(void);

/// @fn int ingresarOpcion(void)
/// @brief funciona dentro del desarrollo menu, pide y valida la opcion ingresada
/// @return devuelve un numero
int ingresarOpcion(void);

/// @fn int ingresarNumero(char[], char[], int*)
/// @brief
/// @pre
/// @post
/// @param mensaje mensaje a imprimir para que el usuario sepa que ingresar
/// @param mensajeDeError mensaje de error en caso de que lo ingresado no sea valido
/// @param resultado puntero al espacio de memoria donde se escribe el numero ingresado
/// @return
int ingresarNumero(char mensaje[], char mensajeDeError[], int* resultado);

/// @fn int ingresarCadena(int*)
/// @brief funciona dentro de ingresarNumero, obtiene un valor de cadena
/// @param resultado puntero a la memoria donde se escribe la cadena obtenida, en tipo entero
/// @return devuelve 1 si la cadena es numerica o 0 si tiene un digito(nunca devuelve 0 en este caso)
int ingresarCadena(int* resultado);

/// @fn int validacionNumero(char[])
/// @brief valida que la cadena ingresada no contenga caracteres(saltea el primer caracter si es -,
/// para que sea compatible con negativos
/// @param cadena
/// @return devuelve 1 si la cadena es numerica o 0 si tiene un caracter
int validacionNumero(char cadena[]);

#endif /* INGRESODEDATOS_H_ */
