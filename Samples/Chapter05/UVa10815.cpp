// UVa10815 Andy's First Dictionary
// Rujia Liu
// �D�N�G��J�@�q��r�A��X�Ҧ����P����r�]�s��r���ǦC�^�A���r��Ǳq�p��j��X�C��������j�p�g�C
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;

set<string> dict;
string s, buf;

int main() {
  while(cin >> s) {
    for(int i = 0; i < s.length(); i++)
      if(isalpha(s[i])) s[i] = tolower(s[i]); else s[i] = ' ';
    stringstream ss(s);
    while(ss >> buf) dict.insert(buf);
  }
  for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    cout << *it << "\n";
  return 0;
}

