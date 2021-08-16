#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "pilha.h"

struct elemento {
    struct jogador pecas;
    struct elemento *prox;
};

typedef struct elemento Elem;
// struct elemento ** = Lista *

// Funções
Lista* criar(){
    Lista *l; // struct elemento ** l;
    l = (Lista*)malloc(sizeof(Lista));
    if (l == NULL) {
        printf("Não foi possível alocar\n");
        return NULL;
    }
    *l = NULL;
    return l;
}

int inserirInicio(Lista *l,struct jogador j) {
    if (l == NULL) {
        printf("Lista não existe\n");
        return 0;
    }
    else {
        struct elemento *novo; // Elem *novo;
        novo = (struct elemento *)malloc(sizeof(struct elemento));
        if (novo == NULL) {
            printf("Alocação inválida\n");
            return 0;
        }
        novo->pecas = j;
        novo->prox = *l;
        *l = novo;
        return 1;
    }
}
void showPecas(Lista* jooj){

    Elem *aux = NULL;
    aux = (*jooj);
    printf("Jogadores\n-----------\n");
    while (aux != NULL)
    {
        puts(aux->pecas.play);
        int aux1 = aux->pecas.andar;
        int aux2 = aux->pecas.parque;
        int aux3 = aux->pecas.teto;
        //printf("Andar: %d ", jooj->pecas.andar;);
        printf("Andar: %d\n", aux1);
        printf("Parque: %d\n",aux2);
        printf("Teto: %d\n", aux3);
        aux = aux->prox;
        printf("-----------\n");
    }

}

int acessarPorIndice (Lista *l, int indice,struct jogador *achou) {
    if (l == NULL) {
        printf("Lista não existe\n");
        return 0;
    }
    else if (*l == NULL) {
        printf("Lista vazia\n");
        return 0;
    }
    else if (indice < 0) {
        printf("Indice negativo\n");
        return 0;
    }
    else {
        struct elemento *aux;
        aux = *l;
        int cont = 0;
        while (aux != NULL && indice != cont) {
            aux = aux->prox;
            cont++;
        }
            if (aux == NULL) {
                printf("Indice maior do que a lista\n");
                return 0;
        }
        *achou = aux->pecas;

        return 1;
    }
}
int retirar(Lista *l, int indice, int peca, int rodada){
    if(l == NULL || *l == NULL){
        return 0;

    }
    Elem *aux = NULL;
    aux = *l;
    int cont = 0;
        while (aux != NULL && indice != cont) {
            aux = aux->prox;
            cont++;
        }
            if (aux == NULL) {
                printf("Indice maior do que a lista\n");
                return 0;
        }
        if(peca == 3){
            aux->pecas.andar--;
        }
        else if(peca == 2){
            aux->pecas.parque--;
        }
        else if(peca == 1){
            aux->pecas.teto--;

        }
        aux->pecas.jog = rodada;
        return 1;
}
void destruirLista(Lista *l) {
    if (l != NULL) {
        struct elemento *aux;
        while (*l != NULL) {
            aux = *l;
            *l = aux->prox;
            free(aux);
        }
        free(l);
    }
}
