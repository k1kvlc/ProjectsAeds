/*
 ============================================================================
 Name        : ProjectAeds05.c
 Author      : k1
 Version     :0.1
 Copyright   : Your copyright notice
 Description : Média entre números
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//Váriaveis 4 números

	int n1, n2, n3, n4, soma;

	//Colocar 4 números

	printf("Informe o primeiro número):\n");
	scanf("%d", &n1);
	printf("Informe o segundo número):\n");
	scanf("%d", &n2);
	printf("Informe o terceiro número):\n");
	scanf("%d", &n3);
	printf("Informe o quarto número):\n");
	scanf("%d", &n4);

	//Soma dos 4 números

	soma = n1 + n2 + n3 + n4;

	printf("Resultado da soma: %d.\n", soma);

	return 0;

	// Ou pode fazer assim

	//int mains (){
	//int n1, n2, n3, n4
	//printf("Informe os quatro n em sequenci:\n", soma
	//scanf("%d", &n1)
	//scanf("%d", &n2)
	//scanf("%d", &n3)
	//scanf("%d", &n4)
	//s = n1 + n2 + n3 + n4;
	//printf ("Resultado da soma:%d.\n", s);


}
