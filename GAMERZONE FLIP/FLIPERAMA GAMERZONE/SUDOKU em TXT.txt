#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct { //STRUCT DO RANKING
    
    char nome[50];
    double tempo;
    int totalscore;

} jogadorsudoku;

void ordenarrankingsudoku(jogadorsudoku rankingsudoku[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMinimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (rankingsudoku[j].tempo < rankingsudoku[indiceMinimo].tempo) {
                indiceMinimo = j;
            }
        }
        if (indiceMinimo != i) {
            jogadorsudoku temp = rankingsudoku[i];
            rankingsudoku[i] = rankingsudoku[indiceMinimo];
            rankingsudoku[indiceMinimo] = temp;
        }
    }
}

jogadorsudoku rankingsudoku[10];

int SUDOKU(){
	clock_t starttime = clock();

	int x,i,j,k,n=3,m[n*n][n*n]; 
    int m2[9][9],y,w,z,t,l,c,cont=0;
    int v[9],a,b,num,opc,c_e,certo=0;
    
	setlocale(LC_ALL,"");
	
	srand(time(NULL));
	
	x=rand()%10;
	
	// Algoritmo utilizado para gerar os n�meros que preencher�o as posi��es da Matriz da forma correta do sudoku.
	
	for(i = 0; i < n; i++, x++){ 
    for(j = 0; j < n; j++, x+=n){
        for(k = 0; k < n*n; k++, x++){
            m[n*i+j][k] = (x % (n*n)) + 1;
			}
		}
	}
	// Loops que ir�o alterar as posi��es de algumas colunas e linhas da Matriz gerada, pois sem essa altera��es ficaria muito �bvio os as posi��es dos n�meros.
       for(i=0;i<9;i++){
			for(j=0;j==0;j++){
				v[i]=m[j][i];
			}
		}
		 for(i=0;i<9;i++){
			for(j=0,a=1;j==0;j++){
				m[j][i]=m[a][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=1;j==1;j++){
				m[j][i]=v[i];
			}
		}
		
		for(i=0;i<9;i++){
			for(j=3;j==3;j++){
				v[i]=m[j][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=3,a=5;j==3;j++){
				m[j][i]=m[a][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=5;j==5;j++){
				m[j][i]=v[i];
			}
		}
		
		for(i=0;i<9;i++){
			for(j=6;j==6;j++){
				v[i]=m[j][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=6,a=7;j==6;j++){
				m[j][i]=m[a][i];
			}
		}
		for(i=0;i<9;i++){
			for(j=7;j==7;j++){
				m[j][i]=v[i];
			}
		}
		
		for(i=0;i<9;i++){
			for(j=0;j==0;j++){
				v[i]=m[i][j];
			}
		}
		 for(i=0;i<9;i++){
			for(j=0,a=1;j==0;j++){
				m[i][j]=m[i][a];
			}
		}
		for(i=0;i<9;i++){
			for(j=1;j==1;j++){
				m[i][j]=v[i];
			}
		}
		
		for(i=0;i<9;i++){
			for(j=3;j==3;j++){
				v[i]=m[i][j];
			}
		}
		for(i=0;i<9;i++){
			for(j=3,a=5;j==3;j++){
				m[i][j]=m[i][a];
			}
		}
		for(i=0;i<9;i++){
			for(j=5;j==5;j++){
				m[i][j]=v[i];
			}
		}
		
		for(i=0;i<9;i++){
			for(j=6;j==6;j++){
				v[i]=m[i][j];
			}
		}
		for(i=0;i<9;i++){
			for(j=6,a=7;j==6;j++){
				m[i][j]=m[i][a];
			}
		}
		for(i=0;i<9;i++){
			for(j=7;j==7;j++){
				m[i][j]=v[i];
			}
		}
		// Loop utilizado para escolher a dificuldade do jogo.
		while(1){
		printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t1-Facil\n\t\t\t\t\t\t\t\t\t\t2-Medio\n\t\t\t\t\t\t\t\t\t\t3-Dificil\n\t\t\t\t\t\t\t\t\t\tEscolha a dificuldade:");
		scanf("%d",&opc);
		switch(opc)
		{
		case 1:
		y=rand()%8;
        w=rand()%8;
        z=rand()%8;

		// Loop utilizado para repassar os valores para outra matriz, mas "apagando" alguns n�meros de forma aleat�rio utilizando os n�meros gerados com random.
        for(i=0;i<9;i++){
           for(j=0;j<9;j++){
           m2[i][j]=m[i][j];
           if(i==y ||i==w || i==z || j==y ||j==w ||j==z){
			m2[i][j]=0;
		   y=rand()%8;
           w=rand()%8; // Atualizando os n�meros rand�micos para n�o apagar uma linha ou coluna toda.
           z=rand()%8;
           }
           }
        }
        certo=1;
			break;
		case 2 :
		y=rand()%8;
        w=rand()%8;
        z=rand()%8;
        t=rand()%8;
        
        // Loop utilizado para repassar os valores para outra matriz, mas "apagando" alguns n�meros de forma aleat�rio utilizando os n�meros gerados com random.
        for(i=0;i<9;i++){
           for(j=0;j<9;j++){
           m2[i][j]=m[i][j];
           if(i==y ||i==w||i==z|| i==t || j==y ||j==w||j==z || j==t  ){
			m2[i][j]=0;
		   y=rand()%8;
           w=rand()%8;
           z=rand()%8; // Atualizando os n�meros rand�micos para n�o apagar uma linha ou coluna toda.
           t=rand()%8;
           }
           }
        }
        certo=1;
        break;
  		case 3 :
		y=rand()%8;
        w=rand()%8;
        z=rand()%8;
        t=rand()%8;
        b=rand()%8;
        
        // Loop utilizado para repassar os valores para outra matriz, mas "apagando" alguns n�meros de forma aleat�rio utilizando os n�meros gerados com random.
        for(i=0;i<9;i++){
           for(j=0;j<9;j++){
           m2[i][j]=m[i][j];
           if(i==y ||i==w||i==z||i==t||i==b || j==y ||j==w||j==z || j==t || j==b ){
			m2[i][j]=0;
		   y=rand()%8;
           w=rand()%8;
           z=rand()%8; // Atualizando os n�meros rand�micos para n�o apagar uma linha ou coluna toda.
           t=rand()%8;
           b=rand()%8;
           }
           }
        }
        certo=1;
        break;
		default:
			system("cls");
			printf("Opcao invalida");
			break;
		}
		if(certo==1){
			break;
		}
		}
        //  O print do corpo do jogo.
        for(;;){
		system("cls");
		printf("\n\t\t\t\t\t\t\033[38;5;15mCaso deseje desistir e voltar ao menu digite o numero 10 nos tres inputs\033[0m");
		printf("\n");
		printf("\n\t\t\t\t\t\t\t\t  |||C1|C2|C3|||C4|C5|C6|||C7|C8|C9||\n\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||\n");
        for(i=0;i<9;i++){
        	printf("\t\t\t\t\t\t\t\tL%d||",i+1);
			for(j=0;j<9;j++){
				printf(" %d ",m2[i][j]);
				if(j==2 || j==5){
					printf("||");
				}
			}
			printf("||\n");
			if(i==2||i==5||i==8){
			printf("\t\t\t\t\t\t\t\t|||||||||||||||||||||||||||||||||||||\n");
			}else{
				printf("\t\t\t\t\t\t\t\t||||\t     ||\t\t||\t   ||\n");
			}
	}
		if(c_e==0){
			printf("\nNumero Correto !!!\n\n");
		}
		if(c_e==1){
			printf("\nNumero Errado !!!\n\n");
		}
	// Local onde o jogador indicara a linha e coluna q ir� ser alterada, e tamb�m o numero q ir� ser inserido na posi��o.
	printf("\t\t\t\t\t\t\t\tDigite a linha:");
	scanf("%d",&l);
	printf("\t\t\t\t\t\t\t\tDigite a coluna:");
	scanf("%d",&c);
	printf("\t\t\t\t\t\t\t\tInforme o valor certo:");
	scanf("%d",&num);
	// Condi��o de que se for um espa�o "vazio" ela ser� preenchido.
	if(m2[l-1][c-1]==0){	
		m2[l-1][c-1]=num;
		c_e=0;
	} 
	// Condi��o que ir� verificar se o n�mero escaneado � o certo com base na matriz de verifica��o.
	if(m2[l-1][c-1]!=m[l-1][c-1]){
		m2[l-1][c-1]=0;
		c_e=1;
	}
	//Loop que verifica se a matriz alterada e igual a de verifica��o, utilizando um contador.
	 for(i=0;i<9;i++){
           for(j=0;j<9;j++){
           if(m2[i][j]==m[i][j]){
			   cont++;
		   }
		   }
	 }
	 // Condi��o de parada verificando o contador.
	if(cont==81){
		system("cls");
		printf("\n");
		printf("\n   ||C1|C2|C3|||C4|C5|C6|||C7|C8|C9||\n|||||||||||||||||||||||||||||||||||||\n");
        for(i=0;i<9;i++){
        	printf("L%d||",i+1);
			for(j=0;j<9;j++){
				printf(" %d ",m2[i][j]);
				if(j==2 || j==5){
					printf("||");
				}
			}
			printf("||\n");
			if(i==2||i==5||i==8){
			printf("|||||||||||||||||||||||||||||||||||||\n");
			}else{
				printf("||||\t     ||\t\t||\t   ||\n");
			}
		}
		printf("Parabens voce completou !!!\n");
        clock_t endtime = clock();
        double finaltime = (double)(endtime - starttime) / CLOCKS_PER_SEC;

		jogadorsudoku novojogador;

	    printf("O TEMPO DE JOGO FOI: %.2f", finaltime/60);
		printf("\n DIGITE SEU NOME: ");
		scanf("%s", novojogador.nome);
		novojogador.tempo = finaltime;
		int numerojogadores = 0;
		int jogadorencontrado = 0;
		int posit = 0;


		//ranking sudoku
		for (int i = 0; i < 10; i++) {
			if (strcmp(rankingsudoku[i].nome, novojogador.nome) == 0) {
				jogadorencontrado = 1;
				break;
			}
			posit++;
		}

		if (jogadorencontrado == 1) {
			printf("\n\n     Jogador encontrado no ranking, caso tenha tido resultado MELHOR vai ser SUBSTITUIDO!\n\n");
			if (novojogador.tempo < rankingsudoku[posit].tempo) {
				rankingsudoku[posit] = novojogador;
			}
		} else {
			rankingsudoku[numerojogadores++] = novojogador;
		}

		ordenarrankingsudoku(rankingsudoku, numerojogadores);

	    system("pause");
		break;

	}	   
	cont=0;
	if(l == 10 && c == 10 && num == 10){
		break;
	}
	
	}
    return 0;
	}	