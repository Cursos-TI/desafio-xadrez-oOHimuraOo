#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//função responsavel por limpar o console. Ela possui um funcionamento levemente diferente a depender se ela foi compilada em windows ou não.
void limpar_console() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

//função responsavel por pausar o programa. Ela possui um funcionamento levemente diferente a depender se ela foi compilada em Windows ou não.
void pausar_programa() {
#if defined(_WIN32) || defined(_WIN64)
    printf("\n");
    system("pause");
    printf("\n");
#else 
    printf("\nPressione ENTER para continuar...\n");
    getchar();
#endif
}

//função reponsavel por inicializar o programa e apresentar as mensagens de boas vindas.
void inicializar_programa() {
    printf("*** Movimento de peças de Xadrez ***\n\n");
    printf("Seja bem vindo a primeira versão do programa de movimento de peças de Xadrez. \n");
    printf("Nessa versão iremos demonstrar como a torre, bispo e rainha se movimentam \n\n");
}

//Função responsavel por simular o movimento da torre. Ela deve receber a quantidade de casas a ser movimentada e a direção para onde ele deverá ir. A direção deve ser um numero inteiro entre 0 e 3, sendo 0 = cima, 1 = direita, 2 = baixo e 3 = esquerda.
void movimentar_torre(int qtd_movimento, int direcao) {
    //variavel a ser incrementada para controle de repetição.
    int i;

    if (direcao == 0) {
        printf("A Torre vai se movimentar %d casas para a Cima!\n", qtd_movimento);
        for (i = 0; i < qtd_movimento; i++) {
            printf("Cima \n");
        }
    } else if (direcao == 1) {
        printf("A Torre vai se movimentar %d casas para a Direita!\n", qtd_movimento);
        for (i = 0; i < qtd_movimento; i++) {
            printf("Direita \n");
        }
    } else if (direcao == 2) {
        printf("A Torre vai se movimentar %d casas para a Baixo!\n", qtd_movimento);
        for (i = 0; i < qtd_movimento; i++) {
            printf("Baixo \n");
        }
    } else {
        printf("A Torre vai se movimentar %d casas para a Esquerda!\n", qtd_movimento);
        for (i = 0; i < qtd_movimento; i++) {
            printf("Esquerda \n");
        }
    }
}

//Função responsavel por simular o movimento do bispo. Ela deve receber a quantidade de casas a ser movimentada e a direção para onde ele deverá ir. A direção deve ser um numero inteiro entre 0 e 3, sendo 0 = diagonal superior esquerda, 1 = diagonal superior direita, 2 = diagonal inferior direita e 3 = diagonal inferior esquerda.
void movimentar_bispo(int qtd_movimento, int direcao) {
    //variavel a ser incrementada para controle de repetição.
    int i = 0;
    
    if (direcao == 0) {
        printf("O Bispo vai se movimentar %d casas para a Diagonal superior esquerda!\n", qtd_movimento);
        while (i < qtd_movimento) {
            printf("Cima, Esquerda \n");
    
            i++;
        }
    } else if (direcao == 1) {
        printf("O Bispo vai se movimentar %d casas para a Diagonal superior direita!\n", qtd_movimento);
        while (i < qtd_movimento) {
            printf("Cima, Direita \n");
    
            i++;
        }
    } else if (direcao == 2) {
        printf("O Bispo vai se movimentar %d casas para a Diagonal inferior direita!\n", qtd_movimento);
        while (i < qtd_movimento) {
            printf("Baixo, Direita \n");
    
            i++;
        }
    } else {
        printf("O Bispo vai se movimentar %d casas para a Diagonal inferior esquerda!\n", qtd_movimento);
        while (i < qtd_movimento) {
            printf("Baixo, Esquerda \n");
    
            i++;
        }
    }
}

//função responsavel pela movimentação da rainha, ela deve receber dois parametros. A quantidade de casas a ser movida, e a direção do movimento. A direção deve ser um numero inteiro entre 0 e 7, onde 0 é igual a cima e 7 é igual a diagonal superior esquerda.
void movimentar_rainha(int qtd_movimento, int direcao) {
    //variavel a ser incrementada para controle de repetição.
    int i = 0;

    switch (direcao)
    {
    case 0:
        printf("A Rainha vai se movimentar %d casas para a Cima!\n", qtd_movimento);
        do
        {
            printf("Cima \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 1:
        printf("A Rainha vai se movimentar %d casas para a Diagonal superior direita!\n", qtd_movimento);
        do
        {
            printf("Cima, Direita \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 2:
        printf("A Rainha vai se movimentar %d casas para a Direita!\n", qtd_movimento);
        do
        {
            printf("Direita \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 3:
        printf("A Rainha vai se movimentar %d casas para a Diagonal inferior direita!\n", qtd_movimento);
        do
        {
            printf("Direita, Baixo \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 4:
        printf("A Rainha vai se movimentar %d casas para a Baixo!\n", qtd_movimento);
        do
        {
            printf("Baixo \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 5:
        printf("A Rainha vai se movimentar %d casas para a Diagonal inferior esquerda!\n", qtd_movimento);
        do
        {
            printf("Baixo, Esquerda \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 6:
        printf("A Rainha vai se movimentar %d casas para a Esquerda!\n", qtd_movimento);
        do
        {
            printf("Esquerda \n");
            i++;
        } while (i < qtd_movimento);
        break;
    case 7:
        printf("A Rainha vai se movimentar %d casas para a Diagonal superior Esquerda!\n", qtd_movimento);
        do
        {
            printf("Esquerda, Cima \n");
            i++;
        } while (i < qtd_movimento);
        break;
    
    default:
        printf("Erro ao reconhecer a direção de movimento. Por favor tente novamente!");
        break;
    }
    
    
}

//Função responsavel por indicar a finalização do programa para o usuario.
void finalizar_programa() {
    printf("Essas foram as movimentações das peças de Xadrez.\n");
}

//função principal reponsavel por chamar as funções auxiliares que fazem o software funcionar.
int main() {
    //chamada da função responsavel por localizar os caracteres do console para o idioma portugues.
    setlocale(LC_ALL, "Portuguese");
    
    inicializar_programa();
    
    movimentar_torre(5, 1);
    pausar_programa();
    
    movimentar_bispo(5, 1);
    pausar_programa();

    movimentar_rainha(8, 6);
    pausar_programa();
    limpar_console();

    finalizar_programa();
    return 0;
}