#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
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

    quickSort(data, 0, size-1);
    
    printf("Sorted Array in Ascending Order:\n");
    printArray(data, size);
    
    // free(data);
    return 0;
}