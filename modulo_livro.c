#include "modulo_livro.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVROS 5000

struct livro biblioteca[MAX_LIVROS];
int numLivros = 0;

void emprestimo_livro(void) {
  char cpf[100];
  printf("CPF do cliente ao qual irá retirar o livro: ");
  scanf("%s", cpf);

  // Coloque aqui a lógica para empréstimo do livro
}

int buscar_livro_por_titulo(char *termo) {
  int encontrado = 0;
  for (int i = 0; i < numLivros; i++) {
    if (strcasecmp(biblioteca[i].titulo, termo) == 0) {
      printf("Livro encontrado:\n");
      printf("Título: %s\n", biblioteca[i].titulo);
      printf("Autor: %s\n", biblioteca[i].autor);
      printf("Quantidade de cópias: %d\n", biblioteca[i].quant);
      printf("Número do local: %d\n", biblioteca[i].local);
      encontrado = 1;
      return 1;
    }
  }

  if (!encontrado) {
    return 0;
  }

  return encontrado;
}

void editor_livro(char *titulo) {
  int mudar;
  int novo_local;
  printf("\n=====================================\n");
  printf("=== Editor de Livros ===\n");
  printf("=====================================\n\n");
  printf("1 - Mudar Local do livro\n");
  printf("2 - Mudar quantidade de unidades\n");
  printf("0 - Retornar para o menu principal\n");
  printf("=====================================\n");
  printf("Escolha uma opção: ");
  scanf("%d", &mudar);

  switch (mudar) {
  case 1:
    printf("Novo local do livro: ");
    scanf("%d", &novo_local);
    for (int i = 0; i < numLivros; i++) {
      if (strcasecmp(biblioteca[i].titulo, titulo) == 0) {
        biblioteca[i].local = novo_local;
      }
    }
    break;
  case 2:
    printf("Nova quantidade de unidades: ");
    scanf("%d", &novo_local);
    for (int i = 0; i < numLivros; i++) {
      if (strcasecmp(biblioteca[i].titulo, titulo) == 0) {
        biblioteca[i].quant = novo_local;
      }
    }
    break;
  case 0:
    printf("Retornando para o menu principal.\n");
    break;
  default:
    printf("Opção inválida. Tente novamente.\n");
  }
}

int menu_livro() {
  int escolha = 1;
  char titulo[100];

  while (escolha != 0) {
    printf("\n=====================================\n");
    printf("=== Registro de Livros ===\n");
    printf("=====================================\n\n");
    printf("1 - Registrar Livros Novos\n");
    printf("2 - Editar Registro de Livro\n");
    printf("3 - Alugar Livro\n");
    printf("0 - Retornar para o menu principal\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
      registrar_livro();
      break;
    case 2:
      printf("Nome do livro: ");
      scanf("%s", titulo);
      if (buscar_livro_por_titulo(titulo)) {
        editor_livro(titulo);
      }
      break;
    case 3:
      emprestimo_livro();
      break;
    case 0:
      printf("Retornando para o menu principal.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }
  return 0;
}

void registrar_livro() {
  if (numLivros < MAX_LIVROS) {
    printf("\n === Registrar Livro ===\n");

    printf("Nome do livro: ");
    scanf("%s", biblioteca[numLivros].titulo);

    printf("Autor do livro: ");
    scanf("%s", biblioteca[numLivros].autor);

    printf("Quantidade de cópias do livro: ");
    scanf("%d", &biblioteca[numLivros].quant);

    printf("Número do local (número de quatro dígitos): ");
    scanf("%d", &biblioteca[numLivros].local);

    numLivros++;
  } else {
    printf("A biblioteca está cheia. Não é possível adicionar mais livros.\n");
  }
}

bool validar_isbn(const char *isbn) {
  if (isbn == NULL) {
    return false;
  }
  if (strlen(isbn) != 13) {
    return false; 
  }
  for (int i = 0; isbn[i] != '\0'; i++) {
    if (!isdigit(isbn[i]) && !(i == 12 && isbn[i] == 'X')) {
      return false; // ISBN inválido se contiver caracteres não permitidos
    }
  }

  // Calcula o dígito de verificação
  int soma = 0;
  for (int i = 0; i < 12; i++) {
    int digito = isbn[i] - '0';
    soma += (i % 2 == 0) ? digito : digito * 3;
  }
  int digitoVerificador = (10 - (soma % 10)) % 10;

  // Verifica o dígito de verificação
  if (isbn[12] != (digitoVerificador + '0')) {
    return false; // ISBN inválido se o dígito de verificação estiver errado
  }

  return true; // ISBN válido
}
