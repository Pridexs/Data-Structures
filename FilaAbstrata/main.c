#include <stdio.h>
#include <stdlib.h>

#include "FilaGenerica.h"

void mostra_float(void *info);

int main()
{
    Fila f1;
    float y, x;
    inicializa_fila(&f1, 50, sizeof(float));
    x = 2.1;
    inserir(&f1, &x);
    x = 4.5;
    inserir(&f1, &x);
    x = 10.4;
    inserir(&f1, &x);
    mostra_fila(f1, mostra_float);

    remover(&f1, &y);
    //printf("%d\n", y);

    return 0;
}

void mostra_float(void *info) 
{
    float *p = (float*)info;
    printf("%f\n", *p);
}
