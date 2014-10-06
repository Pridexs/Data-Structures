#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>

#define ERRO_ALOCACAO -1

typedef struct elemento {
    void *info;
    struct elemento *proximo;
} Elemento;

typedef struct {
    size_t tamInfo;
    Elemento *cabeca;
} Lista;

void inicializa_lista(Lista *l, size_t t);
void mostra_lista(Lista l, void (*mostra_info)(void *));

int insereNoInicio(Lista *l, void *info);


#endif // LISTA_H_INCLUDED
