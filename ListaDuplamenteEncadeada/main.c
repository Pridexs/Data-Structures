#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

void mostra_float(void *);
int compara_float(void *, void *);

int main()
{
    LDE l1;
    inicializa_lista(&l1, sizeof(float));
    float x = 7.0, y;
    insereNoInicio(&l1, &x);
    x = 2.0;
    insereNoInicio(&l1, &x);
    x = 3.5;
    insereNoFim(&l1, &x);
    x = 3.4;
    insereNoFim(&l1, &x);
    x = 3.2;
    insereNoFim(&l1, &x);
    mostra_lista_invertida(l1, mostra_float);
    removeDoFim(&l1, &y);
    printf("-- Removido do Fim\n");
    mostra_lista_invertida(l1, mostra_float);

    x = 3.6;
    insereNaPosicao(&l1, &x, 1);
    printf("-- Insere 3.6 na pos 2\n");
    mostra_lista_invertida(l1, mostra_float);

    return 0;
}

void mostra_float(void *info)
{
    float *p = (float*)info;
    printf("%f\n", *p);
}

int compara_float(void *a, void *b)
{
    float *p1 = (float*) a;
    float *p2 = (float*) b;

    if (*p1 == *p2)
        return 0;
    if (*p1 > *p2)
        return 1;
    return -1;
}
