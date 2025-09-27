#include <stdio.h>

void movimento_torre() {
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }
}

void movimento_bispo() {
    for (int i = 0; i < 5; i++) {
        printf("Cima\n");
        printf("Direita\n"); 
    }
}

void movimento_rainha() {
    for (int i = 0; i < 8; i++) {
        printf("Esquerda\n"); 
    }
}

void movimento_cavalo() {
    
    for (int i = 0; i < 2; i++) {
        printf("Baixo\n");
    }
    printf("Esquerda\n");
}

int main() {

    printf("Movimento da Torre:\n");
    movimento_torre();
    printf("\n");

    printf("Movimento do Bispo:\n");
    movimento_bispo();
    printf("\n");

    printf("Movimento da Rainha:\n");
    movimento_rainha();
    printf("\n");

    printf("Movimento do Cavalo:\n");
    movimento_cavalo();
    printf("\n");

    return 0;
}
