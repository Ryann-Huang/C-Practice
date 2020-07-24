#include <stdio.h>
#define ROW 5
#define COLUMN 10

int main(void) {
    int maze[ROW][COLUMN];
    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            maze[i][j] = (i + 1) * (j + 1);
        }
    }

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            printf("%d\t", maze[i][j]);
        }
        printf("\n");
    }

    putchar('\n');

    int row = 2, column = 3;
    int maze1[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (i = 0; i < row; i++) {
        int* a = maze1[i];
        for (j = 0; j < column; j++) {
            printf("%d\t", a[j]);
        }
    }

    return 0;
}
