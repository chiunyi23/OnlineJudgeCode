#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    Tree* child;
} Tree;

int find(int parent[], int data, int size) {
    for(int i = 0; i < size; i++) {
        if(parent[i] == data) {
            return 1;
        }
    }
    return 0;
}



int main()
{
    int node, edge;
    while(scanf("%d %d", &node, &edge) != EOF) {
        Tree** treeRoot = NULL;
        int rootCounter = 0;
        int parent;
        int child;
        for(int i = 0; i < edge; i++) {
            scanf("%d %d", &parent, &child);
            
        }
    }

    return 0;
}