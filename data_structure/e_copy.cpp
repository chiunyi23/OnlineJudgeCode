
#include <cstdio>
struct ftv
{
       long i;
       long f;
       long t;
       double v;
};

const long oo = 0x7fff0000;
long fa[3002];
ftv h[3002];
bool used[3002];
long size = 0;
long n;long m;

long getroot(long a)
{
       if(fa[a]==a) return a;
       return fa[a]=getroot(fa[a]);
}

void merge(long a,long b)
{
       fa[getroot(a)]=getroot(b);
}
void swap(long a,long b)
{
       ftv tmp = h[a];
       h[a]= h[b];
       h[b]= tmp;
}
void adjust_up(long l)

{
       if(l<=1) return;
       while(l>1)
       {
              if(h[l>>1].v>h[l].v)
                     swap(l>>1,l);
              else
                     break;
              l>>=1;
       }
}
void insert(long i,long a,long b,double c)
{
       size++;
       h[size].i=i;
       h[size].f=a;
       h[size].t=b;
       h[size].v=c;
       adjust_up(size);
}

void adjust_down(long l)

{
       if(l>=size) return;

       while((l<<=1)<=size)
       {
              if(l<size&&h[l].v>h[l+1].v)l++;

              if(h[l].v<h[l>>1].v) swap(l,l>>1);

              else break;
       }
}
ftv del()
{
       ftv tmp = h[1];
       h[1]= h[size];
       h[size]= tmp;
       size--;
       adjust_down(1);
       return tmp;
}

int main()
{
       scanf("%ld%ld",&n,&m);
       for(long i=1;i<m+1;i++)
       {
              double tot = 0;
              long a;long b;double c;
              scanf("%ld %ld %lf",&a,&b,&c);
              insert(i,a,b,c);
              for(long j=1;j<n+1;j++){fa[j] = j;}
              for(long j=1;j<size+1;j++){used[j]=false;}
              long size_u = size;
              for(long j=1;j<size_u+1;j++)
              {
                     ftv ths = del();
                     if(getroot(ths.f)!=getroot(ths.t))
                     {
                            used[ths.i]= true;
                            merge(ths.f,ths.t);
                            tot+=double(ths.v);
                     }
              }
              for(long i=size_u;i>size;i--)
              {
                     adjust_up(i);
              }
              size=size_u;
              //堆删除之后恢复原来的结构
              bool bad = false;
              long root = getroot(1);
              for(long j=2;j<n+1;j++)
              {
                     if(getroot(j)!=root)
                     {
                            bad= true;
                            break;
                     }
              }
              if(!bad)
              {
                     printf("%.2lf",tot/double(2));
                     for(long j=1;j<size+1;j++)
                            if(used[j])
                                   printf(" %ld",j);
                     printf("\n");
              }
              else
                printf("0\n");
       }
       return 0;
}

// #include <stdio.h>
// #define MAX 1005
// struct node
// {
//        int u;
//        int v;
//        int w;
// };
// int f[MAX];
// int count = 0, sum = 0;
// struct node e[3 * MAX];
// void quicksort(int left, int right)
// {
//        if (left > right)
//               return;
//        int i = left;
//        int j = right;
//        struct node temp;
//        while (i != j)
//        {
//               while (e[j].w >= e[left].w && i < j)
//                      j--;
//               while (e[i].w <= e[left].w && i < j)
//                      i++;
//               if (i < j)
//               {
//                      temp = e[i];
//                      e[i] = e[j];
//                      e[j] = temp;
//               }
//        }
//        temp = e[i];
//        e[i] = e[left];
//        e[left] = temp;
//        quicksort(left, i - 1);
//        quicksort(i + 1, right);
//        return;
// }
// int getf(int v)
// {
//        if (f[v] == v)
//               return v;
//        else
//               f[v] = getf(f[v]);
//        return f[v];
// }
// int merge(int v, int u)
// {
//        int t1 = getf(v);
//        int t2 = getf(u);
//        if (t1 != t2)
//        {
//               f[t2] = t1;
//               return 1;
//        }
//        return 0;
// }
// int main()
// {
//        int n, m;
//        scanf("%d", &n);
//        scanf("%d", &m);
//        for (int i = 1; i <= m; ++i)
//        {
//               scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
//        }
//        quicksort(1, m);
//        for (int i = 1; i <= n; ++i)
//        {
//               f[i] = i;
//        }
//        for (int i = 1; i <= m; ++i)
//        {
//               if (merge(e[i].u, e[i].v))
//               {
//                      count++;
//                      sum = sum + e[i].w;
//               }
//               if (count == n - 1)
//                      break;
//        }
//        if (count != n - 1)
//               printf("-1\n");
//        else
//               printf("%d\n", sum);
//        return 0;
// }


