#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

char tab[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int indiceUsadas = 0;

typedef struct {
    int usadas[9];
    int restantes[9];

}Casa;

Casa casas = { {0}, {1, 2, 3, 4, 5, 6, 7, 8, 9} };

int inicio(){
	int decisao = -1;

	printf("---------------------Jogo da Velha-----------------------");
	printf("\n");
	printf("\n");
	printf("Escolha:");
	printf("\n");
	printf("1 - Você começa jogando");
	printf("\n");
	printf("2 - A CPU começa jogando");
	printf("\n");
	printf("0 - Encerrar o programa");
	printf("\n");
	printf("\n");

	printf("Resposta: ");
	scanf("%d", &decisao);
	printf("\n");
	printf("---------------------------------------------------------");
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
	printf(" %c  |  %c  |  %c         7  | 8  | 9  \n", tab[2][0], tab[2][1], tab[2][2]);
	printf("    |     |               |    |    \n");
	printf("\n");

	printf("Resposta: ");
	scanf("%d", &casa);
	printf("\n");

	return casa;
}

void mensagemErro(char mensagem[100]){
	printf("\n");
	printf("-------------------------------------");
	printf("\n");
	printf("\n");
	printf("%s", mensagem);
	printf("\n");
	printf("\n");
	printf("-------------------------------------");
	printf("\n");
	printf("\n");
}

void salvarMudancas(int casa){

    casas.usadas[indiceUsadas] = casa;
    indiceUsadas++;
    casas.restantes[casa-1] = 0;

}

void marcarTabuleiro(int casa, char simbolo){
	switch (casa){
		case 1:
		tab[0][0] = simbolo;
        salvarMudancas(casa);
		break;

		case 2:
		tab[0][1] = simbolo;
		salvarMudancas(casa);
		break;

		case 3:
		tab[0][2] = simbolo;
		salvarMudancas(casa);
		break;

		case 4:
		tab[1][0] = simbolo;
		salvarMudancas(casa);
		break;

		case 5:
		tab[1][1] = simbolo;
		salvarMudancas(casa);
		break;

		case 6:
		tab[1][2] = simbolo;
		salvarMudancas(casa);
		break;

		case 7:
		tab[2][0] = simbolo;
		salvarMudancas(casa);
		break;

		case 8:
		tab[2][1] = simbolo;
		salvarMudancas(casa);
		break;

		case 9:
		tab[2][2] = simbolo;
		salvarMudancas(casa);
		break;

		default:
		mensagemErro("Erro! Não foi possível marcar o tabuleiro!");

	}

}

bool verificarCasa(int casa){
	bool usando = false;

	for(int i = 0; i < 9; i++){
		if(casas.usadas[i] == casa){
			usando = true;
		}

	}

	return usando;
}

int main(){
	setlocale(LC_ALL, "C.UTF-8");
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
			do{
				int casa = tabuleiro();
				if(casa < 1 || casa > 9){
					mensagemErro("Não existe uma casa com esse número! Digite um número válido!");
					repetir = true;
					continue;
				}
				bool usando = verificarCasa(casa);
				if(usando){
					mensagemErro("Erro! A casa selecionada já está sendo usada!");
					repetir = true;
					continue;
				}
				else{
					repetir = false;
					marcarTabuleiro(casa, 'X');


				}

			} while(repetir);
		}
		else if(decisao == 2){

		}
		else if(decisao == 0){
			printf("Encerrando o programa...");
			printf("\n");
			repetir = false;
		}
	} while(repetir);

	return 0;

}
