#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* addNode(Node* root, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;

    if(root == NULL) {
        return temp;
    }   

    Node* current = root;
    while(current != NULL) {
        if(temp->data >= current->data) {
            if(current->right == NULL) {
                current->right = temp;
                return root;
            }
            else {
                current = current->right;
            }
        }
        else {
            if(current->left == NULL) {
                current->left = temp;
                return root;
            }
            else {
                current = current->left;
            }
        }
    }
}

void inorderTraversal(Node* root) {
    if(root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if(root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int num;
    int data;
    Node* root = NULL;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &data);
        root = addNode(root, data);
    }
    // printf("%d\n", root->data);
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);

    return 0;
}