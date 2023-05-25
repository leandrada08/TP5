#include <stdint.h>
#include <stdbool.h>
#include <string.h>

//typedef struct operaciones_s * operaciones_t; 

typedef struct calculadora_s * calculadora_t; //Genero un objeto del tipo candado

typedef int (*funcion_t)(int, int);

calculadora_t CrearCalculadora(void);

bool AgregarOperacion(calculadora_t calculadora, char operador, funcion_t funcion);

int Calcular(calculadora_t calculadora, char * cadena);