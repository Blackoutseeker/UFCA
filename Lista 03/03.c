/*
  No dia da estreia do filme Pantera Negra, a emissora de TV realizou uma pesquisa
  logo após o encerramento do filme. Cada espectador respondeu a um questionário no qual
  constava sua idade e sua opinião em relação ao ao filme: excelente – 3;
  bom – 2; regular – 1. Criar um algoritmo que possa receber a idade e a opinião de
  20 espectadores. Calcule e imprima:

    • a média das idades das pessoas que responderam excelente;
    • a quantidade de pessoas que responderam regular;
    • a percentagem de pessoas que responderam bom entre todos os expectadores analisados.
*/

#include <stdio.h>

#define NUMBER_OF_SPECTATORS 20

enum Opinion {
  REGULAR = 1,
  GOOD = 2,
  EXCELLENT = 3,
} opinion;

int main() {
  int age,
    agesSum = 0;
  float regularAnswers = 0,
    goodAnswers = 0,
    excellentAnswers = 0;

  for (int index = 0; index < NUMBER_OF_SPECTATORS; index++) {
    printf("Digite sua idade: ");
    scanf("%d", &age);

    while (age <= 0) {
      printf("Digite uma idade valida: ");
      scanf("%d", &age);
    }

    printf("\nOpinioes:\n");
    printf("\nRegular - 1");
    printf("\nBom - 2");
    printf("\nExcelente - 3\n");
    printf("\nDigite sua opniao: ");
    scanf("%d", &opinion);

    while (opinion < 1 || opinion > 3) {
      printf("Digite uma opiniao valida: ");
      scanf("%d", &opinion);
    }

    switch (opinion) {
      case REGULAR:
        regularAnswers++;
        break;

      case GOOD:
        goodAnswers++;
        break;

      case EXCELLENT:
        agesSum += age;
        excellentAnswers++;
        break;
    }
  }

  if (excellentAnswers <= 0) {
    printf("\nMedia de idades com respostas excelentes: 0");
  }
  else {
    printf("\nMedia de idades com respostas excelentes: %.2f", (agesSum / excellentAnswers));
  }

  printf("\nRespostas regulares: %.0f", regularAnswers);
  printf("\nPorcentagem das respostas boas: %.2f%%", (goodAnswers * 100) / NUMBER_OF_SPECTATORS);

  return 0;
}
