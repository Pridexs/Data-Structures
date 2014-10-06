#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void mostra_float(void *);

int main()
{
    Lista l1;
    inicializa_lista(&l1, sizeof(float));
    float x = 5.0;
    insereNoInicio(&l1, &x);
    x = 3.0;
    insereNoInicio(&l1, &x);
    x = 2.0;
    insereNoInicio(&l1, &x);
    mostra_lista(l1, mostra_float);
    return 0;
}

void mostra_float(void *info) 
{
    float *p = (float*)info;
    printf("%f\n", *p);
}
