#include <stdio.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}NODE;

NODE* HEAD;

NODE* createNode(){
    NODE* ptr = (NODE*)malloc(sizeof(NODE));
    return ptr;
}

void insertAtBegining( int value ){
    NODE* newNode = createNode();
    if( newNode==NULL ) return;

    newNode->data = value;
    if(HEAD==NULL){
        HEAD=newNode
    } else {
        newNode->next = HEAD;
        HEAD->prev = newNode;
        HEAD = newNode;
    }
}

void insertAtMiddle( int value, int position ){
    if(position==0){
        insertAtBegining(value);
        return;
    }

    NODE * newNode = createNode();
    if(newNode==NULL) return;

    NODE* temp = HEAD;
    for(int i=0;i<position;i++){
        if(temp==NULL) return;
        temp=temp->next;
    }
    newNode->data = value;
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void insertAtEnd(int value){
    if(HEAD=NULL){
        insertAtBegining();
        return;
    }
    NODE* newNode = createNode();
    if(newNode==NULL) return;

    NODE* temp = HEAD;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;
}

void deleteAtBegining(){
    if(HEAD==NULL) return;

    HEAD->next->prev =NULL;
    NODE* temp = HEAD;
    HEAD = HEAD->next;
    free(temp);
}
void deleteAtMiddle(int position){
    NODE* temp = HEAD;
    for(int i=0; i<position;i++){
        if(temp==NULL) return;
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}
void deleteAtEnd(){
    NODE* temp = HEAD;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void traversal(NODE* HEAD){
    NODE* temp = HEAD;
    printf("\n\nList elements are - \n");
    while(temp != NULL) {
        printf("%d --->",temp->data);
        temp = temp->next;
    }
}
int search(NODE* HEAD, int data){
    NODE* temp = HEAD;
    int currentPosition = 0;
    while( temp->next!=NULL ){
        if(temp->data == data) return currentPosition;
        temp = temp->next;
        currentPosition++;
    }
}