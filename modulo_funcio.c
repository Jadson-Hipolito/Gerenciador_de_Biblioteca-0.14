#include "modulo_funcio.h"
#include <stdio.h>
#include <string.h>

#define tamanho_max 100

funcionario funcionarios[tamanho_max];
int num_funcionarios = 0;

void menu_funcio(void) {
  int mudar;
  printf("\n=====================================\n");
  printf("=== Menu Funcionários ===\n");
  printf("=====================================\n\n");
  printf("1 - Cadastrar\n");
  printf("2 - Listar Funcionários\n");
  printf("3 - Editar Registro de Funcionário\n");
  printf("0 - Retornar para o menu principal\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &mudar);

  switch (mudar) {
  case 1:
    cadastrar_funcionario(funcionarios, &num_funcionarios);
    break;
  case 2:
    listar_funcionarios(funcionarios, &num_funcionarios);
    break;
  case 3:
    editar_funcionario(funcionarios, &num_funcionarios);
    break;
  case 0:
    printf("Programa finalizado.\n");
    break;
  default:
    printf("Opção inválida. Tente novamente.\n");
  }
}

void cadastrar_funcionario(funcionario *funcionarios, int *num_funcionarios) {
  if (*num_funcionarios < tamanho_max) {
    FILE *arquivo = fopen("funcionarios.txt", "a");

    if (arquivo != NULL) {
      printf("Digite o nome do funcionario: ");
      scanf("%s", funcionarios[*num_funcionarios].nome);

      printf("Digite o salario do funcionario: ");
      scanf("%f", &funcionarios[*num_funcionarios].salario);

      printf("Digite o endereço do cliente: ");
      scanf("%s", funcionarios[*num_funcionarios].endereco);

      printf("Digite o telefone do cliente: ");
      scanf("%d", &funcionarios[*num_funcionarios].telefone);

      printf("Digite o cpf do funcionario: ");
      scanf("%s", funcionarios[*num_funcionarios].cpf);

      funcionarios[*num_funcionarios].ativ = 1;

      funcionarios[*num_funcionarios].id = *num_funcionarios;

      // Salve os detalhes do cliente no arquivo.
      fprintf(arquivo, "Nome: %s\nSalario: %f\nEndereço: %s\nTelefone: %d\ncpf: %s\nAtividade: %d\nid: %d\n\n",
        funcionarios[*num_funcionarios].nome, funcionarios[*num_funcionarios].salario,
        funcionarios[*num_funcionarios].endereco, funcionarios[*num_funcionarios].telefone,
        funcionarios[*num_funcionarios].cpf, funcionarios[*num_funcionarios].ativ,
        funcionarios[*num_funcionarios].id);

      (*num_funcionarios)++;
      fclose(arquivo);
    } else {
      printf("Erro ao abrir o arquivo.\n");
    }
  } else {
    printf("Limite máximo de funcionarios atingido.\n");
  }
}

void listar_funcionarios(const funcionario *funcionarios, int *num_funcionarios) {
  for (int i = 0; i < *num_funcionarios; i++) {
    printf("Nome: %s\nTelefone: %d\nCPF: %s\n\n",
     funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cpf);
  }}

void editar_funcionario() {
  FILE *arquivo;
  arquivo = fopen("funcionario.txt", "r+");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  char cpf[15]; 
  char confir;
  printf("Digite o CPF do funcionario ao qual deseja pesquisar: ");
  scanf("%14s", cpf);

  char linha[1013]; 
  int encontrado = 0;
  long int posicao = ftell(arquivo); 

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    if (strstr(linha, cpf) != NULL) {
      encontrado = 1;
      break;
    }
    posicao = ftell(arquivo);
  }

  if (!encontrado) {
    printf("Funcionario não encontrado.\n");
    fclose(arquivo);
    return;
  }

  printf("Informações atuais do funcionario:\n");
  printf("%s", linha);

  int continuar = 1;
  while (continuar) {
    printf("\n=====================================\n");
    printf("=== Editor de funcionario ===\n");
    printf("=====================================\n");
    printf("1 - Mudar Nome do Funcionario\n");
    printf("2 - Mudar Endereço do Funcionario\n");
    printf("3 - Mudar Telefone do Funcionario\n");
    printf("5 - Deletar Registro do Funcionario\n");
    printf("0 - Retornar para o menu principal\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    int mudar;
    scanf("%d", &mudar);

    char novoValor[1000]; // Suponha que cada campo tem no máximo 100 caracteres
    switch (mudar) {
      case 1:
        printf("Nome: ");
        scanf("%s", novoValor);
        snprintf(linha, sizeof(linha), "Nome: %s\n", novoValor);
        break;
      case 2:
        printf("Endereço: ");
        scanf("%s", novoValor);
        snprintf(linha, sizeof(linha), "Endereço: %s\n", novoValor);
        break;
      case 3:
        printf("Telefone: ");
        scanf("%s", novoValor);
        snprintf(linha, sizeof(linha), "Telefone: %s\n", novoValor);
        break;
      case 4:
        printf("Salario: ");
        scanf("%s", novoValor);
        snprintf(linha, sizeof(linha), "Salario: %s\n", novoValor);
      case 5:
        printf("Tem certeza que deseja deletar o registro deste cliente? Digite 0 "
               "para cancelar ou 1 para confirmar: ");
        scanf(" %c", &confir);
        if (confir == '1') {
          fseek(arquivo, posicao, SEEK_SET);
          fprintf(arquivo, "Atividade: 0\n");
        }
        break;
      case 0:
        printf("Retornando para o menu principal.\n");
        continuar = 0;
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
    }
  }
  }