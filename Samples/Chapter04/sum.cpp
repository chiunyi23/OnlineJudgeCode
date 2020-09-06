#include<stdio.h>

// �p��}�C�U�Ӥ������M�]���~�^
int sum0(int a[5]) {
  int ans = 0;
  for(int i = 0; i < sizeof(a); i++)
    ans += a[i];
  return ans;
}

// �p��}�C�U�Ӥ������M�A��k�@
int sum1(int a[], int n) {
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans += a[i];
  return ans;
}

// �p��}�C�U�Ӥ������M�A��k�G
int sum2(int* begin, int* end) {
  int n = end - begin;
  int ans = 0;
  for(int i = 0; i < n; i++)
    ans += begin[i];
  return ans;
}

// �p��}�C�U�Ӥ������M�A��k�T
int sum3(int* begin, int* end) {
  int *p = begin;
  int ans = 0;
  for(int *p = begin; p != end; p++)
    ans += *p;
  return ans;
}

int main() {
  int a[] = {1, 2, 3, 5, 8};
  printf("%d\n", sum0(a)); // ���~
  printf("%d\n", sum1(a, 5));
  printf("%d\n", sum2(a, a+5));
  printf("%d\n", sum3(a, a+5));
  return 0;
}


