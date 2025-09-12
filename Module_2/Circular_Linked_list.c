#include<stdio.h>
#include<stdlib.h>
//todo give comments
struct cnode{
    int data;
    struct cnode* next;
};

struct cnode* createnode(int data){
    struct cnode* newnode =(struct cnode*)malloc(sizeof(struct cnode));
    newnode->data = data;
    newnode -> next = NULL;
    return newnode;
}

//INSERTING AT BEGINNING USING THE LAST PTR
void insert_at_first_using_tail(struct cnode** tail , int data){

    if(*tail == NULL){
        struct cnode* newnode = createnode(data);
        *tail = newnode;
        (*tail) -> next = *tail;
        return;
    }


    struct cnode* newnode = createnode(data);
    newnode -> next = (*tail)->next;
    (*tail)->next = newnode;
}

//INSERTING AT END USING THE LAST PTR
void insert_at_end_using_tail(struct cnode** tail , int data){

    if(*tail == NULL){
        struct cnode* newnode = createnode(data);
        *tail = newnode;
        (*tail) -> next = *tail;
        return;
    }

    struct cnode* temp = *tail;
    struct cnode* newnode = createnode(data);

    newnode->next = (*tail)->next;
    (*tail)->next = newnode;
    *tail = newnode;
}

//INSERTING AT FIRST USING THE FIRST PTR
void insert_at_first_using_head(struct cnode** head , int data){

    if(*head == NULL){
        struct cnode* newnode = createnode(data);
        *head = newnode;
        (*head) -> next = *head;
        return;
    }


    struct cnode* newnode = createnode(data);
    struct cnode* temp = *head;
    newnode -> next = *head;

    while(temp->next != *head){
        temp = temp ->next;
    }
    temp -> next = newnode;
    *head = newnode;
}

//INSERTING AT END USING THE FIRST PTR
void insert_at_end_using_head(struct cnode** head , int data){

    if(*head == NULL){
        struct cnode* newnode = createnode(data);
        *head = newnode;
        (*head) -> next = *head;
        return;
    }


    struct cnode* newnode = createnode(data);
    struct cnode* temp = *head;
    newnode -> next = *head;

    while(temp->next != *head){
        temp = temp ->next;
    }
    temp -> next = newnode;

}

//DELETING AN ELEMENT FROM THE BEGINNING USING LAST POINTER
void delete_at_start_using_tail(struct cnode** tail){

    if(*tail == NULL){
        printf("Empty list\n");
        return;
    }

    if((*tail)->next == *tail){
        free(*tail);
        return;
    }

    struct cnode* temp = *tail;
    temp = temp-> next;//temp is at index 0
    (*tail)->next = temp->next;//temp->next give index 1
    free(temp);
}

//DELETING AN ELEMENT FROM THE BEGINNING USING FIRST POINTER
void delete_at_start_using_head(struct cnode** head){

    if(*head == NULL){
        printf("empty\n");
        return;
    }

    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }
    struct cnode* temp = *head;
    while(temp->next != *head){
        temp = temp ->next;
    }
    temp ->next = (*head)->next;
    *head = temp->next;

}

//DELETING AN ELEMENT FROM THE END USING A LAST POINTER
void delete_at_end_using_tail(struct cnode** tail){

    //empty case
    if((*tail) == NULL){
        return;
    }
    //one node
    if((*tail)->next == *tail){
        free(*tail);
        *tail = NULL;
        return;
    }
    struct cnode* temp = *tail;

    while (temp->next != *tail){
        temp = temp ->next;
    }
    temp->next = (*tail)->next;
    free(*tail);
    *tail = temp;

}

//DELETING AN ELEMENT FROM THE END USING A head POINTER
void delete_at_end_using_head(struct cnode** head, struct cnode**send_back_new_tail){

    //empty case
    if((*head) == NULL){
        return;
    }
    //one node
    if((*head)->next == *head){
        free(*head);
        *head = NULL;
        return;
    }
    struct cnode* temp = *head;
    struct cnode* prev_temp;
    while (temp->next != *head){
        prev_temp = temp;
        temp = temp ->next;
    }
    prev_temp ->next = *head;
    free(temp);

    *send_back_new_tail = prev_temp;
}


void print(struct cnode* tail) {
    printf("The circular linked list: \n");

    if (tail == NULL) {
        printf("EMPTY\n");
        return;
    }

    // 2. The head is the node immediately after the tail.
    struct cnode* head = tail->next;
    struct cnode* temp = head;

    // 3. Use a do-while loop to traverse the list.
    // This ensures the loop body runs at least once.
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); // The loop stops once we've returned to the head.

    printf("(back to head: %d)\n", head->data);
}

int main(){
    struct cnode* tail = NULL;

//    print(tail);
//    insert_at_first_using_tail(&tail,5);
//    print(tail);
//
//    insert_at_end_using_tail(&tail,10);
//    print(tail);

    insert_at_end_using_tail(&tail,10);
    insert_at_end_using_tail(&tail,20);
    insert_at_end_using_tail(&tail,30);
    insert_at_end_using_tail(&tail,40);
    insert_at_end_using_tail(&tail,50);
    print(tail);

    struct cnode* head = tail->next;

//    insert_at_first_using_head(&head,0);
//    tail = tail->next;
//    print(tail);

//    insert_at_end_using_head(&head,60);
//    tail = tail->next;
//    print(tail);

//    delete_at_start_using_tail(&tail);
//    print(tail);

//    delete_at_start_using_head(&head);
//    print(tail);

//    delete_at_end_using_tail(&tail);
//    delete_at_end_using_tail(&tail);
//    print(tail);

//    delete_at_end_using_head(&head,&tail);
//    print(tail);




    return 0;
}