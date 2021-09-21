#### PORTUGUESE

# Domino_Game
- Projeto feito no 2 periodo da faculdade para aula de LP
- LP(Laboratório de Programação)
 ## 2º Período do curso de  Ciência da Computação da PUC SP
 - Implementação do Domino_Game modelado pelo método MVC
 - Utilizei tudo que aprendi durante o 1º período e 2º período

# -Regras de jogo:
  As regras do jogo são bem simples: cada jogador pega sete peças e pode comprar sempre que precisar de uma peça para poder jogar e quantas vezes for necessário. Dá-se início ao jogo o jogador que tirar a pedra “seis-seis”. Caso ninguém tenha o tirado, inicia-se o jogador que tiver a peça com os números repetidos mais altos, ou seja, “cinco -cinco”, “quatro-quatro”, e assim sucessivamente. 

  O jogo acontece no sentido anti-horário e os jogadores devem colocar peças que tenham os mesmos números das peças que se encontram na ponta do jogo. O jogador que começa a partida leva vantagem. Este é um conceito importante para a estratégia do dominó, pois o jogador que começa, normalmente, é o que leva a vantagem durante a partida. Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincidam com os pontos da extremidade onde está sendo colocada. 

  Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador. Se um jogador não puder jogar, deverá “comprar” do monte tantas peças como forem necessárias. Se não houver peças no monte, passará o turno ao seguinte jogador. A partida continua com os jogadores colocando suas peças sobre a mesa até que se apresente alguma das seguintes situações:
  
  - Quando um jogador coloca sua última pedra na mesa, essa ação é chamada de bater. Quando joga-se sozinho, o jogador que ganhou a partida soma os pontos de todos os seus adversários. Jogando em dupla, somam-se os pontos de todos os jogadores incluindo os do seu companheiro.

  - Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o número das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida está fechada. Os jogadores contarão os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se os pontos da maneira habitual.

  - Pode acontecer de você ter os mesmos pontos que o jogador ou a dupla que tem a vantagem, nesse caso, ganha este jogador.

# -Desenvolvimento dos Modulos

    O projeto foi dividido em 4 módulos:

    - Model;
    - View;
    - Data;
    - Controller;
    
    O módulo "Model" possui as funções relacionadas com a lógica do jogo (inicialização de peças, jogadas, etc.), veja abaixo um trecho de exemplo, uma função qe embaralha as 28 peças do domino:

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
O módulo "View" possui as funções relacionadas com a interação com o usuário (exibição de menus, textos, etc.), veja abaixo um trecho de exemplo, a função que exibe o menu principal:
void menu()
{ 

    mostrarNome();

    printf("\n\t\t    _________________ \t\t      ***********************                    _________________");
    printf("\n\t\t    ||             || \t\t\t     Bem-Vindo                           ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t\t        ao                               ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t\t       Jogo                              ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t      ***********************                    ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t\t  -=--=DOMINO=--=-                       ||             ||");
    printf("\n\t\t    ||  O       O  ||     _________________________________________________      ||  O       O  ||");
    printf("\n\t\t    ||_____________|| \t\t >Pressione  <1> para jogar                      ||_____________||");
    printf("\n\t\t    ||             || \t\t >Pressione  <2> para embaralhar as pecas        ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <3> para organizar as pecas         ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t >Pressione  <4> para mostrar as pecas           ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <5> para mostrar as regras          ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t >Pressione  <6> para sair                       ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t                                                 ||  O       O  ||");
    printf("\n\t\t    ||_____________||    __________________________________________________      ||_____________||");
}

O módulo "Data" possui as funções ao salvamento e carregamento do jogo, veja abaixo um trecho de exemplo, a função que realiza o salvamento:
void salvarArquivo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro, tipo_peca monte[], tipo_arquivo arqSalvo[]){

    int n;

    printf("\nDigite em que espaco da memoria voce quer salvar esse arquivo: ");
    scanf("%d", &n);
    while(n <= 0 || n > 5){

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

Por fim, o módulo "Controller", que faz o intermédio entre os demais módulos, veja abaixo um trecho de exemplo, onde temos a declaração das variáveis:
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
...}

#### ENGLISH

# Domino_Game
- Project done in the 2nd semester of college for LP class
- LP (Programming Laboratory)
 ## 2nd Period of the Computer Science course at PUC SP
 - Domino_Game implementation modeled by the MVC method
 - I used everything I learned during the 1st period and 2nd period

# -Game Rules:
  The game rules are very simple: each player takes seven pieces and can buy whenever he needs a piece to play and as many times as necessary. The game starts the player who removes the “six-six” stone. If no one has taken it, the player who has the piece with the highest repeated numbers starts, that is, “five-five”, “four-four”, and so on.

  The game runs counterclockwise and players must place pieces that have the same numbers as the pieces at the end of the game. The player who starts the game has the advantage. This is an important concept for dominoes strategy, as the starting player is usually the one with the advantage during the game. Each player, on his turn, must place one of his pieces on one of the 2 open ends, so that the points on one side coincide with the points on the end where it is being placed.

  When the player places his piece on the table, his turn is over and it happens to the following player. If a player cannot play, he must “buy” from the pile as many pieces as necessary. If there are no pieces in the pile, it will pass the turn to the next player. The game continues with players placing their pieces on the table until any of the following situations arise:
  
  - When a player places their last stone on the table, this action is called hitting. When playing alone, the player who won the match adds up the points of all his opponents. Playing in pairs, the points of all players are added up including those of your partner.

  - There are cases where none of the players can continue the match. This occurs when the number of ends came out 7 times before. At that moment it is said that the match is closed. Players will count the points of the stones that are left; the player or pair with the fewest points wins and the points are added up in the usual way.

  - It may happen that you have the same points as the player or the pair that has the advantage, in which case, this player wins.

# -Development of Modules

    The project was divided into 4 modules:

    - Model;
    - View;
    - Data;
    - Controller;
    
    The "Model" module has the functions related to the game logic (initialization of pieces, moves, etc.), see below an example excerpt, a function that shuffles the 28 pieces of the domino:

void embaralhar(dominoAux_part_type[], int array_size)
{
    srand(time(NULL)); //randomize the pieces
    int r, exchange;

    for (int i = array_size - 1; i >0; i--)
    {
        r = rand() % array_size;
        swap = dominoAux[i].p1;
        dominoAux[i].p1 = dominoAux[r].p1;
        dominoAux[r].p1 = swap;
        swap = dominoAux[i].p2;
        dominoAux[i].p2 = dominoAux[r].p2;
        dominoAux[r].p2 = swap;
    }
}

The "View" module has the functions related to the interaction with the user (display of menus, texts, etc.), see below an example excerpt, the function that displays the main menu:
void menu()
{ 

    mostrarNome();

    printf("\n\t\t    _________________ \t\t      ***********************                    _________________");
    printf("\n\t\t    ||             || \t\t\t     Bem-Vindo                           ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t\t        ao                               ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t\t       Jogo                              ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t      ***********************                    ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t\t  -=--=DOMINO=--=-                       ||             ||");
    printf("\n\t\t    ||  O       O  ||     _________________________________________________      ||  O       O  ||");
    printf("\n\t\t    ||_____________|| \t\t >Pressione  <1> para jogar                      ||_____________||");
    printf("\n\t\t    ||             || \t\t >Pressione  <2> para embaralhar as pecas        ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <3> para organizar as pecas         ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t >Pressione  <4> para mostrar as pecas           ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t >Pressione  <5> para mostrar as regras          ||  O       O  ||");
    printf("\n\t\t    ||             || \t\t >Pressione  <6> para sair                       ||             ||");
    printf("\n\t\t    ||  O       O  || \t\t                                                 ||  O       O  ||");
    printf("\n\t\t    ||_____________||    __________________________________________________      ||_____________||");
}

The "Data" module has the functions to save and load the game, see below an example excerpt, the function that performs the save:
void salvarArquivo(tipo_jogo *domino, tipo_peca jogador1[], tipo_peca jogador2[], tipo_mesa *tabuleiro, tipo_peca monte[], tipo_arquivo arqSalvo[]){

    int n;

    printf("\nDigite em que espaco da memoria voce quer salvar esse arquivo: ");
    scanf("%d", &n);
    while(n <= 0 || n > 5){

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

Finally, the "Controller" module, which is the intermediary between the other modules, see below an example excerpt, where we have the declaration of the variables:

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
...}

