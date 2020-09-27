#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} node_t;

int height(node_t* node) {
    int height_left = 0;
    int height_right = 0;
    if(node == NULL)
        return 0;
    if(height_left)
        height_left = height(node->left);
    if(height_right)
        height_right = height(node->right);
    return height_left > height_right ? ++height_left : ++height_right;
}

int balance_factor(node_t* node) {
    return height(node->left) - height(node->right);
}

node_t* create(int key) {
    node_t* node = NULL;
    node = (node_t*)malloc(sizeof(node_t));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t* leftRotate(node_t* node) {
    node_t *y = node->right;
    node_t *x = y->left;
    y->left = node;
    node->right = x;
    return y;
}

node_t* rightRotate(node_t* node) {
    node_t *x = node->left;
    node_t *y = x->right;
    return x;
}


node_t* insert(node_t* node, int key) {
    if(node == NULL)
        return create(key);
    if(key > node->key)
        node->right = insert(node->right, key);
    else if(key < node->key)
        node->left = insert(node->left, key);
    else
        return node;
    
    // rotation
    int balance = balance_factor(node);
    // printf("%d ", balance);
    //Left-Left
    if(balance > 1 && key < node->left->key)
        return leftRotate(node);
    // Right-Right
    if(balance < -1 && key > node->right->key)
        return rightRotate(node);
    // Left-Right
    if(balance > 1 && key > node->left->key) {
        node->left = leftRotate(node);
        return rightRotate(node->left);
    }
    if(balance < -1 && key < node->right->key) {
        node->right = rightRotate(node);
        return leftRotate(node->right);
    }
    return node;
}

void inorder(node_t* node) {
    if(node == NULL) 
        return;
    
    inorder(node->left);
    // printf("%d ", node->key);
    inorder(node->right);
}

int flag = 0;
void search(node_t* node, int key) {
    if(node == NULL) 
        return;
    search(node->left, key);
    // printf("%d ", node->key);
    if(key == node->key) {
        flag = 1;
    }
    search(node->right, key);
}

int main()
{
    int key;
    int node_num, search_num;
    while(~scanf("%d %d", &node_num, &search_num)) {
        node_t* root = NULL;
        for(int i = 0; i < node_num; i++) {
            scanf("%d", &key);
            root = insert(root, key);
            // inorder(root);
            // printf("\n");
        }

        int s;
        for(int i = 0; i < search_num; i++) {
            flag = 0;
            scanf("%d", &s);
            // inorder(root);
            search(root, s);
            printf("%d ", flag);
        }
        printf("\n");
    }
    return 0;
}