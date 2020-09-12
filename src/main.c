/*
 ============================================================================
 Name        : TP1.c
 Author      : Damián D'Arrigo
 Divison	 : 1º E

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1.h"

int main(void) {
	setbuf(stdout, NULL);

	float operando1 = 0;
	float operando2 = 0;
	float resultadoSuma = 0;
	float resultadoResta = 0;
	float resultadoMultiplicacion = 0;
	float resultadoDivision = 0;
	int resultadoFactorial1 = 0;
	int resultadoFactorial2 = 0;
	int flagOperando1 = 0;
	int flagOperando2 = 0;
	int flagCalcular = 0;
	int flagMenu = 0;
	char respuesta;
	char opcion;

	do {
		system("cls");
		if (flagOperando1 == 0) {
			printf("a- Ingrese el primer operando:\n");
		} else {
			printf("a- Ingrese el primer operando Op=%.2f\n", operando1);
		}
		if (flagOperando2 == 0) {
			printf("b- Ingrese el segundo operando:\n");
		} else {
			printf("a- Ingrese el segundo operando Op=%.2f\n", operando2);
		}
		printf("c- Calcular todas las operaciones:\n");
		printf("d- Informar resultados:\n");
		printf("e- Salir:\n");
		fflush(stdin);
		scanf("%c", &opcion);
		switch (opcion) {
		case 'a':
			printf("Ingrese el primer numero:\n");
			fflush(stdin);
			if (scanf("%f", &operando1) == 0) {
				printf("Error, solo se pueden ingresar numeros\n");
				fflush(stdin);
				system("pause");
			}else{
				flagOperando1 = 1;
			}
			break;
		case 'b':
			printf("Ingrese el segundo numero:\n");
			fflush(stdin);
			if (scanf("%f", &operando2) == 0) {
				printf("Error, solo se pueden ingresar numeros\n");
				fflush(stdin);
				system("pause");
			}else{
				flagOperando2 = 1;
			}
			break;
		case 'c':
			if (flagOperando1 == 0 || flagOperando2 == 0) {
				printf("Error. Debe ingresar ambos operandos para calcular\n");
			} else {
				resultadoSuma = suma(operando1, operando2);
				resultadoResta = resta(operando1, operando2);
				resultadoMultiplicacion = multiplicacion(operando1, operando2);
				resultadoDivision = division(operando1, operando2);
				resultadoFactorial1 = factorial(operando1);
				resultadoFactorial2 = factorial(operando2);
				flagCalcular = 1;
				printf("Las operaciones se realizaron correctamente\n");
			}
			system("pause");
			break;
		case 'd':
			if (flagCalcular == 0) {
				printf("Error. Debe calcular antes de mostrar\n");
			} else {
				printf("\tLa suma es %.2f\n", resultadoSuma);
				printf("\tLa resta es %.2f\n", resultadoResta);
				printf("\tLa  es multiplicacion es %.2f\n",
						resultadoMultiplicacion);
				if (operando2 == 0) {
					printf("Error. No se puede dividir por cero\n");
				} else {
					printf("\tLa division es %.2f\n", resultadoDivision);
				}
				if (operando1 <= 0) {
					printf("Error. No se puede realizar factorial de cero o numeros negativos\n");
				} else if (verSiEsEntero(operando1) == 1) {
					printf("\tEl factorial del primer numero es %d\n",
							resultadoFactorial1);
				} else {
					printf("Error. No se puede realizar factorial de numeros decimales\n");
				}
				if (operando2 <= 0) {
					printf("\tError. No se puede realizar factorial de cero o numeros negativos\n");
				} else if (verSiEsEntero(operando2) == 1) {
					printf("\tEl factorial del segundo numero es %d\n",
							resultadoFactorial2);
				} else {
					printf(
							"\tError. No se puede realizar factorial de numeros decimales\n");
				}
			}
			system("pause");
			break;
		case 'e':
			printf("Seguro que desea salir? s/n\n");
			fflush(stdin);
			scanf("%c", &respuesta);
			while (respuesta != 'n' && respuesta != 's') {
				printf("Respuesta invalida, ingrese s o n:\n");
				fflush(stdin);
				scanf("%c", &respuesta);
			}
			if (respuesta == 's') {
				printf("Hasta luego\n");
				system("pause");
				flagMenu = 1;
			} else {
				flagMenu = 0;
			}
			break;
		default:
			printf("Error. Debe ingresar una opcion valida\n");
			system("pause");
		}
	} while (flagMenu == 0);

	return EXIT_SUCCESS;
}
