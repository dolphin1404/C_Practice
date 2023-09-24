#include <stdio.h>

int Fibo(int x) {
  if (x >= 2) {
    return Fibo(x - 1) + Fibo(x - 2);
  } else if (x == 1)
    return 1;
  else
    return 0;
}
int main() {
  /* 2753번 윤년 https://www.acmicpc.net/problem/2753
  int year;
  scanf("%d", &year);
  if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
      printf("1");
  }else{
    printf("0");
  }
  */
  // 10818번 최소, 최대 https://www.acmicpc.net/problem/10818
  /*
  int N, number, max = -1000000, min = 1000000;
  scanf("%d", &N);
  for(int i = 1; i <= N; i++ ){
    scanf("%d", &number);
    if(number >= max){
      max = number;
    }
    if(number <= min){
      min = number;
    }
  }
  printf("%d %d", min, max);
  */
  // 10870번 피보나치 수 5 https://www.acmicp.net/problem/10870
  /*
  int f0 = 0;
  int f1 = 1;
  int fn = 0; // 값설정할 것
  int n;
  scanf("%d", &n);
  if(n == 0){
    printf("%d", f0);
  }else if(n == 1){
    printf("%d", f1);
  }else{
    for(int i = 0; i < n; i++){ // 0번째가 존재함을 알자
      f0 = f1;  // 1
      f1 = fn;  // 0
      fn = f0 + f1;
    }
    printf("%d", fn);
  }
  */
  // 재귀함수
  int n;
  scanf("%d", &n);
  printf("%d\n", Fibo(n));
  return 0;
}
