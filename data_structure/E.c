#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    int counter = 1;
    while(scanf("%d", &num)) {
        if(num == 0) {
            break;
        }

        int* bricks = NULL;
        bricks = (int*)malloc(sizeof(int) * num);
        int i;
        for(i = 0; i < num; i++) {
            scanf("%d", &bricks[i]);
        }

        int sum = 0, avg;
        for(i = 0; i < num; i++) {
            sum += bricks[i];
        }
        avg = sum / num;

        int moves = 0;
        for(i = 0; i < num; i++) {
            moves += abs(bricks[i] - avg);
            // printf("%d ", bricks[i]);
        }
        moves /= 2;
        printf("Set #%d\n", counter++);
        printf("The minimum number of moves is %d.\n\n", moves);
    }

    return 0;
}
