

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n, i, x;
    int stack[MAX];
    int top = -1;
    int sum = 0;

    // Leitura
    scanf("%d", &n);

    // Processamento
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 0) {
            if (top >= 0) {
                top--;
            }
        } else {
            stack[++top] = x;
        }
    }

    // Cálculo
    for (i = 0; i <= top; i++) {
        sum += stack[i];
    }

    // Resultado
    printf("%d\n", sum);

    return 0;
}