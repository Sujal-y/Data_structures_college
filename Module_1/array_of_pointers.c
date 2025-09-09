#include<stdio.h>
int main(){
    int a[5] = {1,43,54,80,90};
    int* ptr = a;
    printf("%d",*(ptr+2));


}