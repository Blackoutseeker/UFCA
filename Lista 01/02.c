/*
  Ler três números, possíveis lados de um triângulo, e imprimir a classificação
  segundo os lados (se for o caso).
*/

#include <stdio.h>

int main() {
  float number1, number2, number3;

  printf("Digite o primeiro lado: ");
  scanf("%f", &number1);
  printf("Digite o segundo lado: ");
  scanf("%f", &number2);
  printf("Digite o terceiro lado: ");
  scanf("%f", &number3);

  if (number1 == number2 && number2 == number3) {
    printf("O triangulo eh equilatero");
  }
  else if (number1 != number2 && number2 != number3) {
    printf("O triangulo eh escaleno");
  }
  else {
    printf("O triangulo eh isosceles");
  }

  return 0;
}
