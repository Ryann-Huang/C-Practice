#include <stdio.h>
#include <string.h>
#define LEN 80

void printArrayElement();

int main(void) {
    /* 若要進行字串的比較，可以使用 strcmp 或 strncmp：

       int strcmp( const char *lhs, const char *rhs );
       int strncmp( const char *lhs, const char *rhs, size_t count );

       strcmp(str1, str2) 會比較字串 str1 與 str2 的大小，若相同就傳回 0，
       str1 大於 str2 則傳回大於 0 的值，小於則傳回小於 0 的值，比較的標準
       是依字典順序，例如若 str1 大於 str2，表示 str1 在字典中的順序是在 str2 之後。

       strncmp 是比較兩個字串中指定長度內的字元是否相同，一個字串比較範例如下所示：
       */
    char passwd[] = "123456";
    char buf[LEN];

    printf("Please enter password: ");
    fgets(buf, sizeof(buf), stdin);
    int result = strncmp(passwd, buf, strlen(passwd));
    printf("===> strncmp result = %d\n", result);

    if (result) {
        puts("Wrong password!");
    }else {
        puts("Correct password!");
    }
    puts("");


    /* C 標準函式庫也提供了搜尋字串的相關函式，先來看到 strstr 函式：

       char *strstr( const char* str, const char* substr );

       第一個參數是被搜尋字串，第二個參數是想要搜尋的子字串，如果沒找到子字串則傳回 NULL，
       如果搜尋到第一個符合的子字串，則傳回符合位置的指標，若想要得知子字串是在哪一個索引
       位置，則可以利用該指標減去字串（字元陣列）開頭的指標，得到的位移量即為符合的索引位置
       */
    char source[LEN] = {'\0'};
    char search[LEN] = {'\0'};

    printf("Please input a string as source: ");
    fgets(source, LEN, stdin);
    printf("String length of source[] = %lu\n", strlen(source));

    printf("Please input the second string to search: ");
    fgets(search, LEN, stdin);
    printf("String length of search[] = %lu\n", strlen(search));

    // 去除最後的換行字元
    search[strlen(search) - 1] = '\0';

    printf("===> strstr()\n");
    char *loc = strstr(source, search);
    if (loc == NULL) {
        printf("Cannot find the second string in source!\n");
    }else {
        printf("Find the second string at index %lu in the source string!\n\n", loc - source);
    }


    /* 相對於 strstr 函式找出符合的子字串，strspn 函式則用來比較兩個字串，找出兩個字串中開
       始不匹配的地方：

       size_t strspn( const char *dest, const char *src );

       strspn 會傳回兩個字串開始不匹配的第一個字元索引位置，否則傳回 0
       */
    // 二個字串中的'\n'去掉再搜尋
    source[strlen(source) - 1] = '\0';
    printf("===> strspn()\n");
    size_t a = strspn(source, search);
    if (a == strlen(source)) {
        printf("Fully match!\n\n");
    }else {
        printf("from index %lu of source string, they mismatch\n\n", a);
    }


    /* strchr 函式找出字串中的指定字元第一次出現，若找到則傳回該字元的指標，否則傳回 NULL，
       可以用找到的指標位置減去字串（字元陣列）開頭位址，如此就可以得到其於字串中的索引位
       置，而 strrchr 則是與 strchr 類似，只不過它是反向搜尋(從字串後面開始找)：

       char *strchr( const char *str, int ch );
       char *strrchr( const char *str, int ch );
       */
    printf("===> strchr()\n");
    char *p = strchr(source, search[0]);
    if (p == NULL) {
        printf("Cannot find '%c' in source\n\n", search[0]);
    }else {
        printf("Find %c at source index: %lu\n\n", search[0], p - source);
    }

    printf("===> strrchr()\n");
    char *q = strrchr(source, search[0]);
    if (q == NULL) {
        printf("Cannot find %c in source\n\n", search[0]);
    }else {
        printf("Find %c at source index: %lu\n\n", search[0], q - source);
    }


    /* strcspn 函式則是找出一個字串中與另一個字串內任何字元第一次匹配的索引位置，若無則
       傳回字串長度：

       size_t strcspn( const char *dest, const char *src );
       */
    printf("===> strcspn()\n");
    size_t b = strcspn(source, search);
    printf("strcspn() result = %lu\n", b);
    if (b == strlen(source)) {
        printf("No char match!\n\n");
    }else {
        printf("Find match at index: %lu in source\n\n", b);
    }


    /* strpbrk 函式則與 strcspn 類似，只不過完全不匹配的話，則傳回 NULL：

       char* strpbrk( const char* dest, const char* breakset );
       */
    printf("===> strpbrk()\n");
    char *r = strpbrk(source, search);
    if (r == NULL) {
        printf("Cannot find any match!\n\n");
    }else {
        printf("Find match at index: %lu in source string\n\n", r - source);
    }

    return 0;
}
