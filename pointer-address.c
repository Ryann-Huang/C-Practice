#include <stdio.h>

int main(void) {
    int n = 10;

    printf("value of n: %d\n", n);
    // 如果想知道變數的記憶體位址，可以使用 & 取址運算子（Address-of operator）
    printf("address of n: %p\n\n", &n);
    /* n 的值：10
       n 的位址：0x0061FECC

       這個程式中，宣告了一個 int 整數變數 n，n 儲存的記憶體位址是 0061FECC，這是 16 進位表
       示法，如果 int 長度是 4 個位元組，從 0061FECC 後的 4 個位元組是 n 配置到的記憶體空間，
       現在這個空間中儲存值為 10。
       直接存取變數會對分配到的空間作存取，指標（Pointer）是一種變數，儲存記憶體位址，要宣告
       指標，是使用以下的語法：

       type *ptr;

       */

    int *p = &n;
    printf("value of n: %d\n", n);
    printf("address stored in p: %p\n", p);
    // 可以使用提取 （Dereference）運算子 * 來提取指標儲存的位址中之資料
    printf("取出 P 儲存位址處之值: %d\n\n", *p);

    // 如果已經取得了記憶體位址，將某值指定給 *P 時，該記憶體位址的值也會改變，這相當於告訴程式，
    // 將值放到 P 儲存的位址處
    *p = 20;
    printf("value of n: %d\n", n);
    printf("*p = %d\n", *p);


    /* 如果宣告指標但不指定初值，則指標儲存的位址是未知的，存取未知位址的記憶體內容是危險的，例如：

       int *p;
       *p = 10;

       這個程式片段並未初始指標就指定值給 *p，會造成不可預知的結果，最好為指標設定初值，如果指標一
       開始不儲存任何位址，可設定初值為 0，例如：

       int *p = 0;

       在指標宣告時，可以靠在名稱旁邊，也可以靠在關鍵字旁邊，或者是置中，例如：

       int *p1;
       int* p2;
       int * p3;

       這三個宣告方式都是可允許的，C 開發者比較傾向用第一個，因為可以避免以下的錯誤：

       int* p1, p2;

       這樣的宣告方式，初學者可能以為 p2 也是指標，但事實上並不是，以下的宣告 p1 與 p2 才都是指標：

       int *p1, *p2;

       有時候，只希望儲存記憶體的位址，可以使用 void* 來宣告指標，例如：

       void *p;

       void* 型態的指標沒有任何型態資訊，只用來儲存位址，不可以使用 * 運算子對 void* 型態指標提取
       值，而必須轉型至對應的型態，例如：
       */
    void *q = &n;

    // 下面這句不可行，void 型態指標不可取值
    // printf("%d\n", *p);

    int *iptr = (int*) q;
    printf("*iptr = %d\n\n", *iptr);



    /* 順便來看一下 const 宣告的變數，被 const 宣告的變數一但被指定值，就不能再改變變數的值，
       雖然可以強制如下改變變數值的：
       */
    const int o = 10;
    int *r = &o; // warning: initialization discards ‘const’ qualifier from pointer target type
    *r = 20;
    printf("value of o: %d\n", o);
    /* 然而，gcc 會產生警訊，執行程式會顯示 20，如果不想該位址的值被改變，可以用 const 宣告指標，
       例如：
       */
    const int *s = &o;
    // *s = 30; // error: assignment of read-only location ‘*s’

    /* 必須留意的是，上面的 s 並不是唯讀，若想要有唯讀的指標，必須使用指標常數，也就是一旦指定給指
       標值，就不能指定新的記憶體位址值給它，例如：
       */
    int x = 10;
    int y = 20;
    int* const t = &x;
    // t = &y; // error: assignment of read-only variable ‘t’

    /* 因此，若 x、y 被 const 宣告，對應的指標常數宣告會是如下： */
    const int e = 10;
    const int f = 10;
    const int* const u = &e;
    // u = &f; // error: assignment of read-only variable ‘u’


    return 0;
}
