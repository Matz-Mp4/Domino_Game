#ifndef DOMINOMODEL_H_
#define DOMINOMODEL_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>


//Essas variaveis representam uma referencia para a locomação das peças na mesa
#define posicaoI 50
#define posicaoF 51



/*  p1 e p2 representa metade da peca 

    maiorP representa a maior peca 

    tipoP = 'D' dobrinha / 'N' "normal"


    status representa a disponibilidade 
    de compra da peca

    h_esq e h_dir representa a quantidade de colunas 
    que o jogador que mover  mapa[50] da mesa para 
    visualicao das pecas 

    -------------------(LEGENDA)------------------
      * maiorP = 1 = representa que essa peca é a maior peca DOBRADA do jogador 
                 2 = representa que essa peca é a maior peca NORMAL do jogador  
                 0 = representa as demais pecas
      
      * status = C = peca disponivel para compra
                 V = peca do monte foi comprada ("Vendida")
                 U = a peca esta sendo usada  
                 M = peca do jogador foi colocada na mesa
                 L  = acontece quando a peça não está disponivel para o jogador | espaço livre

    ----------------------------------------------
*/
typedef struct arquivo{
    
    char status;//'\0'
    int quant;
    FILE *arq;
    char nomes[30];

}tipo_arquivo;


typedef struct peca{ 
    int p1;
    int p2;
    int maiorP;
    char tipoP;
    char status;

} tipo_peca;

typedef struct mesa{
    int mapa[100]; 
    //Escopo de visualizacao
    int h_esq;
    int h_dir;
 

    // essas variáveis vão representar o valor das pontas do tabuleiro
    int ext_esq ;
    int ext_dir ; 

} tipo_mesa;

typedef struct jogo{
    int pontosJ1;
    int pontosJ2;

    // Maior peca do jogo 
    // nao dos jogadores

    int j_maiorP1;
    int j_maiorP2;

    int jogaPrimeiro;
    int rodadaVez;

    int quantJ1;
    int quantJ2;

    int jogou;
    
} tipo_jogo;




void  delay(float delay1) ;

void carregarTela(float tempo);

void jogarPecaBOT(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_mesa *tabuleiro, int *k, int *cont_1, int *cont_2);

void clear();

void inicializarPeca(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_arquivo *arqSalvo);

void desembaralhar(tipo_peca dominoAux[]);

void embaralhar(tipo_peca dominoAux[], int array_tamanho);

void distribuirpecas(tipo_peca dominoAux[], tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void flush_in();

void trocarPeca(int x, tipo_peca dominoAux[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void definirTipo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void definirMaior(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

void definirStatus(tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]);

int acharMaior(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[] );

void verificarJog1(tipo_jogo *domino, tipo_peca jogador1[], tipo_mesa *tabuleiro, char escolha, int peca);

void verificarJog2(tipo_jogo *domino, tipo_peca jogador2[], tipo_mesa *tabuleiro, char escolha, int peca);

void comprarPeca(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_mesa *tabuleiro, int *k, int *cont_1, int *cont_2);

int verificarCompra(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro);

void contarPontos(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[]);

void inicializaMesa(tipo_mesa *tabuleiro);




#endif

