#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
  int algorithm_number; // 알고리즘 1~5 중 선택할 번호 저장
  int total_operations = 0; // 연산 수행 횟수를 저장하는 변수
  printf("Enter the Algorithm Number to test : ");
  scanf("%d", &algorithm_number);

  if(algorithm_number == 1){ 
    //Algorithm 1
    int N;
    printf("1_N: ");
    scanf("%d", &N);
    printf("2부터 %d까지의 소수: ", N);
    for (int i = 2; i <= N; i++) {
        int count = 0;  
        for (int j = 1; j <= i; j++) {
            total_operations++; // 연산 수행 횟수 증가
            if (i % j == 0) {
                count++;
            }
        }
        if (count == 2) {
            printf("%d ", i);
        }
    }
    printf("\nTotal operations: %d\n", total_operations); // 총 연산 횟수 출력 N: 100 >> 5049
    return 0;
  }
  else if(algorithm_number == 2){
    //Algorithm 2
    int N;
    printf("2_N: ");
    scanf("%d", &N);
    printf("2부터 %d까지의 소수: ", N);

    if (N >= 2) {   // 2는 2로 나누어지므로 별도 출력
        printf("2 ");
    }

    for (int i = 3; i <= N; i++) {
        bool is_flag = true;
        int j = 2;

        while (is_flag == true && j < i) {
            if (i % j == 0) {
                is_flag = false;
            }
            j++;
            total_operations++; // 연산 수행 횟수 증가
        }

        if (is_flag == true) {
            printf("%d ", i);
        }
    }
    printf("\nTotal operations: %d\n", total_operations); // 총 연산 횟수 출력 N: 100 >> 1133
    printf("\n");
    return 0;
  }
  
  else if(algorithm_number == 3){
    //Algorithm 3
    int N;

    printf("3_N: ");
    scanf("%d", &N);

    printf("2부터 %d까지의 소수: 2 ", N);

    if (N >= 3) {
        for (int i = 3; i <= N; i += 2) {
            bool is_flag = 1; // 소수인지 여부를 저장하는 bool

            // 안쪽 반복문: 3부터 i-1까지의 모든 홀수로 나누어 떨어지는지 확인
            for (int j = 3; j < i; j += 2) {
                total_operations++; // 비교 연산 1회
                if (i % j == 0) {
                    is_flag = 0; // 나누어 떨어지면 소수가 아님
                    break; // 안쪽 반복문 종료
                }
            }
            // is_flag 값이 1이면 소수라고 판정
            if (is_flag) {
                printf("%d ", i);
            }
        }
        printf("\nTotal operations: %d\n", total_operations); // 총 연산 횟수 출력 N: 100 >> 530
    }

    return 0;
  }
  
  else if(algorithm_number == 4){
    //Algorithm 4
    int N;
    printf("4_N: ");
    scanf("%d", &N);

    printf("2부터 %d까지의 소수: ", N);

    if (N >= 2) {
        printf("2 ");
    }

    for (int i = 3; i <= N; i += 2) { // 2를 제외한 모든 짝수를 대상에서 제외하고 홀수만 검사
        bool is_flag = true;

        for (int j = 3; j * j <= i; j += 2) { // 홀수로만 나눠보며 소수 판별
        total_operations++; // 연산 수행 횟수 증가
            if (i % j == 0) {
                is_flag = false;
                break;
            }
        }

        if (is_flag) {
            printf("%d ", i);
        }
    }
    printf("\nTotal operations: %d\n", total_operations); // 총 연산 횟수 출력 N: 100 >> 87
  }
  else if (algorithm_number == 5) {
        //Algorithm 5
        int N;
        int flag[10000]; //소수가 저장될 배열
        flag[0] = 2;   //첫번째는 2로 저장
        flag[1] = 3;   //두번째는 3으로 저장
        int n=1 ;    //index 1부터 저장 (3은 뒤에서 1번 다시 저장해줌)
        printf("5_N: ");
        scanf("%d", &N);

        printf("2부터 %d까지의 소수: ", N);

        if (N >= 2) {
            printf("2 ");
        }

        for (int i = 3; i <= N; i += 2) { // 2를 제외한 모든 짝수를 대상에서 제외하고 홀수만 검사
            bool is_flag = true;

            int check = 1;

            while (flag[check]<=sqrt(i)) { //소수가 root(i)보다 작거나 같을때만 실행
                total_operations++;
                if (i % flag[check] == 0) {
                    is_flag = false;
                    break;
                }
                check++;
            }

            if (is_flag) {
                printf("%d ", i);
                flag[n] = i;
                n++;
            }
        }
        printf("\nTotal operations: %d\n", total_operations);   // 총 연산 횟수 출력 N: 100 >> 84
    }
    else if(algorithm_number == 6){
    int N;
    printf("N: ");
    scanf("%d", &N);

    if (N >= 2) {
        printf("2부터 %d까지의 소수: 2 ", N);
    }
    bool is_flag[10000]; // 소수 여부를 저장할 배열

    for (int i = 0; i <= N; i++) {
        is_flag[i] = true; // 초기에 모든 수를 소수로 설정
    }

    for (int j = 3; j <= N; j += 2) {
        if (is_flag[j]) {
            printf("%d ", j); // 현재 숫자는 소수로 출력

            total_operations++;

            for (int multiple = j * j; multiple <= N; multiple += 2 * j) {
                is_flag[multiple] = false; // j의 배수들을 소수가 아닌 것으로 표시
                total_operations++;
            }
        }
    }

    printf("\nTotal operations: %d\n", total_operations);   // 총 연산 횟수 출력 N : 100 >> 52

    return 0;
    }
}
