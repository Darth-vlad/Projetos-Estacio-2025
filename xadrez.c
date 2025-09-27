// fiz os dois códigos neste arquivo, uma abaixo do outro, pois não consgui criar uma pasta para ambos ficarem separados
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

// Estou adicionando o outro codigo abaixo, não consegui criar uma respositorio para adicionar os dois codigos separados


#include <stdio.h>


void movimento_torre(int casas) {
    if (casas <= 0) return;  
    printf("Direita\n");
    movimento_torre(casas - 1);  
}

void movimento_bispo(int casas) {
    if (casas <= 0) return;  
    printf("Cima\n");
    printf("Direita\n");
    movimento_bispo(casas - 1);  
}


void movimento_rainha(int casas) {
    if (casas <= 0) return;  
    printf("Esquerda\n");
    movimento_rainha(casas - 1);  
}

void movimento_cavalo() {
   
    for (int i = 0; i < 2; i++) {  
        printf("Baixo\n");
    }

    for (int j = 0; j < 1; j++) {  
        printf("Esquerda\n");
    }
}

int main() {
    
    printf("Movimento da Torre:\n");
    movimento_torre(5);
    printf("\n");

    printf("Movimento do Bispo:\n");
    movimento_bispo(5);
    printf("\n");

    printf("Movimento da Rainha:\n");
    movimento_rainha(8);
    printf("\n");

    printf("Movimento do Cavalo:\n");
    movimento_cavalo();
    printf("\n");

    return 0;
}
