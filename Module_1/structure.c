#include<stdio.h>

int main() {
    int number_of_students =3;
    struct student {
        char name[10];
        int roll_no;
        int marks;
    }s1[number_of_students];


    //initialising the array of structures
    for(int i=0;i<number_of_students;i++) {
        printf("Enter name: ");
        scanf("%s",&s1[i].name);
        printf("Enter roll_no: ");
        scanf("%d",&s1[i].roll_no);
        printf("Enter marks: ");
        scanf("%d",&s1[i].marks);
    }

    //Displaying the array of structures
    for(int i=0;i<number_of_students;i++) {
        printf("Student %d \n",i+1);
        printf("name: %s \n",s1[i].name);
        printf("roll_no:- %d \n",s1[i].roll_no);
        printf("marks:- %d \n",s1[i].marks);
    }




    return 0;
}