/*
  Dadas duas sequências com n números inteiros entre 0 e 9, interpretadas como dois
  números inteiros de n algarismos, calcular a sequência de números que representa a
  soma dos dois inteiros.

  Exemplo: n = 8,

  1a sequência      8 2 4 3 4 2 5 1
  2a sequência    + 3 3 7 5 2 3 3 7
                  ------------------
                  1 1 6 1 8 6 5 8 8
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_RANGE 100

int main() {
  int n,
    i,
    holder,
    n1[MAX_RANGE],
    n2[MAX_RANGE],
    sum[MAX_RANGE],
    aux;

  printf("Digite o valor de n menor ou igual a 99: ");
  scanf("%d", &n);

  printf("Digite a sequencia 1 de %d algarismos entre 0 e 9: \n", n);
  for (i = 1; i<= n; i++) {
    scanf("%d", &n1[i]);
  }

  printf("Digite a sequencia 2 de %d algarismos entre 0 e 9: \n", n);
  for (i = 1; i<= n; i++) {
    scanf("%d", &n2[i]);
  }

  holder = 0;

  for (i = n; i > 0; i--) {
    aux = n1[i] + n2[i] + holder;
    sum[i] = aux % 10;
    holder = aux / 10;
  }

  sum[0] = holder;

  system("cls");
  printf("   ");

  for (i = n; i > 0; i--) {
    printf("%d", n1[i]);
  }

  printf("\n");
  printf(" + ");

  for (i = n; i > 0; i--) {
    printf("%d", n2[i]);
  }

  printf("\n");
  printf("---");

  for (i = 0; i < (n + 2); i++) {
    printf("-");
  }

  printf("\n");
  printf("  ");

  for (i = 0; i<= n; i++) {
    printf("%d", sum[i]);
  }

  return 0;
}
