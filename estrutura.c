
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"    


static unsigned int hash_string(const char *str, unsigned int tamanho) {
    unsigned int hash = 5381;
    int caractere;

    while ((caractere = *str++))
        hash = ((hash << 5) + hash) + caractere; /* hash * 33 + c */

    return hash % tamanho;
}

Estrutura* criar_estrutura(){
    Estrutura *estrutura = (Estrutura*) malloc(sizeof(Estrutura));
    if (estrutura == NULL) return NULL;

    int indice;
    for (indice = 0; indice < TAM_HASH_NOME; indice++) {
        estrutura->por_nome[indice] = criar_lista();
    }
    for (indice = 0; indice < TAM_HASH_BAIRRO; indice++) {
        estrutura->por_bairro[indice] = criar_lista();
    }
    for (indice = 0; indice < TAM_HASH_PESSOAS; indice++) {
        estrutura->por_pessoas[indice] = criar_lista();
    }
    for (indice = 0; indice < TAM_HASH_CRIANCAS; indice++) {
        estrutura->por_criancas[indice] = criar_lista();
    }
    for (indice = 0; indice < TAM_HASH_RENDA; indice++) {
        estrutura->por_renda[indice] = criar_lista();
    }
    return estrutura;
}

void inserir_cliente(Estrutura *estrutura, Cliente *cliente){
    if (estrutura == NULL || cliente == NULL) return;   

    unsigned int indice_nome = hash_string(cliente->nome, TAM_HASH_NOME);
    unsigned int indice_bairro = hash_string(cliente->bairro, TAM_HASH_BAIRRO);
    int indice_pessoas = faixa_pessoas(cliente->num_pessoas);
    int indice_criancas = cliente->tem_criancas;
    int indice_renda = faixa_renda(cliente->renda);

    inserir_lista(estrutura->por_nome[indice_nome], cliente);
    inserir_lista(estrutura->por_bairro[indice_bairro], cliente);
    inserir_lista(estrutura->por_pessoas[indice_pessoas], cliente);
    inserir_lista(estrutura->por_criancas[indice_criancas], cliente);
    inserir_lista(estrutura->por_renda[indice_renda], cliente);

}

Lista* recuperar_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca) {
    if (estrutura == NULL) return NULL;

    unsigned int indice;

    switch (criterio)
    {
    case 1:
        indice = hash_string(busca, TAM_HASH_NOME);
        return estrutura->por_nome[indice];
    case 2:
        indice = hash_string(busca, TAM_HASH_BAIRRO);
        return estrutura->por_bairro[indice];
    case 3:
        return estrutura->por_pessoas[complemento -1];
    case 4:
        return estrutura->por_criancas[complemento];
    case 5:
        return estrutura->por_renda[complemento - 1];

    default:
        return NULL;
    }
}

void destruir_estrutura(Estrutura *estrutura){
    if (estrutura == NULL) return;

    int indice;
    for (indice = 0; indice < TAM_HASH_NOME; indice++) {
        destruir_lista(estrutura->por_nome[indice]);
    }
    for (indice = 0; indice < TAM_HASH_BAIRRO; indice++) {
        destruir_lista(estrutura->por_bairro[indice]);
    }
    for (indice = 0; indice < TAM_HASH_PESSOAS; indice++) {
        destruir_lista(estrutura->por_pessoas[indice]);
    }
    for (indice = 0; indice < TAM_HASH_CRIANCAS; indice++) {
        destruir_lista(estrutura->por_criancas[indice]);
    }
    for (indice = 0; indice < TAM_HASH_RENDA; indice++) {
        destruir_lista(estrutura->por_renda[indice]);
    }
    free(estrutura);
}