// {0~n-1}的所有子集：二進位法
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int s) {  // 列印{0, 1, 2, ..., n-1}的子集S
  for(int i = 0; i < n; i++)
    if(s&(1<<i)) printf("%d ", i); // 這裡利用了C語言"非0值都為真"的規定
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < (1<<n); i++)  // 列舉各子集所對應的編碼 0, 1, 2, ..., 2^n-1
    print_subset(n, i);
  return 0;
}


