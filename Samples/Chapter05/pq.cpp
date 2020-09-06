#include<queue>
#include<iostream>
using namespace std;

struct cmp {
  bool operator() (const int a, const int b) const { // a���u�����Ǥ�b�p�ɪ�^true
    return a % 10 > b % 10;
  }
};

int main() {
  priority_queue<int, vector<int>, cmp> pq;
  pq.push(1);
  pq.push(3);
  pq.push(22);
  pq.push(44);
  while(!pq.empty()) {
    cout << pq.top() << "\n";
    pq.pop();
  }

  return 0;
}