/*
  Ler uma data (no formato dd, mm e aaaa, onde cada entrada é um inteiro) e
  imprimir se a data é válida ou não. Sabe-se que um ano é bissexto
  se ele é divisível por 4 e não divisível por 100 ou ele é divisível por 400.
*/

#include <stdio.h>

int checkIfDateIsValid(int day, int month);
int checkIfIsLeapYear(int year);
int checkIfLeapYearIsValid(int day, int month, int year);

int main() {
  int day, month, year;

  printf("Digite os dias (formato dd): ");
  scanf("%d", &day);
  printf("Digite o mes (formato mm): ");
  scanf("%d", &month);
  printf("Digite o ano (formato aaaa): ");
  scanf("%d", &year);

  const int isValidDate = checkIfLeapYearIsValid(day, month, year);

  if (isValidDate) {
    printf("Eh uma data valida");
  }
  else {
    printf("Nao eh uma data valida");
  }

  return 0;
}

int checkIfDateIsValid(int day, int month) {
  if (day > 31 || month > 12) {
    return 0;
  }

  return 1;
}

int checkIfIsLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return 1;
  }

  return 0;
}

int checkIfLeapYearIsValid(int day, int month, int year) {
  int isValidDate = checkIfDateIsValid(day, month);
  int isLeapYear = checkIfIsLeapYear(year);

  if ((day > 28 && month == 2 && isLeapYear) || isValidDate) {
    return 1;
  }

  return 0;
}
