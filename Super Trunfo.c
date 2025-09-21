#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[50];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
} Carta;

float calcular_densidade_populacional(Carta carta) {
    return carta.populacao / carta.area;
}

float calcular_pib_per_capita(Carta carta) {
    return carta.pib / carta.populacao;
}

void comparar_cartas(Carta carta1, Carta carta2, char atributo) {
    float atributo1, atributo2;

    printf("\nComparação de cartas (Atributo: %c):\n", atributo);

    if (atributo == 'P') {  
        atributo1 = carta1.populacao;
        atributo2 = carta2.populacao;
        printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);
    } else if (atributo == 'A') {  
        atributo1 = carta1.area;
        atributo2 = carta2.area;
        printf("Carta 1 - %s (%s): %.2f km²\n", carta1.cidade, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f km²\n", carta2.cidade, carta2.estado, carta2.area);
    } else if (atributo == 'I') {  
        atributo1 = carta1.pib;
        atributo2 = carta2.pib;
        printf("Carta 1 - %s (%s): %.2f bilhões\n", carta1.cidade, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f bilhões\n", carta2.cidade, carta2.estado, carta2.pib);
    } else if (atributo == 'D') {  
        atributo1 = calcular_densidade_populacional(carta1);
        atributo2 = calcular_densidade_populacional(carta2);
        printf("Carta 1 - %s (%s): %.2f habitantes/km²\n", carta1.cidade, carta1.estado, atributo1);
        printf("Carta 2 - %s (%s): %.2f habitantes/km²\n", carta2.cidade, carta2.estado, atributo2);
    } else if (atributo == 'C') {  
        atributo1 = calcular_pib_per_capita(carta1);
        atributo2 = calcular_pib_per_capita(carta2);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, atributo1);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, atributo2);
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    
    if (atributo == 'D') {  
        if (atributo1 < atributo2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (atributo1 > atributo2) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {  
        if (atributo1 > atributo2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (atributo1 < atributo2) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
}

int main() {
    Carta carta1, carta2;

    // Carta 1#
    printf("Cadastro da Carta 1:\n");
    printf("Digite o nome do estado: ");
    scanf(" %[^\n]", carta1.estado);
    printf("Digite o código da carta: ");
    scanf(" %[^\n]", carta1.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade);
    printf("Digite a população da cidade: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);

    // Carta 2#
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o nome do estado: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Digite o código da carta: ");
    scanf(" %[^\n]", carta2.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade);
    printf("Digite a população da cidade: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);

    // Adicionei uma carta com nome da minha cidade só para testar
    if (strcmp(carta1.cidade, "Imperatriz") != 0 && strcmp(carta2.cidade, "Imperatriz") != 0) {
        printf("\nNota: A cidade Imperatriz não foi incluída. Para incluir, altere uma das cidades para Imperatriz.\n");
    }

    // Adicionei uma opção para comparar com qual atributo o usuáiro vai querer
    char atributo_comparacao;
    printf("\nEscolha o atributo para comparação (P = População, A = Área, I = PIB, D = Densidade Populacional, C = PIB per capita): ");
    scanf(" %c", &atributo_comparacao);
    
    comparar_cartas(carta1, carta2, atributo_comparacao);

    return 0;
}
