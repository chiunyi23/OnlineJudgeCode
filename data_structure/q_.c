#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int weight;
    struct Node* left;
    struct Node* right;
} node_t;

typedef struct Table {
    node_t* node;
    struct Table* next;
} table_t;

node_t* create_node(int weight) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
}

table_t* insert(table_t* head, int weight) {
    node_t* node = create_node(weight);
    if(head == NULL) {
        table_t* table = (table_t*)malloc(sizeof(table_t));
        table->node = node;
        table->next = NULL;
        return table;
    }

    // insert into table in order
    table_t* current = head;
    table_t* prev = current;
    while(current != NULL) {
        if(weight < current) {

        }
    }

}

table_t* build_huffman(table_t* head) {
    table_t* current = head;
    int weight1, weight2;
    while(current->next != NULL) {
        weight1 = dequeue(current);
        weight2 = dequeue(current);
        enqueue(current, weight1 + weight2);
    }
    return head;
}

int main()
{
    int num;
    while(~scanf("%d", &num)) {
        int weight;
        table_t* head = NULL;
        for(int i = 0; i < num; i++) {
            scanf("%d", &weight);
            head = insert(head, weight);
        }
        head = build_huffman(head);
        int sum = count_weight(head);
        printf("%d\n", sum);
    }


    return 0;
}