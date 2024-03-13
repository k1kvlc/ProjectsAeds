/*
 ============================================================================
 Name        : ProjectAeds04.c
 Author      : k1
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// Função para calcular a soma de quatro númeoros inteiros

#include <stdio.h>
#include <stdlib.h>

int calcularSoma(int num1, int num2, int num3, int num4) {
	return num1 + num2 + num3 + num4;
}

int main(void) {
	//Jeito 1
	//int resultadoSoma = calcularSoma(2, 3, 5, 7);
	//printf("1) A soma dos números é: %d\n", resultadoSoma);

	//Jeito 2
	int numero = 0;
	int soma = 0;
	for(int i =1; i <= 4; i++){
		printf("Digite o número para ser somado: ");
		//fflsush(stdout)
		scanf("%d", &numero);
		soma = soma + numero;
	}
	printf("\nA soma é: %d", soma);
}

