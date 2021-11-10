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

// CREATE STACK 
STACK* createStack(){
    STACK* stack;

    stack = (STACK*) malloc(sizeof(STACK));
    if(stack){
        stack->count = 0;
        stack->top = NULL;
    }
    return stack;
}

// PUSH DATA TO STACK.
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

void printStack( STACK* stack ){
    STACK_NODE* currentNode = stack->top;
    printf("\nElements of stack are : ");
    while(currentNode != NULL){
        printf("\n| %d |",currentNode->value);
        printf("\n______");
        currentNode = currentNode->next;
    }
}

int main(){

    STACK* stack = createStack();

    int data;
    // push(5,stack);
    // push(4,stack);
    // push(6,stack);
    // push(1,stack);
    // printStack(stack);
    // pop(&data, stack);
    // printStack(stack);

    // printf("\nPOPED DATA : %d",data);

    int command, repeat = 1;
    printf("\nYOUR STACK IS READY...!");
    printf("\nENTER THE BELOW NUMBER TO PERFORM CORRESPONDING OPERATION.");
    while(repeat){
        printf("\n\n1.PUSH\n2.POP\n3.PRINT STACK\n0.EXIT\n\n");
        scanf("%d",&command);
        switch(command){
            case 1:
                // int data;
                printf("\nEnter the number to be pushed :");
                scanf("%d",&data);
                push(data,stack);
                break;
            case 2:
                // int data;
                pop(&data,stack);
                printf("\nPoped data : %d", data);
                break;
            case 3:
                printStack(stack);
                break;
            case 0:
                printf("\nHappy ending");
                free(stack);
                repeat = 0;
                break;
            default:
                printf("\nEnter a valid input");
                break;
        }
    }
    return 0;
}