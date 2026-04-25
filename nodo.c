#include <stdlib.h>
#include "nodo.h"

Nodo* criar_nodo(void *dado) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    if (novo == NULL) 
        return NULL; 

    novo->dado = dado;
    novo->proximo = NULL;
    return novo;
}

void destroi_nodo(Nodo *nodo) {
    if (nodo == NULL) 
        return;
    free(nodo);
}