// UVa156 Ananagrams
// Rujia Liu
// 題意：輸入一些單字，找出所有滿足如下條件的單字：該單字不能通過字母重排得到輸入文字中的另外一個單字
// 演算法：把每個單字"標準化"，即全部轉化為小寫字母然後排序，然後放到map中進行統計
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;

// 將單字s進行"標準化"
string repr(string s) {
  string ans = s;
  for(int i = 0; i < ans.length(); i++)
    ans[i] = tolower(ans[i]);
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  int n = 0;
  string s;
  while(cin >> s) {
    if(s[0] == '#') break;
    words.push_back(s);
    string r = repr(s);
    if(!cnt.count(r)) cnt[r] = 0;
    cnt[r]++;
  }
  vector<string> ans;
  for(int i = 0; i < words.size(); i++)
    if(cnt[repr(words[i])] == 1) ans.push_back(words[i]);
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << "\n";
  return 0;
}

