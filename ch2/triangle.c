#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) == 1) {
        int line_down = n;
        int current_sign = 1;
        int space_counter = 0;
        while(line_down > 0) {

            if(space_counter < n - line_down) {
                printf(" ");
                space_counter++;
                continue;
            }

            if(current_sign < (line_down << 1)) {
                printf("#");
                current_sign++;
                continue;
            }

            // new line if output all the sign in the line
            if(current_sign == (line_down << 1)) {
                printf("\n");
                line_down--;
                current_sign = 1;
                space_counter = 0;
            }

        }
    }


    return 0;
}