#include<stdio.h>

int data[1000], SZ = 0;
void Insert_Heap(int IN){
    int now = ++SZ, temp, change;
    data[SZ] = IN;
    while(now > 1){
        change = now / 2;
        if(data[change] > data[now]) break;
        temp = data[change];  data[change] = data[now]; data[now] = temp;  // swap
        now = change;
    }
}

void Heapify(int size){
    int now = 1, temp, change;
    while(2 * now <= size){
        int fb = 1;
        if(data[2*now] > data[now]) fb = 0;
        else if((2*now + 1) <= size && data[2*now + 1] > data[now]) fb = 0;
        if(fb) break;
        change = 2 * now;
        if((2 * now + 1) <= size && data[2*now + 1] > data[2*now]) change = 2 * now + 1;
        temp = data[change];  data[change] = data[now]; data[now] = temp;   // swap
        now = change;
    }
}

void Heap_Sort(int n){
    int temp, i, t;
    for(i = n; i >= 2; i--){
        temp = data[i];  data[i] = data[1]; data[1] = temp; // swap
        Heapify(i - 1);
    }
}

int main(){
    int num, i, temp;
    while(scanf("%d", &num) != EOF){
        for(i = 0; i < num; i++){
            scanf("%d", &temp);
            Insert_Heap(temp);
        }
        Heap_Sort(num);
        for(i = 1; i <= num; i++) printf("%d ", data[i]);
        printf("\n\n");
        SZ = 0;
    }
    return 0;
}