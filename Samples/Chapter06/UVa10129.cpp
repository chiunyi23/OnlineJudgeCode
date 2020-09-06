// UVa10129 Play on Words
// Rujia Liu
// �D�N�G��Jn�ӳ�r�A�O�_�i�H�Ʀ��@�ӧǦC�A�ϱo�C�ӳ�r���Ĥ@�Ӧr���M�W�@�ӳ�r���̫�@�Ӧr���ۦP
// �t��k�G��r���ݧ@�`�I�A��r�ݦ����V��A�h���ѷ�B�ȷ�Ϥ����שԸ��|�C�`�N�n���P�s�q

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 1000 + 5;

// �ìd���]�{���X�K�ۡm���ɵ{���]�p�����D��ҤO�а�ںt��k�{���]�p�v�ɰV�m���n�n�ĤT���^
int pa[256];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; } 

int used[256], deg[256]; // �O�_�X�{�L�F�׼�

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    char word[maxn];

    scanf("%d", &n);
    memset(used, 0, sizeof(used));
    memset(deg, 0, sizeof(deg));
    for(int ch = 'a'; ch <= 'z'; ch++) pa[ch] = ch; // ��l�ƨìd��
    int cc = 26; // �s�q���Ӽ�

    for(int i = 0; i < n; i++) {
      scanf("%s", word);
      char c1 = word[0], c2 = word[strlen(word)-1];
      deg[c1]++;
      deg[c2]--;
      used[c1] = used[c2] = 1;
      int s1 = findset(c1), s2 = findset(c2);
      if(s1 != s2) { pa[s1] = s2; cc--; }
    }

    vector<int> d;
    for(int ch = 'a'; ch <= 'z'; ch++) {
      if(!used[ch]) cc--; // �S�X�{�L���r��
      else if(deg[ch] != 0) d.push_back(deg[ch]);
    }
    bool ok = false;
    if(cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) ok = true;
    if(ok) printf("Ordering is possible.\n");
    else printf("The door cannot be opened.\n");
  }
  return 0;
}