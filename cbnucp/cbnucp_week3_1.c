#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int idx1 = 1;
  int idx2 = 1;
  int ad[100];
  int bd[100];
  int mod_count = 0;  // a에 대한 mod 연산 횟수

  for (int i = 1; i <= a; i++) {
    if (a % i == 0) {
      ad[idx1] = i;
      idx1++;
      mod_count++;
    }
  }
  for (int i = 1; i <= b; i++) {
    if (b % i == 0) {
      bd[idx2] = i;
      idx2++;
      mod_count++;
    }
  }
  int flag = 0;
  int i = idx1--;
  int j = idx2--;
  int compare_count = 0;  // 비교 연산 횟수
  while (flag == 0 && i >= 1 && j >= 1) {
    compare_count++;
    if (ad[i] > bd[j]) {
      i--;
    } else if (ad[i] < bd[j]) {
      j--;
    } else {
      flag = 1;
    }
  }
  printf("a에 대한 mod 연산 횟수: %d\n", mod_count);
  printf("비교 연산 횟수: %d\n", compare_count);
  printf("%d", ad[i]);
  return 0;
}
