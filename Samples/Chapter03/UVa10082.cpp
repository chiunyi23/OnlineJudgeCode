// UVa10082 WERTYU
// Rujia Liu
#include<stdio.h>
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
  int i, c;
  while((c = getchar()) != EOF) {
     for (i=1; s[i] && s[i]!=c; i++); // ����줧�᪺�r���b�`�Ʀ�C������m
     if (s[i]) putchar(s[i-1]); // �p�G���A�h��X�����e�@�Ӧr��
     else putchar(c);
  }
  return 0;
}

