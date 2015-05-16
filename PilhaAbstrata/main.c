#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaAbstrata.h"

void mostra_float(void *info);

int main()
{
    PilhaGenerica p1;
    inicializa_pilha(&p1, 50, sizeof(float));
    float x = 5;
    empilha(&p1, &x); //Deve testar se nao esta cheia
    x = 12;
    empilha(&p1, &x);
    mostra_pilha(p1, mostra_float);
    if(deleta_pilha(&p1) == 0)
        printf("Pilha deletada\n");

    return 0;
}

void mostra_float(void *info) 
{
    float *p = (float*)info;
    printf("%f\n", *p);
}
