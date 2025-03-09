#include <stdio.h>
#include <stdbool.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Repositório do projeto oficial: https://github.com/Cursos-TI/desafio-l-gica-super-trunfo-cristianojcruzzz/tree/main

void generateTitle()
{
    // ASCI ART GERADA EM https://patorjk.com/software/taag/#p=display&f=Rectangles&t=Super%20Trunfo
    printf("\n");
    printf(" _____                    _____             ___     \n");
    printf("|   __|_ _ ___ ___ ___   |_   _|___ _ _ ___|  _|___ \n");
    printf("|__   | | | . | -_|  _|    | | |  _| | |   |  _| . |\n");
    printf("|_____|___|  _|___|_|      |_| |_| |___|_|_|_| |___|\n");
    printf("          |_|                                       \n");
    printf("\n");
}

int generateMenu()
{
    int escolha;

    do
    {
        printf("\n**** Escolha uma propriedade para comparar as cartas ****\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. Densidade Populacional\n");
        printf("4. PIB\n");
        printf("5. PIB Per Capita\n");
        printf("6. Pontos Turísticos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &escolha) != 1 || escolha < 0 || escolha > 6)
        {
            // Limpa o buffer, caso seja uma entrada inválida (abc, 12abc)
            while (getchar() != '\n')
                ;

            printf("Opção inválida! Tente novamente.\n");
        }
        else
        {
            // Sai do loop se a entrada for válida
            break;
        }

    } while (1);

    return escolha;
}

int main()
{
    /**
     * Definição de variáveis utilizadas no projeto
     */
    float cidade_pontos_turisticos1, cidade_pontos_turisticos2;

    float cidade_pib1, cidade_pib2;

    float cidade_area1, cidade_area2;
    float cidade_populacao1, cidade_populacao2;
    char cidade_nome1[80], cidade_nome2[80];

    char estado_sigla1[3], estado_sigla2[3];

    char carta_codigo1[4], carta_codigo2[4]; // Código da carta (A01, A02, B01, B02)

    float pib_per_capta1, pib_per_capta2;
    float densidade_populacional1, densidade_populacional2;

    /**
     * Gera uma mensagem de bem vindo
     */
    generateTitle();

    /**
     * Solicita os dados ao usuário
     */
    printf("**** PRIMEIRA CARTA ****\n\n");

    printf("Informe o nome da cidade (Ex: Florianópolis): ");
    scanf(" %[^\n]", cidade_nome1);

    printf("Informe a sigla do estado de '%s' (Ex: SC): ", cidade_nome1);
    scanf("%2s", estado_sigla1);

    printf("Informe a população de '%s': ", cidade_nome1);
    scanf(" %f", &cidade_populacao1);

    printf("Informe o PIB de '%s': ", cidade_nome1);
    scanf(" %f", &cidade_pib1);

    printf("Informe a área em km² de '%s': ", cidade_nome1);
    scanf(" %f", &cidade_area1);

    printf("Informe a quantidade de pontos turísticos de '%s': ", cidade_nome1);
    scanf(" %f", &cidade_pontos_turisticos1);

    printf("Por fim, o código da carta (Ex: A01, A02): ");
    scanf("%3s", carta_codigo1);
    getchar();

    printf("** Ótimo, você cadastrou sua PRIMEIRA carta com sucesso **\n\n");

    //
    //

    printf("**** SEGUNDA CARTA ****\n\n");

    printf("Informe o nome da cidade (Ex: Florianópolis): ");
    scanf(" %[^\n]", cidade_nome2);

    printf("Informe a sigla do estado de '%s' (Ex: SC): ", cidade_nome2);
    scanf("%2s", estado_sigla2);

    printf("Informe a população de '%s': ", cidade_nome2);
    scanf(" %f", &cidade_populacao2);

    printf("Informe o PIB de '%s': ", cidade_nome2);
    scanf(" %f", &cidade_pib2);

    printf("Informe a área em km² de '%s': ", cidade_nome2);
    scanf(" %f", &cidade_area2);

    printf("Informe a quantidade de pontos turísticos de '%s': ", cidade_nome2);
    scanf(" %f", &cidade_pontos_turisticos2);

    printf("Por fim, o código da carta (Ex: A01, A02): ");
    scanf("%3s", carta_codigo2);
    getchar();

    printf("** Ótimo, você cadastrou sua SEGUNDA carta com sucesso **\n\n");

    /**
     * Calcula o pib per capta
     */
    pib_per_capta1 = (cidade_pib1 / cidade_populacao1);
    pib_per_capta2 = (cidade_pib2 / cidade_populacao2);

    /**
     * Calcula a densidade populacional
     */
    densidade_populacional1 = (cidade_populacao1 / cidade_area1);
    densidade_populacional2 = (cidade_populacao2 / cidade_area2);

    /**
     * Gera o menu e aguarda a resposta do usuário
     */
    int escolha = generateMenu();

    /**
     * Identifica a escolha do usuário
     */
    switch (escolha)
    {

    case 1: // População
    {
        printf("CARTA 1 - Código: %s | Nome: %s | Estado: %s | População: %.0f\n", carta_codigo1, cidade_nome1, estado_sigla1, cidade_populacao1);
        printf("CARTA 2 - Código: %s | Nome: %s | Estado: %s | População: %.0f\n", carta_codigo2, cidade_nome2, estado_sigla2, cidade_populacao2);

        if (cidade_populacao1 == cidade_populacao2)
        {
            printf("Empate na comparação de População!\n");
            break;
        }

        printf("A CARTA %d venceu a comparação de População!\n", cidade_populacao1 > cidade_populacao2 ? 1 : 2);
        break;
    }

    case 2: // Área
    {
        printf("CARTA 1 - Código: %s | Nome: %s | Estado: %s | Área: %.4f\n", carta_codigo1, cidade_nome1, estado_sigla1, cidade_area1);
        printf("CARTA 2 - Código: %s | Nome: %s | Estado: %s | Área: %.4f\n", carta_codigo2, cidade_nome2, estado_sigla2, cidade_area2);

        if (cidade_area1 == cidade_area2)
        {
            printf("Empate na comparação de Área!\n");
            break;
        }

        printf("A CARTA %d venceu a comparação de Área!\n", cidade_area1 > cidade_area2 ? 1 : 2);
        break;
    }

    case 3: // Densidade Populacional
    {
        printf("CARTA 1 - Código: %s | Nome: %s | Estado: %s | Densidade Populacional: %.0f\n", carta_codigo1, cidade_nome1, estado_sigla1, densidade_populacional1);
        printf("CARTA 2 - Código: %s | Nome: %s | Estado: %s | Densidade Populacional: %.0f\n", carta_codigo2, cidade_nome2, estado_sigla2, densidade_populacional2);

        if (densidade_populacional1 == densidade_populacional2)
        {
            printf("Empate na comparação de Densidade Populacional!\n");
            break;
        }

        printf("A CARTA %d venceu a comparação de Densidade Populacional!\n", densidade_populacional1 < densidade_populacional2 ? 1 : 2);
        break;
    }

    case 4: // PIB
    {
        printf("CARTA 1 - Código: %s | Nome: %s | Estado: %s | PIB: %.8f\n", carta_codigo1, cidade_nome1, estado_sigla1, cidade_pib1);
        printf("CARTA 2 - Código: %s | Nome: %s | Estado: %s | PIB: %.8f\n", carta_codigo2, cidade_nome2, estado_sigla2, cidade_pib2);

        if (cidade_pib1 == cidade_pib2)
        {
            printf("Empate na comparação de PIB!\n");
            break;
        }

        printf("A CARTA %d venceu a comparação de PIB!\n", cidade_pib1 > cidade_pib2 ? 1 : 2);
        break;
    }

    case 5: // PIB Per Capita
    {
        printf("CARTA 1 - Código: %s | Nome: %s | Estado: %s | PIB per Capta: %.8f\n", carta_codigo1, cidade_nome1, estado_sigla1, pib_per_capta1);
        printf("CARTA 2 - Código: %s | Nome: %s | Estado: %s | PIB per Capta: %.8f\n", carta_codigo2, cidade_nome2, estado_sigla2, pib_per_capta2);

        if (pib_per_capta1 == pib_per_capta2)
        {
            printf("Empate na comparação de PIB per Capta!\n");
            break;
        }

        printf("A CARTA %d venceu a comparação de PIB per Capta!\n", pib_per_capta1 > pib_per_capta2 ? 1 : 2);
        break;
    }

    case 6: // Pontos Turísticos
    {
        printf("CARTA 1 - Código: %s | Nome: %s | Estado: %s | Pontos turísticos: %.0f\n", carta_codigo1, cidade_nome1, estado_sigla1, cidade_pontos_turisticos1);
        printf("CARTA 2 - Código: %s | Nome: %s | Estado: %s | Pontos turísticos: %.0f\n", carta_codigo2, cidade_nome2, estado_sigla2, cidade_pontos_turisticos2);

        if (cidade_pontos_turisticos1 == cidade_pontos_turisticos2)
        {
            printf("Empate na comparação de Pontos turísticos!\n");
            break;
        }

        printf("A CARTA %d venceu a comparação de Pontos turísticos!\n", cidade_pontos_turisticos1 > cidade_pontos_turisticos2 ? 1 : 2);
        break;
    }

    case 0:
        printf("Saindo do jogo...\n");
        break;
    }
    
    return 0;
}
