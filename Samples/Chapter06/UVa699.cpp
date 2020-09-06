// UVa699 The Falling Leaves
// Rujia Liu
// �D�N�G���@�ʤG����A�C�Ӹ`�I�����@�Ӥ�����m�G����l�b������1�ӳ��A�k��l�b�k��1�ӳ��C�q���V�k��X�C�Ӥ�����m���Ҧ��`�I���v�Ȥ��M�C���ӻ��j�覡��J�A-1��ܪž�
// �t��k�G�b"�ؾ�"���P�ɭp��A�L���u�������O�s�U��

#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 200;
int sum[maxn];

// ��J�òέp�@�ʤl��A��ڤ�����m��p
void build(int p) {
  int v;
  cin >> v;
  if(v == -1) return; // �ž�
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

// ��Ū�J��έp
bool init() {
  int v;
  cin >> v;
  if(v == -1) return false;

  memset(sum, 0, sizeof(sum));
  int pos = maxn/2; // ��ڪ�������m
  sum[pos] = v;
  build(pos - 1); // ���l��
  build(pos + 1); // �k�l��
}

int main() {
  int kase = 0;
  while(init()) {
    int p = 0;
    while(sum[p] == 0) p++; // ��̥��䪺���l

    // �}�l��X�C�]���n�קK�楽�h�l�Ů�A�ҥH�y�L�·Ф@�I
    cout << "Case " << ++kase << ":\n" << sum[p++];
    while(sum[p] != 0) {
      cout << " " << sum[p];
      p++;
    }
    cout << "\n\n";
  }
  return 0;
}
