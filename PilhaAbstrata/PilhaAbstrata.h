#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdlib.h> // Para incluir size_t

#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2

typedef struct 
{
    void **dados;
    int topo;
    int capacidade;
    size_t tamInfo;
} PilhaGenerica;

void inicializa_pilha(PilhaGenerica *p, int c, size_t tam);
void mostra_pilha(PilhaGenerica p, void (*mostra_info)(void *));

int empilha(PilhaGenerica *p, void *info);
int desempilha(PilhaGenerica *p, void *info);
int pilha_vazia(PilhaGenerica p);
int pilha_cheia(PilhaGenerica p);


#endif // PILHA_H_INCLUDED
