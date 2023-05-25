#include "calculadora.h"


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
	return a+b;
}
int resta(int a, int b){
	return a-b;
}
int producto(int a, int b){
	return a*b;
}
int main(void){
	int resultado
	calculadora_t calculadora= CrearCalculadora();
	AgregarOperacion(calculadora,'+',suma);
	AgregarOperacion(calculadora,'-',resta);
	AgregarOperacion(calculadora,'*',producto);
	AgregarOperacion(calculadora,'/',division);
	resultado = Calcular(calculadora, "2+4");
	printf("resultado %i\r\n", resultado);
	resultado = Calcular(calculadora, "2*4");
	printf("resultado %i\r\n", resultado);
	resultado = Calcular(calculadora, "4-2");
	printf("resultado %i\r\n", resultado);
	resultado = Calcular(calculadora, "4/2");
	printf("resultado %i\r\n", resultado);
}