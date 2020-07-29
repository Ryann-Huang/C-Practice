#include <stdio.h>

int main(void) {
    /* 指標的加法與減法與一般數值的加減法不同，在指標運算上加 1 ，是表示前進一個資料型態
       的記憶體長度，例如在 int 型態的指標上加 1，是表示在記憶體位址上前進 4 個位元組的長度
       */
    int *p = 0;

    printf("address stored in p: %p\n", p);
    printf("p + 1: %p\n", p + 1);
    printf("p + 2: %p\n\n", p + 2);


    /* 這個記憶體位址的顯示單位是位元組；由於宣告的是 int 型態的指標，所以每加 1 就會前進
       4 個位元組的長度，如果宣告的是 double 型態的指標，則每加 1 就會前進 8 個位元組
       */

    double *q = 0;
    printf("address stored in q: %p\n", q);
    printf("q + 1: %p\n", q + 1);
    printf("q + 2: %p\n", q + 2);


    /* 以上舉的例子為指標的加法，在減法上觀念也是相同，對指標減 1 即是在記憶體位址上退後一
       個資料型態單位的長度。
       */

    return 0;
}
