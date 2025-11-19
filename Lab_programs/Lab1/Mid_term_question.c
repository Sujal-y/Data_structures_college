// A bank wants to record the last 50 transactions of a customer
// (deposit/withdrawal of amounts).
// Using array of pointers, design the C program for the following
// questions:
// A) Store 50 transactions.
// B)Allow the user to input deposits (+ve) and withdrawals (–ve).
// C) Write a function (using pointer arithmetic) to compute the
//  running balance after each transaction.
// D) Display transactions in reverse order using only pointers.

#include<stdio.h>
#include <stdlib.h>

//C
void current_balance(int* array , int count , int* running_balance) {
    int sum =0;
    if (array ==NULL) {
        *running_balance = 0;
        return;
    }
    for (int i=0;i<count;i++) {
        sum += *(array+i);
    }
    *running_balance = sum;
}

void display(int* array , int count){
    if (array ==NULL) {
        return;
    }
    printf("last %d transactions \n",count);
    int temp =1;
    for (int i = count;i > 0;i--) {
        printf("%d.Amount: %d\n",temp++,*(array+i));
    }

}


int main() {
    //A
    int * ptr = malloc(sizeof(int)*50);
    int count =0;
    int running_balance =0;

    while (1) {
        //B
        printf("enter the following \n 1.deposit \n 2.withdraw \n 3.show balance \n 4. show last transaction \n 5.break \n");

        int choice;
        scanf("%d",&choice);

        if (choice == 1) {//deposit
            printf("enter amount \n");
            int temp = 0;
            scanf("%d",&temp);
            *(ptr+count) = temp;
            count++;
            current_balance(ptr,count,&running_balance);

        }

            if (choice == 2) {//withdraw
                printf("enter amount \n");
                int temp = 0;
                scanf("%d",&temp);
                *(ptr+count) = (-1)*temp;
                count++;
                current_balance(ptr,count,&running_balance);
            }

            if (choice == 3) {
                current_balance(ptr,count,&running_balance);
                printf("current balance: %d \n",running_balance);
            }

            if (choice == 4) {
                display(ptr,count);
            }

            if (choice == 5) {
                exit(0);
            }



        }


    }
