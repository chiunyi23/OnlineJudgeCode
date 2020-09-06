// UVa1363 Joseph's Problem
// Rujia Liu
#include<iostream>
#include<algorithm>
using namespace std;

// 首項為a，公差為-d，除了首項之外還有n項
// 末項為a-n*d，平均數為(2*a-n*d)/2
long long sum(int a, int d, int n) {
  return (long long)(2*a-n*d)*(n+1)/2;
}

int main() {
  int n, k;
  while(cin >> n >> k) {
    int i = 1;
    long long ans = 0;
    while(i <= n) {
      int q = k % i, p = k / i;
      int cnt = n - i; // 最多還有n - i項
      if(p > 0) cnt = min(cnt, q / p);
      ans += sum(q, p, cnt);
      i += cnt + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}