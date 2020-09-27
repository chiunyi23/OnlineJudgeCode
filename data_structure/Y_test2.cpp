
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 105;
bool vis[MAXN][MAXN];
int dep[MAXN];
int n,m;
int w,l,sum;
// priority_queue<int,vector<int> >q;

/* 
void TopoSort(int n){
  for(int i=0;i<n;i++){
    if(!dep[i]){q.push(i);sum++;}            // 每入队一次sum就加1
  }
  while(!q.empty()){
    int ans = q.top();
    q.pop();
    for(int i=0;i<n;i++){
      if(vis[ans][i]){
        if(--dep[i]==0){
          q.push(i);
          sum++;
        }
      }
    }
  }
}
*/

void TopoSort(int n){
  int flag = -1;
  for(int i=0;i<n;i++){    // 因为编号为1-n
    for(int j=0;j<n;j++){
      if(dep[j] == 0){      // 找到入度为0的点
        sum++;
        printf("%d%c",j,i == n? '\n' : ' ');     // 输出
        flag = j;           // 标记这个点
        dep[j]--;           // 将其入度-1
        break;              // 跳出循环进入下一个循环
      }
    }
    if(flag >= 0) {
        for(int j=0;j<n;j++){  // 寻找被flag打败的点
            if(vis[flag][j]){     // 如果flag把j打败了
                vis[flag][j] = false;   // 标记找到过
                dep[j]--;           // j入度-1
            }
        }
    }
    
  }
}

int main()
{
  while(scanf("%d%d",&n,&m)!=EOF){
    if(n==0) break;
    memset(vis,0,sizeof(vis));
    memset(dep,0,sizeof(dep));
    for(int i=0;i<m;i++){
      scanf("%d%d",&w,&l);
      if(!vis[w][l]){
        vis[w][l] = 1;
        dep[l]++;
      }
    }
    sum = 0;
    TopoSort(n);
    if(sum==n) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}