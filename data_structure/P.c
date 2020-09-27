#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} node;

node* build_list(node *front, int num)
{
    node *new_node, *current_node, *prev_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->num = num;
    new_node->next = NULL;
    if(front == NULL) {
        front = new_node;
    } else {
        current_node = front;
        if(num < current_node->num) {
            new_node->next = current_node;
            front = new_node;
        } else {
            while(current_node->next != NULL) {
                prev_node = current_node;
                current_node = current_node->next;
                if(num < current_node->num) {
                    prev_node->next = new_node;
                    new_node->next = current_node;
                    return front;
                }
            }
            current_node->next = new_node;
        }
    }
    return front;
}

void show_list(node *front)
{
    node *current_node = front;
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

node* combine(node *x_front, node *y_front)
{
    node *x_current = x_front, *y_current = y_front;
    node *new_front = (node*)malloc(sizeof(node));
    node *new_current = new_front;
    while(x_current != NULL || y_current != NULL) {
        node *new_node = (node*)malloc(sizeof(node));
        new_node->next = NULL;
        if(x_current == NULL) {
            new_node->num = y_current->num;
            y_current = y_current->next;
        } else if(y_current == NULL) {
            new_node->num = x_current->num;
            x_current = x_current->next;
        } else {
            if(x_current->num <= y_current->num) {
                new_node->num = x_current->num;
                x_current = x_current->next;
            } else {
                new_node->num = y_current->num;
                y_current = y_current->next;
            }
        }
        new_current->next = new_node;
        new_current = new_current->next;
        // show_list(new_front);
    }
    return new_front;
}




int main()
{
    int first_num, second_num;
    while(scanf("%d", &first_num) != EOF) {
        node *front_x = NULL, *front_y = NULL;
        int num, i;
        for(i = 0; i < first_num; i++) {
            scanf("%d", &num);
            front_x = build_list(front_x, num);
        }
        // show_list(front_x);

        scanf("%d", &second_num);
        for(i = 0; i < second_num; i++) {
            scanf("%d", &num);
            front_y = build_list(front_y, num);
        }
        // show_list(front_y);

        node *front_add = NULL;
        front_add = (node*)malloc(sizeof(node));


        front_add = combine(front_x, front_y);
        show_list(front_add->next);

    }

    return 0;
}
