#include <stdio.h>
#include <string.h>

char arr[200][200];
int row, column;
int counter;

void walk(int i, int j) {
    if(arr[i][j] == '.' || arr[i][j] == '@') {
        counter++;
        arr[i][j] = '#';
        walk(i + 1, j);
        walk(i - 1, j);
        walk(i, j + 1);
        walk(i, j - 1);
    }
}

int main()
{
    while(~scanf("%d %d", &column, &row)) {
        if(column == 0 && row == 0) break;
        memset(arr, 0, sizeof(arr));
        counter = 0;
        int start_x, start_y;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++) {
                scanf(" %c", &arr[i][j]);
                if(arr[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
            }
                
        walk(start_x, start_y);
        printf("%d\n", counter);
        // for(int i = 0; i < row; i++) {
        //     for(int j = 0; j < column; j++) {
        //         printf("%c", arr[i][j]);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}

// #include <stdio.h>
// char places[22][22];
// int steps;
// void slu(int x,int y)
// {
//     if(places[y][x]=='.'||places[y][x]=='@')
//     {
//         steps++;
//         places[y][x]='#';
//         slu(x+1,y);
//         slu(x-1,y);
//         slu(x,y+1);
//         slu(x,y-1);
//     }
// }
// int main()
// {
//     int x,y,i,j;
//     scanf("%d %d",&x,&y);
//     while(x)
//     {
//         steps=0;
//         for(i=1;i<=y;i++)
//             scanf("%s",&places[i][1]);
//         for(i=0;i<x+2;i++)
//             places[0][i]=places[y+1][i]='#';
//         for(i=0;i<y+2;i++)
//             places[i][0]=places[i][x+1]='#';
//         for(i = 0; i < x + 2; i++) {
//             for(j = 0; j < y + 5; j++) {
//                 printf("%c", places[i][j]);
//             }
//             printf("\n");
//         }
//         for(i=1;i<=y;i++)
//             for(j=1;j<=x;j++)
//                 if(places[i][j]=='@')
//                     slu(j,i);
//         printf("%d\n",steps);
//         scanf("%d %d",&x,&y);
//     }
//     return 0;
// }
