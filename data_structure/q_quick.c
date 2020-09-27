#include <stdio.h>

void insertion_sort(int* arr, int length) {
    int n, j;
    for(int i = 1; i < length; ++i) {
        n = arr[i];
        for(j = i - 1; j >=0 && arr[j] > n; --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = n;
    }

}
int main()
{
    int num;
    while(~scanf("%d", &num)) {
        int table[200000] = {0};
        int weight;
        for(int i = 0; i < num; i++) {
            scanf("%d", &weight);
            table[++table[0]] = weight;
        }
       insertion_sort(table + 1, table[0]);
        for(int i = 1; i <= num; i++) {
            printf("%d ", table[i]);
        }
        printf("\n");
        // int adder = 0;
        // while(table[0] > 1) {
        //     insertion_sort(table + 1, table[0]);
        // }
    }
    return 0;
}