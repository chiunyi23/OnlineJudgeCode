// UVa839 Not so Mobile
// Rujia Liu
// �D�N�G��J�@�Ӿ𪬤ѥ��A�ھڤO�x�۵���h�P�_�O�_���šC�ĥλ��j�覡��J�A0��ܤ����`�I
// �t��k�G�b"�ؾ�"�ɪ���Ū�J�çP�_�A�åB�L�����O�s�U��
#include<iostream>
using namespace std;

// ��J�@�Ӥl�ѥ��A��^�l�ѥ��O�_���šA�Ѽ�W�קאּ�l�ѥ����`���q
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
