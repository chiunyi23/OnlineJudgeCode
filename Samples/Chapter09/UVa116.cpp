// UVa116 Unidirectional TSP
// Rujia Liu
// 演算法：多段圖的動態規劃。因為要字典序最小，所以倒著來，設d[i][j]為從(i,j)到最後一列的最小花費，則d[i][j]=a[i][j]+max(d[i+1][j+1],d[i-1][j+1])
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100 + 5;
const int INF = 1000000000;
int m, n, a[maxn][maxn], d[maxn][maxn], next[maxn][maxn];

int main() {
  while(scanf("%d%d", &m, &n) == 2 && m) {
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        scanf("%d", &a[i][j]);

    int ans = INF, first = 0;
    for(int j = n-1; j >= 0; j--) {
      for(int i = 0; i < m; i++) {
        if(j == n-1) d[i][j] = a[i][j];
        else {
          int rows[3] = {i, i-1, i+1};
          if(i == 0) rows[1] = m-1;
          if(i == m-1) rows[2] = 0;
          sort(rows, rows+3);
          d[i][j] = INF;
          for(int k = 0; k < 3; k++) {
            int v = d[rows[k]][j+1] + a[i][j];
            if(v < d[i][j]) { d[i][j] = v; next[i][j] = rows[k]; }
          }
        }
        if(j == 0 && d[i][j] < ans) { ans = d[i][j]; first = i; }
      }
    }
    printf("%d", first+1);
    for(int i = next[first][0], j = 1; j < n; i = next[i][j], j++) printf(" %d", i+1);
    printf("\n%d\n", ans);
  }
  return 0;
}