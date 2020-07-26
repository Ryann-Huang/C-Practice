#include <stdio.h>
#include <string.h>
#define LEN 80

void clearBuf();
void printArrayElement(char *array);

int main(void) {
    char text[80];
    printf("Please input a string:");
    scanf("%s", text);

    size_t length = strlen(text);
    printf("Length of the string you type is = %d\n\n", length);
    clearBuf();

    /* 如果使用 fgets 的話，要注意它會包括最後按下 Enter 的換行字元 */
    puts("Please input another string:");
    fgets(text, sizeof(text), stdin);

    printf("sizeof(text) = %d\n", sizeof(text));
    length = strlen(text);
    printf("Another string length is = %d\n\n", length);
    printArrayElement(text);
/*    int i;
    for (i = 0; i < length; i++) {
        if (text[i] == '\n') {
            printf("\\n\n\n");
        }else if (text[i] == '\r') {
            printf("\\r\n\n");
        } else {
            printf("%c\n", text[i]);
        }
    }*/
    //clearBuf();
    //getchar();


    /* 如果要進行字串複製，可以使用 strcpy 函式，若要複製字串中若干字元內容，可以使用
       strncpy：
       char *strcpy( char *restrict dest, const char *restrict src );
       char *strncpy( char *restrict dest, const char *restrict src, size_t count );
       restrict 是 C99 制定，只能用於修飾指標的關鍵字，之後會談到，就這邊來說，表示你
       得保證 dest 與 src 是不同來源的引數。
       */
    char buf[LEN] = {'\0'};

    puts("Please input a name:");
    fgets(buf, sizeof(buf), stdin);

    // fgets 會包括按下enter的換行字元
    int lenOfName1 = strlen(buf);
    printf("lenOfName1 = %d\n", lenOfName1);
    char name1[lenOfName1 + 1];
    memset(name1, '\0', lenOfName1 + 1);
    strcpy(name1, buf);
    printf("name1 is %s\n", name1);
    printf("strlen(name1) = %d\n", strlen(name1));
    printArrayElement(name1);

    //不複製換行字元
    int lenOfName2 = lenOfName1 - 1;
    printf("lenOfName2 = %d\n", lenOfName2);
    char name2[lenOfName2 + 1];
    memset(name2, '\0', lenOfName2 + 1);
    strncpy(name2, buf, lenOfName2);
    printf("name2 is %s\n", name2);
    printf("strlen(name2) = %d\n", strlen(name2));
    printArrayElement(name2);
    puts("");


    /* 若要串接兩個字串，則要使用 strcat，若要串接部份字串，可以使用 strncat：
       char *strcat( char *restrict dest, const char *restrict src );
       char *strncat( char *restrict dest, const char *restrict src, size_t count );
       第二個參數的字串會串接到第一個參數之後，因此第一個參數必須保留足夠的空間作為串接時使用
       */
    char str1[] = "xyz";
    char str2[] = "abc";

    int len = strlen(str1) + strlen(str2) + 1;
    char concated[len];
    memset(concated, '\0', len);

    strcat(concated, str1);
    strcat(concated, str2);
    printf("The concatenated string is = %s\n\n", concated);

    return 0;
}

void clearBuf() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

void printArrayElement(char* array) {
    int i;
    size_t length = strlen(array);

    for (i = 0; i < length; i++) {
        if (array[i] == '\n') {
            printf("\\n\n\n");
        }else if (array[i] == '\r') {
            printf("\\r\n\n");
        } else {
            printf("%c\n", array[i]);
        }
    }
}
