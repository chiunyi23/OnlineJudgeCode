// 求1~n的全排列. n<100
// Rujia Liu
#include<cstdio>
using namespace std;

int A[101];

// 輸出1~n的全排列
void print_permutation(int n, int* A, int cur) {
  if(cur == n) { // 遞迴邊界
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
  } else for(int i = 1; i <= n; i++) { // 嘗試在A[cur]中填各種整數i
    int ok = 1;
    for(int j = 0; j < cur; j++)
      if(A[j] == i) ok = 0; // 如果i已經在A[0]~A[cur-1]出現過，則不能再選
    if(ok) {
      A[cur] = i;
      print_permutation(n, A, cur+1); // 遞迴呼叫
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  print_permutation(n, A, 0); 
  return 0;
}
