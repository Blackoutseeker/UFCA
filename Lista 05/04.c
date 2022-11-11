/*
  Criar uma função que receba um número inteiro como parâmetro e retorne 1, se sua
  raíz quadrada for exata, e 0 em caso contrário.
*/

#include <stdio.h>
#include <math.h>

int check_square_root(int value);

int main() {
  int value = -1;

  while (value < 0) {
    printf("Digite um valor positivo: ");
    scanf("%d", &value);
  }

  const int is_square_root_exact = check_square_root(value);

  if (is_square_root_exact) {
    printf("A raiz de %d eh exata.", value);
    return 0;
  }

  printf("A raiz de %d nao eh exata.", value);

  return 0;
}

int check_square_root(int value) {
  if (value == (sqrt(value) * sqrt(value))) return 1;
  return 0;
}
