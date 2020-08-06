#include <stdio.h>

/* 有時候，你會想要定義一組相關的常數，例如，以一組常數來代表遊戲中動作：*/
const int ACTION_STOP = 0;
const int ACTION_RIGHT = 1;
const int ACTION_LEFT = 2;
const int ACTION_UP = 3;
const int ACTION_DOWN = 4;

void play(int action) {
    switch(action) {
    case 0:
        puts("Stop\n");
        break;
    case 1:
        puts("Right\n");
        break;
    case 2:
        puts("Left\n");
        break;
    case 3:
        puts("Up\n");
        break;
    case 4:
        puts("Down\n");
        break;
    default:
        puts("Unknown Action!\n");
    }
}
/* 這種方式雖然行得通，不過 play 的參數宣告為 int，在閱讀上沒有指出它可以接受的列舉，
   因而函式中的 case 也不知道其意涵為何；對於這類列舉常數的需求，
   C 本身提供了 enum 來達到這類任務。例如：
   */
enum ACTION {
    STOP, RIGHT, LEFT, UP, DOWN
};

void play_with_Enum(enum ACTION action) {
    switch(action) {
    case STOP:
        puts("STOP\n");
        break;
    case RIGHT:
        puts("RIGHT\n");
        break;
    case LEFT:
        puts("LEFT\n");
        break;
    case UP:
        puts("UP\n");
        break;
    case DOWN:
        puts("DOWN\n");
        break;
    default:
        puts("Unknown Action!\n");
    }
}
/* enum Action 可以用來宣告變數，被列舉的成員，見範圍會與使用 enum 處的範圍相同，
   如果有其他 enum 列舉了同名的成員，會發生名稱衝突。

   enum 列舉的成員，會有預設的對應整數，無範疇的列舉成員，在必須取得整數值的場合，
   會自動轉換為對應的整數，對應整數預設由 0 開始，也可以自行指定。例如：
   */
enum ACTION1 {
    STOP1 = 1, RIGHT1, LEFT1, UP1, DOWN1
};
/* 就上例來說，STOP 對應的整數為後續列舉成員沒有設定對應數值的話，會自動遞增 1，所以
   RIGHT 為 2、LEFT 為 3，依此類推，然而列舉成員對應的常數值，不一定要有遞增關係，例如：
   */
enum ACTION2 {
    STOP2 = 2, RIGHT2 = 1, LEFT2 = 3, UP2, DOWN2
};

int main(void) {
    play(ACTION_RIGHT);
    play(ACTION_LEFT);

    play_with_Enum(RIGHT);
    play_with_Enum(LEFT);

    printf("STOP2 = %d\n",  STOP2);
    printf("RIGHT2 = %d\n",  RIGHT2);
    printf("LEFT2 = %d\n",  LEFT2);
    printf("UP2 = %d\n",  UP2);
    printf("DOWN2 = %d\n",  DOWN2);
    puts("\n");

    /* 在必要的時候，列舉元的數值可用來與其他數值作運算，例如：*/
    printf("LEFT2 + 1 = %d\n", LEFT2 + 1);


    return 0;
}
