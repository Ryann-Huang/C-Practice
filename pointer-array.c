#include <stdio.h>
#include <stdint.h>
#define ROWS 2
#define LEN 10
#define MAZE_LEN 3

typedef int(*Row)[MAZE_LEN];

int main(void) {
    int arr[10] = {0};

    printf("arr :\t\t%p\n", arr);
    printf("&arr[0] :\t%p\n\n", &arr[0]);


    int arr1[LEN];
    int *p = arr;
    int i;
    for (i = 0; i < LEN; i++) {
        printf("arr[%d]: %p\t\t", i, &arr[i]);
        printf("p + %d: %p\n", i, p + i);
    }
    putchar('\n');


    int nums[5] = {10, 20, 30, 40, 50};
    int *ptr = nums;
    for (i = 0; i < 5; i++) {
        printf("*(ptr + %d): %d\n", i, *(ptr + i));
    }
    putchar('\n');
    for (i = 0; i < 5; i++) {
        printf("*(nums + %d): %d\n", i, *(nums + i));
    }

    int len = *(&nums + 1) - nums;
    printf("nums len = %d\n", len);
    putchar('\n');

    /* 在〈陣列〉中談過，可以使用 sizeof 來計算陣列長度，在認識指標及其運算後，透過以下也
       可以計算出陣列長度：

       int arr[] = {10, 20, 30, 40, 50};
       int len = *(&arr + 1) - arr;

       來解釋一下為什麼這行得通，如果使用 &arr 會取得 arr 變數的位址值，也就是陣列資料儲存
       的位址，與首元素位址是相同的值：
       */
    printf("nums:\t%p\n", nums);
    printf("&nums:\t%p\n\n", &nums);

    /* 每個陣列元素的位址型態是 int*，這表示對它進行運算時，是以 int 長度為單位，而 arr 變
       數的位址處就是陣列資料的開端，&arr 型態會是…呃…int (*)[5]，5 是陣列長度，如果想宣告
       相對應的變數，可以如下：

       int (*p)[5] = &arr;

       int (*)[5] 表示，對它進行運算時，是以 5 個 int 長度為單位，因此 &arr + 1 的結果，會
       是陣列使用的空間後之位址，而 *(&arr + 1) 的值型態會回到 int*，也就是最後一個元素後之
       位址，這時就可以與 int* 的 arr 進行相減，也就是與第一個元素之位址相減，就可以得到陣列
       長度了。

       舉這個例子的重點之一是，對於同一個位址，指標的型態決定了該怎麼看得相對應相加、相減計算；
       另一個重點是，透過陣列變數會取得首元素的位址，將陣列變數指定給指標 p，就只是取得首元素
       位址並儲存在 p，如果將 p 傳給 sizeof，那使用的會是指標 p 的型態，而不是原陣列的型態，這
       會令 sizeof、以及方才那神奇計算長度的方式失效
       */
    printf("ptr:\t%p\n", ptr);
    printf("&ptr:\t%p\n", &ptr);
    putchar('\n');


    uint32_t a = 5;
    int32_t b = 5;
    int c = 5;
    printf("sizeof(a) = %lu\n", sizeof(a));
    printf("sizeof(b) = %lu\n", sizeof(b));
    printf("sizeof(c) = %lu\n", sizeof(c));
    putchar('\n');


    uint32_t numbers[] = {10, 20, 30, 40, 50};
    uint32_t *ptr1 = numbers;

    printf("sizeof(numbers)/sizeof(numbers[0]) = %lu\n", sizeof(numbers)/sizeof(numbers[0]));
    printf("sizeof(ptr1) = %lu\n", sizeof(ptr1));
    printf("sizeof(*ptr1) = %lu\n", sizeof(*ptr1));
    printf("sizeof(ptr1)/sizeof(*ptr1) = %lu\n", sizeof(ptr1)/sizeof(*ptr1));
    printf("*(&ptr1 + 1 = %p\n", *(&ptr1 + 1));
    printf("ptr1 = %p\n", ptr1);
    printf("*(&ptr1 + 1) - ptr1 = %ld\n\n", *(&ptr1 + 1) - ptr1);


    int numbers1[] = {10, 20, 30, 40, 50};
    int *begin = numbers1;
    int *end = *(&numbers1 + 1);
    printf("numbers[] length = %d\n", end - begin);
    int *it;
    for (it = begin; it < end; it++) {
        printf("%d\n", *it);
    }
    putchar('\n');


    int maze[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("rows count of maze = %d\n", sizeof(maze)/sizeof(maze[0]));
    printf("columns count of maze = %d\n", sizeof(maze[0])/sizeof(maze[0][0]));
    putchar('\n');
    printf("rows count of maze = %d\n", *(&maze + 1) - maze);
    printf("columns count of maze = %d\n\n", *(&maze[0] + 1) - maze[0]);


    /* 〈二維（多維）陣列〉也曾經舉了個例子 */
    printf("maze1\n");
    int maze1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int j;
    for (i = 0; i < 2; i++) {
        int *row = maze1[i];
        for (j = 0; j < 3; j++){
            printf("%d\t", row[j]);
        }
        printf("\n");
    }
    putchar('\n');

    /* 現在已經認識指標了，上例中的 maze1[i] 取得其實是每列一維陣列的首元素位址，然而指定
       給 int* 的 row 的話，如稍早談到的，row 就只會儲存位址，也就是 row 並沒有每列一維
       陣列的長度資訊。

       雖說如此，對多數情境來說，這種從二維陣列中取得每列的方式已經足夠，類似地，若不管長
       度資訊會失去的問題，也可以如下模擬二維陣列
       */
    printf("maze2\n");
    int row1[3] = {1, 2, 3};
    int row2[3] = {4, 5, 6};
    int* maze2[2] = {row1, row2};

    for (i = 0; i < 2; i++) {
        int *row = maze2[i];
        for (j = 0; j < 3;j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
    putchar('\n');

    /* 說是模擬的原因在於，maze2 實際上是 int* 的一維陣列，maze2[0]、maze2[1] 僅儲存 row1、
       row2 首元素的位址，並沒有 row1、row2 的長度資訊，雖說如此，對大多數情境來說，想用一
       維陣列組合出二維陣列，以上的方式也已經足夠。

       有沒有辦法不失去長度資訊呢？
       */
    // According to the last example
    printf("_maze2\n");
    Row _maze2[ROWS] = {&row1, &row2};
    int rows = *(&_maze2 + 1) - _maze2;
    printf("_maze2 rows = %d\n", rows);
    for (i = 0; i < rows; i++) {
        Row row = _maze2[i];
        int len = *(row + 1) - *row;
        for (j = 0; j < len; j++) {
            printf("%d ", *(*row + j));
        }
        printf("\n");
    }
    putchar('\n');
    /* typedef 可用來為指定的型態取別名，就上例來說，為 int(*)[LEN] 取了個別名 ROW，這樣比
       較便於使用 ROW 來宣告，當然，這些挑戰的寫法不容易理解，純粹就是探討，程式基本上還是
       選擇各自情境下易懂的寫法會比較好。

       上一個範例以及接下來純粹是挑戰，可以自行研究一下，就不多做說明了。以下程式示範了如何
       取得二維陣列中的每一列，並保留長度資訊：
       */
    printf("maze3\n");
    int maze3[2][3] = {{1, 2, 3}, {4, 5, 6}};

    for (i = 0; i < 2; i++) {
        int (*row)[3] = &maze3[i];
        for (j = 0; j < 3; j++) {
            // *row: get the first element address of each one-dimensional array and
            //       [j] means the offsets from the first element
            printf("%d ", (*row)[j]);
        }
        printf("\n");
    }
    putchar('\n');


    /* 有沒有辦法完全基於指標來迭代陣列，而不是依靠索引呢？ */
    printf("maze3 another example\n");
    int (*maze3Begin)[3] = maze3;
    int (*maze3End)[3] = *(&maze3 + 1);
    int (*maze3Row)[3] = maze3Begin;
    for (; maze3Row < maze3End; maze3Row++) {
        int *begin = *maze3Row;
        int *end = *(maze3Row + 1);
        int *it;
        for (it = begin; it < end; it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }
    putchar('\n');


    return 0;
}
