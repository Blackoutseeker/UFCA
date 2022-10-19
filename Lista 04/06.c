/*
  Publicar o número de acertos de cada aluno em uma prova em forma de testes.
  A prova consta de 10 questões, cada uma com cinco alternativas identificadas por
  A-1, B-2, C-3, D-4 e E-5. São dados:
    - o cartão gabarito;
    - o número de alunos da turma;
    - o cartão de respostas para cada aluno, contendo o seu número e suas respostas.
*/

#include <stdio.h>

#define RANGE 10

int main() {
  int students,
    i,
    j,
    correctAnswer,
    template[RANGE],
    studentAnswer;

  printf("Digite o numero de alunos: ");
  scanf("%d", &students);

  printf("Gabarito da prova:\n");

  for (i = 0; i < RANGE; i++) {
    printf("Resposta da questao %d: ", (i + 1));
    scanf(" %d", &template[i]);
  }

  for (i = 0; i < students; i++) {
    correctAnswer = 0;
    printf("Aluno %d:\n", (i + 1));

    for (j = 0; j < RANGE; j++) {
      printf("\nDigite a resposta da questao %d:", (j + 1));
      scanf(" %d", &studentAnswer);

      if (studentAnswer == template[j]) {
        correctAnswer++;
      }

      printf("Aluno %d acertou %d questoes\n", (i + 1), correctAnswer);
    }
  }

  return 0;
}
