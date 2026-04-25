#include <stdlib.h>
#include "lista.h"

Lista* criar_lista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));

    if (lista == NULL) return NULL;
    
    lista->inicio = NULL;
    lista->tamanho = 0;

    return lista;

}

void insere_lista(Lista *lista, void *dado) {
    if (lista == NULL) return;

    Nodo *novo_nodo = criar_nodo(dado);
    if (novo_nodo == NULL) return;

   novo_nodo->proximo = lista->inicio;
   lista->inicio = novo_nodo;
    lista->tamanho++;
}

void destroi_lista(Lista *lista) {
    if (lista == NULL) return;

    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        Nodo *proximo = atual->proximo;
        destroi_nodo(atual);
        atual = proximo;
    }

    free(lista);
}