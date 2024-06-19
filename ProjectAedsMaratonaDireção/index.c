#include <stdio.h>

int main() {
    char amigo, solis;
    int angulo;

    // Direção
    printf("Digite a direção do amigo (a, b, c ou d): ");
    scanf(" %c", &amigo);
    printf("Digite a direção do solis (a, b, c ou d): ");
    scanf(" %c", &solis);

    // Diferença
    int diferenca = solis - amigo;
    if (diferenca < 0) {
        diferenca += 4; 
    }

    
    angulo = diferenca * 90;

    // Resultado
    printf("O ângulo que seu amigo deve virar é aproximadamente %d graus.\n", angulo);

    return 0;
}
