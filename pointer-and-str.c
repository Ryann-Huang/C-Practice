#include <stdio.h>

typedef const char* String;

int main(void) {
    char *text = "hello";
    // text[0] = 'a';  //不可預期的錯誤
    /* gcc 沒提出任何警訊，然而 text 儲存了字串常量的位址值，字串常量建立
       的內容是唯讀的，如果試圖透過 text 改變字元，會發生不可預期的結果：

       因此對於字面常量，建議加上 const：
       */
    const char *text1 = "hello";
    /* 如此一來，試圖透過 text 改變字元，編譯器會失敗，從而避免了執行時期的錯誤。

       上述方式中，text 只是個型態為 const char* 的指標，是與以下不同的，底下建
       立的 text 內容並不是唯讀的，因為 text 是個陣列，text 是將 "hello" 複製至
       各索引處：
       */
    char text2[] = "hello";
    /* 對於 wchar_t 等其他為了支援 Unicode 的型態，都有這類特性。

       然而，無論是哪個形式，都可以傳遞位址，例如：
       */
    const char *text3 = text2;
    text3 = text1;

    char *text4 = text2;
    text4 = text1;   // error: invalid conversion from 'const char*' to 'char*'
    /* 錯誤該行如果真的想通過編譯，就必須明確告訴編譯器，你要去除 const 修飾：
       (但在ubuntu上可以編譯成功) */
    text4 = (char*)text1;
    /* 會需要這麼做的情況，可能是在使用一些舊的函式，它們在參數上宣告的是 char*，
       而不是 const char*。

       那麼，如何建立字串陣列呢？
       */
    const char* names[] = {"Justin", "Monica", "Irene"};
    int i;
    int len = sizeof(names)/sizeof(names[0]);
    for (i = 0; i < len; i++) {
        printf("%s\n", names[i]);
    }
    putchar('\n');
    /* 留意一下底下的不同： */
    char names1[][10] = {"Justin", "Monica", "Irene"};
    /* name1 的每個元素，儲存了各個字串常量的位址值；然而，name2 是有三個長度為 10
       的 char 陣列，並複製了各個字串常量的 char。
       */


    /* 可以透過 typedef 為 const char* 建立別名，令字串陣列的建立易讀、易寫一些：*/
    String names2[] = {"Justin", "Monica", "Irene"};
    len = sizeof(names2)/sizeof(names2[0]);
    for (i = 0; i < len; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
