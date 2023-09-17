#include <stdio.h>

int main(void) {
  // 1번 문제 - 구구단 - https://www.acmicpc.net/problem/2739
  // 2번 문제 - 윤년 - https://www.acmicpc.net/problem/2753
  // 3번 문제 - 최소, 최대 - https://www.acmicpc.net/problem/10818
  // 4번 문제 - 피보나치 수 5 - https://www.acmicpc.net/problem/10870
  // 5번 문제 - 설탕 배달 - https://www.acmicpc.net/problem/2839

  int problem_number;
  scanf("%d", &problem_number);

  if (problem_number == 1) {
    // 1번 문제
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= 9; i++) {
      printf("%d * %d = %d\n", N, i, N * i);
    }
  } else if (problem_number == 2) {
    // 2번 문제
    int year;
    scanf("%d", &year);
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
      printf("1");
    } else {
      printf("0"); 
    }
  } else if (problem_number == 3) {
    // 3번 문제
    int n, number;
    int min = 1000001, max = -1000001;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &number);
      if (number > max) // max보다 크면 저장됨
        max = number;
      if (number < min) // min보다 작으면 저장됨
        min = number;
    }
    printf("%d %d", min, max);
    return 0;
  } else if (problem_number == 4) {
    // 4번 문제
    int f1 = 0;
    int f2 = 1;
    int f3 = 0;
    int n;
    int i;
    scanf("%d", &n);
    if (n == 0) {
      printf("%d", f1);
    } else if (n == 1) {
      printf("%d", f2);
    } else {
      for (i = 0; i < n; i++) {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
      }
      printf("%d", f3);
    }
  } else if (problem_number == 5) {
    // 5번 문제
    int N, cnt = 0;
    scanf("%d", &N);
    while (1) {
      if (N % 5 == 0) {
        cnt += N / 5;
        break;
      }
      N -= 3;
      cnt++;
      if (N <= 0)
        break;
    }
    if (N < 0)
      printf("-1\n");
    else
      printf("%d\n", cnt);
  }
  return 0;
}