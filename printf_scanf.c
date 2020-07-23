#include <stdio.h>

int main(void) {
    // \n 視為一個字元
    int count = printf("This is a test!\n");
    printf("%d\n\n", count);

    printf("顯示字元 %c\n", 'A');
    printf("顯示字元編碼 %d\n", 'A');
    printf("顯示字元 %c\n", 65);
    printf("顯示十進位整數 %d\n", 15);
    printf("顯示八進位整數 %o\n", 15);
    printf("顯示十六進位整數 %x\n", 15);
    printf("顯示十六進位整數 %X\n", 15);
    printf("顯示科學記號 %e\n", 0.01234);
    printf("顯示科學記號 %E\n\n", 0.001234);

    printf("%6.2f\n", 19.234);
    printf("%-6.2f\n", 19.234);
    printf("%*d\n", 1, 1);
    printf("%*d\n", 2, 1);
    printf("%*d\n", 3, 1);
    printf("%.*s\n", 3, "Justin");
    printf("%.*s\n", 5, "Justin");
    printf("%.*s\n\n", 7, "Justin");


    int input;
    double dInput;

    printf("Type a number:");
    scanf("%d", &input);
    printf("The number you type is: %d\n\n", input);

    printf("Type a float point number: ");
    scanf("%lf", &dInput);
    printf("The float point number you type is: %lf\n\n", dInput);

    int num1, num2;
    printf("Type two numbers separated by one space: ");
    scanf("%d %d", &num1, &num2);
    printf("Two numbers you type are: %d %d\n\n", num1, num2);

    printf("Type two numbers separated by '-': ");
    scanf("%d-%d", &num1, &num2);
    printf("You type: %d-%d\n\n", num1, num2);

    fflush(stdin);

    char buf[50l];

    printf("請輸入1到5的字元: ");
    scanf("%[1-5]", buf);
    printf("輸入的字元為 %s\n\n", buf);

    fflush(stdin);

    printf("請輸入XYZ任一字元: ");
    scanf("%[XYZ]", buf);
    printf("輸入的字元為 %s\n\n", buf);

    fflush(stdin);

    char str[10];
    printf("請輸入字串: ");
    scanf("%9s", str); // 限定scanf能讀入的長度
    printf("輸入的字串: %s\n\n", str);;



    return 0;
}
