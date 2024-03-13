/*
 ============================================================================
 Name        : ProjectAeds03
 Author      : k1
 Version     : 0.1
 Copyright   : @k1kvlc
 Description : Recursivo
 ============================================================================
 */
//Função recursiva em uma linha utilizando operador ternário
#include <stdio.h>
#include <stdlib.h>
int FatorialRecursivaUmaLinha(int c) {
	return (c == 0 || c == 1) ? 1 : (c + FatorialRecursivaUmaLinha(c - 1));
}

//função recursiva padrão
int fatorialRecursivo(int n) {
	//caso base
	if (n == 0 || n == 1) {
		return 1;
	} else{
		//chamada recursdiva
		return n * fatorialRecursivo(n - 1);
	}
}
//Solução iterativa
 int fatorialComLoop(int n) {
	 int resultado = 1;
	 //Utilizando um loop for para multiplicar os números de 1 a n
	 for (int i =1; i <= n; i++) {
		 resultado*= i;
	 }
	 return resultado;
 }
 int main(void) {
	 int numero = 5;
	 printf(" O fatorial do %d é: %d/n", numero, fatorialRecursivo(numero));//chamando a solução
	 return 0;}
