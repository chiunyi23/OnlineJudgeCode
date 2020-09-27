#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    char gender;
    struct stack *next;
} Stack_t;

Stack_t* newNode(char gender) {
    Stack_t* node = (Stack_t*)malloc(sizeof(Stack_t));
    node->gender = gender;
    node->next = NULL;
    return node;
}

unsigned int isEmpty(Stack_t* st) {
    return (st == NULL);
}

void push(Stack_t** st, char gender) {
    Stack_t* node  = newNode(gender);
    node->next = *st;
    *st = node;
}

char pop(Stack_t** st) {
    if(isEmpty(*st)) {
        printf("the stack is empty!\n");
        return '\0';
    }
    Stack_t* temp = *st;
    *st = (*st)->next;
    char popped = temp->gender;
    free(temp);

    return popped;
}
/*
void print(Stack_t* st) {
    Stack_t* current = st;
    while(current != NULL) {
        printf("%c\n", current->gender);
        current = current->next;
    }
}
*/
int main()
{
    int num;
    Stack_t *test = NULL;
    
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        Stack_t* pair = NULL;
        char list[257];

        scanf("%s", list);
        int counter = 0;
        for(int j = 0; list[j] != '\0'; j++) {
            if(list[j] == '.')
                continue;
            if(list[j] == 'B') {
                push(&pair, list[j]);
            }
            else {
                if(isEmpty(pair)) {
                    push(&pair, list[j]);
                    continue;
                }
                if(pair->gender == 'B') {
                    pop(&pair);
                    counter++;
                }
                else{
                    push(&pair, list[j]);
                }
            }
        }
        printf("%d\n", counter);
        free(pair);
    }

    return 0;
}