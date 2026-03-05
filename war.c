#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
// --- Constantes Globais ---
#define MAX_TERRITORIOS 10
#define MAX_NOME 50

// --- Estrutura de Dados ---
typedef struct {
    char nome[MAX_NOME];
    char cor[20];
    int tropas;
} Territorio;
// --- Protótipos das Funções ---
// --- Protótipos das Funções ---
Territorio* alocarMapa();
void inicializarTerritorios(Territorio *mapa);
void exibirMapa(const Territorio *mapa);
void liberarMemoria(Territorio *mapa);

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Alocação Dinâmica)
    Territorio *mapa = alocarMapa();
    
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // 2. Preenche os dados iniciais dos territórios
    inicializarTerritorios(mapa);

    // 3. Exibe o mapa para o jogador
    printf("--- BEM-VINDO AO WAR ESTRUTURADO ---\n");
    exibirMapa(mapa);

    // 4. Limpeza (Liberação de memória)
    liberarMemoria(mapa);
    
    return 0;
}

// --- Implementação das Funções ---
// Função que reserva a memória usando calloc
Territorio* alocarMapa() {
    return (Territorio*) calloc(MAX_TERRITORIOS, sizeof(Territorio));
}

// Função que preenche os nomes (usa ponteiros)
void inicializarTerritorios(Territorio *mapa) {
    // Exemplo de preenchimento do primeiro território
    sprintf(mapa[0].nome, "Brasil");
    sprintf(mapa[0].cor, "Verde");
    mapa[0].tropas = 5;

    // Exemplo de preenchimento do segundo território
    sprintf(mapa[1].nome, "Chile");
    sprintf(mapa[1].cor, "Vermelho");
    mapa[1].tropas = 3;
}

// Função que mostra os dados na tela (usa const para segurança)
void exibirMapa(const Territorio *mapa) {
    for(int i = 0; i < 2; i++) {
        printf("Territorio: %s | Exercito: %s | Tropas: %d\n", 
                mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// Função que libera a memória (free)
void liberarMemoria(Territorio *mapa) {
    free(mapa);
    printf("\nSistema: Memoria liberada com sucesso.\n");
}