// {0~n-1}���Ҧ��l���G��V�q�k
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int* B, int cur) {
  if(cur == n) {
    for(int i = 0; i < cur; i++)
      if(B[i]) printf("%d ", i); // �C�L�ثe���X
    printf("\n");
    return;
  }
  B[cur] = 1; // ���cur�Ӥ���
  print_subset(n, B, cur+1);
  B[cur] = 0; // �����cur�Ӥ���
  print_subset(n, B, cur+1);
}

int B[10];
int main() {
  int n;
  scanf("%d", &n);
  print_subset(5, B, 0);
  return 0;
}


