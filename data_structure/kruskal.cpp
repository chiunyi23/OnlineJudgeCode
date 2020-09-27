#include<iostream>
using namespace std;
const int maxx= 6000;
 
  
 
class Kru{//存储kruskal算法中的节点
    public:
    int bef; 
    int aft;
    int data;
    int flag;
    Kru(){
        bef= -1;
        aft= -1;
        data= 0;
        flag= 0;
    }
};
 
 
 
void change(int visit[], int n, int a, int b){//将两个顶点及与他们相通的顶点改成同样的值表示 
                                              //他们相通
    for(int i= 0; i< n; i++)
      if(visit[i]== a)
        visit[i]= b;
 
}
 
int findmin(int visit[], Kru kr[], int in){//找出kr[]数组中权重最小的边
    int minn= 10000;
    int index= 0;
    int flag= 0;
     for(int i= 0; i< in; i++){
     	if(visit[kr[i].bef]== visit[kr[i].aft])
     	  kr[i].flag= 1;
        if(!kr[i].flag&&kr[i].data< minn){//如果该边没被访问且最小
            minn= kr[i].data;
            index= i;
            flag= 1;
         }
     }
      
 
     return index;
 
}
 
int kruskal(int visit[], int in, int n, Kru kr[]){//kruskal算法
 
     
     int k= 0;
     int result= 0;
     while(true){
        int minn= findmin(visit, kr, in);//找出权重最小的边
 
         kr[minn].flag= 1;
         int t1= kr[minn].bef;
         int t2= kr[minn].aft;
          
      
        if(visit[t1]!= visit[t2]){//如果两个顶点的visit值不一样说明还没相通
         
            change(visit, n, visit[t1], visit[t2]);//将两个顶点连通
            result+= kr[minn].data;
         }
         k++;
         if(k> in)
         break;
     } 
     return result;
}
int main(){
	int n;
	while(cin>>n){
	     int visit[n+ 5];
	      Kru kr[maxx+ 5];
	    for(int i= 0; i< n; i++)
          visit[i]= i;//初始visit[]数组
          
          
		int k= 0;
		for(int i= 0; i< n; i++)
		  for(int j= 0; j< n; j++){
		  	int temp;
		  	cin>>temp;
		  	 if(i< j){
		  	 	kr[k].bef= i;
		  	 	kr[k].aft= j;
		  	 	kr[k++].data= temp;
			   }
		  }
		  
		  int h;
		  cin>>h;
		  while(h--){
		  	int a, b;
		  	cin>>a>>b;
		  
           change(visit, n, visit[a-1], visit[b- 1]);
 
		  }
		  cout<<kruskal(visit, k, n, kr)<<endl;
	}
}