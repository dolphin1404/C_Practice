#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1;
int rear = -1;

int addq(int item) {
  if (rear == MAX - 1)
    return 0;
  else {
    rear++;
    queue[rear] = item;
    return 1;
  }
}

int frontq() {}

int deleteq() {
  if (front == rear)
    return 0;
  else {
    front++;
    return queue[front];
  }
}

void main() {
  addq('A');
  printf("%s\n", queue);
  addq('B');
  printf("%s\n", queue);
  addq('C');
  printf("%s\n", queue);
  deleteq();
  printf("%s\n", queue);
  deleteq();
  printf("%s\n", queue);
  addq('D');
  printf("%s\n", queue);
}