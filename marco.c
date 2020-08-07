#include <stdio.h>

/* 前置處理器語言，顧名思義，並不是 C 語言的一部份，而是編譯過程中前置處理部份處理的簡單語言，
   以最簡單的 Hello, World 程式為例：
   */

/* #include 是前置處理器的原始碼含括指令，表示將含括的檔案插入目前原始碼之中，使用 gcc 的話，
   可以指定 -E 表示只進行前置處理，例如：

   gcc -E main.c -o main.i
   開啟 main.i 的話，你會發現在 main 函式定義之前，安插了 stdio.h 的內容。也可以用來debug!!!!!
   */

/* 至目前為止，常使用到的另一個前置處理器指令是 #define，它本質上是個字串取代（或說為擴展、
   展開），例如：

   #define LEN 10
   int arr[LEN];
   被定義的內容稱為巨集（Macro），gcc 編譯時指定 -E，會產生以下內容，LEN 被展開為 10：

   # 1 "test.c"
   # 1 "<built-in>"
   # 1 "<command-line>"
   # 1 "test.c"

   int arr[10];
   */

/* #define 常用來定義一個模版，以取代經常撰寫的程式片段，例如最常見的教學範例是交換兩變數：
   */
#define swap(a, b) { \
    int temp = a;    \
    a = b;           \
    b = temp;        \
}
/* #define 的內容跨越多行時，每行結尾必須使用 \，可以在 swap(x, y) 之後加上分號，這會令其看
   來像是函式呼叫，實際上是展開了 swap 的內容後加上分號，也會是合法的程式碼罷了類似地，swap
   的定義看來像是定義函式，實際上那對大括號只是定義了陳述句區塊，而不是函式區塊。

   如果上例定義巨集時不加上大括號會如何呢？

   就以上來說，結果是正確的，只不過 main 範疇中多了個 temp 變數，也就是說，如果同一範疇內也
   有 temp 變數，編譯就會失敗，另一個問題是以下也會編譯失敗：

   if(x > y)
      swap(x, y)

   因為 if 的部份展開後會是：

   if(x > y)
      int temp = x;
      x = y;
      y = temp;
   也就是 temp 只有 if 中可見，y = temp 該行也就編譯失敗了：

   if(x > y)
      int temp = x;
   x = y;
   y = temp;
   如果是一開始有加上大括號的 swap 巨集就不會有問題：

   if(x > y) {
      int temp = x;
      x = y;
      y = temp;
   }
   */

/* #define 只是文字替代，因此要小心項目展開後計算先後順序的問題：

   #define pow(a) a * a

   pow 目的是計算二次方，pow(x + x) 預期結果應該是 400，實際上顯示會是 120，因為展開後會是
   x + x * x + x，為了避免這個問題，可以在定義巨集時，將輸入項目加上括號：
   ( x + x * x + x : 用gcc -E main.c -o main.i 看到的 ）
   */
#define pow(a) (a) * (a)
/* #define 的輸入項目要避免副作用，例如：

   printf("%d\n", pow(x++));

   你覺得結果應該會是多少呢？若覺得是 100 就錯了，因為 pow(x++) 會被展開為 (x++) * (x++)，
   結果會是 110；別在巨集中重複使用輸入項目，雖然可以解決問題，然而這有時無法做到，因此最重
   要的是記得，使用巨集時，輸入項目要避免副作用，上例應該寫為以下：

   printf("%d\n", pow(x));
   x++;

   這就是為何有些開發者認為，應該避免使用巨集的原因，因為撰寫不易、除錯不易，然而使用上又容
   易出錯；然而有些功能又只有巨集辦得到，C 語言本身的標準實際上也包含了一些以巨集提供的功能，
   只能說巨集是把雙面刃、必要之惡了。

   #define 用來定義巨集，相對地，#undef 用來取消巨集。
   */

/* 將 fprintf 定義為巨集是個不錯的主意，可以簡化程式的撰寫：*/
#define debug(fmt, ...) { \
    fprintf(stderr, "(%s:%d) "fmt"\n", __FILE__, __LINE__, ##__VA_ARGS__); \
}
/* ... 在巨集中表示其餘的項目，後續可以使用 __VA_ARGS__ 來代表；# 會將項目加上雙引號含括，
   因此 #__VA_ARGS__ 的話，表示將其餘項目展開為字串。

   ## 的話是合併項目，例如若項目是 a 與 b，巨集中撰寫 ab 是不會分別展開的，因為項目必須使用
   空白區隔，這時可以撰寫 a##b，這麼一來，a 與 b 會分別展開後合併，例如若 a 為 12、b 為 34，
   那麼 a##b 就會是 1234。

   如果 ## 出現在逗號之後，有些編譯器（例如 gcc）會在 __VAR_ARGS__ 為空時，自動移除逗號，上
   面的範例若將 ## 拿掉，debug 時若沒有指定 fmt 外的引數，展開後編譯就會出錯。

   那為什麼不把 debug 定義為函式就好，而是要定義為巨集？同樣的疑問應該也會發生在先前的 swap、
   pow 巨集，畢竟它們也可以定義為函式！

   在過去也許有個好理由將 swap、pow 等定義為巨集：「不會產生函式呼叫，比較有效率」。不過在不
   用這麼斤斤計較的場合，將 swap、pow 等定義為巨集的價值不大。

   巨集的本質是文字替換，如果經常寫出某個 C 語言片段，而該片段不適合封裝為函式，或者封裝為函
   式時使用上突冗，才是適用巨集的場合，例如方才的 debug 定義為函式會比較麻煩，因為得使用到不
   定長度引數、字串串接等，相對來說，定義巨集反而容易得多，另一個情況是循序迭代陣列，這可以參s
   考〈foreach 與陣列〉。
   */

#define __DEBUG__

/* 在〈Conditional inclusion〉有個範例，可以看到 defined 以及條件式中還可以進行簡單的運算：*/
#define ABCD 2

int main(void) {
    printf("Hello! World!\n");
    printf("哈囉！C 語言！\n\n");


    int x = 10;
    int y = 20;

    printf("x = %d, y = %d\n", x, y);
    swap(x, y)

    printf("x = %d, y = %d\n", x, y);
    putchar('\n');

    printf("pow(x) = %d\n", pow(x));
    printf("pow(%d + %d) = %d\n", x, x, pow(x + x));

    /* C 語言本身預先定義了 __STDC__、__LINE__ 等名稱，可以在〈Replacing text macros〉
       https://en.cppreference.com/w/c/preprocessor/replace 找到，例如，可以透過
        __FILE__、__LINE__ 來寫個簡單的除錯資訊：
       */
    fprintf(stderr, "(%s:%d) %s %d\n", __FILE__, __LINE__, "Shit happen!", 1);

    debug("%s %d", "Shit happen!!!", 1);

    /* 前置處理指令中，還有 #if、#endif、#ifdef、#ifndef、#elif、#else、#endif，可用來判定
       巨集是否存在，根據條件進行不同的程式碼含括。例如：
       */
    #ifdef __DEBUG__
        debug("%s %d", "Shit happen.", 1);
    #endif // __DEBUG__
    /* 只要在 __DEBUG__ 有定義的情況下，debug("%s %d", "Shit happen!", 1) 該行才會被納入原
       始碼，而後進行編譯的動作，如此一來，就可以透過 __DEBUG__ 是否有定義，來決定要不要包含
       除錯資訊。
       */
    putchar('\n');

    #ifdef ABCD
        printf("1: yes\n");
    #else
        printf("1: no\n");
    #endif // ABCD

    #ifndef ABCD
        printf("2: no1\n");
    #elif ABCD == 2
        printf("2: yes\n");
    #else
        printf("2: no2\n");
    #endif // ABCD

    #if !defined(DCBA) && (ABCD < 2*4-3)
        printf("3: yes\n");
    #endif



    return 0;
}
