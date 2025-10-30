// Design and implement a C program using suitable data structures and memory management
// techniques to automate the process of Class Representative Election.
// The application should follow the steps below:
// • Accept input from the user for:
// ➢ Number of students (voters) present in the class
// ➢ Number of candidates contesting the election
// ➢ Names of each candidate
// • Allocate memory dynamically using calloc() to store:
// ➢ An integer array for counting votes (index represents candidate number; index
// 0 is reserved for foul votes)
// ➢ An array of strings (2D character array) for storing candidate names
// • The voting process must be interactive:
// ➢ A faculty member initiates the voting process (e.g., by pressing a specific key)
// ➢ Each student enters the serial number of the candidate they wish to vote for
// ➢ If an invalid number is entered (i.e., not matching any candidate), it should be
// counted as a foul vote
// ➢ After every vote, a confirmation (e.g., a beep sound or message) is given
// • After all students have cast their votes:
// ➢ Display the total votes received by each candidate
// ➢ Display the total number of foul votes
// ➢ Determine and display the winner (candidate with maximum votes)
// Constraints:
// • Do not use struct or structure concepts
// • Use pointers and dynamic memory allocation functions such as calloc()
// • Optionally, use a recursive function to display results or find the winner.


#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
    printf("enter how many voters");
    int number_of_voters;
    scanf("%d",&number_of_voters);

    printf("number of people standing for the election");
    int number_of_candiates;
    scanf("%d",&number_of_candiates);


    int* votes = (int*)calloc(number_of_candiates + 1, sizeof(int));

    char **candidate_names = (char **) calloc(number_of_candiates, sizeof(char *));

    //gets the candidates names
    for (int i=0;i<number_of_candiates;i++) {
        char name[50];
        printf("enter candidate %d name ",i+1);
        scanf("%s",name);

        int name_length = strlen(name);
        *(candidate_names + i) = (char*)calloc(name_length + 1, sizeof(char));
        strcpy(*(candidate_names+i),name);

    }

    // // //prints candidates name
    // for (int i =0 ;i<number_of_candiates;i++) {
    //     printf("\n %s",*(candidate_names+i));
    // }

    //voting process
    for (int i = 0; i < number_of_voters; i++) {
        printf("enter which candidate you wanna vote for \n");
        for (int i =0 ;i<number_of_candiates;i++) {
            printf("%s :- %d \n",*(candidate_names+i),(i+1));
        }
        int choice;
        scanf("%d",&choice);

        if (choice<=number_of_candiates) {
            *(votes+choice) +=1;
        }
        else {
            *(votes) +=1;
        }
        printf("Votes registered\n");

    }

    //total votes display
    for (int i=0;i<number_of_candiates;i++) {
        printf("Candidate : %s has %d votes\n",*(candidate_names+i),*(votes+1+i));
    }

    //foul votes
    printf("foul votes:- %d\n",*(votes));

    //winner
    int max_index=1;

    for (int i = 1; i <= number_of_candiates; i++) {
        if (*(votes+i) > *(votes+max_index)) {
            max_index =i;
        }
    }

    printf("the winner is %s with %d votes",*(candidate_names+max_index-1),*(votes+max_index));




}
