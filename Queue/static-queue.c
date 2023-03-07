#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 1000

int front = -1;
int rear  = -1;
int QUEUE[N];

void enqueue( int data ){
    if (rear == N-1){
        printf("Queue Overflow");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    QUEUE[rear] = data;
}
int dequeue(){
    if (front == -1 || front > rear) {
        printf("Queue underflow");
        return -1;
    }
    int data = QUEUE[front];
    if(front == rear) {  
        front = -1;  
        rear = -1;  
    } else {
        front++;
    }
    return data;
}
int peek(){
    return front == -1 ? -1 : QUEUE[front];
}
bool isEmpty(){
    return front == -1 || front > rear ? true : false;
}
bool isFull(){
    return rear == N-1 ? true : false;
}
void print(){
    for(int i==front;i<=rear;i++){
        printf("%d | ",QUEUE[i]);
    }
}

int main(){

}