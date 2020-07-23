#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("型態\t\t大小(bytes)\n");
    printf("Short\t\t%lu\n", sizeof(short));
    printf("int\t\t%lu\n", sizeof(int));
    printf("long\t\t%lu\n", sizeof(long));
    printf("float\t\t%lu\n", sizeof(float));
    printf("double\t\t%lu\n", sizeof(double));
    printf("long double\t\t%lu\n", sizeof(long double));
    printf("char\t\t%lu\n\n", sizeof(char));

    printf("bool\t\t%lu\n", sizeof(bool));
    printf("true\t\t%lu\n", sizeof(true));
    printf("false\t\t%lu\n\n", sizeof(false));

    printf("1\t\t%lu\n", sizeof(1));
    printf("1.0\t\t%lu\n\n", sizeof(1.0));

    printf("布林\t值\n");
    printf("true\t%d\n", true);
    printf("false\t%d\n\n", false);

    // literal constant
    printf("%d\n", 26);
    printf("%d\n", 032);
    printf("%d\n", 0x1A);
    // \062 : 8進位的ASCII code, 表示字元'2'
    // \x48 : 16進位的ASCII code, 表示字元'H'
    char c = '\'';
    printf("單引單字元 %c\n", c);
    printf("\"\062 個 \x48\x45\x4c\x4c\x4f\x21\"\n");


    return 0;
}
