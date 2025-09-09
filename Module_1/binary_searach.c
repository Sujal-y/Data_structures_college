#include<stdio.h>
 int binarysearch(int array[],int key,int size){
    int pos;
    int high = size-1,low=0,mid = (high+low) /2;
    while(high > low){
        if(array[mid] == key){
            pos = mid;
            break;
        }
        else if(array[mid]>key){
            high = mid;
            mid = (high+low) /2;
        }
        else if(array[mid]<key){
            low = mid;
            mid = (high+low) /2;
        }
    }
    return pos;
}
 int main(){
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
     printf("%d", binarysearch(array,4,10));

    return 0;
}