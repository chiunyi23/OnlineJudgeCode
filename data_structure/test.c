#include <stdio.h>
#include <stdbool.h>

bool adj[9][9];
bool visit[9];
 
void DFS(int i)
{
    visit[i] = true;
    printf("%d ", i + 1);
    for (int j=0; j<9; j++)
        if (adj[i][j] && !visit[j])
            DFS(j);
}
 
void traversal()
{
    for (int i=0; i<9; i++)
        visit[i] = false;
 
    for (int i=0; i<9; i++)
        if (!visit[i])
            DFS(i);
}

int main()
{
    traversal();
    return 0;
}