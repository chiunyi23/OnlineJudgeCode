 /*
 qq:1239198605
 ctgu_yyf
        */
 
#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int inf=99999;
int map[105][105],dis[105],vis[105];
int c,n,m; 
void prime(int x)
{
	memset(vis,0,sizeof(vis));
	vis[x]=1;
 
	
	for(int i=1;i<=m;i++)
	dis[i]=map[x][i];
    
	dis[x]=0; 
	
	for(int i=1;i<=m;i++)
	{
		if(i==x)
		continue;
		
		int min=inf;
		int u=-1;
		for(int j=1;j<=m;j++)
		{
			if(dis[j]<min&&vis[j]==0)
			{
				min=dis[j];
				u=j;
			}
		}
		if(u==-1)
		break;
		
		vis[u]=1;
		dis[u]=min;
		
		for(int z=1;z<=m;z++)
		if(vis[z]==0&&dis[u]+map[u][z]<dis[z])
		{
			dis[z]=dis[u]+map[u][z];
		}
			
	}
		
}
 
 
int main()
{
   ios::sync_with_stdio(false);
   
   int v1,v2,h;
   while(cin>>c>>n>>m)
   {
   	int flag=0;
   	for(int i=1;i<=m;i++)
   	for(int j=1;j<=m;j++)
   	map[i][j]=inf;
   	
   	
   	
   	for(int i=0;i<n;i++)
   	{
	   cin>>v1>>v2>>h;
	   map[v1][v2]=min(map[v1][v2],h);
	   map[v2][v1]=min(map[v2][v1],h);
   }
   
   prime(1);
   
   int ans=0;
   for(int i=1;i<=m;i++)
   {
   //	cout<<"**"<<dis[i]<<endl;
   	
   	if(dis[i]==inf)
   	flag=1;
   	ans=ans+dis[i];
   }
   
 //  cout<<"**"<<ans<<endl;
   
   
   if(ans>c)
   flag=1;
   
   if(flag==0)
   cout<<"Yes"<<endl;
   
   else
   cout<<"No"<<endl;
   	
   	
   }
return 0;
}
