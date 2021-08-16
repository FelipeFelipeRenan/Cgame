/*struct peca{
    int teto;
    int andar;
    int parque;
};
*/


typedef struct elemento* Pilha;

Pilha* criaP();

void rp(Pilha* p[5][5]);

int vazia(Pilha*);

int empilha(Pilha* , int);

int tamanho(Pilha *);

int topo(Pilha* p);

int show(Pilha* p[5][5]);

void destruirPilha(Pilha*);
