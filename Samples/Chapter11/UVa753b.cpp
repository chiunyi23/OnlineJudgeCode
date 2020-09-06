// UVa753 A Plug for UNIX
// Rujia Liu
// 演算法二：直接構圖
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<string> names;
int ID(const string& s) {
  for(int i = 0; i < names.size(); i++)
    if(names[i] == s) return i;
  names.push_back(s);
  return names.size() - 1;
}

const int maxn = 400 + 5; 

int n, m, k;       // 插座個數，設備個數，轉換器個數
int target[maxn];  // 各個插座的類型
int device[maxn];  // 各個設備的類型
int from[maxn], to[maxn]; // 各個轉換器

const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f) {}
};

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;    // 邊數的兩倍
  vector<int> G[maxn];   // 鄰接串列，G[i][j]表示節點i的第j條邊在e陣列中的序號
  int a[maxn];           // 當起點到i的可改進量
  int p[maxn];           // 最短路徑樹上p的入弧編號

  void init(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for(;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap-e.flow);
            Q.push(e.to);
          }
        }
        if(a[t]) break;
      }
      if(!a[t]) break;
      for(int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

EdmondsKarp g;

int main() {
  int T;
  cin >> T;
  while(T--) {
    names.clear();
    string s1, s2;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> s1;
      target[i] = ID(s1);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
      cin >> s1 >> s2;
      device[i] = ID(s2);
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
      cin >> s1 >> s2;
      from[i] = ID(s1); to[i] = ID(s2);
    }
    
    int V = names.size();
    g.init(V+2);
    for(int i = 0; i < m; i++)
      g.AddEdge(V, device[i], 1); // 源點->設備
    for(int i = 0; i < n; i++)
      g.AddEdge(target[i], V+1, 1); // 插座->匯點
    for(int i = 0; i < k; i++)
      g.AddEdge(from[i], to[i], INF); // 插頭->插頭
    int r = g.Maxflow(V, V+1);
    cout << m-r << "\n";
    if(T) cout << "\n";
  }
  return 0;
}