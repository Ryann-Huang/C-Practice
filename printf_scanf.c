#include <stdio.h>

int main(void) {
    // \n �����@�Ӧr��
    int count = printf("This is a test!\n");
    printf("%d\n\n", count);

    printf("��ܦr�� %c\n", 'A');
    printf("��ܦr���s�X %d\n", 'A');
    printf("��ܦr�� %c\n", 65);
    printf("��ܤQ�i���� %d\n", 15);
    printf("��ܤK�i���� %o\n", 15);
    printf("��ܤQ���i���� %x\n", 15);
    printf("��ܤQ���i���� %X\n", 15);
    printf("��ܬ�ǰO�� %e\n", 0.01234);
    printf("��ܬ�ǰO�� %E\n\n", 0.001234);

    printf("%6.2f\n", 19.234);
    printf("%-6.2f\n", 19.234);
    printf("%*d\n", 1, 1);
    printf("%*d\n", 2, 1);
    printf("%*d\n", 3, 1);
    printf("%.*s\n", 3, "Justin");
    printf("%.*s\n", 5, "Justin");
    printf("%.*s\n\n", 7, "Justin");


    int input;
    double dInput;

    printf("Type a number:");
    scanf("%d", &input);
    printf("The number you type is: %d\n\n", input);

    printf("Type a float point number: ");
    scanf("%lf", &dInput);
    printf("The float point number you type is: %lf\n\n", dInput);

    int num1, num2;
    printf("Type two numbers separated by one space: ");
    scanf("%d %d", &num1, &num2);
    printf("Two numbers you type are: %d %d\n\n", num1, num2);

    printf("Type two numbers separated by '-': ");
    scanf("%d-%d", &num1, &num2);
    printf("You type: %d-%d\n\n", num1, num2);

    fflush(stdin);

    char buf[50l];

    printf("�п�J1��5���r��: ");
    scanf("%[1-5]", buf);
    printf("��J���r���� %s\n\n", buf);

    fflush(stdin);

    printf("�п�JXYZ���@�r��: ");
    scanf("%[XYZ]", buf);
    printf("��J���r���� %s\n\n", buf);

    fflush(stdin);

    char str[10];
    printf("�п�J�r��: ");
    scanf("%9s", str); // ���wscanf��Ū�J������
    printf("��J���r��: %s\n\n", str);;



    return 0;
}
