#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void inorder(Node* n_ptr) {
    if(n_ptr){
        inorder(n_ptr->left);
        printf("%c", n_ptr->data);
        inorder(n_ptr->right);
    }
}


void preorder(Node* n_ptr) {
    if(n_ptr) {
        printf("%c", n_ptr->data);
        preorder(n_ptr->left);
        preorder(n_ptr->right);
    }
}

void postOrder(Node* n_ptr) {
    if(n_ptr) {
        postOrder(n_ptr->left);
        postOrder(n_ptr->right);
        printf("%c", n_ptr->data);
    }
}


int main(){
    
    int num;
    while(scanf("%d", &num) != EOF) {
        int child[26][2] = {};
        Node* root = NULL;
        Node** nodes = NULL;
        nodes = (Node**)malloc(sizeof(Node*) * num);

        for(int i = 0; i < num; i++) {
            char data;
            scanf(" %c", &data);
            scanf("%d %d",  &child[i][0], &child[i][1]);

            nodes[i] = (Node*)malloc(sizeof(Node));
            nodes[i]->data = data;
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
        }
        for(int i = 0; i < num; i++) {
            int left = child[i][0] - 1;
            int right = child[i][1] - 1;
            if(left > 0) {
                nodes[i]->left = nodes[left];
            }
            if(right > 0) {
                nodes[i]->right = nodes[right];
            }
        }

        root = nodes[0];
        preorder(root);
        printf("\n");

        inorder(root);
        printf("\n");

        postOrder(root);
    }
    
    return 0;
}