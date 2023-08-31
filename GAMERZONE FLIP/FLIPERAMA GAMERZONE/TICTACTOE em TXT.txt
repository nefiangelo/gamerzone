//BIBLIOTECAS
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//DEFINES PARA O CODIGO FICAR MAIS LIMPO
#define MAXCOL 20
#define MAXLIN 5
#define PADRAO "\033[0m"
#define BRANCO "\033[38;5;15m"
#define PRETO "\033[38;5;232m"
#define VERDE "\033[48;5;22m"
#define FUNDOAMARELO "\033[48;5;11m"
#define PADRAO "\033[0m"
#define CINZA "\033[38;5;240m"
#define AMARELO "\033[48;5;214m"
#define TEXTOAMARELO "\033[38;5;214m"
#define TEXTOAZUL "\033[38;5;12m"
#define TEXTOVERDE "\033[38;5;76m"

//UMA VARIAVEL GLOBAL
int jogando = 1;
int numerojogadores = 0;
int sair;

//MATRIZ DO JOGO QUE VAI SER EXIBIDA
char jogodavelha[MAXLIN][MAXCOL] = {
    {'1','|','2','|','3'},
    {'-','-','-','-','-'},
    {'4','|','5','|','6'},
    {'-','-','-','-','-'},
    {'7','|','8','|','9'}
};


//A SEGUIR S�O FUN��ES QUE USAREMOS NO CODIGO INTEIRO


//A FUN��O DE EXIBIR A MATRIZ MESMO
void exibmatriz(char matriz[][MAXCOL], int lin, int col) {

	int i,j;

    for (i = 0; i < lin; i++) {
        printf("\t\t");
        for (j = 0; j < col; j++) {

            if(matriz[i][j] >= '1' && matriz[i][j] <= '9'){
                printf("%s%c%s",CINZA, matriz[i][j], PADRAO);
            } else {
                printf("%s%c%s", BRANCO, matriz[i][j], PADRAO);
            };
            
        };
        printf("\n");
        
    }
}


//FAZ A JOGADA DO PLAYER NO LOCAL QUE ELE QUER
int jogada(char opc, char player){

    getchar();
    system("cls");
    printf("\n\n                \033[38;5;240mdigite \033[38;5;12mS\033[38;5;240m para ir para o \033[38;5;12mMENU\033[0m  \n");
    printf("\n%s%s       ===== TIC TAC TOE =====     %s", AMARELO, PRETO, PADRAO);
    printf("\n\n");
    exibmatriz(jogodavelha, MAXLIN, MAXCOL);

    printf("\n\n%s%s ESCOLHA ONDE QUER FAZER SUA JOGADA:%s ", AMARELO, PRETO, PADRAO);
    scanf("%c", &opc);

    switch(opc){
        case '1':

            if(jogodavelha[0][0] == '1'){
                jogodavelha[0][0] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '2':

            if(jogodavelha[0][2] == '2'){
                jogodavelha[0][2] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '3':

            if(jogodavelha[0][4] == '3'){
                jogodavelha[0][4] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '4':

            if(jogodavelha[2][0] == '4'){
                jogodavelha[2][0] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '5':

            if(jogodavelha[2][2] == '5'){
                jogodavelha[2][2] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '6':

        if(jogodavelha[2][4] == '6'){
                jogodavelha[2][4] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '7':

            if(jogodavelha[4][0] == '7'){
                jogodavelha[4][0] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '8':

            if(jogodavelha[4][2] == '8'){
                jogodavelha[4][2] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case '9':

            if(jogodavelha[4][4] == '9'){
                jogodavelha[4][4] = player;
            } else {
                printf("\n\nLUGAR JA OCUPADO!\n\n");
                system("pause");
                return 1;
            }

        break;
        case 's':
        case 'S':
            sair = 1;
            break;

        default:
            return 1;

    };

    return 0;
};


//APENAS VERIFICA SE AINDA H� LOCAL PARA JOGAR
int verifjogo(char matriz[][MAXCOL]){
	
	int i,j;

    for(i = 0; i < MAXLIN; i++){
        for(j = 0; j < MAXCOL; j++){

            if(matriz[i][j] >= '1' && matriz[i][j] <= '9'){
                return 0;
            }

        }
    }

    return 1;

}

//POSSIBILIDADES DE VIT�RIA QUE FUNCIONA PARA O PLAYER E IA AO MESMO TEMPO
int verifvitoria(){
    if (jogodavelha[0][0] == jogodavelha[0][2] && jogodavelha[0][0] == jogodavelha[0][4]){
        return 1;
    } else if (jogodavelha[2][0] == jogodavelha[2][2] && jogodavelha[2][0] == jogodavelha[2][4]){
        return 1;
    } else if (jogodavelha[4][0] == jogodavelha[4][2] && jogodavelha[4][0] == jogodavelha[4][4]){
        return 1;
    } else if (jogodavelha[0][0] == jogodavelha[2][0] && jogodavelha[0][0] == jogodavelha[4][0]){
        return 1;
    } else if (jogodavelha[0][2] == jogodavelha[2][2] && jogodavelha[0][2] == jogodavelha[4][2]){
        return 1;
    } else if (jogodavelha[0][4] == jogodavelha[2][4] && jogodavelha[0][4] == jogodavelha[4][4]){
        return 1;
    } else if (jogodavelha[0][0] == jogodavelha[2][2] && jogodavelha[0][0] == jogodavelha[4][4]){
        return 1;
    } else if (jogodavelha[0][4] == jogodavelha[2][2] && jogodavelha[0][4] == jogodavelha[4][0]){
        return 1;
    } else {
        return 0;
    }


}


//REDEFINE MATRIZ PARA RAIZ
void limparmatriz(){
    jogodavelha[0][0] = '1';
        jogodavelha[0][2] = '2';
        jogodavelha[0][4] = '3';
        jogodavelha[2][0] = '4';
        jogodavelha[2][2] = '5';
        jogodavelha[2][4] = '6';
        jogodavelha[4][0] = '7';
        jogodavelha[4][2] = '8';
        jogodavelha[4][4] = '9';
}


typedef struct {
    
    char nome[50];
    double tempo;
    int totalscore;

} jogador;


void ordenarrankingttt(jogador rankingttt[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMinimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (rankingttt[j].tempo < rankingttt[indiceMinimo].tempo) {
                indiceMinimo = j;
            }
        }
        if (indiceMinimo != i) {
            jogador temp = rankingttt[i];
            rankingttt[i] = rankingttt[indiceMinimo];
            rankingttt[indiceMinimo] = temp;
        }
    }
}

jogador rankingttt[10];

//O JOGO EM SI
int TICTACTOE() { //INICIO DO CODIGO MAIN
    setlocale(LC_ALL, "Portuguese");

    char opc, player, CPU;
    int contador = 0, vitoria = 0, ultimajogada = 0, jogadavalida = 0, jogadas = 0, jogadaCPUX, jogadaCPUY, menuopc;

    system("cls");
    printf("\n\n%s%s     BEM-VINDO AO JOGO DA VELHA! %s \t\t %svers�o 1.0%s\n", AMARELO, PRETO, PADRAO, CINZA, PADRAO);
    

    //SELE��O DA PRIMEIRA ESCOLHA DO JOGADOR PARA SABER SE QUER JOGAR MESMO
    while(1){
        system("cls");
        printf("\n\n%s%s ESCOLHA O QUE QUER FAZER: %s", AMARELO, PRETO, PADRAO);
        printf("\n%s%s 1.%s JOGAR ", AMARELO, PRETO, PADRAO);
        printf("\n%s%s 2.%s VOLTAR AO MENU ", AMARELO, PRETO, PADRAO);
        printf("\n\n%s%s RESPOSTA:%s ", AMARELO, PRETO, PADRAO);
		scanf("%d", &menuopc);

        if(menuopc == 1){
            break;
        } else if(menuopc == 2){
            break;
        }

    }

    if(menuopc == 2){
        return 0;
    }

    system("cls");

    jogador novojogador; //CRIA A NOVA STRUCT DE NOVO JOGADOR

    printf("\n\n%s%s ME DIGA SEU NOME:%s ", AMARELO, PRETO, PADRAO);
    scanf("%s", novojogador.nome); //DEFININDO O NOME DO NOVO JOGADOR
    getchar();


    //ESCOLHA DO S�MBOLO
    while(1){

        system("cls");
        printf("\n\n%s%s ESCOLHA SEU SIMBOLO: %s", AMARELO, PRETO, PADRAO);
        printf("\n%s%s 1.%s X ", AMARELO, PRETO, PADRAO);
        printf("\n%s%s 2.%s O ", AMARELO, PRETO, PADRAO);
        printf("\n\n%s%s RESPOSTA:%s ", AMARELO, PRETO, PADRAO);
        scanf("%c", &opc);

        if(opc == '1'){
            player = 'X';
            CPU = 'O';
            break;
        } else if(opc == '2'){
            player = 'O';
            CPU = 'X';
            break;
        };

    }

    //DEBUGG APENAS
    printf("\n%s%s VOCE SELECIONOU:%s %c\n\n", AMARELO, PRETO, PADRAO, player);
    system("pause");


    system("cls");
    printf("\n\n");
    exibmatriz(jogodavelha, MAXLIN, MAXCOL);


    //INICIO DA FUN��O DE CONTAGEM DO TEMPO DE JOGO
    clock_t starttime = clock();

    while (jogando) { // INICIO DO JOGO NA TABELA EM SI
        srand(time(NULL));
        while (contador < 5) {
            int jogadainvalida = 1;

            // Jogada do jogador
            while(jogadainvalida){
                jogadainvalida = jogada(opc, player);
                ultimajogada = 1;


                if(!jogadainvalida){
                    jogadavalida = 1;
                    jogadas++;
                }

                if(sair){
                    break;
                }
            }

            if(sair){
                break;
            }

            // Jogada da m�quina
            while (jogadavalida) {
                jogadaCPUX = (rand() % 3) * 2;
                jogadaCPUY = (rand() % 3) * 2;
                
                if (jogodavelha[jogadaCPUY][jogadaCPUX] >= '1' && jogodavelha[jogadaCPUY][jogadaCPUX] <= '9') {
                    if(verifvitoria() == 0){
                        jogodavelha[jogadaCPUY][jogadaCPUX] = CPU;
                        ultimajogada = 2;
                    }
                    break;
                } else if (verifjogo(jogodavelha) == 1){
                    break;
                }
            }

            //VERIFICA��O DE VIT�RIA
            if(verifvitoria() == 1){
                break;
            }
            contador++;
        }

        break;
    }
    
    //FINAL DA CONTAGEM DO TEMPO E CALCULO PARA SABER O TEMPO
    clock_t endtime = clock();
    double finaltime = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    novojogador.tempo = finaltime;

    system("cls");

    if(sair){

        printf("\n\n JOGO INTERROMPIDO PELO JOGADOR!\n");
        system("pause");
        return 0;



    } else {
        printf("\n\n%s%s     O JOGO ACABOU!%s\n\n", AMARELO, PRETO, PADRAO);
    exibmatriz(jogodavelha, MAXLIN, MAXCOL);
    printf("\n\n     O RESULTADO FOI: ");
    verifvitoria();

    //SABER QUEM GANHOU PELA ULTIMA JOGADA
    if(verifvitoria() == 1){
        vitoria = 1;
    } else {
        vitoria = 0;
    };

    //VER SE ULTIMA JOGADA FOI VIT�RIA MESMO
    if(vitoria == 1){

        if(ultimajogada == 1){
            printf("%sVITORIA DE %s!%s +50 PONTOS\n", TEXTOAMARELO, novojogador.nome, PADRAO);
        } else if(ultimajogada == 2){
            printf("%sVITORIA DA CPU!%s\n", TEXTOAZUL, PADRAO);
        }

    } else if(vitoria == 0){
        printf("%sEMPATE! +25 PONTOS%s\n", BRANCO, PADRAO);
    }

    //CALCULA O SCORE POR ULTIMO
    int score = 0;
    printf("     O JOGO DUROU: %s%.2fs%s\n", TEXTOVERDE, finaltime, PADRAO);
    printf("     JOGADAS: %s%d%s\n\n", TEXTOAZUL, jogadas, PADRAO);
    printf("     ============ CALCULO DO SCORE ============\n");
    printf("     |    JOGADAS  |   TEMPO    |   PONTOS    |\n");
    printf("     |-------------|------------|-------------|\n");
    printf("     |     < 4     |    < 2s    |     +50     |\n");
    printf("     |     < 5     |    < 5s    |     +35     |\n");
    printf("     |     < 7     |    < 7s    |     +20     |\n");
    printf("     |       9     |   >= 10s   |      +5     |\n");
    printf("     |-------------|------------|-------------|\n\n");

    if(ultimajogada == 1){
        score += 50;

        if(jogadas < 4){
            score += 50;
        } else if(jogadas < 5){
            score += 35;
        } else if(jogadas < 7){
            score += 20;
        } else if(jogadas >= 9){
            score += 5;
        }

        if(finaltime < 2){
            score += 50;
        } else if(finaltime < 5){
            score += 35;
        } else if(finaltime < 7){
            score += 20;
        } else if(finaltime >= 10){
            score += 5;
        }

    } else {
        score = 0;
    }
    printf("      %sSCORE%s = %d\n\n",TEXTOAMARELO, PADRAO, score);
    novojogador.totalscore = score;
    //AGORA PARA DEFINIR A STRUCT DO rankingttt; novojogador.tempo e novojogador.nome

    int jogadorencontrado = 0;
    int posit = 0;

    for (int i = 0; i < 10; i++) {
        if (strcmp(rankingttt[i].nome, novojogador.nome) == 0) {
            jogadorencontrado = 1;
            break;
        }
        posit++;
    }

    if (jogadorencontrado == 1) {
        printf("\n     Jogador encontrado no ranking, caso tenha tido resultado melhor ira ser substituido!\n\n");
        if (novojogador.tempo < rankingttt[posit].tempo) {
            rankingttt[posit] = novojogador;
        }
    } else {
        if(score != 0){
            printf("\n     PARABENS! SCORE computado no ranking, sera que ficou em primeiro?!\n\n");
            rankingttt[numerojogadores++] = novojogador;
        } else {
            printf("\n     Oh nao! Voce perdeu, SCORE nao computado! Tende novamente.\n\n");
        }
    }
    
    limparmatriz();
    ordenarrankingttt(rankingttt, numerojogadores);
    system("pause");

    //FINAL DO CODIGO

    return 0;
    }
}