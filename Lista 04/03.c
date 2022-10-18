/*
  Imprimir a sequência de Fibonacci, utilizando vetores.
*/

#include <stdio.h>

#define RANGE 2

long long int calcFibonacci(long long int n[RANGE]);

int main() {
  long long int n[RANGE],
    fibonacci;

  n[0] = 0;
  n[1] = 1;

  while (1) {
    fibonacci = calcFibonacci(n);

    if (fibonacci < 0) break;

    printf("\n%lld", fibonacci);
  }

  return 0;
}

long long int calcFibonacci(long long int n[RANGE]) {
  n[2] = n[0] + n[1];
  n[1] = n[2];
  n[0] = n[1];

  return n[2];
}
