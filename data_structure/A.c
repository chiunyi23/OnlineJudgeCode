#include <stdio.h>
#include <stdlib.h>
int gcd(int, int);
int lcm(int, int);

int main()
{
    int num;
    scanf("%d", &num);

    while(num--) {
        int input_num, i;
        int* inputs = NULL;
        scanf("%d", &input_num);
        inputs = (int* )malloc(sizeof(int) * input_num);
        for(i = 0; i < input_num; i++) {
            scanf("%d", &inputs[i]);
        }
        /*
        int* result = NULL;
        result = (int* )malloc(sizeof(int) * input_num - 1);
        for(i = 0; i < input_num - 1; i++) {
            // printf("%d ", lcm(inputs[i], inputs[i+1]));
            // printf("%d ", lcm(inputs[i], lcm(inputs[i+1], inputs[i])));
            // result = lcm(inputs[i], lcm(inputs[i+1], inputs[i]));
            result[i] = lcm(inputs[i], inputs[i+1]);
        }
        */
        /*
        int result;
        for(i = 0; i < input_num - 1; i++) {
            result = lcm(inputs[i+1], lcm(inputs[i+1], inputs[i]));
        }
        */
        int result = inputs[0];
        for(i = 1; i < input_num; i++) {
            result = inputs[i] / gcd(inputs[i], result) * result;
        }
        printf("%d\n", result);
    }

    return 0;
}


int gcd(int m, int n)
{
    while(n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int lcm(int m, int n)
{
    return m * (n / gcd(m, n));

}
