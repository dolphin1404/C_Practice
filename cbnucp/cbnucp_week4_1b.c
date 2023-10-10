#include <stdbool.h>
#include <stdio.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char x) {
  if (top < MAX_STACK_SIZE - 1) {
    stack[++top] = x;
  }
}

// Function to pop an element from the stack
char pop() {
  if (top >= 0) {
    return stack[top--];
  }
  return '\0';  // Empty stack
}

// Function to check if a character is an operand
bool isOperand(char x) {
  return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int precedence(char x) {
  if (x == '+' || x == '-') {
    return 1;
  } else if (x == '*' || x == '/') {
    return 2;
  }
  return 0;  // For '('
}
// Function to convert infix expression to postfix expression
void infixToPostfix(char *expression) {
  char *ptr = expression;
  char x;

  while (*ptr != '\0') {
    x = *ptr;
    ptr++;

    if (isOperand(x)) {
      printf("%c", x);
    } else if (x == ')') {
      while (stack[top] != '(') {
        printf("%c", pop());
      }
      pop();  // Pop '('
    } else if (top == -1 || x == '(') {
      push(x);
    } else {
      while (top >= 0 && stack[top] != '(' &&
             precedence(stack[top]) >= precedence(x)) {
        printf("%c", pop());
      }
      push(x);
    }
  }

  while (top >= 0) {
    printf("%c", pop());
  }
}

int main() {
  char expression[100];
  printf("Enter an infix expression: ");
  scanf("%s", expression);

  printf("Postfix expression: ");
  infixToPostfix(expression);

  return 0;
}

/*#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100  // 스택의 최대크기 상수화

int stack[MAX_STACK_SIZE];  // stack 배열 생성
int top = -1;
int *p;
p = &top;  // stack 저장위치 값을 가지는 top 변수 초기화

char pop() {
  if (top < 0) {
    printf("stack empty");
    return top;
  }
  return stack[(*p)--];
}

void push(char token) {
  if (MAX_STACK_SIZE - 1 == top) {
    printf("stack full");
    return 0;
  }
  stack[++(*p)] = token;
}
int precedence(char x) {
  if (x == '+' || x == '-') {
    return 1;
  } else if (x == '*' || x == '/') {
    return 2;
  }
  return 0;  // For '('
}

bool isOperand(char x) {
  return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

void infixToPostfix(char *exp) {
  char *pt = exp;
  char x;

  while (*pt != '\0') {
    x = *pt;
    pt++;

    if (isOperand(x)) {
      printf("%c", x);
    } else if (x == ')') {
      while (stack[top] != '(') {
        printf("%c", pop());
      }
      pop();  // pop '('
    } else if (top == -1 || x == '(') {
      push(x);
    } else {
      while (top >= 0 && stack[top] != '(' &&
             precedence(stack[top]) >= precedence(x)) {
        printf("%c", pop());
      }
      push(x);
    }
  }
  while (top >= 0) {
    printf("%c", pop());
  }
}

int main() {
  char expression[100];
  printf("Enter an infix expression: ");
  scanf("%s", expression);

  printf("Postfix expression: ");
  infixToPostfix(expression);

  return 0;
}
*/