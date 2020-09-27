#include <iostream>
using namespace std;

bool adj[9][9]; // adjacency matrix
int ref[9];     // 記錄圖上每一個點目前仍被多少條邊連到
 
void topological_ordering()
{
    for (int i=0; i<9; ++i) ref[i] = 0; // 初始化為0
 
    // 累計圖上每一個點被幾條邊連到
    for (int i=0; i<9; ++i)
        for (int j=0; j<9; ++j)
            if (adj[i][j])
                ref[j]++;
 
    // 開始找出一個合理的排列順序
    for (int i=0; i<9; ++i)
    {
        // 尋找沒有被任何邊連向的點
        int s = 0;
        while (s < 9 && ref [s] != 0) ++s;
 
        if (s == 9) {
            cout << "cyle\n";
            break;  // 找不到。表示目前殘存的圖是個環。
        }
        ref[s] = -1;        // 設為已找過（刪去s點）
 
        cout << s;          // 印出合理的排列順序的第i點
 
        // 更新ref的值（刪去由s點連出去的邊）
        for (int t=0; t<9; ++t)
            if (adj[s][t])
                ref[t]--;
    }
}

int main()
{
    int n1, n2; 
    for(int i = 0; i < 5; i++) {
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
    }
    topological_ordering();
    return 0;
}