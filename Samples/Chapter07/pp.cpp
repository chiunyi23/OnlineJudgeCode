// �D1~n�����ƦC. n<100
// Rujia Liu
#include<cstdio>
using namespace std;

int A[101];

// ��X1~n�����ƦC
void print_permutation(int n, int* A, int cur) {
  if(cur == n) { // ���j���
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
  } else for(int i = 1; i <= n; i++) { // ���զbA[cur]����U�ؾ��i
    int ok = 1;
    for(int j = 0; j < cur; j++)
      if(A[j] == i) ok = 0; // �p�Gi�w�g�bA[0]~A[cur-1]�X�{�L�A�h����A��
    if(ok) {
      A[cur] = i;
      print_permutation(n, A, cur+1); // ���j�I�s
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  print_permutation(n, A, 0); 
  return 0;
}
