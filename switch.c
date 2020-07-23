#include <stdio.h>

int main(void) {
    int score, level;
    printf("Input the score:");
    scanf("%d", &score);
    level = score / 10;

    switch(level) {
    case 10:
    case 9:
        puts("A\n\n");
        {
            /*
                這是因為以上的程式碼中，default 與 case 屬於同一區塊，而初始可能被跳過，
                如果真的要在 case 中若宣告並初始變數，必須明確定義另一個區塊
            */
            int a = 0;
        }
        break;
    case 8:
        puts("B\n\n");
        break;
    case 7:
        puts("C\n\n");
        break;
    case 6:
        puts("D\n\n");
        break;
    default:
        puts("E\n\n");
    }

    return 0;
}
