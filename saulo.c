#include <stdio.h>

// Protótipo da função auxiliar
float getValor(int atributo, unsigned long int pop, float area, float pib, int pontos, float dens, float pibper);

int main() {
    // Dados das cartas
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[50], cidade2[50];
    unsigned long int populacao1, populacao2;
    int pontos1, pontos2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2;
    float pibper1, pibper2;

    int atributo1 = 0, atributo2 = 0;

    // Entrada de dados da carta 1
    printf("Digite as informações da primeira carta:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &estado1);
    printf("Código (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    scanf("%s", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em milhões): ");
    scanf("%f", &pib1);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos1);

    // Entrada de dados da carta 2
    printf("\nDigite as informações da segunda carta:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &estado2);
    printf("Código (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    scanf("%s", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em milhões): ");
    scanf("%f", &pib2);
    printf("Pontos turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos automáticos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibper1 = pib1 * 1000000 / populacao1;
    pibper2 = pib2 * 1000000 / populacao2;

    // Menu para escolha do primeiro atributo
    printf("\n===== ESCOLHA DO PRIMEIRO ATRIBUTO =====\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica (menor vence)\n");
    printf("6 - PIB per capita\n");
    printf("Escolha o primeiro atributo (1 a 6): ");
    scanf("%d", &atributo1);

    // Menu para escolha do segundo atributo (sem repetir o primeiro)
    do {
        printf("\n===== ESCOLHA DO SEGUNDO ATRIBUTO =====\n");
        for (int i = 1; i <= 6; i++) {
            if (i != atributo1) {
                switch(i) {
                    case 1: printf("1 - População\n"); break;
                    case 2: printf("2 - Área\n"); break;
                    case 3: printf("3 - PIB\n"); break;
                    case 4: printf("4 - Pontos turísticos\n"); break;
                    case 5: printf("5 - Densidade demográfica (menor vence)\n"); break;
                    case 6: printf("6 - PIB per capita\n"); break;
                }
            }
        }
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 6);

    // Pegando os valores dos atributos escolhidos para cada carta
    float valor1_carta1 = getValor(atributo1, populacao1, area1, pib1, pontos1, densidade1, pibper1);
    float valor1_carta2 = getValor(atributo1, populacao2, area2, pib2, pontos2, densidade2, pibper2);

    float valor2_carta1 = getValor(atributo2, populacao1, area1, pib1, pontos1, densidade1, pibper1);
    float valor2_carta2 = getValor(atributo2, populacao2, area2, pib2, pontos2, densidade2, pibper2);

    // Exibição dos valores
    printf("\n===== COMPARAÇÃO DAS CARTAS =====\n");
    printf("Cidade 1: %s\n", cidade1);
    printf("Cidade 2: %s\n", cidade2);

    printf("\nAtributo 1: ");
    switch(atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos turísticos\n"); break;
        case 5: printf("Densidade demográfica (menor vence)\n"); break;
        case 6: printf("PIB per capita\n"); break;
    }

    printf("%s: %.2f\n", cidade1, valor1_carta1);
    printf("%s: %.2f\n", cidade2, valor1_carta2);

    printf("\nAtributo 2: ");
    switch(atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos turísticos\n"); break;
        case 5: printf("Densidade demográfica (menor vence)\n"); break;
        case 6: printf("PIB per capita\n"); break;
    }

    printf("%s: %.2f\n", cidade1, valor2_carta1);
    printf("%s: %.2f\n", cidade2, valor2_carta2);

    // Regras de comparação com soma final
    float soma1 = 0, soma2 = 0;

    soma1 += (atributo1 == 5) ? (1000000 - valor1_carta1) : valor1_carta1;
    soma2 += (atributo1 == 5) ? (1000000 - valor1_carta2) : valor1_carta2;

    soma1 += (atributo2 == 5) ? (1000000 - valor2_carta1) : valor2_carta1;
    soma2 += (atributo2 == 5) ? (1000000 - valor2_carta2) : valor2_carta2;

    // Resultado final
    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s - Soma dos atributos: %.2f\n", cidade1, soma1);
    printf("%s - Soma dos atributos: %.2f\n", cidade2, soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s!\n", cidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

// Definição da função auxiliar fora da main
float getValor(int atributo, unsigned long int pop, float area, float pib, int pontos, float dens, float pibper) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return dens;
        case 6: return pibper;
        default: return 0;
    }
}
