/*
 ============================================================================
 Name        : ProjectAeds04.c
 Author      : k1
 Version     : 0.1
 Copyright   : @k1kvlc
 Description : Desafio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int portaPremiada, portaEscolhida, portaMostrada, trocarPorta;
    char opcao;

    // Inicializa a semente para a função rand() usando o tempo atual
    srand(time(NULL));

    // Sortear a porta premiada
    portaPremiada = rand() % 3 + 1;

    // Solicitar ao jogador que escolha uma porta
    printf("Escolha uma porta (1, 2, 3): ");
    scanf("%d", &portaEscolhida);

    // Monty abre uma porta que não é a premiada e não foi escolhida pelo jogador
    do {
        portaMostrada = rand() % 3 + 1;
    } while (portaMostrada == portaEscolhida || portaMostrada == portaPremiada);

    printf("Monty abre a porta %d e lá há um bode.\n", portaMostrada);

    // Perguntar ao jogador se quer trocar de porta
    printf("Você quer trocar de porta? (s/n): ");
    scanf(" %c", &opcao); // espaço antes de %c para ignorar qualquer espaço em branco no buffer

    if (opcao == 's' || opcao == 'S') {
        trocarPorta = 6 - portaEscolhida - portaMostrada; // Soma das portas é 6, então isso encontra a terceira porta
        portaEscolhida = trocarPorta;
        printf("Você agora escolheu a porta %d.\n", portaEscolhida);
    } else {
        printf("Você manteve sua escolha inicial, porta %d.\n", portaEscolhida);
    }

    // Revelar se o jogador ganhou ou perdeu
    if (portaEscolhida == portaPremiada) {
        printf("Parabéns! Você ganhou um carro!\n");
    } else {
        printf("Que pena! Você encontrou um bode.\n");
    }

    return 0;
}
