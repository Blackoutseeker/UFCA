/*
  Escreva um programa que recebe o salário de uma
  pessoa e imprime o desconto mensal correspondente do INSS segundo a seguinte tabela:

  Valor do salário                                      desconto
  menor ou igual a R$ 900,00 -------------------------- isento
  maior que R$ 900,00 e menor ou igual a R$ 1500,00 --- 8%
  maior que R$ 1500,00 e menor ou igual a R$ 2500,00 -- 10%
  maior que R$ 2500,00 -------------------------------- 12%
*/

#include <stdio.h>

int main() {
  float salary = 0, discount = 0;
  int percentage;

  printf("Digite o salario: ");
  scanf("%f", &salary);

  if (salary <= 900) {
    percentage = 100;
  }
  else if (salary <= 1500) {
    percentage = 8;
  }
  else if (salary <= 2500) {
    percentage = 10;
  }
  else {
    percentage = 12;
  }

  if (salary > 900) {
    discount = (salary * percentage) / 100;
    salary -= discount;
  }

  printf("O desconto mensal eh de R$ %.2f, resultando um salario de R$ %.2f", discount, salary);

  return 0;
}
