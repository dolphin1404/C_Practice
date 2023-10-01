#include <stdio.h>

int modcount = 0;

int gcd(int a, int b) {
  if (b == 0)
    return (a);
  else {
    modcount++;
    return (gcd(b, a % b));
  }
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int answer = gcd(a, b);
  printf("%d ", answer);
  printf("%d", modcount);
}