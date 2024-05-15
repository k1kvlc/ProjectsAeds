/*
 ============================================================================
 Name        : ProjectAeds10.c
 Author      : @k1kvlc
 Version     :0.1
 Copyright   : Your copyright notice
 Description : Custo de energia
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calcKw(float v_sal, float q_kw, float *v_kw, float *v_rs, float *v_dsc){
	//a) Kw é um milessimo do salario e b e c

	(*v_kw) = v_sal / 1000;
	(*v_rs) = (*v_kw) * q_kw;
	(*v_dsc) = (*v_rs) * 0.85;
}


int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "Portuguese")

	float val_sal, qtde_kw, val_kw, val_reais, val_desc;

	printf("Insira o salário mínimo:\n");
	scanf("%f", &val_sal);
	printf("Insira a quantidade de KW gastos:\n");
	scanf("%f", &qtde_kw);

	//invocar procedimento

	calcKw(val_sal, qtde_kw, &val_kw, &val_reais, &val_desc)

	printf("Valor de 1 KW (em r$): %.2f.\n", val_kw);
	printf("Valor a ser pago pela residencia (em r$): %.2f.\n", val_reais);
	printf("Valor com desconto (em r$): %.2f.\n", val_desc);


	return 0;
}
