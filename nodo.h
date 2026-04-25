#ifndef NODO_H
#define NODO_H

typedef struct Nodo {
    void *dado;
    struct Nodo *proximo;
} Nodo;

Nodo* criar_nodo(void *dado);
void destroi_nodo(Nodo *nodo);

#endif 