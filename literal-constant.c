#include <stdio.h>

int main(void) {
    printf("sizeof(1):\t %lu\n", sizeof(1));
    printf("sizeof(1.0):\t %lu\n\n", sizeof(1.0));

    printf("%d\n", 26);
    printf("%d\n", 032);
    printf("%d\n\n", 0x1A);

    char c = '\'';
    printf("單引號字元 %c \n", c);
    printf(" \" \062 個 \x48\x45\x4c\x4c\x4f\x21 \" \n");

    return 0;
}
