#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createnode(int data){
    struct Node* newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode -> next = NULL;
    return newnode;
}

//basic list generation
void basic_list(struct Node** head) {
    struct Node *newnode = createnode(5);
    *head = newnode;
    struct Node* temp = *head;
    temp->next = createnode(10);
    temp = temp->next;
    temp->next = createnode(15);
    temp = temp->next;
    temp->next = createnode(20);
    temp = temp->next;
    temp->next = createnode(25);

}

//1
void insert_before_element(struct Node** head){
    struct Node* temp = *head;
    struct Node* prev_temp = NULL;
    int data;
    int after_target;
    printf("enter data to be entered:- ");
    scanf("%d",&data);
    printf("the data to be entered before which element:- ");
    scanf("%d",&after_target);

    if (temp == NULL) {
        printf("empty set");
        return;
    }

    while (temp->data != after_target) {
        prev_temp=temp;
        temp = temp->next;
    }

    //Check again after the loop in case the target position is right after the last node
    if(temp->next == NULL && temp->data != after_target){
        printf("element not there!!");
        return;
    }

    if (prev_temp == NULL) {
        *head = createnode(data);
        (*head)->next = temp;
        printf("insertion completed!\n");
        return;
    }

    struct Node* newnode = createnode(data);
    newnode->next = temp->next;
    prev_temp->next = newnode;
    printf("insertion completed!\n");
}

//2
void insert_after_element(struct Node** head){
    struct Node* temp = *head;
    int data;
    int before_target;
    printf("enter data to be entered:- ");
    scanf("%d",&data);
    printf("the data to be entered after which element:- ");
    scanf("%d",&before_target);

    if (temp == NULL) {
        printf("empty set");
        return;
    }

    while (temp->data != before_target) {
        temp = temp->next;
    }

    //Check again after the loop in case the target position is right after the last node
    if(temp->next == NULL && temp->data != before_target){
        printf("element not there!!");
        return;
    }

    struct Node* newnode = createnode(data);
    newnode->next = temp->next;
    temp->next = newnode;
    printf("insertion completed!\n");
}
//3
void deletion_element(struct Node ** node) {

};

//deletion of a node in a position using head
void deletion_at_pos(struct Node** head, int loc){

    struct Node* temp = *head;

    //case: empty list
    if(temp == NULL){
        printf("EMPTY LIST!! \n");
        return;
    }

    //case : deleting first node
    if (loc == 0) {
        *head = temp -> next;
        free(temp);
        return;
    }

    struct Node* prev_temp = temp;

    //traverses temp to the node to be deleted
    int i = 0;
    while(i < loc){
        prev_temp = temp;
        temp = temp->next;
        i++;
    }
    //if temp is past the end of the list
    if(temp == NULL){
        printf("out of bounds \n");
        return;
    }
    prev_temp -> next = temp -> next;
    free(temp);

}

//searching an element in singly linked list
void search(struct Node** head, int key){
    struct Node* temp = *head;

    //traverses temp to the last node
    int i=0;
    while(temp != NULL){
        //if element found it will end the function using return
        if(temp->data == key){
            printf("Found the element %d at index %d",key,i);
            return;
        }
        temp = temp-> next;
        i++;
    }
    printf("element %d does not exist in the list\n",key);
}


//4
void print(struct Node** head){
    struct Node* temp = *head;
    printf("The singly linked list:- \n");

    if(temp == NULL){
        printf("NULL\n");
        return;
    }

    while(temp != NULL){
        printf("%d -> ",(temp ->data));
        temp = temp->next;
    }
    printf("NULL\n");
}

//5
void reverse_linked_list_5(struct Node** head){
    struct Node* current = *head;
    struct Node* next;
    struct Node* prev = NULL;

    //case : the list is empty
    if(current == NULL){
        printf("Empty list\n");
        return;
    }


    while(current != NULL){
        next = current->next; // saves the next node address
        current->next = prev; // changes current node to previous node address
        prev = current; // updates previous address as current for the next node
        current = next; //current node is switched to next node
    }

    //the head is changed to the tail of the original list
    *head = prev;
}


void help_msg() {
    printf("--------------- \n");
    printf("1.Insert an element before another specified element in the list\n");
    printf("2.Insert an element after another specified element in the list\n");
    printf("3.Delete a specified element from the list\n");
    printf("4.Traverse the list and display all elements\n");
    printf("5.Reverse the linked list\n");
    printf("6.Sort the list in ascending order\n");
    printf("7.Delete every alternate node in the list\n");
    printf("8.Insert an element into a sorted linked list while maintaining the sorted order\n");
    printf("9 or e :exit\n");
    printf("--------------- \n");
}


int main(){
    struct Node* head = NULL;

    printf("You are entering menu driven linked list implementation, a basic list is created \n");
    printf("type h for help\n");
    char choice;
    basic_list(&head);
    while (1) {
        printf("choice: ");
        scanf(" %c",&choice);

        //TODO 3 6 7 8
        switch (choice) {
            case 'h':help_msg();
                break;
            case 'e':printf("exiting");
                exit(0);
                break;
            case '9':printf("exiting");
                exit(0);
                break;
            case '1':insert_before_element(&head);
                break;
            case'2':insert_after_element(&head);
                break;
            case '3':deletion_element(&head);
                break;
            case'4':print(&head);
                break;
            case '5':reverse_linked_list_5(&head);
                break;

        }

    }
    return 0;
}
