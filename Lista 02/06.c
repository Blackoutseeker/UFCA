/*
  Dado n, calcular o n-ésimo termo da série de Fibonacci.
*/

#include <stdio.h>

long long int calcFibonacci(long long int n);

int main() {
  long long int n;

  printf("Digite um numero natural n maior que zero: ");
  scanf("%lld", &n);

  long long int fibonacci = calcFibonacci(n);

  printf("O n-esimo termo eh: %lld", fibonacci);

  return 0;
}

long long int calcFibonacci(long long int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;

  long long int fibonacci = calcFibonacci(n - 1) + calcFibonacci(n - 2);

  return fibonacci;
}
