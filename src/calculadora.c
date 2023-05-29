#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct operacion_s * operacion_t;


struct calculadora_s {
	operacion_t operaciones;
};

struct operacion_s {
	char operador;
	funcion_t funcion;
	operacion_t siguiente;
};


operacion_t BuscarOperacion(calculadora_t calculadora, char operador);


operacion_t BuscarOperacion(calculadora_t calculadora, char operador){
	operacion_t result = NULL; //<!Genero un puntero para devolver lo que necesito
	operacion_t actual = calculadora->operaciones;
	while(actual!=NULL){
		if(actual->operador==operador){ //<! Verifico que sea el operador que busco
			result=actual;//<! Guardo el operador que es igual al buscado
			break;
		}
		actual=actual->siguiente;
	}
	#if 0
	if(actual!=NULL){
		for(actual;actual!=NULL; actual=actual->siguiente){//<! Recorro los operador como lista enlazadas hasta encontrar un nulo
			if(actual->operador==operador){ //<! Verifico que sea el operador que busco
				result=actual;//<! Guardo el operador que es igual al buscado
				break;
			}
		}
	}
	#endif
	return result;
}



calculadora_t CrearCalculadora(void){ //Creo la calculadora de manera dinamica
	calculadora_t result = malloc(sizeof(struct calculadora_s));
	if (result){
		memset(result, 0, sizeof(struct calculadora_s)); //limpia la memoria que usara la calculadora
	}
	return result; //Devuelve la calculadora vacia
}


bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion){
	bool result = BuscarOperacion(calculadora, operador);//<! Verifico si ya existe el operador, el operador ! es operador logico, solo verifica que sea distinto de 0
	if (!result) {
		operacion_t operacion = malloc(sizeof(struct operacion_s));	//<! Creo una operacion, en el caso de no tener espacio devolvera NULL
		if ((operacion)){ //<! Verifico que el operador sea disntito de NULL, el operador && es logico, verifica que cada uno sea dinstito de 0
			operacion->operador = operador;
			operacion->funcion = funcion;
			operacion->siguiente=calculadora->operaciones;
			calculadora->operaciones=operacion;
		}
		result = operacion != NULL;
	}
	return result;
}

int Calcular(calculadora_t calculadora, char * cadena){
	int a;
	int b;
	char operador;
	int result = 0;

	for(int indice = 0;indice<strlen(cadena); indice++){
		if(cadena[indice]<'0'){ //<!Corroboramos que el cadena indice sea menor al ascii de 0
			operador = cadena[indice];
			a = atoi(cadena);//Como funciona atoi
			b = atoi(cadena + indice + 1);
			break;
		}
	}
	operacion_t operacion = BuscarOperacion(calculadora, operador);
	if(operacion) {
		result = operacion->funcion(a,b);
	}
	return result;
}