#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int A[21][21];
int pass[20], D[20];
int v, e, k, min;


int isPass(int a, int n){
    int i;
    for (i=1; i<=n; i++)
        if (pass[i] == a)
            return 1;
    return 0;
}

void find(int p, int n){
    pass[n]=p;
    int i, j;

    if (p == v){
        for (i=0; i<n; i++)
            D[i]=A[pass[i]][pass[i+1]];

        for (i=0; i<n; i++){
            for (j=i+1; j<n; j++){
                if (D[j] < D[i]){
                    int t=D[i];
                    D[i]=D[j];
                    D[j]=t;
                }
            }
        }

        int t=0;
        for (i=0; i<n-k; i++)
            t+=D[i];

        if (t < min)
            min=t;
    }

    for (i=1; i<=v; i++)
        if (A[i][p] != INF && !isPass(i, n))
            find(i, n+1);
    return;
}
int main(){
    while (scanf("%d", &v) == 1){
        scanf("%d %d", &e, &k);

        for (int i=0; i<=v; i++)
            for (int j=0; j<=v; j++)
                A[i][j]=INF;

        int i, x, y, l;
        for (i=0; i<e; i++){
            scanf("%d %d %d", &x, &y, &l);
            A[x][y]=A[y][x]=l;
        }

        min=INF;
        find(1, 0);
        printf("%d\n", min);
    }
    return 0;
}

