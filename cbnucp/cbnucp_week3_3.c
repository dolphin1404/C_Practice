#include <stdio.h>

int modcount = 0;

int findGCD(int a, int b) {
  if (b == 0)
    return (a);
  else {
    modcount++;
    return (findGCD(b, a % b));
  }
}
int main() {
  int a, b;
  printf("두 수를 입력하세요: ");
  scanf("%d %d", &a, &b);
  int gcd = findGCD(a, b);
  printf("최대공약수 (GCD): %d\n", gcd);
  printf("mod 연산 횟수: %d", modcount);
}