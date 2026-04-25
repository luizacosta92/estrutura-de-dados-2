#include <stdlib.h>
#include "nodo.h"

Nodo* criar_nodo(void *dado) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nodo == NULL) 
        return NULL; 

    nodo->dado = dado;
    nodo->proximo = NULL;
    return nodo;
}

void destroi_nodo(Nodo *nodo) {
    if (nodo == NULL) 
        return;
    free(nodo);
}

void* get_data(Nodo *nodo) {
    if (nodo == NULL) 
        return NULL;
    return nodo->dado;
}

Nodo* get_next(Nodo *nodo) {
    if (nodo == NULL) 
        return NULL;
    return nodo->proximo;
}