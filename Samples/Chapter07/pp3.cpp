// �i���������ƦC(next_permutation��)
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
  int n, p[10];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &p[i]);
  sort(p, p+n); // �ƧǡA�o��p���̤p�ƦC
  do {
    for(int i = 0; i < n; i++) printf("%d ", p[i]); // ��X�ƦCp
    printf("\n");
  } while(next_permutation(p, p+n)); // �D�U�@�ӱƦC
  return 0;
}
