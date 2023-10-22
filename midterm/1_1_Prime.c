#include <stdbool.h>
#include <stdio.h>

#define MAX 1000

/* bool is_decimal[MAX];
// 홀수
int main() {
  int M, N;
  scanf("%d %d", &M, &N);
  printf("2 ");  // 2 먼저 출력
  for (int i = 3; i <= N; i += 2) {
    is_decimal[i] = 1;  // 소수다
    for (int j = 3; j * j <= i; j += 2) {
      if (i % j == 0) {
        is_decimal[i] = 0;
        //is_decimal[j * j] = 0;
        break;
      }
    }
  }
  for (int i = M; i <= N; i++) {
    if (is_decimal[i]== 1) {
      printf("%d ", i);
    }
  }
}
 */

bool arr[MAX];
void finePrimeNum(int m, int n) {
  arr[0] = 0;  // 소수아닌거 = 0 (false)
  arr[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      if (arr[j] == 1) {
        arr[j] = 0;
      }
    }
  }
  for (int i = m; i <= n; i++) {
    if (arr[i] == 1) printf("%d ", i);
  }
}

// 소수구하기 에라토스테네스의 체
int main() {
  int m = 1, n = 100;
  arr[0] = 1;  // 소수아닌거 = 0 (false)
  arr[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      if (arr[j] == 0) {
        arr[j] = 1;
      }
    }
  }
  for (int i = m; i <= n; i++) {
    if (arr[i] == 0) printf("%d ", i);
  }
}