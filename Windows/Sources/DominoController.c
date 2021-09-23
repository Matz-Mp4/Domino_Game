#include "DominoController.h"

//menu de comando principal
void controller() {
    //declaração das variáveis
    tipo_jogo domino;
    tipo_mesa tabuleiro;

    

    tipo_peca monte[14];
    tipo_peca jogador1[21];
    tipo_peca jogador2[21];
    tipo_peca dominoAux[28];
    tipo_peca bot[21];

    tipo_arquivo arqSalvo[5];

    for (int i = 0; i < 5; i++){
        arqSalvo[i].status = 'L';
        strcpy(arqSalvo[i].nomes, " ");
    }

    bool veri= true;
    int opcao, tamanho = 28;
    


    inicializarPeca(dominoAux, &domino, &tabuleiro, arqSalvo);

    do {
        menu();

        printf("\n\n\tDigite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao){

            case 1: //começa o jogo
                hubJogador(dominoAux, &domino, &tabuleiro, jogador1, jogador2, monte, arqSalvo, bot);
                limparInterface();
                break;

            case 2: // embaralha peça
                embaralhar(dominoAux, tamanho);
                limparInterface();
                
                break;

            case 3: //organiza peça
                desembaralhar(dominoAux);
                limparInterface();
                break;

            case 4://mostra peça
                exibirPeca(dominoAux);
                printf("\n");
                limparInterface();
                
                break;
                
            case 5://Regras do jogo
                mostrarRegras();
                limparInterface();
                break;

            case 6:  //sai do terminal
                veri = false;
                break;
            case 7: 
                mostrarMensTRANSF(arqSalvo);
                mostrarCarregamento("T R A N S F E R I D N O ", 0.01, ".."); 
            break;

            default: //digitou um número invalido
                mostrarErro();
                
                printf("\nOpps!!! Voce deve ter digitado algo errado!");

                
                limparInterface();
            
        }
    }while(veri == true);
}