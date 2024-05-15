/*
 ============================================================================
 Name        : ProjectAeds12.c
 Author      : @k1kvlc
 Version     : 0.1
 Copyright   : kvlc
 Description : Piramide
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("Piramide"); /* prints Piramide */
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>>

int main() {
  int linhas, espacos, asteriscos, i, j;

  printf("Digite o número de linhas da pirâmide: ");
  scanf("%d", &linhas);

  for (i = 1; i <= linhas; i++) {

    espacos = linhas - i;

    for (j = 1; j <= espacos; j++) {
      printf(" ");
    }

    asteriscos = 2 * i - 1;

    for (j = 1; j <= asteriscos; j++) {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}
