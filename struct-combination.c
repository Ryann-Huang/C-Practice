#include <stdio.h>

/* 如果今天你想定義一個支票帳戶，方式之一是：

   typedef struct {
      String id;
      String name;
      double balance;
      double overdraftlimit;
   } CheckingAccount;
   這是個很尋常的作法，也許你想將 id、name 與 balance 組織在一起，C 語言的結構中允許定義結構：
   */

typedef const char* String;

typedef struct {
    struct {
        String id;
        String name;
        double balance;
    } acct;
    double overdraftlimit;
} CheckingAccount;
/* 因為內層的匿名結構用來實例了 acct，因此必須透過 acct 來進一步取得內層的值域，你也可以為內層
   結構命名並用來實例化：
   */
typedef struct {
    struct Account {
        String id;
        String name;
        double balance;
    };

    struct Account acct;
    double overdraftlimit;
} CheckingAccount1;
/* 或者使用已定義的結構來實例化 acct： */
typedef struct {
    String id;
    String name;
    double balance;
} Account;

typedef struct {
    Account acct;
    double overdraftlimit;
} CheckingAccount2;
/* 看來還不錯，不過，如果想要 checking.name 就能取得名稱的話，可以直接內嵌結構型態：*/
typedef struct {
    struct {
        String id;
        String name;
        double balance;
    };
    double overdraftlimit;
} CheckingAccount3;
/* CheckingAccount 中有個匿名結構，匿名結構的成員會被視為外包結構的成員，也就可以如上
   存取，也可以將另一個已定義的結構嵌入：
   */
typedef struct {
    String id;
    String name;
    double balance;
} Account1;

typedef struct {
    Account1;
    double overdraftlimit;
} CheckingAccount4;

int main(void) {
    CheckingAccount checking = {
        .acct = {"123-456-789", "Justin Lin", 1000},
        .overdraftlimit = 30000
    };

    printf("%s\n", checking.acct.id);
    printf("%s\n", checking.acct.name);
    printf("%f\n", checking.acct.balance);
    printf("%f\n", checking.overdraftlimit);
    puts("\n");

    CheckingAccount1 checking1 = {
        .acct = {"223-456-789", "Mary Li", 950},
        .overdraftlimit = 35000
    };

    printf("%s\n", checking1.acct.id);
    printf("%s\n", checking1.acct.name);
    printf("%f\n", checking1.acct.balance);
    printf("%f\n", checking1.overdraftlimit);
    puts("\n");

    CheckingAccount2 checking2 = {
        .acct = {"323-456-789", "Michael Jordan", 3000},
        .overdraftlimit = 100000
    };

    printf("%s\n", checking2.acct.id);
    printf("%s\n", checking2.acct.name);
    printf("%f\n", checking2.acct.balance);
    printf("%f\n", checking2.overdraftlimit);
    puts("\n");

    CheckingAccount3 checking3 = {
        {"423-456-789", "Tim Duncan", 1100},
        .overdraftlimit = 50000
    };

    printf("%s\n", checking3.id);
    printf("%s\n", checking3.name);
    printf("%f\n", checking3.balance);
    printf("%f\n", checking3.overdraftlimit);
    puts("\n");

    /*CheckingAccount4 checking4 = {
        {"523-456-789",
        "Dennis Robert",
        2500},
        .overdraftlimit = 60000
    };

    printf("%s\n", checking4.id);
    printf("%s\n", checking4.name);
    printf("%f\n", checking4.balance);
    printf("%f\n", checking4.overdraftlimit);
    puts("\n");*/

    return 0;
}
