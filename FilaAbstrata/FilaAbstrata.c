#include "FilaAbstrata.h"
#include <string.h>
#include <stdlib.h>

void inicializa_fila(Fila *f, int cap, size_t tamInfo) 
{
    f->capacidade = cap;
    f->tamInfo = tamInfo;
    f->dados = (int*) malloc(sizeof(int) * cap);
    f->inicio = f->fim  = 0;
    f->num_ele = 0;
}

int inserir(Fila *f, void *info) 
{
    if(fila_cheia(*f))
        return ERRO_FILA_CHEIA;
    f->dados[f->fim] = malloc (f->tamInfo);
    memcpy(f->dados[f->fim], info, f->tamInfo);
    f->fim++;
    f->num_ele++;
    if (f->fim == f->capacidade)
        f->fim = 0;
    return 0;
}

int remover(Fila *f, void *y) 
{
    if(fila_vazia(*f))
        return ERRO_FILA_VAZIA;
    memcpy(y, f->dados[f->inicio], f->tamInfo);
    free(f->dados[f->inicio]);
    f->inicio++;
    f->num_ele--;
    if(f->inicio == f->capacidade)
        f->inicio = 0;
    return 0;
}

int fila_cheia(Fila f) 
{
    return f.num_ele == f.capacidade;
}

int fila_vazia(Fila f) 
{
    return f.num_ele == 0;
}

void mostra_fila(Fila f, void (*mostra_info)(void *)) 
{
    if(fila_vazia(f))
        return ERRO_FILA_VAZIA;
    int i = f.inicio;
    int n = f.num_ele;
    while(n--) 
    {
        mostra_info(f.dados[i]);
        i++;
        if (i == f.capacidade)
            i = 0;
    }
}
