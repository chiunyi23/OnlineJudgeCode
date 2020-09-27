#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr = NULL;
    ptr = (int*)malloc(sizeof(int));
    printf("%x\n", ptr);
    printf("%d", *ptr);
    return 0;
}