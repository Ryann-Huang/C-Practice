#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("型態\t\t大小（bytes）\n");
    printf("short\t\t%lu\n", sizeof(short));
    printf("int\t\t%lu\n", sizeof(int));
    printf("long\t\t%lu\n", sizeof(long));
    printf("float\t\t%lu\n", sizeof(float));
    printf("double\t\t%lu\n", sizeof(double));
    printf("long double\t%lu\n", sizeof(long double));
    printf("char\t\t%lu\n\n", sizeof(char));

    printf("sizeof(bool)\t%d\n", sizeof(bool));
    printf("sizeof(true)\t%d\n",  sizeof(true));
    printf("sizeof(false)\t%d\n\n",  sizeof(false));

    // value
    printf("true\t%d\n", true);
    printf("false\t%d\n", false);

    return 0;
}
