// {0~n-1}���Ҧ��l���G�W�q�غc�k
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int* A, int cur) {
  for(int i = 0; i < cur; i++) printf("%d ", A[i]); // �C�L�ثe���X    
  printf("\n");
  int s = cur ? A[cur-1]+1 : 0; // �T�w�ثe�������̤p�i���
  for(int i = s; i < n; i++) {
    A[cur] = i;
    print_subset(n, A, cur+1); // ���j�غc�l��
  }
}

int A[10];
int main() {
  int n;
  scanf("%d", &n);
  print_subset(n, A, 0);
  return 0;
}
