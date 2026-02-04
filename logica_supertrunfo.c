#include <stdio.h>

int main() {
    // Mensagem inicial
    printf("===== SUPER TRUNFO - CIDADES =====\n");
    printf("Comparacao entre duas cartas (SP x RJ)\n");
    printf("Escolha 2 atributos diferentes. Quem tiver a maior soma vence!\n");
    printf("----------------------------------\n\n");

    // Dados das cartas (fixos)
    char nome_cidade1[20] = "SP";
    char nome_cidade2[20] = "RJ";

    unsigned long populacao1 = 12325000UL;
    unsigned long populacao2 = 6748000UL;

    double area1 = 1200.25;
    double area2 = 1521.15;

    double pib1 = 699800000000.0;
    double pib2 = 300500000000.0;

    int pontos_turisticos1 = 12;
    int pontos_turisticos2 = 20;

    // Cálculo de atributos derivados
    double densidade_populacional_1 = (double)populacao1 / area1;
    double densidade_populacional_2 = (double)populacao2 / area2;

    // Variáveis para escolha de atributos
    int primeiroAtributo = 0;
    int segundoAtributo = 0;

    // Variáveis que guardarão os valores escolhidos para cada carta
    double valor1_carta1 = 0.0, valor1_carta2 = 0.0;
    double valor2_carta1 = 0.0, valor2_carta2 = 0.0;

    // Variáveis que armazenam o "resultado booleano" da comparação de cada atributo
    // (1 = carta1 venceu o atributo, 0 = carta2 venceu ou empate tratado depois)
    int resultado1 = 0, resultado2 = 0;

    // Menu - primeiro atributo
    printf("Escolha o primeiro atributo para comparacao:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de pontos turisticos\n");
    printf("5. Densidade Demografica (menor vence)\n");
    printf("Escolha: ");
    if (scanf("%d", &primeiroAtributo) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    switch (primeiroAtributo) {
        case 1: // População
            valor1_carta1 = (double)populacao1;
            valor1_carta2 = (double)populacao2;
            resultado1 = populacao1 > populacao2 ? 1 : 0;
            break;
        case 2: // Área
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            resultado1 = area1 > area2 ? 1 : 0;
            break;
        case 3: // PIB
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            resultado1 = pib1 > pib2 ? 1 : 0;
            break;
        case 4: // Pontos turísticos
            valor1_carta1 = (double)pontos_turisticos1;
            valor1_carta2 = (double)pontos_turisticos2;
            resultado1 = pontos_turisticos1 > pontos_turisticos2 ? 1 : 0;
            break;
        case 5: // Densidade (menor vence)
            valor1_carta1 = densidade_populacional_1;
            valor1_carta2 = densidade_populacional_2;
            resultado1 = densidade_populacional_1 < densidade_populacional_2 ? 1 : 0;
            break;
        default:
            printf("Opcao invalida para o primeiro atributo.\n");
            return 1;
    }

    // Menu - segundo atributo
    printf("\nEscolha o segundo atributo para comparacao (diferente do primeiro):\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Numero de pontos turisticos\n");
    printf("5. Densidade Demografica (menor vence)\n");
    printf("Escolha: ");
    if (scanf("%d", &segundoAtributo) != 1) {
        printf("Entrada invalida.\n");
        return 1;
    }

    // Impedir escolher o mesmo atributo duas vezes
    if (segundoAtributo == primeiroAtributo) {
        printf("Voce nao pode escolher o mesmo atributo duas vezes.\n");
        return 1;
    }

    switch (segundoAtributo) {
        case 1: // População
            valor2_carta1 = (double)populacao1;
            valor2_carta2 = (double)populacao2;
            resultado2 = populacao1 > populacao2 ? 1 : 0;
            break;
        case 2: // Área
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            resultado2 = area1 > area2 ? 1 : 0;
            break;
        case 3: // PIB
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            resultado2 = pib1 > pib2 ? 1 : 0;
            break;
        case 4: // Pontos turísticos
            valor2_carta1 = (double)pontos_turisticos1;
            valor2_carta2 = (double)pontos_turisticos2;
            resultado2 = pontos_turisticos1 > pontos_turisticos2 ? 1 : 0;
            break;
        case 5: // Densidade (menor vence)
            valor2_carta1 = densidade_populacional_1;
            valor2_carta2 = densidade_populacional_2;
            resultado2 = densidade_populacional_1 < densidade_populacional_2 ? 1 : 0;
            break;
        default:
            printf("Opcao invalida para o segundo atributo.\n");
            return 1;
    }

    // Cálculo das somas (critério final de vitória)
    double soma1 = valor1_carta1 + valor2_carta1;
    double soma2 = valor1_carta2 + valor2_carta2;

    // Exibição organizada dos resultados
    printf("\n===== Resultado Final =====\n");
    printf("Carta 1: %s\n", nome_cidade1);
    printf("Carta 2: %s\n\n", nome_cidade2);

    // Primeiro atributo: nome, valores e quem venceu
    if (primeiroAtributo == 1) {
        printf("1º Atributo: Populacao\n");
        printf("%s: %.0f | %s: %.0f", nome_cidade1, valor1_carta1, nome_cidade2, valor1_carta2);
        if (valor1_carta1 > valor1_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor1_carta2 > valor1_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (primeiroAtributo == 2) {
        printf("1º Atributo: Area\n");
        printf("%s: %.2f | %s: %.2f", nome_cidade1, valor1_carta1, nome_cidade2, valor1_carta2);
        if (valor1_carta1 > valor1_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor1_carta2 > valor1_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (primeiroAtributo == 3) {
        printf("1º Atributo: PIB\n");
        printf("%s: %.0f | %s: %.0f", nome_cidade1, valor1_carta1, nome_cidade2, valor1_carta2);
        if (valor1_carta1 > valor1_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor1_carta2 > valor1_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (primeiroAtributo == 4) {
        printf("1º Atributo: Pontos Turisticos\n");
        printf("%s: %.0f | %s: %.0f", nome_cidade1, valor1_carta1, nome_cidade2, valor1_carta2);
        if (valor1_carta1 > valor1_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor1_carta2 > valor1_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (primeiroAtributo == 5) {
        printf("1º Atributo: Densidade Demografica (menor vence)\n");
        printf("%s: %.2f | %s: %.2f", nome_cidade1, valor1_carta1, nome_cidade2, valor1_carta2);
        if (valor1_carta1 < valor1_carta2) { // menor vence
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor1_carta2 < valor1_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    }

    // Segundo atributo: nome, valores e quem venceu
    if (segundoAtributo == 1) {
        printf("2º Atributo: Populacao\n");
        printf("%s: %.0f | %s: %.0f", nome_cidade1, valor2_carta1, nome_cidade2, valor2_carta2);
        if (valor2_carta1 > valor2_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor2_carta2 > valor2_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (segundoAtributo == 2) {
        printf("2º Atributo: Area\n");
        printf("%s: %.2f | %s: %.2f", nome_cidade1, valor2_carta1, nome_cidade2, valor2_carta2);
        if (valor2_carta1 > valor2_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor2_carta2 > valor2_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (segundoAtributo == 3) {
        printf("2º Atributo: PIB\n");
        printf("%s: %.0f | %s: %.0f", nome_cidade1, valor2_carta1, nome_cidade2, valor2_carta2);
        if (valor2_carta1 > valor2_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor2_carta2 > valor2_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (segundoAtributo == 4) {
        printf("2º Atributo: Pontos Turisticos\n");
        printf("%s: %.0f | %s: %.0f", nome_cidade1, valor2_carta1, nome_cidade2, valor2_carta2);
        if (valor2_carta1 > valor2_carta2) {
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor2_carta2 > valor2_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    } else if (segundoAtributo == 5) {
        printf("2º Atributo: Densidade Demografica (menor vence)\n");
        printf("%s: %.2f | %s: %.2f", nome_cidade1, valor2_carta1, nome_cidade2, valor2_carta2);
        if (valor2_carta1 < valor2_carta2) { // menor vence
            printf(" -> %s venceu\n\n", nome_cidade1);
        } else if (valor2_carta2 < valor2_carta1) {
            printf(" -> %s venceu\n\n", nome_cidade2);
        } else {
            printf(" -> Empate\n\n");
        }
    }

    // Soma final e declaração do vencedor da rodada
    printf("Soma dos atributos:\n");
    // Em impressao, dependendo do tipo de atributo, escolhi formatacoes para ficar legivel:
    // usamos %.0f para valores inteiros muito grandes (populacao/PIB), e %.2f para decimais.
    printf("%s: %.2f\n", nome_cidade1, soma1);
    printf("%s: %.2f\n\n", nome_cidade2, soma2);

    if (soma1 > soma2) {
        printf("=> Vencedor da rodada: %s\n", nome_cidade1);
    } else if (soma2 > soma1) {
        printf("=> Vencedor da rodada: %s\n", nome_cidade2);
    } else {
        printf("=> Empate!\n");
    }

    printf("==============================\n");

    return 0;
}
