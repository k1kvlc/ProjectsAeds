#include <stdio.h>

int main() {
    int cartas[5];
    int i;

    // Cartas
    for (i = 0; i < 5; i++) {
        scanf("%d", &cartas[i]);
    }

    // Crescentemente
    int crescente = 1;
    for (i = 1; i < 5; i++) {
        if (cartas[i] < cartas[i - 1]) {
            crescente = 0;
            break;
        }
    }

    // Decrescentemente
    int decrescente = 1;
    for (i = 1; i < 5; i++) {
        if (cartas[i] > cartas[i - 1]) {
            decrescente = 0;
            break;
        }
    }

    // Resultado
    if (crescente) {
        printf("C\n");
    } else if (decrescente) {
        printf("D\n");
    } else {
        printf("N\n");
    }

    return 0;
}
