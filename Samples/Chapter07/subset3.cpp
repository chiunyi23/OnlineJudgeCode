// {0~n-1}���Ҧ��l���G�G�i��k
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int s) {  // �C�L{0, 1, 2, ..., n-1}���l��S
  for(int i = 0; i < n; i++)
    if(s&(1<<i)) printf("%d ", i); // �o�̧Q�ΤFC�y��"�D0�ȳ����u"���W�w
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < (1<<n); i++)  // �C�|�U�l���ҹ������s�X 0, 1, 2, ..., 2^n-1
    print_subset(n, i);
  return 0;
}


