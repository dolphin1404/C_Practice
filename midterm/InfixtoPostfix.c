#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;  // 데이터 스택의 데이터 형식을 정의
typedef struct {
  element stack[MAX_STACK_SIZE];  // 스택 배열
  int top;  // 스택의 현재 상단을 가리키는 인덱스
} StackType;

int is_empty(StackType *s) {
  return (s->top == -1);
}  // 스택이 비어 있는지 확인하는 함수

int is_full(StackType *s) {
  return (s->top == MAX_STACK_SIZE - 1);
}  // 스택이 가득 찼는지 확인하는 함수

void init(StackType *s) { s->top = -1; }  // 스택을 초기화하는 함수

void push(StackType *s, element item) {
  if (is_full(s)) {  // 스택이 가득 차있으면 에러 출력
    fprintf(stderr, "스택 포화 에러\n");
    return;
  } else
    s->stack[++(s->top)] = item;  // 스택에 아이템을 추가
}

element peek(StackType *s) {
  if (is_empty(s)) {  // 스택이 비어 있으면 에러 출력
    fprintf(stderr, "스택 공백 에러\n");
    exit(1);
  } else
    return s->stack[s->top];  // 스택의 현재 상단 아이템을 반환
}

element pop(StackType *s) {
  if (is_empty(s)) {  // 스택이 비어 있으면 에러 출력
    fprintf(stderr, "스택 공백 에러\n");
    exit(1);
  } else
    return s->stack[(s->top)--];  // 스택에서 아이템을 제거하고 반환
}

int prec(char op) {
  switch (op) {
    case '(':  // 여는 괄호
    case ')':  // 닫는 괄호
      return 0;
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
  }
  return -1;  // 연산자 우선순위가 정의되지 않은 경우
}

void infix_to_postfix(const char *infix, char *postfix) {
  StackType s;
  init(&s);  // 스택 초기화

  while (*infix != '\0') {
    if (*infix == '(') {  // 여는 괄호인 경우
      push(&s, *infix);   // 스택에 푸시하고 다음 문자로 이동
      infix++;
    } else if (*infix == ')') {  // 닫는 괄호인 경우
      while (peek(&s) != '(') {  // 스택의 상단이 여는 괄호가 아닐 때까지
        *postfix++ = pop(&s);  // 스택의 값을 꺼내서 후위 표기식에 추가
        *postfix++ = ' ';
      }
      pop(&s);  // 여는 괄호를 스택에서 제거
      infix++;
    } else if (*infix == '+' || *infix == '-' || *infix == '*' ||
               *infix == '/') {
      while (!is_empty(&s) && (prec(*infix) <= prec(peek(&s)))) {
        *postfix++ = pop(&s);
        *postfix++ = ' ';
      }
      push(&s, *infix);
      infix++;
    } else if (*infix >= '0' && *infix <= '9') {
      do {
        *postfix++ = *infix++;
      } while ((*infix >= '0' && *infix <= '9'));
      *postfix++ = ' ';
    } else
      infix++;
  }

  while (!is_empty(&s)) {
    *postfix++ = pop(&s);
    *postfix++ = ' ';
  }
  postfix--;
  *postfix = '\0';  // 후위 표기식 문자열 마무리

  printf("%s\n", infix);  // 입력 중위 표기식 출력
  printf("%s", postfix);  // 후위 표기식 출력
}

int evaluate_postfix(char *postfix) {
  StackType s;
  init(&s);

  while (*postfix != '\0') {
    if (*postfix >= '0' && *postfix <= '9') {
      int num = 0;
      while (*postfix >= '0' && *postfix <= '9') {
        num = num * 10 + (*postfix - '0');
        postfix++;
      }
      push(&s, num);
    } else if (*postfix == ' ') {
      postfix++;
    } else {
      int operand2 = pop(&s);
      int operand1 = pop(&s);
      int result;
      switch (*postfix) {
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
            fprintf(stderr, "0으로 나누기 오류\n");
            exit(1);
          }
          result = operand1 / operand2;
          break;
      }
      push(&s, result);
      postfix++;
    }
  }

  return pop(&s);
}

int main() {
  int result;
  const char *expp = "((15-((4/2)+1))*((5*2)-2))/12";  // 입력 중위 표기식
  char *postfix = (char *)malloc(MAX_STACK_SIZE + 1);

  infix_to_postfix(expp, postfix);  // 중위 표기식을 후위 표기식으로 변환
  printf("%s\n", expp);             // 입력 중위 표기식 출력
  printf("[ %s ] ", postfix);  // 후위 표기식 출력
  result = evaluate_postfix(postfix);
  printf(" 계산 결과: %d\n", result);
  return 0;
}