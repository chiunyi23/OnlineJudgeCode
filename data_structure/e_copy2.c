#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int c1, c2;
    int fee;
    int num;
    struct Node *next;
}node_t;
node_t *head=NULL, *curr, *prev;
int total_city;
float total_cost;
int set[501];
int project[2001];


void init(){
    int i;
    for (i=1; i<=total_city; i++)
        set[i]=i;
    total_cost=0;
}


int setting(int a, int b){
    if (set[a] == set[b])
        return 1;
    if (set[a] != set[b]){
        int set_num=set[b];
        int i;
        for (i=1; i<=total_city; i++)
            if (set[i] == set_num)
                set[i]=set[a];
    }
    return 0;
}


void add(int i){
    node_t *new_case=(node_t *)malloc(sizeof(node_t));
    int x, y, p;
    scanf("%d %d %d", &x, &y, &p);
    new_case->c1=x;
    new_case->c2=y;
    new_case->fee=p;
    new_case->num=i;
    new_case->next=NULL;

    if (head == NULL)
        head=new_case;
    else{
        curr=head;
        if (new_case->fee < curr->fee){
            new_case->next=curr;
            head=new_case;
        }
        else{
            while (curr->next != NULL){
                prev=curr;
                curr=curr->next;
                if (new_case->fee < curr->fee){
                    new_case->next=curr;
                    prev->next=new_case;
                    return;
                }
            }
            curr->next=new_case;
        }
    }
}
int kruskal(){
    int i=0;
    curr=head;
    while (curr != NULL){
        if ( !setting(curr->c1, curr->c2) ){
            total_cost+=curr->fee;
            project[++i]=curr->num;
            if (i == total_city-1)
                return 1;
        }
        curr=curr->next;
    }
    return 0;
}

void sort(){
    int i, j, min;
    for (i=1; i<total_city-1; i++){
        min=i;
        for (j=i+1; j<=total_city-1; j++)
            if (project[j] < project[min])
                min=j;
        int temp=project[i];
        project[i]=project[min];
        project[min]=temp;
    }
}

int main(){
    int e, i;
    while (scanf("%d", &total_city) == 1){
        scanf("%d", &e);
        for (i=0; i<e; i++){
            init();
            add(i+1);
            int flag=kruskal();
            if (flag == 0)
                printf("0\n");
            else{
                sort();
                printf("%.2f ", total_cost/2);
                int j;
                for (j=1; j<=total_city-1; j++)
                    printf("%d ", project[j]);
                printf("\n");
            }
        }
        while (head != NULL){
            curr=head;
            head=head->next;
            free(curr);
        }
    }
    return 0;
}
