#include <stdbool.h>
#include <stdio.h>

// 함수를 사용하여 소수 여부를 확인합니다.
bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int a, b;
  int gcd = 1;
  int mod_count = 0;
  printf("두 수를 입력하세요: ");
  scanf("%d %d", &a, &b);

  int min_num = (a < b) ? a : b;  // 두 수 중 작은 수를 찾습니다.

  // 작은 수의 약수 중 소수를 배열 pn[]에 저장합니다.
  int pn[100];  // 충분히 큰 크기의 배열로 가정합니다.
  int pn_count = 0;
  for (int i = 2; i <= min_num; i++) {
    mod_count++;
    if (min_num % i == 0 && isPrime(i)) {
      pn[pn_count++] = i;
    }
  }

  for (int i = 0; i < pn_count; i++) {
    while ((a % pn[i] == 0) && (b % pn[i] == 0)) {
      gcd *= pn[i];
      a /= pn[i];
      b /= pn[i];
      mod_count += 2;  // mod 연산 횟수를 증가시킴 (a와 b에서 각각 1번씩)
    }
  }

  printf("최대공약수 (GCD): %d\n", gcd);
  printf("mod 연산 횟수: %d\n", mod_count);

  return 0;
}
