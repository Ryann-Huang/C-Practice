#include <stdio.h>
#include <stdbool.h>

/* 在這個例子中，sort 上的函式指標宣告有些難以閱讀，可以使用 typedef，定義一個比較容易
   閱讀的名稱
   */
typedef bool (*CMP)(int, int);

/* 也可以宣告函式指標陣列，例如：

   bool (*compare[10])(int, int);
   上面這個宣告產生具有 10 個元素的陣列，可以儲存 10 個 bool (*)(int, int) 函式型態的
   位址，不過這樣的宣告實在難以閱讀，可以使用 typedef 來改進：

   typedef bool (*CMP)(int, int);
   CMP compare[10];
   */

int foo(int);
void sort(int*, int, CMP compare);
bool ascending(int, int);
bool descending(int, int);
void printArray(int, int*);

int main(void) {
    /* 程式在執行時，函式在記憶體中也佔有一個空間，將函式名稱作為指定來源時，函式名稱
       會自動轉為指標，型態由傳回值型態與參數列決定，若要將之指定給另一函式指標，型態
       的宣告方式如下：

       傳回值型態 (*名稱)(參數列);

       函式指標代表著一個函式，相同型態的函式可以指定給具有相同型態的指標
       */
    int (*fp)(int) = foo;
    foo(10);
    fp(20);
    putchar('\n');

    /* foo 指定給 fp，等效於 &foo 指定給 fp，在指定之後，fp 儲存了 foo 的位址，在呼
       叫時，fp(20) 等效於 (*fp)(20)。

       函式指標可以用來傳遞函式，例如，你想撰寫用於陣列的 sort 函式，希望大小順序可以
       由呼叫者指定，這就可以傳遞函式來指定
       */
    int number[] = {3, 5, 1, 6, 9};

    sort(number, 5, ascending);
    printArray(5, number);

    sort(number, 5, descending);
    printArray(5, number);


    return 0;
}

int foo(int n) {
    printf("n = %d\n", n);
    return 0;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int* arr, int length, CMP compare) {
    int flag, i, j;
    for (flag = 1, i = 0; i < length - 1 && flag == 1; i++) {
        flag = 0;
        for (j = 0; j < length - 1 - i; j++) {
            if (compare(arr[j + 1], arr[j])) {
                swap(&arr[j + 1], &arr[j]);
                flag = 1;
            }
        }
    }
}

bool ascending(int a, int b) {
    return a < b;
}

bool descending(int a, int b) {
    return a > b;
}

void printArray(int length, int* arr) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
