#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* data;
    int count;
    int stackMax;
    int top;
} STACK;

STACK* createStack(int stackMax){
    STACK* stack = (STACK*) malloc(sizeof(STACK));
    if(!stack) return NULL;
    
    stack->data  = ( int * ) malloc (stackMax * sizeof(int));
    if( !stack->data ) return NULL;
    stack->count = 0;
    stack->stackMax = stackMax;
    stack->top   = -1;
    return stack;
}
void push(int data, STACK* stack){
    if( stack->count == stack->stackMax ){
        printf("\nStack overflow\n");
        return;
    }
    (stack->count)++;
    (stack->top)++;
    *(stack->data + stack->top) = data;   
}
void pop(int* data, STACK* stack){
    if( stack->count <= 0 ){
        printf("\nEmpty stack\n");
        return;
    }
    *data = *(stack->data + stack->top);
    (stack->count)--;
    (stack->top)--;
}
void printStack( STACK* stack ){
    printf("\nElements of stack are : ");
    for (int i=stack->count-1;i>=0;i--){
        printf("\n| %d |", *(stack->data+i) );
        printf("\n______");
    }
}
void deleteStack( STACK* stack ){
    if( !stack ) return;
    if( !stack->data ) return;
    free( stack->data );
    free( stack );
}
int stackTop( STACK* stack ){
    if( !stack ) return NULL;
    if( stack->count == 0 ) return NULL;
    else return stack->top;
}
int isEmpty( STACK* stack ){
    return (stack->count == 0);
}
int stackCount( STACK* stack ){
    return stack->count;
}

int main(){
    STACK* stack;

    stack = createStack(10);

    int data,command, repeat = 1;
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