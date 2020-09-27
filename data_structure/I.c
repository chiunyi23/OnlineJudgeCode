#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Size 15

typedef struct number {
    int data;
    struct number* next;
} Stack_t;

int isError = 0;

unsigned int isEmpty(Stack_t* top) {
    return (top == NULL);
}

unsigned int isFull(Stack_t* top) {
    int counter = 0;
    Stack_t* current = top;
    while(current != NULL) {
        current = current->next;
        counter++;
    }
    printf("!!!%d\n", counter);
    return counter > Size ? 1 : 0;
}

Stack_t* newNode(Stack_t* top, int data) {
    Stack_t* node = (Stack_t*)malloc(sizeof(Stack_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Stack_t** top, int data) {
    Stack_t* new_node = newNode(&top, data);
    new_node->next = *top;
    *top = new_node;
}

int pop(Stack_t** top) {
    if(isEmpty(*top)) {
        isError = 1;
        return 0;
    }
    Stack_t* temp = *top;
    *top = (*top)->next;

    int popped = temp->data;
    free(temp);
    return popped;
}
void print(Stack_t* top) {
    Stack_t* current = top;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    char num[20] = {};

    while(scanf("%s", num) != EOF) {
        int i;
        int error = 0;
        Stack_t* list = NULL;
        for(i = 0; i < strlen(num); i++) {
            if(isdigit(num[i])) {
                push(&list, num[i] - '0');
            }
            else {
                if(isEmpty(list)) {
                    printf("Input Error\n");
                    error = 1;
                    break;
                }
                int a = pop(&list);
                int b = pop(&list);
                if(isError) {
                    printf("Input Error\n");
                    isError = 0;
                    break;
                }

                switch (num[i]) {
                    case '+':
                        push(&list, b + a);
                        //print(list);
                        break;
                    case '-':
                        push(&list, b - a);
                        //print(list);
                        break;
                    case '*':
                        push(&list, b * a);
                        //print(list);
                        break;
                    case '/':
                        push(&list, b / a);
                        //print(list);
                        break;
                    default:
                        printf("Input Error\n");
                        error = 1;
                        break;
                }
                if(error == 1) break;
            }
        }
        if(error == 0) {
            if(list->next == NULL) {
                printf("%d\n", pop(&list));
            }
            else {
                printf("Input Error\n");
            }
        }

        free(list);
    }

    return 0;
}
