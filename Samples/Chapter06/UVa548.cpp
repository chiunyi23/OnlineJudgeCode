// UVa548 Tree	
// Rujia Liu
// 題意：給一棵點帶權（權各不相同，都是正整數）二元樹的中序和後序走訪，找一個葉子使得它到根的路徑上的權和最小。如果有多解，該葉子本身的權應儘量小
// 演算法：遞迴建樹，然後DFS。注意，直接遞迴求結果也可以，但是先建樹的方法不僅直觀，而且更好除錯
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

// 因為各個節點的權值各不相同且都是正整數，直接用權值作為節點編號
const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int* a) {
  string line;
  if(!getline(cin, line)) return false;
  stringstream ss(line);
  n = 0;
  int x;
  while(ss >> x) a[n++] = x;
  return n > 0;
}

// 把in_order[L1..R1]和post_order[L2..R2]建成一棵二元樹，返回樹根
int build(int L1, int R1, int L2, int R2) {
  if(L1 > R1) return 0; // 空樹
  int root = post_order[R2];
  int p = L1;
  while(in_order[p] != root) p++;
  int cnt = p-L1; // 左子樹的節點個數
  lch[root] = build(L1, p-1, L2, L2+cnt-1);
  rch[root] = build(p+1, R1, L2+cnt, R2-1);
  return root;
}

int best, best_sum; // 目前為止的最優解和對應的權和

void dfs(int u, int sum) {
  sum += u;
  if(!lch[u] && !rch[u]) { // 葉子
    if(sum < best_sum || (sum == best_sum && u < best)) { best = u; best_sum = sum; }
  }
  if(lch[u]) dfs(lch[u], sum);
  if(rch[u]) dfs(rch[u], sum);
}

int main() {
  while(read_list(in_order)) {
    read_list(post_order);
    build(0, n-1, 0, n-1);
    best_sum = 1000000000;
    dfs(post_order[n-1], 0);
    cout << best << "\n";
  }
  return 0;
}
