/*
 ============================================================================
 Name        : ProjectAeds08.c
 Author      : @k1kvlc
 Version     : 0.1
 Copyright   : Your copyright notice
 Description : Conversão Temporal
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int seg, min, hr

	printf("Insira o tempo em segundos:\n");
	scanf("%d", &seg);

	hr = seg / 3600;
	seg = seg - (3600*hr);

	printf("Horas: %d.\n", hr);
	printf("Minutos: %d.\n", min);
	printf("Segundos: %d.\n", seg);

	system("pause");

	return 0;
}
