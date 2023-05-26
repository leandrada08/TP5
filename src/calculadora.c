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
	if(actual!=NULL){
		for(actual;actual!=NULL; actual=actual->siguiente){//<! Recorro los operador como lista enlazadas hasta encontrar un nulo
			if(actual->operador==operador){ //<! Verifico que sea el operador que busco
				result=actual;//<! Guardo el operador que es igual al buscado
				break;
			}
		}
	}
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
	operacion_t operacion = malloc(sizeof(struct operacion_s)); 
	if(!BuscarOperacion(calculadora, operador)){//<! Verifico si ya existe el operador
		operacion_t operacion = malloc(sizeof(struct operacion_s));	//<! Creo una operacion, en el caso de no tener espacio devolvera NULL
		// Como se que esta se crea dentro del espacio de alcenamiento de calculadora y no afuera
	}
	if ((operacion) && !BuscarOperacion(calculadora, operador)){ //<! Verifico que el operador sea disntito de NULL
		operacion->operador = operador;
		operacion->funcion = funcion;
		operacion->siguiente=calculadora->operaciones;
		calculadora->operaciones=operacion;
	}
	return (operacion != NULL);
}

int Calcular(calculadora_t calculadora, char * cadena){
	int a;
	int b;
	char operador;
	int result = 0;

	for(int indice = 0;indice<strlen(cadena); indice++){
		if(cadena[indice]<'0'){ //Como esta funcion busca al operador?
        //Porque menor que 0 para buscar el operador?
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