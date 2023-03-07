#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int val;
    struct node *next;
} NODE;
NODE* FRONT;
NODE* REAR;

// same as insert at end
void enqueue (int data){ 
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->val = val;
    ptr->next = NULL;
    if(FRONT==NULL){
        FRONT = ptr;
        REAR = ptr;
    } else {
        REAR->next = ptr;
        REAR = ptr;
    }
}
// same as delete at begining
int dequeue(){ 
    if(FRONT==NULL) {
        printf("Queue Underflow");
        return;
    }
    NODE* ptr = FRONT;
    int data = FRONT->data;
    FRONT = FRONT->next;
    free(ptr);
    return data;
}
int peek(){
    return FRONT!=NULL ? FRONT->val : -1;
}
bool isEmpty(){
    return FRONT==NULL ? true : false;
}
void print(){
    NODE* ptr = FRONT;
    while(ptr != NULL){
        printf("%d | ", ptr->data );
        ptr = ptr->next;
    }
}

int main (){
    
}
