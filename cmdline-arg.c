#include <stdio.h>

int main(int argc, char *argv[]) {
    /* 參數 argc 是一個整數，記錄命令列引數的個數，這個數目包括了程式名稱，
       例如下面的執行指令，argc 將記錄為 5：

       prog hello.c -o  -c project.p
       每個引數之間以空白作區隔，上面的命令包括程式名稱共會有五個引數，即
       "prog"、"hello.c"、"-o"、"-c"、"project.p"。

       程式在執行後，argc 的值一定大於 1，因為至少包括了程式名稱，而 argv
       分別儲存了引數的字串，例如上面的例子中，argv[0] 是 "prog"、
       argv[1] 是 "hello.c"、argv[2] 是 "-o"、argv[3] 是 "-c"、
       argv[4] 是 "project.p"。

       在命令列引數的使用中，若輸入是一個包括空白的字串，就使用 "" 來包括，
       例如：

       prog "This is a string!"
       如此 argv[0] 是程式名稱 "prog"，而 argv[1] 的字串就會是
       "This is a string!"。
       */
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
