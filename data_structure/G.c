#include <stdio.h>
#define MAX 1000

void show(int matrix[][3]) {
    int counter = 1;
    for(int i = 0; i < matrix[0][0]; i++) {
        for(int j = 0; j < matrix[0][1]; j++) {
            if(matrix[counter][0] == i && matrix[counter][1] == j) {
                printf("%d ", matrix[counter][2]);
                counter++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    int row_num, col_num;
    while(~scanf("%d %d", &row_num, &col_num)) {
        int element, counter = 1;
        int matrix[MAX][3];
        matrix[0][0] = row_num;
        matrix[0][1] = col_num;
        matrix[0][2] = 0;
        for(int i = 0; i < row_num; i++) {
            for(int j = 0; j < col_num; j++) {
                scanf("%d", &element);
                if(element != 0) {
                    matrix[counter][0] = i;
                    matrix[counter][1] = j;
                    matrix[counter][2] = element;
                    counter++;
                    matrix[0][2]++;
                }
            }
        }
        // transport matrix
        int trans_matrix[matrix[0][2] + 1][3];
        trans_matrix[0][0] = matrix[0][1];
        trans_matrix[0][1] = matrix[0][0];
        trans_matrix[0][2] = trans_matrix[0][2];
        counter = 1;
        for(int col = 0; col < matrix[0][1]; col++) {
            for(int j = 1; j <= matrix[0][2]; j++) {
                if(matrix[j][1] == col) {
                    trans_matrix[counter][0] = matrix[j][1];
                    trans_matrix[counter][1] = matrix[j][0];
                    trans_matrix[counter][2] = matrix[j][2];
                    counter++;
                }
            }
        }
        show(trans_matrix);
    }

    return 0;
}