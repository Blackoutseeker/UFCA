/*
  Dado um inteiro não-negativo n, determinar n!
*/

#include <stdio.h>

int main() {
  int n, result;

  printf("Digite um numero n natural: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Numero natural invalido.");
    return 0;
  }

  result = n;

  for (int index = (n - 1); index > 0; index--) {
    result *= index;
  }

  printf("n! = %d", result);

  return 0;
}
