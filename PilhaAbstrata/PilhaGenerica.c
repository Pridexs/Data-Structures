#include "PilhaGenerica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void inicializa_pilha(PilhaGenerica *p, int c, size_t tam) 
{
    p->topo = -1;
    p->capacidade = c;
    p->tamInfo = tam;
    p->dados = (void**) malloc(sizeof(void*) * c);
}
void mostra_pilha(PilhaGenerica p, void (*mostra_info)(void *)) 
{
    int i;
    if(pilha_vazia(p)) 
    {
        printf("Pilha vazia\n");
        return;
    }
    printf("Topo -> ");
    for(i = p.topo; i >= 0; i--) 
    {
        (*mostra_info)(p.dados[i]);
    }
}

int empilha(PilhaGenerica *p, void *info) 
{
    if(pilha_cheia(*p))
        return ERRO_PILHA_CHEIA;
    p->topo++;
    p->dados[p->topo] = malloc(p->tamInfo);
    memcpy(p->dados[p->topo], info, p->tamInfo);
    return 0; //Sucesso
}

int desempilha(PilhaGenerica *p, void *info) 
{
    if(pilha_vazia(*p))
        return ERRO_PILHA_VAZIA;
    memcpy(info, p->dados[p->topo], p->tamInfo);
    free(p->dados[p->topo]);
    p->topo--;
    return 0; //Sucesso
}

int pilha_vazia(PilhaGenerica p) 
{
    return p.topo == -1;
}

int pilha_cheia(PilhaGenerica p) 
{
    return p.topo == p.capacidade-1;
}

