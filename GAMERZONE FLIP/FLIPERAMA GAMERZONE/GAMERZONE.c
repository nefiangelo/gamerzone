//BIBLIOTECAS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "jogos/SUDOKU.h"
#include "jogos/TICTACTOE.h"

//DEFINES DE ALGUMAS COISA
#define cima 119
#define baixo 115
#define enter 13
#define esc 27
#define FALSE 0
#define TRUE 1

// A LOGO
char menu[18][50] = { // A LOGO É UMA MATRIZ QUE CADA LETRA É UMA COR EM PIXEL
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ','A','A','A','A','A','A',' ','A','A','A','A','A','A',' ','A','A','A',' ',' ','A','A','A',' ','A','A','A','A','A','A',' ','A','A','A','A','A','A',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ','B','B',' ',' ',' ',' ',' ','B','B',' ',' ','B','B',' ','B','B',' ','B','B',' ','B','B',' ','B','B',' ',' ',' ',' ',' ','B','B',' ',' ','B','B',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ','C','C',' ','C','C','C',' ','C','C','C','C','C','C',' ','C','C',' ','C','C',' ','C','C',' ','C','C','C','C','C','C',' ','C','C','C','C',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ','D','D',' ',' ','D','D',' ','D','D',' ',' ','D','D',' ','D','D',' ',' ',' ',' ','D','D',' ','D','D',' ',' ',' ',' ',' ','D','D',' ','D','D',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ','E','E','E','E','E','E',' ','E','E',' ',' ','E','E',' ','E','E',' ',' ',' ',' ','E','E',' ','E','E','E','E','E','E',' ','E','E',' ',' ','E','E',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','A','A','A','A','A','A',' ','A','A','A','A','A','A',' ','A','A','A','A',' ',' ','A','A','A','A','A','A',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','B','B','B',' ','B','B',' ',' ','B','B',' ','B','B',' ','B','B',' ','B','B',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','C','C','C','C',' ',' ','C','C',' ',' ','C','C',' ','C','C',' ','C','C',' ','C','C','C','C','C','C',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D','D','D',' ',' ',' ',' ','D','D',' ',' ','D','D',' ','D','D',' ','D','D',' ','D','D',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','E','E','E','E','E','E',' ','E','E','E','E','E','E',' ','E','E',' ','E','E',' ','E','E','E','E','E','E',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','>',' ',' ','J','O','G','O','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','I','N','F','O','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','C','R','E','D','I','T','S',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','R','A','N','K','I','N','G',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
};
char jogos[3][10] = { //MENU EM MATRIZ
            {'>',' ','T','I','C','T','A','C',' ',' ',},
            {' ',' ','S','U','D','O','K','U',' ',' ',},
            {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',},
        };

// UMA FUNÇÃO PADRÃO DO WINDOWS.H QUE SÓ MMUDA UM CURSOR DE LUGAR, VAMOS USAR ELA LA NA MAIN.
void menuselect(int linha, int coluna){
    COORD coord;
    coord.X = coluna;
    coord.Y = linha;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// FUNÇÃO PARA SABER QUAL TECLA FOI DIGITADA E ATRIBUIR UM VALOR A ELA
int digit(int tecla, int *linha_m, int limit_cima, int limit_baixo){
    //PRIMEIRO TEMOS QUE SABER SE A TECLA ESTÁ EM LUGAR VÁLIDO OU NO LIMITE DE CIMA (linha 14) OU DE BAIXO (linha 16)
    if((*linha_m == limit_cima && tecla == cima) || (*linha_m == limit_baixo && tecla == baixo)){
        //ESTÁ NO LIMITE ENTÃO NADA ACONTECE
    } else {
        //AÇÕES
        //OBS: QUANDO RETORNA FALSE, É APENAS PARA QUE (LA NA MAIN) O LOOP N SEJA QUEBRADO E CONTINUE NO MENU.

        //SE PRECIONAR "W"
        if(tecla == cima){
            *linha_m -= 1;
            return FALSE;
        } else if(tecla == baixo){ //SE PRESSIONAR "S"
            *linha_m += 1;
            return FALSE;
        }

    }
    // SE PRESSIONAR ENTER
        if(tecla == enter){
            return TRUE;
        } else {
            return FALSE;
        }
}


// FUNÇÃ O NORMAL DE PRINTAR A LOGO MESMO QUE A GENTE SEMPRE USOU
void exibirMat(char matriz[][50]){
    int lin, col;
    for(lin = 0; lin < 18; lin++){
        printf("\t\t\t\t\t\t\t\t   ");
        for(col = 0; col < 50; col++){
            if(matriz[lin][col] == ' '){
                printf("%c", matriz[lin][col]);
            } else if(matriz[lin][col] == 'A' && lin < 13){
                printf("\033[38;5;17m\033[48;5;17m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'B'){
                printf("\033[38;5;18m\033[48;5;18m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'C' && lin < 13){
                printf("\033[38;5;19m\033[48;5;19m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'D' && lin < 13){
                printf("\033[38;5;20m\033[48;5;20m%c\033[0m",matriz[lin][col]);
            } else if(matriz[lin][col] == 'E' && lin < 13){
                printf("\033[38;5;21m\033[48;5;21m%c\033[0m",matriz[lin][col]);
            } else if(lin > 13 && matriz[lin][col] != '>') {
                printf("%c", matriz[lin][col]);
            } else if(matriz[lin][col] == '>'){
                printf("\033[38;5;21m%c\033[0m",matriz[lin][col]);
            }
        }
        printf("\n");
    }
}

void semPiscar(){
    //APENAS PARA DAR EFEITO DE QUE NÃO TEM ONDE ESCREVER, ELE SOME COM O SIMBOLOZINHO DE ESCREVER QUE PISCA
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //SELECIONA O HANDLE PARA OUTPUT (O CONSOLE MSM)
    CONSOLE_CURSOR_INFO cursorInfo; // PEGA AS PROPRIEDADES DO CONSOLE
    GetConsoleCursorInfo(consoleHandle, &cursorInfo); // DAÍ ELEAPLICA AS INFORMAÇÕES PADRÃO
    cursorInfo.bVisible = FALSE; // COLOCA A PROPRIEDADE "VISIBLE BUTTON" PARA FALSE
    SetConsoleCursorInfo(consoleHandle, &cursorInfo); // APLICA DNV
}

void Piscando(){
    //CÓPIA DO OUTRO MAS QUE AGORA PISCA
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_CURSOR_INFO cursorInfo; 
    GetConsoleCursorInfo(consoleHandle, &cursorInfo); 
    cursorInfo.bVisible = TRUE; 
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}




// COMEÇO DO CODIGO ------------------------------------------------------------------------------
int main(){
    HWND hwnd = GetConsoleWindow(); // Obtém o identificador da janela do console
    ShowWindow(hwnd, SW_MAXIMIZE);  // Maximiza a janela do console
    semPiscar();
    menu:
    system("cls");
    int limite_cima = 17;
    int limite_baixo = 20;
    int linha_menu = 17;
    int tecla = 0;
    int input = FALSE;

    printf("\n\n\n");
    exibirMat(menu);
    printf("\n\t\t\t\t\t\t\t\t\t    \033[38;5;240mUSE ");
    printf("\033[38;5;12mW");
    printf("\033[38;5;240m e ");
    printf("\033[38;5;12mS");
    printf("\033[38;5;240m para usar o MENU!\n\n");
    printf("\t\t\t\t\t\t\t\t\t    \033[38;5;240m ESC para sair do programa!\033[0m");
    printf("\n\033[48;5;240m\033[38;5;0m Versao BETA 1.0 \033[0m");


    do{
        if(kbhit() != 0){ //SE ALGUMA TECLA FOR APERTADA
        tecla = getch(); // ELE PEGA A TECLA
        menuselect(linha_menu,40); // COLOCA O CURSOR NO LOCAL DESEJADO
        printf("\t\t\t                      ");//IMPRIME ISSO AÍ
        input = (digit(tecla, &linha_menu, limite_cima, limite_baixo));//VÊ SE O APERTOU ENTER
        menuselect(linha_menu,40); //COLOCA O CURSOR NO LUGAR NOVO
        printf("\t\t\t                     \033[38;5;21m>\033[0m"); //IMPRIMIR ISSO NO LUGAR NOVO

        if(input == TRUE){ // SE ELE APERTAR ENTER 
            break;
        }
        
        if(tecla == esc){
            exit(0);
        } 

        }
    } while (tecla != 13);

    //AREA DE JOGOS 
    tecla = 0;
    if(linha_menu == 17){ // JOGO 1 - REINOS ------------------------------
        linha_menu = 1;
        limite_cima = 1;
        limite_baixo = 2;

        tecla = 0;
        system("cls");
        printf("\n");
        
		int i,j;

        for (i = 0; i < 3; i++){
            printf("  ");
            for(j = 0; j < 10; j++){
                if(jogos[i][j] == '>'){
                    printf("\033[38;5;21m%c\033[0m",jogos[i][j]);
                } else {
                    printf("%c", jogos[i][j]);
                }
            }
            printf("\n");
        }


        do{
            if(kbhit() != 0){ 
                tecla = getch(); 
                menuselect(linha_menu,1); 
                printf("  ");
                input = (digit(tecla,&linha_menu, limite_cima, limite_baixo));
                menuselect(linha_menu,1); 
                printf(" \033[38;5;21m>\033[0m"); 

                if(input == TRUE){ 
                    break;
                }
            }

        } while (tecla != 13 && tecla != 27);   

        if(tecla == 27){
            goto menu;
        } else if(linha_menu == 1){
            Piscando();
            system("cls");
            TICTACTOE();

            semPiscar();
            goto menu;

        } else if(linha_menu == 2){
            Piscando();
            system("cls");
            SUDOKU();

            semPiscar();
            goto menu;
        }
    }

    //AREA DAS INFOS
    if(linha_menu == 18){
        infos:
        system("cls");
        printf("\n\n     Os jogos desenvolvidos foram feitos com muito carinho e com muito amor, apesar da dificuldade :)\n\n");
        printf("Aperte ESC para retornar ao menu.");
        tecla = getch();
        if(tecla == esc){
            goto menu;
        } else {
            goto infos;
        };
    }

    //AREA DOS CREDITOS
    if(linha_menu == 19){
        creditos:
        system("cls");
        printf("\n\n     ALUNOS DO CURSO DE CIENCIA DA COMPUTACAO\n");
        printf("\n     - NEFI ANGELO DIAS DA COSTA");
        printf("\n     - ROBERT DANILO SANTOS DA SILVA");
        printf("\n     - PAULO HENRIQUE DA SILVA PEREIRA");
        printf("\n     - RAFAEL ALEXANDER DE SOUZA BRITO");
        printf("\n\n     Aperte ESC para retornar ao menu.\n\n");
        tecla = getch();
        if(tecla == esc){
            goto menu;
        } else {
            goto creditos;
        };
    }


    //AREA DO RANKING
    if(linha_menu == 20){ //RANKING DOS JOGOS (RANKING DO JOGO DA VELHA POIS O SUDOKU FICA SALVO EM OUTRO LUGAR)
        int contador = 0;
        ranking:
        system("cls");
        printf("\n\t\t\t\t\t\t\033[38;5;240m            PRESSIONE ESC A QUALQUER MOMENTO PARA VOLTAR   \033[0m");
        printf("\n\n\t\t\t\t\t\t\t\033[38;5;12m============== RANKING GERAL DOS GAMES ============= \033[0m\n\n");
        printf("\n\n\t\t\t\t\033[38;5;12m===== TIC TAC TOE =====\033[38;5;240m BASEADO NO TEMPO\033[0m\n\n");
        for(int i = 0; i < numerojogadores; i++){
            if(contador == 0){
                printf("\t\t\t\t%d. \033[38;5;220m%s\033[0m - %.2lf segundos \033[38;5;12m-\033[0m %d POINTS",i+1, rankingttt[i].nome, rankingttt[i].tempo, rankingttt[i].totalscore);
            } else if(contador == 1){
                printf("\t\t\t\t%d. \033[38;5;15m%s\033[0m - %.2lf segundos \033[38;5;12m-\033[0m %d POINTS", i+1, rankingttt[i].nome, rankingttt[i].tempo, rankingttt[i].totalscore);
            } else if(contador == 2){
                printf("\t\t\t\t%d. \033[38;5;136m%s\033[0m - %.2lf segundos \033[38;5;12m-\033[0m %d POINTS", i+1, rankingttt[i].nome, rankingttt[i].tempo, rankingttt[i].totalscore);
            } else if(contador > 2){
                printf("\t\t\t\t%d. \033[38;5;7m%s\033[0m - %.2lf segundos \033[38;5;12m-\033[0m %d POINTS", i+1, rankingttt[i].nome, rankingttt[i].tempo, rankingttt[i].totalscore);
            }
            contador++;
            printf("\n");
    }
        printf("\n\n\t\t\t\t\033[38;5;12m===== SUDOKU =====\033[38;5;240m BASEADO NO TEMPO\033[38;5;0m\n\n");
        
    


        tecla = getch();
        if(tecla == esc){
            goto menu;
        } else {
            goto ranking;
        };
    }
    
    return 0;
}