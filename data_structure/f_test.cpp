#include <iostream>
using namespace std;


char s[500];
char solution[500];
int array[128]; // 分別存入 128 個 ASCII 字元的出現次數
int num, counter = 0;

void backtrack(int n, int N)
{
    if (n == N)
    {
        counter++;
        for (int i=0; i<N; i++)
            cout << solution[i];
        cout << endl;
        return;
    }
 
    for (int i=0; i<128; i++)   // 枚舉每一個字母
        if (array[i] > 0)       // 還有字母剩下來，就要枚舉
        {
            array[i]--;         // 用掉了一個字母
 
            solution[n] = i;    // char 變數可以直接存入 ascii 數值
            backtrack(n+1, N);
 
            array[i]++;         // 回收了一個字母
        }
}
 
void enumerate_permutations()
{
    // initialization
    for (int i=0; i<num; i++) array[i] = 0;
    for (int i=0; i<num; i++) array[s[i]]++;
 
    backtrack(0, num);    // 印出字母abb的所有排列。
}


int main()
{
    cin >> num;
    cin >> s;
    enumerate_permutations();
    cout << counter << endl;
    return 0;
}