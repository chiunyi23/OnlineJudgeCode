#include <stdio.h>

int main()
{
    int num;
    while(scanf("%d", &num) != EOF) {
        int matrix[100][100];
        int input;
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < num; j++) {
                scanf("%d", &input);
                matrix[i][j] = input;
            }
        }
        int is_symmetry = 1;
        for(int i = 0; i < num; i++) {
            for(int j = 0; j < num - i; j++) {
                // printf("%d %d\n", matrix[i][j], matrix[j][i]);
                if(matrix[i][j] != matrix[j][i]) {
                    is_symmetry = 0;
                    break;
                }
            }
        }
        if(is_symmetry == 1) {
            printf("Yes!\n");
        }
        else {
            printf("No!\n");
        }
        
    }

    return 0;
}