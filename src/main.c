#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma(int a, int b);
int resta(int a, int b);
int producto(int a, int b);
int division(int a, int b);

/** @brief Genero las funciones que tendra mi calculadora
 * 
 *
 *
 *
 *
 *
 *
**/
int suma(int a, int b){
	return (a + b);
}
int resta(int a, int b){
	return (a - b);
}
int producto(int a, int b){
	return (a * b);
}
int division(int a, int b){
	return (a / b);
}
int main(void){
	int resultado=0;
	calculadora_t calculadora1= CrearCalculadora();
	AgregarOperacion(calculadora1, '+' ,suma);
	AgregarOperacion(calculadora1, '-' ,resta);
	AgregarOperacion(calculadora1, '*' ,producto);
	AgregarOperacion(calculadora1, '/' ,division);
	resultado = Calcular(calculadora1, "2+4");
	printf("Resultado: %i\r\n",resultado);
	resultado = Calcular(calculadora1, "2*4");
	printf("Resultado: %i\r\n",resultado);
	resultado = Calcular(calculadora1, "4-2");
	printf("Resultado: %i\r\n",resultado);
	resultado = Calcular(calculadora1, "4/2");
	printf("Resultado: %i\r\n",resultado);
	return 0;
}
