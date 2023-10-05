#include <stdio.h>

int findCommonFactor(int a, int b, int *modCount, int *compareCount) {
  int ad[100];  // 배열의 크기는 충분히 크게 설정
  int bd[100];
  int idx1 = 0; // 0으로 초기화
  int idx2 = 0;

  // 1. a의 약수를 구해서 ad 배열에 저장
  for (int i = 1; i <= a; i++) {
    (*modCount)++;  // mod 연산 횟수 증가
    if (a % i == 0) {
      ad[idx1++] = i;
    }
  }
  // 2. b의 약수를 구해서 bd 배열에 저장
  for (int i = 1; i <= b; i++) {
    (*modCount)++;  // mod 연산 횟수 증가
    if (b % i == 0) {
      bd[idx2++] = i;
    }
  }

  // 3. 공통 약수를 찾는 과정
  int i = idx1 - 1;
  int j = idx2 - 1;
  int flag = 0;            // 0으로 초기화
  int compareCounter = 0;  // 비교 연산 횟수를 따로 계산

  while (flag == 0 && i >= 0 && j >= 0) {
    compareCounter++;  // 비교 연산 횟수 증가
    if (ad[i] > bd[j]) {
      i--;
    } else if (ad[i] < bd[j]) {
      j--;
    } else {
      flag = 1;  // 공통 약수를 찾았으니 flag를 1로 설정
    }
  }
  *compareCount = compareCounter;  // 비교 연산 횟수를 저장

  return ad[i];
}

int main() {
  int a, b;
  printf("두 수를 입력하세요: ");
  scanf("%d %d", &a, &b);
  int modCount = 0;
  int compareCount = 0;
  int commonFactor = findCommonFactor(a, b, &modCount, &compareCount);  // 함수에 넣어줄 변수 선언
  printf("최대공약수(GCD): %d\n", commonFactor);
  printf("mod 연산 횟수: %d\n", modCount);
  printf("비교 연산 횟수: %d\n", compareCount);

  return 0;
}