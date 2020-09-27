#include <stdio.h>
#include <limits.h>
int main()
{
    int vertex, edge;
    while(~scanf("%d %d", &vertex, &edge)) {
        int root_check[100] = {0};
        int node[100][101] = {0};
        int father, child;
        for(int i = 0; i < edge; i++) {
            scanf("%d %d", &father, &child);
            root_check[father]++;
            root_check[child] = INT_MIN;
            int current_child = ++node[father][0];
            node[father][current_child] = child;
        }


        int max_vertex = 1;
        for(int i = 1; i < vertex; i++) {
            if(root_check[i] > 0) {
                printf("%d\n", i);
            }
            if(node[i][0] >= node[max_vertex][0]) {
                max_vertex = i;
            }
        }
        printf("%d\n", max_vertex);
        for(int i = 1; i <= node[max_vertex][0]; i++) {
            printf("%d ", node[max_vertex][i]);
        }
        printf("\n");
    }

    return 0;
}