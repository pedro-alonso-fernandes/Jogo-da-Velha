# Jogo da Velha - Trabalho Final

Este repositório contém a implementação de um jogo da velha (Tic-Tac-Toe) em linguagem C, desenvolvido como trabalho final da disciplina **Introdução à Ciência da Computação**. O projeto inclui um **executável pronto para Windows (**``**) e Linux (**``**)**, permitindo que o usuário jogue sem precisar compilar o código-fonte.

## 📌 Objetivo do Projeto

O objetivo do trabalho é demonstrar o conhecimento adquirido em programação estruturada, manipulação de variáveis, estruturas de controle e interação com o usuário via terminal. O jogo foi desenvolvido para oferecer uma interface simples e intuitiva para dois jogadores ou contra a CPU.

## 🛠️ Funcionalidades

- **Modos de Jogo:**
  - Jogador vs Jogador
  - Jogador vs CPU
- **Sistema de Placar:**
  - Contabiliza vitórias e empates.
- **Configurações Personalizadas:**
  - Alteração de símbolos dos jogadores.
  - Modificação de nomes dos jogadores.
- **Verificação automática de vitória e empate.**
- **Interface em terminal amigável e limpa.**

## 📜 Como Jogar

1. **Baixe o executável compatível com seu sistema:**

   - Para **Windows**, utilize `jogo.exe`.
   - Para **Linux**, utilize `./jogo`.

2. **Execute o jogo:**

   - No **Windows**, basta dar um duplo clique no `jogo.exe` ou abrir o terminal e digitar:
     ```sh
     jogo.exe
     ```
   - No **Linux**, abra o terminal na pasta do jogo e execute:
     ```sh
     chmod +x jogo
     ./jogo
     ```

## 🎮 Funcionamento do Programa

### 1️⃣ Menu Principal

Ao iniciar o jogo, o usuário verá o seguinte menu:

```
------------------------Jogo da Velha--------------------------

Escolha:
1 - Novo jogo
2 - Configurações
0 - Encerrar o programa

Resposta: _
```

### 2️⃣ Opção: Novo Jogo

Caso o jogador escolha `1`, ele verá o seguinte menu para selecionar o modo de jogo:

```
Escolha:
1 - Jogador x CPU
2 - Jogador x Jogador
0 - Voltar

Resposta: _
```

- No modo **Jogador x CPU**, o jogador joga contra a máquina, que faz jogadas aleatórias.
- No modo **Jogador x Jogador**, dois jogadores alternam as jogadas no tabuleiro.
- O jogo exibe o tabuleiro a cada rodada e pede ao jogador que escolha uma casa para marcar.

### 3️⃣ Opção: Configurações

Caso o jogador escolha `2` no menu principal, ele verá o menu de configurações:

```
Escolha:
1 - Configuração de símbolos da partida
2 - Configuração de Jogador x CPU
3 - Configuração de Jogador x Jogador
0 - Voltar

Resposta: _
```

#### Alteração de Símbolos

Permite escolher novos símbolos para os jogadores (padrão: `X` e `O`).

#### Configuração de Nomes

- No modo **Jogador x CPU**, permite alterar o nome do jogador.
- No modo **Jogador x Jogador**, permite alterar os nomes dos dois jogadores.

### 4️⃣ Exibição do Tabuleiro

Durante o jogo, o tabuleiro é exibido da seguinte forma:

```
Rodada 1

   |   |   
 X | O |   
___|___|___
   |   |   
 O | X | X 
___|___|___
   |   |   
   |   | O 
   |   |   
```

Os jogadores alternam jogadas até que alguém vença ou ocorra um empate.

### 5️⃣ Verificação de Vitória ou Empate

- Caso um jogador alinhe três símbolos, a seguinte mensagem será exibida:
  ```
  PARABÉNS!
  Jogador X venceu!
  ```
- Se todas as casas forem ocupadas sem um vencedor, o jogo exibe:
  ```
  EMPATE!
  ```

Após uma partida, o jogador pode escolher entre **jogar novamente** ou **voltar ao menu principal**.

## 📖 Estrutura do Código

### 1️⃣ Estruturas Utilizadas

```c
typedef struct {
    int vitorias[2];
    int empates;
    char nome[2][15];
} Jogador;

typedef struct {
    int vitorias;
    int empates;
    int derrotas;
    char nome[15];
} CPU;

typedef struct {
    char tab[3][3];
    char simbolos[2];
    int rodada;
    int turno;
    CPU cpu;
    Jogador jogador;
} Jogo;
```

### 2️⃣ Funções Principais

- `menu()` → Exibe o menu principal.
- `novoJogo()` → Define o modo de jogo.
- `tabuleiro()` → Atualiza e exibe o tabuleiro.
- `verificarVitoria()` → Checa se há um vencedor.
- `telaVitoria()` → Exibe a mensagem de vitória.
- `telaEmpate()` → Exibe a mensagem de empate.
- `marcarTabuleiro()` → Registra a jogada.
- `jogadaCPU()` → Define jogadas automáticas da CPU.
- `reiniciarJogo()` → Reseta os dados para nova partida.

## 📌 Conclusão

Este projeto apresenta uma implementação funcional e didática do jogo da velha, com foco na aplicação de conceitos fundamentais da programação em C. O código está estruturado de forma modular e organizada, permitindo futuras expansões.

🎓 Trabalho final da disciplina **Introdução à Ciência da Computação**. Desenvolvido por Pedro Alonso, Milena Boa, Pedro Henrique e Sávio Thomaz.

