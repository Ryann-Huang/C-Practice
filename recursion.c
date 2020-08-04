#include <stdio.h>

int gcd(int, int);
int gcd_with_loop(int, int);

int main(void) {
    /* 遞迴（Recursion）是在函式中呼叫自身，呼叫者會先置入記憶體堆疊，被呼叫者執行完後，
       再從堆疊取出被置入的函式繼續執行。堆疊（Stack）是一種「先進後出」的資料結構，就好
       比將書本置入箱中，最先放入的書會最後才取出。

       C 支援函式遞迴呼叫，遞迴之目在於執行重複任務，例如，求最大公因數可以使用遞迴，下面
       的程式是使用遞迴來求最大公因數的範例：
       */
    int m, n;

    printf("Please input two integers(with one space between them): ");
    scanf("%d %d", &m, &n);

    printf("GCD: %d\n", gcd(m, n));


    /* 上面的程式是使用輾轉相除法來求最大公因數；可以使用遞迴求解的程式，基本上也可以使用
       迴圈求解，例如下面的程式就是最大公因數的迴圈求解方式：
       */
    printf("GCD from loop: %d\n", gcd_with_loop(m, n));


    /* 那麼使用遞迴還是使用迴圈求解？這沒有一定的答案，也有看程式語言是否可以做遞迴最佳化，
       因為遞迴函式會在記憶體中堆疊，語言會有堆疊的數量限制，若遞迴最佳化能展開遞迴，轉為
       迴圈形式，可以避開這類限制。

       這麼說來，使用迴圈比較好？並非如此，開發者很容易在迴圈執行過多的任務，令迴圈難以閱
       讀、理解與維護，特別是令那些本質上可以分而治之的任務，難以抽取、平行化，或者令原始
       碼本質上其實重複的流程，難以辨識出來。
       */

    return 0;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }else {
        return gcd(b, a%b);
    }
}

int gcd_with_loop(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
