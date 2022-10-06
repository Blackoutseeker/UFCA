/*
  Um marciano chegou em uma floresta e se escondeu atrás
  de uma das 100 árvores do local quando viu um caçador.
  O caçador só tem 5 balas em sua espingarda.
  Cada vez que ele atira e não acerta, o marciano diz:
  “hahaha estou mais à direita!” ou “hahaha estou mais à esquerda!”,
  de acordo com a sua posição. Se o caçador não conseguir acertar o marciano,
  ele será levado para Marte. Implementar esse jogo para dois jogadores,
  onde um escolhe a árvore em que o marciano irá se esconder, e o outro tenta acertar.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_TREES 100
#define MAX_BULLETS 5

void clearTerminal(void);

int main() {
  int realTree, fakeTree, remainingBullets = MAX_BULLETS;
  printf("Jogador 1: Em qual arvore o marciano vai se esconder? ");
  scanf("%d", &realTree);

  while (realTree < 1 || realTree > NUMBER_OF_TREES) {
    printf("Jogador 1: Escolha uma arvore para o marciano se esconder: ");
    scanf("%d", &realTree);
  }

  clearTerminal();

  printf("NOTA: Existem %d arvores no campo...", NUMBER_OF_TREES);

  while (remainingBullets > 0) {
    printf("\nJogador 2: Voce possui %d balas...", remainingBullets);
    printf("\nJogador 2: Em qual arvore o marciano se escondeu? ");
    scanf("%d", &fakeTree);

    clearTerminal();

    if (fakeTree < 1 || fakeTree > NUMBER_OF_TREES) {
      clearTerminal();
      printf("Jogador 2: Sua escolha foi absurda... Ela lhe custou uma viagem sem volta para Marte!");
      printf("\nREALLY BAD ENDING: A negligencia do cacador o levou para Marte.");
      return 0;
    }

    if (fakeTree == realTree) {
      printf("\nGOOD ENDING: O cacador derrotou o marciano.");
      return 0;
    }

    else if (fakeTree < realTree) {
      printf("\nO marciano debocha do cacador: Hahaha! Estou mais a direita!\n");
    }

    else {
      printf("\nO marciano debocha do cacador: Hahaha! Estou mais a esquerda!\n");
    }

    remainingBullets--;
  }

  clearTerminal();
  printf("BAD ENDING: O cacador foi levado para Marte!");

  return 0;
}

void clearTerminal() {
  system("cls");
}
