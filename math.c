#include "math.h"

/* 在 C 中如果呼叫函式不傳回任何值，則宣告為 void，若不傳入任何引數，則參數列保持空白即可，
   也可以使用 void 來加以註明，標頭檔案被儲存為 .h 檔案，接著可以根據函式原型來實作函式主
   體，例如，在 math.c 中撰寫：
   */

/* 在呼叫函式時會有額外的資源負擔，一些小函式，可以「建議」編譯器設為 inline 行內，若建議
   被採納，該函式會自動在呼叫點展現為程式碼

   inline 函式只能建議編譯器，建議不一定被採納，例如遞迴函式無法在呼叫點展開，數千行的函式
   也不適合在呼叫點展開，如果編譯器拒絕將函式展開，會視為一般函式進行編譯，inline 的建議會
   被忽略。

   C99 的 inline 規則，與 GNU 的 inline 規則有所不同，詳情可參考〈Inline Functions In C〉。
   */
inline int power2(int num) {
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
