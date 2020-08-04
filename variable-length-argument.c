#include <stdio.h>
#include <stdarg.h>

void foo(int len, double *params);
void foo_var(int len, ...);
void print_positive_ints(int first, ...);

int main(void) {
    /* 在定義函式時，有時無法事先得知要傳遞的參數個數，透過陣列收集是方式之一，例如：*/
    double x = 1.1, y = 2.1, z = 3.1;
    double a = 0.1, b = 0.2, c = 0.3;

    puts("Three arguments:");
    foo(3, (double[]){x, y, z});

    puts("Six arguments:");
    foo(6, (double[]){x, y, z, a, b, c});
    puts("\n");

    /* 或許你會覺得 double[] 形態的指定與 {} 很煩，這邊介紹不定長度引數
       （Variable-length argument）的使用，為了要使用不定長度引數，必須包含 stdarg.h
       標頭檔案：
       */
    puts("Three arguments with variable length arguments:");
    foo_var(3, x, y, z);
    puts("Six arguments with variable length arguments:");
    foo_var(6, x, y, z, a, b, c);
    puts("\n");
    /* 上例中由於首個參數用來規範不定長度型態，也是唯一的具名參數，就用來作為指定將有
       幾個不定長度引數。
       */


    /* va_start 第二個引數要指定最後一個具名參數，因此未必得以第一個參數指出引數的數量 */
    print_positive_ints(1, 2, 3, 4, 5, -1);

    return 0;
}

void foo (int len, double *params) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%.1f\n", params[i]);
    }
}

void foo_var(int len, ...) {
    va_list args;
    va_start(args, len);

    int i;
    for (i = 0; i < len; i++) {
        printf("%.1f\n", va_arg(args, double));
    }

    va_end(args);
}

void print_positive_ints(int first, ...) {
    va_list args;
    va_start(args, first);

    int arg;
    for (arg = first; arg > 0; arg = va_arg(args, int)) {
        printf("%d\n", arg);
    }

    va_end(args);
}
