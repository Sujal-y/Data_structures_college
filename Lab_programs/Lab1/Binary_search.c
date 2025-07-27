/// binary search
#include <stdio.h>


int main() {
    int array[] = {1,2,3,4,5,6};
    int array_length = 6;
    int mid,start=0,end=array_length-1;
    mid = array_length/2;
    int key = 5;
    while(1){

        if(array[mid] == key){
            printf("element found at index %d",mid);
            break;
        }
        else if(array[mid] < key){

            start = mid;
            mid = (start+end) /2;

        }
        else if(array[mid] > key){

            end = mid;
            mid = (start+end) /2;
        }
        else{
            break;
        }

    }

    return 0;
}