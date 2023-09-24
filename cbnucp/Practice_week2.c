#include <stdio.h>
#include <string.h>

int main() {
  int problem_number;
  scanf("%d", &problem_number);
  if (problem_number == 0) {
    int N, i, j = 0;
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
      for (j = 1; j <= N - i; j++) {
        printf(" ");
      }
      for (j = 1; j <= i; j++) {
        printf("*");
      }
      printf("\n");
    }
  }
}