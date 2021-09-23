#include "DominoData.h"

void salvarArquivo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro, tipo_peca monte[], tipo_arquivo arqSalvo[]){

    int n;

    printf("\nDigite em que espaco da memoria voce quer salvar esse arquivo: ");
    scanf("%d", &n);
    while(n <=0 || n > 5){

        printf("\nOpps! Parece que voce digitou algo errado!");
        printf("\nDigite em que espaco da memoria voce quer salvar esse arquivo: ");
        scanf("%d", &n);
        system("clear");
    }

    n--;

    printf("\nComo o arquivo salvo vai se chamar: ");
    scanf("%s", arqSalvo[n].nomes);
    flush_in();
    arqSalvo[n].status = 'S';


    arqSalvo[n].arq = fopen(arqSalvo[n].nomes, "wb");

    if(arqSalvo[n].arq == NULL){
        printf("Impossivel criar o arquivo %s\n", arqSalvo[n].nomes);
        exit(1);
    }

    fwrite(jogador1, sizeof(tipo_peca), 21, arqSalvo[n].arq);

    fwrite(jogador2, sizeof(tipo_peca), 21, arqSalvo[n].arq);

    fwrite(monte, sizeof(tipo_peca), 14, arqSalvo[n].arq);

    fwrite(tabuleiro, sizeof(tipo_mesa), 1, arqSalvo[n].arq);

    fwrite(domino , sizeof(tipo_jogo), 1, arqSalvo[n].arq);

    fclose(arqSalvo[n].arq);

}

void carregarArquivo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro, tipo_peca monte[], tipo_arquivo arqSalvo[]){

    int n;

    printf("\nDigite qual o numero do arquivo salvado: ");
    scanf("%d", &n);

    while(n <=0 || n > 5){

        printf("\nOpps! Parece que voce digitou algo errado!");
        printf("\nDigite qual o numero do arquivo salvado: ");
        scanf("%d", &n);
        system("clear");
    }
    n--;
  

    arqSalvo[n].arq = fopen(arqSalvo[n].nomes, "rb");

    if(arqSalvo[n].arq == NULL){
        printf("Impossivel criar o arquivo %s\n", arqSalvo[n].nomes);
        exit(1);
    }

    fread(jogador1, sizeof(tipo_peca), 21, arqSalvo[n].arq);
    fread(jogador2, sizeof(tipo_peca), 21, arqSalvo[n].arq);
    fread(monte, sizeof(tipo_peca), 14, arqSalvo[n].arq);
    fread(tabuleiro, sizeof(tipo_mesa), 1, arqSalvo[n].arq);
    fread(domino, sizeof(tipo_jogo), 1, arqSalvo[n].arq);


    fclose(arqSalvo[n].arq);


}

void resetarArq(tipo_arquivo arqSalvo[]){

    tipo_jogo dominoAux;
    tipo_peca jogAux1[21], jogAux2[21], monteAux[14];
    tipo_mesa tabuleiroAux;

    for(int i = 0; i < 21; i++) {
        jogAux1[i].status = 'L';
        jogAux2[i].status = 'L';

        jogAux1[i].p1 = -1;
        jogAux1[i].p2 = -1;

        jogAux2[i].p1 = -1;
        jogAux2[i].p2 = -1;

        if(i < 14){
            monteAux[i].status = 'C';
            monteAux[i].p1 = -1;
            monteAux[i].p2 = -1;
        }

    }

    dominoAux.j_maiorP1 = -1;
    dominoAux.j_maiorP2 = -1;
    dominoAux.jogou = -1;
    dominoAux.pontosJ1 = -1;
    dominoAux.pontosJ2 = -1;
    dominoAux.quantJ1= -1;
    dominoAux.quantJ2= -1;
    dominoAux.rodadaVez= -1;

    for(int j = 0; j < 100; j++){
        tabuleiroAux.mapa[j] = -1;
    }

    tabuleiroAux.ext_dir = -1;
    tabuleiroAux.ext_esq = -1;
    tabuleiroAux.h_dir = -1;
    tabuleiroAux.h_esq = -1;

    int n;
    char  ultimaLetra;

    printf("\nDigite qual o numero do arquivo salvado: ");
    scanf("%d", &n);

    while(n <= 0 || n > 5){

        printf("\nOpps! Parece que voce digitou algo errado!");
        printf("\nDigite qual o numero do arquivo salvado: ");
        scanf("%d", &n);
        system("clear");
    }
    n--;

    char validador[30];
    strcpy(validador, arqSalvo[n].nomes);    

    if(arqSalvo[n].status == 'L'){
        printf("\n\t\tVoce so pode resetar arquivo salvo");

    }else{                                         
        printf("\n\t Escreva  este nome de arquivo %s: ", arqSalvo[n].nomes);
        scanf("%s", arqSalvo[n].nomes);
        flush_in();
        //Converte um int em char   
        

        while((strcmp(arqSalvo[n].nomes, validador)) != 0){

            printf("\n\t Escreva  este nome de arquivo %s: ",validador);
            scanf("%s", arqSalvo[n].nomes);
            flush_in();
            system("cls");
        }
        
        arqSalvo[n].status = 'R';

        arqSalvo[n].arq= fopen(arqSalvo[n].nomes, "wb");

        if(arqSalvo[n].arq == NULL){
            printf("Impossivel criar o arquivo %s\n", arqSalvo[n].nomes);
            exit(1);
        }

        fwrite(jogAux1, sizeof(tipo_peca), 21, arqSalvo[n].arq);

        fwrite(jogAux2, sizeof(tipo_peca), 21, arqSalvo[n].arq);

        fwrite(monteAux, sizeof(tipo_peca), 14, arqSalvo[n].arq);

        fwrite(&tabuleiroAux, sizeof(tipo_mesa), 1, arqSalvo[n].arq);

        fwrite(&dominoAux , sizeof(tipo_jogo), 1, arqSalvo[n].arq);


        fclose(arqSalvo[n].arq);

    }
}
