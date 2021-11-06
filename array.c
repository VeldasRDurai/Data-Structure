#include <stdio.h>
#include <stdlib.h>

int main(){
    int arrayLen;
    printf("\nEnter how many elements to be stored in array : ");
    scanf("%d",&arrayLen);

    int *ptr = (int *) malloc(sizeof(int)*arrayLen);
    if(ptr == NULL) {
        printf("malloc of size %d failed!\n", arrayLen);
        exit(1);
    }

    for(int i=0; i < arrayLen; i++){
        printf("\nEnter the %d the element : ",i);
        scanf("%d",&ptr[i]);
    } 
    for(int i=0; i < arrayLen; i++) printf("\n%d - %d", i, &ptr[i]);

    printf("\n%d", sizeof(ptr));

    return 0;
}