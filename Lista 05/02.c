/*
  Faça um programa que recebe uma frase e retorna a mesma frase com a seguinte
  modificação: a primeira letra de cada palavra deve ser maiúscula
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PHRASE_LENGTH 200

int main() {
  char phrase[PHRASE_LENGTH];

  printf("Digite uma frase: ");
  scanf("%[^\n]s", phrase);

  for (int index = 0; index < strlen(phrase); index++) {
    if (index == 0) phrase[0] = toupper(phrase[0]);

    if (
      phrase[index] == ' ' ||
      phrase[index] == '-' ||
      phrase[index] == '_'
    )
    phrase[index + 1] = toupper(phrase[index + 1]);
  }

  printf("Resultado: %s", phrase);

  return 0;
}
