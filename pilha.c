#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pilha.h"
#include "player.h"


struct elemento{
    int peca;
    struct elemento *prox;
    int qtd;
};
typedef struct elemento Elem;

Pilha* criaP(){
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi == NULL){
        //pi->qtd = 0;
    }

    return pi;
}
void rp(Pilha *mat[5][5]){

    srand(time(NULL));
    int var,var2;

    printf ("Posições já ocupadas:\n\n");
    printf("Linha  | Coluna\n");
    printf("----------------\n");

    for (int i = 0; i < 6; i++)
    {
        var = rand () % 5; //Gerando dois numeros aleatorios
        var2 = rand () % 5;

    // verificando se os numeros nao coincidem com a posição do parque (2,2)
    // Repetição pra gerar dois valores diferentes e dentro da area proxima ao parque
    while(var == 0 || var == 4  || var2 == 0 || var2 == 4 || (var == 2 && var2 == 2)){
            var = rand () % 5;
            var2 = rand() % 5;
    }

    empilha(mat[var][var2], 3);

    printf("  %d    |    %d  |\n", var, var2);
    printf("----------------\n");
}
    printf("\n");
    }

int vazia(Pilha *pe) {
    if (pe == NULL) {
        return -1;
        printf("VAZIA\n");
    }
    else if (*pe == NULL) {

        return 1;
    }
    else {

        return 0;
    }
}

int empilha(Pilha *pe, int individuo){

    if (pe == NULL)
        return 0;
    if (vazia(pe)){
        Elem *novo = (Elem*)malloc(sizeof(Elem));
        if (novo == NULL){
            return 0;
        }
        novo->peca = individuo;
        novo->prox = NULL;
        *pe = novo;

        return 1;
    }
    else {
        Elem *novo = (Elem*)malloc(sizeof(Elem));
        if (novo == NULL){
            return 0;
        }
        novo->peca = individuo;

        novo->prox = *pe;
        *pe = novo;
        return 1;
    }
}

int tamanho(Pilha *pe){
    int tam = 0;
    if(pe == NULL){
        return 0;
    }
    else if(vazia(pe)){
        return 0;
    }
    Elem *aux = *pe;
    while(aux != NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;

}

int topo(Pilha *pe){
    int ult;
    if (pe == NULL)
        return 0;
    else if (vazia(pe)){
        return 0;
    }
    else{
       ult = (*pe)->peca;
       return ult;
    }
}
void destruirPilha(Pilha *p){
    if(p != NULL){
        Elem *aux;
        while(*p != NULL){
            aux = *p;
            *p = (*p)->prox;
            free(aux);
        }
        free(p);
    }
}


int show(Pilha *mat[5][5]){
    printf("\t\t\t  Norte\n\n");
    printf("                 -----------------------\n");
    for(int i = 0; i<5; i++){
        for(int j=0;j <5; j++){
            if(j == 0){
                if(i == 2){
                    printf("         Oeste  ");

                }
                else{
                    printf("                ");
                }
            }
            if(i == 2 && j == 2){
                printf(" [P] ");
                continue;
            }
            if(topo(mat[i][j]) == 2 || topo(mat[i][j]) == 1){
                printf("|[%d]|", tamanho(mat[i][j]));

            }
            else if(topo(mat[i][j]) == 3){
                printf("| %d |",tamanho(mat[i][j]));
            }
            else{
                printf("|   |");
            }
            if(j == 4){
                if(i == 2){
                    printf("  %d  Leste\n", i + 1);
                }else{
                    printf("  %d\n", i + 1 );
            }
            }
        }
                printf("                 -----------------------\n");
    }
    printf("                  1    2    3    4    5\n\n");
    printf("\t\t\t  Sul\n\n");

    return 0;
}
