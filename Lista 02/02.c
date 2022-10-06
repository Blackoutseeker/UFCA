/*
  Dados o número n de alunos de uma turma de Fundamentos de Programação
  e suas notas da primeira prova, determinar a maior e a menor nota
  obtidas por essa turma (Nota máxima = 100 e nota mínima = 0).
*/

#include <stdio.h>

int main() {
  float holder, max = 0, min = 0;
  int students;

  printf("Digite a quantidade de alunos: ");
  scanf("%d", &students);

  if (students <= 0) {
    printf("Sem alunos, sem notas...");
    return 0;
  }

  for (int index = 0; index < students; index++) {
    printf("Digite a nota do aluno %d: ", (index + 1));
    scanf("%f", &holder);

    while (holder < 0 || holder > 100) {
      printf("Digite uma nota entre 0 e 100: ");
      scanf("%f", &holder);
    }

    if (index == 0) max = min = holder;
    if (holder > max) max = holder;
    if (holder < min) min = holder;
  }

  printf("\nMaior nota: %.2f\nMenor nota: %.2f", max, min);

  return 0;
}
