// UVa839 Not so Mobile
// Rujia Liu
// 題意：輸入一個樹狀天平，根據力矩相等原則判斷是否平衡。採用遞迴方式輸入，0表示中間節點
// 演算法：在"建樹"時直接讀入並判斷，並且無須把樹保存下來
#include<iostream>
using namespace std;

// 輸入一個子天平，返回子天平是否平衡，參數W修改為子天平的總重量
bool solve(int& W) {
  int W1, D1, W2, D2;
  bool b1 = true, b2 = true;
  cin >> W1 >> D1 >> W2 >> D2;
  if(!W1) b1 = solve(W1);
  if(!W2) b2 = solve(W2);
  W = W1 + W2;
  return b1 && b2 && (W1 * D1 == W2 * D2);
}

int main() {
  int T, W;
  cin >> T;
  while(T--) {
    if(solve(W)) cout << "YES\n"; else cout << "NO\n";
    if(T) cout << "\n";
  }
  return 0;
}
