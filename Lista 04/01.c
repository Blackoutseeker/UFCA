/*
  Entrar com números inteiros em um vetor A[10]. Gerar e imprimir o vetor B
  onde cada elemento é o quadrado do elemento, na respectiva posição, do vetor A.
*/

#include <stdio.h>

#define RANGE 10

int main() {
  int A[RANGE], B[RANGE];

  for (int index = 0; index < RANGE; index++) {
    printf("Digite o valor para A[%d]: ", index);
    scanf("%d", &A[index]);
  }

  for (int index = 0; index < RANGE; index++) {
    B[index] = A[index] * A[index];
  }

  for (int index = 0; index < RANGE; index++) {
    printf("\nB[%d]: %d", index, B[index]);
  }

  return 0;
}
