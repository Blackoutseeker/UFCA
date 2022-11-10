/*
  Faça um programa que recebe uma frase e a retorna criptografada da seguinte
  maneira: troca todas as ocorrências de A por 1, de E por 2, de I por 3, de O por 4 e de
  U por 5.
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
    switch (tolower(phrase[index])) {
      case 'a':
        phrase[index] = '1';
        break;
      case 'e':
        phrase[index] = '2';
        break;
      case 'i':
        phrase[index] = '3';
        break;
      case 'o':
        phrase[index] = '4';
        break;
      case 'u':
        phrase[index] = '5';
        break;
      default:
        break;
    }
  }

  printf("Resultado: %s", phrase);

  return 0;
}
