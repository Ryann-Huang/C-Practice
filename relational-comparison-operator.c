#include <stdio.h>

int main(void) {
    printf("10 > 5\t\t%d\n", 10 > 5);
    printf("10 >= 5\t\t%d\n", 10 >= 5);
    printf("10 < 5\t\t%d\n", 10 < 5);
    printf("10 <= 5\t\t%d\n", 10 <= 5);
    printf("10 == 5\t\t%d\n", 10 == 5);
    printf("10 != 5\t\t%d\n", 10 != 5);

    // 在 C 中，所有非零的數值在作為條件式時都被視為真
    int score = 0;
    printf("輸入學生分數：");
    scanf("%d", &score);
    printf("該生是否及格？%c\n\n", score >= 60 ? 'Y' : 'N');

    int input = 0;
    printf("輸入整數：");
    scanf("%d", &input);
    printf("該數為奇數？%c\n\n", input % 2 ? 'Y' : 'N');

    return 0;
}
