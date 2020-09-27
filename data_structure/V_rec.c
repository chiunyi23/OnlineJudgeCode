#include <stdio.h>
#include <string.h>

void preorder(char *inorder, char *postorder, int len) { 
    //printf("\n----\nlen: %d\ninorder: %s\npostorder: %s\n-------\n", len, inorder, postorder);
    if(len == 0)
        return;
    // int l = strlen(postorder);
    char middle = postorder[len-1];
    printf("%c", middle);

    int i, seperate_point = 0;
    for(i = 0; i < len; i++) {
        if(middle == inorder[i]) {
            seperate_point = i;
            break;
        }
    }

    int left = seperate_point;
    int right = len - seperate_point - 1;
    //printf("\nleft");
    preorder(inorder, postorder, left);
    //printf("\nright");
    preorder(inorder + seperate_point + 1, postorder + seperate_point, right);

}

int main()
{
    char inorder[27];
    char postorder[27];

    while(scanf("%s", inorder) != EOF) {
        scanf("%s", postorder);
        int len = strlen(inorder);
        preorder(inorder, postorder, len);
        printf("\n");
    }
    return 0;
}
