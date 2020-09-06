// UVa129 Krypton Factor
// Rujia Liu
#include<stdio.h>
int n, L, cnt;
int S[100];

int dfs(int cur) {                                       // 返回0表示已經得到解，無須繼續搜尋
  if(cnt++ == n) {
    for(int i = 0; i < cur; i++) {
      if(i % 64 == 0 && i > 0) printf("\n");
      else if(i % 4 == 0 && i > 0) printf(" ");
      printf("%c", 'A'+S[i]); // 輸出方案
    }
    printf("\n%d\n", cur);
    return 0;
  }
  for(int i = 0; i < L; i++) {
    S[cur] = i;
    int ok = 1;
    for(int j = 1; j*2 <= cur+1; j++) {                  // 嘗試長度為j*2的後綴 
      int equal = 1;
      for(int k = 0; k < j; k++)                         // 檢查後一半是否等於前一半
        if(S[cur-k] != S[cur-k-j]) { equal = 0; break; }
      if(equal) { ok = 0; break; }                       // 後一半等於前一半，方案不合法
    }
    if(ok) if(!dfs(cur+1)) return 0;                     // 遞迴搜尋。如果已經找到解，則直接退出
  }
  return 1;
}

int main() {
  while(scanf("%d%d", &n, &L) == 2 && n > 0) {
    cnt = 0;
    dfs(0);
  }
  return 0;
}


