#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} node;

void build_list(node **front, int num)
{
    node *new_node, *current_node, *prev_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->num = num;
    new_node->next = NULL;
    if(*front == NULL) {
        (*front)= new_node;
        printf("front in build_list function: %x\n", (*front));
    } else {
        current_node = *(front);
        if(num < current_node->num) {
            new_node->next = current_node;
            (*front) = new_node;
        } else {
            while(current_node->next != NULL) {
                prev_node = current_node;
                current_node = current_node->next;
                if(num < current_node->num) {
                    prev_node->next = new_node;
                    new_node->next = current_node;
                    return ;
                }
            }
            current_node->next = new_node;
        }
    }
    // printf("front in build-list function: %x\n", front);
    // printf("num value of front in build-list function: %d\n", front->num);
    return ;
}

void show_list(node *front)
{
    node *current_node = front;
    // printf("%x\n", current_node);
    // printf("%x\n", front);
    while(current_node != NULL) {
        if(current_node->next == NULL) {
            printf("%d", current_node->num);
        }
        else {
            printf("%d ", current_node->num);
        }
        current_node = current_node->next;
    }
    printf("\n");
}


int main()
{
    int first_num, second_num;
    while(scanf("%d", &first_num) != EOF) {
        node *front_x = NULL, *front_y = NULL;
        int num, i;
        for(i = 0; i < first_num; i++) {
            scanf("%d", &num);
            build_list(&front_x, num);
        }
        printf("front's value in main funciton: %x\n", front_x);
        printf("front's address in main funciton: %x\n", &front_x);
        show_list(front_x);


    }

    return 0;
}
