#include <stdio.h>

int main()
{
    int x = 0, y = 0;
    int a = 1, b = 1;
    if(a)
        if(b)
            x++;
        else
            y++;

    printf("%d %d\n", x, y);

    return 0;
}