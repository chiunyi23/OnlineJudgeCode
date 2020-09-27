#include <iostream>
using namespace std;
#define	 0x3f3f3f3f
int n,m,e[520][520];                      //n表示顶点的个数，m表示边的条数，e存储两顶点的花费
void prim()
{
	int dis[520],book[520]={0};       //所有顶点初始化为未走过
	for (int i=0;i<n;i++)
	    dis[i]=e[0][i];               //初始化dis数组，0号顶点到各个顶点的距离
	book[0]=1;                        //0号顶点已经走过（将0号顶点加入生成树）
	int minn,sum=0,u;                
	for (int i=0;i<n-1;i++)           //把剩下n-1个点加入生成树中
	{
		minn=inf;
		for (int j=0;j<n;j++)
		{
			if (!book[j]&&dis[j]<minn)     //找到生成树中的点到其它点的最短距离
			{
				minn=dis[j];
				u=j;                   //标记一下是哪个点
			}
		}
		book[u]=1;sum+=dis[u];                 //标记为走过，和加上这个距离
		for (int j=0;j<n;j++)
		{
			if (!book[j]&&dis[j]>e[u][j]) dis[j]=e[u][j];
		}                   //扫描当前顶点J的所有边，更新生成树到每一个非定点树的距离
	}
	cout<<sum<<endl;
}
int main ()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		int u,v,w;
		for (int i=0;i<n;i++)             //初始化
		    for (int j=0;j<n;j++)
		    {
		    	if (i==j) e[i][j]=0;
		    	else e[i][j]=inf;
		    }                       
		for (int i=0;i<m;i++)             //读入边
		{
			cin>>u>>v>>w;
			e[u][v]=w;
			e[v][u]=w;                //无向图，将边反向再存一遍
		}
		prim();
	}
	return 0;
}