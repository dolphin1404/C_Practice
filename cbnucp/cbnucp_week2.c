#include <stdio.h>
#include <string.h>

int main(void) {
  // 1번 문제 - 시험 성적 - https://www.acmicpc.net/problem/9498
  // 2번 문제 - 별 찍기 2 - https://www.acmicpc.net/problem/2439
  // 3번 문제 - 문자열 반복 - https://www.acmicpc.net/problem/2675
  // 4번 문제 - 단어 공부 - https://www.acmicpc.net/problem/1157
  // 5번 문제 - 열 개씩 끊어 출력하기 - https://www.acmicpc.net/problem/11721

  int problem_number;
  scanf("%d", &problem_number);

  if (problem_number == 1) {
    // 1번 문제
    int score;
    scanf("%d", &score);
    if (score >= 100 && score >= 90) {
      printf("A");
    } else if (score <= 89 && score >= 80) {
      printf("B");
    } else if (score <= 79 && score >= 70) {
      printf("C");
    } else if (score <= 69 && score >= 60) {
      printf("D");
    } else {
      printf("F");
    }
    return 0;

  } else if (problem_number == 2) {
    // 2번 문제

    int num, j, i;
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
      for (j = 1; j <= (num - i); j++) printf(" ");
      for (j = 1; j <= i; j++) printf("*");
      printf("\n");
    }
  } else if (problem_number == 3) {
    // 3번 문제
    int T, R;
    char S[20];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
      scanf("%d %s", &R, S);
      for (int j = 0; j < strlen(S); j++)
        for (int k = 0; k < R; k++) printf("%c", S[j]);

      printf("\n");
    }
  } else if (problem_number == 4) {
    // 4번 문제
    int i, j, max, result = 0, len;
    char arr[1000000];
    int cnt[26] = {
        0,
    };
    int select = 0;
    // 'a' = 97 , 'b' = 98, 'A' = 65 'Z' = 90 '[' = 91 ''' = 96
    scanf("%s", arr);
    len = strlen(arr);

    // printf("%d, %d, %d", 'a', 'Z', 'A');
    for (i = 'a'; i <= 'z'; i++) {
      for (j = 0; j < len; j++) {
        if (i == arr[j]) cnt[i - 'a']++;
      }
    }
    for (i = 'A'; i <= 'Z'; i++) {
      for (j = 0; j < len; j++) {
        if (i == arr[j]) cnt[i - 'A']++;
      }
    }
    max = cnt[0];
    for (i = 1; i < 26; i++) {
      if (max < cnt[i]) {
        max = cnt[i];
        select = i;
      }
    }
    for (i = 0; i < 26; i++) {
      if (max == cnt[i]) result++;
    }
    if (result > 1)
      printf("?\n");
    else
      printf("%c", select + 'A');
    return 0;
  } else if (problem_number == 5) {
    // 5번 문제
    char input[100];
    scanf("%s", &input);

    int len = strlen(input);
    int now = 0;
    for (int i = 0; i <= len; i++) {
      printf("%c", input[i]);
      now++;
      if (now == 10) {
        now = 0;
        printf("\n");
      }
    }
  }
}