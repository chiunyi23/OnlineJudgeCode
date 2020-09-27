#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tree {
    char alpha;
    struct Tree *child, *siblings;
} tree_t;

tree_t* create_node(char ch) {
    tree_t* node = (tree_t*)malloc(sizeof(tree_t));
    node->alpha = ch;
    node->child = NULL;
    node->siblings = NULL;
    return node;
}

tree_t* insert_word(tree_t* root, char word[]) {
    tree_t* head = root;
    for(int i = 0; i < strlen(word); i++) {
        if(head->child == NULL) {
            head->child = create_node(word[i]);
            head = head->child;
            continue;
        }
        tree_t* node = head->child;
        bool is_found = false;
        while(node != NULL) {
            if(node->alpha == word[i]) {
                is_found = true;
                head = node;
                break;
            }
            node = node->siblings;
        }
        if(!is_found) {
            tree_t* new_node = create_node(word[i]);
            new_node->siblings = head->child;
            head->child = new_node;
            head = head->child;
        }
    }
    return root;
}

int counter = 0;
void show(tree_t* head) {
    if(head == NULL)
        return;
    tree_t* current = head;
    while(current != NULL) {
        printf("%c ", current->alpha);
        counter++;
        show(current->child);    
        current = current->siblings;
    }
}

int main()
{
    char word[64];
    tree_t* word_tree = create_node('\0');
    while(~scanf("%s", word)) {
        insert_word(word_tree, word);
    }

    show(word_tree);
    printf("%d\n", counter);
    // tree_t* current = word_tree->child;
    // word_tree = word_tree->child;
    // int counter = 1;
    // while(word_tree) {
    //     current = word_tree;
    //     while(current) {
    //         printf("%c ", current->alpha);
    //         current = current->child;
    //     }
    //     printf("word_tree: %c\n", word_tree->alpha);
    //     word_tree = word_tree->siblings;
    // }

    return 0;
}