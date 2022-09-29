// Receber três números e imprimir o maior.

#include <stdio.h>

int main() {
  int number = 0, maxNumber = 0;

  for (int index = 1; index <= 3; index++) {
    printf("Digite o %d numero: ", index);
    scanf("%d", &number);
    if (number > maxNumber) {
      maxNumber = number;
    }
  }

  printf("O maior numero eh: %d", maxNumber);

  return 0;
}
