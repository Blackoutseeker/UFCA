/*
  Num campeonato de vôlei de praia, se inscreveram 15 equipes. Sabendo que na ficha de
  inscrição de cada time consta, além de outros dados, o peso e a idade de 2 jogadores,
  criar um programa que apresente: peso médio e idade média de cada equipe e peso
  médio e idade média de todos os participantes.
*/

#include <stdio.h>

#define NUMBER_OF_EQUIPS 15
#define NUMBER_OF_PLAYERS 2

int main() {
  float weights[NUMBER_OF_EQUIPS][NUMBER_OF_PLAYERS],
    ages[NUMBER_OF_EQUIPS][NUMBER_OF_PLAYERS],
    weightAverage = 0,
    ageAverage = 0;
  int equip,
    player;

  for (equip = 0; equip < NUMBER_OF_EQUIPS; equip++) {
    for (player = 0; player < NUMBER_OF_PLAYERS; player++) {
      printf("Digite o peso do jogador %d da equipe %d: ", (player + 1), (equip + 1));
      scanf("%f", &weights[equip][player]);

      printf("Digite a idade do jogador %d da equipe %d: ", (player + 1), (equip + 1));
      scanf("%f", &ages[equip][player]);
    }
  }

  for (equip = 0; equip < NUMBER_OF_EQUIPS; equip++) {
    weightAverage = (weights[equip][0] + weights[equip][1]) / NUMBER_OF_PLAYERS;
    ageAverage = (ages[equip][0] + ages[equip][1]) / NUMBER_OF_PLAYERS;
    printf("\nO peso medio da equipe %d eh: %.2f", (equip + 1), weightAverage);
    printf("\nA idade media da equipe %d eh: %.2f", (equip + 1), ageAverage);
  }

  weightAverage = 0;
  ageAverage = 0;

  for (equip = 0; equip < NUMBER_OF_EQUIPS; equip++) {
    weightAverage += (weights[equip][0] + weights[equip][1]) / NUMBER_OF_PLAYERS;
    ageAverage += (ages[equip][0] + ages[equip][1]) / NUMBER_OF_PLAYERS;
  }

  printf("\n\nO peso medio das equipes eh: %.2f", weightAverage / NUMBER_OF_EQUIPS);
  printf("\nA idade media das equipes eh: %.2f", ageAverage / NUMBER_OF_EQUIPS);

  return 0;
}
