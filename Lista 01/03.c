/*
  Converter uma determinada quantia, dada em reais, para uma das seguintes moedas:
  - Euro
  - Dólar americano
  - Libra esterlina
  - Peso argentino
*/

#include <stdio.h>

#define EURO 5.22
#define AMERICAN_DOLAR 5.38
#define POUND_STERLING 5.82
#define ARGENTINIAN_PESO 0.037

int main() {
  float value;
  int currency;

  printf("Digite o valor a ser convertido: ");
  scanf("%f", &value);
  printf("\n\n1 - Euro");
  printf("\n2 - Dolar americano");
  printf("\n3 - Libra esterlina");
  printf("\n4 - Peso argentino");
  printf("\n\nEscolha uma das moedas acima: ");
  scanf("%d", &currency);

  switch (currency) {
    case 1:
      value /= EURO;
      break;
    case 2:
      value /= AMERICAN_DOLAR;
      break;
    case 3:
      value /= POUND_STERLING;
      break;
    case 4:
      value /= ARGENTINIAN_PESO;
      break;
    default:
      printf("Moeda invalida");
      break;
  }

  if (value > 0) {
    printf("O valor convertido eh: %.2f", value);
  }

  return 0;
}
