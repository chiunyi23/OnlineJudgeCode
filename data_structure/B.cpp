#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct Node {
    int term_num;
    int pow_num;
    struct Node* next;
} node_t;

node_t* create(int term, int pow) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->term_num = term;
    new_node->pow_num = pow;
    new_node->next = NULL;
    return new_node;
}

node_t* insert(node_t* front, int term, int pow) {
    node_t* new_node = create(term, pow);
    if(front == NULL) {
        return new_node;
    }
    node_t *current = front;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return front;
}

node_t* data_linker(char input[], node_t* front) {
    int term_num, pow_num;
    char *pch;
    pch = strtok(input, " ");
    while(pch != NULL) {
        term_num = atoi(pch);
        pch = strtok(NULL, " ");
        pow_num = atoi(pch);
        pch = strtok(NULL, " ");
        front = insert(front, term_num, pow_num);
        // printf("%d %d\n", term_num, pow_num);
    }
    return front;
}

node_t* insert_poly(node_t* result, node_t* origin) {
    node_t* current = result;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = origin;
    return result;
}

void show_poly(node_t* front) {
    while(front != NULL) {
        if(front->term_num != 0)
            printf("%d %d ", front->term_num, front->pow_num);
        front = front->next;
    }
}

int main()
{
    char input[300];
    char *pch;
    int term_num, pow_num;
    

    while(gets(input) != 0) {
        node_t *poly1 = NULL, *poly2 = NULL;
        poly1 = data_linker(input, poly1);
        gets(input);
        poly2 = data_linker(input, poly2);
        node_t* result = NULL;
        while(poly1 != NULL || poly2 != NULL) {
            if(poly1 == NULL) {
                result = insert_poly(result, poly2);
                break;
            }
            else if(poly2 == NULL){
                result = insert_poly(result, poly1);
                break;
            }
            else {
                if(poly1->pow_num > poly2->pow_num) {
                    result = insert(result, poly1->term_num, poly1->pow_num);
                    poly1 = poly1->next;
                }
                else if(poly1->pow_num < poly2->pow_num) {
                    result = insert(result, poly2->term_num, poly2->pow_num);
                    poly2 = poly2->next;
                }
                else {
                    result = insert(result, poly1->term_num + poly2->term_num, poly1->pow_num);
                    poly1 = poly1->next;
                    poly2 = poly2->next;
                }
            }
        }
        show_poly(result);
        printf("\n");
    }

    return 0;
}