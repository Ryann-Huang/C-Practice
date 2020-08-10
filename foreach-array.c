#include <stdio.h>

int main(void) {
    /* 在處理陣列時，經常會是從頭至尾迭代陣列元素，針對這類需求，現代語言中都有 foreach
       之類的語法，C++ 11 之後也有提供，然而 C 語言沒有。

       透過巨集，可以來建立簡單的 foreach，以進行陣列的迭代，方式有許多種，這邊採取的出發
       點是以下範例：
       */
    int arr[] = {10, 20, 30, 40, 50};
    int size = *(&arr + 1) - arr;
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    puts("\n");

    /* 這邊希望的 foreach 語法，可以如下使用：

       int arr[] = {10, 20, 30, 40, 50};
       foreach(int *v, arr) {
           printf("%d ", *v);
       }

       這個語法如何展開為方才範例的完整語法呢？因為可用的展開項目只有 int *v 與 arr，因此必須整理一下範例：

       int arr[] = {10, 20, 30, 40, 50};
       for(int size = *(&arr + 1) - arr, i = 0; i < size; i++) {
           int *v = arr + i;
           printf("%d ", *v);
       }

       現在可以初步定義巨集：

       #define foreach(item, arr)                                  \
           for(int size = *(&arr + 1) - arr, i = 0; i < size; i++) \
               item = (arr + i);

       問題來了，你不能在巨集中直接寫死 {}，因為 foreach 的使用者要能自行決定是否使用 {}，因此 item = arr + i
       這行必須能建立一個範疇，而 foreach 的使用者決定該範疇要不要使用 {}，要能建立範疇又可以建立變數的陳述句，
       也只有 for 了，因此試著將範例再整理一下：

       int arr[] = {10, 20, 30, 40, 50};
       for(int size = *(&arr + 1) - arr, i = 0, j = 0; i < size; i++, j = 0) {
           for(int *v = arr + i; j < 1; j++)
               printf("%d ", *v);
       }

       內層的 for 作用純粹用來建立範疇，因此只執行一次，現在可以定義巨集如下：

       #define foreach(item, arr)                                                \
       for(int size = *(&arr + 1) - arr, i = 0, j = 0; i < size; i++, j = 0) \
           for(item = arr + i; j < 1; j++)

       看來好像 OK，不過這個 foreach 在處理 break 時會有問題，底下還是會顯示全部的陣列元素：

       int arr[] = {10, 20, 30, 40, 50};
       foreach(int *v, arr) {
           printf("%d ", *v);
           if(*v > 30) {
               break;
           }
       }

       理由很簡單，展開(gcc -E file.c -o file.i)就是 break 只中斷內部的 for 迴圈，必須有個方式知道內層 for
       被中斷了，因此不採取計數 j 的方式，改用個 loop 旗標：

       #define foreach(item, arr)                                                                  \
           for(int size = *(&arr + 1) - arr, i = 0, loop = 1; loop && i < size; i++, loop = !loop) \
               for(item = arr + i; loop; loop = !loop)

       這個 foreach 可以處理 break，因為 loop 一開始是 1，表示預設執行外層與內層 for，內層 for 執行過後將 loop
       反相，此時 loop 為 0，外層 for 又將之反相，此時 loop 又回到 1，也就可以繼續下次的迴圈。

       如果內層 for 被 break，loop 就不會被反相，也就是 loop 維持為 1，外層 for 將之反相後 loop 成為 0，接下來外
       層 for 也就不會執行了。

       這個 foreach 也可以用於其他型態的陣列，例如字串陣列：

       String names[] = {"Justin", "Monica", "Irene"};
       foreach(String *name, names) {
           printf("%s ", *name);
       }
       */



    return 0;
}
