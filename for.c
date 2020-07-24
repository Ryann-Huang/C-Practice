#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 1; i <= 9; i++) {
        for (j = 2; j <= 9; j++) {
            printf("%d*%d=%2d  ", j, i, j*i);
        }
        printf("\n");
    }

    puts("");

    for (i = 2, j = 1; j <= 9; i == 9 ? i = (++j/j) + 1 : i++) {
        printf("%d*%d=%2d%c", i, j , i*j, i == 9 ? '\n' : ' ');
    }

    return 0;
}
