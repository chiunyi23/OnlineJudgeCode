#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* addNode(Node* n_ptr, int index, char element, int child) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = element;
    temp->left = NULL;
    temp->right = NULL;
    temp = addNode(temp, index+1, element, child);
    n_ptr->left = temp;
}

Node* createList(Node* root, char element, int child) {
    if(child == 0) 
        return;

    
}

int main(){
    
    int num;
    while(scanf("%d", &num) != EOF) {
        char element[26] = {};
        int child[26][2] = {};
        Node* root = NULL;

        for(int i = 0; i < num; i++) {
            scanf("%c %d %d", &element[i], child[i][0], child[i][1]);
        }
        root = createList(root, element, child);
    }
    
    return 0;
}