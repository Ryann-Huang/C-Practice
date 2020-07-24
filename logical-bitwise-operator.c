#include <stdio.h>

int main(void) {
    // Logical operator
    int num = 75;
    printf("%d\n", num > 70 && num < 80);
    printf("%d\n", num > 80 || num < 75);
    printf("%d\n\n", !(num > 80 || num < 75));

    // Bitwise operator
    puts("AND運算：");
    printf("0 AND 0\t\t%d\n", 0 & 0);
    printf("0 AND 1\t\t%d\n", 0 & 1);
    printf("1 AND 0\t\t%d\n", 1 & 0);
    printf("1 AND 1\t\t%d\n\n", 1 & 1);

    puts("OR運算：");
    printf("0 OR 0\t\t%d\n", 0 | 0);
    printf("0 OR 1\t\t%d\n", 0 | 1);
    printf("1 OR 0\t\t%d\n", 1 | 0);
    printf("1 OR 1\t\t%d\n\n", 1 | 1);

    puts("XOR運算：");
    printf("0 XOR 0\t\t%d\n", 0 ^ 0);
    printf("0 XOR 1\t\t%d\n", 0 ^ 1);
    printf("1 XOR 0\t\t%d\n", 1 ^ 0);
    printf("1 XOR 1\t\t%d\n\n", 1 ^ 1);

    puts("NOT運算：");
    printf("NOT 0\t\t%d\n", !0);
    printf("NOT 1\t\t%d\n\n", !1);

    char num1 = 255;
    printf("%d\n\n", ~num1);

    /*
        這個程式得以運算的原理是，奇數的數值若以二進位來表示，其最右邊的位元必為 1，
        而偶數最右邊的位元必為 0，所以使用 1 來與輸入的值作 AND 運算，由於 1 除了
        最右邊的位元為 1 之外，其他位元都會是0，與輸入數值 AND 運算的結果，只會留
        下最右邊位元為 0 或為 1 的結果，其他部份都被 0 AND 運算遮掉了，這就是所謂
        「位元遮罩」
    */
    int input = 0;
    printf("請輸入一個整數：");
    scanf("%d", &input);
    printf("輸入為奇數？ %c\n\n", input & 1 ? 'Y' : 'N');


    // XOR example: Encoding and decoding
    char ch = 'A';
    printf("before encoding: %c\n", ch);
    ch = ch ^ 0x7;
    printf("after encoding: %c\n", ch);
    ch = ch ^ 0x7;
    printf("decoding: %c\n\n", ch);


    /*
        在位元運算上，C 還有左移（<<）與右移（>>）兩個運算子，左移運算子會將所有的
        位元往左移指定的位數，左邊被擠出去的位元會被丟棄，而右邊會補上 0；右移運算
        則是相反，會將所有 的位元往右移指定的位數，右邊被擠出去的位元會被丟棄，至於
        左邊位元補 0 或補 1 則不一定，視系統而定。
    */
    int num2 = 1;
    printf("2的0次方：%d\n", num2);
    num2 = num2 << 1;
    printf("2的1次方：%d\n", num2);
    num2 = num2 << 1;
    printf("2的2次方：%d\n", num2);
    num2<<=1;
    printf("2的3次方：%d\n", num2);



    return 0;
}
