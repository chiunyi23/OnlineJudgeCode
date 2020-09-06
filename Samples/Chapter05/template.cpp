#include<iostream>
using namespace std;

struct Point {
  int x, y;
//  Point(int x=0, int y=0):x(x),y(y) {}
  Point(int x=0, int y=0) { this->x = x; this->y = y; }
};

// �w�q�F+�B��l����A�U����sum�d����ƴN�i�H�Ω�Point�}�C�F�I
Point operator + (const Point& A, const Point& B) {
  return Point(A.x+B.x, A.y+B.y);
}

ostream& operator << (ostream &out, const Point& p) {
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

/*
int sum(int* begin, int* end) {
  int *p = begin;
  int ans = 0;
  for(int *p = begin; p != end; p++)
    ans += *p;
  return ans;
}
*/

// �U���O�d�����sum�A�ק�ۤW�zint����sum���
template<typename T>
T sum(T* begin, T* end) {
  T *p = begin;
  T ans = 0;
  for(T *p = begin; p != end; p++)
    ans = ans + *p;
  return ans;
}

int main() {
  double a[] = {1.1, 2.2, 3.3, 4.4};
  cout << sum(a, a+4) << "\n";
  Point b[] = { Point(1,2), Point(3,4), Point(5,6), Point(7,8) };
  cout << sum(b, b+4) << "\n";
  return 0;
}

