#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num;
    while(scanf("%d", &num) != EOF) {
        if(num == 0) {
            break;
        }
        int* matrix = NULL;
        matrix = (int*)malloc(sizeof(int*) * num * num);
        int i, j;

        for(i = 0; i < num; i++) {
            for(j = 0; j < num; j++) {
                scanf("%d", matrix+(num * i) + j);
                // printf("%d ", (num * i) + j);
                // printf("%d ", *(matrix+i+j));
            }
        }


        int RowCheck = 0, ErrorRow = 0;
        // check row
        for(i = 0; i < num; i++) {
            int counter = 0;
            for(j = 0; j < num; j++) {
                const int a = *(matrix + (i * num) + j);
                if(*(matrix + (i * num) + j) == 1) {
                    counter++;
                }
            }
            if(counter % 2 != 0) {
                RowCheck++;
                ErrorRow = i;
            }
        }
        // printf("%d ", RowCheck);

        // check column
        int ColumnCheck = 0, ErrorColunm = 0;
        for(i = 0; i < num; i++) {
            int counter = 0;
            for(j = 0; j < num; j++) {
                const int a = *(matrix + (i * num) + j);
                if(*(matrix + i + (j * num)) == 1) {
                    counter++;
                }
            }
            if(counter % 2 != 0) {
                ColumnCheck++;
                ErrorColunm = i;
            }
        }
        // printf("%d ", ColumnCheck);


        // check all
        if(ColumnCheck == 0 && RowCheck == 0) {
            printf("OK\n");
        }
        else if(ColumnCheck == 1 && RowCheck == 1) {
            printf("Change bit (%d,%d)\n", ErrorRow + 1, ErrorColunm + 1);
        }
        else {
            printf("Corrupt\n");
        }
    }

    return 0;
}
