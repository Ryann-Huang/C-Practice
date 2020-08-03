#include <stdio.h>
#include "math.h"
#include "math.c"

/* 可以使用 gcc math.c main.c 來編譯

   在編譯時期，編譯器會檢查被呼叫的函式，若無法根據函式名稱、提供的引數型態與函式宣告上參
   數型態來決定被呼叫的函式，會出現編譯錯誤，這就是必須先作函式宣告的原因，這對編譯器的檢
   查工作是必要的資料。
   */

int main(void) {
    int num = 0;
    int p = 0;

    printf("Input a integer: ");
    scanf("%d", &num);

    printf("Input the power of the integer: ");
    scanf("%d", &p);

    printf("The integer to the 2nd power = %d\n", power2(num));
    printf("The integer to the %d power = %d\n", p, power(num, p));

    return 0;
}
