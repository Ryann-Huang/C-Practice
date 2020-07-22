#include <stdio.h>

int main(void) {
    /*
        你可以將遞增或遞減運算子撰寫在變數之前或變數之後，
        但其實兩者是有差別的，將遞增（遞減）運算子撰寫在變
        數前時，表示先將變數的值加（減）1，然後再傳回變數
        的值，將遞增（遞減）運算子撰寫在變數之後，表示先傳
        回變數值，然後再對變數加（減）1
    */

    int i = 0;
    int num = 0;

    num = ++i;   // 相當於i = i + 1; num = i;
    printf("%d\n", num);

    num = --i;    // 相當於i = i - 1; num = i;
    printf("%d\n", num);


    i = 0;
    num = 0;

    num = i++;    // 相當於num = i; i = i + 1;
    printf("%d\n", num);

    num = i--;     // 相當於 num = i; i = i - 1;
    printf("%d\n", num);

    return 0;
}
