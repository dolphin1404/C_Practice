#include <stdio.h>

#define MAX 100

int findGCD(int a, int b) {
  int ad[MAX];
  int bd[MAX];
  int idx1 = 0, idx2 = 0;
  for (int i = 1; i <= a; i++) {
    if (a % i == 0) {
      ad[idx1++] = i;
    }
  }
  for (int i = 1; i <= b; i++){
    if(b%i==0){
      bd[idx2++] = i;
    }
  }

  int i = idx1 - 1;
  int j = idx2 - 1;
  int flag = 0;

  while(flag == 0 && i >= 0 && j >= 0){
    if(ad[i] > bd[j]){
      i--;
    } else if(ad[i] < bd[j]){
      j--;
    } else{
      flag = 1;
    }
  }
  return ad[i];
}

int main(){
  int a, b;
  printf("두 수를 입력하세요: ");
  scanf("%d %d", &a, &b);
  int commonFactor = findGCD(a, b);  // 함수에 넣어줄 변수 선언
  printf("최대공약수(GCD): %d\n", commonFactor);
}