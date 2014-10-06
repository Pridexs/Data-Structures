#include <stdio.h>
#include <stdlib.h>

#include "FilaAbstrataPrioridade.h"

void mostra_float(void *info);
float compara_float(void *x, void *y);

int main()
{
    Fila f1;
    float y, x;
    inicializa_fila(&f1, 5, sizeof(float));
    x = 2.1;
    inserir(&f1, &x, compara_float);
    x = 4.5;
    inserir(&f1, &x, compara_float);
    x = 10.4;
    inserir(&f1, &x, compara_float);
    x = 5.4;
    inserir(&f1, &x, compara_float);
    remover(&f1, &y);
    inserir(&f1, &x, compara_float);
    x = 12.0;
    inserir(&f1, &x, compara_float);
    x = 15.0;

    mostra_fila(f1, mostra_float);
    printf("Inicio: %d, Fim: %d, nElementos: %d\n", f1.inicio, f1.fim, f1.num_ele);
    remover(&f1, &y);
    printf("%f\n", y);

    return 0;
}

void mostra_float(void *info) 
{
    float *p = (float*)info;
    printf("%f\n", *p);
}

float compara_float(void *x, void *y) 
{
    float *a = (float*)x;
    float *b = (float*)y;
    return (*a  < *b);
}
