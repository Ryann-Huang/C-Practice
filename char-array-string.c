#include <stdio.h>
#include <string.h>
#include <uchar.h>

int main(void) {
    char text[] = "Hello";
    int length = sizeof(text) / sizeof(text[0]);

    int i;
    for (i = 0; i < length; i++) {
        if (text[i] != '\0') {
            printf("%c ", text[i]);
        } else {
            puts("null");
        }
    }

    printf("text[] length = %d\n", length);
    printf("string length = %d\n\n", strlen(text));


    /* 這個程式片段可以取得使用者的字串輸入，輸入的字串長度不得超過 80 個字元，
    80 個字元的上限包括空字元，因此實際上可以輸入 79 個字元；如果輸入的字元超出
    所宣告的上限，會發生不可預期的結果，甚至成為安全弱點，如〈printf 與 scanf〉
    中最後談到的，預防的方法之一是，限定 scanf 每次執行可以接受的最大字元數，或者是使用 fgets。
    fgets(buf, sizeof(buf), stdin);
    */
    char buf[80];
    printf("Type a string:");
    /* 在使用 scanf 取得使用者輸入的字串時，格式指定字是使用 %s，而變數前不用再加上 &，
       因為實際上，字串（字元陣列）變數名稱本身，即表示記憶體位址資訊。
       */
    scanf("%s", buf);
    printf("The string you type: %s\n\n", buf);


    /* warning: multi-character character constant
       warning: overflow in conversion from 'int' to 'char' changes value from '43596' to '76'

       char t = '林';
       */
    char t[] = "林";
    /* char 用來儲存字元資料，但沒有規定什麼是字元資料，若單純使用 gcc 編譯，不加上任
    何引數的話，原始碼中字串怎麼儲存，執行時期 text 就怎麼儲存，當原始碼是 Big5 時，
    因為 "林" 會用上兩個位元組，strlen(text) 會是 2，當原始碼是 UTF-8 時，"林" 會用上
    三個位元組，因此 strlen(text) 會是是 3
    */
    printf("林 default string length = %d\n", strlen(t));


    /* 這就要問到一個問題了，字元是什麼呢？C 的 char 又是什麼呢？C 是個歷史悠久的語言，
    早期用 char 儲存的文字僅需單一位元組，例如 ASCII 的文字，使用 char 代表字元是沒問題，
    因為 ASCII 既定義了字元集，也定義了字元編碼，在表示 ASCII 的文字時，char 確實就代表字
    元，然而後來為了支援更多的文字，char 就不再是代表字元了。

    char 是用來儲存字元資料，至於存什麼沒有規定，對於 char text[] = "林" 的情況，應該將
    text 中每個索引位置當成是碼元（code unit），而不是字元了，因為必須以多個位元組來儲存「林」，
    因此這類字元在 C 被稱為多位元組字元（multibyte character），技術上來說，是用數個 char
    組成的一個字元，如何組成就要看採用哪種編碼了。

    如果採用 Big5 編碼，那 "林" 是個 Big5 字元，如果採用 UTF-8 編碼，那 "林" 是個 Unicode 字元，
    現代程式設計鼓勵用 UTF-8，若要固定使用 UTF-8 編碼字串，C11 可以 UTF-8 撰寫原始碼，並在 ""
    前置 u8，指定字串使用 UTF-8 編碼
    */

    char tt[] = u8"林";
    printf("林 string length with UTF-8 encoding = %d\n", strlen(tt));
    char ttt[] = u8"\u6797";
    printf("林 string length with code unit = %d\n", strlen(ttt));


    /* 如果處理中文字串時，想知道有幾個中文字怎麼辦？這要知道 wchar_t 型態，對應的字元常量是
     L'林' 這樣的寫法稱為擴充字元字面常量（wide character literal），wchar_t 其實是個整數型
     態，用來儲存碼點，就現今來說，基本上是指 Unicode。
     */
    wchar_t ch = L'林'; // 也可以寫L'\u6797'
    printf("wchar_t stores code unit of 林: %d\n\n", ch);


    /*  這種寫法，稱為擴充字元字串（wide-chararater string），C 的字串處理函式，都有對應 wchar_t
    的版本，只要將函式名稱的 str 前置改為 wcs 前置就可以了，wcs 就是 wide-chararater string 的縮寫。
    */
    wchar_t name[] = L"陳小明";
    printf("陳小明 字串長度：%d\n\n", wcslen(name));


    /* wchar_t 並沒有規定大小，只要求必須容納系統中可以使用的字元，C11 在 uchar.h 中定義了
    char16_t 與 char32_t，這會讓人誤以為它們用來儲存編碼，其實它們依舊是儲存碼點。

    char16_t 可儲存的碼點，必須能涵蓋 UTF-16 編碼可表現的全部字元，使用的字元常量或字串常量前
    要加上 u，例如：
    */
    char16_t ch1 = u'林';
    char16_t text1[] = u"陳小明";

    /* char32_t 可儲存的碼點，必須能涵蓋 UTF-32 編碼可表現的全部字元，使用的字元常量或字串常
    量前要加上 U，例如：
    */
    char32_t ch2 = U'林';
    char32_t text2[] = U"陳小明";

    return 0;
}
