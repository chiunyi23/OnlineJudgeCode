#include<stdio.h>

// 計算組合數的一種方法
long long C(int n, int m)
{
  return factorial(n)/(factorial(m)*factorial(n-m));
}

// 計算組合數的另一種方法，可以解決更大規模的問題
long long C2(int n, int m) {
  if(m < n-m) m = n-m;
  long long ans = 1;
  for(int i = m+1; i <= n; i++) ans *= i;
  for(int i = 1; i <= n-m; i++) ans /= i;
  return ans;
}

long long factorial(int n)
{
  long long m = 1;
  for(int i = 1; i <= n; i++)
    m *= i;
  return m;
}

int main() {
  printf("%lld\n", C(21,1));
  printf("%lld\n", C2(21,1));
  return 0;
}


