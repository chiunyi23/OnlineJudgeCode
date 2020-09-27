#include <stdio.h>

// void check_and_print()

int main()
{
    int num;
    while(~scanf("%d", &num)) {
        int q1[1001] = {0}, q2[1001] = {0}, q3[1001] = {0};
        int input;
        for(int i = 0; i < num; i++) {
            scanf("%d", &input);
            if(input % 2 == 0) {
                q2[0]++;
                q2[q2[0]] = input;
            }    
            else {
                q1[0]++;
                q1[q1[0]] = input;
            }
        }
        int counter1 = 1, counter2 = 1;
        while(1) {
            if(q1[0] == 0 && q2[0] == 0)
                break;
            if(q1[0] != 0) {
                if(q1[0] == 1 && q2[0] == 0) {
                    printf("%d\n", q1[counter1++]);
                    break;
                }
                printf("%d ", q1[counter1++]);
                q1[0]--;
            }
            if(q1[0] != 0) {
                if(q1[0] == 1 && q2[0] == 0) {
                    printf("%d\n", q1[counter1++]);
                    break;
                }
                printf("%d ", q1[counter1++]);
                q1[0]--;
            }
            if(q2[0] != 0) {
                if(q2[0] == 1 && q1[0] == 0) {
                    printf("%d\n", q2[counter2++]);
                    break;
                }
                printf("%d ", q2[counter2++]);
                q2[0]--;
            }
        }
    } 

    return 0;
}