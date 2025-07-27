//Linear search
#include <stdio.h>

int main() {
    int array[] = {1,2,3,4,5,6};
    int array_length = 6;
    int key = 5;
    for(int i = 0;i<array_length;i++){
        if(array[i] == key){
            printf("found element at %d index ",i);
        }
    }
    return 0;
}