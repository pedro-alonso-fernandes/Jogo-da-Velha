#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

#define tamNome 15

typedef struct {

    int vitorias[2];
    int empates;
    char nome[2][tamNome];

}Jogador;

typedef struct {

    int vitorias;
    int empates;
    int derrotas;
    char nome[tamNome];

}CPU;

typedef struct {

    int usadas[9];
    int restantes[9];
    int indiceUsadas;

}Casa;

typedef struct {

    char tab[3][3];    // tabuleiro do jogo
    int jogadas[2][5]; // 2 jogadores com no máximo 5 jogadas
    char simbolos[2];  // simbolos do jogo (Ex: X e O);
    int rodada;
    int turno;         // Turno = 0: vez do jogador 1, turno = 1: vez do jogador 2
    Casa casas;
    CPU cpu;
    Jogador jogador;

}Jogo;

// Inicializando variáveis
Jogo jogo = {
    // tab[3][3]
    {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}},

    // jogadas[2][5]
    {{-1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1} },

    // simbolos
    {'X', 'O'},

    // rodada
    1,

    //turno
    0,

    // struct casas
    { {0}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, 0 },

    // struct cpu
    {0, 0, 0, {'J','o','g','a','d','o','r'}}, // Nome padrão: "Jogador"

    // struct jogador
    {{0}, 0, { {'J','o','g','a','d','o','r',' ','1'}, {'J','o','g','a','d','o','r',' ','2'}}} // Nomes padrão: "Jogador 1" e "Jogador 2"
};


int menu(){
	int decisao = -1;

	printf("------------------------Jogo da Velha--------------------------");
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
	printf("---------------------------------------------------------------");
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
	printf("---------------------------------------------------------------");
	printf("\n");
	printf("\n");

	return decisao;
}

int configGeral(){
    int decisao = -1;

    printf("Escolha:");
	printf("\n");
	printf("1 - Configuração de símbolos da partida");
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
	printf("---------------------------------------------------------------");
	printf("\n");
	printf("\n");

    return decisao;
}

int configSimbolos(){
    int decisao = -1;

    printf("Símbolos atuais: \"%c\" e \"%c\"", jogo.simbolos[0], jogo.simbolos[1]);
    printf("\n");
    printf("Símbolos padrão: \"X\" e \"O\"");
    printf("\n");
    printf("Escolha:");
    printf("\n");
    printf("1 - Alterar símbolos");
    printf("\n");
    printf("2 - Restaurar símbolos padrão");
    printf("\n");
    printf("0 - Voltar");
    printf("\n");
    printf("\n");

    printf("Resposta: ");
    scanf("%d", &decisao);
    printf("\n");
    printf("---------------------------------------------------------------");
	printf("\n");
	printf("\n");

    return decisao;

}

int configCPU(){
    int decisao = -1;

    printf("Nome atual do jogador: \"%s\"", jogo.cpu.nome);
    printf("\n");
    printf("Nome padrão do jogador: \"Jogador\"");
    printf("\n");
    printf("Escolha:");
    printf("\n");
    printf("1 - Alterar nome");
    printf("\n");
    printf("2 - Restaurar nome padrão");
    printf("\n");
    printf("0 - Voltar");
    printf("\n");
    printf("\n");

    printf("Resposta: ");
    scanf("%d", &decisao);
    printf("\n");
    printf("---------------------------------------------------------------");
	printf("\n");
	printf("\n");

    return decisao;

}

int configJogador(){
    int decisao = -1;

    printf("Nome atual dos jogadores: \"%s\" e \"%s\"", jogo.jogador.nome[0], jogo.jogador.nome[1]);
    printf("\n");
    printf("Nome padrão dos jogadores: \"Jogador 1\" e \"Jogador 2\"");
    printf("\n");
    printf("Escolha:");
    printf("\n");
    printf("1 - Alterar nome do Jogador 1");
    printf("\n");
    printf("2 - Alterar nome do Jogador 2");
    printf("\n");
    printf("3 - Restaurar nome padrão");
    printf("\n");
    printf("0 - Voltar");
    printf("\n");
    printf("\n");

    printf("Resposta: ");
    scanf("%d", &decisao);
    printf("\n");
    printf("---------------------------------------------------------------");
	printf("\n");
	printf("\n");

    return decisao;

}

void limparTela(){
    printf("\e[1;1H\e[2J"); // Escape ANSI para limpar a tela
}

void placarCPU(){

    char nomeCPU[3];
    strcpy(nomeCPU, "CPU");

    printf("|-----------------------------------------------------|\n");
    printf("|                        PLACAR                       |\n");
    printf("|-----------------|-----------------------------------|\n");
    printf("| %15s |      Vitórias: %d       Empates: %d |\n", jogo.cpu.nome, jogo.cpu.vitorias, jogo.cpu.empates);
    printf("|-----------------|-----------------------------------|\n");
    printf("| %15s |      Vitórias: %d       Empates: %d |\n", nomeCPU, jogo.cpu.derrotas, jogo.cpu.empates);
    printf("|-----------------|-----------------------------------|\n");
    printf("\n");
    printf("\n");

}

void placarJogador(){

    printf("|-----------------------------------------------------|\n");
    printf("|                        PLACAR                       |\n");
    printf("|-----------------|-----------------------------------|\n");
    printf("| %15s |      Vitórias: %d       Empates: %d |\n", jogo.jogador.nome[0], jogo.jogador.vitorias[0], jogo.jogador.empates);
    printf("|-----------------|-----------------------------------|\n");
    printf("| %15s |      Vitórias: %d       Empates: %d |\n", jogo.jogador.nome[1], jogo.jogador.vitorias[1], jogo.jogador.empates);
    printf("|-----------------|-----------------------------------|\n");
    printf("\n");
    printf("\n");

}

int tabuleiro(int decisao){

    printf("---------------------------------------------------------------");
    printf("\n");
    printf("\n");
    printf("                        RODADA %d", jogo.rodada);
    printf("\n");
    printf("\n");

    // Placar de Jogador x CPU
    if(decisao == 1){
        placarCPU();

        if(jogo.turno == 0){
            printf("                   Vez de %s", jogo.cpu.nome);
        }
        else if(jogo.turno == 1){
            printf("                   Vez da CPU");
        }

    }
    // Placar de Jogador x Jogador
    else if(decisao == 2){
        placarJogador();

        printf("                   Vez de %s", jogo.jogador.nome[jogo.turno]);

    }

    printf("\n");
    printf("\n");
    printf("\n");

	printf("             |     |               |    |    \n");
	printf("          %c  |  %c  |  %c         1  | 2  | 3  \n", jogo.tab[0][0], jogo.tab[0][1], jogo.tab[0][2]);
	printf("         ____|_____|____       ____|____|____\n");
	printf("             |     |               |    |    \n");
	printf("          %c  |  %c  |  %c         4  | 5  | 6  \n", jogo.tab[1][0], jogo.tab[1][1], jogo.tab[1][2]);
	printf("         ____|_____|____       ____|____|____\n");
	printf("             |     |               |    |    \n");
	printf("          %c  |  %c  |  %c         7  | 8  | 9  \n", jogo.tab[2][0], jogo.tab[2][1], jogo.tab[2][2]);
	printf("             |     |               |    |    \n");
	printf("\n");
	printf("\n");

	int casa = -1;
	printf("Resposta: ");
	scanf("%d", &casa);
	printf("\n");

	return casa;
}

void mensagemJogo(char mensagem[100]){
	printf("\n");
	printf("---------------------------------------------------------------");
	printf("\n");
	printf("\n");
	printf("%s", mensagem);
	printf("\n");
	printf("\n");
}

void mensagemMenu(char mensagem[100]){
	printf("%s", mensagem);
	printf("\n");
	printf("\n");
	printf("---------------------------------------------------------------");
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
		mensagemJogo("Erro! Não foi possível marcar o tabuleiro!");

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

    for(int i = 0; i < 3; i++){
        // Linhas
        if(jogo.tab[i][0] == simbolo && jogo.tab[i][1] == simbolo && jogo.tab[i][2] == simbolo){
            vitoria = true;
            break;
        }
        // Colunas
        else if(jogo.tab[0][i] == simbolo && jogo.tab[1][i] == simbolo && jogo.tab[2][i] == simbolo){
            vitoria = true;
            break;
        }
    }

    if(!vitoria){
        // Primeira Diagonal
        if(jogo.tab[0][0] == simbolo && jogo.tab[1][1] == simbolo && jogo.tab[2][2] == simbolo){
            vitoria = true;
        }
        // Segunda Diagonal
        else if(jogo.tab[0][2] == simbolo && jogo.tab[1][1] == simbolo && jogo.tab[2][0] == simbolo){
            vitoria = true;
        }
        // O simbolo passado não ganhou
        else {
            if(jogo.turno == 0){
                jogo.turno = 1;
            }
            else {
                jogo.turno = 0;
                jogo.rodada++;
            }
        }
    }

    return vitoria;
}

void restaurarSimb(){
    jogo.simbolos[0] = 'X';
    jogo.simbolos[1] = 'O';

}

void restaurarNomeCPU(){
    char nomePadrao[8] = {'J','o','g','a','d','o','r', '\0'};
    strcpy(jogo.cpu.nome, nomePadrao);

}

void restaurarNomeJogadores(){
    char nomePadrao[2][10] = {{'J','o','g','a','d','o','r', ' ', '1', '\0'}, {'J','o','g','a','d','o','r', ' ', '2', '\0'}};
    strcpy(jogo.jogador.nome[0], nomePadrao[0]);
    strcpy(jogo.jogador.nome[1], nomePadrao[1]);
}

void limparEntrada(){
    int extra = getchar();

    // Se não for '\n' ou EOF, significa que há caracteres extras no buffer
    if (extra != '\n' && extra != EOF) {
        // Limpa o buffer até encontrar '\n' ou EOF
        while (extra != '\n' && extra != EOF) {
            extra = getchar();
        }
    }
}

int main(){
	setlocale(LC_ALL, "C.UTF-8");
	bool repetirMenu = false;
	limparTela();

	do{

		int decisao = menu();

		// Validação da entrada do usuário
		if(decisao != 1 && decisao != 2 && decisao != 0){
			mensagemMenu("Não existe essa opção! Escolha uma opção existente!");
			limparEntrada();
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
                   mensagemMenu("Não existe essa opção! Escolha uma opção existente!");
                    limparEntrada();
                    repetirNovoJogo = true;
                }
                // Jogador x CPU:
                else if(decisao == 1){

                    limparTela();
                    bool repetirTab = false;
                    do{
                        int casa = tabuleiro(decisao);

                        // Verifica se a entrada di usuário foi válida
                        if(casa < 1 || casa > 9){
                            limparTela();
                            limparEntrada();
                            mensagemJogo("Não existe uma casa com esse número! Digite um número válido!");
                            repetirTab = true;
                            continue;
                        }
                        bool usando = verificarCasa(casa);
                        // Se a casa já estiver em uso
                        if(usando){
                            limparTela();
                            mensagemJogo("Erro! A casa selecionada já está sendo usada!");
                            repetirTab = true;
                            continue;
                        }
                        // Marcando a casa
                        else{
                            marcarTabuleiro(casa, jogo.simbolos[jogo.turno]);
                            limparTela();
                            bool vitoria = verificarVitoria(jogo.simbolos[jogo.turno]);
                            if(!vitoria){
                                repetirTab = true;
                                // Fazer a parte da CPU
                            }
                            else{
                                repetirTab = false;
                                // Fazer tela de vitoria
                                break;
                            }


                        }

                    } while(repetirTab);

                }
                // Jogador x Jogador
                else if(decisao == 2){

                    limparTela();
                    bool repetirTab = false;
                    do{
                        int casa = tabuleiro(decisao);

                        // Verifica se a entrada di usuário foi válida
                        if(casa < 1 || casa > 9){
                            limparTela();
                            limparEntrada();
                            mensagemJogo("Não existe uma casa com esse número! Digite um número válido!");
                            repetirTab = true;
                            continue;
                        }
                        bool usando = verificarCasa(casa);
                        // Se a casa já estiver em uso
                        if(usando){
                            limparTela();
                            mensagemJogo("Erro! A casa selecionada já está sendo usada!");
                            repetirTab = true;
                            continue;
                        }
                        // Marcando a casa
                        else{
                            marcarTabuleiro(casa, jogo.simbolos[jogo.turno]);
                            limparTela();
                            bool vitoria = verificarVitoria(jogo.simbolos[jogo.turno]);
                            if(!vitoria){
                                repetirTab = true;
                            }
                            else{
                                // Fazer tela de vitoria
                                repetirTab = false;
                                break;
                            }


                        }

                    } while(repetirTab);


                }
                // Voltar para o Menu principal
                else if(decisao == 0){
                    repetirMenu = true;
                    repetirNovoJogo = false;
                    limparTela();
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
                    mensagemMenu("Não existe essa opção! Escolha uma opção existente!");
                    limparEntrada();
                    repetirConfigGeral = true;
                }
                else if(decisao == 1){
                    decisao = -1;
                    bool repetirConfigSimb = false;

                    do{

                        decisao = configSimbolos();

                        // Validação da entrada do usuário
                        if(decisao != 1 && decisao != 2 && decisao != 0){
                            mensagemMenu("Não existe essa opção! Escolha uma opção existente!");
                            limparEntrada();
                            repetirConfigSimb = true;
                        }
                        // Alterar símbolos da partida
                        else if(decisao == 1){
                            bool repetirNovoSimb = false;
                            char novoSimbolo[2] = {' ', ' '};

                            do{


                                printf("Digite o símbolo 1: ");
                                limparEntrada();
                                scanf("%c", &novoSimbolo[0]);

                                printf("Digite o símbolo 2: ");
                                limparEntrada();
                                scanf("%c", &novoSimbolo[1]);
                                printf("\n");

                                limparEntrada();
                                ungetc('\n', stdin); // Devolve o \n para  buffer

                                if(novoSimbolo[0] == novoSimbolo[1]){
                                    printf("---------------------------------------------------------------");
                                    printf("\n");
                                    printf("\n");
                                    mensagemMenu("Erro! Os símbolos não podem ser iguais!");
                                    repetirNovoSimb = true;
                                    continue;

                                }
                                else{
                                    jogo.simbolos[0] = novoSimbolo[0];
                                    jogo.simbolos[1] = novoSimbolo[1];

                                    printf("Novos símbolos: \"%c\" e \"%c\"", novoSimbolo[0], novoSimbolo[1]);
                                    printf("\n");
                                    printf("\n");
                                    printf("---------------------------------------------------------------");
                                    printf("\n");
                                    printf("\n");
                                    mensagemMenu("Novos símbolos salvos com sucesso!");

                                    repetirConfigSimb = true;
                                    repetirNovoSimb = false;
                                    break;
                                }


                            } while(repetirNovoSimb);


                        }
                        // Restaurar símbolo padrão
                        else if(decisao == 2){
                            restaurarSimb();
                            mensagemMenu("Símbolos restaurados com sucesso!");

                            repetirConfigSimb = true;
                            continue;
                        }
                        // Voltar para menu de configurações
                        else if(decisao == 0){
                            repetirConfigGeral = true;
                            repetirConfigSimb = false;
                            break;
                        }

                    } while(repetirConfigSimb);

                }
                // Configurações de Jogador x CPU
                else if(decisao == 2){
                    decisao = -1;
                    bool repetirConfigCPU = false;

                    do{

                        decisao = configCPU();

                        // Validação da entrada do usuário
                        if(decisao != 1 && decisao != 2 && decisao != 0){
                            mensagemMenu("Não existe essa opção! Escolha uma opção existente!");
                            limparEntrada();
                            repetirConfigCPU = true;
                        }
                        // Alterar nome do Jogador x CPU
                        else if(decisao == 1){

                            char novoNome[tamNome];

                            printf("Digite o novo nome (máximo de 15 caracteres): \n");
                            limparEntrada();
                            fgets(novoNome, tamNome, stdin);
                            printf("\n");

                            size_t len = strlen(novoNome); // Pega o tamanho do nome digitado
                            //Removendo o \n do final do nome:
                            if (len > 0 && novoNome[len - 1] == '\n') {
                                novoNome[len - 1] = '\0';
                            }
                            else {
                                limparEntrada();
                            }

                            strcpy(jogo.cpu.nome, novoNome); // Salva o novo nome

                            printf("Novo nome: \"%s\"", novoNome);
                            printf("\n");
                            printf("\n");
                            printf("---------------------------------------------------------------");
                            printf("\n");
                            printf("\n");
                            mensagemMenu("Novo nome salvo com sucesso!");

                            repetirConfigCPU = true;


                        }
                        // Restaurar nome padrão
                        else if(decisao == 2){
                            restaurarNomeCPU();
                            mensagemMenu("Nome restaurado com sucesso!");

                            repetirConfigCPU = true;
                            continue;
                        }
                        // Voltar para menu de configurações
                        else if(decisao == 0){
                            repetirConfigGeral = true;
                            repetirConfigCPU = false;
                            break;
                        }

                    } while(repetirConfigCPU);


                }
                // Configuração Jogador x Jogador
                else if(decisao == 3){
                    decisao = -1;
                    bool repetirConfigJogador = false;

                    do{

                        decisao = configJogador();

                        // Validação da entrada do usuário
                        if(decisao != 1 && decisao != 2 && decisao != 3 && decisao != 0){
                            mensagemMenu("Não existe essa opção! Escolha uma opção existente!");
                            limparEntrada();
                            repetirConfigJogador = true;
                        }
                        // Alterar nome do Jogador 1
                        else if(decisao == 1 || decisao == 2){
                            int index = decisao - 1; // index do nome que está sendo alterado
                            // Usando operador ternário ao invés de if e else
                            int outroIndex = (index == 0) ? 1 : 0; // Se o index for zero, o outro index vai ser 1. Caso contrário, o outro index vai ser 0

                            bool repetirNovoNome = false;
                            do {
                                char novoNome[tamNome];

                                printf("Digite o novo nome (máximo de 15 caracteres): \n");
                                limparEntrada();
                                fgets(novoNome, tamNome, stdin);
                                printf("\n");

                                size_t len = strlen(novoNome); // Pega o tamanho do nome digitado
                                if (len > 0 && novoNome[len - 1] == '\n') {
                                    // Removendo o \n do final do nome:
                                    novoNome[len - 1] = '\0';
                                }
                                else {
                                    // Se o nome não tiver um \n no final, significa que o usuário ultrapassou o limite de
                                    // caracteres
                                    limparEntrada();
                                }

                                printf("Novo nome: \"%s\"", novoNome);
                                    printf("\n");
                                    printf("\n");
                                    printf("---------------------------------------------------------------");
                                    printf("\n");
                                    printf("\n");

                                // Verificando se os nomes são iguais
                                int comp = strcmp(novoNome, jogo.jogador.nome[outroIndex]);

                                if(comp == 0){
                                    // Se os nomes forem iguais
                                    mensagemMenu("Erro! Os nomes dos jogadores não podem ser iguais!");

                                    ungetc('\n', stdin); // Devolve o \n para  buffer
                                    repetirNovoNome = true;
                                    continue;
                                }
                                else{

                                    strcpy(jogo.jogador.nome[index], novoNome); // Salva o novo nome


                                    mensagemMenu("Novo nome salvo com sucesso!");

                                    repetirConfigJogador = true;
                                    repetirNovoNome = false;
                                    break;
                                }

                            } while(repetirNovoNome);




                        }
                        // Restaurar nomes padrão
                        else if(decisao == 3){
                            restaurarNomeJogadores();
                            mensagemMenu("Nomes restaurados com sucesso!");

                            repetirConfigJogador = true;
                            continue;
                        }
                        // Voltar para menu de configurações
                        else if(decisao == 0){
                            repetirConfigGeral = true;
                            repetirConfigJogador = false;
                            break;
                        }

                    } while(repetirConfigJogador);

                }
                // Voltar para o Menu principal
                else if(decisao == 0){
                    repetirMenu = true;
                    repetirConfigGeral = false;
                    limparTela();
                    break;
                }

            } while(repetirConfigGeral);

		}
		else if(decisao == 0){
			printf("Encerrando o programa...");
			printf("\n");
			printf("\n");
            printf("---------------------------------------------------------------");
            printf("\n");
			repetirMenu = false;
		}

	} while(repetirMenu);

	return 0;

}
