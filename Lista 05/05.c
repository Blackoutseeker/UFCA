/*
  Criar uma função que calcule o número de combinações de n elementos p a p. A
  fórmula da combinação é dada da seguinte forma: Cn,p = n!/p!(n-p)!
*/

#include <stdio.h>

int main() {
  int n = 0,
    p = 0,
    nFactorial = 1,
    pFactorial = 1,
    npFactorial = 1,
    Cnp;

  while (n <= 0 || p <= 0) {
    printf("Digite n e p elementos, respectivamente: ");
    scanf("%d %d", &n, &p);
  }

  for (int index = 1; index <= n; index++) {
    nFactorial *= index;
  }

  for (int index = 1; index <= p; index++) {
    pFactorial *= index;
  }

  for (int index = 1; index <= (n - p); index++) {
    npFactorial *= index;
    if ((n - p) == 0) npFactorial = 1;
  }

  Cnp = nFactorial / (pFactorial * npFactorial);

  printf("C%d%d = %d", n, p, Cnp);

  return 0;
}
