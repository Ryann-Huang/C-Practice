#include <stdio.h>


/* 有些結構的實例，可能包含不同型態的成員，然而，在某個時間點上，只會有一個成員是有效的，
   例如，你可能會設計一個磁頭結構，磁頭讀取磁帶中的資料並儲存為對應的資料型態：
   */
typedef struct {
    char cvalue;
    int ivalue;
    double dvalue;

    enum {
        CHAR, INT, DOUBLE
    } type;
} Head;

/* 你可以使用 union，它是一種特殊的結構，維護足夠的空間來置放多個資料成員中的一種，而不是
   為每個資料成員配置各自空間，例如：
   */
typedef struct {
    union {
        char cvalue;
        int ivalue;
        double dvalue;
    } value;

    enum {
        CHAR1, INT1, DOUBLE1
    } type;
} Head1;
/* 在 Head 中定義了匿名的 union 並建立了 value 成員，union 配置足夠大的空間以來容納最大長
   度的資料成員，以上例而言，最大長度是 double 型態，因此 value 成員的大小是 double 的長度，
   由於 union 的資料成員共用記憶體空間，存取當前具有合法值的資料成員，才能正確地取資料
   */

void readChar(Head *head, char cvalue) {
    head->cvalue = cvalue;
    head->type = CHAR;
}

void readInt(Head *head, int ivalue) {
    head->ivalue = ivalue;
    head->type = INT;
}

void readDouble(Head *head, double dvalue) {
    head->dvalue = dvalue;
    head->type = DOUBLE;
}

void printHead(Head *head) {
    switch(head->type) {
    case CHAR:
        printf("head->cvalue = %c\n", head->cvalue);
        break;
    case INT:
        printf("head->ivalue = %d\n", head->ivalue);
        break;
    case DOUBLE:
        printf("head->dvalue = %f\n", head->dvalue);
        break;
    }
}

void readChar1(Head1 *head, char cvalue) {
    head->value.cvalue = cvalue;
    head->type = CHAR1;
}

void readInt1(Head1 *head, int ivalue) {
    head->value.ivalue = ivalue;
    head->type = INT1;
}

void readDouble1(Head1 *head, double dvalue) {
    head->value.dvalue = dvalue;
    head->type = DOUBLE1;
}

void printHead1(Head1 *head) {
    switch(head->type) {
    case CHAR1:
        printf("head->value.cvalue = %c\n", head->value.cvalue);
        break;
    case INT1:
        printf("head->value.ivalue = %d\n", head->value.ivalue);
        break;
    case DOUBLE1:
        printf("head->value.dvalue = %f\n", head->value.dvalue);
        break;
    }
}

int main(void) {
    Head head;

    readInt(&head, 10);
    printHead(&head);

    readChar(&head, 'a');
    printHead(&head);
    putchar('\n');

    Head1 head1;

    readInt1(&head1, 25);
    printHead1(&head1);
    printf("head1->ivalue = %d\n", head1.value.ivalue);

    readChar1(&head1, 'b');
    printHead1(&head1);
    printf("head1->cvalue = %c\n", head1.value.cvalue);


    return 0;
}
