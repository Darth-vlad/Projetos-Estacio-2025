#include <stdio.h>


#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; 
        }
    }
}

int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
  
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) {
        return 0; 
    }

  
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; 
        }
    }

    
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; 
    }

    return 1; 
}


int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    
    if (linha + TAM_NAVIO > TAM_TABULEIRO) {
        return 0; 
    }

   
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0; 
        }
    }

    
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; 
    }

    return 1; 
}


void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n"); 
    }
}

int main() {
    
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    
    inicializarTabuleiro(tabuleiro);

   
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 1; 
    int linhaNavioVertical = 5, colunaNavioVertical = 6;   

   
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    
    exibirTabuleiro(tabuleiro);

    return 0;
}
// codigo 2 **********************************************************************

#include <stdio.h>
#include <stdlib.h> //p usar fun abs

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            tabuleiro[i][j] = 0;
}


void aplicarForma(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                  int forma[TAM_HABILIDADE][TAM_HABILIDADE],
                  int origemLinha, int origemColuna) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int lin = origemLinha + i - centro;
            int col = origemColuna + j - centro;
            if (lin >= 0 && lin < TAM_TABULEIRO && col >= 0 && col < TAM_TABULEIRO) {
                if (forma[i][j] == 1) {
                    tabuleiro[lin][col] = 3;
                }
            }
        }
    }
}

void construirCone(int forma[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            forma[i][j] = (j >= centro - i && j <= centro + i) ? 1 : 0;
}

void construirCruz(int forma[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            forma[i][j] = (i == centro || j == centro) ? 1 : 0;
}

void construirOctaedro(int forma[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        for (int j = 0; j < TAM_HABILIDADE; j++)
            forma[i][j] = (abs(centro - i) + abs(centro - j) <= centro) ? 1 : 0;
}

void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro 10x10 com figuras formadas por números 3:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    
    aplicarForma(tabuleiro, cone, 2, 2);       // Cone no canto superior esquerdo
    aplicarForma(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarForma(tabuleiro, octaedro, 7, 7);   // Octaedro na parte inferior direita

    exibirTabuleiro(tabuleiro);
    return 0;
}

//* (asterisco) representa a área afetada pela habilidade especial.

//~ =  água

// 3 =  navio




