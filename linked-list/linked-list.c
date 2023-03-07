#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} NODE;

NODE* HEAD;

NODE* createNode(){
    return (NODE*) malloc(sizeof(NODE));
}
NODE* nodeAtPostion(int position){
    NODE* temp = HEAD;
    int currentPosition = 0;
    while( temp != NULL ){
        if( currentPosition == position ) return temp;
        temp = temp->next;
        currentPosition++;
    }
    return NULL;
}

void insertAtBegining(int data){
    NODE* newNode = createNode();
    if(newNode==NULL) return;

    newNode->data = data;
    newNode->next = HEAD;
    HEAD = newNode
}

void insertAtMiddle(int data, int position){
    if( position==0 ){
        insertAtBegining(int data, NODE* HEAD);
        return;
    }
    NODE* newNode = createNode();
    if(newNode==NULL) return;
    
    newNode->data = data;
    NODE* prevNode = nodeAtPostion(position-1);
    if( prevNode==NULL ) return

    newNode->next  = prevNode->next;
    prevNode->next = newNode;
}
void insertAtEnd(int data){
    NODE* newNode = createNode();
    if(newNode==NULL) return;
    NODE* temp = HEAD;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->data = data;
}
void deleteAtBegining(){
    if(HEAD==NULL) return;
    NODE* temp = HEAD;
    if(HEAD->next != NULL)
        HEAD = HEAD->next;
    free(temp);
}
void deleteAtMiddle(NODE* HEAD, int position){
    NODE* prevNode = nodeAtPostion(HEAD,position-1);
    if(prevNode==NULL) return;

    NODE* temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    free(temp);
}
void deleteAtEnd(int data, NODE* HEAD){
    if( HEAD->next == NULL ){
        deleteAtBegining(HEAD);
        return;
    }
    NODE* prevTemp = HEAD; 
    NODE* temp = HEAD->next;
    while( temp->next != NULL ){
        prevTemp = temp;
        temp = temp->next;
    }
    prevTemp->next = NULL;
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