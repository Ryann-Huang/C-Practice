#include <stdio.h>

void clearBuf();

int main(void) {
    char c;

    printf("請輸入一個字元：");
    // 只讀取一個字元，若輸入多個會把剩下的留在緩衝區內。要繼續使用getchar()或scanf()把後續的資料讀出，或是清除緩衝區
    c = getchar();
    putchar(c);
    putchar('\n');

    clearBuf();

    printf("請輸入多個字元：");
    while ((c = getchar()) != EOF) {
        if (c == '\r' || c == '\n') {
            break;
        }

        printf("%c\n", c);

    }


    char str[20];
    puts("請輸入字串(gets()請取)：");
    // ‘gets’ is deprecated (declared at /usr/include/stdio.h:638) [-Wdeprecated-declarations]|
    gets(str);

    puts("輸入的字串為：");
    puts(str);


    // length = 20, 其實只能存19個char，因為最後一個要存'\n'
    char buf[20];
    puts("請輸入字串(fgets()請取)：");
    fgets(buf, sizeof(buf), stdin);

    puts("輸入的字串為：");
    puts(buf);


    return 0;
}

void clearBuf() {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}
