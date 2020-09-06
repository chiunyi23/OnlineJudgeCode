// UVa297 Quadtrees
// Rujia Liu
// �D�N�G����ʥ|���𪺥��Ǩ��X�A�D�G�̦X�֤���]�¦ⳡ���X�֡^�¦⹳�����ӼơCp���ܤ����`�I�Af���ܶ¦�]full�^�Ae���ܥզ�]empty�^
// �t��k�G���ؾ�A�M��έp
#include<cstdio>
#include<cstring>

const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len], cnt;

// ��r��s[p..]�ץX��H(r,c)�����W���A�����w���w�İϤ�
// 2 1
// 3 4
void draw(const char* s, int& p, int r, int c, int w) {
  char ch = s[p++];
  if(ch == 'p') {
    draw(s, p, r,     c+w/2, w/2); // 1
    draw(s, p, r,     c    , w/2); // 2
    draw(s, p, r+w/2, c    , w/2); // 3
    draw(s, p, r+w/2, c+w/2, w/2); // 4
  } else if(ch == 'f') { // �e�¹����]�չ������e�^
    for(int i = r; i < r+w; i++)
      for(int j = c; j < c+w; j++)
       if(buf[i][j] == 0) { buf[i][j] = 1; cnt++; }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    memset(buf, 0, sizeof(buf));
    cnt = 0;
    for(int i = 0; i < 2; i++) {
      scanf("%s", s);
      int p = 0;
      draw(s, p, 0, 0, len);
    }
    printf("There are %d black pixels.\n", cnt);
  }
  return 0;
}