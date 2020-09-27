
// //去重全排列的递归实现
// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>
// void Swap(char *a, char *b)
// {
// 	char t = *a;
// 	*a = *b;
// 	*b = t;
// }
// //在pszStr数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等
// bool IsSwap(char *pszStr, int nBegin, int nEnd)
// {
// 	for (int i = nBegin; i < nEnd; i++)
// 		if (pszStr[i] == pszStr[nEnd])
// 			return false;
// 	return true;
// }
// //k表示当前选取到第几个数,m表示共有多少数.
// void AllRange(char *pszStr, int k, int m)
// {
// 	if (k == m)
// 	{
// 		static int s_i = 1;
// 		printf("%s\n", pszStr);
// 	}
// 	else
// 	{
// 		for (int i = k; i <= m; i++) //第i个数分别与它后面的数字交换就能得到新的排列
// 		{
// 			if (IsSwap(pszStr, k, i))
// 			{
// 				Swap(pszStr + k, pszStr + i);
// 				AllRange(pszStr, k + 1, m);
// 				Swap(pszStr + k, pszStr + i);
// 			}
// 		}
// 	}
// }
// void Foo(char *pszStr)
// {
// 	AllRange(pszStr, 0, strlen(pszStr) - 1);
// }
// int main()
// {
// 	char szTextStr[] = "aacc";
// 	Foo(szTextStr);
// 	return 0;
// }


#include <stdio.h>
long long int counter;

void Swap(char A[], int q, int p) {
    int temp = A[p];
    A[p] = A[q];
    A[q] = temp;
}

int is_swap(char A[], int begin, int end) {
    for(int i = begin; i < end; i++)
        if(A[i] == A[end])
            return 0;
    return 1;
}

void printArray(char A[], int num) {
    for(int i = 0; i <= num; i++) {
        printf("%c", A[i]);
    }
    printf("\n");
}

void perm(char A[], int p, int q) {
    if(p == q) {
        counter++;
        printArray(A, q);
    }
    else {
        for(int i = p; i < q; i++) {
            if(is_swap(A, p, i)) {
                Swap(A, p, i);
                perm(A, p + 1, q);
                Swap(A, p, i);
            }
        }
    }
//     int j, k, l, r;

//     while(1){
//         for(int i=0; i<q; i++)
//             printf("%c",A[i]);
//         counter++;
//         printf("\n");

//         for(j=q-2; j>=0 && A[j]>=A[j+1]; j--)
//             continue;

//         if(j < 0)
//             return ;

//         for(k=q-1; k>j && A[k]<=A[j]; k -- )
//             continue;

//         Swap(A, j, k);

//         for(l=j+1, r=q-1; l<r ; l++, r--)
//             Swap(A, l,r);
//     }
}

void insertion_sort(char arr[], int n) {
    int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
}

int main()
{
    int num;
    char A[1000];
    counter = 0;
    scanf("%d", &num);
    scanf("%s", A);
    insertion_sort(A, num);
    perm(A, 0, num);
    printf("%lld\n", counter);
    return 0;
}


