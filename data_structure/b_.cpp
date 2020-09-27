#include <iostream>
#include <cstring>
#include <limits.h>
#define MAXN 1000
using namespace std;

int d[MAXN][MAXN];
int V;

void floyd()
{
    for(int k = 0; k < V; ++k)
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    int edge, target;
    cin >> V >> edge >> target;
    --target;
    memset(d, INT_MAX, V * MAXN * sizeof(int));
    for(int i = 0; i < V; i++)
        d[i][i] = 0;
    while(edge--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        --a;
        --b;
        d[a][b] = cost;
    }
    floyd();
    int sum = 0;
    for(int i = 0; i < V; ++i)
        sum = max(sum, d[i][target] + d[target][i]);

    cout << sum << endl;

    return 0;
}