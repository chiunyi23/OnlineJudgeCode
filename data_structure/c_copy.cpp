#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define inf 1000000000
int n,m,q,dis[301][301];

int read()
{
    int w=0,c=1; char ch=getchar();
    while (ch<'0' || ch>'9')
      {
        if (ch=='-') c=-1;
        ch=getchar();
      }
    while (ch>='0' && ch<='9')
      w=w*10+ch-'0',ch=getchar();
    return w*c;
}

void floyed()
{
    int i,j,k;
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          dis[i][j]=min(max(dis[i][k],dis[k][j]),dis[i][j]);
}

int main()
{
    int i,x,y,z;
    memset(dis,127,sizeof(dis));
    n=read(),m=read(),q=read();
    for (i=1;i<=m;i++)
      x=read(),y=read(),z=read(),dis[x][y]=min(dis[x][y],z);
    floyed();
    for (i=1;i<=q;i++)
      {
        x=read(),y=read();
        if (dis[x][y]<inf) printf("%d\n",dis[x][y]);
        else printf("%d\n",-1);
      }
    return 0;
}