/*
 ============================================================================
 Name        : ProjectAeds04.c
 Author      : k1
 Version     : 0.1
 Copyright   : @k1kvlc
 Description : p1 aeds portas
 ============================================================================
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int prtcomasdojob, prtdoparticipante, prtaberta, trcprt;
    char decisao;

    // números aleatórios a cada execucão do programa
    srand(time(NULL));

    // divide por 3 sobra 2 e adiciona mais 1 correspondendo as portas
    prtcomasdojob = rand() % 3 + 1;

    // participante escolhe uma das 3 portas
    printf("Escolha uma dessas portas! (1, 2, 3): ");
    scanf("%d", &prtdoparticipante);

    // Mc Ryan Sp abre uma porta que não foi escolhida pelo participante e que não tem uma pernoite com as do job!
    do {
        prtaberta = rand() % 3 + 1;
    } while (prtaberta == prtdoparticipante || prtaberta == prtcomasdojob);

    printf("Mc Ryan Sp abre a porta %d e lá não tem as do job!!!\n", prtaberta);

    // Mc Ryan Sp pergunta o participante se quer trocar sua porta escolhida!
    printf("Você quer trocar de porta?! (s/n): ");
    scanf(" %c", &decisao); // "%c" com espaco para evitar problemas

    if (decisao == 's' || decisao == 'S') {
        trcprt = 6 - prtdoparticipante - prtaberta; // Encontra a porta
        prtdoparticipante = trcprt;
        printf("Parabéns! Você agora escolheu a porta %d.\n", prtdoparticipante);
    } else {
        printf("Hmm, você acabou mantendo sua escolha inicial, a porta %d.\n", prtdoparticipante);
    }

    // Mc Ryan Sp revelar se o participante ganhou a pernoite com as do job ou ficou quanquan sem nada!!!
    if (prtdoparticipante == prtcomasdojob) {
        printf("Parabéns! Você ganhou uma pernoite com as do job!!! Apreoveite essa vida rasa hahaha!\n");
    } else {
        printf("Deu bolete hein veinho! Ficou quanquan sem nada!\n");
    }

    return 0;
}
