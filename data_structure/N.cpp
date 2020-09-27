#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    scanf("%d", &num);
    while(num--) {
        char* str = NULL;
        str = (char*)malloc(sizeof(char) * 5);
        scanf("%s", str);

        int i = 0;
        for(i = 3; i >= 0; i--) {
            printf("%c", *(str + i));
        }
        printf("\n");

    }

    return 0;
}
