#include "FilaAbstrataPrioridade.h"
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

int inserir(Fila *f, void *info, float (*compara_info)(void*,void*)) 
{
    if(fila_cheia(*f))
        return ERRO_FILA_CHEIA;
    int atual = f->fim;
    int anterior = ant(atual, f->capacidade);
    int cont = 0;
    while (cont < f->num_ele && compara_info(f->dados[anterior],info)) 
    {
        f->dados[atual] = f->dados[anterior];
        atual = anterior;
        anterior = ant(atual, f->capacidade);
        cont++;
    }
    f->dados[atual] = malloc (f->tamInfo);
    memcpy(f->dados[atual], info, f->tamInfo);
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

int ant(int index, int cap) 
{
    if(index == 0)
        return cap-1;
    else
        return index-1;
}
