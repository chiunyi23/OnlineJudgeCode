#include <stdio.h>
#include <stdbool.h>

bool graph[100][100];
int edges_each_node[100];
int vertice, edge;

bool topological() {
    for(int i = 0; i < vertice; i++) {
        int s = 0;
        while(s < vertice && edges_each_node[s] != 0)
            s++;
        if(s == vertice) return false;

        printf("%d ", s);
        edges_each_node[s] = -1;
        for(int j = 0; j < vertice; j++)
            if(graph[s][j])
                edges_each_node[j]--;
    }
    return true;
}

int main()
{
    int v1, v2;
    while(~scanf("%d %d", &vertice, &edge)) {
        if(vertice == 0)    break;
        for(int i = 0; i < vertice; i++) {
            edges_each_node[i] = 0;
            for(int j = 0; j < vertice; j++) {
                graph[i][j] = 0;
            }
        }
        for(int i = 0; i < edge; i++) {
            scanf("%d %d", &v1, &v2);
            if(!graph[v1][v2]) {
                graph[v1][v2] = 1;
                edges_each_node[v2]++;
            }
            
        }
        for(int i = 0; i < vertice; i++)
            printf("%d ", edges_each_node[i]);
        printf("\n");
    
        bool is_legal = topological();
        if(is_legal) 
            printf("YES\n");
        else
            printf("NO\n");
        }
    return 0;
}