/*
  Dado um inteiro positivo n, verificar se n é primo.
*/

#include <stdio.h>

int main() {
  int n, result;
  printf("Digite um numero natural: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Nao eh um numero natural");
    return 0;
  }

  if (n == 0 || n == 1) {
    printf("Nao eh um numero primo");
    return 0;
  }

  if (n > 1) {
    for (int index = 2; index <= n / 2; index++) {
      if (n % index == 0) {
        printf("Nao eh primo");
        return 0;
      }
    }
  }

  printf("Eh um numero primo");

  return 0;
}
