#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 1000

int top = -1;
int STACK[N];

void push( int data ){
    if(top == N-1) {
        printf("Stack Overflow\n");
        return;
    }
    STACK[top] = data;
    top = top+1;
}
int pop(){
    if(top == -1){
        printf("Stack underflow\n");
        return -1;
    }
    int x = STACK[top];
    top = top-1;
    return x;
}
int peek(){
    return STACK[top];
}
bool isEmpty(){
    return top == -1 ? true : false;
}
bool isFull(){
    return top == N-1 ? true : false;
}
void print(){
    for(int i=0;i<=top;i++){
        printf("%d | ",STACK[i]);
    }
}

int main(){

}