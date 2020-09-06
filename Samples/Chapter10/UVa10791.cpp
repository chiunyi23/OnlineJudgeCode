// UVa10791 Minimum Sum LCM
// Rujia Liu
// �D�N�G��J���n�]1<=n<2^31�^�A�D�ܤ֨�ӥ���ơA�ϱo���̪��̤p�����Ƭ�n�A�B�o�Ǿ�ƪ��M�̤p�C��X�̤p���M�C
// �t��k�G���]�ߤ@���Ѧ�n=a1^p1 * a2^p2...�A�����o�{�C��a[i]^p[i]�@���@�ӳ�W����Ʈɳ��u�C
// �S�ҡGn=1�ɵ��׬�1+1=2�Cn�u���@�ئ]�Ʈɻݭn�[��1�C�t�~�`�Nn=2^31-1�ɤ��n���X
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
  int pf = 0; // ��]��(prime_factor)�Ӽ�
  for(int i = 2; i < m; i++) {
    if(n % i == 0) { // �s����]��
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