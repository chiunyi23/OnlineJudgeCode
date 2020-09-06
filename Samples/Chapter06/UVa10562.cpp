// UVa10562 Undraw the Trees
// Rujia Liu
// 題意：把畫得很好看的多元樹轉化為括弧標記法
// 演算法：直接在二維字元陣列裡遞迴。注意空樹，並且節點標號可以是任意可列印字元

#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];

// 遞迴走訪並且輸出以字元buf[r][c]為根的樹
void dfs(int r, int c) {
  printf("%c(", buf[r][c]);
  if(r+1 < n && buf[r+1][c] == '|') { // 有子樹
    int i = c;
    while(i-1 >= 0 && buf[r+2][i-1] == '-') i--; // 找"----"的左邊界
    while(buf[r+2][i] == '-' && buf[r+3][i] != '\0') {
      if(!isspace(buf[r+3][i])) dfs(r+3, i); // fgets讀入的'\n'也滿足isspace()
      i++;
    }
  }
  printf(")");
}

void solve() {
  n = 0;
  for(;;) {
    fgets(buf[n], maxn, stdin);
    if(buf[n][0] == '#') break; else n++;
  }
  printf("(");
  if(n) {
    for(int i = 0; i < strlen(buf[0]); i++)
      if(buf[0][i] != ' ') { dfs(0, i); break; }
  }
  printf(")\n");
}

int main() {
  int T;
  fgets(buf[0], maxn, stdin);
  sscanf(buf[0], "%d", &T);
  while(T--) solve();
  return 0;
}

