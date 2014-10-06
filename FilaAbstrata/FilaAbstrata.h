#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdlib.h>

#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct {
    void **dados;
    int inicio, fim, capacidade;
    size_t tamInfo;
    int num_ele;
} Fila;

void inicializa_fila(Fila *f, int cap, size_t tamInfo);
int inserir(Fila *f, void *info);
int remover(Fila *f, void *y);
int fila_cheia(Fila f);
int fila_vazia(Fila f);

void mostra_fila(Fila f, void (*mostra_info)(void *));

#endif // FILA_H_INCLUDED
