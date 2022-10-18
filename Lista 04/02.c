/*
  Ler dados de um vetor de tamanho 10 com valores entre 0 e 100
  imprimir o maior, o menor, o percentual de números pares e a média
  dos elementos do vetor.
*/

#include <stdio.h>

#define RANGE 10

int main() {
  int holder[RANGE],
    maxNumber = 0,
    minNumber = 0,
    pairNumbers = 0;
  float average = 0,
    pairPercentage;

  for (int index = 0; index < RANGE; index++) {
    printf("Digite um numero inteiro entre 0 e 100: ");
    scanf("%d", &holder[index]);

    while (holder[index] < 0 || holder[index] > 100) {
      printf("Digite um numero inteiro valido entre 0 e 100: ");
      scanf("%d", &holder[index]);
    }

    average += holder[index];

    if (holder[index] % 2 == 0) {
      pairNumbers++;
    }

    if (index == 0) {
      maxNumber = holder[index];
      minNumber = holder[index];
    }

    else {
      if (maxNumber < holder[index]) {
        maxNumber = holder[index];
      }

      if (minNumber > holder[index]) {
        minNumber = holder[index];
      }
    }
  }

  average /= RANGE;
  pairPercentage = (pairNumbers * 100) / RANGE;

  printf("\nO maior numero eh: %d", maxNumber);
  printf("\nO menor numero eh: %d", minNumber);
  printf("\nO percentual de numero pares eh: %.2f%%", pairPercentage);
  printf("\nA media dos elementos eh: %.2f", average);

  return 0;
}
