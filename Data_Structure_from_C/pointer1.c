#include <stdio.h>
#include <stdlib.h>

void main() {
  int i = 100;
  int *ptr = &i;

  char *ptr1 = (char *)malloc(10);
  ptr1[0] = 100;
  char *ptr2 = "korea";

  char A[100] = {'A', 'B'};
  char *ptr3 = A;

  char B[100] = {'a', 'b'};
  char *ptr4 = &B[0];
  char *ptr5 = &B[1];

  printf("\n &i = %u", &i);
  printf("\n ptr = %u, *ptr = %d", ptr, *ptr);  // ptr = 주소값, *ptr = 참조값
  printf("\n ptr1 = %u, *ptr1 = %d ", ptr1, *ptr1);
  for (int j = 0; j < 11; j++) printf("%d ", ptr1[j]);
  free(ptr1);
  printf("\n ptr1 = %u, *ptr1 = %d", ptr1, *ptr1);
  printf("\n prt2 = %u, *ptr2 = %c", ptr2, *ptr2);
  printf("\n prt3 = %u, *ptr3 = %c", ptr3, *ptr3);
  printf("\n prt4 = %u, *ptr4 = %c \n ptr5 = %u, *prt5 = %c", ptr4, *ptr4, ptr5,
         *ptr5);

  // 포인터배열
  int j;
  char *ptrArray[4] = {{"Korea"}, {"Seoul"}, {"Mapo"}, {"152번지 2 / 3"}};
  for (j = 0; j < 4; j++) {
    printf("\n %s", ptrArray[j]);
  }

  ptrArray[2] = "Jongno";
  printf("\n\n");
  for (j = 0; j < 4; j++) printf("\n %s", ptrArray[j]);
}