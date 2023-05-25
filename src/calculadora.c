#include "calculadora.h"
#include <stdlib.h>
#include <string.h>




typedef struct operacion_s * operacion_t;


struct calculadora_s{
	operacion_t operaciones;
};

struct operacion_s {
	char operador;
	funcion_t funcion;
	operacion_t siguiente;
};


/** Funcion verificada para hacer lo que necesitamos OK
 *
 *
 *
**/
operacion_t BuscarOperacion(calculadora_t calculadora, char operador){

	//Hacer codigo para evitar error cuando la calculadora esta vacia
	
	operacion_t result = NULL; //<!Genero un puntero para devolver lo que necesito
	for(operacion_t actual = calculadora->operaciones; actual->siguiente!=NULL; actual=actual->siguiente){//<! Recorro los operador como lista enlazadas hasta encontrar un nulo
		if(actual->operador==operador){ //<! Verifico que sea el operador que busco
			result=actual;//<! Guardo el operador que es igual al buscado
			// Porque no devuelvo este valor?

			break;
		}
	}
	return result;
}



calculadora_t CrearCalculadora(void){ //Creo la calculadora de manera dinamica
	calculadora_t result = malloc(sizoef(struct calculadora_s));
	if (result){
		memset(result, 0, sizeof(struct calculadora_s)); //limpia la memoria que usara la calculadora
	}
	return result; //Devuelve la calculadora vacia
}



/** @brief Funcion para agregar operacion a la calculadora
* @return 1 si operacion es distinto de 0 y 0 si es igual
*
**/
bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion){
	operacion_t operacion = NULL;//<! En caso de que ya exista la operacion, lo creo como nulo al puntero
	if(!BuscarOperacion(calculadora, operador)){//<! Verifico si ya existe el operador
		operacion_t operacion = malloc(sizeof(struct operacion_s));	//<! Creo una operacion, en el caso de no tener espacio devolvera NULL
		// Como se que esta se crea dentro del espacio de alcenamiento de calculadora y no afuera
	}
	if(operacion){ //<! Verifico que el operador sea disntito de NULL
		operacion->operador = operador;
		operacion->funcion = funcion;
		operacion->siguiente=calculadora->operaciones;
		calculadora->operaciones=operacion;
	}
	return (operacion != NULL);
}


/** @brief Funcion para calcular el valor de una determinada operacion
*
*
*
*
**/
int Calcular(calculadora_t calculadora, char * cadena){
	int a,b;
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