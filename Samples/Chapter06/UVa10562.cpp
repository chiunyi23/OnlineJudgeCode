// UVa10562 Undraw the Trees
// Rujia Liu
// �D�N�G��e�o�ܦn�ݪ��h������Ƭ��A���аO�k
// �t��k�G�����b�G���r���}�C�̻��j�C�`�N�ž�A�åB�`�I�и��i�H�O���N�i�C�L�r��

#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;

const int maxn = 200 + 10;
int n;
char buf[maxn][maxn];

// ���j���X�åB��X�H�r��buf[r][c]���ڪ���
void dfs(int r, int c) {
  printf("%c(", buf[r][c]);
  if(r+1 < n && buf[r+1][c] == '|') { // ���l��
    int i = c;
    while(i-1 >= 0 && buf[r+2][i-1] == '-') i--; // ��"----"�������
    while(buf[r+2][i] == '-' && buf[r+3][i] != '\0') {
      if(!isspace(buf[r+3][i])) dfs(r+3, i); // fgetsŪ�J��'\n'�]����isspace()
      i++;
    }
  }
  printf(")");
}

void solve() {
  n = 0;
  for(;;) {
    fgets(buf[n], maxn, stdin);
    if(buf[n][0] == '#') break; else n++;
  }
  printf("(");
  if(n) {
    for(int i = 0; i < strlen(buf[0]); i++)
      if(buf[0][i] != ' ') { dfs(0, i); break; }
  }
  printf(")\n");
}

int main() {
  int T;
  fgets(buf[0], maxn, stdin);
  sscanf(buf[0], "%d", &T);
  while(T--) solve();
  return 0;
}

