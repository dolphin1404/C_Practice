#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 7
#define COL 12

int maze[ROW][COL] = {'0'};

void readMazeFromFile(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Failed to open the file: %s\n", filename);
  } else {
    for (int r = 0; r < ROW; r++) {
      for (int c = 0; c < COL; c++) {
        if (fscanf(file, "%d", &maze[r][c]) != 1) {
          printf("Failed to read data from the file.\n");
          exit(1);
        }
      }
    }
  }
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      printf("%d", maze[r][c]);
      if (c == COL - 1) printf("\n");
    }
  }
  printf("Complete");
  fclose(file);
}

int route[ROW][COL][3];
int* ans[ROW * COL] = (int *) malloc(ROW * COL);
int top = 0;
int startR, startC;
int destR, destC;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int isValidPos(int r, int c) {  // 맞는 길인지
  if (r < 0 || r >= ROW || c < 0 || r >= COL) return 0;
  return 1;
}

void getRoute(int r, int c) {
  if (r == startR && c == startC) return;
  ans[top++] = route[r][c];
  getRoute(route[r][c][0], route[r][c][1]);
}

void bfs(int R, int C) {
  int q[ROW * COL][3];
  int visited[ROW][COL];
  memset(visited, 0, sizeof(int[ROW][COL]));
  visited[R][C] = 1;
  int r, c, nr, nc;
  int front = 0, rear = 0;
  q[rear][0] = R;
  q[rear][1] = C;
  rear++;
  while (front < rear) {
    r = q[front][0];
    c = q[front][1];
    front++;
    for (int i = 0; i < 4; i++) {
      nr = r + dir[i][0];
      nc = c + dir[i][1];
      if (!isValidPos(nr, nc) || visited[nr][nc] || maze[nr][nc] == 1) continue;
      q[rear][0] = nr;
      q[rear][1] = nc;
      rear++;
      route[nr][nc][0] = r;
      route[nr][nc][1] = c;
      route[nr][nc][2] = i;
      visited[nr][nc] = 1;
      if (nr == destR && nc == destC) break;
    }
    if (nr == destR && nc == destC) break;
  }
}

int main(int argc, char* argv[]) {
  printf("Input Start ROW COL : ");
  scanf("%d %d", &startR, &startC);
  printf("Input Destination ROW COL : ");
  scanf("%d %d", &destR, &destC);

  if (argc != 2) {
    printf("Usage: %s <maze_file>\n", argv[0]);
  }
  const char* mazeFile = argv[1];
  readMazeFromFile("mazeFile.txt");
  FILE* fp = freopen("output.txt", "w", stdout);
  // 입력 잘 받기 : 시작 좌표, 도착 좌표 받아 startR, startC, destR, destC 에
  // 넣고 미로도 입력받거나 해서 maze에 저장
  // startR = 1;
  // startC = 0;
  // destR = 5;
  // destC = 11;
  bfs(startR, startC);
  getRoute(destR, destC);
  for (top = top - 1; top >= 0; top--)
    printf("%d %d %d\n", ans[top][0], ans[top][1], ans[top][2]);
  fclose(fp);
  return 0;
}