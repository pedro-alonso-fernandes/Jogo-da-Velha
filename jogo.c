#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


typedef struct {

    int vitorias[2];
    int empates;
    char nome[2][50];

}Usuario;

typedef struct {

    int vitorias;
    int empates;
    int derrotas;
    char nome[50];

}CPU;

typedef struct {

    int usadas[9];
    int restantes[9];
    int indiceUsadas;

}Casa;

typedef struct {

    char tab[3][3];
    int jogadas[2][5]; // 2 jogadores com no máximo 5 jogadas
    Casa casas;
    CPU cpu;
    Usuario usuario;

}Jogo;

// Inicializando variáveis
Jogo jogo = {
    // tab[3][3]
    {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}},

    // jogadas[2][5]
    {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1} },

    // struct casas
    { {0}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, 0 },

    // struct cpu
    {0, 0, 0, {'U','s','u','á','r','i','o'}}, // Nome padrão: "Usuário"

    //struct usuario
    {{0}, 0, { {'U','s','u','á','r','i','o',' ','1'}, {'U','s','u','á','r','i','o',' ','2'}}} // Nomes padrão: "Usuário 1" e "Usuário 2"
};


int menu(){
	int decisao = -1;

	printf("---------------------Jogo da Velha-----------------------");
	printf("\n");
	printf("\n");
	printf("Escolha:");
	printf("\n");
	printf("1 - Novo jogo");
	printf("\n");
	printf("2 - Configurações");
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

int novoJogo(){
    int decisao = -1;

    printf("Escolha:");
	printf("\n");
	printf("1 - Jogador x CPU");
	printf("\n");
	printf("2 - Jogador x Jogador");
	printf("\n");
	printf("0 - Voltar");
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

int configGeral(){
    int decisao = -1;

    printf("Escolha:");
	printf("\n");
	printf("1 - Alterar símbolos da partida");
	printf("\n");
	printf("2 - Configuração de Jogador x CPU");
	printf("\n");
	printf("3 - Configuração de Jogador x Jogador");
	printf("\n");
	printf("0 - Voltar");
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

	printf("    |     |               |    |    \n");
	printf(" %c  |  %c  |  %c         1  | 2  | 3  \n", jogo.tab[0][0], jogo.tab[0][1], jogo.tab[0][2]);
	printf("____|_____|____       ____|____|____\n");
	printf("    |     |               |    |    \n");
	printf(" %c  |  %c  |  %c         4  | 5  | 6  \n", jogo.tab[1][0], jogo.tab[1][1], jogo.tab[1][2]);
	printf("____|_____|____       ____|____|____\n");
	printf("    |     |               |    |    \n");
	printf(" %c  |  %c  |  %c         7  | 8  | 9  \n", jogo.tab[2][0], jogo.tab[2][1], jogo.tab[2][2]);
	printf("    |     |               |    |    \n");
	printf("\n");

	int casa = -1;
	printf("Resposta: ");
	scanf("%d", &casa);
	printf("\n");

	return casa;
}

void mensagemErro(char mensagem[100]){
	printf("\n");
	printf("---------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("%s", mensagem);
	printf("\n");
	printf("\n");
	printf("---------------------------------------------------------");
	printf("\n");
	printf("\n");
}

void salvarMudancas(int casa){

    jogo.casas.usadas[jogo.casas.indiceUsadas] = casa;
    jogo.casas.indiceUsadas++;
    jogo.casas.restantes[casa-1] = 0;

}

void marcarTabuleiro(int casa, char simbolo){
	switch (casa){
		case 1:
		jogo.tab[0][0] = simbolo;
        salvarMudancas(casa);
		break;

		case 2:
		jogo.tab[0][1] = simbolo;
		salvarMudancas(casa);
		break;

		case 3:
		jogo.tab[0][2] = simbolo;
		salvarMudancas(casa);
		break;

		case 4:
		jogo.tab[1][0] = simbolo;
		salvarMudancas(casa);
		break;

		case 5:
		jogo.tab[1][1] = simbolo;
		salvarMudancas(casa);
		break;

		case 6:
		jogo.tab[1][2] = simbolo;
		salvarMudancas(casa);
		break;

		case 7:
		jogo.tab[2][0] = simbolo;
		salvarMudancas(casa);
		break;

		case 8:
		jogo.tab[2][1] = simbolo;
		salvarMudancas(casa);
		break;

		case 9:
		jogo.tab[2][2] = simbolo;
		salvarMudancas(casa);
		break;

		default:
		mensagemErro("Erro! Não foi possível marcar o tabuleiro!");

	}

}

bool verificarCasa(int casa){
	bool usando = false;

	for(int i = 0; i < 9; i++){
		if(jogo.casas.usadas[i] == casa){
			usando = true;
			break;
		}

	}

	return usando;
}

bool verificarVitoria(char simbolo){
    bool vitoria = false;

//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            if(tab[i][j] == simbolo){
//
//            }
//        }
//    }

    return vitoria;
}

int main(){
	setlocale(LC_ALL, "C.UTF-8");
	bool repetirMenu = false;

	do{

		int decisao = menu();

		// Validação da entrada do usuário
		if(decisao != 1 && decisao != 2 && decisao != 0){
			printf("Não existe essa opção! Escolha uma opção existente!");
			printf("\n");
			printf("\n");
			while (getchar() != '\n'); // Limpa o buffer de entrada
			repetirMenu = true;
		}
		// Novo Jogo:
		else if(decisao == 1){
            decisao = -1;
            bool repetirNovoJogo = false;

            do{
                decisao = novoJogo();

                // Validação da entrada do usuário
                if(decisao != 1 && decisao != 2 && decisao != 0){
                    printf("Não existe essa opção! Escolha uma opção existente!");
                    printf("\n");
                    printf("\n");
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                    repetirNovoJogo = true;
                }
                // Jogador x CPU:
                else if(decisao == 1){

                    bool repetirTab = false;
                    do{
                        int casa = tabuleiro();
                        if(casa < 1 || casa > 9){
                            mensagemErro("Não existe uma casa com esse número! Digite um número válido!");
                            repetirTab = true;
                            continue;
                        }
                        bool usando = verificarCasa(casa);
                        if(usando){
                            mensagemErro("Erro! A casa selecionada já está sendo usada!");
                            repetirTab = true;
                            continue;
                        }
                        else{
                            marcarTabuleiro(casa, 'X');
                            repetirTab = true;


                        }

                    } while(repetirTab);

                }
                // Jogador x Jogador
                else if(decisao == 2){




                }
                // Voltar para o Menu principal
                else if(decisao == 0){
                    repetirMenu = true;
                    repetirNovoJogo = false;
                    break;
                }


            } while(repetirNovoJogo);


		}
		// Configurações
		else if(decisao == 2){
            decisao = -1;
            bool repetirConfigGeral = false;

            do{

                decisao = configGeral();

                // Validação da entrada do usuário
                if(decisao != 1 && decisao != 2 && decisao != 3 && decisao != 0){
                    printf("Não existe essa opção! Escolha uma opção existente!");
                    printf("\n");
                    printf("\n");
                    while (getchar() != '\n'); // Limpa o buffer de entrada
                    repetirConfigGeral = true;
                }
                else if(decisao == 1){

                }
                else if(decisao == 2){

                }
                else if(decisao == 3){

                }
                // Voltar para o Menu principal
                else if(decisao == 0){
                    repetirMenu = true;
                    repetirConfigGeral = false;
                    break;
                }

            } while(repetirConfigGeral);

		}
		else if(decisao == 0){
			printf("Encerrando o programa...");
			printf("\n");
			printf("\n");
            printf("---------------------------------------------------------");
            printf("\n");
			repetirMenu = false;
		}

	} while(repetirMenu);

	return 0;

}
