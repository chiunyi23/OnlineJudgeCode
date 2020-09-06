// �J�Τ��ư��D
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

// ��^����1/c <= a/b���̤pc
inline int get_first(LL a, LL b) {
  return b/a+1;
}

const int maxn = 100 + 5;

LL v[maxn], ans[maxn];

// �p�G�ثe��v��ثe���u��ans���u�A��sans
bool better(int d) {
  for(int i = d; i >= 0; i--) if(v[i] != ans[i]) {
    return ans[i] == -1 || v[i] < ans[i];
  }
  return false;
}

// �ثe�`�׬�d�A��������p��from�A���Ƥ��M��n��aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
  if(d == maxd) {
    if(bb % aa) return false; // aa/bb�����O�J�Τ���
    v[d] = bb/aa;
    if(better(d)) memcpy(ans, v, sizeof(LL) * (d+1));
    return true;
  }
  bool ok = false;
  from = max(from, get_first(aa, bb)); // �C�|���_�I
  for(int i = from; ; i++) {
    // �ŪK�G�p�G�ѤU��maxd+1-d�Ӥ��ƥ������O1/i�A�[�_�Ӥ��M���W�Laa/bb�A�h�L��
    if(bb * (maxd+1-d) <= i * aa) break;
    v[d] = i;
    // �p��aa/bb - 1/i�A�]���G��a2/b2
    LL b2 = bb*i;
    LL a2 = aa*i - bb;
    LL g = gcd(a2, b2); // �H�K����
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
