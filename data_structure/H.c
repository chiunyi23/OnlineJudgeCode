#include <stdio.h>
#include <stdlib.h>

#define Stack_Size 4

typedef struct stack {
    int top;
    int max_size;
    int *data;
} Stack_t;

void create_stack(Stack_t *st, int size) {
    st->max_size = size - 1;
    st->top = -1;
    st->data = (int*)malloc(sizeof(int) * size);
}

unsigned int isEmpty(Stack_t *st) {
    if(st->top <= -1)   
        return 1; 
    return 0;    
}

unsigned int isFull(Stack_t *st) {
    if(st->top >= st->max_size)    
        return 1;
    return 0;
}

void push(Stack_t *st, int data) {
    if(isFull(st)) 
        return;
        // printf("Stack Full\n");
    else
        st->data[++st->top] = data;
}

int pop(Stack_t *st) {
    if(isEmpty(st))
        // printf("Stack Empty\n");
        return -1;
    else
        return st->data[st->top--];
}

void print(Stack_t *st) {
    for(int i = 0; i < st->top; i++) {
        printf("%d ", st->data[i]);
    }
    printf("%d\n", st->data[st->top]);
}

int main()
{
    int command;
    Stack_t stack;
    create_stack(&stack, Stack_Size);
    while(scanf("%d", &command) != EOF) {
        if(command == 1) {
            int data;
            scanf("%d", &data);
            if(isFull(&stack))
                printf("Stack Full\n");
            else {
                push(&stack, data);
                print(&stack);
            }
        }
        else {
            pop(&stack);
            if(isEmpty(&stack))
                printf("Stack Empty\n");
            else
                print(&stack);
        }
    }
    return 0;
}