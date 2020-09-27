#include <stdio.h>
#include <stdlib.h>


void sort(int arr[], int len) {
    for(int i = 1; i < len; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && temp < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
/*
void InsertionSort(int *arr, int size){

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
*/
int main()
{
    int num;
    int location[1000];
    int loc_num;
    while(~scanf("%d", &num)) {
        while(num--) {
            scanf("%d", &loc_num);
            for(int i = 0; i < loc_num; i++)
                scanf("%d", &location[i]);
            sort(location, loc_num);
            
            int mid;
            int distance = 0;
            if(loc_num & 1) {
                mid = location[loc_num / 2];
                for(int i = 0; i < loc_num; i++) {
                    distance += abs(mid - location[i]);
                }
            }
            else {
                int temp_dis1 = 0, temp_dis2 = 0;
                mid = (location[loc_num / 2] + location[loc_num / 2 - 1]) / 2;
                for(int i = 0; i < loc_num; i++) {
                    distance += abs(mid - location[i]);
                    temp_dis1 += abs(location[loc_num / 2] - location[i]);
                    temp_dis2 += abs(location[loc_num / 2 - 1] - location[i]);
                }
                if(temp_dis1 <= distance) {
                    mid = location[loc_num / 2];
                    distance = temp_dis1;
                }
                else if(temp_dis2 <= distance) {
                    mid = location[loc_num / 2 - 1];
                    distance = temp_dis2;
                }
            }

        
            printf("%d %d\n", mid, distance);
        }
        
    }
    return 0;
}