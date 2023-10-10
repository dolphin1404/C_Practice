#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int push(int item) {
  if (top == MAX - 1)
    return 0;  // stack full
  else {
    top++;
    stack[top] = item;
    return 1;
  }
}

int pop() {  // pop() + top()
  int topelem;
  if (top == -1)
    return 0;  // stack empty
  else {
    topelem = stack[top];
    top--;
    return topelem;
  }
}
void main() {
  push(3);
  printf("%d\n", stack[top]);
  push(2);
  printf("%d\n", stack[top]);
  push(5);
  printf("%d\n", stack[top]);
  pop();
  printf("%d\n", stack[top]);
  pop();
  printf("%d\n", stack[top]);
  push(6);
  printf("%d\n", stack[top]);
  pop();
  printf("%d", stack[top]);
  pop();
}
