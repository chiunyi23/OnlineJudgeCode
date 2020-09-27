
// #include <iostream>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// // #include<algorithm>
// using namespace std;
// #define inf 0x3f3f3f3f
// int n, m, x;
// int edge[1050][1050];
// int road[1050];
// int dis1[1050];
// int dis2[1050];
// int book[1050];
// bool cmp(int a, int b)
// {
//     return a > b;
// }

// void sort(int* begin, int* end, bool cmp) {
//     int i, key, j; 
//     int 
//    for (i = 1; i < n; i++) 
//    { 
//        key = arr[i]; 
//        j = i-1; 
//        while (j >= 0 && arr[j] > key) 
//        { 
//            arr[j+1] = arr[j]; 
//            j = j-1; 
//        } 
//        arr[j+1] = key; 
//    } 
// }

// int main()
// {
//     scanf("%d%d%d", &n, &m, &x);
//     int i, j, k;
//     int a, b, c;
//     for (i = 1; i <= n; i++)
//         for (j = 1; j <= n; j++)
//             if (i == j)
//                 edge[i][j] = 0;
//             else
//                 edge[i][j] = inf; //初始化

//     for (i = 1; i <= m; i++)
//     {
//         scanf("%d%d%d", &a, &b, &c);
//         if (edge[a][b] > c)
//             edge[a][b] = c;
//     }

//     for (i = 1; i <= n; i++)
//     {
//         dis1[i] = edge[x][i];
//     }
//     memset(book, 0, sizeof(book));
//     book[x] = 1;
//     int u, v;
//     for (i = 1; i <= n; i++)
//     {
//         int minn = inf;
//         for (j = 1; j <= n; j++)
//         {
//             if (book[j] == 0 && dis1[j] < minn)
//             {
//                 minn = dis1[j];
//                 u = j;
//             }
//         }
//         book[u] = 1;
//         for (j = 1; j <= n; j++)
//         {
//             if (book[j] == 0 && dis1[j] > dis1[u] + edge[u][j])
//             {
//                 dis1[j] = dis1[u] + edge[u][j];
//             }
//         }
//     }

//     int cnt;
//     for (i = 1; i <= n; i++)
//         for (j = i + 1; j <= n; j++)
//         {
//             cnt = edge[i][j];
//             edge[i][j] = edge[j][i];
//             edge[j][i] = cnt;
//         }

//     for (i = 1; i <= n; i++)
//         dis2[i] = edge[x][i];
//     memset(book, 0, sizeof(book));
//     book[x] = 1;
//     for (i = 1; i <= n; i++)
//     {
//         int minn = inf;
//         for (j = 1; j <= n; j++)
//         {
//             if (book[j] == 0 && dis2[j] < minn)
//             {
//                 minn = dis2[j];
//                 u = j;
//             }
//         }
//         book[u] = 1;
//         for (j = 1; j <= n; j++)
//         {
//             if (book[j] == 0 && dis2[j] > dis2[u] + edge[u][j])
//             {
//                 dis2[j] = dis2[u] + edge[u][j];
//             }
//         }
//     }
//     for (i = 1; i <= n; i++)
//         road[i] = dis1[i] + dis2[i];
//     // sort(road + 1, road + 1 + n, cmp);
//     printf("%d\n", road[1]);
//     return 0;
// }

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_V 1024
int d[MAX_V][MAX_V];	//	d[u][v]表示边e=(u,v)的权值，不存在的时候等于无穷大或者d[i][i] = 0
int V;					//	顶点数
 
void warshall_floyd()
{
	for (int k = 0; k < V; ++k)
	{
		for (int i = 0; i < V; ++i)
		{
			for (int j = 0; j < V; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	int M, X;
	cin >> V >> M >> X;
	--X;
	memset(d, 0x3f, V * MAX_V * sizeof(int));
	for (int i = 0; i < V; ++i)
	{
		d[i][i] = 0;
	}
	while (M--)
	{
		int A, B, T;
		cin >> A >> B >> T;
		--A;
		--B;
		d[A][B] = T;
	}
	warshall_floyd();
	int ans = 0;
	for (int i = 0; i < V; ++i)
	{
		ans = max(ans, d[i][X] + d[X][i]);
	}
	cout << ans << endl;
	return 0;
}