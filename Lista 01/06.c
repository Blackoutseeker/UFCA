/*
  Dados um inteiro x e um inteiro não-negativo n,
  calcular x elevado a n sem utilizar funções pré-definidas.
*/

#include <stdio.h>

int main() {
  int x, n, result;

  printf("Digite um numero inteiro: ");
  scanf("%d", &x);
  printf("Digite um numero natural: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Numero natural invalido");
    return 0;
  }
  else if (n == 0) {
    result = 1;
  }
  else {
    result = x;
    for (int index = 1; index < n; index++) {
      result *= x;
    }
  }

  printf("%d elevado a %d = %d", x, n, result);

  return 0;
}