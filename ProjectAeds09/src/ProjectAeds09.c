/*
 ============================================================================
 Name        : ProjectAeds09.c
 Author      : @k1kvlc
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Maior entre 2 n
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	float n1, n2

	printf("Insira o primeiro numero:\n");
	scanf("%f", &n1);
    printf("Insira o segundo maior numero:\n");
    scanf("%f," &n2)

    if(n1 > n2){
    	printf("O maior é: %f. \n", n1);
    } else {
    	if(n2 > n1){
    		printf("O maior é: %f.\n", n2);
    	}else{
    		printf("Os numeros sao iguais.\n");
    	}
    }

    system("pause");

	return EXIT_SUCCESS;
}
