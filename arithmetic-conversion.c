#include <stdio.h>

int main(void) {
    int number = 10;
    printf("number = %d\n\n", number/3);

    double number1 = 10.0;
    printf("number1 = %f\n\n", number1/3);
    /*
        這是 C 的隱式型態轉換（Implicit type conversion），在一個型態混雜的算式中，長度較長的資料型態會成為目標型態，
        較小的型態會自動提升為目標型態，因而在上例中3會被提升為 3.0 再進行運算，
        結果就可以顯示無誤，這樣的轉換又稱算術轉換（Arithmetic conversion）。
    */

    int number3 = 10;
    // 在一個指定( = )的動作中，左邊的數值會成為目標型態，當右邊的數值型態比左邊的數值型態長度小時，右邊的數值會自動提升為目標型態
    double number4 = number3;
    printf("number4 = %f\n\n", number4);

    int number5 = 0;
    double number6 = 3.14;
    // 在指定( = )的動作時，如果右邊的數值型態比左邊的數值型態長度大時，超出可儲存範圍的部份會被自動消去
    number5 = number6;
    printf("number5 = %d\n\n", number5);

    int number7 = 10;
    printf("%d/3 = %f\n\n", number7, (double)number7/3);

    return 0;
}
