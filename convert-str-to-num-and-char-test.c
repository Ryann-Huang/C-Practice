#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(void) {
    /* atof、atoi、atol、atoll 等函式 會搜尋字串中可以轉換的部份，直到遇到無法轉換的字元，
       字串開頭可以使用正負號，例如 "+100" 或 "-100"，atof 可以接受科學記號，例如 "12.3e-5"
       或 "123E+4"，這幾個函式若沒有可轉換的字元則傳回 0，
       <<< 若是轉換結果超出了傳回型態的範圍，傳回值沒有定義，也就是難以檢查錯誤。>>>

       C99 有一系列轉換字串的函式，使用起來比較麻煩一些：

       long               strtol( const char *restrict str, char **restrict str_end, int base );
       long long          strtoll( const char *restrict str, char **restrict str_end, int base );

       unsigned long      strtoul( const char *restrict str, char **restrict str_end,int base );
       unsigned long long strtoull( const char *restrict str, char **restrict str_end, int base );

       float              strtof( const char *restrict str, char **restrict str_end );
       double             strtod( const char *restrict str, char **restrict str_end );
       long double        strtold( const char *restrict str, char **restrict str_end );

       這幾個函式的第一個參數都接受來源字串；第二個參數在函式執行過後，會用來儲存字串中第一個
       無法剖析為數字的字元位址，如果設定為 NULL，會忽略這個參數；第三個參數用來指定基底，如果
       設定為 0，從字串中自動偵測基底；函式若沒有可轉換的字串，會傳回 0。
       */
    printf("\"1010\"\t二進位：\t%ld\n", strtol("1010", NULL, 2));
    printf("\"12\"\t八進位：\t%ld\n", strtol("12", NULL, 8));
    printf("\"A\"\t十六進位：\t%ld\n", strtol("A", NULL, 16));
    printf("\"012\"\t自動基底：\t%ld\n", strtol("012", NULL, 0));
    printf("\"0xA\"\t自動基底：\t%ld\n", strtol("0xA", NULL, 0));
    printf("\"junk\"\t自動基底：\t%ld\n\n", strtol("junk", NULL, 0));


    long i = strtol("999999999999999999999999999999999999999999999999999999999999", NULL, 10);

    if (errno == ERANGE) {
        printf("Exceed the range of convert function!\n\n");
        errno = 0;
    }else {
        printf("%ld\n\n", i);
    }


    const char *p = "10,200,3000,-400000";
    char *end;
    long j;
    for (j = strtol(p, &end, 10); p != end; j = strtol(p, &end, 10)) {
        printf("\"%.*s\"：", (int)(end - p), p);
        p = end + 1;  // 新的字串起點
        if (errno == ERANGE){
            printf("轉換超出範圍");
            errno = 0;
        }

        printf("%ld\n", j);
    }
    puts("");


    /* 若要測試字元為數字、字母、大寫、小寫等等，可以使用 ctype.h 中的 isxxxx() 函式 */
    printf("a is alpha:\t%c\n", isalnum('a') ? 'Y' : 'N');
    printf("3 is number:\t%c\n", isalnum('3') ? 'Y' : 'N');
    printf("b is alpha:\t%c\n", isalpha('b') ? 'Y' : 'N');
    printf("\\n is control character:\t%c\n", iscntrl('\n') ? 'Y' : 'N');
    printf("4 is digit:\t%c\n", isdigit('4') ? 'Y' : 'N');
    printf("b is lower case:\t%c\n", islower('b') ? 'Y' : 'N');
    printf("c is printable:\t%c\n", isprint('c') ? 'Y' : 'N');
    printf(", is punctuation:\t%c\n", ispunct(',') ? 'Y' : 'N');
    printf("' ' is space:\t%c\n", isspace(' ') ? 'Y' : 'N');
    printf("D is upper case:\t%c\n", isupper('D') ? 'Y' : 'N');
    printf("A is hexadecimal:\t%c\n\n", isxdigit('A') ? 'Y' : 'N');

    return 0;
}
