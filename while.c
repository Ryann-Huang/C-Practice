#include <stdio.h>

void clearBuf();

int main(void) {
    int score = 0, sum = 0;
    int count = -1;

    while (score != -1) {
        sum += score;
        ++count;
        printf("Please input the score for average(-1 to stop):");
        scanf("%d", &score);
    }

    printf("The average is %.2f\n\n", (double)sum/count);


    int num;
    int replay;

    do {
        printf("Input an integer:");
        scanf("%d", &num);
        clearBuf();
        printf("The integer you input is odd number? %c\n", num & 1 ? 'Y': 'N');

        printf("Input 1 to continue or 0 to stop: ");
        scanf("%d", &replay);
        clearBuf();
    }while(replay == 1);

    printf("\n");


    int input = 0;

    while (!input) {
        printf("Please input an integer:");
        scanf("%d", &input);
        clearBuf();

        if (input) {
            printf("100 / %d = %f\n", input, (double)100/input);
        }else {
            printf("Divisor can't be \"0\"\n");
        }
    }

    return 0;
}

void clearBuf() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF){}
}
