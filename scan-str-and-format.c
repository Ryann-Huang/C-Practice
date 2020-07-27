#include <stdio.h>
#define LEN 80

int main(void) {
    /* 在〈printf 與 scanf〉談過 scanf 的用法，它是針對標準輸入的掃描方案，如果來
       源是個字串，可以使用 sscanf：

       int sscanf( const char *restrict buffer, const char *restrict format, ... );
       */
    int i, j, k;
    float x, y;
    char str1[10], str2[4];

    sscanf("25 54.32E-1 Thompson 56789 123 56",
           "%d %f %9s %2d %f %d %3[0-9]",
           &i, &x, str1, &j, &y, &k, str2);

    printf("%d %f %s %d %f %d %s\n\n", i, x, str1, j, y, k, str2);


    /* printf 是針對標準輸出的格式化方案，如果想格式化字串，可以使用 sprintf：

       int sprintf( char *restrict buffer, const char *restrict format, ... );
       */
    printf("===> sprintf()\n");
    char buf[80];
    sprintf(buf,
            "%d %f %s %d %d %d %s",
            25, 54.32E-1, "Thompson", 56, 789, 123, "56");

    printf("%s\n\n", buf);


    /* sprintf 的問題在於，格式化寫入的字串長度，不能超過 buf 的容量，若超過的話會有
       緩衝區溢位的問題，你可以使用 snprintf，限制最大的字串長度：

       int snprintf( char *restrict buffer, size_t bufsz, const char *restrict format, ... );

       函式執行過後，會傳回格式化後的字串長度
       */
    printf("===> snprintf()\n");
    memset(buf, '\0', LEN);
    snprintf(buf, LEN, "%d %f %s %d %d %d %s",
                        25, 54.32E-1, "Thompson", 56, 789, 123, "56");

    printf("%s\n\n", buf);


    /* 呼叫 snprintf 時，第一個參數若指定 NULL，第二個參數指定 0 的話，可以用來決定緩
       衝區的大小
       */
    printf("===> use snprintf to get the length of formatted string first\n");
    int n = snprintf(NULL, 0, "%d %f %s %d %d %d %s",
                               25, 54.32E-1, "Thompson", 56, 789, 123, "56");
    char str[n + 1];  // for '\0'
    snprintf(str, sizeof(str), "%d %f %s %d %d %d %s",
                                25, 54.32E-1, "Thompson", 56, 789, 123, "56");

    printf("%s\n\n", str);


    char str3[] = "xyz";
    char str4[] = "abc";

    n = snprintf(NULL, 0, "%s%s", str3, str4);
    char buf1[n + 1];
    snprintf(buf1, sizeof(buf1), "%s%s", str3, str4);
    printf("%s\n\n", buf1);

    return 0;
}
