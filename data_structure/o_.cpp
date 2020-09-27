
// //二分查找（625ms）
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <memory.h>
// #include <cstring>
// using namespace std;
// #define N 100010
// int cnt;
 
// struct DIC
// {
// 	char a[25];
// 	char b[85];
// }d[2][N];
 
// int comp1(const void *a,const void *b)
// {
// 	struct DIC *A=(DIC*) a;
// 	struct DIC *B=(DIC*)b;
// 	return strcmp(A->a,B->a);
// }
 
// int comp2(const void *a,const void *b)
// {
// 	struct DIC *A=(DIC*) a;
// 	struct DIC *B=(DIC*)b;
// 	return strcmp(A->b,B->b);
// }
 
// void Search(char*s, int dicset,int l,int r)
// {
// 	int i;
// 	int m=(l+r)>>1;
// 	if(dicset==1)
// 	{	
// 		while(l<=r)
// 		{
// 			m=(l+r)>>1;
// 			if(strcmp(s,d[1][m].b)==0)
// 			{	
// 				for(i=1;i<strlen(d[1][m].a)-1;i++)
// 					printf("%c",d[1][m].a[i]);
// 				cout<<endl;
// 				return;
// 			}
// 			else if(strcmp(s,d[1][m].b)>0)
// 				l=m+1;
// 			else 
// 				r=m-1;
// 		}
// 		puts("what?");
// 		return ;
// 	}
// 	else if(dicset==0)
// 	{	
// 		while(l<=r)
// 		{
// 			m=(l+r)>>1;
// 			if(strcmp(s,d[0][m].a)==0)
// 			{
// 				printf("%s\n",d[0][m].b);
// 				return ;
// 			}
// 			else if(strcmp(s,d[0][m].a)>0)
// 				l=m+1;
// 			else 
// 				r=m-1;
// 		}
// 		puts("what?");
// 		return;
// 	}
// }
 
 
// int main()
// {
// 	char str1[25],str2[85],str[120];
// 	int i,j;
// 	cnt=0;
// 	while(gets(str))
// 	{
// 		if(strcmp(str,"@END@")==0)
// 			break;
// 		i=j=0;
// 		while(str[i-1]!=']')
// 			str1[j++]=str[i++];
// 		str1[j]='\0';
 
// 		j=0,i++;
// 		while(i<strlen(str))
// 			str2[j++]=str[i++];
// 		str2[j]='\0';
 
// 		strcpy(d[1][cnt].a,str1);
// 		strcpy(d[1][cnt].b,str2);
// 		strcpy(d[0][cnt].a,str1);
// 		strcpy(d[0][cnt].b,str2);
// 		cnt++;
// 	}
// 	qsort(d[0],cnt,sizeof(d[0][0]),comp1);
// 	qsort(d[1],cnt,sizeof(d[1][0]),comp2);
 
// 	int n;
// 	scanf("%d",&n);
// 	getchar();
// 	while(n--)
// 	{
// 		int dic_index=1;
// 		gets(str2);
// 		if(str2[0]=='[')
// 			dic_index=0;
// 		Search(str2,dic_index,0,cnt-1);
// 	}
// }



//AC-暴力2187ms）
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 10000
#define M 'z'-'['+10
char dic[2][N][81];
int cnt;
 
int Search(char* s,int dicset)
{
	int i;
	for(i=0;i<cnt;i++)
		if(strcmp(s,dic[dicset][i])==0)
			return i;
	if(i==cnt)
		return -1;
}
 
int main()
{
	char str1[21],str2[81],str[120];
	int i,j;
	cnt=0;
	while(gets(str))
	{
		if(strcmp(str,"@END@")==0)
			break;
		i=j=0;
		while(str[i-1]!=']')
			str1[j++]=str[i++];
		str1[j]='\0';
 
		j=0,i++;
		while(i<strlen(str))
			str2[j++]=str[i++];
		str2[j]='\0';
 
		strcpy(dic[0][cnt],str1);
		strcpy(dic[1][cnt],str2);
		cnt++;
	}
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int dic_index=1;
		gets(str2);
		if(str2[0]=='[')
			dic_index=0;
		int index=Search(str2,dic_index);
		if(index==-1)
			puts("what?");
		else
		{
			if(dic_index==0)
				printf("%s\n",dic[1][index]);
			else
			{
				for(i=1;i<strlen(dic[0][index])-1;i++)
					printf("%c",dic[0][index][i]);
				cout<<endl;
			}
		}
	}
}