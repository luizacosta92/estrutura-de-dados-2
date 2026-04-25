#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Cliente* criar_cliente(char *nome, char *bairro, int num_pessoas, int tem_criancas, double renda) {
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) return NULL;

    strncpy(cliente->nome, nome, TAM_NOME - 1);
    cliente->nome[TAM_NOME - 1] = '\0';

    strncpy(cliente->bairro, bairro, TAM_BAIRRO - 1);
    cliente->bairro[TAM_BAIRRO - 1] = '\0';

    cliente->num_pessoas = num_pessoas;
    cliente->tem_criancas = tem_criancas;
    cliente->renda = renda;

    return cliente;
}

void destroi_cliente(Cliente *cliente) {
    if (cliente == NULL) return;
    free(cliente);
}

int faixa_pessoas(int num_pessoas) {
    if (num_pessoas <= 1) return 0;
    if (num_pessoas <= 2) return 1;
    if (num_pessoas <= 3) return 2;
    if (num_pessoas <= 4) return 3;
    return 4;
}

int faixa_renda(double renda) {
    if (renda <= 2000) return 0;
    if (renda <= 3000) return 1;
    if (renda <= 5000) return 2;
    return 3;
}