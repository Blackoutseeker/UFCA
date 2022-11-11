/*
  Receber uma matriz e imprimir o vetor soma_linha (onde cada elemento é a soma
  dos elementos de uma linha da matriz).
*/

#include <stdio.h>

int main() {
  int rows,
    cols;

  do {
    printf("Digite a quantidade de linhas e colunas da matriz, respectivamente: ");
    scanf("%d %d", &rows, &cols);
  } while (rows < 2 || cols < 2);

  rows;
  cols;

  int matrix[rows][cols],
    soma_linha[rows];

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      printf("Digite o valor para o indice[%d][%d]: ", row, col);
      scanf("%d", &matrix[row][col]);
    }
  }

  for (int row = 0; row < rows; row++) {
    soma_linha[row] = 0;
    for (int col = 0; col < cols; col++) {
      soma_linha[row] += matrix[row][col];
    }
  }

  printf("\n");

  for (int row = 0; row < rows; row++) {
    printf("soma_linha[%d] = %d\n", row, soma_linha[row]);
  }

  return 0;
}
