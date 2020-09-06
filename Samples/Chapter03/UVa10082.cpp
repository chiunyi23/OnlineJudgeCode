// UVa10082 WERTYU
// Rujia Liu
#include<stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
  int i, c;
  while((c = getchar()) != EOF) {
     for (i=1; s[i] && s[i]!=c; i++); // 找錯位之後的字元在常數串列中的位置
     if (s[i]) putchar(s[i-1]); // 如果找到，則輸出它的前一個字元
     else putchar(c);
  }
  return 0;
}

