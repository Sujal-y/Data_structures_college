#include<stdio.h>
int main(){
    int a[5] = {1,2,3,4,5};
    int (*b)[5] = NULL;
    for (int i = 0; i < 5; ++i) {
        *b[i] = (int) &a[i];
    }
    printf("%d",*b[4]);

}