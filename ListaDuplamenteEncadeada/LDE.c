#include "LDE.h"

#include <stdlib.h>

void inicializa_lista(LDE *l, size_t t)
{
    l->tamInfo = t;
    l->cabeca = NULL;
}

int insereNoInicio(LDE *l, void *info)
{
    EleDuplo *p = aloca_elemento(l->tamInfo, info);
    if (p == NULL)
        return 0;
    p->proximo = l->cabeca;
    p->anterior = NULL;
    l->cabeca = p;
    if (p->proximo != NULL)
        p->proximo->anterior = p;
    return 1; //Sucesso
}

int removeDoInicio(LDE *l, void *info)
{
    if (l->cabeca == NULL)
        return ERRO_LISTA_VAZIA;

    EleDuplo *p = l->cabeca;
    l->cabeca = p->proximo;

    if(l->cabeca != NULL)
        l->cabeca->anterior = NULL;

    memcpy(info, p->info, l->tamInfo);
    free(p->info);
    free(p);
    return 1; //Sucesso
}

int insereNoFim(LDE *l, void *info)
{
    if(l->cabeca == NULL)
        return insereNoInicio(l, info);

    EleDuplo *aux = l->cabeca;
    while(aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    EleDuplo *p = aloca_elemento(l->tamInfo, info);
    p->proximo = NULL;
    p->anterior = aux;
    aux->proximo = p;
    return 1; //Sucesso
}

int removeDoFim(LDE *l, void *info)
{
    if (l->cabeca == NULL)
        return ERRO_LISTA_VAZIA;

    if(l->cabeca->proximo == NULL)
        return removeDoInicio(l, info);

    EleDuplo *aux = l->cabeca;
    while(aux->proximo->proximo != NULL)
    {
        aux = aux->proximo;
    }
    memcpy(info, aux->proximo->info, l->tamInfo);
    free(aux->proximo->info);
    free(aux->proximo);
    aux->proximo = NULL;
    return 1; //Sucesso
}


int insereNaPosicao(LDE *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;
    if(pos == 0)
        return insereNoInicio(l, info);

    EleDuplo *aux = l->cabeca;
    int cont = 0;
    while(cont < pos-1 && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if(cont != pos-1)
        return ERRO_POSICAO_INVALIDA;

    EleDuplo *novo = aloca_elemento(l->tamInfo, info);
    if(novo == NULL)
        return 0; //Fracasso
    novo->anterior = aux;
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    if(novo->proximo != NULL)
        novo->proximo->anterior = novo;
    return 1; //Sucesso
}

int removeNaPosicao(LDE *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;
    if(pos == 0)
        return removeDoInicio(l, info);

    EleDuplo *aux = l->cabeca;
    int cont = 0;
    while(cont < pos-1 && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if (cont != pos-1 || aux->proximo == NULL)
        return ERRO_POSICAO_INVALIDA;

    memcpy(info, aux->proximo->info, l->tamInfo);

    EleDuplo *aux2 = aux->proximo;

    if(aux2->proximo != NULL)
        aux2->proximo->anterior = aux;
    aux->proximo = aux2->proximo;

    free(aux2->info);
    free(aux2);
    return 1; //Sucesso
}

int insereEmOrdem(LDE *l, void *info, int (*compara_float)(void*, void *))
{
    int cont = 0;
    EleDuplo *aux = l->cabeca;
    while(aux != NULL && compara_float(aux->info, info) < 0)
    {
        aux = aux->proximo;
        cont++;
    }
    return insereNaPosicao(l, info, cont);
}

int removeInfo(LDE *l, void *info)
{
    if(l->cabeca == NULL)
        return ERRO_LISTA_VAZIA;
    int cont = 0;
    EleDuplo *aux = l->cabeca;
    while(aux->proximo != NULL && memcmp(aux->info, info, l->tamInfo) != 0)
    {
        aux = aux->proximo;
        cont++;
    }
    if (memcmp(aux->info, info, l->tamInfo) == 0)
        return removeNaPosicao(l, info, cont);
}

int modificaNaPosicao(LDE *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;

    EleDuplo *aux = l->cabeca;
    int cont = 0;
    while(cont != pos && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if(cont != pos)
        return ERRO_POSICAO_INVALIDA;
    memcpy(aux->info, info, l->tamInfo);
    return 1; //Sucesso
}

int leNaPosicao(LDE *l, void *info, int pos)
{
    if(pos < 0)
        return ERRO_POSICAO_INVALIDA;

    EleDuplo *aux = l->cabeca;
    int cont = 0;
    while(cont != pos && aux->proximo != NULL)
    {
        aux = aux->proximo;
        cont++;
    }
    if(cont != pos)
        return ERRO_POSICAO_INVALIDA;
    memcpy(info, aux->info, l->tamInfo);
    return 1; //Sucesso
}

EleDuplo *aloca_elemento(size_t t, void *info)
{
    EleDuplo *p;
    p = (EleDuplo*) malloc(sizeof(EleDuplo));

    if(p == NULL)
        return NULL;

    p->info = malloc(t);
    if (p->info == NULL)
    {
        free(p);
        return NULL;
    }
    memcpy(p->info, info, t);
    return p;
}

void mostra_lista(LDE l, void (*mostra_info)(void *))
{
    EleDuplo *aux = l.cabeca;
    if (aux == NULL)
        return;

    int cont = 0;
    while(aux != NULL)
    {
        printf("%d: ", cont++);
        mostra_float(aux->info);
        aux = aux->proximo;
    }
}

void mostra_lista_invertida(LDE l, void (*mostra_info)(void *))
{
    EleDuplo *aux = l.cabeca;
    if (aux == NULL)
        return;

    int cont = 0;
    while(aux->proximo != NULL)
    {
        aux = aux->proximo;
    }
    while(aux != NULL)
    {
        printf("%d: ", cont++);
        mostra_float(aux->info);
        aux = aux->anterior;
    }
}
