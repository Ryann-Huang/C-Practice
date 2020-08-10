#include <stdio.h>
#include <stdlib.h>

int writeInts(int* arr, int len) {
    FILE *fp = fopen("temp", "wb");
    if (!fp) {
        perror("Cannot write file! (writeInts)");
        return EXIT_FAILURE;
    }

    fwrite(arr, sizeof(int) * len, 1, fp);
    fclose(fp);
}

int readInts(int* arr, int len) {
    FILE *fp = fopen("temp", "rb");
    if (!fp) {
        perror("Cannot read file! (readInts)");
        return EXIT_FAILURE;
    }

    fread(arr, sizeof(int) * len, 1, fp);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    /* 使用二進位模式開啟檔案，在寫入或讀取檔案時不會發生字元轉換，數值在記憶體中的位元是如何，
       寫入檔案時就是如何，而讀入時也是相同。

       要單純地以二進位方式讀取檔案，可以使用 fread 函式，在讀寫時是使用位元組為單位：

       size_t fread( void* buffer, size_t size, size_t count, FILE* stream );
       buffer 參數為讀入的資料所要存放的地方，size 是指讀入的位元組長度，count 是讀入的筆數。

       以二進位方式讀取時，要判斷檔案是否到尾端，可以使用 feof 函式：

       while(!feof(fp)) {
           ....
       }
       下面這個程式可以讀入任意檔案，每次讀入一個位元組，並將讀入的資料以 16 進位數顯示：
       */
    FILE *fp = fopen(argv[1], "rb");
    FILE *dest = fopen(argv[2], "wb");
    if (!fp) {
        perror("Cannot read the source file!");
        return EXIT_FAILURE;
    }

    if (!dest) {
        perror("Cannot create the destination file!");
        return EXIT_FAILURE;
    }

    unsigned char ch;
    int count = 0;
    /* feof是發生在fread使用＂讀取過檔案＂後，已讀到End－of－file位置時，回傳的指標才會是true(檔案結尾)，
       所以上面的寫法在讀完最後一筆後，指標會停留在End－of－file位置前，需要再讀一次到在End－of－file位
       置後（判斷讀取資料失敗，因為已讀到eof），才會為true，而因為fread讀取失敗，buffer的資料不會改變，
       所以才會多讀一筆

       while (!feof(fp)) {
           fread(&ch, sizeof(char), 1, fp);
           printf("%2X ", ch);
           count++;
           if (count > 16) {  // 換行
               putchar('\n');
               count = 0;
           }
       }
    */

    /* 如果要寫入檔案，可以使用 fwrite：

       size_t fwrite( const void* buffer, size_t size, size_t count, FILE* stream );
       下面這個程式可以讓你將任意的檔案複製至另一個指定的名稱：
       */

    while (1) {
        fread(&ch, sizeof(char), 1, fp);
        if (feof(fp)) {
            break;
        } else {
            fwrite(&ch, sizeof(char), 1, dest);
        }

        printf("%2X ", ch);
        count++;
        if (count > 16) {
            putchar('\n');
            count = 0;
        }
    }

    putchar('\n');
    fclose(fp);
    fclose(dest);

    /* 下面這個程式示範如何將陣列資料寫入檔案，然後再將之讀出：*/
    fp = fopen("temp", "wb");
    if (!fp) {
        perror("Cannot read temp file!");
        return EXIT_FAILURE;
    }

    const int len = 5;
    int arr[] = {1, 2, 3, 4, 5};

    writeInts(arr, len);
    readInts(arr, len);

    int i;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}
