// UVa10791 Minimum Sum LCM
// Rujia Liu
// 題意：輸入整數n（1<=n<2^31），求至少兩個正整數，使得它們的最小公倍數為n，且這些整數的和最小。輸出最小的和。
// 演算法：假設唯一分解式n=a1^p1 * a2^p2...，不難發現每個a[i]^p[i]作為一個單獨的整數時最優。
// 特例：n=1時答案為1+1=2。n只有一種因數時需要加個1。另外注意n=2^31-1時不要溢出
#include<cmath>
#include<iostream>
using namespace std;

int divide_all(int& n, int d) {
  int x = 1;
  while(n % d == 0) { n /= d; x *= d; }
  return x;
}

long long solve(int n) {
  if(n == 1) return 2;
  int m = floor(sqrt(n) + 0.5);
  long long ans = 0;
  int pf = 0; // 質因數(prime_factor)個數
  for(int i = 2; i < m; i++) {
    if(n % i == 0) { // 新的質因數
      pf++;
      ans += divide_all(n, i);
    }
  }
  if(n > 1) { pf++; ans += n; }
  if(pf <= 1) ans++;
  return ans;
}

int main() {
  int n, kase = 0;
  while(cin >> n && n)
    cout << "Case " << ++kase << ": " << solve(n) << "\n";
  return 0;
}