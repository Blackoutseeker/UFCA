/*
  Ler dois números inteiros do usuário ("digite um inteiro: ", "digite outro inteiro").
  Em seguida, o programa deve ler um terceiro inteiro ("digite uma operação: ").
  Se esse último inteiro for 1, então o programa deve imprimir a soma dos dois primeiros inteiros lidos.
  Se o último inteiro for 2, então a subtração deve ser impressa.
  Idem para 3, 4, 5: multiplicação, quociente, resto da divisão.
  Caso o terceiro inteiro não seja um número de 1 a 5, o programa deve imprimir algo como "operação inválida".
  O programa também deve imprimir uma mensagem de erro em caso de divisão por zero.
*/

#include <stdio.h>

int main() {
  int number1, number2, operation;
  float result = 0;

  printf("Digite um numero inteiro: ");
  scanf("%d", &number1);
  printf("Digite outro numero inteiro: ");
  scanf("%d", &number2);

  printf("\n1 - Soma");
  printf("\n2 - Subtracao");
  printf("\n3 - Multiplicacao");
  printf("\n4 - Divisao");
  printf("\n5 - Resto da divisao");
  printf("\n\nEscolha uma operacao: ");
  scanf("%d", &operation);

  switch (operation) {
    case 1:
      result = number1 + number2;
      break;
    case 2:
      result = number1 - number2;
      break;
    case 3:
      result = number1 * number2;
      break;
    case 4:
      if (number2 != 0) {
        result = number1 / number2;
      }
      break;
    case 5:
      if (number2 != 0) {
        result = number1 % number2;
      }
      break;
    default:
      printf("Operacao invalida");
      break;
  }

  if ((operation == 4 || operation == 5) && number2 == 0) {
    printf("Impossivel dividir por 0");
  }
  else if (operation >= 1 && operation <= 5) {
    printf("O resultado eh: %.2f", result);
  }

  return 0;
}
