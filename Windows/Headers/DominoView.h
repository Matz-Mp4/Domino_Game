#ifndef DOMINOVIEW_H_
#define DOMINOVIEW_H_

#include "DominoModel.h"



void mostrarCarregamento (char palavra[], float velocidade, char imagem[]);  

void mostrarMensTRANSF(tipo_arquivo arqSalvo[]);

void entraArqSalvos(tipo_arquivo arqSalvo[]);

void imagem();

void menu();

char menuJogo();

char opcao();

void exibirPeca(tipo_peca dominoAux[]);

int entrarJogador();

void visualizarPeca(tipo_peca dominoAux[], tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void mostrarMesa(tipo_mesa *tabuleiro, int modo);

void mostrarMesa2();

int moverTela(int quant);

void limparInterface();

void hubJogador(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_arquivo arqSalvo[], tipo_peca bot[]);

void jogodeDois(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_arquivo arqSalvo[]);

void alocarPeca(tipo_jogo *domino,tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro);

void mostrarRegras();

void mostrarNome();

void mostrarMenu();

void mostrarErro();

void mostrarJ1();

void mostrarJ2();

void mostrarArquivos(tipo_arquivo arqSalvo[]);

void mostrarSave();

char escolherDirecao();

void monstrarMensBot();

void jogoAUTO(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_peca jogador1[], tipo_peca bot[], tipo_peca monte[], tipo_arquivo arqSalvo[]);





#endif