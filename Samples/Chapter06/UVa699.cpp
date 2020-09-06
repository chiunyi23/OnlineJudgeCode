// UVa699 The Falling Leaves
// Rujia Liu
// 題意：給一棵二元樹，每個節點都有一個水平位置：左兒子在它左邊1個單位，右兒子在右邊1個單位。從左向右輸出每個水平位置的所有節點的權值之和。按照遞迴方式輸入，-1表示空樹
// 演算法：在"建樹"的同時計算，無須真正的把樹保存下來

#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 200;
int sum[maxn];

// 輸入並統計一棵子樹，樹根水平位置為p
void build(int p) {
  int v;
  cin >> v;
  if(v == -1) return; // 空樹
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

// 邊讀入邊統計
bool init() {
  int v;
  cin >> v;
  if(v == -1) return false;

  memset(sum, 0, sizeof(sum));
  int pos = maxn/2; // 樹根的水平位置
  sum[pos] = v;
  build(pos - 1); // 左子樹
  build(pos + 1); // 右子樹
}

int main() {
  int kase = 0;
  while(init()) {
    int p = 0;
    while(sum[p] == 0) p++; // 找最左邊的葉子

    // 開始輸出。因為要避免行末多餘空格，所以稍微麻煩一點
    cout << "Case " << ++kase << ":\n" << sum[p++];
    while(sum[p] != 0) {
      cout << " " << sum[p];
      p++;
    }
    cout << "\n\n";
  }
  return 0;
}
