#include <stdio.h>
#include <stdlib.h>

typedef const char* String;

typedef struct {
    String id;
    String name;
    double balance;
} Account;

void deposit(Account *acct, double amount) {
    if (amount <= 0) {
        printf("The amount must be greater than 0!\n");
        return;
    }

    /* 如果使用結構宣告的指標來存取成員，必須使用 -> 運算子，因為傳遞的是結構實例的位址，
       函式中對實例的變更，就是對原結構實例的變更
       */
    acct->balance += amount;
}

void withdraw(Account *acct, double amount) {
    if (amount <= 0) {
        printf("The amount must be greater than 0!\n");
        return;
    }

    if (amount > acct->balance) {
        printf("餘額不足!\n");
        return;
    }

    acct->balance -= amount;
}

/* ===================================================================================
   以上範例的 withdraw、deposit 等函式，都是服務於 Account，若想要的話，也可以令函式成為結
   構的成員之一，這麼組合有點物件導向語言中，物件與方法的概念，例如：
   */
typedef struct Account2{
    String id;
    String name;
    double balance;

    char *_to_str;

    void (*deposit)(struct Account2*, double);
    void (*withdraw)(struct Account2*, double);
    String (*to_str)(struct Account2*);
} Account2;

String to_str(Account2 *acct) {
    int n = snprintf(NULL, 0, "Account2(%s, %s, %f)\n", acct->id, acct->name, acct->balance);

    if (acct->_to_str != NULL) {
        free(acct->_to_str);
    }

    acct->_to_str = malloc((n + 1) * sizeof(char));
    snprintf(acct->_to_str, n + 1, "Account2(%s, %s, %f)\n", acct->id, acct->name, acct->balance);

    return acct->_to_str;
}

Account2* new_account(String id, String name, double balance) {
    Account2 *acct = (Account2*)malloc(sizeof(Account2));
    acct->id = id;
    acct->name = name;
    acct->balance = balance;
    acct->_to_str = NULL;

    acct->deposit = deposit;
    acct->withdraw = withdraw;
    acct->to_str = to_str;

    return acct;
}

void del_account(Account2 *acct) {
    free(acct->_to_str);
    free(acct);
}

int main(void) {
    Account acct = {"123-456-789", "Justin Lin", 1000};
    /* 在〈定義結構〉中示範的 printAcct 函式，參數直接以結構型態宣告，指定結構實例作為引數
       時，會建立新的實例並複製各個值域。

       如果不希望複製的行為發生，可以傳遞位址，例如：
       */
    deposit(&acct, 500);
    withdraw(&acct, 200);

    printf("Account(%s, %s, %f)\n", acct.id, acct.name, acct.balance);
    putchar('\n');

    Account2 *acct1 = new_account("223-456-789", "Mary Li", 950);
    acct1->deposit(acct1, 300);
    acct1->withdraw(acct1, 500);

    printf("%s\n", acct1->to_str(acct1));

    del_account(acct1);

    return 0;
}
