#include <cstdio>
using namespace std;
const int maxn = 15;
int mp[maxn][maxn];
const int inf = 0x3f3f3f3f;
int n, m;
int dij(int s, int t)
{ //套用迪傑斯特拉演算法的模板 不斷更新位置來確定最短路徑
    int dis[maxn], vis[maxn];
    for (int i = 1; i <= n; i++)
        dis[i] = inf, vis[i] = 0;
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = -1, min = inf;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && min > dis[j]) //vis[j]為0才能進行，也就是說每個點最終都會進行更新
                min = dis[k = j];        //每次挑選最小的dis的點繼續更新與之連通的其他點的dis,並標記k=-1;
            //min=dis[j],k=j;
        }
        if (k == -1)
            break; //全圖完成遍歷 退出 返回求出的最短路徑dis[t]
        vis[k] = 1;
        for (int j = 1; j <= n; j++)
            if (dis[j] > dis[k] + mp[k][j])
                dis[j] = dis[k] + mp[k][j]; //首次執行僅僅更新了與s連通的點的dis
    }
    return dis[t];
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                mp[i][j] = inf;
        }
        for (int i = 1; i <= m; i++)
        {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            mp[a][b] = mp[b][a] = w;
        }
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = dij(x, y);
        if (ans == inf)
        {
            printf("No path\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
}