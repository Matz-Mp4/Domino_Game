#include "DominoModel.h"

void inicializarPeca(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_arquivo *arqSalvo)
{
    int i;
    int valorp1 = 0;
    int valorp2 = 0;
    int reset = 0;

    //fim da declara��o de vari�veis e struct

    //fun��o de inicializa��o das pe�as (REQ01)

    for (i = 0; i < 28; i++)
    {
        if (i >= 7 && i < 13)
            valorp1 = 1;
        if (i >= 13 && i < 18)
            valorp1 = 2;
        if (i >= 18 && i < 22)
            valorp1 = 3;
        if (i >= 22 && i < 25)
            valorp1 = 4;
        if (i >= 25 && i < 27)
            valorp1 = 5;
        if (i == 27)
            valorp1 = 6;
        dominoAux[i].p1 = valorp1;
    }

    for (i = 0; i < 28; i++)
    {
        dominoAux[i].p2 = valorp2;
        valorp2++;

        if (i == 6)
        {
            reset = 1;
            valorp2 = reset;
        }
        if (i == 12)
        {
            reset = 2;
            valorp2 = reset;
        }
        if (i == 17)
        {
            reset = 3;
            valorp2 = reset;
        }
        if (i == 21)
        {
            reset = 4;
            valorp2 = reset;
        }
        if (i == 24)
        {
            reset = 5;
            valorp2 = reset;
        }
        if (i == 26)
        {
            reset = 6;
            valorp2 = reset;
        }
    }

    
}
//Organiza as peças
void desembaralhar(tipo_peca dominoAux[])
{

    int i;
    int valorp1 = 0;
    int valorp2 = 0;
    int reset = 0;

    //fim da declaração de variáveis e struct

    //função de inicialização das peças (REQ01)

    for (i = 0; i < 28; i++)
    {
        if (i >= 7 && i < 13)
            valorp1 = 1;
        if (i >= 13 && i < 18)
            valorp1 = 2;
        if (i >= 18 && i < 22)
            valorp1 = 3;
        if (i >= 22 && i < 25)
            valorp1 = 4;
        if (i >= 25 && i < 27)
            valorp1 = 5;
        if (i == 27)
            valorp1 = 6;
        dominoAux[i].p1 = valorp1;
    }

    for (i = 0; i < 28; i++)
    {
        dominoAux[i].p2 = valorp2;
        valorp2++;

        if (i == 6)
        {
            reset = 1;
            valorp2 = reset;
        }
        if (i == 12)
        {
            reset = 2;
            valorp2 = reset;
        }
        if (i == 17)
        {
            reset = 3;
            valorp2 = reset;
        }
        if (i == 21)
        {
            reset = 4;
            valorp2 = reset;
        }
        if (i == 24)
        {
            reset = 5;
            valorp2 = reset;
        }
        if (i == 26)
        {
            reset = 6;
            valorp2 = reset;
        }
    }
}
//Embaralha as peças
void embaralhar(tipo_peca dominoAux[], int array_tamanho)
{
    srand(time(NULL)); //randomiza as peças
    int r, troca;

    for (int i = array_tamanho - 1; i >0; i--)
    {
        r = rand() % array_tamanho;
        troca = dominoAux[i].p1;
        dominoAux[i].p1 = dominoAux[r].p1;
        dominoAux[r].p1 = troca;
        troca = dominoAux[i].p2;
        dominoAux[i].p2 = dominoAux[r].p2;
        dominoAux[r].p2 = troca;
    }
}
//distribui as peças do jogador 1, jogador 2 e colocar o resto no monte
void distribuirpecas(tipo_peca dominoAux[], tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{
    int tam = 28;  
    embaralhar(dominoAux, tam);
    //um jogador pode comprar ate 14 = 7 + 14 = 21, porem usamos 28 por segurança
    int i, k,  tamanho = 28;

     for (i = 0; i < 7; i++)
    {
        //distribuição de 7 peças embaralhadas para o jogador 1
        
        
        jogador1[i].p1 =  dominoAux[i].p1;
    
        jogador1[i].p2 =  dominoAux[i].p2;
            
        
    }

    for (i = 7, k = 0; i < 14, k < 7; i++, k++)
    {
        //distribuição de 7 peças embaralhadas para o jogador 2

        
        jogador2[k].p1 =  dominoAux[i].p1;
        
        jogador2[k].p2 = dominoAux[i].p2;

    }

    for (i = 14, k = 0; i < 28, k < 14; i++, k++)
    {
        
        monte[k].p1 = dominoAux[i].p1;
        
        monte[k].p2 = dominoAux[i].p2;
    }

    

}
//limpar o buffer 
void flush_in()
{
    char op;

    while ((op = fgetc(stdin)) != EOF && op != '\n')
    {
    };
}

void trocarPeca(int x, tipo_peca dominoAux[], tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{

    int temp, i;

    temp = dominoAux[x].p1;
    dominoAux[x].p1 = dominoAux[x].p2;
    dominoAux[x].p2 = temp;
}
    
// definir se a peça é dobra ou não
void definirTipo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca *monte){

    int i = 0, j;

    for (i = 0; i < 21; i++){
        
        if(jogador1[i].p1 != -1 && jogador1[i].p2 != -1){

            if (jogador1[i].p1 == jogador1[i].p2 ){

                jogador1[i].tipoP = 'D';
            }else{

                jogador1[i].tipoP = 'N';
            }
        }

        if(jogador2[i].p1 != -1 && jogador2[i].p2 != -1){

            if (jogador2[i].p1 == jogador2[i].p2){

                jogador2[i].tipoP = 'D';
            }else{

                jogador2[i].tipoP = 'N';
            }
        }

    }

    for(j = 0; j < 14; j++){

         
        if (monte[j].p1 == monte[j].p2 ){

            monte[j].tipoP = 'D';
        }else{

            monte[j].tipoP = 'N';
        }
    }
}
// define a maior peça de um dos jogadores 
void definirMaior(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]){
    int i, j;
    //mDobra1 <-- maior dobra do jogador 1 || mDobra2 <-- Maior dobra do jogador 2
    //mDobra1 e mDobra2 nao possui dois valores pq sao pecas iguais
    //mNormal1 <-- maior normal do jogador 1 || mNormal2 <-- Maior normal do jogador 2                
      

    int mDobra1 = -1, mDobra2 = -1;
    int mNormal1_p1 = -1, mNormal1_p2 = -1, mNormal2_p1 = -1, mNormal2_p2 = -1;
    
    //aux tem o p1 do mNormal de cada jogador > do que o p2
    int aux1_p1 = -1, aux1_p2 = -1, aux2_p1 = -1, aux2_p2 = -1;  
    
    //Buscando a maior peca dobrada de ambos os jogadores 

    definirTipo(domino, jogador1, jogador2, monte);

    for (i = 0; i < 21; i++){

        if(jogador1[i].tipoP == 'D'){   

            if (mDobra1 < jogador1[i].p1){
                
                mDobra1 = jogador1[i].p1; 
            }
        }
        
        if(jogador2[i].tipoP == 'D'){   

            if (mDobra2 < jogador2[i].p1){
                
                mDobra2 = jogador2[i].p1; 
            }
        }
    }
        
    for (i = 0; i < 21; i++){
        //se for peca normal
        if(jogador1[i].tipoP == 'N'){
            //==========================jogador_1===================================
            
            //comparação entre a peça 1 do jogador 1 e a peça 2 do jogador 2
            if(jogador1[i].p1 > jogador1[i].p2){        
                
                if(mNormal1_p1 < jogador1[i].p1){
                    mNormal1_p1 = jogador1[i].p1;
                    mNormal1_p2 = jogador1[i].p2;
                    
                        aux1_p1 = jogador1[i].p1;
                        aux1_p2 = jogador1[i].p2;
                    
                // se o p1 da maior peça armazenada for igual ao valor do p1 do jogador 1
                // ex = 5|1 e  5|2
                } else if(mNormal1_p1 == jogador1[i].p1){
                    
                    if(mNormal1_p2 < jogador1[i].p2){
                        mNormal1_p1 = jogador1[i].p1;
                        mNormal1_p2 = jogador1[i].p2;
                        
                        aux1_p1 = jogador1[i].p1;
                        aux1_p2 = jogador1[i].p2;
                    }
                }
            //comparação entre a peça 2 do jogador 1 e a p1 do jogador 2
            } else if(jogador1[i].p2 > jogador1[i].p1){
            
                if(mNormal1_p1 < jogador1[i].p2){
                    mNormal1_p1 = jogador1[i].p2;
                    mNormal1_p2 = jogador1[i].p1;

                    aux1_p1 = jogador1[i].p2;
                    aux1_p2 = jogador1[i].p1;
    
                // se o maior peça normal tiver o mesmo valor do p2 do jogador 1 acontece:
                } else if(mNormal1_p1 == jogador1[i].p2){

                    // se a maior normal p2 do jogador 1 for menor que uma nova peça do jogador 1, ele irá substituir
                    if(mNormal1_p2 < jogador1[i].p1){
                        mNormal1_p1 = jogador1[i].p2;
                        mNormal1_p2 = jogador1[i].p1;

                        aux1_p1 = jogador1[i].p2;
                        aux1_p2 = jogador1[i].p1;
                    }
                }
            }
        }
        //==========================jogador_2===================================
        if(jogador2[i].tipoP == 'N'){
            //comparação entre a peça 1 do jogador 1 e a peça 2 do jogador 2
            if(jogador2[i].p1 > jogador2[i].p2){        
                
                if(mNormal2_p1 < jogador2[i].p1){
                    mNormal2_p1 = jogador2[i].p1;
                    mNormal2_p2 = jogador2[i].p2;

                    aux2_p1 = jogador2[i].p1;
                    aux2_p2 = jogador2[i].p2;
                // se o p1 da maior peça armazenada for igual ao valor do p1 do jogador 1
                // ex = 5|1 e  5|2
                } else if(mNormal2_p1 == jogador2[i].p1){
                    
                    if(mNormal2_p2 < jogador2[i].p2){
                        mNormal2_p1 = jogador2[i].p1;
                        mNormal2_p2 = jogador2[i].p2;

                        aux2_p1 = jogador2[i].p1;
                        aux2_p2 = jogador2[i].p2;
                    }
                }
            //comparação entre a peça 2 do jogador 1 e a p1 do jogador 2
            } else if(jogador2[i].p2 > jogador2[i].p1){
            
                if(mNormal2_p1 < jogador2[i].p2){
                    mNormal2_p1 = jogador2[i].p2;
                    mNormal2_p2 = jogador2[i].p1;

                    aux2_p1 = jogador2[i].p2;
                    aux2_p2 = jogador2[i].p1;

                    
                // se o maior peça normal tiver o mesmo valor do p2 do jogador 1 acont  ece:
                } else if(mNormal2_p1 == jogador2[i].p2){
                    // se a maior normal p2 do jogador 1 for menor que uma nova peça do jogador 1, ele irá substituir
                    if(mNormal2_p2 < jogador2[i].p1){
                        mNormal2_p1 = jogador2[i].p2;
                        mNormal2_p2 = jogador2[i].p1;

                        aux2_p1 = jogador2[i].p2;
                        aux2_p2 = jogador2[i].p1;

                    }
                }
            }
        }

    }
    //Atulizando os status de maior peca do struct
    //Peca dobrada
    for (i = 0; i < 21; i++){
        
        if((mDobra1 == jogador1[i].p1) && (jogador1[i].tipoP == 'D')){
            jogador1[i].maiorP = 1;

        } else if(jogador1[i].tipoP == 'D'){
            jogador1[i].maiorP = 0;

        }

        if((mDobra2 == jogador2[i].p1) && (jogador2[i].tipoP == 'D')){
            jogador2[i].maiorP = 1;

        } else if(jogador2[i].tipoP == 'D'){
            jogador2[i].maiorP = 0;

        }
    }
        
    for(i = 0; i < 21; i++){
         
        if((((mNormal1_p1 == jogador1[i].p1) && (mNormal1_p2 == jogador1[i].p2)) || ((mNormal1_p1 == jogador1[i].p2) && (mNormal1_p2 == jogador1[i].p1))) && (jogador1[i].tipoP == 'N')){

             jogador1[i].maiorP = 2; 
         } else if(jogador1[i].tipoP == 'N'){    
             
            jogador1[i].maiorP = 0;  
         }

        if(((mNormal2_p1 == jogador2[i].p1) && (mNormal2_p2 == jogador2[i].p2) || (mNormal2_p1 == jogador2[i].p2) && (mNormal2_p2 == jogador2[i].p1)) && (jogador2[i].tipoP == 'N')){
                
            jogador2[i].maiorP = 2; 
         } else if(jogador2[i].tipoP == 'N'){    
             
            jogador2[i].maiorP = 0;  
         }
    }   

    //Se tiver 2 pecas dobradas
    if(mDobra1 != -1 && mDobra2 != -1){
        
        //neste caso, o jogador 1 será o primeiro a jogar
        if(mDobra1 > mDobra2){
            domino->j_maiorP1 = mDobra1;
            domino->j_maiorP2 = mDobra1;
            domino->jogaPrimeiro = 1;

        // ja neste caso, o jogador 2 será o primeiro a jogar    
        } else if( mDobra2 > mDobra1){
            domino->j_maiorP1 = mDobra2;
            domino->j_maiorP2 = mDobra2;
            domino->jogaPrimeiro = 2;
        }

    //jogador 1 irá começar, pois ele é o único com dobra
    } else if(mDobra1 != -1 && mDobra2 == -1){ 
        domino->j_maiorP1 = mDobra1;
        domino->j_maiorP2 = mDobra1;
        domino->jogaPrimeiro = 1;
    
    //jogador 2 irá começar, pois ele é o único com dobra    
    } else if (mDobra1 == -1 && mDobra2 != -1){
        domino->j_maiorP1 = mDobra2;
        domino->j_maiorP2 = mDobra2;
        domino->jogaPrimeiro = 2;
    
    //jogador 1 e 2 apenas estão com peças normais
    } else if(mDobra1 == -1 && mDobra2 == -1){
        
        if(aux1_p1 > aux2_p1){
            domino->j_maiorP1 = aux1_p1;
            domino->j_maiorP2 = aux1_p2;
            domino->jogaPrimeiro = 1;

        }else if(aux2_p1 > aux1_p1){
            domino->j_maiorP1 = aux2_p1;
            domino->j_maiorP2 = aux2_p2;
            domino->jogaPrimeiro = 2;
        }
    }

}

void definirStatus(tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[]){

    for (int i = 0; i < 7; i++){
        jogador1[i].status = 'U';
        jogador2[i].status = 'U';
    }

    for (int i = 0; i < 14; i++){
        monte[i].status = 'C';
    }

    for(int i = 7; i < 21; i++){
        jogador1[i].status = 'L';
        jogador2[i].status = 'L';

        jogador1[i].p1 = -1;
        jogador1[i].p2 = -1;

        jogador2[i].p1 = -1;
        jogador2[i].p2 = -1;

    }

}


int  acharMaior(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[] ){

    int i = 0;

    if(domino->rodadaVez % 2 != 0){
        for(i=0; i<7; i++){    
            
            if(jogador1[i].p1 == domino->j_maiorP1 && jogador1[i].p2 == domino->j_maiorP2){
                
                return i;
            
            }
        }
        
    } 

    if(domino->rodadaVez % 2 == 0){
        for(i=0; i<7; i++){    
            if(jogador2[i].p1 == domino->j_maiorP1 && jogador2[i].p2 == domino->j_maiorP2){
                return i;
            
            }
        }
    } 
}


//verifica se a jogada do jogador 1 é válida
void verificarJog1(tipo_jogo *domino, tipo_peca jogador1[], tipo_mesa *tabuleiro, char escolha, int peca){

    int troca_p1, troca_p2;

    //jogador1

    if(escolha == 'E'){
    
        if(jogador1[peca].p1 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
            
        //======================================================|
            /*INVERTE A ATRIBUICAO  
              -Exemplo: 5|1  5|5
                       (p1|p2 mP1|mP2)
               * ja que p1 é igual a p1 temos que inverter 
                 a atribuição ficando assim:
                        1|5 5|1
            */
        //========================================================|
            troca_p1 = jogador1[peca].p2; 
            troca_p2 = jogador1[peca].p1;
            //peca foi colocada na mesa
            jogador1[peca].status = 'M'; 
            jogador1[peca].p1 = -1;
            jogador1[peca].p2 = -1;
            //Colocando peca no tabuleiro 
            tabuleiro->mapa[posicaoI - tabuleiro->ext_esq] = troca_p1;
            tabuleiro->mapa[posicaoF - tabuleiro->ext_esq] = troca_p2;
            tabuleiro->ext_esq = tabuleiro->ext_esq + 2;

            domino->jogou = 1;

        } else if(jogador1[peca].p2 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
            
            troca_p1 = jogador1[peca].p1;
            troca_p2 = jogador1[peca].p2;
            //peca foi colocada na mesa
            jogador1[peca].status = 'M'; 
            jogador1[peca].p1 = -1;
            jogador1[peca].p2 = -1;
            //Colocando peca no tabuleiro 4|2 5|5
            tabuleiro->mapa[posicaoI - tabuleiro->ext_esq] = troca_p1;
            tabuleiro->mapa[posicaoF - tabuleiro->ext_esq] = troca_p2;
            tabuleiro->ext_esq = tabuleiro->ext_esq + 2;

            domino->jogou = 1;
            
        
        }else {
            printf("Jogada inválida >:("); 
            domino->jogou = 0;
        }
    }
    
    if (escolha == 'D'){
        
        if(jogador1[peca].p1 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
        
            troca_p1 = jogador1[peca].p1; 
            troca_p2 = jogador1[peca].p2;
            //peca foi colocada na mesa
            jogador1[peca].status = 'M'; 
            jogador1[peca].p1 = -1;
            jogador1[peca].p2 = -1;
            tabuleiro->mapa[posicaoI + tabuleiro->ext_dir] = troca_p1;
            tabuleiro->mapa[posicaoF + tabuleiro->ext_dir] = troca_p2; 
            tabuleiro->ext_dir = tabuleiro->ext_dir + 2;

            domino->jogou = 1;

        }else if(jogador1[peca].p2 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
            //======================================================|
                /*INVERTE A ATRIBUICAO  
                  -Exemplo: 4|4  1|4
                           (mP1|mP2 p1|p2)
                   * ja que mp2 é igual a p2 temos que inverter 
                     a atribuição ficando assim:
                            4|4 4|1
                */
            //========================================================|            
            troca_p1 = jogador1[peca].p2;
            troca_p2 = jogador1[peca].p1;
            //peca foi colocada na mesa
            jogador1[peca].status = 'M'; 
            jogador1[peca].p1 = -1;
            jogador1[peca].p2 = -1;
                                        
            tabuleiro->mapa[posicaoI + tabuleiro->ext_dir] = troca_p1;
            tabuleiro->mapa[posicaoF + tabuleiro->ext_dir] = troca_p2; 
            tabuleiro->ext_dir = tabuleiro->ext_dir + 2;

            domino->jogou = 1;
                
        } else {
            printf("Jogada inválida >:("); 
            domino->jogou = 0;
        }
    
    }
    
}

//verificar se a jogada do jogador 2 está válida
void verificarJog2(tipo_jogo *domino, tipo_peca jogador2[], tipo_mesa *tabuleiro, char escolha, int peca){

    int troca_p1, troca_p2;

    //jogador 2

    
    if(escolha == 'E'){
    
        if(jogador2[peca].p1 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
            
        //======================================================|
            /*INVERTE A ATRIBUICAO  
              -Exemplo: 5|1  5|5
                       (p1|p2 mP1|mP2)
               * ja que p1 é igual a p1 temos que inverter 
                 a atribuição ficando assim:
                        1|5 5|1
            */
        //========================================================|
            troca_p1 = jogador2[peca].p2; 
            troca_p2 = jogador2[peca].p1;
            //peca foi colocada na mesa
            jogador2[peca].status = 'M'; 
            jogador2[peca].p1 = -1;
            jogador2[peca].p2 = -1;
            //Colocando peca no tabuleiro 
            tabuleiro->mapa[posicaoI - tabuleiro->ext_esq] = troca_p1;
            tabuleiro->mapa[posicaoF - tabuleiro->ext_esq] = troca_p2;
            tabuleiro->ext_esq = tabuleiro->ext_esq + 2;

            domino->jogou = 1;

        } else if(jogador2[peca].p2 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
            troca_p1 = jogador2[peca].p1;
            troca_p2 = jogador2[peca].p2;
            //peca foi colocada na mesa
            jogador2[peca].status = 'M'; 
            jogador2[peca].p1 = -1;
            jogador2[peca].p2 = -1;
            //Colocando peca no tabuleiro 4|2 5|5
            tabuleiro->mapa[posicaoI - tabuleiro->ext_esq] = troca_p1;
            tabuleiro->mapa[posicaoF - tabuleiro->ext_esq] = troca_p2;
            tabuleiro->ext_esq = tabuleiro->ext_esq + 2;

            domino->jogou = 1;

        }else {
            printf("Jogada inválida >:("); 
            domino->jogou = 0;
        }
    }
    
    if (escolha == 'D'){

        if(jogador2[peca].p1 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
        
            troca_p1 = jogador2[peca].p1; 
            troca_p2 = jogador2[peca].p2;
            //peca foi colocada na mesa
            jogador2[peca].status = 'M'; 
            jogador2[peca].p1 = -1;
            jogador2[peca].p2 = -1;
            tabuleiro->mapa[posicaoI + tabuleiro->ext_dir] = troca_p1;
            tabuleiro->mapa[posicaoF + tabuleiro->ext_dir] = troca_p2; 
            tabuleiro->ext_dir = tabuleiro->ext_dir + 2;

            domino->jogou = 1;

    }else if(jogador2[peca].p2 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
        //======================================================|
            /*INVERTE A ATRIBUICAO  
              -Exemplo: 4|4  1|4
                       (mP1|mP2 p1|p2)
               * ja que mp2 é igual a p2 temos que inverter 
                 a atribuição ficando assim:
                        4|4 4|1
            */
        //========================================================|            
        troca_p1 = jogador2[peca].p2;
        troca_p2 = jogador2[peca].p1;
        //peca foi colocada na mesa
        jogador2[peca].status = 'M'; 
        jogador2[peca].p1 = -1;
        jogador2[peca].p2 = -1;
                                    
        tabuleiro->mapa[posicaoI + tabuleiro->ext_dir] = troca_p1;
        tabuleiro->mapa[posicaoF + tabuleiro->ext_dir] = troca_p2; 
        tabuleiro->ext_dir = tabuleiro->ext_dir + 2;
            
        domino->jogou = 1;

        } else {
            printf("Jogada inválida >:("); 
            domino->jogou = 0;
        }

    }

}

// função para comprar peça
void comprarPeca(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_mesa *tabuleiro, int *k, int *cont_1, int *cont_2){
    
    
    int i = 0 , j, aux_p1 , aux_p2, m = 0, verjog;
    verjog = verificarCompra(domino, jogador1, jogador2, tabuleiro);
    
    if(verjog == 1){
            printf("\n\n\tNao foi possivel efetuar a compra, voce possui pecas disponiveis");
    }
    
    
    bool achou = false;
    //14 é a quantidade padrao de peças no monte
    for(j = 0 ; j < 14 ; j++){
      
       if((monte[j].p1 != -1 && monte[j].p2 != -1) || (monte[j].status == 'C')){
           i++;  
       }
    }

    //Existe pelo menos uma peca disponivel
    if(i > 0 && verjog == 0){
        
        while(achou == false && *k < 14){
            //14 é a quantidade padrao de peças no monte
    
            if((monte[*k].p1 != -1 && monte[*k].p2 != -1) && (monte[*k].status == 'C')){
            //Verifica se a peca pode ser encaixada 
            //no Lado esquerdo 
                if(monte[*k].p1 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                    aux_p1 = monte[*k].p1;
                    aux_p2 = monte[*k].p2;
                    
                    monte[*k].p1 = -1;
                    monte[*k].p2 = -1;
                    monte[*k].status = 'V';
                    m++;

                    achou =true;
                }else if(monte[*k].p2 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                    aux_p1 = monte[*k].p1;
                    aux_p2 = monte[*k].p2;
                    monte[*k].p1 = -1;
                    monte[*k].p2 = -1;
                    monte[*k].status = 'V';
                    m++;

                    achou =true;
                //no Lado direito
                }else if(monte[*k].p1 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
                    aux_p1 = monte[*k].p1;
                    aux_p2 = monte[*k].p2;
                    monte[*k].p1 = -1;
                    monte[*k].p2 = -1;
                    monte[*k].status = 'V';
                    m++;

                    achou =true;
                }else if(monte[*k].p2 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
                    aux_p1 = monte[*k].p1;
                    aux_p2 = monte[*k].p2;
                    monte[*k].p1 = -1;
                    monte[*k].p2 = -1;
                    monte[*k].status = 'V';
                    m++;

                    achou =true;
                }else {
                    aux_p1 = monte[*k].p1;
                    aux_p2 = monte[*k].p2;
                    monte[*k].p1 = -1;
                    monte[*k].p2 = -1;
                    monte[*k].status = 'V';
                    m++;
                    
                }
            } 
            if(domino->rodadaVez %2 != 0){
                
                while((jogador1[*cont_1].p1 == -1 && jogador1[*cont_1].p2 == -1) && (jogador1[*cont_1].status == 'L' || jogador1[*cont_1].status == 'M')){
                    
                    if(*cont_1 < 21){
                        
                        if(aux_p1 != -1 && aux_p2 != -1){
                            jogador1[*cont_1].p1 = aux_p1;
                            jogador1[*cont_1].p2 = aux_p2;
                            jogador1[*cont_1].status = 'U';
                    
                        }
                    }
                }
            }
            if(domino->rodadaVez %2 == 0){
                
                while((jogador2[*cont_2].p1 == -1 && jogador2[*cont_2].p2 == -1) && (jogador2[*cont_2].status == 'L' || jogador2[*cont_2].status == 'M')){
                    
                    if(*cont_2 < 21){
                        
                        if(aux_p1 != -1 && aux_p2 != -1){
                            jogador2[*cont_2].p1 = aux_p1;
                            jogador2[*cont_2].p2 = aux_p2;
                            jogador2[*cont_2].status = 'U';
                            
                        }
                    }
                }
            }

            (*k)++;

            if(domino->rodadaVez %2 != 0){
                (*cont_1)++;
                domino->quantJ1++;
                
            } else{
                (*cont_2)++;
                domino->quantJ2++;
            }
        }
    
        printf("\n\n Voce comprou %d peca(s)!", m);

        } else if(i < 0){
            printf("\n\n O monte esta vazio!!!");
        }
    
}    

//verificar se pode comprar ou não
int verificarCompra(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro){
    int i; 
    int veri = 0;
    
    //jogador 1
    if(domino->rodadaVez %2 != 0){
        
        for(i = 0; i < 21; i++){

            if(jogador1[i].p1 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                veri = 1;

            }else if(jogador1[i].p2 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                veri = 1;

            }else if(jogador1[i].p1 ==  tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
                veri = 1;

            }else if(jogador1[i].p2 ==  tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
                veri = 1;
            }
        }   

        return veri;
    }
    
    //jogador 2
    if(domino->rodadaVez %2 == 0){

        for(i = 0; i < 21; i++){

            if(jogador2[i].p1 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                veri = 1;

            }else if(jogador2[i].p2 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                veri = 1;

            }else if(jogador2[i].p1 ==  tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
                veri = 1;

            }else if(jogador2[i].p2 ==  tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
               veri = 1;

            }
        }

        return veri;
    }
}

//funcao do jogo fechado
void contarPontos(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[]){
    int i;
    
    domino->pontosJ1 = 0;
    domino->pontosJ2 = 0;

    for(i = 0; i < 21; i++){
        
        if(jogador1[i].p1 != -1 && jogador1[i].p2 != -1 && jogador1[i].status == 'U'){
            domino->pontosJ1 = domino->pontosJ1 + jogador1[i].p2 + jogador1[i].p1;
        }
        
            if(jogador2[i].p1 != -1 && jogador2[i].p2 != -1 && jogador2[i].status == 'U'){
            domino->pontosJ2 = domino->pontosJ2 + jogador2[i].p2 + jogador2[i].p1;
        }
    }
}

void inicializaMesa(tipo_mesa *tabuleiro){
    int i;
    
    //SETUP DA MESA
    for(i = 0; i < 100; i++){
        tabuleiro->mapa[i] = -1;
    }

    tabuleiro->h_esq = 42;
    tabuleiro->h_dir = 77;
}

void  delay(float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;

   return;

}

void carregarTela(float tempo){
    fflush (stdout);
    delay(tempo);
}


void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

//jogador2 = bot 
void jogarPecaBOT(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_mesa *tabuleiro, int *k, int *cont_1, int *cont_2){
    int i = 0, troca_p1, troca_p2, cont = 0;
    bool achou = false;
    int veri;


    while(achou == false && i < 21){
        
        cont = 0;

        for(int j = 0 ; j < 14 ; j++){
      
            if((monte[j].p1 != -1 && monte[j].p2 != -1) || (monte[j].status == 'C')){
                cont++;  
            }
        }

        if(jogador2[i].p1 != -1 && jogador2[i].p2 != -1 && jogador2[i].status == 'U'){
            if(jogador2[i].p1 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                //======================================================|
                    /*INVERTE A ATRIBUICAO  
                      -Exemplo: 5|1  5|5
                               (p1|p2 mP1|mP2)
                       * ja que p1 é igual a p1 temos que inverter 
                         a atribuição ficando assim:
                                1|5 5|1
                    */
                //========================================================|
                troca_p1 = jogador2[i].p2; 
                troca_p2 = jogador2[i].p1;
                //peca foi colocada na mesa
                jogador2[i].status = 'M'; 
                jogador2[i].p1 = -1;
                jogador2[i].p2 = -1;
                //Colocando peca no tabuleiro 
                tabuleiro->mapa[posicaoI - tabuleiro->ext_esq] = troca_p1;
                tabuleiro->mapa[posicaoF - tabuleiro->ext_esq] = troca_p2;
                tabuleiro->ext_esq = tabuleiro->ext_esq + 2;
                achou = true;
            } else if(jogador2[i].p2 == tabuleiro->mapa[posicaoI - tabuleiro->ext_esq + 2]){
                troca_p1 = jogador2[i].p1;
                troca_p2 = jogador2[i].p2;
                //peca foi colocada na mesa
                jogador2[i].status = 'M'; 
                jogador2[i].p1 = -1;
                jogador2[i].p2 = -1;
                //Colocando peca no tabuleiro 4|2 5|5
                tabuleiro->mapa[posicaoI - tabuleiro->ext_esq] = troca_p1;
                tabuleiro->mapa[posicaoF - tabuleiro->ext_esq] = troca_p2;
                tabuleiro->ext_esq = tabuleiro->ext_esq + 2;
                achou = true;
            }else if(jogador2[i].p1 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
            
                troca_p1 = jogador2[i].p1; 
                troca_p2 = jogador2[i].p2;
                //peca foi colocada na mesa
                jogador2[i].status = 'M'; 
                jogador2[i].p1 = -1;
                jogador2[i].p2 = -1;
                tabuleiro->mapa[posicaoI + tabuleiro->ext_dir] = troca_p1;
                tabuleiro->mapa[posicaoF + tabuleiro->ext_dir] = troca_p2; 
                tabuleiro->ext_dir = tabuleiro->ext_dir + 2;
                achou = true;
            }else if(jogador2[i].p2 == tabuleiro->mapa[posicaoF + tabuleiro->ext_dir - 2]){
                //======================================================|
                    /*INVERTE A ATRIBUICAO  
                      -Exemplo: 4|4  1|4
                       * ja que mp2 é igual a p2 temos que inverter 
                               (mP1|mP2 p1|p2)
                         a atribuição ficando assim:
                                4|4 4|1
                    */
                //========================================================|            
                troca_p1 = jogador2[i].p2;
                troca_p2 = jogador2[i].p1;
                //peca foi colocada na mesa
                jogador2[i].status = 'M'; 
                jogador2[i].p1 = -1;
                jogador2[i].p2 = -1;
                tabuleiro->mapa[posicaoI + tabuleiro->ext_dir] = troca_p1;
                tabuleiro->mapa[posicaoF + tabuleiro->ext_dir] = troca_p2; 
                tabuleiro->ext_dir = tabuleiro->ext_dir + 2;
                achou = true;
            } 
        } 
        i++;

        if(i == 21 && achou == false && cont > 0) {
            printf("\n\tBOT COMPRANDO PECAS");
            for(int i = 0; i < 10 ; i++){
                printf(".");
                carregarTela(0.1);
            }
           
            comprarPeca(domino, jogador1, jogador2, monte, tabuleiro, k, cont_1, cont_2);
            //Apagar a mensagem do dessa função
            printf("\r BOT ");
            i = 0;
            
        } 
        if(cont  == 0){
            printf("\n\tPROCESSADNO");
            for(int i = 0; i < 10 ; i++){
                printf(".");
                carregarTela(0.1);
            }

             printf("\n\t BOT NAO NENHUMA POSSUI PECA PARA COLOCAR NA MESA\n\t ->MONTE VAZIO!!");

             achou  = true;
        }
    }
    
}