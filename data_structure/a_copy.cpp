#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
    int x,y,w,next;
};
struct status
{
    int x,k,dis;
    friend bool operator<(status a,status b)
    {
    return a.dis>b.dis;       
    }
};
priority_queue<status>q;
edge e[100101];
bool v[50101][101];
int dis[50101][101],ls[100101];
int maxE=0;
void add(int x,int y,int w)
{
    e[++maxE]=(edge){x,y,w,ls[x]};
    ls[x]=maxE;
}
int main()
{
    int n,m,k,st,ed;
    scanf("%d%d%d",&n,&m,&k);
    //scanf("%d%d",&st,&ed);
   // cout<<"  @@"<<n<<"   "<<m<<"   "<<k;
    st++;ed=n;
    for (int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
       // x++;y++;
      // cout<<x<<"  "<<y<<"   @@@"<<w<<endl;
        add(x,y,w);
        add(y,x,w);
    }
    st=1;ed=n;
    
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            dis[i][j]=1<<31-1;
            
    dis[st][0]=0;
    status o;
    o.x=st;
    o.k=0;
    o.dis=0;
    //{st,0,0}
    q.push(o);
    //cout<<q.empty()<<"   ((("<<endl; 
    v[st][0]=true;
    
    
    while (!q.empty())
    {
          
        status s=q.top();
        int now=s.x;
        int tmp=s.k;
        int jh=s.dis; 
        //cout<<"  "<<now<<"  !!!"<<tmp<<"   @@@"<<jh;
        q.pop();
        for (int i=ls[now];i;i=e[i].next)
        {
            if (e[i].w+dis[now][tmp]<dis[e[i].y][tmp])
            {
            
                dis[e[i].y][tmp]=e[i].w+dis[now][tmp];
                //cout<<"  "<<"***"<<dis[e[i].y][tmp]<<endl;
                if (!v[e[i].y][tmp])
                {
                    v[e[i].y][tmp]=true;
                    q.push((status){e[i].y,tmp,dis[e[i].y][tmp]});
                }
                
            }
            if (dis[now][tmp]<dis[e[i].y][tmp+1]&&tmp<k)
            {
            
                dis[e[i].y][tmp+1]=dis[now][tmp];
                if (!v[e[i].y][tmp+1])
                {
                    v[e[i].y][tmp+1]=true;
                    q.push((status){e[i].y,tmp+1,dis[e[i].y][tmp+1]});
                }
                 
        }    
    }
    v[now][tmp]=false;
    }
    //cout<<ed<<"  @@@"<<endl;
    int ans=1<<31-1;
    for (int i=0;i<=n;i++)
        {
        if(dis[ed][i]<ans)
        {
        ans=dis[ed][i];
        //cout<<
        }
}
    printf("%d\n",ans);
    return 0;
}