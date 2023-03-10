#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}NODE;

NODE* HEAD;

void insertAtBegining( int value ){
    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    if(newNode==NULL) return;
    newNode->data = value;

    if(HEAD==NULL){
        newNode->next = newNode
    } else {
        newNode->next = HEAD;
        NODE* temp = HEAD;
        while(temp->next!=HEAD){
            temp = temp->next;
        }
        temp->next = newNode;
        HEAD = newNode;
    }
}

void insertAtMiddle(int value, int position){
    if(position==0){
        insertAtBegining(value);
        return;
    }

    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    if(newNode==NULL) return;

    NODE* temp = HEAD;
    for(int i=0;i<position-1;i++){
        if(temp->next==HEAD) return;
        temp=temp->next;
    }
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtEnd( int value ){
    if(HEAD==NULL){
        insertAtBegining(value);
        return;
    }

    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    if(newNode==NULL) return;

    NODE* temp = HEAD;
    while(temp->next!=HEAD){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = HEAD;
    newNode->data = value;
}

void deleteAtBegining(){
    NODE* temp = HEAD;
    while(temp->next!=HEAD){
        temp = temp->next;
    }
    temp->next = HEAD->next;
    NODE* temp2 = HEAD;
    HEAD = HEAD->next;
    free(temp2);
}

void deleteAtMiddle(int position){
    if(HEAD==NULL) return;

    NODE* temp = HEAD;
    for(int i=0;i<position-1;i++){
        // Reached last node
        // position greater than length
        if(temp->next==HEAD) return;
        temp=temp->next;
    }
    NODE* temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
}
void deleteAtEnd(){
    // Empty
    if(HEAD==NULL) return;
    // One Node
    if(HEAD->next==HEAD)
        HEAD = NULL;

    NODE* temp1 = HEAD;
    NODE* temp2 = HEAD->next;
    while(temp2!=HEAD){
        temp1 = temp2;
        temp2 = temp2->next;
    }
    temp1->next = HEAD;
    free(temp2);
}


void traversal(NODE* HEAD){
    NODE* temp = HEAD;
    printf("\n\nList elements are - \n");
    while(true) {
        printf("%d --->",temp->data);
        temp = temp->next;
        if(temp->next==HEAD) break;
    }
}
int search(NODE* HEAD, int data){
    NODE* temp = HEAD;
    int currentPosition = 0;
    while( temp->next!=HEAD ){
        if(temp->data == data) return currentPosition;
        temp = temp->next;
        currentPosition++;
    }
}