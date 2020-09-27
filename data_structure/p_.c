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
        if(arr[right] >= arr[left]) {
            if(arr[right] > arr[N]) {
                swap(&arr[right], &arr[N]);
                reHeapDown(arr, right, bottom);
            }
        }
        else {
            if(arr[left] > arr[N]) {
                swap(&arr[left], &arr[N]);
                reHeapDown(arr, left, bottom);
            }
        }
    }
    else if(left <= bottom) {
        if(arr[left] > arr[N]) {
            swap(&arr[left], &arr[N]);
            reHeapDown(arr, left, bottom);
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

void heap_sort(int table[], int num) {
    for(int i = num / 2; i > 0; i--)
        reHeapDown(table, i, num);
    for(int i = num; i > 0; i--) {
        swap(&table[1], &table[i]);
        reHeapDown(table, 1, i);
    }
}

int main()
{
    int num;
    while(~scanf("%d", &num)) {
        int table[num];
        int weight;
        adder = 0;
        for(int i = 1; i <= num; i++) {
            scanf("%d", &table[i]);
            // insert(table, weight);
        }
        heap_sort(table, num);
        for(int i = 1; i <= num; i++) {
            printf("%d ", table[i]);
            // printf("%d ", table[i]);
        }
        printf("\n");

        // build heap
        
        int weight1, weight2;
        // printf("%d\n", adder);
    }
    return 0;
}