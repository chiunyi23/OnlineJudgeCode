#include <cstdio>
using namespace std;

bool map[100][100];
bool first;

void dfs(int x1, int x2, int y1, int y2)
{
    bool is_same = true;
    bool m = map[x1][y1];
    int i, j;
    for (i = x1; i <= x2 && is_same; i++)
        for (j = y1; j <= y2; j++)
            if (map[i][j] != m)
            {
                is_same = false;
                break;
            }
    if (is_same)
    {
        if (first)
            printf(" ");
          first = true;
        if (m)
            printf("b");
        else
            printf("w");
        return;
    }
    if (first)
        printf(" ");
    first = true;
    printf("g");
    dfs(x1, (x1 + x2) / 2, (y1 + y2) / 2 + 1, y2);
    dfs(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
    dfs((x1 + x2) / 2 + 1, x2, y1, (y1 + y2) / 2);
    dfs((x1 + x2) / 2 + 1, x2, (y1 + y2) / 2 + 1, y2);
}

int main()
{
  int N;
  while(~scanf("%d", &N)) {
    int i, j;
      first = false;
      for (i = 0; i < N; i++)
      {
        scanf("\n");
        for (j = 0; j < N; j++)
        {
          char ch;
          scanf("%c", &ch);
          map[i][j] = ch - '0';
        }
      }
      dfs(0, N - 1, 0, N - 1);
      puts("");
  }
  
  return 0;
}