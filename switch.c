#include <stdio.h>

int main(void) {
    int score, level;
    printf("Input the score:");
    scanf("%d", &score);
    level = score / 10;

    switch(level) {
    case 10:
    case 9:
        puts("A\n\n");
        {
            /*
                �o�O�]���H�W���{���X���Adefault �P case �ݩ�P�@�϶��A�Ӫ�l�i��Q���L�A
                �p�G�u���n�b case ���Y�ŧi�ê�l�ܼơA�������T�w�q�t�@�Ӱ϶�
            */
            int a = 0;
        }
        break;
    case 8:
        puts("B\n\n");
        break;
    case 7:
        puts("C\n\n");
        break;
    case 6:
        puts("D\n\n");
        break;
    default:
        puts("E\n\n");
    }

    return 0;
}
