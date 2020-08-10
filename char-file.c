#include <stdio.h>
#include <stdlib.h>

/* 檔案的輸出入定義在 stdio.h 標頭檔，若要開啟檔案，可以使用 fopen，其函式原型宣告如下：

    FILE* fopen( const char* filename, const char* mode )
    FILE 是個結構型態：

    typedef struct _iobuf {
        char*    _ptr;
        int    _cnt;
        char*    _base;
        int    _flag;
        int    _file;
        int    _charbuf;
        int    _bufsiz;
        char*    _tmpfname;
    } FILE;
   fopen 傳回 FILE 實例的位址，若將 FILE 的位址傳給 fgetc、fputc、fgets、fputs 等函式，
   字元串流只是在讀取或寫入的過程，會進行文字編碼的轉換，例如 int 數字 9，在寫入的操作中，
   會轉換為編碼 57 的位元組資料，至於本身是 char 的資料，就直接以對應的位元組寫出，也就是
   所謂的純文字檔案讀寫。

   fopen 第一個參數用來指定檔案名稱，第二個參數用來指定輸出入模式，模式基本上就是讀、寫、
   擴充等，分別可使用 r、w 與 a 等設定，若加上 +， 表示擴充檔案讀寫能力。例如，以下是可設定的模式：

    r：唯讀模式開啟檔案，若檔案不存在，傳回 NULL。
    w：唯寫模式建立檔案，若檔案不存在，建立新檔，若檔案存在，就刪除其內容。
    a：附加模式開啟檔案，若檔案不存在，建立新檔，若檔案存在，從檔案尾端寫入。
    r+：開啟檔案進行讀寫，若檔案不存在，傳回 NULL，若檔案存在，從檔案開頭進行讀寫。
    w+：建立檔案進行讀寫，若檔案不存在，建立新檔，若檔案存在，就刪除其內容。
    a+：開啟檔案進行讀寫，若檔案不存在，建立新檔，若檔案存在，從檔案尾端寫入。
    可以選擇性地加上 b 表示以二進位模式，在 POSIX 系統上會忽略，Windows 會不處理 \n 與 \x1A。

   例如，以下可開啟一個檔案進行讀取：

    FILE *fp = fopen("test.txt", "r");
   可以使用以下片段來測試檔案是否開啟成功：

    if(!fp) {
        perror("檔案開啟失敗"); // 將訊息輸出至 stderr
        return EXIT_FAILURE;
    }
   開啟檔案之後，可以使用 fgetc 來讀取檔案中的字元，使用 fputc 來將字元寫入檔案，以讀取為例：

    int c;
    while ((c = fgetc(fp)) != EOF) {
       putchar(c);
    }
    ferror 可以檢查檔案讀寫是否有誤，feof 可檢查讀取到檔尾：

    if (ferror(fp)) {
        puts("讀取時發生錯誤");
    }
    else if (feof(fp)) {
        puts("讀取成功");
    }
    fopen 會使用緩衝區減少對磁碟的讀寫，不使用檔案時，記得關閉檔案，關閉檔案會將緩衝區中的資料寫入磁碟，若忘了關閉檔案，可能會造成資料遺失，可以使用 fclose 來關閉檔案：

    fclose(fp);
    下面這個程式示範如何讀取來源檔案並將內容寫為另一檔案：
    */

/* 1. console mode to compile *.c
       gcc [programName].c -o programName
   2. Run the program
       ./programName
   */

int main(int argc, char* argv[]) {
    FILE* src = fopen(argv[1], "r");
    if (!src) {
        perror("Cannot open the source file!");
        return EXIT_FAILURE;
    }

    FILE* dest = fopen(argv[2], "w");
    if (!dest) {
        perror("Cannot create the destination file!");
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }

    if (ferror(src) || ferror(dest)) {
        puts("Read/Write file error!");
    }

    fclose(src);
    fclose(dest);

    /* 也可以使用 fgets 來讀取整個字串，使用 fputs 來寫入整個字串：
       fgets 第一個參數為用來儲存讀入的資料，第二個參數為讀入的字元長度，第三個參數為 FILE
       位址值，而 fputs 第一個參數為寫入的資料，第二個參數為 FILE 位址值。

       以下的程式使用 fgets、fputs 改寫以上範例：
       */
    src = fopen(argv[3], "r");
    if (!src) {
        /* 在程式執行過程開啟的標準輸出 stdout、標準輸入 stdin、標準錯誤 stderr，事實上也是
           檔案的特例，在 C 程式中，也常見到以下的方式，以便直接控制這三個標準輸入、輸出、錯誤：
           */
        fputs("Cannot open the source file!(fgets-fputs)\n", stderr);
        return EXIT_FAILURE;
    }

    dest = fopen(argv[4], "w");
    if (!dest) {
        fputs("Cannot create the destination file!(fgets-fputs)\n", stderr);
        return EXIT_FAILURE;
    }

    char buf[8];
    while ((fgets(buf, sizeof(buf), src)) != NULL) {
        fputs(buf, dest);
    }

    if (ferror(src) || ferror(dest)) {
        fputs("Read/Write file error!\n", stderr);
    }

    fclose(src);
    fclose(dest);



    return 0;
}
