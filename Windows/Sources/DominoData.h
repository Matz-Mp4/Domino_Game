#ifndef DOMINODATA_H_
#define DOMINODATA_H_


#include "DominoModel.h"

void salvarArquivo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro, tipo_peca monte[], tipo_arquivo arqSalvo[]);

void carregarArquivo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro, tipo_peca monte[], tipo_arquivo arqSalvo[]);

void resetarArq(tipo_arquivo arqSalvo[]);

#endif