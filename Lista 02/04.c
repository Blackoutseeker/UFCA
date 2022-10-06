/*
  Dizemos que um inteiro positivo n é perfeito se for igual à
  soma de seus divisores positivos diferentes de n.

    Exemplo: 6 é perfeito, pois 1+2+3 = 6.

  Dado um inteiro positivo n, verificar se n é perfeito.
*/

#include <stdio.h>

int main() {
  int n, totalSum = 0;

  printf("Digite um numero inteiro positivo: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Numero inteiro positivo invalido (incluindo 0).");
    return 0;
  }

  for (int index = 1; index <= (n / 2); index++) {
    if (n % index == 0) {
      totalSum += index;
    }
  }

  if (totalSum != n) {
    printf("%d nao eh perfeito.", n);
    return 0;
  }

  printf("%d eh perfeito.", n);

  return 0;
}
