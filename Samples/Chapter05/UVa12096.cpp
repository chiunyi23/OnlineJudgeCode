// UVa12096 The SetStack Computer
// Rujia Liu
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache; // �ⶰ�X�M�g��ID
vector<Set> Setcache; // �ھ�ID���o���X

// �j�M���w���Xx��ID�C�p�G�䤣��A���t�@�ӷsID
int ID (Set x) {
  if (IDcache.count(x)) return IDcache[x];
  Setcache.push_back(x); // �s�W�s���X
  return IDcache[x] = Setcache.size() - 1;
}

int main () {
  int T;
  cin >> T;
  while(T--) {
    stack<int> s; // �D�ؤ������| 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      string op;
      cin >> op;
      if (op[0] == 'P') s.push(ID(Set()));
      else if (op[0] == 'D') s.push(s.top());
      else {
        Set x1 = Setcache[s.top()]; s.pop();
        Set x2 = Setcache[s.top()]; s.pop();
        Set x;
        if (op[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));
        if (op[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(x));
        if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }
        s.push(ID(x));
      }      
      cout << Setcache[s.top()].size() << endl;
    }
    cout << "***" << endl;
  }
  return 0;  
}

