#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// 스택을 정의합니다.
char stack[MAX_STACK_SIZE];
int top = -1;

// 우선순위를 정의합니다. isp(In-Stack Priority)와 icp(In-Coming Priority)를
// 사용합니다.
int isp(char op) {
  if (op == '(') return 0;
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return -1;  // 연산자가 아닌 경우
}

int icp(char op) {
  if (op == '(') return 3;
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return -1;  // 연산자가 아닌 경우
}

// 스택에 원소를 푸시합니다.
void push(char item) {
  if (top >= MAX_STACK_SIZE - 1) {
    printf("스택 오버플로우\n");
    exit(1);
  }
  stack[++top] = item;
}

// 스택에서 원소를 팝합니다.
char pop() {
  if (top == -1) {
    printf("스택 언더플로우\n");
    exit(1);
  }
  return stack[top--];
}

// 주어진 수식을 postfix로 변환하는 함수
void infixToPostfix(char* expression) {
  char x;
  int i = 0;

  while (expression[i] != '\0') {
    x = expression[i];
    if (x >= '0' && x <= '9') {
      // 피연산자인 경우 바로 출력
      printf("%c", x);
    } else if (x == '(') {
      // 여는 괄호는 스택에 푸시
      push(x);
    } else if (x == ')') {
      // 닫는 괄호를 만나면 스택에서 여는 괄호를 만날 때까지 팝하고 출력
      while (stack[top] != '(') {
        printf("%c", pop());
      }
      pop();  // 여는 괄호 제거
    } else {
      // 연산자인 경우
      while (top > -1 && isp(stack[top]) >= icp(x)) {
        printf("%c", pop());
      }
      push(x);
    }
    i++;
  }

  // 스택에 남아있는 모든 연산자를 출력
  while (top > -1) {
    printf("%c", pop());
  }

  printf("\n");
}

int evaluatePostfix(char* postfix) {
  // postfix로 표현된 수식을 계산하는 함수
  int stack[MAX_STACK_SIZE];
  int top = -1;
  int i = 0;

  while (postfix[i] != '\0') {
    char token = postfix[i];
    if (token >= '0' && token <= '9') {
      // 피연산자인 경우 스택에 푸시
      stack[++top] = token - '0';
    } else {
      // 연산자인 경우 스택에서 피연산자를 팝하여 연산 후 결과를 다시 스택에
      // 푸시
      int operand2 = stack[top--];
      int operand1 = stack[top--];
      int result;

      switch (token) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          if (operand2 == 0) {
            printf("0으로 나눌 수 없습니다.\n");
            exit(1);
          }
          result = operand1 / operand2;
          break;
        default:
          printf("잘못된 연산자: %c\n", token);
          exit(1);
      }
      stack[++top] = result;
    }
    i++;
  }

  if (top != 0) {
    printf("잘못된 postfix 표현\n");
    exit(1);
  }

  return stack[top];
}

int main() {
  char infixExpression[100];

  printf("Infix 표현식을 입력하세요: ");
  scanf("%s", infixExpression);

  printf("Postfix 표현식: ");
  infixToPostfix(infixExpression);

  int result = evaluatePostfix(infixExpression);
  printf("계산 결과: %d\n", result);

  return 0;
}
