// modulo_funcio.h - se trata de uma versão auterada de um modulo feito, com uso do ChatGpt, da openai.

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#define max_nome 50
#define max_cpf 12

typedef struct funcio{
    char nome[max_nome];
    float salario;
    int telefone;
    char endereco[max_nome];
    char cpf[max_cpf];
    int id;
    int ativ;
} funcionario;

void menu_funcio(void);
void editar_funcionario();
void cadastrar_funcionario(funcionario *funcionarios, int *num_funcionarios);
void listar_funcionarios(const funcionario *funcionarios, int *num_funcionarios);
// Outras funções relacionadas aos funcionários, se necessário

#endif // FUNCIONARIO_H
