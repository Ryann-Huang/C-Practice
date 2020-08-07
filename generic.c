#include <stdio.h>
#include <math.h>

/* C11 提供了 _Generic 選擇，用來模擬泛型程式，其本質是類似 switch 的選擇陳述，不過是編譯
   時期根據型態來選擇展開的對象。
   */
#define V_TYPE 0
#define WAT _Generic(V_TYPE, float: 2.0,   \
                             char *: "XD", \
                             int: 10,      \
                             default: 'a')
/* 根據 V_TYPE 的型態，WAT 會展開為 2.0、"XD"、10 等，如果沒有符合的型態，就使用 default
   的'a'。

   其應用之一，就是用來模擬 C 語言本身不支援的函式重載（function overloading），例如，根據
   參數型態的不同，選擇真正對應的函式
   */

/* 然而，如果想以同一個名稱來呼叫，可以定義 _Generic 選擇：*/
#define cbrt_marco(X) _Generic((X), long double: cbrtl, \
                                    float: cbrtf,       \
                                    default: cbrt       \
                              )(X)

/* 當然，只要選擇有依據，也可以是多個參數，例如：*/
#define foo(a, b) _Generic((a), int: foo1,    \
                                default: foo2 \
                          )(a, b)

void foo1(int a, int b) {
    printf("foo1: %d %d\n", a, b);
}

void foo2(double a, int b) {
    printf("foo2: %f %d\n", a, b);
}

/* 在上面的範例中，選擇的依據是第一個參數的型態，在更複雜的範例中，可能要根據第二個參數的
   型態來選擇，這時可以如下：
   */
#define foo_two(a, b) _Generic((a), int: foo3,                         \
                                    double: _Generic((b), int: foo4,   \
                                                          double: foo5 \
                              ))(a, b)
/* 當然，還可以結合 ...、__VA_ARGS__ 等，撰寫更複雜的巨集，只不過很難撰寫與維護，該用在哪
   些場合，還是得在可讀性等方面評估一下。
   */

void foo3(int a, int b) {
    printf("foo3: %d %d\n", a, b);
}

void foo4(double a, int b) {
    printf("foo4: %f %d\n", a, b);
}

void foo5(double a, double b) {
    printf("foo5: %f %f\n", a, b);
}


int main(void) {
    /* 像是 math.h 中定義有 cbrt、cbrtl、cbrtf 等函式，可用來求得 double、long double、
       float 等引數的立方根，基本上可以如下使用：
       */
    double x = 8.0;
    const float y = 3.375;
    printf("cbrt(8.0) = %f\n", cbrt(x));
    printf("cbrtf(3.375) = %f\n", cbrtf(y));
    putchar('\n');

    printf("cbrt_marco(8.0) = %f\n", cbrt_marco(x));
    printf("cbrt_marco(3.375) = %f\n", cbrt_marco(y));
    /* 以 cbrtf(3.375) 為例，x 是 float 型態，_Generic 透過第一個 (X) 展開後的 (3.375)
       比對後選擇預設的 cbrtf，之後結合第二個 (X) 展開後的 (3.375) 成為 cbrtf(3.375)
       */
    putchar('\n');

    foo(1, 10);
    foo(1.0, 10);
    putchar('\n');

    foo_two(1, 5);
    foo_two(1.0, 10);
    foo_two(1.0, 3.14);
    foo_two(1, 5.3);



    return 0;
}
