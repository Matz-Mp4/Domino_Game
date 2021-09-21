#include "DominoModel.h"
#include "DominoView.h"
#include "DominoData.h"

 void mostrarCarregamento (char palavra[], float velocidade, char imagem[]){    
     int i, j;
     float x = 0;
          
   
     for (i = 0; i <= 100; i++){  
        
        //Animação da barrinha
         
         
         printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t%s: ", palavra);    
         if(x == 0  || (x/10) >= 0  && (x/10) < 1)
            printf ("[|]  ");
         if(x == 1  || (x/10) >= 1  && (x/10) < 2)
            printf ("[/]  " );

         if(x == 2  || (x/10) >= 2  && (x/10) < 3)
            printf ("[-]  "  );
         if(x == 3  || (x/10) >= 3  && (x/10) < 4)
            printf ("[\\]  " );
         if(x == 4  || (x/10) >= 4  && (x/10) < 5)
            printf ("[|]  "  );
         if(x == 5  || (x/10) >= 5  && (x/10) < 6)
            printf ("[/]  "  );
         if(x == 6  || (x/10) >= 6  && (x/10) < 7)
            printf ("[-]  "  );
         if(x == 7  || (x/10) >= 7  && (x/10) < 8)
            printf ("[\\]  "  );
         if(x == 8  || (x/10) >= 8  && (x/10) < 9)
            printf ("[|]  "  );
         if(x == 9  || (x/10) >= 9  && (x/10) < 10)
            printf ("[/]  "  );

        printf ("[");
         printf ("%d%% ", i);   
            
          //garante a escrita de dados imediatamente na tela                  
         //repare mod 10, eu limito a qtd de pontos q serao gerados
         
         for (j = 0; j < i%10; j++){
                
    
                printf("%s", imagem);
                   
                
         } 
            
         ("]");
            
          
        
         carregarTela(velocidade);//função espera por tempo, parametro em microsegundos.
         printf("\r");//retorna para o inicio da linha 
         clear();
         x++;
     }                 
     printf (" ");//Apagar mensagem   
     

  }
void imagem(){ //bolo

printf("\n\t                   ,                    ");
printf("\n\t                  /(                    ");
printf("\n\t                 (  )               ");
printf("\n\t                 ,\\/,                   ");
printf("\n\t                 |--|                   ");
printf("\n\t                 |  |                   ");    
printf("\n\t                 |  |                   ");
printf("\n\t       .-'~--..__|  |                   ");
printf("\n\t      |~-,,__    `..|'--..__         ");
printf("\n\t      |      ~~''--,,__     ~-.      ");
printf("\n\t      |                ~~''--~|      ");
printf("\n\t      |    .                  |      ");
printf("\n\t      |   ' `     _.          |      ");
printf("\n\t      | ,'   \\   /\\       .-|      ");
printf("\n\t      |'      `-'   \\     /  |      ");
printf("\n\t      |               `._,'   |      ");
printf("\n\t   _-~|                       |      ");
printf("\n\t   -   ~-..__                 |._    ");
printf("\n\t    ~-.__    ~~''--..__       |  -.  ");
printf("\n\t         ~~''--..__    ~~''--'~  ,'  ");
printf("\n\t                   ~~''--....--'~    ");
        
}

//hub do sistema
void menu()
{ 

    mostrarNome();
    
     //garante a escrita de dados imediatamente na tela
    
    
    
    printf("\n\t\t    _________________ \t\t      ***********************                    _________________");
     carregarTela(0.02);
    printf("\n\t\t    ||             || \t\t\t     Bem-Vindo                           ||             ||");
     carregarTela(0.02);
    printf("\n\t\t    ||  O       O  || \t\t\t        ao                               ||  O       O  ||");
     carregarTela(0.02);
    printf("\n\t\t    ||             || \t\t\t       Jogo                              ||             ||");
     carregarTela(0.02);
    printf("\n\t\t    ||  O       O  || \t\t      ***********************                    ||  O       O  ||");
     carregarTela(0.02);
    printf("\n\t\t    ||             || \t\t\t  -=--=DOMINO=--=-                       ||             ||");
     carregarTela(0.02);
    printf("\n\t\t    ||  O       O  ||     _________________________________________________      ||  O       O  ||");
     carregarTela(0.02);
    printf("\n\t\t    ||_____________|| \t\t >Pressione  <1> para jogar                      ||_____________||");
     carregarTela(0.02);
    printf("\n\t\t    ||             || \t\t >Pressione  <2> para embaralhar as pecas        ||             ||");
     carregarTela(0.02);
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <3> para organizar as pecas         ||  O       O  ||");
     carregarTela(0.02);
    printf("\n\t\t    ||             || \t\t >Pressione  <4> para mostrar as pecas           ||             ||");
     carregarTela(0.02);
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <5> para mostrar as regras          ||  O       O  ||");
     carregarTela(0.02);
    printf("\n\t\t    ||             || \t\t >Pressione  <6> para sair                       ||             ||");
     carregarTela(0.02);
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <7> para transferir arquivos salvos ||  O       O  ||"); 
     carregarTela(0.02);
    printf("\n\t\t    ||_____________||    __________________________________________________      ||_____________||");

}             

//mostra as peças
void exibirPeca(tipo_peca dominoAux[])
{ 
    int k = 0;
    for (int i = 0; i < 28; i++)
    {
        k++;

        printf("peca: %d --> %d | %d\n", k , dominoAux[i].p1, dominoAux[i].p2);
    }
    puts("\n");

    
}


int entrarJogador()
{ //detecta a qtd de jogadores

    int quant;
    scanf("%d", &quant);

    return quant;
}

//mostra as peças do jogador 1 e jogador 2
void visualizarPeca(tipo_peca dominoAux[], tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[])
{


    //MOSTRA A PECA DO JOGADOR 1
    if(domino->rodadaVez % 2 != 0){
        printf("\n\t\t-=-=-=-=JOGADOR_1-=-=-=-=-\n");
        printf("\n");

        for (int i = 0; i < 21; i++)
        {   
            //Peca foi movida para o tabuleiro
            if( jogador1[i].p1 == -1 && jogador1[i].p2 == -1 || jogador1[i].status != 'U'){
                 carregarTela( 0.004);
                printf("peca %d:    \t\t VAZIO\n", i+1 );
                

            }else if( jogador1[i].maiorP == 1){
                 carregarTela( 0.004);
                printf("peca %d:    \t\t|%d | %d| -> (Maior peca dobrada)\n", i+1 ,  jogador1[i].p1, jogador1[i].p2);

            } else if( jogador1[i].maiorP == 2){
                 carregarTela( 0.004);
                printf("peca %d:    \t\t|%d | %d| -> (Maior peca normal)\n", i+1 ,  jogador1[i].p1, jogador1[i].p2);

            }else{
                carregarTela( 0.004);
                printf("peca %d:    \t\t|%d | %d|\n", i+1 ,  jogador1[i].p1, jogador1[i].p2);
            }
        } 
    } 
    //MOSTRA A PECA DO JOGADOR 2
    if(domino->rodadaVez % 2 == 0){
        printf("\n\t\t-=-=-=-=JOGADOR_2-=-=-=-=-\n");
        printf("\n");

        for (int i = 0; i < 21; i++)
        {   
             if( jogador2[i].p1 == -1 && jogador2[i].p2 == -1){
                  carregarTela( 0.004);
                printf("peca %d:    \t\t VAZIO\n", i+1 );

             }else  if( jogador2[i].maiorP == 1){
                 carregarTela( 0.004);
                printf("peca %d:    \t\t|%d | %d| -> (Maior peca dobrada)\n", i+1 ,  jogador2[i].p1, jogador2[i].p2);

            } else if( jogador2[i].maiorP == 2){
                    carregarTela(0.004);
                printf("peca %d:    \t\t|%d | %d| -> (Maior peca normal)\n", i+1 ,  jogador2[i].p1, jogador2[i].p2);

            }else{
                 carregarTela( 0.004);
                printf("peca %d:    \t\t|%d | %d|\n", i+1 ,  jogador2[i].p1, jogador2[i].p2);
            }
        }
    }

  
}

//função para mostrar a mesa
void mostrarMesa(tipo_mesa *tabuleiro, int modo)

{                                                   
    int i, j, k;
    
    printf("\n\n\t\t\t\t\t\t                 -=-=-=-=-=DOMINO=-=-=-=-=-\n\n");
    
    printf("\n");
    printf("======================================================================================================================================================\n");   

    for (i =  tabuleiro->h_esq; i <=  tabuleiro->h_dir; i++){
        
        if( tabuleiro->mapa[i] != -1){
            if(i % 2 == 0){
                if(modo == 1){
                    carregarTela(0.07);
                }
                 
                 
                printf("|%d-",  tabuleiro->mapa[i]);
                   
            }else {
                 if(modo == 1){
                    carregarTela(0.07);
                }
                 printf("-%d|",  tabuleiro->mapa[i]);
                    
                 
            }                     
        
        }else if(tabuleiro->mapa[i] == -1){
            printf("    ");
            
        }                       
        
    }
    printf("\n______________________________________________________________________________________________________________________________________________________");   
    printf("\n======================================================================================================================================================");
    mostrarMesa2();    
}

//Opçao do menu
char opcao()
{
    char op;
    op = getchar();
    flush_in();

    return op;
}

// menu dentro do jogo
char menuJogo()
{ 
    int escolha;
    printf("\n\n\t\t/===============================\\");
    printf("\n\t\t   Digite <1> para jogar");
    printf("\n\t\t   Digite <2> para comprar");
    printf("\n\t\t   Digite <3> para ver as pecas");
    printf("\n\t\t   Digite <4> para mover a tela");
    printf("\n\t\t   Digite <5> para terminar a jogada");
    printf("\n\t\t   Digite <6> para finalizar o jogo");
    printf("\n\t\t   Digite <7> para salvar o jogo");
    printf("\n\t\t   Digite <8> para carregar um jogo");
    printf("\n\t\t   Digite <9> para sair do jogo");
    printf("\n\t\t   Digite <0> para resetar um arquivo");
    printf("\n\t\t\\===============================/");
    printf("\nOpcao: ");
    scanf("%d", &escolha);
    

    return escolha;
}

//move a a mesa para direita e esquerda
int moverTela(int quant)
{
    char op;
    //char escolha;
    int escolha;
    printf("\n\n         \t\t\t\t\t-=-=-=-=-=-=-=-=DIRECAO=-=-=-=-=-=-=-=-");
    printf("\n                \t\t\t\t\tPressinoe <1> para ----->");
    printf("\n                \t\t\t\t\tPressinoe <2> para <-----");
    printf("\n         \t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");

    printf("\n\t\tOpcao: ");
    //escolha = opcao();
    scanf("%d", &escolha);

    printf("\nDigite a quantidade de colunas: ");
    scanf("%d", &quant);

    if (escolha == 2)
    {
        return quant;
    }

    if (escolha == 1)
    {
        quant = quant * -1;
        return quant;
    }
}

// hub dos dois jogadores
void jogodeDois(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_arquivo arqSalvo[])
{
    //h_esq -> horizontal esquerda [50] 
    //h_dir -> horizontal direita  [50]
    //quant -> quantidade de colunas no sentido da esquerda 
    //         ou no sentido da direita 
    int   i = 0, aux, quant, cont = 0, cont_1 = 7, cont_2 = 7, posicao, vitoria;

    // veri = verificador para a entrada do usuario nao ultrapasse a borda
    // em ambos sentidos
    int   veri = 0, veri1 = 101;

    // jogador = recebe um valor para demonstrar ao usuario
    //           quem comeca a jogar
    char  escolha;
    bool  sair = false;
    
    //definindo a vez de cada jogador 
    domino->rodadaVez = domino->jogaPrimeiro;

    //Quando o jogo comeca a maior peca do jogo tem que ter seus status alterado
    posicao = acharMaior(domino, jogador1, jogador2);
    tabuleiro->mapa[50] = domino->j_maiorP1;
    tabuleiro->mapa[51] = domino->j_maiorP2;

    //se for a vez do 1 jogador 
    if(domino->jogaPrimeiro % 2 != 0){

        //peca foi para mesa | -1 = peca foi movida 
        jogador1[posicao].status = 'M';
        jogador1[posicao].p1 = -1;
        jogador1[posicao].p2 = -1;

        domino->quantJ1 = 6;
        domino->quantJ2 = 7;
    }

    if(domino->jogaPrimeiro % 2 == 0){

        jogador2[posicao].status = 'M';
        jogador2[posicao].p1 = -1;
        jogador2[posicao].p2 = -1;

        domino->quantJ1 = 7;
        domino->quantJ2 = 6;
    }

    if(domino->jogaPrimeiro % 2 != 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t   JOGADOR 1 JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n\n");

    }
    
    if(domino->jogaPrimeiro % 2 == 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t   JOGADOR 2 JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n");
    }

    cont = 0;
    domino->rodadaVez++;
    domino-> jogou = 0;

    do{ 
        mostrarMenu();
        escolha = menuJogo();

        switch (escolha)
        {
            case 1: //jogar a peça

                if(domino-> jogou == 0){

                    if(domino->rodadaVez % 2 != 0) {
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    JOGADOR 1 IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n\n");

                    }
                    if(domino->rodadaVez % 2 == 0) {
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    JOGADOR 2 IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n");

                    }

                    //Colocamos definirMaior para ele atualizar constantemente quem é a maior
                    //peca dobrada e a maior peca normal
                    definirMaior(domino, jogador1, jogador2, monte);
                    mostrarMesa(tabuleiro, 1);
                    visualizarPeca(dominoAux, domino, jogador1, jogador2, monte);
                    alocarPeca(domino, jogador1 , jogador2, tabuleiro);


                } else{
                    printf("\n\tVoce ja jogou sua peca!");
                }

                    system("clear");
                    mostrarMesa(tabuleiro, 0);
                break;

            case 2: //comprar uma peça
                comprarPeca(domino, jogador1, jogador2, monte, tabuleiro, &cont, &cont_1, &cont_2);
                limparInterface();
            break;

            case 4:
                //Quando ele digita <E> o aux ja é convetido para negativo
                // por isso: h_esq + aux = h_esq - aux
                aux = moverTela(quant);

                while (( tabuleiro->h_esq + aux) <= veri || ( tabuleiro->h_dir + aux) >= veri1)
                {
                    carregarTela(10);
                     
                      
                     
                    printf("\nOPPS!");
                    printf("Sua escolha de colunas ultapassou o limite!!");
                       
                    aux = moverTela(quant);
                }

                tabuleiro->h_esq = aux +  tabuleiro->h_esq;
                tabuleiro->h_dir =  tabuleiro->h_dir + aux;
    
                mostrarMesa(tabuleiro, 1);
                limparInterface();
                break;
    
            
    
            case 3:
                mostrarMesa(tabuleiro, 0);
                definirMaior(domino, jogador1, jogador2, monte);
                visualizarPeca(dominoAux, domino, jogador1, jogador2, monte);
                limparInterface();
                break;
            
            case 5: //terminar rodada

                domino->rodadaVez++;

                if(domino->rodadaVez % 2 != 0) {
                    printf("\n\t\t/================================\\");
                    printf("\n\t\t    JOGADOR 1 IRA JOGAR!!");
                    printf("\n\t\t\\================================/\n\n");
                }

                if(domino->rodadaVez % 2 == 0) {
                    printf("\n\t\t/================================\\");
                    printf("\n\t\t    JOGADOR 2 IRA JOGAR!!");
                    printf("\n\t\t\\===============================/\n");
                }

                domino->jogou = 0;

                mostrarMesa(tabuleiro, 0);
                limparInterface();
                break;
            
            case 6://finalizar o jogo (caso fechado)

                contarPontos(domino, jogador1, jogador2);

                if(domino->pontosJ1 <  domino->pontosJ2){

                    mostrarJ1();
                    imagem();

                }else if(domino->pontosJ2 <  domino->pontosJ1){
                    mostrarJ2();
                    imagem();

                }else{
                    printf("empate");

                }
                sair = true;
                limparInterface();
                break;

            case 9: //sair do jogo
                sair = true;
                
                break;
    
            case 7:
                mostrarArquivos(arqSalvo);
                salvarArquivo(domino, jogador1, jogador2, tabuleiro, monte, arqSalvo);
                mostrarCarregamento("S A L V A N D O", 0.009, ".."); 

                
                break;
            
            case 8:
                mostrarArquivos(arqSalvo);
                carregarArquivo(domino,jogador1,jogador2, tabuleiro,  monte, arqSalvo);
                mostrarCarregamento(" CA R R E G A N D O", 0.009, ".."); 
                break;

            case 0:
                mostrarArquivos(arqSalvo);
                resetarArq(arqSalvo);
                limparInterface();
                break;
    
            default: //opção inválida >:(
                mostrarErro();
                printf("Opcao invalida!! >:(");
                limparInterface();
                break;

    
        }
    } while (sair == false);

}

//limpa o sistema
void limparInterface()
{ 
    char op;
     
    
     
    printf("\n................Pressione <ENTER> para continuar...................");
    
    scanf("%c", &op);
    flush_in();
    clear(); //("cls") para Windows
}

//opção de seleção de jogadores
void hubJogador(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_peca jogador1[], tipo_peca jogador2[], tipo_peca monte[], tipo_arquivo arqSalvo[], tipo_peca bot[])
{ 

    int quant;

    printf("\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=(HUB)=-=-=-=-=-=-=-=-=-=--=-=-");
    printf("\n\n\t\t\t    Digite a quantidade de jogadores: ");
    quant = entrarJogador();

    if (quant == 1)
    { // jogo com 1 jogador
        
        printf("\n\t\t\t\t  /===================================\\");
        printf("\n\t\t\t\t               JOGO COM BOT");
        printf("\n\t\t\t\t  \\===================================/");
        printf("\n\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        limparInterface();

        //Setup do jogo
        distribuirpecas(dominoAux, domino, jogador1, bot, monte);
        definirStatus(jogador1, bot, monte);
        definirTipo(domino, jogador1, bot, monte);
        definirMaior(domino, jogador1, bot, monte);
        inicializaMesa(tabuleiro);

        monstrarMensBot();
    
        printf("\n\tEM MANUTENCAO!!!!");
        jogoAUTO(dominoAux, domino, tabuleiro, jogador1,  bot,  monte,  arqSalvo);

    }

    if (quant == 2)
    { // jogo com 2 jogadores

        printf("\n\t\t\t\t  /===================================\\");
        printf("\n\t\t\t\t              JOGO DE DOIS");
        printf("\n\t\t\t\t  \\===================================/");
        printf("\n\n\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        limparInterface();

        //Setup do jogo
        distribuirpecas(dominoAux, domino, jogador1, jogador2, monte);
        definirStatus(jogador1, jogador2, monte);
        definirTipo(domino, jogador1, jogador2, monte);
        definirMaior(domino, jogador1, jogador2, monte);
        inicializaMesa(tabuleiro);

        jogodeDois(dominoAux, domino, tabuleiro, jogador1, jogador2, monte, arqSalvo);
    }

    while (quant > 2 || quant < 1)
    {    
          
         
        printf("\nOps voce deve ter digitado algo errado!!");
           
        printf("\nDigite a quantidade de jogadores:");
        quant = entrarJogador();
    }
    
}

//coloca as peças na mesa
void alocarPeca(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro){

    char escolha;
    int pecaAux, peca;

    escolha = escolherDirecao();
    
    printf("\nDigite sua peca: ");
    scanf("%d", &pecaAux);

    peca = pecaAux -1;

    if(domino->rodadaVez %2 != 0){
        verificarJog1(domino, jogador1, tabuleiro, escolha, peca);
        

    } else if(domino->rodadaVez %2 == 0){
        verificarJog2(domino, jogador2, tabuleiro, escolha, peca);
        
    }

}

//Mostra as regras do jogo
void mostrarRegras(){
    
    printf("\n");
    printf("\nRegras do Jogo \n");
    printf("\nAs regras do jogo sao bem simples: cada jogador pega sete pecas e pode comprar sempre que precisar de");
    printf("\numa peca para poder jogar e quantas vezes for necessario. Da-se inicio ao jogo o jogador que tirar");
    printf("\na pedra seis-seis. Caso ninguem tenha o tirado, inicia-se o jogador que tiver a peca com os numeros");
    printf("\nrepetidos mais altos, ou seja, cinco-cinco, quatro-quatro, e assim sucessivamente. O jogo");
    printf("\nacontece no sentido anti-horario e os jogadores devem colocar pecas que tenham os mesmos numeros das");
    printf("\npecas que se encontram na ponta do jogo. O jogador que comeca a partida leva vantagem. Este e um");
    printf("\nconceito importante para a estrategia do domino, pois o jogador que comeca, normalmente, e o que leva");
    printf("\na vantagem durante a partida. Cada jogador, no seu turno, deve colocar uma das suas pecas em uma das");
    printf("\nduas extremidades abertas, de forma que os pontos de um dos lados coincidam com os pontos da extremidade");
    printf("\nonde esta sendo colocada. As dobradas sao colocadas de maneira transversal para facilitar");
    printf("\nsua localizacao. Quando o jogador coloca sua peca sobre a mesa, seu turno se acaba e passa-se ao");
    printf("\nseguinte jogador. Se um jogador nao puder jogar, devera comprar do monte tantas pecas como forem");
    printf("\nnecessarias. Se nao houver pecas no monte, passara o turno ao seguinte jogador.A partida continua com");
    printf("\nos jogadores colocando suas pecas sobre a mesa ate que se apresente alguma das seguintes situacoes:\n");
    printf("\n- Quando um jogador coloca sua ultima pedra na mesa, essa acao e chamada de bater. Quando joga-se sozinho,");
    printf("\no jogador que ganhou a partida soma os pontos de todos os seus adversarios. Jogando em dupla, somam-se"); 
    printf("\nos pontos de todos os jogadores incluindo os do seu companheiro.\n"); 
    printf("\n- Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o numero das"); 
    printf("\nextremidades saiu 7 vezes antes. Nesse momento se diz que a partida esta fechada. Os jogadores"); 
    printf("\ncontarao os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se");
    printf("\nos pontos da maneira habitual.\n");
    printf("\n- Pode acontecer de voce ter os mesmos pontos que o jogador ou a dupla que tem a vantagem,"); 
    printf("\nnesse caso, ganha este jogador.\n");
    printf("\nPontificia Universidade Catolica de Sao Paulo");
    printf("\nFaculdade de Ciencia Exatas e Tecnologia - Ciencia da Computacao");

}

//Menu ilustrativo
void mostrarNome(){
                                                                                                                                 
printf("\n        ***** **                                                                        ***** **   ***                          ");
printf("\n     ******  ***                                  *                                  ******  ***    ***      *                  ");
printf("\n   **    *  * ***                                ***                                **   *  * **     **     ***                 ");
printf("\n  *     *  *   ***                                *                                *    *  *  **     **      *                  ");
printf("\n       *  *     ***    ****                                             ****           *  *   *      **                         ");
printf("\n      ** **      **   * ***  * *** **** ****    ***     ***  ****      * ***  *       ** **  *       **    ***     ***  ****    ");
printf("\n      ** **      **  *   ****   *** **** ***  *  ***     **** **** *  *   ****        ** ** *        **     ***     **** **** * ");
printf("\n      ** **      ** **    **     **  **** ****    **      **   ****  **    **         ** ***         **      **      **   ****  ");
printf("\n      ** **      ** **    **     **   **   **     **      **    **   **    **         ** ** ***      **      **      **    **   ");
printf("\n      ** **      ** **    **     **   **   **     **      **    **   **    **         ** **   ***    **      **      **    **   ");
printf("\n      *  **      ** **    **     **   **   **     **      **    **   **    **         *  **     **   **      **      **    **   ");
printf("\n         *       *  **    **     **   **   **     **      **    **   **    **            *      **   **      **      **    **   ");
printf("\n    *****       *    ******      **   **   **     **      **    **    ******         ****     ***    **      **      **    **   ");
printf("\n   *   *********      ****       ***  ***  ***    *** *   ***   ***    ****         *  ********      *** *   *** *   ***   ***  ");
printf("\n  *       ****                    ***  ***  ***    ***     ***   ***               *     ****         ***     ***     ***   *** ");
printf("\n  *                                                                                *                                            ");
printf("\n   **                                                                               **                                          \n\n");
}

//menu dentro do jogo ilustrativo
void mostrarMenu(){

 printf("\n\t\t __  __                           "); 
 printf("\n\t\t|  \\/  |   ___   _ __    _   _   ");
 printf("\n\t\t| |\\/| |  / _ \\ | '_ \\  | | | |  ");
 printf("\n\t\t| |  | | |  __/ | | | | | |_| |  ");
 printf("\n\t\t|_|  |_|  |___| |_| |_|  |__,_|  \n\n");
                                
                                         
}

void mostrarErro(){
    
    printf("\n\t\t\t\t_______ ");
    printf("\n\t\t\t\t|  ___|                   ");
    printf("\n\t\t\t\t| |__ _ __ _ __ ___  _ __ ");
    printf("\n\t\t\t\t|  __| '__| '__/ _ \\| '__|");
    printf("\n\t\t\t\t| |__| |  | | | (_) | |   ");
    printf("\n\t\t\t\t|____/_|  |_|  \\___/|_|   \n");
                         
}



void mostrarMesa2(){

    printf("\n\t\t\t\t\t\t         \\ \\  / /   / /             \\ \\     \\ \\  / /       ");
    printf("\n\t\t\t\t\t\t          \\ \\/ /   /_/               \\_\\     \\ \\/ /        ");
    printf("\n\t\t\t\t\t\t          _\\/ /_______________________________\\ \\/_        ");    
    printf("\n\t\t\t\t\t\t         [_/o/_________________________________\\o\\_]       ");    
    printf("\n\t\t\t\t\t\t          / /\\ \\                             / /\\ \\        ");    
    printf("\n\t\t\t\t\t\t         /_/  \\_\\                           /_/  \\_\\       ");
}

void mostrarJ1(){

    carregarTela(0.1);
    printf("\n\n\t\t   _                       _                 __    ");
    printf("\n\t\t  (_)                     | |               /  |  ");
    printf("\n\t\t   _  ___   __ _  __ _  __| | ___  _ __     `| |  ");
    carregarTela(0.1);
    printf("\n\t\t  | |/ _ \\ / _` |/ _` |/ _` |/ _ \\| '__      | |  ");
    printf("\n\t\t  | | (_) | (_| | (_| | (_| | (_) | |      _ | |_ ");
    carregarTela(0.1);
    printf("\n\t\t  | |\\___/ \\__, |\\__,_|\\__,_|\\___/|_|       \\___/ ");
    printf("\n\t\t _/ |       __/ |                              ");
    carregarTela(0.1);
    printf("\n\t\t|__/       |___/                               ");

    
    printf("\n\n\t\t    _____             _                          ");
    carregarTela(0.1);
    printf("\n\t\t   / ____|           | |                         ");
    carregarTela(0.1);
    printf("\n\t\t  | |  __  __ _ _ __ | |__   ___  _   _          ");
    carregarTela(0.1);
    printf("\n\t\t  | | |_ |/ _` | '_ \\| '_ \\ / _ \\| | | |         ");    
    carregarTela(0.1);
    printf("\n\t\t  | |__| | (_| | | | | | | | (_) | |_| |         ");
    carregarTela(0.1);
    printf("\n\t\t   \\_____|\\__,_|_| |_|_| |_|\\___/ \\__,_|     ");
    carregarTela(0.1);
}

void mostrarJ2(){

    printf("\n\n\t             _                       _              ___   ");
    carregarTela(0.1);
    printf("\n\t\t   (_)                     | |            |__ \\  ");
    carregarTela(0.1);
    printf("\n\t\t    _  ___   __ _  __ _  __| | ___  _ __     ) | ");
    carregarTela(0.1);
    printf("\n\t\t   | |/ _ \\ / _` |/ _` |/ _` |/ _ \\| '__|   / /  ");
    carregarTela(0.1);
    printf("\n\t\t   | | (_) | (_| | (_| | (_| | (_) | |     / /_  ");
    carregarTela(0.1);
    printf("\n\t\t   | |\\___/ \\__, |\\__,_|\\__,_|\\___/|_|    |____| ");
    carregarTela(0.1);
    printf("\n\t\t  _/ |       __/ |                               ");
    carregarTela(0.1);
    printf("\n\t\t |__/       |___/  ");

    printf("\n\n\t\t    _____             _                          ");
    carregarTela(0.1);
    printf("\n\t\t   / ____|           | |                         ");
    carregarTela(0.1);
    printf("\n\t\t  | |  __  __ _ _ __ | |__   ___  _   _          ");
    carregarTela(0.1);
    printf("\n\t\t  | | |_ |/ _` | '_ \\| '_ \\ / _ \\| | | |         ");    
    carregarTela(0.1);
    printf("\n\t\t  | |__| | (_| | | | | | | | (_) | |_| |         ");
    carregarTela(0.1);
    printf("\n\t\t   \\_____|\\__,_|_| |_|_| |_|\\___/ \\__,_|     ");
    carregarTela(0.1);
                                       
                                       


}

void mostrarArquivos(tipo_arquivo arqSalvo[]){

    mostrarSave();

    printf("\n\t\t===================================================");
    for(int i = 0; i < 5; i++){

        if(arqSalvo[i].status == 'S'){
            printf("\n\t\t  %d) Arquivo: %s -------------> Status: SALVO", i+1, arqSalvo[i].nomes);
        
        }else if(arqSalvo[i].status == 'R'){
             printf("\n\t\t  %d) Arquivo: %s -------------> Status: RESETADO", i+1, arqSalvo[i].nomes);
        }else{
             printf("\n\t\t  %d) Arquivo: %s -------------> Status: LIVRE", i+1, arqSalvo[i].nomes);
        }
    }
    printf("\n\t\t====================================================");


}

void mostrarSave(){

    printf("\n\n\t\t\t   _____    __      ________  _____ ");
    printf("\n\t\t\t  / ____|  /\\ \\    / /  ____|/ ____|");
    printf("\n\t\t\t | (___   /  \\ \\  / /| |__  | (___  ");
    printf("\n\t\t\t  \\___ \\ / /\\ \\ \\/ / |  __|  \\___ \\ ");
    printf("\n\t\t\t  ____) / ____ \\  /  | |____ ____) |");
    printf("\n\t\t\t |_____/_/    \\_\\/   |______|_____/ ");
                                    
                                  
}

void mostrarMensTRANSF(tipo_arquivo arqSalvo[]){
    int resposta;


    printf("\n\t _______                   __                         _        ");
    printf("\n\t|__   __|                 / _|                       (_)      ");
    printf("\n\t   | |_ __ __ _ _ __  ___| |_ ___ _ __ ___ _ __   ___ _  __ _ ");
    printf("\n\t   | | '__/ _` | '_ \\/ __|  _/ _ \\ '__/ _ \\ '_ \\ / __| |/ _` |");
    printf("\n\t   | | | | (_| | | | \\__ \\ ||  __/ | |  __/ | | | (__| | (_| |");
    printf("\n\t   |_|_|  \\__,_|_| |_|___/_| \\___|_|  \\___|_| |_|\\___|_|\\__,_|");

    printf("\n\t\t/====================================================\\");          
    printf("\n\t\t ->Voce pode transferir ate 5 arquivos salvos"); 
    entraArqSalvos(arqSalvo);
    printf("\n\t\t");                     
    printf("\n\t\t\\====================================================/");             
   
}

 
void entraArqSalvos(tipo_arquivo arqSalvo[]){

    int quant;
    char nomeArqTRANSF[30];
    FILE *arqAux;
    int l = 0, cont = 1;

    printf("\n\t\t  Digite a quantida de arquivos salvos: ");
    scanf("%d", &quant);

    while(quant > 5 || quant <= 0){
         
          
         
        printf("\n\t\t OPPS! VOCE DEVE TER DIGITADO ALGO ERRADO :D");
           
        printf("\n\t\t ->Digite a quantida de arquivos salvos: ");
        scanf("%d", &quant);

    }

    while(arqSalvo[l].status == 'S'){
        l++;    
        cont++;
        quant++;
    }

    for(int i =  l; i < quant; i++){
        
        
        printf("\n\t\t ->Escreva corretamente o nome do arquivo #%d: ", cont);
        scanf("%s", nomeArqTRANSF);
        flush_in();
        
        arqAux = fopen(nomeArqTRANSF , "a+b");
        arqSalvo[i].arq = fopen(nomeArqTRANSF , "a+b");
        
        arqSalvo[i].status = 'S';
        
        if(arqAux == NULL){
            printf("Impossivel criar o arquivo %s\n", nomeArqTRANSF);
            exit(1);
        }

        if(arqSalvo[i].arq == NULL){
            printf("Impossivel criar o arquivo %s\n", nomeArqTRANSF);
            exit(2);
        }

        fwrite(arqAux, sizeof(FILE), 1, arqSalvo[i].arq);
        fclose(arqAux);
        fclose(arqSalvo[i].arq);
        strcpy(arqSalvo[i].nomes, nomeArqTRANSF);
        
        cont++;
    }

}

char escolherDirecao(){

    char escolha [10];

    printf("\nEm que direcao voce gostaria de fazer sua jogada (Esquerda ou Direita)?");
    printf("\n Escolha: ");
    scanf("%s", escolha);
    flush_in();

    if (toupper(escolha[0]) == 'D')
    { //move pela esq ou dir dependendo da primeira letra
        return 'D';
    }

    if (toupper(escolha[0]) == 'E')
    {
        return 'E';
    }
}
               
void monstrarMensBot(){

    
    printf("\n\t\t\t                              .-\"\"\"-.             ");
    printf("\n\t\t\t                            /`       `\\           ");
    printf("\n\t\t\t     ,-==-.                ;           ;      ");
    printf("\n\t\t\t    /(    \\`.              |           |      ");
    printf("\n\t\t\t   | \\ ,-. \\ (             :           ;          ");
    printf("\n\t\t\t    \\ \\`-.> ) 1             \\         /           ");
    printf("\n\t\t\t     \\_`.   | |              `._   _.`            ");
    printf("\n\t\t\t      \\o_`-_|/                _|`\"\'|  -.            ");
    printf("\n\t\t\t     /`  `>.  __          .-'`-|___|_ )           ");
    printf("\n\t\t\t    |\\  \\(^  >'  `>-----._/             )      ");
    printf("\n\t\t\t    | `._\\ /    /      / |      ---   -;  ");
    printf("\n\t\t\t    :     `|   (      (  |      ___  _/            ");
    printf("\n\t\t\t     \\     `.  `\\      \\_\\      ___ _/                ");
    printf("\n\t\t\t      `.     `-='`t----'  `--.______/         ");
    printf("\n\t\t\t        `.   ,-''-.)           |---|              ");
    printf("\n\t\t\t          `.(,-=-./             \\_/               ");
    printf("\n\t\t\t             |   |               V                    ");
    printf("\n\t\t\t             |-''`-.             `.                   ");
    printf("\n\t\t\t          /  ,-'-.\\              `-.                      ");
    printf("\n\t\t\t           |  (      \\                `.                  ");
    printf("\n\t\t\t            \\  \\     |               ,.'              ");
    

     
     
    carregarTela(0.5);
    printf("\n\t  _   _  ___  _____   ______ _________________ ___________  _   _ _   ____  ___  ___   _   _ _____ "); 
    carregarTela(0.5);
    printf("\n\t | | | |/ _ \\|_   _| | ___ \\  ___| ___ \\  _  \\  ___| ___ \\ | | | | | | |  \\/  | / _ \\ | \\ | |  _  |");
    carregarTela(0.5);
    printf("\n\t | | | / /_\\ \\ | |   | |_/ / |__ | |_/ / | | | |__ | |_/ / | |_| | | | | .  . |/ /_\\ \\|  \\| | | | |");
    carregarTela(0.5);
    printf("\n\t | | | |  _  | | |   |  __/|  __||    /| | | |  __||    /  |  _  | | | | |\\/| ||  _  || . ` | | | |");
    carregarTela(0.5);
    printf("\n\t \\ \\_/ / | | |_| |_  | |   | |___| |\\ \\| |/ /| |___| |\\ \\  | | | | |_| | |  | || | | || |\\  \\ \\_/ /");
    carregarTela(0.5);
    printf("\n\t  \\___/\\_| |_/\\___/  \\_|   \\____/\\_| \\_|___/ \\____/\\_| \\_| \\_| |_/\\___/\\_|  |_/\\_| |_/\\_| \\_/\\___/ ");
    printf("\n\t                                                                                                   ");
    carregarTela(0.9);
    
    clear();
    

}
//JOGO AUTOMATICO = JOGO COM BOT
void jogoAUTO(tipo_peca dominoAux[], tipo_jogo *domino, tipo_mesa *tabuleiro, tipo_peca jogador1[], tipo_peca bot[], tipo_peca monte[], tipo_arquivo arqSalvo[]){
    //h_esq -> horizontal esquerda [50] 
    //h_dir -> horizontal direita  [50]
    //quant -> quantidade de colunas no sentido da esquerda 
    //         ou no sentido da direita 
    int   i = 0, aux, quant, cont = 0, cont_1 = 7, cont_2 = 7, posicao, vitoria;

    // veri = verificador para a entrada do usuario nao ultrapasse a borda
    // em ambos sentidos
    int   veri = 0, veri1 = 101;

    // jogador = recebe um valor para demonstrar ao usuario
    //           quem comeca a jogar
    char  escolha;
    bool  sair = false;
    
    //definindo a vez de cada jogador 
    domino->rodadaVez = domino->jogaPrimeiro;

    //Quando o jogo comeca a maior peca do jogo tem que ter seus status alterado
    posicao = acharMaior(domino, jogador1, bot);
    tabuleiro->mapa[50] = domino->j_maiorP1;
    tabuleiro->mapa[51] = domino->j_maiorP2;

    //se for a vez do 1 jogador 
    if(domino->jogaPrimeiro % 2 != 0){

        //peca foi para mesa | -1 = peca foi movida 
        jogador1[posicao].status = 'M';
        jogador1[posicao].p1 = -1;
        jogador1[posicao].p2 = -1;

        domino->quantJ1 = 6;
        domino->quantJ2 = 7;
    }

    if(domino->jogaPrimeiro % 2 == 0){

        bot[posicao].status = 'M';
        bot[posicao].p1 = -1;
        bot[posicao].p2 = -1;

        domino->quantJ1 = 7;
        domino->quantJ2 = 6;
    }

    

    if(domino->jogaPrimeiro % 2 != 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t   JOGADOR 1 JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n\n");

    }
    
    if(domino->jogaPrimeiro % 2 == 0) {
        printf("\n\t\t/================================\\");
        printf("\n\t\t       BOT JOGOU SUA MAIOR PECA!!");
        printf("\n\t\t\\================================/\n");
    }

    cont = 0;
    domino->rodadaVez++;
    domino-> jogou = 0;

    do{ 
        mostrarMenu();
        if(domino->rodadaVez % 2 != 0){
            escolha = menuJogo();
        }
        if(domino->rodadaVez % 2 == 0){
            escolha = 1;
        }

        switch (escolha){

            case 1: //jogar a peça

                if(domino->rodadaVez % 2 != 0) {
                    
                    if(domino-> jogou == 0){
                        
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    JOGADOR 1 IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n\n");
                        definirMaior(domino, jogador1, bot, monte);
                        mostrarMesa(tabuleiro, 0);
                        visualizarPeca(dominoAux, domino, jogador1, bot, monte);
                        alocarPeca(domino, jogador1 , bot, tabuleiro);
                        mostrarMesa(tabuleiro, 1);
                    } else{
                        printf("\n\tVoce ja jogou sua peca!");
                    }

                }
                if(domino->rodadaVez % 2 == 0) {
                    printf("\n\t\t/================================\\");
                    printf("\n\t\t      BOT JOGOU A PECA !!");
                    printf("\n\t\t\\================================/\n");
                    definirMaior(domino, jogador1, bot, monte);
                    jogarPecaBOT(domino, jogador1, bot, monte, tabuleiro, &cont, &cont_1, &cont_2);
                    mostrarMesa(tabuleiro, 1);
                    visualizarPeca(dominoAux, domino, jogador1, bot, monte);
                    domino->rodadaVez ++;
                }

                
            break;

            case 2: //comprar uma peça
                if(domino->rodadaVez % 2 != 0){
                    comprarPeca(domino, jogador1, bot, monte, tabuleiro, &cont, &cont_1, &cont_2);
                }
                limparInterface();
            break;

            case 4:
                //Quando ele digita <E> o aux ja é convetido para negativo
                // por isso: h_esq + aux = h_esq - aux
                if(domino->rodadaVez % 2 != 0) {
                    aux = moverTela(quant);

                    while (( tabuleiro->h_esq + aux) <= veri || ( tabuleiro->h_dir + aux) >= veri1)
                    {
                        
                        printf("\nOPPS!");
                        carregarTela(10);
                        printf("Sua escolha de colunas ultapassou o limite!!");

                        aux = moverTela(quant);
                    }

                    tabuleiro->h_esq = aux +  tabuleiro->h_esq;
                    tabuleiro->h_dir = aux + tabuleiro->h_dir;

                    mostrarMesa(tabuleiro, 1);
                    limparInterface();
                }
                break;
    
            
    
            case 3:
                
                if(domino->rodadaVez % 2 != 0) {
                    mostrarMesa(tabuleiro, 0);
                    definirMaior(domino, jogador1, bot, monte);
                    mostrarMesa(tabuleiro, 0);
                    definirMaior(domino, jogador1, bot, monte);
                    visualizarPeca(dominoAux, domino, jogador1, bot, monte);
                    limparInterface();
                }
                
                break;
            
            case 5: //terminar rodada

                if(domino->rodadaVez % 2 != 0) {
                    domino->rodadaVez++;

                    
                        printf("\n\t\t/================================\\");
                        printf("\n\t\t    BOT IRA JOGAR!!");
                        printf("\n\t\t\\================================/\n\n");
                    


                    domino->jogou = 0;

                    mostrarMesa(tabuleiro, 0);
                    limparInterface();
                }
                break;
            
            case 6://finalizar o jogo (caso fechado)

                if(domino->rodadaVez % 2 != 0) {
                    contarPontos(domino, jogador1, bot);

                    if(domino->pontosJ1 <  domino->pontosJ2){

                        mostrarJ1();
                        imagem();

                    }else if(domino->pontosJ2 <  domino->pontosJ1){
                        mostrarJ2();
                        imagem();

                    }else{
                        printf("empate");

                    }
                    sair = true;
                    limparInterface();
                }
            break;

            case 9: //sair do jogo
                sair = true;
                
            break;
    
            case 7:

                if(domino->rodadaVez % 2 != 0) {
                    mostrarArquivos(arqSalvo);
                    salvarArquivo(domino, jogador1, bot, tabuleiro, monte, arqSalvo);
                    mostrarCarregamento("S A L V A N D O", 0.009, ".."); 
                }
                
            break;
            
            case 8:

                if(domino->rodadaVez % 2 != 0) {
                    mostrarArquivos(arqSalvo);
                    carregarArquivo(domino,jogador1, bot, tabuleiro,  monte, arqSalvo);
                    mostrarCarregamento(" CA R R E G A N D O", 0.009, ".."); 
                }

            break;

            case 0:

                if(domino->rodadaVez % 2 != 0) {
                    mostrarArquivos(arqSalvo);
                    resetarArq(arqSalvo);
                    limparInterface();
                }
            break;
    
            default: //opção inválida >:(
                if(domino->rodadaVez % 2 != 0) {
                    mostrarErro();
                    printf("Opcao invalida!! >:(");
                    limparInterface();
                }
            break;
        }

    } while(sair == false);

}

