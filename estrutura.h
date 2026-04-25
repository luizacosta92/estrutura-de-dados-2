#ifndef ESTRUTURA_H
#define ESTRUTURA_H
 
#include "lista.h"
#include "cliente.h"    

#define TAM_HASH_NOME 101
#define TAM_HASH_BAIRRO 101

#define TAM_HASH_PESSOAS 5
#define TAM_HASH_CRIANCAS 2
#define TAM_HASH_RENDA 4

typedef struct Estrutura {
    Lista *por_nome[TAM_HASH_NOME];
    Lista *por_bairro[TAM_HASH_BAIRRO];
    Lista *por_pessoas[TAM_HASH_PESSOAS];
    Lista *por_criancas[TAM_HASH_CRIANCAS];
    Lista *por_renda[TAM_HASH_RENDA];
} Estrutura;

Estrutura* criar_estrutura();
void inserir_cliente(Estrutura *estrutura, Cliente *cliente);
void destruir_estrutura(Estrutura *estrutura);

Lista* recuperar_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca);

#endif