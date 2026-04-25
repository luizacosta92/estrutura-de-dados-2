#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"   

typedef struct Lista {
    Nodo *inicio;
    int tamanho;
} Lista;    

Lista* criar_lista();
void insere_lista(Lista *lista, void *dado);
void destroi_lista(Lista *lista);

int get_quantidade(Lista *lista);
Nodo* get_inicio(Lista *lista);

#endif