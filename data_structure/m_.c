#include <stdio.h>

int main()
{
    int people_num, books;
    while(~scanf("%d %d", &people_num, &books)) {
        int hash_table[400] = {0};
        int people[people_num];
        for(int i = 0; i < people_num; i++) {
            scanf("%d", &people[i]);
            hash_table[people[i]]++;
        }
        for(int i = 0; i < people_num; i++) {
            if(hash_table[people[i]] - 1 == 0)
                printf("BeiJu\n");
            else
                printf("%d\n", hash_table[people[i]] - 1);
        }
    }
    return 0;
}