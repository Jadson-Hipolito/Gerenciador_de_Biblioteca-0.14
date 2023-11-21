// modulo_cliente.h - Se treta de uma versão  alterada de um ou mais codigos feitos pelo ChatGPT (Openai).

#ifndef CLIENTE_H
#define CLIENTE_H
#define max_nome 50
#define TAMANHO_MAX_CLIENTES 100

typedef struct {
    char nome[max_nome];
    char endereco[max_nome];
    char telefone[max_nome];
    char cpf[max_nome];
    int id;
    int  ativ;
} cliente;

void menu_cliente(void);
void cadastrar_cliente();
void listar_clientes();
void editar_cliente();
// Outras funções relacionadas aos clientes, se necessário

#endif // CLIENTE_H