#include <stdio.h>

int main(void) {
    /*
        �A�i�H�N���W�λ���B��l���g�b�ܼƤ��e���ܼƤ���A
        ������̬O���t�O���A�N���W�]����^�B��l���g�b��
        �ƫe�ɡA��ܥ��N�ܼƪ��ȥ[�]��^1�A�M��A�Ǧ^�ܼ�
        ���ȡA�N���W�]����^�B��l���g�b�ܼƤ���A��ܥ���
        �^�ܼƭȡA�M��A���ܼƥ[�]��^1
    */

    int i = 0;
    int num = 0;

    num = ++i;   // �۷��i = i + 1; num = i;
    printf("%d\n", num);

    num = --i;    // �۷��i = i - 1; num = i;
    printf("%d\n", num);


    i = 0;
    num = 0;

    num = i++;    // �۷��num = i; i = i + 1;
    printf("%d\n", num);

    num = i--;     // �۷�� num = i; i = i - 1;
    printf("%d\n", num);

    return 0;
}
