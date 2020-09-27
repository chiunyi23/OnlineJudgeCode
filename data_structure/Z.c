#include <stdio.h>
#include <stdbool.h>

bool graph[100][100];
bool vistited[100];
int vertice, edge;

void DFS(int i, bool graph[][100]) {
    vistited[i] = 1;
    printf("%d ", i + 1);
    for(int j = 0; j < vertice; j++) {
        if(graph[i][j] && !vistited[j]) {
            DFS(j, graph);
        }
    }
}

void traversal(bool graph[][100]) {
    for(int i = 0; i < vertice; i++)
        vistited[i] = 0;
    DFS(0, graph);
}

int main()
{
    while(scanf("%d %d", &vertice, &edge) != EOF) {
        int n1, n2; 
        for(int i = 0; i < edge; i++) {
            scanf("%d %d", &n1, &n2);
            graph[n1 - 1][n2 - 1] = 1;
            graph[n2 - 1][n1 - 1] = 1;
        }
        traversal(graph);
        printf("\n");
    }

    return 0;
}