/*
  Criar um programa que leia dois vetores, A e B, contendo cada um 25 elementos inteiros.
  Intercalar esses dois conjuntos (A[0]/B[0]/A[1]/B[1]/...), formando um vetor
  V de 50 elementos. Imprima o vetor V.
*/

#include <stdio.h>

#define RANGE 25

int top = -1;
int V[RANGE * 2];

void push(int value);

int main() {
  int A[RANGE], B[RANGE];

  for (int index = 0; index < RANGE; index++) {
    printf("\nDigite o valor para A[%d]: ", index);
    scanf("%d", &A[index]);

    printf("Digite o valor para B[%d]: ", index);
    scanf("%d", &B[index]);

    push(A[index]);
    push(B[index]);
  }

  for (int index = 0; index < (RANGE * 2); index++) {
    printf("\nV[%d]: %d", index, V[index]);
  }

  return 0;
}

void push(int value) {
  if (top != (RANGE * 2) - 1) {
    top++;
    V[top] = value;
  }
}
