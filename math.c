#include "math.h"

/* 在 C 中如果呼叫函式不傳回任何值，則宣告為 void，若不傳入任何引數，則參數列保持空白即可，
   也可以使用 void 來加以註明，標頭檔案被儲存為 .h 檔案，接著可以根據函式原型來實作函式主
   體，例如，在 math.c 中撰寫：
   */

int power2(int num) {
    return power(num, 2);
}

int power(int n, int p) {
    int r = 1;
    int i;
    for (i = 0; i < p; i++) {
        r*=n;
    }

    return r;
}
