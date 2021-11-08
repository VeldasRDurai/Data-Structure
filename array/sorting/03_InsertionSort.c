#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int n) {
  for (int i=1; i<n; i++) {
    int key = array[i];
    int j = i - 1;
    while ( key<array[j] && j >= 0 ) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) printf("%d  ", array[i]);
}

int* createArray(int size){
    int* data = (int *) malloc( size * sizeof(int) );
    for( int i =0; i<size; i++ ){
        printf("\nEnter the %dth element : ", i);
        scanf("%d", (data+i));
    }
    return data;
}

int main() {
    // int size;
    // printf("\nEnter the length of array to be created : ");
    // scanf("%d",&size);    
    // int *data = createArray(size);

    int data[] = {-2, 45, 0, 11, -9};
    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);
    
    // free(data);
    return 0;
}