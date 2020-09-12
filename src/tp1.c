#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

float suma(float num1, float num2) {
	float suma = num1 + num2;
	return suma;
}

float resta(float num1, float num2) {
	float resta = num1 - num2;
	return resta;
}

float multiplicacion(float num1, float num2) {
	float multiplicacion = num1 * num2;
	return multiplicacion;
}

float division(float num1, float num2) {
	float division = num1 / num2;
	return division;
}

int factorial(int num) {
	int factorial = 1;
	for (int i = 1; i <= num; i++) {
		factorial = factorial * i;
	}
	return factorial;
}

int verSiEsEntero (float num){
	int flagValidacion = 0;
	int numero = (int)num;
	if(numero == num){
		flagValidacion = 1;
	}else{
		flagValidacion =0;
	}
	return flagValidacion;
}
