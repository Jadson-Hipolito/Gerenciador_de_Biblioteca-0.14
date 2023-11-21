#include "modulo_cliente.h"
#include "modulo_funcio.h"
#include "modulo_livro.h"
#include <stdio.h>

int main() {
  int menu = 0;
  printf("\n███████████████████████████████████████████████████████████████████"
         "█████████\n");
  printf("█████████████████████████████████████████████████████████████████████"
         "███████\n");
  printf("████████████████████████████████<Biblioteca>"
         "████████████████████████████████\n");
  printf("█████████████████████████████████████████████████████████████████████"
         "███████\n");
  printf("█████████████████████████████████████████████████████████████████████"
         "███████\n\n");
  printf("               ██████████████████████████████████████████████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("             █████ 1-Livros Resistrados                   █████\n");
  printf("            █████  2-Cliente                               █████\n");
  printf("            █████  3-Funcionarios                          █████\n");
  printf("             █████ 0-Finalizar Programa                   █████\n");
  printf("              ████████████████████████████████████████████████\n");
  printf("               ██████████████████████████████████████████████\n\n");
  scanf("%d", &menu);

  switch (menu) {
  case 1:
    menu_livro();
    break;
  case 2:
    menu_cliente();
    break;
  case 3:
    menu_funcio();
    break;
  case 0:
    printf("Programa finalizado.\n");
    return 0;
  default:
    printf("Opção inválida. Tente novamente.\n");
    break;
  }
  return 0;
}