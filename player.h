
struct jogador{
    char play[12];
    int jog;
    int teto;
    int andar;
    int parque;
};

typedef struct elemento* Lista; // Lista (struct elemento *)

Lista* criar();

int inserirInicio(Lista* ,struct jogador );

int acessarPorIndice (Lista* , int , struct jogador* );

void mpecas(Lista* , struct jogador );

void showPecas(Lista* );

int retirar(Lista*, int, int, int);

int contarRodada(Lista*, int );

void destruirLista(Lista*);

