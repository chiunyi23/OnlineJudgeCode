#include <stdio.h>

int adder;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reHeapDown(int* arr, int N, int bottom) {
    int left = 2 * N;
    int right = (2 * N) + 1;
    // check if N node has right child
    if(right <= bottom) {
        if(arr[right] <= arr[left]) {
            if(arr[right] < arr[N]) {
                swap(&arr[right], &arr[N]);
                reHeapDown(arr, right, bottom);
            }
        }
        else {
            if(arr[left] < arr[N]) {
                swap(&arr[left], &arr[N]);
                reHeapDown(arr, left, bottom);
            }
        }
    }
    if(left <= bottom) {
        if(arr[left] < arr[N]) {
            swap(&arr[left], &arr[N]);
        }
    }
}

void reHeapUp(int arr[], int index) {
    while(index / 2 > 0) {
        if(arr[index] < arr[index / 2]) {
            swap(&arr[index], &arr[index / 2]);
        }
        index /= 2;
    }
}

void insert(int table[], int weight) {
    int index = ++table[0];
    table[index] = weight;
    reHeapUp(table, index);
}

int delete(int table[]) {
    int key = table[1];
    int index = table[0];
    --table[0];
    table[1] = table[index];
    reHeapDown(table, 1, table[0]);
    return key;
}

int main()
{
    int num;
    while(~scanf("%d", &num)) {
        int table[10000] = {0};
        int weight;
        adder = 0;
        for(int i = 0; i < num; i++) {
            scanf("%d", &weight);
            insert(table, weight);
        }
        for(int i = 1; i <= num; i++) {
            printf("%d ", delete(table));
            // printf("%d ", table[i]);
        }
        printf("\n");

        // build heap
        
        int weight1, weight2;
        // printf("%d\n", adder);
    }
    return 0;
}