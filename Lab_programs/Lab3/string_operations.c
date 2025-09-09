// Write a program to perform following string operations without using string
// handling functions:
// a.) length of the string
// b.) string concatenation
// c.) string comparison
// d.) to insert a sub string
// e.) to delete a substring
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int length_of_string(char* str) {
    int counter = 0;
    int i = 0;
    while (str[i] != '\0') {
        counter++;
        i++;
    }
    return counter;
}

char* string_concatenation(char* str1 , char* str2) {
    int len1 = length_of_string(str1);
    int len2 = length_of_string(str2);
    char* result = (char*) malloc(len1*len2*sizeof(char)+1) ;

    for (int i = 0; i <len1; i++) {
        result[i] = str1[i];
    }
    for (int i = len1; i <len1+len2; i++) {
        result[i] = str2[i-len1];
    }
    result[len1+len2+1] = '\0';

    return result;
}

int string_compare(char* str1 , char* str2) {
    int istrue=1;
    if(length_of_string(str1)!= length_of_string(str2)){
        return 0;
    }
    for (int i = 0; i < length_of_string(str1); i++) {
        if(str1[i]!=str2[i]){
            istrue =0;
        }
    }
    return istrue;
}

char* string_insert_sub_string(char str[], char sub[], int pos){
    char * result = malloc((length_of_string(str)+ length_of_string(sub)+1)*sizeof(char));
    int indexing =0;

    for (int i = 0; i < pos; i++) {
        result[i] = str[i];
    }

    for (int i = pos; i < (pos+ length_of_string(sub)); i++) {
        int temp =0;
        result[i] = sub[temp];
        temp++;
    }

    for (int i = (pos+ length_of_string(sub)); i < (length_of_string(str)+ length_of_string(sub)); i++) {
        int temp =pos;
        result[i] = str[temp];
        pos++;
    }
    result[(length_of_string(str)+ length_of_string(sub))] = '\0';

    return result;
}
//TODO delete substring
char* string_delete_sub_string(char str[], char sub[]){
    int len1 = length_of_string(str);
    int len2 = length_of_string(sub);
    char * result = malloc((len1-len2+1) * sizeof(char));
    for (int i = 0; i < len1; i++) {
        int j = 0;
        if(str[i]==sub[j]){
            for (int j = 0; j < len2; j++) {
                int temp = i;
                if(str[temp]!=sub[j]){
                    break;
                }

                temp++;

            }
        }
        else{
            j=0;
        }

    }

    return result;
}

int main(){
    printf("The length of the string is: %d\n", length_of_string("Hello"));

    char* concatenated_string = string_concatenation("hell","nah");
    printf("The hell + nah : %s\n", concatenated_string);
    free(concatenated_string);

    printf("magic vs hello : 0 false 1 true:- %d\n", string_compare("magic","hello"));

    char* sub_insert = string_insert_sub_string("helo","l",3);
    printf("sub insert:- %s\n", sub_insert);
    free(sub_insert);

    char* sub_delete = string_delete_sub_string("hellotheworld","the");
    printf("sub delete:- %s", sub_delete);
    free(sub_delete);

    return 0;
}



