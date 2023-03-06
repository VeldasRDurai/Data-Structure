#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} NODE;

NODE* createNode();
NODE* nodeAtPostion(NODE* HEAD, int position);
void insertAtBegining(int data, NODE* HEAD);
void insertAtMiddle(int data, NODE* HEAD, int position);
void insertAtEnd(int data, NODE* HEAD);
void traversal(NODE* HEAD){
    NODE* temp = HEAD;
    printf("\n\nList elements are - \n");
    while(temp != NULL) {
        printf("%d --->",temp->data);
        temp = temp->next;
    }
}

int main() {
    NODE* HEAD;
    insertAtBegining(1,HEAD);
    insertAtBegining(2,HEAD);
    insertAtBegining(3,HEAD);
    insertAtBegining(4,HEAD);
    traversal(HEAD);
}

NODE* createNode(){
    return (NODE*) malloc(sizeof(NODE));
}
NODE* nodeAtPostion(NODE* HEAD, int position){
    NODE* temp = HEAD;
    int currentPosition = 0;
    while( temp->next !=NULL ){
        if( currentPosition == position ){
            return temp
        }
        temp = temp->next;
    }
    return NULL;
}

void insertAtBegining(int data, NODE* HEAD){
    NODE* newNode = createNode();
    newNode->data = data;
    newNode->next = HEAD;
    HEAD = newNode
}
void insertAtMiddle(int data, NODE* HEAD, int position){
    NODE* newNode = createNode();
    newNode->data = data;
    
    if( position==0 ){
        insertAtBegining(int data, NODE* HEAD);
        return;
    }

    NODE* prevNode = nodeAtPostion(position-1);
    if( prevNode==NULL ) return

    newNode->next  = prevNode->next;
    prevNode->next = newNode;
}
void insertAtEnd(int data, NODE* HEAD){
    NODE* newNode = createNode();
    NODE* temp = HEAD;
    while( temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode.data = data;
}