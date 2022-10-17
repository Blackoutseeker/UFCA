/*
  Uma pessoa aplicou um capital de x reais a juros mensais de z
  durante 1 ano. Determinar o montante de cada mês durante este período
  considerando juros simples e juros compostos.
*/

#include <stdio.h>

int main() {
  float 
    initialCapital,
    interestRate,
    correctionRate,
    currentCapital;

  printf("Digite o valor do capital aplicado: ");
  scanf("%f", &initialCapital);

  if (initialCapital <= 0) {
    printf("Valor de capital invalido");
    return -1;
  }

  printf("Digite o valor dos juros: ");
  scanf("%f", &interestRate);

  if (interestRate <= 0) {
    printf("Valor invalido para juros");
    return -1;
  }

  correctionRate = 1 + interestRate / 100;
  currentCapital = initialCapital;

  printf("\nValor do capital inicial: R$ %.2f\n", initialCapital); 

  for (int month = 1; month <= 12; month++){
    currentCapital *= correctionRate;
    printf("Valor do capital ao final do mes %2d: R$ %.2f\n", month, currentCapital); 
  }

  return 0;
}
