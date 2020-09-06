// 埃及分數問題
// Rujia Liu

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

int a, b, maxd;

typedef long long LL;

LL gcd(LL a, LL b) {
  return b == 0 ? a : gcd(b, a%b);
}

// 返回滿足1/c <= a/b的最小c
inline int get_first(LL a, LL b) {
  return b/a+1;
}

const int maxn = 100 + 5;

LL v[maxn], ans[maxn];

// 如果目前解v比目前最優解ans更優，更新ans
bool better(int d) {
  for(int i = d; i >= 0; i--) if(v[i] != ans[i]) {
    return ans[i] == -1 || v[i] < ans[i];
  }
  return false;
}

// 目前深度為d，分母不能小於from，分數之和恰好為aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
  if(d == maxd) {
    if(bb % aa) return false; // aa/bb必須是埃及分數
    v[d] = bb/aa;
    if(better(d)) memcpy(ans, v, sizeof(LL) * (d+1));
    return true;
  }
  bool ok = false;
  from = max(from, get_first(aa, bb)); // 列舉的起點
  for(int i = from; ; i++) {
    // 剪枝：如果剩下的maxd+1-d個分數全部都是1/i，加起來仍然不超過aa/bb，則無解
    if(bb * (maxd+1-d) <= i * aa) break;
    v[d] = i;
    // 計算aa/bb - 1/i，設結果為a2/b2
    LL b2 = bb*i;
    LL a2 = aa*i - bb;
    LL g = gcd(a2, b2); // 以便約分
    if(dfs(d+1, i+1, a2/g, b2/g)) ok = true;
  }
  return ok;
}

int main() {
  int kase = 0;
  while(cin >> a >> b) {
    int ok = 0;
    for(maxd = 1; maxd <= 100; maxd++) {
      memset(ans, -1, sizeof(ans));
      if(dfs(0, get_first(a, b), a, b)) { ok = 1; break; }
    }
    cout << "Case " << ++kase << ": ";
    if(ok) {
      cout << a << "/" << b << "=";
      for(int i = 0; i < maxd; i++) cout << "1/" << ans[i] << "+";
      cout << "1/" << ans[maxd] << "\n";
    } else cout << "No solution.\n";
  }
  return 0;
}
