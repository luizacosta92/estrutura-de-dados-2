#ifndef CLIENT_H
#define CLIENT_H

#define TAM_NOME 40
#define TAM_BAIRRO 40

typedef struct Cliente {
    char nome[TAM_NOME];
    char bairro[TAM_BAIRRO];
    int num_pessoas;
    int tem_criancas;
    double renda;
} Cliente;

Cliente* cria_cliente(char *nome, char *bairro, int num_pessoas, int tem_criancas, double renda);

void destroi_cliente(Cliente *cliente);

char* get_nome(Cliente *cliente);
char* get_bairro(Cliente *cliente);
int get_pessoas(Cliente *cliente);
int get_criancas(Cliente *cliente);
double get_renda(Cliente *cliente);

int faixa_pessoas(int num_pessoas);
int faixa_renda(double renda);

#endif