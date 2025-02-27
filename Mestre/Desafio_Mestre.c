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

//função responsavel por imprimir uma linha no console que irá separar a informação revelada na tela.
void imprimir_linha(int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("-");
        if (i == tamanho -1) {
            printf("-\n");
        }
    }
}

//função reponsavel por inicializar o programa e apresentar as mensagens de boas vindas.
void inicializar_programa() {
    printf("*** Movimento de peças de Xadrez ***\n\n");
    printf("Seja bem vindo a primeira versão do programa de movimento de peças de Xadrez. \n");
    printf("Nessa versão iremos demonstrar como a torre, bispo e rainha se movimentam \n\n");
}

//Função responsavel por movimentar a torre, ela recebe três paramentros. No primeiro a a quantidade de casas que será andada. No segundo parametro a direção em que a torre ira se mover(0=cima, 1=direita, 2=baixo, 3=esquerda), no terceiro parametro deve ser passado 0 quando quiser que o texto de apresentação seja enviado.
void movimentar_torre(int qtd_movimento, int direcao, int textOn) {
    if (direcao == 0) {
        if (textOn == 0) {
            printf("A Torre vai se movimentar %d casas para a Cima!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Cima \n");
            movimentar_torre(qtd_movimento -1, 0, 1);
        }
    } else if (direcao == 1) {
        if (textOn == 0) {
            printf("A Torre vai se movimentar %d casas para a Direita!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Direita \n");
            movimentar_torre(qtd_movimento -1, 1, 1);
        }
    } else if (direcao == 2) {
        if (textOn == 0) {
            printf("A Torre vai se movimentar %d casas para a Baixo!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Baixo \n");
            movimentar_torre(qtd_movimento - 1, 2, 1);
        }
    } else {
        if (textOn == 0) {
            printf("A Torre vai se movimentar %d casas para a Esquerda!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Esquerda \n");
            movimentar_torre(qtd_movimento - 1, 3, 1);
        }
    }
}

//função responsavel por movimentar o bispo, ela recebe três parametros. No primeiro a quantidade de casas que será andada é passada. No segundo a direção em que o bispo ira se mover(0=diagonal superior esquerda, 1=diagonal superior direita, 2=diagonal inferior direita, 3=diagonal inferior esquerda). o terceiro parametro deverá ser 0 para que o texto de apresentação seja revelado.
void movimentar_bispo(int qtd_movimento, int direcao, int textOn) {
    //variavel a ser incrementada para controle de repetição.
    int i;
    int j;
    if (direcao == 0) {
        if (textOn == 0) {
            printf("O Bispo vai se movimentar %d casas para a Diagonal superior esquerda!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            for (i = 0; i < 1; i++) {
                for (j = 0; j < 1; j++) {
                    printf("Esquerda! \n");
                }
                printf("Cima! \n");    
            }
            movimentar_bispo(qtd_movimento - 1, 0, 1);
        }
    } else if (direcao == 1) {
        if (textOn == 0) {
            printf("O Bispo vai se movimentar %d casas para a Diagonal superior direita!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            for (i = 0; i < 1; i++) {
                for (j = 0; j < 1; j++) {
                    printf("Direita! \n");
                }
                printf("Cima!\n");
            }
            movimentar_bispo(qtd_movimento - 1, 1, 1);
        }
    } else if (direcao == 2) {
        if (textOn == 0) {
            printf("O Bispo vai se movimentar %d casas para a Diagonal inferior direita!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            for (i = 0; i < 1; i++) {
                for (j = 0; j < 1; j++) {
                    printf("Direita! \n");
                }
                printf("Baixo! \n");
            }
            movimentar_bispo(qtd_movimento - 1, 2, 1);
        }
    } else {
        if (textOn == 0) {
            printf("O Bispo vai se movimentar %d casas para a Diagonal inferior esquerda!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            for (i = 0; i < 1; i++) {
                for (j = 0; j < 1; j++) {
                    printf("Esquerda! \n");
                }
                printf("Baixo! \n");
            }
            movimentar_bispo(qtd_movimento - 1, 3, 1);
        }
    }
}

//função responsavel por simular o movimento da rainha. Ela deve receber 4 parametros. No primeiro parametro deve ser a quantidade de casas que a rainha irá se movimentar. No segundo parametro a direção que a rainha ira se movimentar (0=cima, 1=baixo, 2=direita, 3=esquerda). O terceiro parametro deve ser 0 caso queira que o texto de apresentação seja revelado. O quarto parametro deve ser 0 se o movimento não for na diagonal, porem se ele for na diagonal ele precisará ser -1 ou 1 onde -1 simboliza esquerda e 1 direita, e ele só irá funcionar se estiver acompanhado da direção 0 ou 1.
void movimentar_rainha(int qtd_movimento, int direcao, int textOn, int diagonal) {
    switch (direcao)
    {
    case 0:
        if (textOn == 0) {
            printf("A Rainha vai se movimentar %d casas para a Cima!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Cima \n");
            if (diagonal == 0) {
                movimentar_rainha(qtd_movimento - 1, 0, 1, 0);
            } else if (diagonal < 0){
                printf("Esquerda! \n");
                movimentar_rainha(qtd_movimento - 1, 0, 1, -1);
            } else if (diagonal > 0){
                printf("Direita! \n");
                movimentar_rainha(qtd_movimento - 1, 0, 1, 1);
            }
        }
        break;
    case 1:
        if (textOn == 0) {
            printf("A Rainha vai se movimentar %d casas para a Baixo!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Baixo \n");
            if (diagonal == 0) {
                movimentar_rainha(qtd_movimento - 1, 1, 1, 0);
            } else if (diagonal < 0) {
                printf("Esquerda! \n");
                movimentar_rainha(qtd_movimento - 1, 1, 1, -1);
            } else if (diagonal > 0) {
                printf("Direita! \n");
                movimentar_rainha(qtd_movimento - 1, 1, 1, 1);
            }
        }
        break;
    case 2:
        if (textOn == 0) {
            printf("A Rainha vai se movimentar %d casas para a direita!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Direita! \n");
            movimentar_rainha(qtd_movimento - 1, 2, 1, 0);
        }
        break;
    case 3:
        if (textOn == 0) {
            printf("A Rainha vai se movimentar %d casas para a esquerda!\n", qtd_movimento);
        }
        if (qtd_movimento > 0) {
            printf("Esquerda! \n");
            movimentar_rainha(qtd_movimento - 1, 3, 1, 0);
        }
        break;
    default:
        printf("Erro ao reconhecer a direção de movimento. Por favor tente novamente!");
        break;
    }
}

// função responsavel pela movimentação do cavalo.  Ela recebe dois parametros, O primeiro indica a direção no eixo x (horizontal), a segunda indica a direção no eixo y (vertical). Os valores dos parametros devem ir de -2 a 2 (excluindo o 0) e se somar os seus valores absolutos deve dar 3.
void movimentar_cavalo(int direcao_x, int direcao_y) {
    int x, y;

    x = direcao_x;
    y = direcao_y;

    if (direcao_x < 0) {
        x = -direcao_x;
    }

    if (direcao_y < 0) {
        y = -direcao_y;
    }
    
    if (direcao_x >= 0) {
        if (direcao_y >= 0) {
            if (x + y != 3 || x == 0 || y == 0) {
                printf("houve um erro ao realizar o movimento. Tente novamente!\n");
                return;
            } else {
                printf("O Cavalo vai se movimentar %d casa(s) para direita e %d casa(s) para cima \n", x, y);
                int i;
                int j = 0;
                for (i = 0; i < x; i++) {
                    while (j < y)
                    {
                        printf("Cima! \n");
                        j++;
                    }
                    printf("Direita! \n");
                }
            }
        } else {
            if (x + y != 3 || x == 0 || y == 0) {
                printf("houve um erro ao realizar o movimento. Tente novamente!\n");
                return;
            } else {
                printf("O Cavalo vai se movimentar %d casa(s) para direita e %d casa(s) para baixo \n", x, y);
                int i;
                int j = 0;
                for (i = 0; i < x; i++) {
                    while (j < y)
                    {
                        printf("baixo! \n");
                        j++;
                    }
                    printf("Direita! \n");
                }
            }
        }
    } else {
        if (direcao_y >= 0) {
            if (x + y != 3 || x == 0 || y == 0) {
                printf("houve um erro ao realizar o movimento. Tente novamente!\n");
                return;
            } else {
                printf("O Cavalo vai se movimentar %d casa(s) para esquerda e %d casa(s) para cima \n", x, y);
                int i;
                int j = 0;
                for (i = 0; i < x; i++) {
                    while (j < y)
                    {
                        printf("Cima! \n");
                        j++;
                    }
                    printf("Direita! \n");
                }
            }
        } else {
            if (x + y != 3 || x == 0 || y == 0) {
                printf("houve um erro ao realizar o movimento. Tente novamente!\n");
                return;
            } else {
                printf("O Cavalo vai se movimentar %d casa(s) para esquerda e %d casa(s) para baixo \n", x, y);
                int i;
                int j = 0;
                for (i = 0; i < x; i++) {
                    while (j < y)
                    {
                        printf("baixo! \n");
                        j++;
                    }
                    printf("Direita! \n");
                }
            }
        }
    }
}

// função responsavel para indicar a finalização do programa
void finalizar_programa() {
    printf("Essas foram as movimentações das peças de Xadrez.\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    inicializar_programa();
    
    movimentar_torre(5, 1, 0);
    pausar_programa();
    
    movimentar_bispo(5, 1, 0);
    pausar_programa();

    movimentar_rainha(8, 3, 0, 0);
    pausar_programa();

    imprimir_linha(100);

    movimentar_cavalo(-1,-2);
    pausar_programa();

    finalizar_programa();
    return 0;
}
