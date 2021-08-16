#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "pilha.h"
#include "player.h"

int main()
{
    setlocale(LC_ALL, "portuguese");
    printf("SkyLiners!\n\n");

    // criando o tabuleiro e os jogadores
    Pilha* mat[5][5];

    struct jogador j;
    Lista* jooj = NULL;
    jooj = criar();
    //pondo os quatro jogadores na lista
    strcpy(j.play, "Leste");
    j.jog = 4;
    j.andar = 12;
    j.parque = 1;
    j.teto = 2;
    inserirInicio(jooj, j);

    strcpy(j.play, "Norte");
    j.jog = 3;
    j.andar= 12;
    j.parque = 1;
    j.teto = 2;
    inserirInicio(jooj, j);

    strcpy(j.play, "Oeste");
    j.jog = 2;
    j.andar= 12;
    j.parque = 1;
    j.teto = 2;
    inserirInicio(jooj, j);

    strcpy(j.play, "Sul");
    j.jog = 1;
    j.andar= 12;
    j.parque = 1;
    j.teto = 2;
    inserirInicio(jooj, j);

    showPecas(jooj);

    // Criar as posiçoes no tabuleiro
    for(int i = 0; i<=4; i++){
        for(int j=0;j <=4; j++){
            mat[i][j] = criaP();
        }
    }
    // gerar aleatorios rp == random positions
    rp(mat);

    // Mostrar matriz

    printf("\n");
    show(mat);

    // partida

    int rodada = 1,saida = 0, i = 0;
    // structs criadas de ultima hora pra resolver o problema de ter rodadas iguais
    struct jogador cont1,cont2, cont3, cont4;
    while(saida == 0){
        if(i == 4){
            i = 0;
            rodada++;
        }
        struct jogador aux;
        acessarPorIndice(jooj, i, &aux);

        int opt, lin, col;

        printf("Jogador com vista para o ");
        puts(aux.play);

        printf("\nEscolha: 1: Andar[%d] | 2: Parque[%d] | 3: Teto[%d]\n", aux.andar, aux.parque, aux.teto);
        scanf("%d", &opt);
        while(opt < 0 || opt > 3){
            printf("Opção inválida, digite uma disponivel: ");
            while( getchar() != '\n' );
            scanf("%d", &opt);

        } // grande switch-case para checar e empilhar
        switch(opt){
            case 1:
                if(aux.andar > 0){
                    printf("Escolha a linha: ");
                        while( getchar() != '\n' );
                        scanf("%d", &lin);

                    printf("\nEscolha a coluna: ");
                        while( getchar() != '\n' );
                        scanf("%d", &col);

                    while(lin > 5 || col > 5 || lin < 1 || col < 1){
                     //validação das posições
                        printf("Posição inválida, Escolha alguma disponível\n");

                        printf("Escolha a linha: ");
                        while( getchar() != '\n' );
                        scanf("%d", &lin);

                        printf("\nEscolha a coluna: ");
                        while( getchar() != '\n' );
                        scanf("%d", &col);

                    }
                //Colocando a peça
                if((topo(mat[lin - 1][col - 1]) != 1 && topo(mat[lin - 1][col - 1]) != 2)){
                    empilha(mat[lin - 1][col - 1], 3);
                    retirar(jooj, i, 3, rodada);
                }else{
                    printf("Não pode por a peça em cima de telhados ou parques!\n\n");
                }
                }
                else{
                    printf("Não possui mais andares!");
                }
            break;

            case 2:
                if(aux.parque > 0){
                    printf("Escolha a linha: ");
                        scanf("%d", &lin);

                        printf("\nEscolha a coluna: ");
                        scanf("%d", &col);
                        while(lin > 5 || col > 5 || lin < 1 || col < 1){
                         //validação das posições
                            printf("Posição inválida, Escolha alguma disponível\n");
                            printf("Escolha a linha: ");
                            while( getchar() != '\n' );
                            scanf("%d", &lin);
                            printf("\nEscolha a coluna: ");
                            while( getchar() != '\n' );
                            scanf("%d", &col);
                        }
                        //Colocando a peça
                    if((topo(mat[lin - 1][col - 1]) != 1 && topo(mat[lin - 1][col - 1]) != 2)){
                        empilha(mat[lin - 1][col - 1], 2);
                        retirar(jooj, i, 2,rodada );
                    }
                    else{
                        printf("Não pode por a peça em cima de telhados ou parques!\n\n");
                    }
                }
                else{
                    printf("Não possui mais parques!\n");
                }

            break;

            case 3:
                if(aux.teto > 0){
                    printf("Escolha a linha: ");
                        scanf("%d", &lin);

                        printf("\nEscolha a coluna: ");
                        scanf("%d", &col);
                        while(lin > 5 || col > 5 || lin < 1 || col < 1){
                            //validação das posições
                            printf("Posição inválida, Escolha alguma disponível\n");
                            printf("Escolha a linha: ");
                            while( getchar() != '\n' );
                            scanf("%d", &lin);
                            printf("\nEscolha a coluna: ");
                            while( getchar() != '\n' );
                            scanf("%d", &col);
                        }
                    //Colocando a peça
                    if((topo(mat[lin - 1][col - 1]) != 1 && topo(mat[lin - 1][col - 1]) != 2)){
                        empilha(mat[lin - 1][col - 1], 1);
                        retirar(jooj, i, 1, rodada);
                    }else{
                        printf("Não pode por a peça em cima de telhados ou parques!\n\n");
                    }
                    }
                else{
                    printf("Não possui mais teto!");
                }


            break;
        default:
            printf("Opção inválida!\n");

        }
        show(mat);
        // usei essas structs extras pra ver a rodada, eu nao tinha visto que ter rodadas iguais era uma condição
        //de parada, ai fiz isso as exatas 18:22 de 23/04/2021
        acessarPorIndice(jooj, 0, &cont1);
        acessarPorIndice(jooj, 1, &cont2);
        acessarPorIndice(jooj, 2, &cont3);
        acessarPorIndice(jooj, 3, &cont4);


        printf("%d\n", cont1.jog);
        printf("%d\n", cont1.jog);
        printf("%d\n", cont1.jog);
        printf("%d\n", cont1.jog);
    //Condição de parada(Vitoria )
    if(aux.andar == 0 && (cont1.jog == cont2.jog && cont2.jog == cont3.jog && cont3.jog == cont4.jog) ){
        printf("Jogador com vista para o ");
        puts(aux.play);
        printf(" venceu!\n");
        printf("%d", aux.jog);
        break;
        }
    i++;
    }
    // Destruindo a pilha e a lista;
    destruirLista(jooj);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            destruirPilha(mat[i][j]);
        }
    }
    return 0;
}
