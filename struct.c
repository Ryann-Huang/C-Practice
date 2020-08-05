#include <stdio.h>

typedef const char* String;

/* 有些資料會有相關性，相關聯的資料組織在一起，對於資料本身的可用性或者是程式碼的可讀性，
   都會有所幫助，例如，在程式中你可能發現，在進行帳戶之類的處理時，帳號、名稱、餘額這三個
   資料總是一併出現的，這時可以將它們組織在一起，定義為結構：
   */
struct Account {
    String id;
    String name;
    double balance;
};

/* 也可以在函式中定義結構，可以直接宣告結構實例，例如：*/
struct Member_Info {
    String name;
    Int age;
} m_info = {"Tom", 33};

/*結構的名稱型態包含 struct 這個名稱，因此建立實例時，會需要是 struct Account acct 的形式，
  為了方便起見，可以使用 typedef 定義結構的別名，如此一來，宣告並產生實例時，就不用再寫 struct
  關鍵字，例如：
  */
typedef struct Order {
    String Order_Id;
    String Order_Date;
} Order;

/* 以上的範例定義的結構型態為 struct Order，並以 typedef 取了個別名，這與以下不太一樣：*/
typedef struct {
    String login_id;
    String login_time;
} login;
/* 以上的範例定義的結構型態為 struct <anonymous>，也就是匿名結構，並以 typedef 取這個匿名
   結構取了個別名。
   */

void PrintAcct(struct Account);

int main(void) {
    struct Account acct;
    acct.id = "123-456-789";
    acct.name = "Justin Lin";
    acct.balance = 1000;
    PrintAcct(acct);
    /* struct Account acct 建立了 Account 的實例，這時 acct 在函式執行完畢後就會自動清
       除，存取實例的值域時可以使用 dot 運算子「.」，將結構實例直接指定給另一結構時會進行
       複製，如果值域是個陣列，會逐一複製元素，如上作為引數傳遞時也是如此。

       如同變數沒有指定初值，結果會不可預期，如果沒有指定值域的初值也是如此，可以如下指定
       每個值域的初值來建立結構實例：
       */
    struct Account acct1 = {"123-456-799", "Tim Duncan", 900};
    PrintAcct(acct1);
    /* 在建立實例並初始化時，也可以使用成員名稱，不一定要按照成員名稱的定義順序來指定：*/
    struct Account acct2 = {.balance = 950, .id = "223-456-789", .name = "Michael Jordan"};
    PrintAcct(acct2);

    /* 若要宣告結構陣列並初始每個結構成員，可以如下：*/
    struct Account accts[] = {
        {"323-456-799", "Scotty Pipen", 930},
        {"123-466-799", "Karl Malone", 900}
    };

    Order orders[] = {
        {"0001", "2020-08-05"},
        {"0002", "2020-08-05"}
    }


    return 0;
}

void PrintAcct(struct Account acct) {
    printf("Account(%s, %s, %f)\n", acct.id, acct.name, acct.balance);
}
