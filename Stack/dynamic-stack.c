#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int val;
    struct node *next;
} NODE;
NODE* HEAD;

// same as insert at begining
void push (int data){ 
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    ptr->val = val;
    ptr->next = HEAD;
    HEAD=ptr;
}
// same as delete at begining
int pop(){ 
    NODE* ptr = HEAD;
    int data = HEAD->data;
    HEAD = HEAD->next;
    free(ptr);
    return data;
}
int peek(){
    return HEAD!=NULL ? HEAD->val : -1;
}
bool isEmpty(){
    return HEAD == NULL ? true : false;
}
void print(){
    NODE* ptr = HEAD;
    while(ptr != NULL){
        printf("%d | ", ptr->data );
        ptr = ptr->next;
    }
}

int main (){
    
}
