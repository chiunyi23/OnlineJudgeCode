
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

class QueueArraySequential{
private:
    int capacity, front, back;
    int *queue;
    void DoubleCapacity();
public:
    QueueArraySequential():capacity(5),front(-1),back(-1){
        queue = new int[capacity];
    };
    void Push(int x);
    void Pop();
    bool IsEmpty();
    bool IsFull();
    int getFront();
    int getBack();
    int getSize();
    int getCapacity();    // 驗證用, 可有可無
};

void QueueArraySequential::DoubleCapacity(){

    capacity *= 2;
    int *newQueue = new int[capacity];

    int j = -1;
    for (int i = front+1; i <= back; i++) {
        j++;
        newQueue[j] = queue[i];
    }
    front = -1;       // 新的array從0開始, 把舊的array"整段平移", front跟back要更新
    back = j;
    delete [] queue;
    queue = newQueue;
}
void QueueArraySequential::Push(int x){

    if (IsFull()) {
        DoubleCapacity();
    }
    queue[++back] = x;
}
void QueueArraySequential::Pop(){

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return;
    }
    front++;        
}
bool QueueArraySequential::IsFull(){

    return (back + 1 == capacity);
}
bool QueueArraySequential::IsEmpty(){

    return (front  == back);
}
int QueueArraySequential::getFront(){

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return queue[front+1];
}
int QueueArraySequential::getBack(){

    if (IsEmpty()) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    return queue[back];
}
int QueueArraySequential::getSize(){

    return (back - front);
}
int QueueArraySequential::getCapacity(){

    return capacity;
}

struct node
{
    int from;
    int to;
    int w;
    int f;
    int num;
    int next;
}e[400000];
int head[10000];
int vis[10000];
int dis[10000];
int pre[10000];
int path[10000];
int n,m,kk,cont,ss,tt;
void add(int from,int to,int f,int w)
{
    e[cont].to=to;
    e[cont].f=f;
    e[cont].w=w;
    e[cont].num=cont;
    e[cont].next=head[from];
    head[from]=cont++;
}
void Getmap()
{
    ss=n*2+1;
    tt=ss+1;
    cont=0;
    memset(head,-1,sizeof(head));
    add(ss,1,0x3f3f3f3f,0);
    add(1,ss,0,0);
    add(n*2,tt,0x3f3f3f3f,0);
    add(tt,n*2,0,0);
    for(int i=1;i<=n;i++)
    {
        if(i==1||i==n)
        {
            add(i,i+n,0x3f3f3f3f,0);
            add(i+n,i,0,0);
            continue;
        }
        add(i,i+n,1,0);
        add(i+n,i,0,0);
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x+n,y,0x3f3f3f3f,1);
        add(y,x+n,0,-1);
    }
}
int SPFA()
{
    for(int i=1;i<=tt;i++)dis[i]=0x3f3f3f3f;
    memset(vis,0,sizeof(vis));
    dis[ss]=0;
    QueueArraySequential s;
    s.Push(ss);
    while(!s.IsEmpty())
    {
        int u=s.getFront();
        s.Pop();vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            int f=e[i].f;
            int w=e[i].w;
            if(f&&dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pre[v]=u;
                path[v]=e[i].num;
                if(vis[v]==0)
                {
                    vis[v]=1;
                    s.Push(v);
                }
            }
        }
    }
    if(dis[tt]<=kk)return 1;
    else return 0;
}
void MCMF()
{
    int maxflow=0;
    while(SPFA()==1)
    {
        int minn=0x3f3f3f3f;
        for(int i=tt;i!=ss;i=pre[i])
        {
            minn=min(minn,e[path[i]].f);
        }
        for(int i=tt;i!=ss;i=pre[i])
        {
            e[path[i]].f-=minn;
            e[path[i]^1].f+=minn;
        }
        maxflow+=minn;
    }
    printf("%d\n",maxflow);
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&kk))
    {
        if(n==0&&m==0&&kk==0)break;
        Getmap();
        MCMF();
    }
    return 0;
}
