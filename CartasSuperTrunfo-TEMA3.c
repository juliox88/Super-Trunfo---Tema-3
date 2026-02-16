#include <stdio.h>

int main() {
    // Definição das variáveis de entrada
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2, pib_per_capita1, pib_per_capita2;

    // Entrada de Dados: Carta 1
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): "); scanf(" %c", &estado1);
    printf("Código da Carta: "); scanf("%s", codigo1);
    printf("Nome da Cidade: "); scanf(" %[^\n]", cidade1);
    printf("População: "); scanf("%d", &populacao1);
    printf("Área (em km²): "); scanf("%f", &area1);
    printf("PIB (em bilhões): "); scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: "); scanf("%d", &pontos_turisticos1);

    // Entrada de Dados: Carta 2
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): "); scanf(" %c", &estado2);
    printf("Código da Carta: "); scanf("%s", codigo2);
    printf("Nome da Cidade: "); scanf(" %[^\n]", cidade2);
    printf("População: "); scanf("%d", &populacao2);
    printf("Área (em km²): "); scanf("%f", &area2);
    printf("PIB (em bilhões): "); scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: "); scanf("%d", &pontos_turisticos2);

    // Cálculos Automáticos
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0) / (float)populacao1;
    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0) / (float)populacao2;

    // ==========================================
    // VARIÁVEIS PARA A BATALHA DINÂMICA
    int opcao1, opcao2;
    float val1_carta1, val1_carta2;
    float val2_carta1, val2_carta2;
    char *nome_attr1 = "";
    char *nome_attr2 = "";

    // MENU 1 - ESCOLHA DO PRIMEIRO ATRIBUTO
    do {
        printf("\n=====================================\n");
        printf("   ESCOLHA O 1º ATRIBUTO DE BATALHA  \n");
        printf("=====================================\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("6 - PIB per Capita\n");
        printf("Opção: ");
        scanf("%d", &opcao1);

        switch (opcao1) {
            case 1: val1_carta1 = (float)populacao1; val1_carta2 = (float)populacao2; nome_attr1 = "População"; break;
            case 2: val1_carta1 = area1; val1_carta2 = area2; nome_attr1 = "Área"; break;
            case 3: val1_carta1 = pib1; val1_carta2 = pib2; nome_attr1 = "PIB"; break;
            case 4: val1_carta1 = (float)pontos_turisticos1; val1_carta2 = (float)pontos_turisticos2; nome_attr1 = "Pontos Turísticos"; break;
            case 5: val1_carta1 = densidade1; val1_carta2 = densidade2; nome_attr1 = "Densidade Demográfica"; break;
            case 6: val1_carta1 = pib_per_capita1; val1_carta2 = pib_per_capita2; nome_attr1 = "PIB per Capita"; break;
            default: printf("[!] Opção inválida. Tente novamente.\n");
        }
    } while (opcao1 < 1 || opcao1 > 6);

    // MENU 2 - ESCOLHA DO SEGUNDO ATRIBUTO (DINÂMICO)
    do {
        printf("\n=====================================\n");
        printf("   ESCOLHA O 2º ATRIBUTO DE BATALHA  \n");
        printf("=====================================\n");
        if (opcao1 != 1) printf("1 - População\n");
        if (opcao1 != 2) printf("2 - Área\n");
        if (opcao1 != 3) printf("3 - PIB\n");
        if (opcao1 != 4) printf("4 - Pontos Turísticos\n");
        if (opcao1 != 5) printf("5 - Densidade Demográfica\n");
        if (opcao1 != 6) printf("6 - PIB per Capita\n");
        printf("Opção: ");
        scanf("%d", &opcao2);

        if (opcao2 == opcao1) {
            printf("[!] Você já escolheu '%s'. Escolha um atributo diferente!\n", nome_attr1);
            continue;
        }

        switch (opcao2) {
            case 1: val2_carta1 = (float)populacao1; val2_carta2 = (float)populacao2; nome_attr2 = "População"; break;
            case 2: val2_carta1 = area1; val2_carta2 = area2; nome_attr2 = "Área"; break;
            case 3: val2_carta1 = pib1; val2_carta2 = pib2; nome_attr2 = "PIB"; break;
            case 4: val2_carta1 = (float)pontos_turisticos1; val2_carta2 = (float)pontos_turisticos2; nome_attr2 = "Pontos Turísticos"; break;
            case 5: val2_carta1 = densidade1; val2_carta2 = densidade2; nome_attr2 = "Densidade Demográfica"; break;
            case 6: val2_carta1 = pib_per_capita1; val2_carta2 = pib_per_capita2; nome_attr2 = "PIB per Capita"; break;
            default: printf("[!] Opção inválida. Tente novamente.\n");
        }
    } while (opcao2 < 1 || opcao2 > 6 || opcao2 == opcao1);

    // Cálculo da soma dos atributos escolhidos
    float soma_carta1 = val1_carta1 + val2_carta1;
    float soma_carta2 = val1_carta2 + val2_carta2;

    int venceu_attr1_c1 = (opcao1 == 5) ? (val1_carta1 < val1_carta2) : (val1_carta1 > val1_carta2);
    int venceu_attr2_c1 = (opcao2 == 5) ? (val2_carta1 < val2_carta2) : (val2_carta1 > val2_carta2);

    // ==========================================
    // EXIBIÇÃO DOS RESULTADOS
    printf("\n#####################################\n");
    printf("        RESULTADO DA BATALHA         \n");
    printf("#####################################\n\n");
    
    printf("Países na disputa: %s vs %s\n\n", cidade1, cidade2);

    // Exibe o Atributo 1 e seu vencedor
    printf("-> Atributo 1: %s\n", nome_attr1);
    printf("   %s: %.2f\n", cidade1, val1_carta1);
    printf("   %s: %.2f\n", cidade2, val1_carta2);
    if (val1_carta1 == val1_carta2) {
        printf("   (Empate no Atributo 1!)\n\n");
    } else {
        printf("   (Vencedor do Atributo 1: %s)\n\n", venceu_attr1_c1 ? cidade1 : cidade2);
    }

    // Exibe o Atributo 2 e seu vencedor
    printf("-> Atributo 2: %s\n", nome_attr2);
    printf("   %s: %.2f\n", cidade1, val2_carta1);
    printf("   %s: %.2f\n", cidade2, val2_carta2);
    if (val2_carta1 == val2_carta2) {
        printf("   (Empate no Atributo 2!)\n\n");
    } else {
        printf("   (Vencedor do Atributo 2: %s)\n\n", venceu_attr2_c1 ? cidade1 : cidade2);
    }

    // Exibe a Soma e o Vencedor Final
    printf("=====================================\n");
    printf("SOMA FINAL DOS ATRIBUTOS (%s + %s):\n", nome_attr1, nome_attr2);
    printf("%s: %.2f\n", cidade1, soma_carta1);
    printf("%s: %.2f\n", cidade2, soma_carta2);
    printf("-------------------------------------\n");

    if (soma_carta1 > soma_carta2) {
        printf(" VENCEDOR GERAL: Carta 1 (%s)!\n", cidade1);
    } else if (soma_carta2 > soma_carta1) {
        printf(" VENCEDOR GERAL: Carta 2 (%s)!\n", cidade2);
    } else {
        printf(" RESULTADO GERAL: Empate!\n");
    }
    printf("=====================================\n");

    return 0;
}