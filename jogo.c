#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char tab[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

int inicio(){
	int decisao = -1;
	
	printf("-----------Jogo da Velha-------------");
	printf("\n");
	printf("\n");
	printf("Escolha:");
	printf("\n");
	printf("1 - Você começa jogando");
	printf("\n");
	printf("2 - A CPU começa jogando");
	printf("\n");
	printf("0 - Encerrar o pŕograma");
	printf("\n");
	printf("\n");
	
	printf("Resposta: ");
	scanf("%d", &decisao);
	printf("\n");
	printf("-------------------------------------");
	printf("\n");
	printf("\n");
	
	return decisao;
}

int tabuleiro(){
	int casa = -1;

	printf("    |     |               |    |    \n");
	printf(" %c  |  %c  |  %c         1  | 2  | 3  \n", tab[0][0], tab[0][1], tab[0][2]);
	printf("____|_____|____       ____|____|____\n");
	printf("    |     |               |    |    \n");
	printf(" %c  |  %c  |  %c         4  | 5  | 6  \n", tab[1][0], tab[1][1], tab[1][2]);
	printf("____|_____|____       ____|____|____\n");
	printf("    |     |               |    |    \n");
	printf(" %c  |  %c  |  %c         4  | 5  | 6  \n", tab[2][0], tab[2][1], tab[2][2]);
	printf("    |     |               |    |    \n");
	printf("\n");

	printf("Resposta: ");	
	scanf("%d", &casa);
	printf("\n");

	return casa;
}

void main(){
	bool repetir = false;
	
	do{
	
		int decisao = inicio();
		
		if(decisao != 1 && decisao != 2 && decisao != 0){
			printf("Não existe essa opção! Escolha uma opção existente!");
			printf("\n");
			printf("\n");
			repetir = true;
		}
		else if(decisao == 1){			
			int casa = tabuleiro();
		
		}
		else if(decisao == 2){
		
		}
		else if(decisao == 0){
			printf("Encerrando o programa...");
			printf("\n");		
			repetir = false;
		}
	} while(repetir);

}
