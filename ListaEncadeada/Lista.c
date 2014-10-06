#include "Lista.h"
#include <stdlib.h>


void inicializa_lista(Lista *l, size_t t)
{
    l->tamInfo = t;
    l->cabeca = NULL;
}

int insereNoInicio(Lista *l, void *info)
{
    Elemento *p = (Elemento*) malloc(sizeof(Elemento));
    if(p == NULL)
        return ERRO_ALOCACAO;
    p->info = malloc(l->tamInfo);
    if(p->info == NULL)
    {
        free(p);
        return ERRO_ALOCACAO;
    }
    memcpy(p->info, info, l->tamInfo);
    p->proximo = l->cabeca;
    l->cabeca = p;
    return 1; //Sucesso
}

void mostra_lista(Lista l, void (*mostra_info)(void *))
{
    Elemento *aux = l.cabeca;
    if (aux == NULL)
        return;

    int cont = 0;
    while(aux != NULL)
    {
        printf("%d: ", ++cont);
        mostra_float(aux->info);
        aux = aux->proximo;
    }
}
