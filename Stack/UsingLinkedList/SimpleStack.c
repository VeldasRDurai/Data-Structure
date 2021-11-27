#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} STACK_NODE;

typedef struct{
    int count;
    STACK_NODE* top;
} STACK;

STACK* createStack(){
    STACK* stack;

    stack = (STACK*) malloc(sizeof(STACK));
    if(stack){
        stack->count = 0;
        stack->top = NULL;
    }
    return stack;
}
void push( int data, STACK* stack ){
    printf("\npushing data to stack: %d", data);
    STACK_NODE* newNode = (STACK_NODE*) malloc(sizeof(STACK_NODE));
    if(!newNode){
        return;
    } else {
        newNode->value = data;
        newNode->next = stack->top;
        stack->top = newNode;
        stack->count++;
        return;
    }
}
void pop( int* data, STACK* stack){
    printf("\nPoping data...");
    STACK_NODE* deletedNode;
    if(stack->top == NULL){
        printf("\nYOUR STACK IS EMPTY... :(");
        return;
    }
    *data = stack->top->value;
    deletedNode = stack->top;
    stack->top = stack->top->next;
    stack->count--;
    free(deletedNode);
}
void deleteStack(STACK *stack){
    STACK_NODE* temp;
    if(stack){
        while( stack->top!=NULL ){
            temp = stack->top;
            stack->top = stack->top->next;
            free(temp);
        }
        free(stack);
    }
}
void printStack( STACK* stack ){
    STACK_NODE* currentNode = stack->top;
    printf("\nElements of stack are : ");
    while(currentNode != NULL){
        printf("\n| %d |",currentNode->value);
        printf("\n______");
        currentNode = currentNode->next;
    }
}
int stackTop(STACK* stack){
    if( stack->count == 0 ) return NULL;
    else return stack->top->value;
}
int isEmpty(STACK* stack){
    if( stack->count == 0 ) return 1;
    else return 0;
}
int stackCount(STACK* stack){
    return stack->count;
}
int main(){

    STACK* stack = createStack();

    int command, repeat = 1,data;
    printf("\nYOUR STACK IS READY...!");
    printf("\nENTER THE BELOW NUMBER TO PERFORM CORRESPONDING OPERATION.");
    while(repeat){
        printf("\n\n1.PUSH\n2.POP\n3.PRINT STACK\n0.EXIT\n\n");
        scanf("%d",&command);
        switch(command){
            case 1:
                printf("\nEnter the number to be pushed :");
                scanf("%d",&data);
                push(data,stack);
                break;
            case 2:
                pop(&data,stack);
                printf("\nPoped data : %d", data);
                break;
            case 3:
                printStack(stack);
                break;
            case 0:
                printf("\nHappy ending");
                deleteStack(stack);
                repeat = 0;
                break;
            default:
                printf("\nEnter a valid input");
                break;
        }
    }
    return 0;
}