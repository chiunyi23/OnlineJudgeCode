// #include<cstdio>
// using namespace std;
// int f[1000001];
// int father(int i)
// {
// 	if (f[i]!=i) f[i]=father(f[i]);
// 	return f[i];
// }
// int main()
// {
// 	int i,j,n,m,s,x1,y1,x2,y2,p,q;
	
// 	scanf("%d%d",&m,&n);
// 	s=0;
// 	for (i=1;i<=n*m;i++) f[i]=i;
// 	while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4)
// 	{
// 		p=father((x1-1)*n+y1); q=father((x2-1)*n+y2);
// 		if (p!=q) f[q]=p;
// 	}
// 	for (i=1;i<=n;i++)//先纵后横因为纵向权值小
// 		for (j=1;j<m;j++)
// 		{
// 			p=father((j-1)*n+i);
// 			q=father(j*n+i);
// 			if (p!=q) {f[q]=p; s++;}
// 		}
// 	for (i=1;i<=m;i++)
// 		for (j=1;j<n;j++)
// 		{
// 			p=father((i-1)*n+j);
// 			q=father((i-1)*n+j+1);
// 			if (p!=q) {f[q]=p; s+=2;}
// 		}
// 	printf("%d",s);
// 	return 0;

// }


#include<cstdio>
using namespace std;
int f[1001];
int father(int i)
{
	if (f[i]!=i) f[i]=father(f[i]);
	return f[i];
}
int main()
{
	int i,j,n,m,s,x1,y1,x2,y2,p,q;
	
	scanf("%d%d",&m,&n);
	s=0;
	for (i=1;i<=n*m;i++) f[i]=i;
	while (scanf("%d%d%d%d",&x1,&y1,&x2,&y2)==4)
	{
		p=father((x1-1)*n+y1); q=father((x2-1)*n+y2);
		if (p!=q) f[q]=p;
	}
	for (i=1;i<=n;i++)
		for (j=1;j<m;j++)
		{
			p=father((j-1)*n+i);
			q=father(j*n+i);
			if (p!=q) {f[q]=p; s++;}
		}
	for (i=1;i<=m;i++)
		for (j=1;j<n;j++)
		{
			p=father((i-1)*n+j);
			q=father((i-1)*n+j+1);
			if (p!=q) {f[q]=p; s+=2;}
		}
	printf("%d",s);
	return 0;

}