#include <stdio.h>

/* C 本身不支援在定義函式指定預設引數，然而，可以透過結構與巨集來處理，例如，若有個結構與
   函式如下：
   */
typedef struct {
    int a;
    double b;
} foo_args;

void _foo(foo_args args) {
    int a = args.a ? args.a : 8;
    double b = args.b ? args.b : 3.14;
    printf("a: %d\n", a);
    printf("b: %f\n", b);
}
/* 如果 a 成員沒有指定，預設的成員值會是 0，在 _foo 中就會使用 8 作為預設值，類似地，若 b
   成員沒有指定，預設值會是 0.0，這時會使用 3.14 作為預設值。
   */

/* 不過每次都得撰寫 (foo_args) 與 {} 感覺不是很方便，這可以可以定義巨集來展開：*/
#define foo(...) _foo((foo_args) {__VA_ARGS__});

/* 若要設置必要參數，可以如下：*/
#define foo_with_must(must, ...) _foo_with_must(must, (foo_args) {__VA_ARGS__});

_foo_with_must(char must, foo_args args) {
    int a = args.a ? args.a : 8;
    double b = args.b ? args.b : 3.14;
    printf("must: %c\n", must);
    printf("a: %d\n", a);
    printf("b: %f\n", b);
}

/* 如果只想模擬具名參數風格，由於結構若具名地指定成員時，重複是可以允許的，也就可以撰寫如下：*/
#define foo_with_args(must, ...) _foo_with_args(must, (foo_args) {.a = 8, .b = 3.14, __VA_ARGS__});

_foo_with_args(char must, foo_args args) {
    printf("must: %c\n", must);
    printf("a: %d\n", args.a);
    printf("b: %f\n", args.b);
}

int main(void) {
    _foo((foo_args) {});
    _foo((foo_args) {10});
    _foo((foo_args) {10, 20.0});
    _foo((foo_args) {.a = 5, .b = 30});
    /* 以上建立了匿名的 foo_args 實例並傳入，由於可以指定成員名稱來設值，也就可以有具名參
       數指定的風格。
       */
    putchar('\n');

    foo();
    foo(10);
    foo(10, 20);
    foo(.a = 5, .b = 30);
    /* 巨集的出發點是字串取代（或稱擴展），... 代表引數的部份，後續可以使用 __VA_ARGS__ 在
       指定位置展開，以 foo(10, 20) 為例，... 捕捉了 10, 20，後續的 __VA_ARGS__ 會展開為
       10, 20，因此整個 foo(10, 20) 會被展開為 _foo((foo_args) {10, 20})。
       */
    puts("\n");

    foo_with_must('A');
    foo_with_must('B', 10);
    foo_with_must('C', 10, 20);
    foo_with_must('D', .a = 5, .b = 30);
    putchar('\n');

    foo_with_args('A');
    foo_with_args('B', .a = 5);
    foo_with_args('C', .b = 88);
    foo_with_args('D', .b = 9, .a = 2);

    return 0;
}
