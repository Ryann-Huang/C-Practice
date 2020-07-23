#include <stdio.h>

void clearBuf();

int main(void) {
    int a;
    printf("Type one integer:");
    scanf("%d", &a);
    if (a & 1) {
        printf("%d is odd number\n\n", a);
    }else {
        printf("%d is even number\n\n", a);
    }

    if (a % 2) {
        printf("%d is odd number\n\n", a);
    }else {
        printf("%d is even number\n\n", a);
    }

    clearBuf();

    int score;
    printf("Please input the score:");
    scanf("%d", &score);
    if (score >= 90) {
        puts("A\n\n");
    }else if (score >= 80) {
        puts("B\n\n");
    }else if (score >= 70) {
        puts("C\n\n");
    }else if (score >= 60) {
        puts("D\n\n");
    }else {
        puts("E\n\n");
    }

    return 0;
}

void clearBuf() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {};
}
